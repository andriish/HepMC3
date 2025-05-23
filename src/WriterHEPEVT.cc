// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file WriterHEPEVT.cc
 *  @brief Implementation of \b class WriterHEPEVT
 *
 */
#include <array>
#include <cstdio>  // sprintf
#include <sstream>

#include "HepMC3/Print.h"
#include "HepMC3/WriterHEPEVT.h"
namespace HepMC3
{


WriterHEPEVT::WriterHEPEVT(const std::string &filename,
                           std::shared_ptr<GenRunInfo> /*run*/): m_file(filename), m_stream(&m_file)
{
    HEPMC3_WARNING_LEVEL(900,"WriterHEPEVT::WriterHEPEVT: HEPEVT format is outdated. Please use HepMC3 format instead.")
    m_hepevt_interface.allocate_internal_storage();
}

WriterHEPEVT::WriterHEPEVT(std::ostream& stream,
                           std::shared_ptr<GenRunInfo> /*run*/): m_stream(&stream)
{
    HEPMC3_WARNING_LEVEL(900,"WriterHEPEVT::WriterHEPEVT: HEPEVT format is outdated. Please use HepMC3 format instead.")
    m_hepevt_interface.allocate_internal_storage();
}

WriterHEPEVT::WriterHEPEVT(std::shared_ptr<std::ostream> s_stream,
                           std::shared_ptr<GenRunInfo> /*run*/): m_shared_stream(s_stream), m_stream(s_stream.get())
{
    HEPMC3_WARNING_LEVEL(900,"WriterHEPEVT::WriterHEPEVT: HEPEVT format is outdated. Please use HepMC3 format instead.")
    m_hepevt_interface.allocate_internal_storage();
}

void WriterHEPEVT::write_hepevt_particle(int index, bool iflong)
{
    std::array<char, 512> buf{};//Note: the format is fixed, so no reason for complicatied tratment
    char* cursor = buf.data();
    cursor += sprintf(cursor, "% 8i% 8i", m_hepevt_interface.status(index), m_hepevt_interface.id(index));
    if (iflong)
    {
        cursor += sprintf(cursor, "% 8i% 8i", m_hepevt_interface.first_parent(index), m_hepevt_interface.last_parent(index));
        cursor += sprintf(cursor, "% 8i% 8i", m_hepevt_interface.first_child(index), m_hepevt_interface.last_child(index));
        cursor += sprintf(cursor, "% 19.8E% 19.8E% 19.8E% 19.8E% 19.8E\n", m_hepevt_interface.px(index), m_hepevt_interface.py(index), m_hepevt_interface.pz(index), m_hepevt_interface.e(index), m_hepevt_interface.m(index));
        cursor += sprintf(cursor, "%-48s% 19.8E% 19.8E% 19.8E% 19.8E\n", " ", m_hepevt_interface.x(index), m_hepevt_interface.y(index), m_hepevt_interface.z(index), m_hepevt_interface.t(index));
    }
    else
    {
        cursor += sprintf(cursor, "% 8i% 8i", m_hepevt_interface.first_child(index), m_hepevt_interface.last_child(index));
        cursor += sprintf(cursor, "% 19.8E% 19.8E% 19.8E% 19.8E\n", m_hepevt_interface.px(index), m_hepevt_interface.py(index), m_hepevt_interface.pz(index), m_hepevt_interface.m(index));
    }
    unsigned long length = cursor - buf.data();
    m_stream->write(buf.data(), length);
}

void WriterHEPEVT::write_hepevt_event_header()
{
    std::array<char, 512> buf{};//Note: the format is fixed, so no reason for complicatied tratment
    char* cursor = buf.data();
    cursor += sprintf(cursor, "E% 8i %8i\n", m_hepevt_interface.event_number(), m_hepevt_interface.number_entries());
    unsigned long length = cursor - buf.data();
    m_stream->write(buf.data(), length);
}

void WriterHEPEVT::write_event(const GenEvent &evt)
{
    m_hepevt_interface.GenEvent_to_HEPEVT(&evt);
    m_hepevt_interface.fix_daughters();
    write_hepevt_event_header();
    for ( int i = 1; i <= m_hepevt_interface.number_entries(); ++i )  write_hepevt_particle(i, get_vertices_positions_present());
    m_events_count++;
}

void WriterHEPEVT::close()
{
    auto* ofs = dynamic_cast<std::ofstream*>(m_stream);
    if (ofs && !ofs->is_open()) return;
    if (ofs) ofs->close();
}

bool WriterHEPEVT::failed()
{
    return static_cast<bool>(m_file.rdstate());
}

void WriterHEPEVT::set_vertices_positions_present(bool iflong) { if (iflong) m_options["vertices_positions_are_absent"] = ""; else m_options.erase("vertices_positions_are_absent"); }

bool WriterHEPEVT::get_vertices_positions_present() const { return  (m_options.count("vertices_positions_are_absent") == 0); }

} // namespace HepMC3
