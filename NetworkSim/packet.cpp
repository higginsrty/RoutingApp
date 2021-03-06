#include "stdafx.h"


Packet::Packet(QQuickItem *parent) :
    QQuickItem(parent)
{
}

Packet::~Packet()
{
    pac_obj->deleteLater();
    panel = NULL;
    engine = NULL;
    source_node = NULL;
    destination_node = NULL;
    next_hop = NULL;
}

QObject* Packet::get_q_object()
{
    return pac_obj;
}

int Packet::get_flood_flag()
{
    return this->flood_flag;
}

void Packet::set_flood_flag(int flag)
{
    this->flood_flag = flag;
}

PacketType Packet::get_packet_type()
{   //get packet type
    //can be hello packet or acknowledgement packet
    return type;
}

void Packet::set_packet_type(PacketType type)
{   //assigns hello or acknowledgement type to packet
    this->type = type;
    QQuickItem *item = qobject_cast<QQuickItem*>(pac_obj);
    item->setProperty("type", type);
}

std::pair<int,int> location(Node* node){
    std::pair<int,int> loc;
    loc.first = node->get_x();
    loc.second = node->get_y();
    return loc;
}

QString Packet::get_name()
{
    return this->name;
}

void Packet::animate()
{
    QMetaObject::invokeMethod(pac_obj, "animate", Qt::DirectConnection );
}

void Packet::pause()
{
    QMetaObject::invokeMethod(pac_obj, "pause", Qt::DirectConnection );
}

void Packet::resume()
{
    QMetaObject::invokeMethod(pac_obj, "resume", Qt::DirectConnection );
}

void Packet::set_source_node(Node* node)
{   //assign the source node
    source_node = node;
    std::pair<int,int> loc = location(node);
    QQuickItem *item = qobject_cast<QQuickItem*>(pac_obj);
    item->setProperty("x", loc.first+offset);
    item->setProperty("y", loc.second+offset);
    QObject::connect(this->pac_obj, SIGNAL(dest_reached(QString)), this->source_node,SLOT(send_pack(QString)),Qt::UniqueConnection);

}

void Packet::set_destination_node(Node* node)
{  //assign the destination node
    destination_node = node;
    update_dest_pos(node);
    QObject::connect(this->source_node,SIGNAL(sent_pack(Packet*,int)),this->destination_node,SLOT(process_packet(Packet*,int)),Qt::UniqueConnection);
}

double Packet::get_time()
{   //might need adjusted
    return time;
}

void Packet::set_time(double t)
{
    time = t;
    QQuickItem *item = qobject_cast<QQuickItem*>(pac_obj);
    item->setProperty("timer" , t);
}

Node* Packet::get_source_node()
{
    return source_node;
}

void Packet::set_ttl(int ttl){
    this->ttl = ttl;
}

int Packet::get_ttl(){
    return ttl;
}

Node* Packet::get_destination_node()
{
    return destination_node;
}

void Packet::set_name(QString name)
{
    QQuickItem *item = qobject_cast<QQuickItem*>(pac_obj);
    item->setProperty("pack_name", name);
    this->name = name;
}

void Packet::create_packet(QString name, QObject *main_panel, QQmlApplicationEngine *engine) {
    // Load Node QML file
    QQmlComponent component(engine, QUrl("qrc:/qml_files/packet.qml"));
    // Create QObject
    pac_obj = component.create();
    // Cast it as a QQuickItem
    QQuickItem *item = qobject_cast<QQuickItem*>(pac_obj);
    // Set the parent as the main_panel (this changes when added to a link)
    item->setParentItem(qobject_cast<QQuickItem*>(main_panel));
    item->setProperty("pack_name", name);
#ifdef Q_OS_ANDROID
    item->setProperty("packet_size", 50);
    offset = 25;
#else
    item->setProperty("packet_size", 20);
    offset = 13;
#endif
    this->name = name;
}

void Packet::update_dest_pos(Node *node)
{
    std::pair<int,int> dest_loc = location(node);
    QQuickItem *item = qobject_cast<QQuickItem*>(pac_obj);
    item->setProperty("dest_x", dest_loc.first+offset);
    item->setProperty("dest_y", dest_loc.second+offset);
}

/***The following will need to be adjusted after DVR table is created***
 *
void Packet::set_dvr_table(vector<Dv> dv_table)
{
dvr_Table = dv_table;
}

void Packet::add_dvr_entry(Node* destination_node, int cost)
{
dvr_table.push_back(Dv(destination_node,cost));
}

int Packet::get_dvr_table_size()
{
return dvr_table.size();
}

Node* Packet::get_dvr_table_destination(int index)
{
return dvr_table[index].destination_node;
}

int Packet::get_dvr_table_cost(int index)
{
return dvr_table[index].cost;
}
*************************************************************************/

