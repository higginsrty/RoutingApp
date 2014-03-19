#include"stdafx.h"
#include "dynamiclist_xmlparser_itemsdata.h"
#include "dynamicList_common_globaldata.h"

static const QString KDestinationElement = "Destination";
static const QString KWeightElement = "Weight";
static const QString KGatewayElement = "Gateway";

extern GlobalData*iGlobalData;

dynamiclist_xmlparser_itemsData::dynamiclist_xmlparser_itemsData(QObject *parent) : QObject(parent)
{
}

void dynamiclist_xmlparser_itemsData::ParseScreeningsXmlData(const QString& aScreeningFilePath)
{
    QFile* File = new QFile(aScreeningFilePath);
    //can't open. Display Error
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QDomDocument doc("mydocument");
    if(!doc.setContent(file))
    {
        return;
    }

    //get the root element
    iGlobalData->iListDataArray.clear();
    QDomElement docElem = doc.documentElement();

    //check root tag name if it matters??
    QString rootTag = docElem.tagName(); //root

    //get the node's destinations
    QDomNodeList nodeList = docElem.elementsByTagName(KDestinationElement);

    //check each node
    for(int iNodeCount = 0;iNodeCount < nodeList.count(); iNodeCount++)
    {
        dynamiclist_dto_listnodedata*idynamiclist_dto_listnodedata = new dynamiclist_dto_listnodedata();
        //get the current one as QDomElement
        QDomElement e1 = nodeList.at(iNodeCount).toElement();

        //get all data for the element by looping through all child elements
        QDomNode pEntries = e1.firstChild();
        while(!pEntries.isNull()){
            QDomElement perData = pEntries.toElement();
            QString tagNam = perData.tagName();

            if(tagName == KDestinationElement){
                idynamiclist_dto_listnodedata->SetItemDestination(perData.text());
            }else if(tagNam == KWeightElement){
                idynamiclist_dto_listnodedata->SetItemWeight(perData.text());
            }else if(tagNam == KGatewayElement){
                idynamiclist_dto_listnodedata->SetItemGateway(perData.text());
            }
            pEntries = pEntries.nextSibling();
        }//end of while

        iGlobalData->iListDataArray.append(idynamiclist_dto_listnodedata);
        ItemsMasterList.append(idynamiclist_dto_listnodedata);
    }//end of for loop

    file->close();
    if(ItemMasterList.count()%10==0)
        iGlobalData->iResultPageCount = (ItemsMasterList.count()/10);
    else
    {
        iGlobalData->iResultPageCount = (ItemsMasterList.count()/10);
        iGlobalData->iResultPageCount = iGlobalData->iResultPageCount+1;
    }

    QString qStr = QString::number(iGlobalData->iResultPageCount);
    SetiResultPageCount(qStr);
}
//Get first 10 elements from array

QList<QObject*> dynamiclist_xmlparser_itemsData::ExtractItems() //called from listviewRT::createlistview()
{
 QList<QObject*>iTempItemsList;

 for(int ifilmitemcount = iGlobalData->iInitialNumRecords;ifilmitemcount<iGlobalData->iFinalNumRecords;ifilmitemcount++)
 {
     iTempItemsList.append(ItemsMasterList.at(ifilmitemcount));
 }

 QString qStr = QString::number(iGlobalData->upperpagecount);
 SetiResultUpper_Lower(qStr);

 return iTempItemList;

}//end of extract items




