#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libevhtp::evhtp" for configuration "RelWithDebInfo"
set_property(TARGET libevhtp::evhtp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(libevhtp::evhtp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/evhtp.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/evhtp.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS libevhtp::evhtp )
list(APPEND _IMPORT_CHECK_FILES_FOR_libevhtp::evhtp "${_IMPORT_PREFIX}/lib/evhtp.lib" "${_IMPORT_PREFIX}/bin/evhtp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
