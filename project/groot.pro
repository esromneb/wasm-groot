TEMPLATE = app
TARGET = groot
OBJECTS_DIR = .obj
MOC_DIR = .moc

INCLUDEPATH += ../lib/Groot/depend/BehaviorTree.CPP/src/
INCLUDEPATH += ../lib/Groot/depend/BehaviorTree.CPP/include/
INCLUDEPATH += ../lib/Groot/bt_editor/
INCLUDEPATH += ../lib/Groot/bt_editor/models
INCLUDEPATH += ../lib/Groot/
INCLUDEPATH += ../lib/Groot/QtNodeEditor/include

DEFINES += NODE_EDITOR_STATIC

SOURCES += main.cpp 
# SOURCES += ../lib/Groot/bt_editor/main.cpp

FORMS += ../lib/Groot/bt_editor/about_dialog.ui
FORMS += ../lib/Groot/bt_editor/mainwindow.ui
FORMS += ../lib/Groot/bt_editor/action_form.ui
FORMS += ../lib/Groot/bt_editor/sidepanel_editor.ui
FORMS += ../lib/Groot/bt_editor/sidepanel_replay.ui
FORMS += ../lib/Groot/bt_editor/startup_dialog.ui
FORMS += ../lib/Groot/bt_editor/custom_node_dialog.ui
FORMS += ../lib/Groot/bt_editor/sidepanel_monitor.ui




SOURCES += ../lib/Groot/bt_editor/models/BehaviorTreeNodeModel.cpp
SOURCES += ../lib/Groot/bt_editor/models/SubtreeNodeModel.cpp
SOURCES += ../lib/Groot/bt_editor/mainwindow.cpp
SOURCES += ../lib/Groot/bt_editor/editor_flowscene.cpp
SOURCES += ../lib/Groot/bt_editor/utils.cpp
SOURCES += ../lib/Groot/bt_editor/bt_editor_base.cpp
SOURCES += ../lib/Groot/bt_editor/graphic_container.cpp
SOURCES += ../lib/Groot/bt_editor/startup_dialog.cpp
SOURCES += ../lib/Groot/bt_editor/sidepanel_editor.cpp
SOURCES += ../lib/Groot/bt_editor/sidepanel_replay.cpp
SOURCES += ../lib/Groot/bt_editor/custom_node_dialog.cpp
SOURCES += ../lib/Groot/bt_editor/XML_utilities.cpp
SOURCES += ../lib/Groot/bt_editor/sidepanel_monitor.cpp
# SOURCES += ../lib/Groot/bt_editor/models/RootNodeModel.cpp


HEADERS += ../lib/Groot/QtNodeEditor/include/nodes/internal/*.hpp
HEADERS += ../lib/Groot/bt_editor/*.h
HEADERS += ../lib/Groot/bt_editor/models/*.hpp



# lib/Groot/build/lib/libbehaviortree_cpp_v3.so \

LIBS += ../lib/Groot/build/lib/libbehaviortree_cpp_v3.so
LIBS += ../lib/Groot/build/lib/libQtNodeEditor.a

# LIBS += ../lib/Groot/build/libbehavior_tree_editor.a
# LIBS += ../lib/Groot/build/libGroot.so
# LIBS += ../lib/Groot/build/lib/libbehaviortree_cpp_v3.so ../lib/Groot/build/libbehavior_tree_editor.a
# LIBS += -L"../lib/Groot/build/lib/" -lbehaviortree_cpp_v3.so



RESOURCES += main.qrc
RESOURCES += groot.qrc
RESOURCES += ../lib/Groot/bt_editor/resources/icons.qrc


QT += quick gui core widgets svg xml
