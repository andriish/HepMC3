// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_WRITERGZ_H
#define HEPMC3_WRITERGZ_H
///
/// @file  WriterGZ.h
/// @brief Definition of class \b WriterGZ
///
/// @class HepMC3::WriterGZ
/// @brief GenEvent I/O serialization for compressed files
///
/// @ingroup IO
///
#include <string>
#include <fstream>
#include "HepMC3/Writer.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenRunInfo.h"
#include "HepMC3/CompressedIO.h"
namespace HepMC3 {

template <class T, Compression C = Compression::z> class WriterGZ : public Writer  {
public:

    /// @brief Constructor
    /// @warning If file already exists, it will be cleared before writing
    WriterGZ(const std::string& filename, std::shared_ptr<GenRunInfo> run = std::shared_ptr<GenRunInfo>()) {
        m_zstr = std::shared_ptr< std::ostream >(new ofstream(filename.c_str(), C));
        m_writer = std::make_shared<T>(*(m_zstr.get()), run);
    }

    /// @brief Constructor from ostream
    WriterGZ(std::ostream& stream, std::shared_ptr<GenRunInfo> run = std::shared_ptr<GenRunInfo>()) {
        m_zstr = std::shared_ptr< std::ostream >(new ostream(stream, C));
        m_writer = std::make_shared<T>(*(m_zstr.get()), run);
    }

    /// @brief Constructor from ostream
    WriterGZ(std::shared_ptr<std::ostream> s_stream, std::shared_ptr<GenRunInfo> run = std::shared_ptr<GenRunInfo>()) {
        m_zstr = std::shared_ptr< std::ostream >(new ostream(*(s_stream.get()), C));
        m_writer = std::make_shared<T>(m_zstr, run);
    }

    /// @brief Destructor
    ~WriterGZ() {};

    /// @brief Write event to file
    ///
    /// @param[in] evt Event to be serialized
    void write_event(const GenEvent& evt) override { if (m_writer) m_writer->write_event(evt); };

    /// @brief Return status of the stream
    bool failed() override { if (m_writer) return  m_writer->failed(); return true; };

    /// @brief Close file stream
    void close() override {
        if (m_writer)  m_writer->close();
        m_zstr->flush();
        if(dynamic_pointer_cast<ofstream>(m_zstr)) dynamic_pointer_cast<ofstream>(m_zstr)->close();
    }

    /// Set the act writer's GenRunInfo object.
    void set_run_info(std::shared_ptr<GenRunInfo> run) override {  if (m_writer) m_writer->set_run_info(run); }

    /// Get the act writer's GenRunInfo object.
    std::shared_ptr<GenRunInfo> run_info() const override { return m_writer?m_writer->run_info():nullptr; }

    /// Return writer
    std::shared_ptr<Writer> writer() { return m_writer;}

private:
    std::shared_ptr< std::ostream > m_zstr = nullptr;  ///< Stream to write
    std::shared_ptr<Writer> m_writer = nullptr; //!< actual writter

};

} // namespace HepMC3
#endif
