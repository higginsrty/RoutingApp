import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.1

Item {
    id: node

    property string name
    width: 100
    height: 100

    z: 10

    signal position_changed_sig(real X, real Y, string name)
    signal press_and_hold_node(string name)
    signal show_routing_table(string name)

    Rectangle {
        property string name_id: parent.name
        id: rect_node
        anchors.fill: node
        width: parent.width
        height: parent.height
        radius: width*.5
        state: "enabledNode"
        color: "green"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                show_routing_table(parent.name_id)
            }
            drag.target: node
            onPositionChanged: {
                if (drag.active === true)
                    node.position_changed_sig(node.x,node.y, parent.name_id)
            }

            onPressAndHold: {
                press_and_hold_node(parent.name_id)
            }
        }
        states: [
            State {
                name: "disabledNode"
                PropertyChanges {
                    target: rect_node
                    color: "red"
                }
            }, //end of State
            State {
                name: "enabledNode"
                PropertyChanges {
                    target: rect_node
                    color: "green"
                }
            }

        ]//end of states
    } //end of rectangle


} //end of item
