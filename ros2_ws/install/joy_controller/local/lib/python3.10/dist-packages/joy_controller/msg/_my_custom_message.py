# generated from rosidl_generator_py/resource/_idl.py.em
# with input from joy_controller:msg/MyCustomMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'my_axes'
# Member 'my_buttons'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MyCustomMessage(type):
    """Metaclass of message 'MyCustomMessage'."""

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
            module = import_type_support('joy_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'joy_controller.msg.MyCustomMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__my_custom_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__my_custom_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__my_custom_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__my_custom_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__my_custom_message

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MyCustomMessage(metaclass=Metaclass_MyCustomMessage):
    """Message class 'MyCustomMessage'."""

    __slots__ = [
        '_my_axes',
        '_my_buttons',
    ]

    _fields_and_field_types = {
        'my_axes': 'sequence<float>',
        'my_buttons': 'sequence<int32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.my_axes = array.array('f', kwargs.get('my_axes', []))
        self.my_buttons = array.array('i', kwargs.get('my_buttons', []))

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
        if self.my_axes != other.my_axes:
            return False
        if self.my_buttons != other.my_buttons:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def my_axes(self):
        """Message field 'my_axes'."""
        return self._my_axes

    @my_axes.setter
    def my_axes(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'my_axes' array.array() must have the type code of 'f'"
            self._my_axes = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'my_axes' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._my_axes = array.array('f', value)

    @builtins.property
    def my_buttons(self):
        """Message field 'my_buttons'."""
        return self._my_buttons

    @my_buttons.setter
    def my_buttons(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'my_buttons' array.array() must have the type code of 'i'"
            self._my_buttons = value
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
                "The 'my_buttons' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._my_buttons = array.array('i', value)
