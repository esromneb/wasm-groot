#include <QtGui>
#include <QtQuick>
#include <iostream>

using namespace std;




#include "behaviortree_cpp_v3/flatbuffers/bt_flatbuffer_helper.h"
#include "behaviortree_cpp_v3/bt_factory.h"
#include <iostream>

using namespace std;
using namespace BT;



static const char* xml_text_sequence = R"(

 <root main_tree_to_execute = "MainTree" >

     <BehaviorTree ID="MainTree">
        <Sequence name="root">
            <IsDoorOpen/>
            <IsDoorOpen/>
        </Sequence>
     </BehaviorTree>

 </root>
 )";


NodeStatus DummyFunction(void) {
    return NodeStatus::SUCCESS;
}

void tryBt(void) {
    BT::BehaviorTreeFactory factory;

    factory.registerSimpleCondition("IsDoorOpen", std::bind(DummyFunction));


    auto tree = factory.createTreeFromText(xml_text_sequence);

    for( const auto& n : tree.nodes ) {
        cout << n->registrationName() << "->" << n->UID() << "\n";
    }
}





















// #include <QCommandLineParser>
// #include <QApplication>
// #include <QDialog>
// #include <QFile>
// // #include <nodes/NodeStyle>
// // #include <nodes/FlowViewStyle>
// // #include <nodes/ConnectionStyle>
// // #include <nodes/DataModelRegistry>

// #include "mainwindow.h"
// #include "XML_utilities.hpp"
// #include "startup_dialog.h"

// // using QtNodes::DataModelRegistry;
// // using QtNodes::FlowViewStyle;
// // using QtNodes::NodeStyle;
// // using QtNodes::ConnectionStyle;

// int
// main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);
//     app.setApplicationName("Groot");
//     app.setWindowIcon(QPixmap(":/icons/BT.png"));
//     app.setOrganizationName("EurecatRobotics");
//     app.setOrganizationDomain("eurecat.org");

//     qRegisterMetaType<AbsBehaviorTree>();

//     QCommandLineParser parser;
//     parser.setApplicationDescription("Groot. The fancy BehaviorTree Editor");
//     parser.addHelpOption();

//     QCommandLineOption test_option(QStringList() << "t" << "test",
//                                    "Load dummy data");
//     parser.addOption(test_option);

//     QCommandLineOption mode_option(QStringList() << "mode",
//                                    "Start in one of these modes: [editor,monitor,replay]",
//                                    "mode");
//     parser.addOption(mode_option);
//     parser.process( app );

//     QFile styleFile( ":/stylesheet.qss" );
//     styleFile.open( QFile::ReadOnly );
//     QString style( styleFile.readAll() );
//     app.setStyleSheet( style );

//     // if( parser.isSet(test_option) )
//     // {
//         MainWindow win( GraphicMode::EDITOR );
//         win.setWindowTitle("Groot");
//         win.show();
//         win.loadFromXML( ":/crossdoor_with_subtree.xml" );
//         return app.exec();
//     // }
//     // else{
//     //     auto mode = GraphicMode::EDITOR;

//     //     if( parser.isSet(mode_option) )
//     //     {
//     //         QString opt_mode = parser.value(mode_option);
//     //         if( opt_mode == "editor")
//     //         {
//     //             mode = GraphicMode::EDITOR;
//     //         }
//     //         else if( opt_mode == "monitor")
//     //         {
//     //             mode = GraphicMode::MONITOR;
//     //         }
//     //         else if( opt_mode == "replay")
//     //         {
//     //             mode = GraphicMode::REPLAY;
//     //         }
//     //         else{
//     //             std::cout << "wrong mode passed to --mode. Use on of these: editor / monitor /replay"
//     //                       << std::endl;
//     //             return 0;
//     //         }
//     //     }
//     //     else{
//     //         StartupDialog dialog;
//     //         dialog.setWindowFlags( Qt::FramelessWindowHint );
//     //         if(dialog.exec() != QDialog::Accepted)
//     //         {
//     //             return 0;
//     //         }
//     //         mode = dialog.getGraphicMode();
//     //     }

//     //     MainWindow win( mode );
//     //     win.show();
//     //     return app.exec();
//     // }
// }


#include <QCommandLineParser>
#include <QApplication>
#include <QDialog>
#include <QFile>
#include "mainwindow.h"
#include "XML_utilities.hpp"
#include "startup_dialog.h"






int main2(int argc, char *argv[]);


// int main3(int argc, char **argv)
// {
//     QGuiApplication app(argc, argv);
    
//     QQuickView view;
//     view.setSource(QUrl("qrc:///main.qml"));
//     view.setResizeMode(QQuickView::SizeRootObjectToView);
//     view.showFullScreen();

//     tryBt();
//     cout << "Above exec" << std::endl;


//     qRegisterMetaType<AbsBehaviorTree>();


//     return app.exec();

//     // return main2(argc, argv);

// }

int main(int argc, char **argv) {

    QApplication app(argc, argv);
    app.setApplicationName("Groot");
    app.setWindowIcon(QPixmap(":/icons/BT.png"));
    app.setOrganizationName("EurecatRobotics");
    app.setOrganizationDomain("eurecat.org");

    qRegisterMetaType<AbsBehaviorTree>();

    QCommandLineParser parser;
    parser.setApplicationDescription("Groot. The fancy BehaviorTree Editor");
    parser.addHelpOption();

    QCommandLineOption test_option(QStringList() << "t" << "test",
                                   "Load dummy data");
    parser.addOption(test_option);

    QCommandLineOption mode_option(QStringList() << "mode",
                                   "Start in one of these modes: [editor,monitor,replay]",
                                   "mode");
    parser.addOption(mode_option);
    parser.process( app );

    QFile styleFile( ":/stylesheet.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    app.setStyleSheet( style );


  MainWindow win( GraphicMode::EDITOR );
std::cout << "empty: " << win.saveToXML().toStdString() << "\n";
win.setWindowTitle("Groot");
win.show();
return app.exec();

}
