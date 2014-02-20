#include "stdafx.h"


Model::Model(QQuickItem *parent) :
    QQuickItem(parent)
{

}

int Model::set_main_panel(QObject *main_panel)
{
    if (main_panel == NULL)
        return -1;
    this->main_panel = main_panel;
    return 0;
}

void Model::set_graph(Graph &g)
{

   graph = &g;
}

void Model::start_sim()
{
    /*
     * Core based trees can have multiple sources
     *
     * Multicasting has "groups"
     */
    qDebug()<<"Running...";
    Node *source = graph->get_source();
    qDebug() << "Source Fetched...";
    graph->send_packets(source, NULL);
}

void Model::reset_sim()
{
    qDebug() << "reset";
    graph->destroy_packets();
}

void Model::pause_sim()
{
    //graph->pause();
    /*
     * in the graph, it is tracking where the packets are
     * And this will stop all animation and store how much time is left
     * in each individual animation (its most generally going to be unique to every packet)
     *
     */
    qDebug() << "paused";
}

void Model::resume_sim()
{
    qDebug() << "resuming";
}

void Model::step_sim()
{
    qDebug() << "Step_sim";
}

void Model::create_node()
{
    graph->create_node();
}
