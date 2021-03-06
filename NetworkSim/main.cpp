#include "stdafx.h"

void connect_model_actionbar(QObject *action_bar, Model *model);
void connect_model_menu(QObject *menu, Model *model);

int main(int argc, char *argv[])
{ try {
    bool android = false;
    QApplication app(argc, argv);

#ifdef Q_OS_ANDROID
    android = true;
    QQmlApplicationEngine *engine = new QQmlApplicationEngine(QUrl("qrc:/qml_files/main.qml"));
#else
    QQmlApplicationEngine *engine = new QQmlApplicationEngine(QUrl("qrc:/qml_files/main.qml"));
#endif
    QObject *main_panel;
    QObject *root = *engine->rootObjects().begin();
    if (root == NULL)
        return -1;
    main_panel = root->findChild<QObject*>("MainPanel");
    if (main_panel == NULL)
        return -1;
    // Connecting the GUI to the model
    // Controller codes
    QQmlComponent cmp(engine, QUrl("qrc:/qml_files/menu.qml"));
    QObject *menu = cmp.create();
    QQuickItem *menu_item = qobject_cast<QQuickItem*>(menu);
    QQuickItem *panel_item = qobject_cast<QQuickItem*>(main_panel);
    menu_item->setParentItem(panel_item);
    menu_item->setProperty("height", panel_item->height());
    menu_item->setProperty("width", panel_item->width() / 2);
    menu_item->setProperty("x", menu_item->width() * -0.9);
    if (android)
        menu_item->setProperty("anchors.bottom", panel_item->property("anchors.bottom"));

    Model *model = new Model();

    connect_model_actionbar(root, model);
    connect_model_menu(menu, model);

    // Main Graph object
    Graph *main_graph = new Graph(main_panel, engine);

    // This works now!
    model->set_graph(*main_graph);

    Node *n1 = main_graph->add_node("node1", 100, 100, 23);
    Node *n2 = main_graph->add_node("node2", 400, 200, 40);
    Node *n3 = main_graph->add_node("node3", 550, 400, 20);
    Node *n4 = main_graph->add_node("node4", 500, 50, 27);
    Node *n5 = main_graph->add_node("node5", 600, 250, 30);
    Node *n6 = main_graph->add_node("node6", 400, 250, 31);
    Node *n7 = main_graph->add_node("node7", 300, 400, 21);
    main_graph->add_link(n1, n2, 2000);
    main_graph->add_link(n2, n3, 1200);
    main_graph->add_link(n1, n3, 2000);
    main_graph->add_link(n1, n4, 1250);
    main_graph->add_link(n2, n5, 1600);
    main_graph->add_link(n5, n7, 1400);
    main_graph->add_link(n3, n5, 1600);
    main_graph->add_link(n5, n6, 1400);
    n1->set_source(true);

    return app.exec();
    }
    catch (std::exception &e)
    {
        qDebug() << e.what();
    }

}

void connect_model_actionbar(QObject* root, Model *model)
{
    QObject::connect(root, SIGNAL(onStart()), model, SLOT(start_sim()));
    QObject::connect(root, SIGNAL(onPause()), model, SLOT(pause_sim()));
    QObject::connect(root, SIGNAL(onResume()), model, SLOT(resume_sim()));
    QObject::connect(root, SIGNAL(onReset()), model, SLOT(reset_sim()));
    QObject::connect(root, SIGNAL(onStop()), model, SLOT(stop_sim()));
}

void connect_model_menu(QObject *menu, Model *model)
{
    QObject::connect(menu, SIGNAL(create_node()), model, SLOT(create_node()));
}
