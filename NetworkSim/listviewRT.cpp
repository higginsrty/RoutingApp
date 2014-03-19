#include "listviewRT.h"

extern GlobalData*iGlobalData;
static const QString KListingQMLPath = ""; //listingpage.qml path
static const QString KListXMLPath = ""; //the XML path

listviewRT::listviewRT(QDeclarativeView *view,QObject *parent) : QObject(parent), main_view(view)
{
    //first parse the XML file & save it's data

    iFilesDirPath.append(KListXMLPath);
    QFile film_xmlfile(iFilesDirPath);
    int ifFileExists = film_xmlfile.exists(iFilesDirPath);
    ilistviewRT_xmlparser_itemsData = new listviewRT_xmlparser_itemsData();
    ilistviewRT_xmlparser_itemsData->ParseScreeningXMLData(iFilesDirPath);
}

//create film listing view

void listviewRT::create_listview()
{
    m_mainComponent = new QDeclarativeComponent(main_view -> engine(),QUrl::fromLocalFile(KListingQMLPath));
    //QDeclarativeItem *mainQML=
    mainQML = qobject_cast<QDeclarativeItem*>(m_mainComponent->create());
    main_view->scene()->addItem(mainQML);

    QDeclarativeContext *context = main_view->engine()->rootContext();
    //expose this class to Routing Table QML, so it can call it's functions from it
    context->setContextProperty("listLoader",this);
    context->setContextProperty("xmldatalistmodel1", idynamiclist_xmlparser_itemsData);

    //expose this list data model, set as model for listview qml
    context->setContextProperty("xmldatalistmodel", QVariant::fromValue(idynamiclist_xmlparser_itemsData->ExtractItems()));

    setNewContextinit(context);
    QObject::connect(mainQML, SIGNAL(loadnewmodel()),this, SLOT(setNewContext(/*context*/)));
    QObject::connect(mainQML, SIGNAL(loadnewmodelprevious()),this, SLOT(setNewContextPrevious()));

    main_view->showFullScreen();

}//end of create_listview()

void listviewRT::setNewContextinit(QDeclarativeContext *acontext)
{
    icontext = acontext;

}//end of set new contextinit
