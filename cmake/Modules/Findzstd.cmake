# Based on https://github.com/llvm/llvm-project/blob/main/llvm/cmake/modules/Findzstd.cmake
# Try to find the zstd library
#
# If successful, the following variables will be defined:
# zstd_INCLUDE_DIR
# zstd_LIBRARY
# zstd_STATIC_LIBRARY
# zstd_FOUND
# zstd_VERSION
#
# Additionally, one of the following import targets will be defined:
# zstd::libzstd_shared
# zstd::libzstd_static

if(MSVC)
  set(zstd_STATIC_LIBRARY_SUFFIX "_static\\${CMAKE_STATIC_LIBRARY_SUFFIX}$")
else()
  set(zstd_STATIC_LIBRARY_SUFFIX "\\${CMAKE_STATIC_LIBRARY_SUFFIX}$")
endif()

find_path(zstd_INCLUDE_DIR NAMES zstd.h)
find_library(zstd_LIBRARY NAMES zstd zstd_static)
find_library(zstd_STATIC_LIBRARY NAMES
  zstd_static
  "${CMAKE_STATIC_LIBRARY_PREFIX}zstd${CMAKE_STATIC_LIBRARY_SUFFIX}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    zstd DEFAULT_MSG
    zstd_LIBRARY zstd_INCLUDE_DIR
)

if(zstd_FOUND)
  file(STRINGS ${zstd_INCLUDE_DIR}/zstd.h ZSTD_VERSION_MAJOR_STRING_CONTENT REGEX "^#define[ ]+ZSTD_VERSION_MAJOR[ ]+" )
  file(STRINGS ${zstd_INCLUDE_DIR}/zstd.h ZSTD_VERSION_MINOR_STRING_CONTENT REGEX "^#define[ ]+ZSTD_VERSION_MINOR[ ]+" )
  file(STRINGS ${zstd_INCLUDE_DIR}/zstd.h ZSTD_VERSION_RELEASE_STRING_CONTENT REGEX "^#define[ ]+ZSTD_VERSION_RELEASE[ ]+" )
  set(zstd_VERSION "0.0.0")
  if (ZSTD_VERSION_MAJOR_STRING_CONTENT AND ZSTD_VERSION_MINOR_STRING_CONTENT AND ZSTD_VERSION_RELEASE_STRING_CONTENT)
      string(REGEX MATCH "[1234567890.]+[a-zA-Z]*" ZSTD_VERSION_MAJOR ${ZSTD_VERSION_MAJOR_STRING_CONTENT})
      string(REGEX MATCH "[1234567890.]+[a-zA-Z]*" ZSTD_VERSION_MINOR ${ZSTD_VERSION_MINOR_STRING_CONTENT})
      string(REGEX MATCH "[1234567890.]+[a-zA-Z]*" ZSTD_VERSION_RELEASE ${ZSTD_VERSION_RELEASE_STRING_CONTENT})
      set(zstd_VERSION "${ZSTD_VERSION_MAJOR}.${ZSTD_VERSION_MINOR}.${ZSTD_VERSION_RELEASE}")
  endif()
  if(zstd_LIBRARY MATCHES "${zstd_STATIC_LIBRARY_SUFFIX}$")
    set(zstd_STATIC_LIBRARY "${zstd_LIBRARY}")
  elseif (NOT TARGET zstd::libzstd_shared)
    add_library(zstd::libzstd_shared SHARED IMPORTED)
    if(MSVC)
      # IMPORTED_LOCATION is the path to the DLL and IMPORTED_IMPLIB is the "library".
      get_filename_component(zstd_DIRNAME "${zstd_LIBRARY}" DIRECTORY)
      string(REGEX REPLACE "${CMAKE_INSTALL_LIBDIR}$" "${CMAKE_INSTALL_BINDIR}" zstd_DIRNAME "${zstd_DIRNAME}")
      get_filename_component(zstd_BASENAME "${zstd_LIBRARY}" NAME)
      string(REGEX REPLACE "\\${CMAKE_LINK_LIBRARY_SUFFIX}$" "${CMAKE_SHARED_LIBRARY_SUFFIX}" zstd_BASENAME "${zstd_BASENAME}")
      set_target_properties(zstd::libzstd_shared PROPERTIES
          INTERFACE_INCLUDE_DIRECTORIES "${zstd_INCLUDE_DIR}"
          IMPORTED_LOCATION "${zstd_DIRNAME}/${zstd_BASENAME}"
          IMPORTED_IMPLIB "${zstd_LIBRARY}")
      unset(zstd_DIRNAME)
      unset(zstd_BASENAME)
    else()
      set_target_properties(zstd::libzstd_shared PROPERTIES
          INTERFACE_INCLUDE_DIRECTORIES "${zstd_INCLUDE_DIR}"
          IMPORTED_LOCATION "${zstd_LIBRARY}")
    endif()
  endif()
  if(zstd_STATIC_LIBRARY MATCHES "${zstd_STATIC_LIBRARY_SUFFIX}$" AND
     NOT TARGET zstd::libzstd_static)
    add_library(zstd::libzstd_static STATIC IMPORTED)
    set_target_properties(zstd::libzstd_static PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${zstd_INCLUDE_DIR}"
        IMPORTED_LOCATION "${zstd_STATIC_LIBRARY}")
  endif()
endif()

unset(zstd_STATIC_LIBRARY_SUFFIX)


include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(zstd REQUIRED_VARS zstd_INCLUDE_DIR zstd_LIBRARY
                               VERSION_VAR zstd_VERSION
                               )

mark_as_advanced(zstd_INCLUDE_DIR zstd_LIBRARY zstd_STATIC_LIBRARY zstd_VERSION)
