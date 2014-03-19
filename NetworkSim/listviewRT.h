#ifndef LISTVIEWRT_H
#define LISTVIEWRT_H
#include "stdafx.h"
#include <QObject>
#include "listviewRT_xmlparser_itemsdata.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDeclarativeContext>
#include <QDeclarativeItem>

class QDeclarativeView;
class QDeclarativeComponent;
class QDeclarativeContext;
class QDeclarativeItem;

class listviewRT : public QObject
{
    Q_OBJECT

public:
    explicit listviewRT_listviewloader(QDeclarativeView *view,QObject *parent = 0);
    listviewRT_xmlparser_itemsData* ilistviewRT_xmlparser_itemsData;
    void setNewContextinit(QDeclarativeContext*acontext);
    Q_INVOKABLE void filtersearchfilmitems(const QString& afiltersearchitems);

private:
    QDeclarativeView* main_view;
    QDeclarativeComponent *m_mainComponent //not owned
    QGraphicsScene *scene;
    QDeclarativeView *view;
    QDeclarativeContext*icontext:
    QDeclarativeItem* mainQML;
    QString iFilesDirPath;
    QString iScreeningFileDirPath;

public slots:
    void createListview();
    void setNewContext();
    void setNewContextPrevious();
};

#endif // LISTVIEW_H
