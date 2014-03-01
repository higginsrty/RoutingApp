#include "stdafx.h"


Model::Model(QQuickItem *parent) :
    QQuickItem(parent)
{
    is_paused = false;
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
    graph->start_animation();
}

void Model::reset_sim()
{
    if (is_paused) {
        graph->destroy_packets();
        is_paused = false;
    }
    else
    {
        graph->pause_animation();
        graph->destroy_packets();
    }
}

void Model::pause_sim()
{
    /*
     * in the graph, it is tracking where the packets are
     * And this will stop all animation and store how much time is left
     * in each individual animation (its most generally going to be unique to every packet)
     *
     */
    if (is_paused)
        return;
    is_paused = true;
    graph->pause_animation();
}

void Model::resume_sim()
{
    if (is_paused)
    {
        is_paused = false;
        graph->resume_animation();
    }
}

void Model::stop_sim()
{
    graph->stop_send_packets();
}

void Model::create_node()
{
    graph->create_node();
}
