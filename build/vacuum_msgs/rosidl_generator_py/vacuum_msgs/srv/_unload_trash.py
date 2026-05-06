# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vacuum_msgs:srv/UnloadTrash.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UnloadTrash_Request(type):
    """Metaclass of message 'UnloadTrash_Request'."""

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
            module = import_type_support('vacuum_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vacuum_msgs.srv.UnloadTrash_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__unload_trash__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__unload_trash__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__unload_trash__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__unload_trash__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__unload_trash__request

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UnloadTrash_Request(metaclass=Metaclass_UnloadTrash_Request):
    """Message class 'UnloadTrash_Request'."""

    __slots__ = [
        '_robot_id',
        '_robot_pos',
    ]

    _fields_and_field_types = {
        'robot_id': 'string',
        'robot_pos': 'geometry_msgs/Point',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_id = kwargs.get('robot_id', str())
        from geometry_msgs.msg import Point
        self.robot_pos = kwargs.get('robot_pos', Point())

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
        if self.robot_id != other.robot_id:
            return False
        if self.robot_pos != other.robot_pos:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_id(self):
        """Message field 'robot_id'."""
        return self._robot_id

    @robot_id.setter
    def robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_id' field must be of type 'str'"
        self._robot_id = value

    @builtins.property
    def robot_pos(self):
        """Message field 'robot_pos'."""
        return self._robot_pos

    @robot_pos.setter
    def robot_pos(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'robot_pos' field must be a sub message of type 'Point'"
        self._robot_pos = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_UnloadTrash_Response(type):
    """Metaclass of message 'UnloadTrash_Response'."""

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
            module = import_type_support('vacuum_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vacuum_msgs.srv.UnloadTrash_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__unload_trash__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__unload_trash__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__unload_trash__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__unload_trash__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__unload_trash__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UnloadTrash_Response(metaclass=Metaclass_UnloadTrash_Response):
    """Message class 'UnloadTrash_Response'."""

    __slots__ = [
        '_success',
        '_score_gained',
        '_capacity_used',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'score_gained': 'int32',
        'capacity_used': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.score_gained = kwargs.get('score_gained', int())
        self.capacity_used = kwargs.get('capacity_used', int())

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
        if self.success != other.success:
            return False
        if self.score_gained != other.score_gained:
            return False
        if self.capacity_used != other.capacity_used:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def score_gained(self):
        """Message field 'score_gained'."""
        return self._score_gained

    @score_gained.setter
    def score_gained(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'score_gained' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'score_gained' field must be an integer in [-2147483648, 2147483647]"
        self._score_gained = value

    @builtins.property
    def capacity_used(self):
        """Message field 'capacity_used'."""
        return self._capacity_used

    @capacity_used.setter
    def capacity_used(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'capacity_used' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'capacity_used' field must be an unsigned integer in [0, 4294967295]"
        self._capacity_used = value


class Metaclass_UnloadTrash(type):
    """Metaclass of service 'UnloadTrash'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vacuum_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vacuum_msgs.srv.UnloadTrash')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__unload_trash

            from vacuum_msgs.srv import _unload_trash
            if _unload_trash.Metaclass_UnloadTrash_Request._TYPE_SUPPORT is None:
                _unload_trash.Metaclass_UnloadTrash_Request.__import_type_support__()
            if _unload_trash.Metaclass_UnloadTrash_Response._TYPE_SUPPORT is None:
                _unload_trash.Metaclass_UnloadTrash_Response.__import_type_support__()


class UnloadTrash(metaclass=Metaclass_UnloadTrash):
    from vacuum_msgs.srv._unload_trash import UnloadTrash_Request as Request
    from vacuum_msgs.srv._unload_trash import UnloadTrash_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
