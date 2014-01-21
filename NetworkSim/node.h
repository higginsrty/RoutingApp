#ifndef NODE_H
#define NODE_H

#include "stdafx.h"

class Link;

class Node : public QQuickItem
{
    Q_OBJECT

public:
    explicit Node(QQuickItem *parent = 0);
    bool is_source();
    void set_source(bool new_source);
    void setup_node(QString name, int x, int y, QObject* main_panel, QQmlEngine* engine);
    void addLink(QString name, Node* node2, QObject* main_panel, QQmlEngine* engine);
    QObject* get_q_object();
private:
    std::vector<Link*> links;
    bool source;
    QObject* node;

signals:

public slots:
    void position_changed(qreal x, qreal y);
};

#endif // NODE_H
