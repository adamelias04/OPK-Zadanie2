# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vacuum_msgs:msg/RobotStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotStatus(type):
    """Metaclass of message 'RobotStatus'."""

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
                'vacuum_msgs.msg.RobotStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_status

            from geometry_msgs.msg import Pose2D
            if Pose2D.__class__._TYPE_SUPPORT is None:
                Pose2D.__class__.__import_type_support__()

            from geometry_msgs.msg import Twist
            if Twist.__class__._TYPE_SUPPORT is None:
                Twist.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotStatus(metaclass=Metaclass_RobotStatus):
    """Message class 'RobotStatus'."""

    __slots__ = [
        '_robot_id',
        '_pose',
        '_velocity',
        '_capacity_used',
        '_capacity_max',
        '_in_collision',
    ]

    _fields_and_field_types = {
        'robot_id': 'string',
        'pose': 'geometry_msgs/Pose2D',
        'velocity': 'geometry_msgs/Twist',
        'capacity_used': 'uint32',
        'capacity_max': 'uint32',
        'in_collision': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose2D'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Twist'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_id = kwargs.get('robot_id', str())
        from geometry_msgs.msg import Pose2D
        self.pose = kwargs.get('pose', Pose2D())
        from geometry_msgs.msg import Twist
        self.velocity = kwargs.get('velocity', Twist())
        self.capacity_used = kwargs.get('capacity_used', int())
        self.capacity_max = kwargs.get('capacity_max', int())
        self.in_collision = kwargs.get('in_collision', bool())

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
        if self.pose != other.pose:
            return False
        if self.velocity != other.velocity:
            return False
        if self.capacity_used != other.capacity_used:
            return False
        if self.capacity_max != other.capacity_max:
            return False
        if self.in_collision != other.in_collision:
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
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose2D
            assert \
                isinstance(value, Pose2D), \
                "The 'pose' field must be a sub message of type 'Pose2D'"
        self._pose = value

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Twist
            assert \
                isinstance(value, Twist), \
                "The 'velocity' field must be a sub message of type 'Twist'"
        self._velocity = value

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

    @builtins.property
    def in_collision(self):
        """Message field 'in_collision'."""
        return self._in_collision

    @in_collision.setter
    def in_collision(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'in_collision' field must be of type 'bool'"
        self._in_collision = value
