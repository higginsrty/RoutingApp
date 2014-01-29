#ifndef FLOODINGRT_H
#define FLOODINGRT_H

#include "stdafx.h"

class Packet;

class FloodingRT : public QQuickItem
{
    Q_OBJECT

public:
    explicit FloodingRT(QQuickItem *parent = 0);
    void floodNetwork(Node* node, Packet *packet);

private:
    QString address;
    std::vector<QString> destination;
    std::vector<QString> gateway;
    std::vector<qreal> weight;



};
#endif // FLOODINGRT_H
