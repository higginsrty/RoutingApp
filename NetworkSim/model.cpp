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

int Model::set_graph(Graph *g)
{
   if (g == NULL)
       return -1;
   graph = g;
   return 0;
}

void Model::start_sim()
{
    /*
     * Core based trees can have multiple sources
     *
     * Multicasting has "groups"
     */
    Node *source = graph->get_source();
    source->send_packets(/*Packet or null for source*/);
}

void Model::reset_sim()
{
    qDebug() << "reset";
}

void Model::pause_sim()
{
    //graph->pause();
    /*
     * in the graph, it is tracking where the packets are
     * And this will stop all animation and store how much time is left
     * in each individual animation (its most generally going to be unique to every packet)
     */
    qDebug() << "paused";
}

void Model::resume_sim()
{
    /*
     * Gets the position for the packet,
     * tells the packet to move to the destination from its current position
     * uses the stored time left to tell how long to reach the destination
     */
    qDebug() << "resuming";
}

void Model::step_sim()
{
    qDebug() << "Step_sim";
}
