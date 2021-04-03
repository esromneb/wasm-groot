# wasm-groot
The goal of this project is to get Groot to run 100% on the web. This project uses the qt5 wasm, but is stuck, and work-in-progress. I can't get threads to work in wasm as of now, and about 10% of this project uses this as a callback method. If I can remove these callbacks I can finally get this to work.

# Travis
The Travis CI is here https://travis-ci.com/github/esromneb/wasm-groot

# Instructions
I'm using a docker from https://hub.docker.com/repository/docker/esromneb/qt-wasm

From inside the docker:
```bash
cd cd lib/Groot && mkdir build && cd build && cmake .. -DQT5PATH=/home/emscripten/qt5/qtbase/lib/cmake/Qt5 && make -j2
cd project && qmake && make -j2
```

From your host:
```bash
sudo python -m SimpleHTTPServer 9000
```



# Development
Getting this to build was at the edge of my capability.  I don't know much about Qt5 and so that did't help.

Before any of my changes the setup was this:
* Groot's top cmake includes BehaviorTree.CPP's cmake.  This builds behaviortree_cpp_v3
* Groot's top cmake includes QtNodeEditor's cmake. This builds a static lib libQtNodeEditor.a
* Groot's top cmake defines `behavior_tree_editor` which has all of Groot's cpp except for main
* Groot's top cmake defines `Groot` which has main and links against the rest

Now:
* I'm using a new qmake project to replace the Groot target.
Becaues cmake uses auto moc and auto rrc on the Groot target, I had to make a custom hand edited version of the resource file (`project/groot.grc`)
* In the qmake project, I directly link to the `libbehaviortree_cpp_v3.so` `libQtNodeEditor.a` files.  This means that the cmake project needs to be built first, then the qmake project.



# See Also
* https://doc.qt.io/qt-5/wasm.html
* https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code
* https://www.qt.io/blog/2019/06/26/qt-webassembly-multithreading
