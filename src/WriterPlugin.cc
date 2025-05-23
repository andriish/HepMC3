// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2023 The HepMC collaboration (see AUTHORS for details)
//
///
/// @file WriterPlugin.cc
/// @brief Implementation of \b class WriterPlugin
///
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#define NOWINBASEINTERLOCK
#define NOMINMAX
#undef UNICODE
#include <intrin.h>
#include <windows.h>
#endif
#if defined(__linux__) || defined(__darwin__) || defined(__APPLE__) || defined(BSD) || defined(__sun)
#include <dlfcn.h>
#endif
#include <sstream>
#include <cstring>
#include "HepMC3/GenEvent.h"
#include "HepMC3/WriterPlugin.h"



namespace HepMC3 {


WriterPlugin::WriterPlugin(std::shared_ptr<std::ostream> stream, const std::string &libname, const std::string &newwriter, std::shared_ptr<GenRunInfo> run) {
#ifdef WIN32
    dll_handle = LoadLibrary(libname.c_str());
    if (!dll_handle) { printf("Error  while loading library %s. Error code %i\n", libname.c_str(), GetLastError()); m_writer = nullptr; return;  }
    typedef Writer* (__stdcall *f_funci)(std::shared_ptr<std::ostream> stream, std::shared_ptr<GenRunInfo>);
    f_funci newWriter = (f_funci)GetProcAddress((HINSTANCE)(dll_handle), newwriter.c_str());
    if (!newWriter) { printf("Error  while loading function %s from  library %s. Error code %i\n", newwriter.c_str(), libname.c_str(), GetLastError()); m_writer = nullptr; return;  }
    m_writer = (Writer*)(newWriter(stream, run));
#endif

#if defined(__linux__) || defined(__darwin__) || defined(__APPLE__) || defined(BSD) || defined(__sun)
    dll_handle = dlopen(libname.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!dll_handle) { printf("Error  while loading library %s: %s\n", libname.c_str(), dlerror()); m_writer=nullptr; return;  }
    using f_funci =  Writer* (*)(std::shared_ptr<std::ostream> stream, std::shared_ptr<GenRunInfo>);
    auto newWriter = (f_funci)dlsym(dll_handle, newwriter.c_str());
    if (!newWriter) { printf("Error  while loading function %s from  library %s: %s\n", newwriter.c_str(), libname.c_str(), dlerror()); m_writer = nullptr; return;   }
    m_writer = (Writer*)(newWriter(stream, run));
#endif
}

WriterPlugin::WriterPlugin(std::ostream & stream, const std::string &libname, const std::string &newwriter, std::shared_ptr<GenRunInfo> run) {
#ifdef WIN32
    dll_handle = LoadLibrary(libname.c_str());
    if (!dll_handle) { printf("Error  while loading library %s. Error code %i\n", libname.c_str(), GetLastError()); m_writer = nullptr; return;  }
    typedef Writer* (__stdcall *f_funci)(std::ostream & stream, std::shared_ptr<GenRunInfo>);
    f_funci newWriter = (f_funci)GetProcAddress((HINSTANCE)(dll_handle), newwriter.c_str());
    if (!newWriter) { printf("Error  while loading function %s from  library %s. Error code %i\n", newwriter.c_str(), libname.c_str(), GetLastError()); m_writer = nullptr; return;  }
    m_writer = (Writer*)(newWriter(stream, run));
#endif

#if defined(__linux__) || defined(__darwin__) || defined(__APPLE__) || defined(BSD) || defined(__sun)
    dll_handle = dlopen(libname.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!dll_handle) { printf("Error  while loading library %s: %s\n", libname.c_str(), dlerror()); m_writer=nullptr; return;  }
    using f_funci =  Writer* (*)(std::ostream & stream, std::shared_ptr<GenRunInfo>);
    auto newWriter = (f_funci)dlsym(dll_handle, newwriter.c_str());
    if (!newWriter) { printf("Error  while loading function %s from  library %s: %s\n", newwriter.c_str(), libname.c_str(), dlerror()); m_writer = nullptr; return;   }
    m_writer = (Writer*)(newWriter(stream, run));
#endif
}

WriterPlugin::WriterPlugin(const std::string& filename, const std::string &libname, const std::string &newwriter, std::shared_ptr<GenRunInfo> run) {
#ifdef WIN32
    dll_handle = LoadLibrary(libname.c_str());
    if (!dll_handle) { printf("Error while loading library %s. Error code %i\n", libname.c_str(), GetLastError()); m_writer = nullptr; return;  }
    typedef Writer* (__stdcall *f_funci)(const std::string&, std::shared_ptr<GenRunInfo>);
    f_funci newWriter = (f_funci)GetProcAddress((HINSTANCE)(dll_handle), newwriter.c_str());
    if (!newWriter) { printf("Error while loading function %s from  library %s. Error code %i\n", newwriter.c_str(), libname.c_str(), GetLastError()); m_writer = nullptr; return;  }
    m_writer = (Writer*)(newWriter(filename, run));
#endif

#if defined(__linux__) || defined(__darwin__) || defined(__APPLE__) || defined(BSD) || defined(__sun)
    dll_handle = dlopen(libname.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!dll_handle) { printf("Error while loading library %s: %s\n", libname.c_str(), dlerror()); m_writer = nullptr; return;  }
    using f_funci =  Writer* (*)(const std::string&, std::shared_ptr<GenRunInfo>);
    auto newWriter = (f_funci)dlsym(dll_handle, newwriter.c_str());
    if (!newWriter) { printf("Error while loading function %s from  library %s: %s\n", newwriter.c_str(), libname.c_str(), dlerror()); m_writer = nullptr; return;   }
    m_writer = (Writer*)(newWriter(filename, run));
#endif
}

WriterPlugin::~WriterPlugin() {
    if (m_writer) m_writer->close();
    delete m_writer;
#ifdef WIN32
    if (dll_handle) {
        FreeLibrary((HINSTANCE)dll_handle);
    }
#endif
#if defined(__linux__) || defined(__darwin__) || defined(__APPLE__) || defined(BSD) || defined(__sun)
    if (dll_handle) {
        dlclose(dll_handle);
        dll_handle = nullptr;
    }
#endif
}
} // namespace HepMC3
