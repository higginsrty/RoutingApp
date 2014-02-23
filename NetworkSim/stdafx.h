#ifndef STDAFX_H
#define STDAFX_H

#include <QtGlobal>
#include <QtGui/QGuiApplication>
#include "qtquick2controlsapplicationviewer.h"
#include <QQmlEngine>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>

enum PacketType {HELLO, ACK, DATA};

#include <vector>
#include <routingtable.h>
#include <graph.h>
#include <link.h>
#include <stdlib.h>
#include <node.h>
#include <packet.h>
#include <model.h>
#include <floodingRT.h>

#endif // STDAFX_H
