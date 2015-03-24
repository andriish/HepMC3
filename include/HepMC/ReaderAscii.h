// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC_READERASCII_H
#define HEPMC_READERASCII_H
///
/// @file  ReaderAscii.h
/// @brief Definition of class \b ReaderAscii
///
/// @class HepMC::ReaderAscii
/// @brief GenEvent I/O parsing for structured text files
///
/// @ingroup IO
///
#include "HepMC/Reader.h"
#include "HepMC/GenEvent.h"
#include <string>
#include <fstream>

namespace HepMC {

class ReaderAscii : public Reader {
public:

    /// @brief Constructor
    /// @warning If file already exists, it will be cleared before writing
    ReaderAscii(const std::string& filename);

    /// @brief Destructor
    ~ReaderAscii();

    /// @brief Load event from file
    ///
    /// @param[out] evt Event to be filled
    bool read_event(GenEvent& evt);

    /// @brief Return status of the stream
    ///
    /// @todo Rename!
    int rdstate() { return m_file.rdstate(); }

    /// @brief Close file stream
    void close();

  private:

    /// @brief Get global attribute
    ///
    /// @todo rewrite global attributes
    shared_ptr<Attribute> get_global(std::string name);

    /// @brief Unsecape '\' and '\n' characters in string
    std::string unescape(const std::string s);

    /// @name Read helpers
    //@{

    /// @brief Parse event
    ///
    /// Helper routine for parsing event information
    /// @param[out] evt Event that will be filled with new data
    /// @param[in]  buf Line of text that needs to be parsed
    /// @return vertices count and particles count for verification
    std::pair<int,int> parse_event_information(GenEvent &evt, const char *buf);

    /// @brief Parse units
    ///
    /// Helper routine for parsing units information
    /// @param[out] evt Event that will be filled with unit information
    /// @param[in]  buf Line of text that needs to be parsed
    ///
    bool parse_units(GenEvent &evt, const char *buf);

    /// @brief Parse struct GenPdfInfo information
    ///
    /// Helper routine for parsing PDF information
    /// @param[out] evt Event that will be filled with unit information
    /// @param[in]  buf Line of text that needs to be parsed
    bool parse_pdf_info(GenEvent &evt, const char *buf);

    /// @brief Parse struct GenHeavyIon information
    ///
    /// Helper routine for parsing heavy ion information
    /// @param[out] evt Event that will be filled with unit information
    /// @param[in]  buf Line of text that needs to be parsed
    bool parse_heavy_ion(GenEvent &evt, const char *buf);

    /// @brief Parse struct GenCrossSection information
    ///
    /// Helper routine for parsing cross-section information
    /// @param[out] evt Event that will be filled with unit information
    /// @param[in]  buf Line of text that needs to be parsed
    bool parse_cross_section(GenEvent &evt, const char *buf);

    /// @brief Parse vertex
    ///
    /// Helper routine for parsing single event information
    /// @param[out] evt Event that will contain parsed vertex
    /// @param[in] buf Line of text that needs to be parsed
    ///
    bool parse_vertex_information(GenEvent &evt, const char *buf);

    /// @brief Parse particle
    ///
    /// Helper routine for parsing single particle information
    /// @param[out] evt Event that will contain parsed particle
    /// @param[in] buf Line of text that needs to be parsed
    bool parse_particle_information(GenEvent &evt, const char *buf);

    /// @brief Parse attribute
    ///
    /// Helper routine for parsing single attribute information
    /// @param[out] evt Event that will contain parsed attribute
    /// @param[in] buf Line of text that needs to be parsed
    bool parse_attribute(GenEvent &evt, const char *buf);
    //@}


  private:

  std::ifstream m_file; //!< Input file

    /** @brief Store attributes global to the run being written/read. */
    std::map< std::string, shared_ptr<Attribute> > m_global_attributes;
  };


} // namespace HepMC

#endif