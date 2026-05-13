# generated from rosidl_generator_py/resource/_idl.py.em
# with input from msgs:msg/GameState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GameState(type):
    """Metaclass of message 'GameState'."""

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
                'msgs.msg.GameState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__game_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__game_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__game_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__game_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__game_state

            from msgs.msg import RobotStatus
            if RobotStatus.__class__._TYPE_SUPPORT is None:
                RobotStatus.__class__.__import_type_support__()

            from msgs.msg import TrashCount
            if TrashCount.__class__._TYPE_SUPPORT is None:
                TrashCount.__class__.__import_type_support__()

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


class GameState(metaclass=Metaclass_GameState):
    """Message class 'GameState'."""

    __slots__ = [
        '_mode',
        '_phase',
        '_elapsed_seconds',
        '_score',
        '_collected',
        '_active_trash',
        '_robots',
        '_winner',
    ]

    _fields_and_field_types = {
        'mode': 'string',
        'phase': 'string',
        'elapsed_seconds': 'float',
        'score': 'int32',
        'collected': 'sequence<msgs/TrashCount>',
        'active_trash': 'sequence<msgs/TrashItem>',
        'robots': 'sequence<msgs/RobotStatus>',
        'winner': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['msgs', 'msg'], 'TrashCount')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['msgs', 'msg'], 'TrashItem')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['msgs', 'msg'], 'RobotStatus')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mode = kwargs.get('mode', str())
        self.phase = kwargs.get('phase', str())
        self.elapsed_seconds = kwargs.get('elapsed_seconds', float())
        self.score = kwargs.get('score', int())
        self.collected = kwargs.get('collected', [])
        self.active_trash = kwargs.get('active_trash', [])
        self.robots = kwargs.get('robots', [])
        self.winner = kwargs.get('winner', str())

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
        if self.mode != other.mode:
            return False
        if self.phase != other.phase:
            return False
        if self.elapsed_seconds != other.elapsed_seconds:
            return False
        if self.score != other.score:
            return False
        if self.collected != other.collected:
            return False
        if self.active_trash != other.active_trash:
            return False
        if self.robots != other.robots:
            return False
        if self.winner != other.winner:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mode' field must be of type 'str'"
        self._mode = value

    @builtins.property
    def phase(self):
        """Message field 'phase'."""
        return self._phase

    @phase.setter
    def phase(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'phase' field must be of type 'str'"
        self._phase = value

    @builtins.property
    def elapsed_seconds(self):
        """Message field 'elapsed_seconds'."""
        return self._elapsed_seconds

    @elapsed_seconds.setter
    def elapsed_seconds(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'elapsed_seconds' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'elapsed_seconds' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._elapsed_seconds = value

    @builtins.property
    def score(self):
        """Message field 'score'."""
        return self._score

    @score.setter
    def score(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'score' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'score' field must be an integer in [-2147483648, 2147483647]"
        self._score = value

    @builtins.property
    def collected(self):
        """Message field 'collected'."""
        return self._collected

    @collected.setter
    def collected(self, value):
        if __debug__:
            from msgs.msg import TrashCount
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
                 all(isinstance(v, TrashCount) for v in value) and
                 True), \
                "The 'collected' field must be a set or sequence and each value of type 'TrashCount'"
        self._collected = value

    @builtins.property
    def active_trash(self):
        """Message field 'active_trash'."""
        return self._active_trash

    @active_trash.setter
    def active_trash(self, value):
        if __debug__:
            from msgs.msg import TrashItem
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
                 all(isinstance(v, TrashItem) for v in value) and
                 True), \
                "The 'active_trash' field must be a set or sequence and each value of type 'TrashItem'"
        self._active_trash = value

    @builtins.property
    def robots(self):
        """Message field 'robots'."""
        return self._robots

    @robots.setter
    def robots(self, value):
        if __debug__:
            from msgs.msg import RobotStatus
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
                 all(isinstance(v, RobotStatus) for v in value) and
                 True), \
                "The 'robots' field must be a set or sequence and each value of type 'RobotStatus'"
        self._robots = value

    @builtins.property
    def winner(self):
        """Message field 'winner'."""
        return self._winner

    @winner.setter
    def winner(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'winner' field must be of type 'str'"
        self._winner = value
