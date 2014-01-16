import QtQuick 2.0

Item {
    width: 100
    height: 100
    Rectangle {
        anchors.fill: parent
        ListModel {
            id: node_list
            ListElement {
                name: "Add Link"
                MouseArea {
                    anchors.fill: parent
                }
            }

            ListElement {
                name: "Delete Link"
                MouseArea {

                }
            }

            ListElement {
                name: "Set As Source"
                MouseArea {
                    anchors.fill: parent
                }
            }

            ListElement {
                name: "Delete Node"
                MouseArea {
                    anchors.fill: parent
                }
            }

            ListElement {
                name: "Change Name/ID"
                MouseArea {
                    anchors.fill: parent
                }
            }
        }

        ListView {
            width: parent.width
            height: parent.height

            model: node_list
            delegate: Text {
                text: name
            }
        }
    }
}
