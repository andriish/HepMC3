// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_LHEFHDF5_H
#define HEPMC3_LHEFHDF5_H

#include "HepMC3/LHEF.h"
#include <highfive/H5Attribute.hpp>
#include <highfive/H5DataSet.hpp>
#include <highfive/H5DataSpace.hpp>
#include <highfive/H5File.hpp>

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace LHEFHDF5 {

/**
 *  @class LHEFHDF5::Reader
 *  @brief Reads LHE events from HDF5 format files created by SHERPA Output_HDF5
 */
class Reader {
public:
    /** @brief Run-level LHEF information. */
    LHEF::HEPRUP heprup;
    /** @brief Most recently read LHEF event. */
    LHEF::HEPEUP hepeup;

    /** @brief Open an LHEF-HDF5 input file. */
    Reader(const std::string &filename)
        : m_failed(false), m_next_index(0), m_event_count(0), m_nweights(0) {
        m_file.reset(new HighFive::File(filename, HighFive::File::ReadOnly));
        if (!m_file->exist("events") || !m_file->exist("particles")) {
            m_failed = true;
            return;
        }
        m_events_ds.reset(new HighFive::DataSet(m_file->getDataSet("events")));
        m_particles_ds.reset(new HighFive::DataSet(m_file->getDataSet("particles")));
        auto dims = m_events_ds->getSpace().getDimensions();
        if (!dims.empty()) m_event_count = dims[0];
        auto attr_names = m_events_ds->listAttributeNames();
        if (!attr_names.empty()) {
            std::vector<std::string> enames;
            m_events_ds->getAttribute(attr_names[0]).read(enames);
            if (enames.size() >= 9) m_weight_names.assign(enames.begin() + 9, enames.end());
        }
        if (m_weight_names.empty()) m_weight_names.push_back("NOMINAL");
        m_nweights = m_weight_names.size();
        int beamA = 0, beamB = 0, pdfG1 = 0, pdfG2 = 0, pdfS1 = -1, pdfS2 = -1, weight_strat = 1;
        double energyA = 0.0, energyB = 0.0;
        if (m_file->exist("init")) {
            auto init_ds = m_file->getDataSet("init");
            std::vector<double> idata;
            init_ds.read(idata);
            if (idata.size() >= 10) {
                beamA = static_cast<int>(idata[0]); beamB = static_cast<int>(idata[1]);
                energyA = idata[2]; energyB = idata[3];
                pdfG1 = static_cast<int>(idata[4]); pdfG2 = static_cast<int>(idata[5]);
                pdfS1 = static_cast<int>(idata[6]); pdfS2 = static_cast<int>(idata[7]);
                weight_strat = static_cast<int>(idata[8]);
            }
        }
        if (m_file->exist("procInfo")) {
            auto proc_ds = m_file->getDataSet("procInfo");
            std::vector<std::vector<double>> pdata;
            proc_ds.read(pdata);
            for (const auto &row : pdata) {
                if (row.size() >= 6) {
                    ProcData p;
                    p.procId = static_cast<int>(row[0]); p.npLO = static_cast<int>(row[1]);
                    p.npNLO = static_cast<int>(row[2]); p.xSection = row[3];
                    p.error = row[4]; p.unitWeight = row[5];
                    m_proc_info.push_back(p);
                }
            }
        }
        heprup.IDBMUP = {beamA, beamB}; heprup.EBMUP = {energyA, energyB};
        heprup.PDFGUP = {pdfG1, pdfG2}; heprup.PDFSUP = {pdfS1, pdfS2};
        heprup.IDWTUP = weight_strat; heprup.NPRUP = static_cast<int>(m_proc_info.size());
        heprup.resize();
        for (std::size_t i = 0; i < m_proc_info.size(); ++i) {
            heprup.LPRUP[i] = m_proc_info[i].procId; heprup.XSECUP[i] = m_proc_info[i].xSection;
            heprup.XERRUP[i] = m_proc_info[i].error; heprup.XMAXUP[i] = m_proc_info[i].unitWeight;
        }
        heprup.weightinfo.clear();
        for (const auto &wname : m_weight_names) {
            LHEF::WeightInfo wi;
            wi.name = wname;
            heprup.weightinfo.push_back(wi);
        }
        hepeup.heprup = &heprup;
    }
    /** @brief Close the reader. */
    ~Reader() = default;

    /** @brief Read the next LHEF event. */
    bool readEvent() {
        if (m_failed || m_next_index >= m_event_count) { m_failed = true; return false; }
        std::vector<std::vector<double>> erows;
        m_events_ds->select({m_next_index, 0}, {1, 9 + m_nweights}).read(erows);
        if (erows.empty() || erows[0].size() < 9) { m_failed = true; return false; }
        const auto &erow = erows[0];
        hepeup.heprup = &heprup; hepeup.IDPRUP = static_cast<long>(erow[0]);
        hepeup.NUP = static_cast<int>(erow[1]); uint64_t start = static_cast<uint64_t>(erow[2]);
        hepeup.ntries = static_cast<int>(erow[3]); hepeup.SCALUP = erow[4];
        hepeup.AQEDUP = erow[7]; hepeup.AQCDUP = erow[8];
        hepeup.XWGTUP = erow.size() > 9 ? erow[9] : 1.0;
        hepeup.resize();
        if (hepeup.NUP > 0) {
            std::vector<std::vector<double>> prows;
            m_particles_ds->select({static_cast<size_t>(start), 0}, {static_cast<size_t>(hepeup.NUP), 13}).read(prows);
            for (int i = 0; i < hepeup.NUP; ++i) {
                const auto &p = prows[i];
                hepeup.IDUP[i] = static_cast<long>(p[0]); hepeup.ISTUP[i] = static_cast<int>(p[1]);
                hepeup.MOTHUP[i] = {static_cast<int>(p[2]), static_cast<int>(p[3])};
                hepeup.ICOLUP[i] = {static_cast<int>(p[4]), static_cast<int>(p[5])};
                hepeup.PUP[i] = {p[6], p[7], p[8], p[9], p[10]};
                hepeup.VTIMUP[i] = p[11]; hepeup.SPINUP[i] = p[12];
            }
        }
        hepeup.weights.clear();
        for (std::size_t w = 0; w < m_nweights; ++w) {
            if (9 + w < erow.size()) {
                const LHEF::WeightInfo *wi = w < heprup.weightinfo.size() ? &heprup.weightinfo[w] : nullptr;
                hepeup.weights.push_back({erow[9 + w], wi});
            }
        }
        ++m_next_index; m_failed = false;
        return true;
    }
    /** @brief Read the next event into a caller-supplied object. */
    bool readEvent(LHEF::HEPEUP &hepe) { if (!readEvent()) return false; hepe = hepeup; return true; }
    /** @brief Alias for readEvent. */
    bool read_event(LHEF::HEPEUP &hepe) { return readEvent(hepe); }

    /** @brief Return run-level LHEF information. */
    const LHEF::HEPRUP &get_heprup() const { return heprup; }

    /** @brief Skip input events. */
    bool skip(const int n) {
        if (n < 0 || m_failed) return false;
        if (m_next_index >= m_event_count) { m_failed = true; return false; }
        std::size_t remaining = m_event_count - m_next_index;
        if (static_cast<std::size_t>(n) > remaining) { m_next_index = m_event_count; return false; }
        m_next_index += static_cast<std::size_t>(n);
        return true;
    }
    /** @brief Return reader failure state. */
    bool failed() const { return m_failed; }
    /** @brief Release HDF5 resources. */
    void close() { m_events_ds.reset(); m_particles_ds.reset(); m_file.reset(); }

private:
    bool m_failed = false;
    std::unique_ptr<HighFive::File> m_file;
    std::unique_ptr<HighFive::DataSet> m_events_ds;
    std::unique_ptr<HighFive::DataSet> m_particles_ds;

    std::size_t m_next_index = 0;
    std::size_t m_event_count = 0;
    std::size_t m_nweights = 0;
    std::vector<std::string> m_weight_names;

    struct ProcData {
        int procId;
        int npLO;
        int npNLO;
        double xSection;
        double error;
        double unitWeight;
    };
    std::vector<ProcData> m_proc_info;
};




/**
 *  @class LHEFHDF5::Writer
 *  @brief Writes LHE events into HDF5 format files compatible with SHERPA Output_HDF5
 */
class Writer {
public:
    LHEF::HEPRUP heprup;
    LHEF::HEPEUP hepeup;

    Writer(const std::string &filename): m_filename(filename) {}
    Writer(const std::string &filename, const LHEF::HEPRUP &heprup_in): heprup(heprup_in), m_filename(filename) {}
    ~Writer() = default;

    void init() { initFile(); }
    void writeinit() { init(); }

    void writeEvent() {
        if (!m_initialized) initFile();
        if (m_failed) return;
        std::vector<std::vector<double> > prows;
        prows.reserve(hepeup.NUP);
        for (int i = 0; i < hepeup.NUP; ++i) {
            const std::vector<double> &p = hepeup.PUP[i];
            prows.push_back({static_cast<double>(hepeup.IDUP[i]), static_cast<double>(hepeup.ISTUP[i]), static_cast<double>(hepeup.MOTHUP[i].first), static_cast<double>(hepeup.MOTHUP[i].second), static_cast<double>(hepeup.ICOLUP[i].first), static_cast<double>(hepeup.ICOLUP[i].second), p.size() > 0 ? p[0] : 0.0, p.size() > 1 ? p[1] : 0.0, p.size() > 2 ? p[2] : 0.0, p.size() > 3 ? p[3] : 0.0, p.size() > 4 ? p[4] : 0.0, static_cast<size_t>(i) < hepeup.VTIMUP.size() ? hepeup.VTIMUP[i] : 0.0, static_cast<size_t>(i) < hepeup.SPINUP.size() ? hepeup.SPINUP[i] : 0.0});
        }
        std::vector<double> weights;
        if (!hepeup.weights.empty()) for (const auto &weight : hepeup.weights) weights.push_back(weight.first);
        else weights.push_back(hepeup.XWGTUP);
        weights.resize(m_nweights, 0.0);
        std::vector<double> erow = {static_cast<double>(hepeup.IDPRUP), static_cast<double>(hepeup.NUP), static_cast<double>(m_particles_offset), static_cast<double>(hepeup.ntries), hepeup.SCALUP, hepeup.SCALUP, hepeup.SCALUP, hepeup.AQEDUP, hepeup.AQCDUP};
        erow.insert(erow.end(), weights.begin(), weights.end());
        m_events_ds->resize({m_event_offset + 1, 9 + m_nweights});
        m_events_ds->select({static_cast<size_t>(m_event_offset), 0}, {1, 9 + m_nweights}).write(std::vector<std::vector<double> >{erow});
        ++m_event_offset;
        if (!prows.empty()) { m_particles_ds->resize({m_particles_offset + prows.size(), 13}); m_particles_ds->select({static_cast<size_t>(m_particles_offset), 0}, {prows.size(), 13}).write(prows); m_particles_offset += prows.size(); }
    }
    void writeEvent(const LHEF::HEPEUP &hepe) { hepeup = hepe; writeEvent(); }
    void write_event(const LHEF::HEPEUP &hepe) { writeEvent(hepe); }

    bool failed() const { return m_failed; }
    void close() { m_events_ds.reset(); m_particles_ds.reset(); m_file.reset(); }

private:
    void initFile() {
        if (m_initialized) return;
        m_file.reset(new HighFive::File(m_filename, HighFive::File::Overwrite));
        std::vector<int> version_no = {2, 0, 1};
        m_file->createDataSet<int>("version", HighFive::DataSpace::From(version_no)).write(version_no);
        std::vector<ProcData> procs;
        for (int i = 0; i < heprup.NPRUP; ++i) procs.push_back({i < static_cast<int>(heprup.LPRUP.size()) ? heprup.LPRUP[i] : i + 1, -1, -1, i < static_cast<int>(heprup.XSECUP.size()) ? heprup.XSECUP[i] : 0.0, i < static_cast<int>(heprup.XERRUP.size()) ? heprup.XERRUP[i] : 0.0, i < static_cast<int>(heprup.XMAXUP.size()) ? heprup.XMAXUP[i] : 1.0});
        if (procs.empty()) procs.push_back({1, -1, -1, 0.0, 0.0, 1.0});
        std::vector<std::string> weight_names;
        for (std::size_t i = 0; i < heprup.weightinfo.size(); ++i) { std::string name = heprup.weightNameHepMC(i); weight_names.push_back(name.empty() ? heprup.weightinfo[i].name : name); }
        if (weight_names.empty()) weight_names.push_back("NOMINAL");
        m_nweights = weight_names.size();
        std::vector<double> idata = {static_cast<double>(heprup.IDBMUP.first), static_cast<double>(heprup.IDBMUP.second), heprup.EBMUP.first, heprup.EBMUP.second, static_cast<double>(heprup.PDFGUP.first), static_cast<double>(heprup.PDFGUP.second), static_cast<double>(heprup.PDFSUP.first), static_cast<double>(heprup.PDFSUP.second), static_cast<double>(heprup.IDWTUP), static_cast<double>(procs.size())};
        HighFive::DataSet init_ds = m_file->createDataSet<double>("init", HighFive::DataSpace::From(idata)); init_ds.write(idata);
        std::vector<std::string> inames = {"beamA", "beamB", "energyA", "energyB", "PDFgroupA", "PDFgroupB", "PDFsetA", "PDFsetB", "weightingStrategy", "numProcesses"}; init_ds.createAttribute<std::string>("properties", HighFive::DataSpace::From(inames)).write(inames);
        std::vector<std::vector<double> > pdata;
        for (const auto &p : procs) pdata.push_back({static_cast<double>(p.procId), static_cast<double>(p.npLO), static_cast<double>(p.npNLO), p.xSection, p.error, p.unitWeight});
        HighFive::DataSet proc_ds = m_file->createDataSet<double>("procInfo", HighFive::DataSpace::From(pdata)); proc_ds.write(pdata);
        std::vector<std::string> pnames = {"procId", "npLO", "npNLO", "xSection", "error", "unitWeight"}; proc_ds.createAttribute<std::string>("properties", HighFive::DataSpace::From(pnames)).write(pnames);
        std::vector<std::string> enames = {"pid", "nparticles", "start", "trials", "scale", "fscale", "rscale", "aqed", "aqcd"}; enames.insert(enames.end(), weight_names.begin(), weight_names.end());
        HighFive::DataSpace event_space({0, 9 + m_nweights}, {HighFive::DataSpace::UNLIMITED, 9 + m_nweights}); HighFive::DataSetCreateProps event_props; event_props.add(HighFive::Chunking(std::vector<hsize_t>{1024, 9 + m_nweights}));
        m_events_ds.reset(new HighFive::DataSet(m_file->createDataSet<double>("events", event_space, event_props))); m_events_ds->createAttribute<std::string>("events", HighFive::DataSpace::From(enames)).write(enames);
        std::vector<std::string> part_names = {"id", "status", "mother1", "mother2", "color1", "color2", "px", "py", "pz", "e", "m", "lifetime", "spin"};
        HighFive::DataSpace particle_space({0, 13}, {HighFive::DataSpace::UNLIMITED, 13}); HighFive::DataSetCreateProps particle_props; particle_props.add(HighFive::Chunking(std::vector<hsize_t>{10240, 13}));
        m_particles_ds.reset(new HighFive::DataSet(m_file->createDataSet<double>("particles", particle_space, particle_props))); m_particles_ds->createAttribute<std::string>("properties", HighFive::DataSpace::From(part_names)).write(part_names);
        m_initialized = true;
    }

    bool m_failed = false;
    bool m_initialized = false;
    std::string m_filename;
    std::unique_ptr<HighFive::File> m_file;
    std::unique_ptr<HighFive::DataSet> m_events_ds;
    std::unique_ptr<HighFive::DataSet> m_particles_ds;
    uint64_t m_event_offset = 0;
    uint64_t m_particles_offset = 0;
    std::size_t m_nweights = 1;

    struct ProcData {
        int procId;
        int npLO;
        int npNLO;
        double xSection;
        double error;
        double unitWeight;
    };
};


} // namespace LHEFHDF5

#endif