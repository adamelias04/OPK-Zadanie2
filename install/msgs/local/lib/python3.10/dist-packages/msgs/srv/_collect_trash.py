# generated from rosidl_generator_py/resource/_idl.py.em
# with input from msgs:srv/CollectTrash.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CollectTrash_Request(type):
    """Metaclass of message 'CollectTrash_Request'."""

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
            module = import_type_support('msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'msgs.srv.CollectTrash_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__collect_trash__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__collect_trash__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__collect_trash__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__collect_trash__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__collect_trash__request

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


class CollectTrash_Request(metaclass=Metaclass_CollectTrash_Request):
    """Message class 'CollectTrash_Request'."""

    __slots__ = [
        '_robot_id',
        '_robot_pos',
        '_robot_radius',
    ]

    _fields_and_field_types = {
        'robot_id': 'string',
        'robot_pos': 'geometry_msgs/Point',
        'robot_radius': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_id = kwargs.get('robot_id', str())
        from geometry_msgs.msg import Point
        self.robot_pos = kwargs.get('robot_pos', Point())
        self.robot_radius = kwargs.get('robot_radius', float())

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
        if self.robot_radius != other.robot_radius:
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

    @builtins.property
    def robot_radius(self):
        """Message field 'robot_radius'."""
        return self._robot_radius

    @robot_radius.setter
    def robot_radius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_radius' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'robot_radius' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._robot_radius = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_CollectTrash_Response(type):
    """Metaclass of message 'CollectTrash_Response'."""

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
            module = import_type_support('msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'msgs.srv.CollectTrash_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__collect_trash__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__collect_trash__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__collect_trash__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__collect_trash__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__collect_trash__response

            from msgs.msg import TrashItem
            if TrashItem.__class__._TYPE_SUPPORT is None:
                TrashItem.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CollectTrash_Response(metaclass=Metaclass_CollectTrash_Response):
    """Message class 'CollectTrash_Response'."""

    __slots__ = [
        '_success',
        '_collected',
        '_capacity_used',
        '_capacity_max',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'collected': 'msgs/TrashItem',
        'capacity_used': 'uint32',
        'capacity_max': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['msgs', 'msg'], 'TrashItem'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        from msgs.msg import TrashItem
        self.collected = kwargs.get('collected', TrashItem())
        self.capacity_used = kwargs.get('capacity_used', int())
        self.capacity_max = kwargs.get('capacity_max', int())

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
        if self.collected != other.collected:
            return False
        if self.capacity_used != other.capacity_used:
            return False
        if self.capacity_max != other.capacity_max:
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
    def collected(self):
        """Message field 'collected'."""
        return self._collected

    @collected.setter
    def collected(self, value):
        if __debug__:
            from msgs.msg import TrashItem
            assert \
                isinstance(value, TrashItem), \
                "The 'collected' field must be a sub message of type 'TrashItem'"
        self._collected = value

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

    @builtins.property
    def capacity_max(self):
        """Message field 'capacity_max'."""
        return self._capacity_max

    @capacity_max.setter
    def capacity_max(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'capacity_max' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'capacity_max' field must be an unsigned integer in [0, 4294967295]"
        self._capacity_max = value


class Metaclass_CollectTrash(type):
    """Metaclass of service 'CollectTrash'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'msgs.srv.CollectTrash')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__collect_trash

            from msgs.srv import _collect_trash
            if _collect_trash.Metaclass_CollectTrash_Request._TYPE_SUPPORT is None:
                _collect_trash.Metaclass_CollectTrash_Request.__import_type_support__()
            if _collect_trash.Metaclass_CollectTrash_Response._TYPE_SUPPORT is None:
                _collect_trash.Metaclass_CollectTrash_Response.__import_type_support__()


class CollectTrash(metaclass=Metaclass_CollectTrash):
    from msgs.srv._collect_trash import CollectTrash_Request as Request
    from msgs.srv._collect_trash import CollectTrash_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
