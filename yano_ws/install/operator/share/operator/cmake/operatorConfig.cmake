# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_operator_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED operator_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(operator_FOUND FALSE)
  elseif(NOT operator_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(operator_FOUND FALSE)
  endif()
  return()
endif()
set(_operator_CONFIG_INCLUDED TRUE)

# output package information
if(NOT operator_FIND_QUIETLY)
  message(STATUS "Found operator: 0.0.0 (${operator_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'operator' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${operator_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(operator_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${operator_DIR}/${_extra}")
endforeach()
