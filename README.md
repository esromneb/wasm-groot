# wasm-groot



# See Also
* https://doc.qt.io/qt-5/wasm.html
* https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code


# Development
Getting this to build was at the edge of my capability.  I don't know much about Qt5 and so that did't help.

Before any of my changes the setup was this:
* Groot's top cmake includes BehaviorTree.CPP's cmake.  This builds behaviortree_cpp_v3
* Groot's top cmake includes QtNodeEditor's cmake. This builds a static lib libQtNodeEditor.a
* Groot's top cmake defines `behavior_tree_editor` which has all of Groot's cpp except for main
* Groot's top cmake defines `Groot` which has main and links against the rest

Now:
* I'm using a new qmake project to replace
