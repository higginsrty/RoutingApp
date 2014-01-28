#include "stdafx.h"

void connect_model_actionbar(QObject *action_bar, Model *model);
void connect_model_menu(QObject *menu, Model *model);

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    QObject *main_panel;
    viewer.setMainQmlFile(QStringLiteral("qml/NetworkSim/main.qml"));
    QObject *root = viewer.rootObject();
    main_panel = root->findChild<QObject*>("MainPanel");

    // Connecting the GUI to the model
    // Controller code
    QObject *action_bar = main_panel->findChild<QObject*>("action_bar");
    QObject *menu = main_panel->findChild<QObject*>("menu");
    Model *model = new Model();

    connect_model_actionbar(action_bar, model);
    connect_model_menu(menu, model);

    // Engine to draw the QML files
    QQmlEngine *engine = viewer.engine();

    // Main Graph object
    Graph *main_graph = new Graph(main_panel, engine);

    Node *n1 = main_graph->add_node("node1", 100, 100, 23);
    Node *n2 = main_graph->add_node("node2", 200,200,40);
    Node *n3 = main_graph->add_node("node3", 400,400, 20);

    main_graph->add_link(n1, n2, 100);
    main_graph->add_link(n2,n3,120);
    main_graph->add_link(n3, n1, 200);

    viewer.showExpanded();
    return app.exec();
}

void connect_model_actionbar(QObject* action_bar, Model *model)
{
    QObject::connect(action_bar, SIGNAL(onStart()), model, SLOT(start_sim()));
    QObject::connect(action_bar, SIGNAL(onPause()), model, SLOT(pause_sim()));
    QObject::connect(action_bar, SIGNAL(onResume()), model, SLOT(resume_sim()));
    QObject::connect(action_bar, SIGNAL(onReset()), model, SLOT(reset_sim()));
    QObject::connect(action_bar, SIGNAL(onStep()), model, SLOT(step_sim()));
}

void connect_model_menu(QObject *menu, Model *model)
{

}
