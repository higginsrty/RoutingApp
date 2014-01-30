import QtQuick 2.0

ListElement {
    id: flooding_routing_table_element
    property string destination
    property int weight
    property string gateway

    destination: "blank"
    weight: 0
    gateway: "blank"
}
