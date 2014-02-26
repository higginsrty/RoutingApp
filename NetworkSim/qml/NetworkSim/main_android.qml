import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1


ApplicationWindow {
    visible: true
    title: qsTr("Network Simulation App")
    objectName: "root"
    id: root

    signal onStart()
    signal onPause()
    signal onResume()
    signal onReset()
    signal onStep()
    signal showMenu()

    toolBar: BorderImage {
        objectName: "tool_bar"
        border.bottom: 8
        source: "qrc:/images/toolbar"
        width: parent.width
        height: 100

        Rectangle {
            id: backButton
            width: opacity ? parent.height-10 : 0
            anchors.left: parent.left
            //opacity: stackView.depth > 1 ? 1 : 0
            anchors.verticalCenter: parent.verticalCenter
            antialiasing: true
            height: parent.height-5
            y:0
            radius: 2
            color: backmouse.pressed ? "#222" : "transparent"
            Behavior on opacity { NumberAnimation{} }
            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/images/navigation_previous_item"
            }
            MouseArea {
                id: backmouse
                anchors.fill: parent
                anchors.margins: -10
                //onClicked: stackView.pop()
            }
        }

        Text {
            id: text_name
            font.pixelSize: 42
            Behavior on x { NumberAnimation{ easing.type: Easing.OutCubic} }
            x: backButton.x + backButton.width + 20
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
            text: "Network Simulation"
        }

        ToolButton {
            id: menu_action
            anchors.right: parent.right
            height: parent.height - 5
            width: parent.height - 10
            style: ButtonStyle {
                background: Rectangle {
                    id: menu_button
                    color: menu_action.pressed ? "#222" : "transparent"
                    implicitWidth: parent.width
                    implicitHeight: parent.height
                    radius: 2
                }
            }

            onClicked: {
                showMenu()

            }
        }

    }


    Item {
        objectName: "MainPanel"
        id: main_panel
        width: parent.width
        height: parent.height
        // This is where all other items will be added, such as the menu, nodes, links...etc.

    }
}
