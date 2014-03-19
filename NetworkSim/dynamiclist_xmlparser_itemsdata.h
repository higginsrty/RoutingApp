#ifndef DYNAMICLIST_XMLPARSER_ITEMSDATA_H
#define DYNAMICLIST_XMLPARSER_ITEMSDATA_H
#include "stdafx.h"

class dynamiclist_xmlparser_itemsData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString getiResultPageCount READ getiResultPageCount WRITE SetiResultPageCount NOTIFY ResultPageCountChanged)
    Q_PROPERTY(QString getiResultPageCountUpper_Lower READ getiResultPageCountUpper_Lower WRITE SetiResultUpper_Lower NOTIFY ResultPageCount_upperChanged)

public:
    explicit dynamiclist_xmlparser_itemsData(QObject *parent = 0);
    QList<QObject*>ExtractItems();
    QList<QObject*>ExtractItemsNext();
    QList<QObject*>ExtractItemsPrevious();
    QList<QObject*>ExtractItemsFromSearch(const QString& section);

    QList<QObject*> ItemsMasterList;
    QString iResultPageCountStr;
    QString iResultPageCountUpper_LowerStr;
    int iRemainingItemCount;

signals:
    void ResultPageCountChanged();
    void ResultPageCount_upperChanged();
    void uppercountchanged();
    void lowercountchanged();

public slots:
    void ParseScreeningXmlData(const QString& aScreeningFilePath);

    void SetiResultPageCount(const QString& iResultPage);
    QString getiResultPageCount();

    void SetiResultUpper_Lower(const QString& iResultPageCount );
    QString getiResultPageCountUpper_Lower();

};

#endif // DYNAMICLIST_XMLPARSER_ITEMSDATA_H
