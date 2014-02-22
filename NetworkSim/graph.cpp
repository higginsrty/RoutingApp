#include "stdafx.h"

Graph::Graph(QObject *panel, QQmlApplicationEngine *engine)
{
    this->panel = panel;
    this->engine = engine;
}

Node* Graph::add_node(QString name, int x, int y, int id)
{
    Node *node = get_node_by_name(name);
    if (node != NULL)
        return NULL;
    node = get_node_by_id(id);
    if (node != NULL)
        return NULL;
    node = new Node();
    node->setup_node(name, x, y, panel, engine);
    node->set_id(id);
    QObject::connect(node->get_q_object(),SIGNAL(position_changed_sig(qreal,qreal,QString)),this,SLOT(update_node_position(qreal,qreal,QString)));
    QObject::connect(node->get_q_object(), SIGNAL(press_and_hold_node(QString)), this, SLOT(press_and_hold_node(QString)));
    QObject::connect(node->get_q_object(), SIGNAL(show_routing_table(QString)), this, SLOT(show_routing_table(QString)));
    node_pool.push_back(node);
    update_algorithm(0);
    return node;
}

void Graph::update_algorithm(int alg_id)
{
    std::vector<Node*>::iterator iter;
    for (iter = node_pool.begin(); iter != node_pool.end(); iter++)
    {
        Node *tmp = *iter;
        tmp->set_alg(alg_id);
    }
}


/*
 * Starts with the source node and a NULL previous node(from the model start)
 * and then once the signal slot communication works we can have the signal
 * that the packet was recieved at its destination (node n) and then
 * pass node n to this function and prev = the source of said packet
 * ----------------------------------------------------------
 * SOMETIMES IT BUGS AND SPAWNS THE PACKETS WRONG OR CRASHES
 * ----------------------------------------------------------
 * I have't figured out why it does this yet but simply rerunning fixes it
 */
void Graph::send_packets(Node* node, Node* prev)
{
    /*The next two lines are for testing node 2's ability to create packets
    *remove the comments to force the method to use node2 as the origin and
    * and node1 as the prev node
    */
    //node = get_node_by_name("node2");
    //prev = get_node_by_name("node1");
    //If the passed node is the source it creates a packet for every link the node has
    if(node->is_source()==true){
        //Get All links lined to this node
        std::vector<Link*> links= get_link_from_node(node);
        qDebug() << "Links fetched...";
        //Iterate through all the links and make a packet for each one
        for (int i=0; i<links.size();i++)
        {
            Node* src = links[i]->get_source();
            Node* dest = links[i]->get_node2();
            Packet *p = new Packet();
            p->create_packet("packet" + QString::number(i+1),panel,engine);
            if(src->get_id() == node->get_id())
            {
                p->set_source_node(src);
                p->set_destination_node(dest);
            }
            else{
                p->set_source_node(dest);
                p->set_destination_node(src);
            }
            node->packets.push_back(p);
            p->set_time(links[i]->get_weight());
            p->set_packet_type(ACK);
            p->set_ttl(node_pool.size());
            packet_pool.push_back(p);
            qDebug()<< "Packet" << i+1 << "Created...";


            p->animate();
        }

    }
    /*If the node is not the source send a packet to every node
    *expect the node it recieved the packet from
    *(Question) Would it be just the node it recieved the packet from
    *or any node that it has ever received a packet from?
    *
    * (ANSWER)
    * Just the node it received the packet from, that is why flooding algorithms are so bad
    */
    else {
        std::vector<Link*> links= get_link_from_node(node);
        for (int i=0; i<links.size();i++){
            Node* src = links[i]->get_source();
            Node* dest = links[i]->get_node2();
            if((src->get_id() != prev->get_id()) && (dest->get_id() != prev->get_id()))
            {
                Packet *p = new Packet();
                p->create_packet("packet",panel,engine);
                src->packets.push_back(p);
                /*Flips the "source" of the packets to make sure it starts
                 * on the current node because it could spawn
                 * on the other node of the link due to the order in which
                 * the nodes were passed to the create link method
                 */
                if(src->get_id() == node->get_id())
                {
                    p->set_source_node(src);
                    p->set_destination_node(dest);
                }
                else{
                    p->set_source_node(dest);
                    p->set_destination_node(src);
                }
                p->set_time(links[i]->get_weight());
                p->set_packet_type(ACK);
                packet_pool.push_back(p);
            }


        }
    }

}

void Graph::destroy_packets(){
    packet_pool.clear();
}


Node* Graph::get_source()
{
    std::vector<Node*>::iterator iter;
    for (iter = node_pool.begin(); iter!=node_pool.end(); iter++)
    {
        Node *n1 = *iter;
        if (n1->is_source())
            return n1;
    }
    return NULL;
}

std::vector<Link*> Graph::get_link_from_node_id(int nodeID)
{
    std::vector<Link*> links;
    for (std::vector<Link*>::iterator iter = link_pool.begin(); iter !=link_pool.end(); iter++)
    {
        Link *temp = *iter;
        int temp_id = -1;
        temp_id = temp->get_source()->get_id();
        if (temp_id == nodeID)
        {
            links.push_back(temp);
            continue;
        }
        temp_id = temp->get_node2()->get_id();
        if (temp_id == nodeID)
        {
            links.push_back(temp);
            continue;
        }
    }
    return links;
}

std::vector<Link*> Graph::get_link_from_node(Node *node)
{
    return get_link_from_node_id(node->get_id());
}

int Graph::add_link(Node *node1, Node *node2, int weight)
{
    for (std::vector<Link*>::iterator iter = link_pool.begin(); iter != link_pool.end(); iter++)
    {
        // Check to see if a link already exists
        Link *temp = *iter;
        int t1 = temp->get_source()->get_id();
        int t2 = temp->get_node2()->get_id();
        int n1_id = node1->get_id();
        int n2_id = node2->get_id();
        // Return an error of -1 if a link exists
        if ((t1 == n1_id || t2 == n1_id) && (t1 == n2_id || t2 == n2_id))
            return -1;
    }
    // Create the link
    Link *lnk = new Link();
    lnk->addLink("link",weight,node1,node2,panel,engine);
    lnk->update_weight(weight);
    // weight is in milliseconds
    // this refers to the current node
    // n is a child node
    // Add children and weight to the link
    //lnk->addChildren(node1,node2,weight);
    node1->add_link(lnk);
    node2->add_link(lnk);
    link_pool.push_back(lnk);
    // Return 0 for a normal return
    return 0;
}

bool Graph::update_link_weight(Link *lkn, int weight)
{
    int node1_id = lkn->get_source()->get_id();
    int node2_id = lkn->get_node2()->get_id();

    for (std::vector<Link*>::iterator iter = link_pool.begin(); iter != link_pool.end(); iter++)
    {
        Link *temp = *iter;
        if (temp->get_source()->get_id() != node1_id)
            continue;
        if (temp->get_node2()->get_id() != node2_id)
            continue;
        temp->update_weight(weight);
        delete temp;
        free(*iter);
        return true;
    }
    return false;
}

bool Graph::update_link_weight(Node *node1, Node *node2, int weight)
{
    std::vector<Link*> lnks = get_link_from_node_id(node1->get_id());
    std::vector<Link*>::iterator iter;
    int node2_id = node2->get_id();
    for (iter = lnks.begin(); iter != lnks.end(); iter++)
    {
        Link *temp = *iter;
        int n1_id = temp->get_source()->get_id();
        int n2_id = temp->get_node2()->get_id();
        if (node2_id == n1_id || node2_id == n2_id)
        {
            temp->update_weight(weight);
            return true;
        }

    }
    return false;
}

Node* Graph::get_node_by_name(QString string)
{
    std::vector<Node*>::iterator iter;
    for (iter = node_pool.begin(); iter != node_pool.end(); iter++) {
        Node *n1 = *iter;
        if (n1->get_name().compare(string) == 0)
            return n1;
    }
    return NULL;
}

Node* Graph::get_node_by_id(int id)
{
    std::vector<Node*>::iterator iter;
    for (iter = node_pool.begin(); iter != node_pool.end(); iter++)
    {
        Node *n1 = *iter;
        if (n1->get_id() == id)
            return n1;
    }

    return NULL;
}

void Graph::update_node_position(qreal x, qreal y, QString string)
{
    Node *node = get_node_by_name(string);
    QObject *obj = node->get_q_object();
    std::vector<Link*> lnks = get_link_from_node(node);
    for (std::vector<Link*>::iterator iter = lnks.begin(); iter != lnks.end(); iter++)
    {
        Link *temp = *iter;
        QQuickItem *tmp = qobject_cast<QQuickItem*>(temp->get_q_object());
        QQuickItem *node1 = qobject_cast<QQuickItem*>(obj);
        int y_off = node1->height();
        int x_off = node1->width();
        if (temp->get_source()->get_id() == node->get_id()) {
            tmp->setProperty("x1", x + x_off/2);
            tmp->setProperty("y1", y + y_off/2);
        } else {
            tmp->setProperty("x2", x + x_off/2);
            tmp->setProperty("y2", y + y_off/2);
        }
    }
    node->set_x(x);
    node->set_y(y);
    update_source_packet_pos(node);
    update_dests(node);
}

void Graph::update_source_packet_pos(Node *node)
{
    if (packet_pool.size() == 0)
        return;
    std::vector<Packet*>::iterator iter;
    for (iter = packet_pool.begin(); iter != packet_pool.end(); iter++)
    {
        Packet *p1 = *iter;
        if (p1->get_source_node()->get_id() == node->get_id())
        {
            QObject *obj = p1->get_q_object();
            QQuickItem *item = qobject_cast<QQuickItem*>(obj);
            item->setProperty("x",node->get_x()+25);
            item->setProperty("y",node->get_y()+25);
        }
    }
}

void Graph::update_dests(Node *node)
{
    std::vector<Node*>::iterator iter;
    for (iter=node_pool.begin(); iter != node_pool.end(); iter++)
    {
        Node *n1 = *iter;
        std::vector<Packet*>::iterator iter1;
        for (iter1=packet_pool.begin(); iter1 != packet_pool.end(); iter1++)
        {
            Packet *p1 = *iter1;
            Node *temp_dest = p1->get_destination_node();
            if (temp_dest->get_id() == node->get_id())
                p1->update_dest_pos(node);
        }
    }
}

void Graph::press_and_hold_node(QString node_name)
{
    QQmlComponent component(engine, QUrl("qrc:/qml_files/node_dialog.qml"));
    QObject *object = component.create();
    object->setParent(panel);
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    item->setParentItem(qobject_cast<QQuickItem*>(panel));
    QObject::connect(object,SIGNAL(destroy_dialog(void)),this,SLOT(destroy_dialog(void)));
    Node* node = get_node_by_name(node_name);
}

void Graph::destroy_dialog()
{
    QObject *dialog = panel->findChild<QObject*>("nodeDialog");
    //QQuickItem *dialog_item = qobject_cast<QQuickItem*>(dialog);
    dialog->deleteLater();
}

void Graph::show_routing_table(QString node_name)
{
    Node *node = get_node_by_name(node_name);
    node->show_routing_table(engine, qobject_cast<QQuickItem*>(panel));

}

void Graph::create_node()
{
    qDebug() << "Created Node";
    add_node("default",350,200,++node_id);
}

