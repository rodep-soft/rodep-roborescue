# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:joy_controller__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:joy_controller__rosidl_typesupport_fastrtps_c;__rosidl_generator_cpp:joy_controller__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:joy_controller__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_c:joy_controller__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:joy_controller__rosidl_typesupport_c;__rosidl_typesupport_introspection_cpp:joy_controller__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:joy_controller__rosidl_typesupport_cpp;__rosidl_generator_py:joy_controller__rosidl_generator_py")

# populate joy_controller_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "joy_controller::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'joy_controller' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND joy_controller_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
