
// #include <QCommandLineParser>
// #include <QApplication>
// #include <QDialog>
// #include <nodes/NodeStyle>
// #include <nodes/FlowViewStyle>
// #include <nodes/ConnectionStyle>
// #include <nodes/DataModelRegistry>

// #include "mainwindow.h"
// #include "XML_utilities.hpp"
// #include "startup_dialog.h"
// #include "models/RootNodeModel.hpp"

// using QtNodes::DataModelRegistry;
// using QtNodes::FlowViewStyle;
// using QtNodes::NodeStyle;
// using QtNodes::ConnectionStyle;

// int
// main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);
//     app.setApplicationName("Groot");
// }


#include <iostream>

using namespace std;

int side(const int a);

void longFunction(void);

int main(void) {
    cout << "Hello world " << side(1) << "\n";

    longFunction();
}