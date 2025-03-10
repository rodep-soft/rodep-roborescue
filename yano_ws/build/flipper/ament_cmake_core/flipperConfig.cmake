# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_flipper_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED flipper_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(flipper_FOUND FALSE)
  elseif(NOT flipper_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(flipper_FOUND FALSE)
  endif()
  return()
endif()
set(_flipper_CONFIG_INCLUDED TRUE)

# output package information
if(NOT flipper_FIND_QUIETLY)
  message(STATUS "Found flipper: 0.0.0 (${flipper_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'flipper' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${flipper_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(flipper_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${flipper_DIR}/${_extra}")
endforeach()
