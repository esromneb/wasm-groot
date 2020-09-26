
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

#include "behaviortree_cpp_v3/flatbuffers/bt_flatbuffer_helper.h"
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

static const char* xml_text_reactive = R"(

 <root main_tree_to_execute = "MainTree" >

     <BehaviorTree ID="MainTree">
        <ReactiveSequence name="root">
            <BatteryOK/>
            <Sequence>
                <SaySomething   message="mission started..." />
                <MoveBase       goal="1;2;3"/>
                <SaySomething   message="mission completed!" />
            </Sequence>
        </ReactiveSequence>
     </BehaviorTree>

 </root>
 )";

#include "behaviortree_cpp_v3/bt_factory.h"

NodeStatus DummyFunction(void) {



    return NodeStatus::SUCCESS;
}


void tryBt(void) {
    BT::BehaviorTreeFactory factory;

    // factory.registerNodeType<BT::SubtreeNode>("Root");
    factory.registerSimpleCondition("IsDoorOpen", std::bind(DummyFunction));


    auto tree = factory.createTreeFromText(xml_text_sequence);

     for( const auto& n : tree.nodes ) {
            cout << n->registrationName() << "->" << n->UID() << "\n";
            // node_names.push_back(n->registrationName());

            // const auto uid = n->UID();

            // node_ids.push_back(uid);
            // largestUid = std::max(largestUid, uid);

            // // this makes sure that children_ids
            // // has an (empty) vector for every single
            // // uid
            // // we can use this as a quick way in
            // // logTransition to tell if a uid is valid
            // if( children_ids.count(uid) == 0 ) {
            //     children_ids[uid] = {};
            // }
        }

}



int side(const int a);

// void longFunction(void);

int main(void) {
    cout << "Hello world " << side(1) << "\n";

    tryBt();
    cout << "Hello world " << side(1) << "\n";

    // longFunction();
}