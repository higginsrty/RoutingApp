#include "stdafx.h"

Graph::Graph(QObject *panel, QQmlApplicationEngine *engine)
{
    this->panel = panel;
    this->engine = engine;
}

Node* Graph::add_node(QString name, int x, int y, int id, Packet *p1)
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
    node->p1 = p1;
    p1->set_source_node(node);
    p1->set_destination_node(get_node_by_id(23));
    return node;
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
        if (temp->get_source() == node) {
            tmp->setProperty("x1", x + x_off/2);
            tmp->setProperty("y1", y + y_off/2);
        } else {
            tmp->setProperty("x2", x + x_off/2);
            tmp->setProperty("y2", y + y_off/2);
        }
    }
    node->set_x(x);
    node->set_y(y);
    update_dests(node);
}

void Graph::update_dests(Node *node)
{
    std::vector<Node*>::iterator iter;
    for (iter=node_pool.begin(); iter != node_pool.end(); iter++)
    {
        Node *n1 = *iter;
        Node *temp_dest = n1->p1->get_destination_node();
        if (temp_dest->get_id() == node->get_id())
            n1->p1->update_dest_pos(node);
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
