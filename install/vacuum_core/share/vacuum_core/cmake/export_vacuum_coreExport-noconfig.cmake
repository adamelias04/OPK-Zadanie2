#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "vacuum_core::vacuum_core" for configuration ""
set_property(TARGET vacuum_core::vacuum_core APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(vacuum_core::vacuum_core PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libvacuum_core.so"
  IMPORTED_SONAME_NOCONFIG "libvacuum_core.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS vacuum_core::vacuum_core )
list(APPEND _IMPORT_CHECK_FILES_FOR_vacuum_core::vacuum_core "${_IMPORT_PREFIX}/lib/libvacuum_core.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
