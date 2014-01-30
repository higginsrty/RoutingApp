#ifndef NODE_H
#define NODE_H

#include "stdafx.h"

class Link;

class Node : public QQuickItem
{
    Q_OBJECT

public:
    explicit Node(QQuickItem *parent = 0);
    int get_id();
    bool is_source();
    QString get_name();
    void set_source(bool new_source);
    void setup_node(QString name, int x, int y, QObject* main_panel, QQmlEngine* engine);
    //void addLink(QString name, int weight, Node* node2, QObject* main_panel, QQmlEngine* engine);
    QObject* get_q_object();
    void set_id(int id);
private:
    int node_id;
    QString name;
    bool source;
    QObject* node;

signals:

public slots:

};

#endif // NODE_H
