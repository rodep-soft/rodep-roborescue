# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/DriverVelocity.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'flipper_vel'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DriverVelocity(type):
    """Metaclass of message 'DriverVelocity'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.msg.DriverVelocity')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__driver_velocity
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__driver_velocity
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__driver_velocity
            cls._TYPE_SUPPORT = module.type_support_msg__msg__driver_velocity
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__driver_velocity

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DriverVelocity(metaclass=Metaclass_DriverVelocity):
    """Message class 'DriverVelocity'."""

    __slots__ = [
        '_m1_vel',
        '_m2_vel',
        '_flipper_vel',
    ]

    _fields_and_field_types = {
        'm1_vel': 'float',
        'm2_vel': 'float',
        'flipper_vel': 'sequence<int32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.m1_vel = kwargs.get('m1_vel', float())
        self.m2_vel = kwargs.get('m2_vel', float())
        self.flipper_vel = array.array('i', kwargs.get('flipper_vel', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.m1_vel != other.m1_vel:
            return False
        if self.m2_vel != other.m2_vel:
            return False
        if self.flipper_vel != other.flipper_vel:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def m1_vel(self):
        """Message field 'm1_vel'."""
        return self._m1_vel

    @m1_vel.setter
    def m1_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm1_vel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm1_vel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m1_vel = value

    @builtins.property
    def m2_vel(self):
        """Message field 'm2_vel'."""
        return self._m2_vel

    @m2_vel.setter
    def m2_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm2_vel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm2_vel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m2_vel = value

    @builtins.property
    def flipper_vel(self):
        """Message field 'flipper_vel'."""
        return self._flipper_vel

    @flipper_vel.setter
    def flipper_vel(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'flipper_vel' array.array() must have the type code of 'i'"
            self._flipper_vel = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'flipper_vel' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._flipper_vel = array.array('i', value)
