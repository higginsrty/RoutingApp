#ifndef LINK_H
#define LINK_H

#include "stdafx.h"

class Node;

class Link : public QQuickItem
{
    Q_OBJECT
public:
    explicit Link(QQuickItem *parent = 0);
    void addLink(QString name, int weight, Node *node1, Node *node2, QObject *panel, QQmlApplicationEngine *engine);
    QObject* get_q_object();
    Node* get_source();
    Node* get_node2();
    double get_weight();
    void update_weight(int w);

private:
    Node *node1;
    Node *node2;
    int weight;
    QObject* link;

signals:

public slots:

};

#endif // LINK_H
