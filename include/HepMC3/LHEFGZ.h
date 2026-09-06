// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_LHEFGZ_H
#define HEPMC3_LHEFGZ_H

#include "HepMC3/CompressedIO.h"
#include "HepMC3/LHEF.h"

#include <memory>
#include <string>

/** @brief Compressed ASCII Les Houches Event File I/O. */
namespace LHEF {

using HepMC3::Compression;
using HepMC3::ifstream;
using HepMC3::ofstream;
using HepMC3::istream;
using HepMC3::ostream;

/** @brief Reads compressed ASCII LHEF files. */
template <class T = Reader, Compression C = Compression::z> class ReaderGZ : public ReaderBase {
public:
    /** @brief Open a compressed LHEF file. */
    ReaderGZ(const std::string &filename) {
        m_zstr = std::shared_ptr<std::istream>(new ifstream(filename.c_str()));
        m_reader = std::make_shared<T>(*(m_zstr.get()));
        heprup = m_reader->heprup;
        hepeup = m_reader->hepeup;
    }

    /** @brief Constructor from istream. */
    ReaderGZ(std::istream &is) {
        m_zstr = std::shared_ptr<std::istream>(new istream(is));
        m_reader = std::make_shared<T>(*(m_zstr.get()));
        heprup = m_reader->heprup;
        hepeup = m_reader->hepeup;
    }

    /** @brief Constructor from shared pointer to stream. */
    ReaderGZ(std::shared_ptr<std::istream> s_stream) {
        m_zstr = s_stream;
        m_reader = std::make_shared<T>(*(m_zstr.get()));
        heprup = m_reader->heprup;
        hepeup = m_reader->hepeup;
    }

    /** @brief Close the input file. */
    ~ReaderGZ() override { close(); }

    /** @brief Read the next LHEF event. */
    bool readEvent() override {
        if (!m_reader || !m_reader->readEvent()) return false;
        hepeup = m_reader->hepeup;
        hepeup.heprup = &heprup;
        return true;
    }

    /** @brief Skip input events. */
    bool skip(const int count) override {
        if (!m_reader) return false;
        return m_reader->skip(count);
    }

    /** @brief Return reader failure state. */
    bool failed() const override { return !m_reader || m_reader->failed(); }

    /** @brief Release input resources. */
    void close() override {
        if (m_reader) m_reader->close();
        if (std::dynamic_pointer_cast<ifstream>(m_zstr)) {
            std::dynamic_pointer_cast<ifstream>(m_zstr)->close();
        }
    }

    /** @brief Return underlying reader. */
    std::shared_ptr<T> reader() { return m_reader; }

private:
    std::shared_ptr<std::istream> m_zstr = nullptr;
    std::shared_ptr<T> m_reader = nullptr;
};

/** @brief Writes compressed ASCII LHEF files. */
template <class T = Writer, Compression C = Compression::z> class WriterGZ : public WriterBase {
public:
    /** @brief Create a compressed LHEF writer from filename. */
    WriterGZ(const std::string &filename) {
        m_zstr = std::shared_ptr<std::ostream>(new ofstream(filename.c_str(), C));
        m_writer = std::make_shared<T>(*(m_zstr.get()));
    }

    /** @brief Create a compressed LHEF writer from ostream. */
    WriterGZ(std::ostream &stream) {
        m_zstr = std::shared_ptr<std::ostream>(new ostream(stream, C));
        m_writer = std::make_shared<T>(*(m_zstr.get()));
    }

    /** @brief Create a compressed LHEF writer from shared pointer to ostream. */
    WriterGZ(std::shared_ptr<std::ostream> s_stream) {
        m_zstr = std::shared_ptr<std::ostream>(new ostream(*(s_stream.get()), C));
        m_writer = std::make_shared<T>(*(m_zstr.get()));
    }

    /** @brief Close the output file. */
    ~WriterGZ() override { close(); }

    /** @brief Write the LHEF initialization block. */
    void init() override {
        if (!m_writer || m_initialized) return;
        m_writer->heprup = heprup;
        m_writer->init();
        m_initialized = true;
    }

    /** @brief Write the current LHEF event. */
    void writeEvent() override {
        if (!m_writer) return;
        if (!m_initialized) init();
        m_writer->hepeup = hepeup;
        m_writer->hepeup.heprup = &m_writer->heprup;
        m_writer->writeEvent();
    }

    /** @brief Return writer failure state. */
    bool failed() const override { return !m_writer || !m_zstr || m_writer->failed() || !(*m_zstr); }

    /** @brief Finalize and close the output file. */
    void close() override {
        if (m_writer) m_writer->close();
        if (m_zstr) {
            m_zstr->flush();
            if (std::dynamic_pointer_cast<ofstream>(m_zstr)) {
                std::dynamic_pointer_cast<ofstream>(m_zstr)->close();
            }
        }
    }

    /** @brief Return underlying writer. */
    std::shared_ptr<T> writer() { return m_writer; }

private:
    std::shared_ptr<std::ostream> m_zstr = nullptr;
    std::shared_ptr<T> m_writer = nullptr;
    bool m_initialized = false;
};

} // namespace LHEF

#endif
