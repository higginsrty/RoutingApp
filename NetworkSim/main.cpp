#include "stdafx.h"

void connect_model_actionbar(QObject *action_bar, Model *model);
void connect_model_menu(QObject *menu, Model *model);

int main(int argc, char *argv[])
{
    bool android = false;
    QApplication app(argc, argv);

#ifdef Q_OS_ANDROID
    android = true;
    QQmlApplicationEngine *engine = new QQmlApplicationEngine(QUrl("qrc:/qml_files/main_android.qml"));
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

    Node *n1 = main_graph->add_node("node1", 100, 100, 23);
    Node *n2 = main_graph->add_node("node2", 200,200,40);
    Node *n3 = main_graph->add_node("node3", 400,400, 20);

    main_graph->add_link(n1, n2, 100);
    main_graph->add_link(n2,n3,120);
    main_graph->add_link(n3, n1, 200);
    return app.exec();
}

void connect_model_actionbar(QObject* root, Model *model)
{
    QObject::connect(root, SIGNAL(onStart()), model, SLOT(start_sim()));
    QObject::connect(root, SIGNAL(onPause()), model, SLOT(pause_sim()));
    QObject::connect(root, SIGNAL(onResume()), model, SLOT(resume_sim()));
    QObject::connect(root, SIGNAL(onReset()), model, SLOT(reset_sim()));
    QObject::connect(root, SIGNAL(onStep()), model, SLOT(step_sim()));
}

void connect_model_menu(QObject *menu, Model *model)
{

}
