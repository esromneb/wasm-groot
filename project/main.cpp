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































int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    
    QQuickView view;
    view.setSource(QUrl("qrc:///main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.showFullScreen();

    tryBt();
    cout << "Above exec" << std::endl;

    return app.exec();
}
