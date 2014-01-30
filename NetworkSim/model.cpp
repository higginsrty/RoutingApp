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

    qDebug() << "start";
}

void Model::reset_sim()
{
    qDebug() << "reset";
}

void Model::pause_sim()
{
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
