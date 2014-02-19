#ifndef MODEL_H
#define MODEL_H

#include "stdafx.h"

class Graph;

class Model : public QQuickItem
{
    Q_OBJECT
public:
    explicit Model(QQuickItem *parent = 0);
    bool change_algorithm(std::string alg);
    int get_algorithm();
    int set_main_panel(QObject *main_panel);
    void set_graph(Graph &g);

private:
    QObject *main_panel;
    Graph *graph;

signals:

public slots:
    void start_sim();
    void pause_sim();
    void resume_sim();
    void step_sim();
    void reset_sim();
};

#endif // MODEL_H
