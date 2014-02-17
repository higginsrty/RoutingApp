import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1

ApplicationWindow {
    visible: true
    title: qsTr("Network Simulation")
    objectName: "root"
    width: 800
    height: 600
    id: root

    signal onStart()
    signal onPause()
    signal onResume()
    signal onReset()
    signal onStep()


    menuBar: MenuBar {
        id: menu_bar
        objectName: "tool_bar"

        Menu {
            title: qsTr("Simulation")
            MenuItem {
                text: qsTr("Quit")
                onTriggered: Qt.quit();
            }

            MenuItem {
                text: qsTr("Start")
                onTriggered: onStart();
            }
            MenuItem {
                text: qsTr("Step")
                onTriggered: onStep();
            }
            MenuItem {
                text: qsTr("Pause")
                onTriggered: onPause();
            }
            MenuItem {
                text: qsTr("Reset")
                onTriggered: onReset();
            }
            MenuItem {
                text: qsTr("Resume")
                onTriggered: onResume();
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
