TEMPLATE = app
TARGET = hellosquare
OBJECTS_DIR = .obj
MOC_DIR = .moc

INCLUDEPATH += ../lib/Groot/depend/BehaviorTree.CPP/src/
INCLUDEPATH += ../lib/Groot/depend/BehaviorTree.CPP/include/

SOURCES += main.cpp 





# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/action_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/basic_types.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/behavior_tree.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/blackboard.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/bt_factory.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/decorator_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/condition_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/control_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/shared_library.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/tree_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/xml_parsing.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/decorators/inverter_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/decorators/repeat_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/decorators/retry_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/decorators/subtree_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/decorators/timeout_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/if_then_else_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/fallback_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/parallel_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/reactive_sequence.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/reactive_fallback.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/sequence_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/sequence_star_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/switch_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/controls/while_do_else_node.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/loggers/bt_cout_logger.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/loggers/bt_file_logger.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/loggers/bt_minitrace_logger.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/src/private/tinyxml2.cpp
# SOURCES += ../lib/Groot/depend/BehaviorTree.CPP/3rdparty/minitrace/minitrace.cpp

# lib/Groot/build/lib/libbehaviortree_cpp_v3.so \

LIBS += ../lib/Groot/build/lib/libbehaviortree_cpp_v3.so ../lib/Groot/build/libbehavior_tree_editor.a
# LIBS += -L"../lib/Groot/build/lib/" -lbehaviortree_cpp_v3.so



RESOURCES += main.qrc
QT += quick gui
