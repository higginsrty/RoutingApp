import QtQuick 2.0

Item {
    id: action_bar
    width: parent.width
    height: parent.height * 0.1
    z: 50

    signal onStart()
    signal onPause()
    signal onResume()
    signal onReset()
    signal onStep()

    Rectangle {
        z:51
        color: "red"
        id: start
        anchors.left: parent.left

        height: parent.height
        width: parent.width/5

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Start"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onStart()
            }
        }
    }

    Rectangle {
        id: resume
        color: "red"
        z:51
        anchors.left: start.right

        height: parent.height
        width: parent.width/5

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Resume"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onResume()
            }
        }
    }

    Rectangle {
        id: pause
        color: "red"
        z:51
        anchors.left: resume.right
        height: parent.height
        width: parent.width/5

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Pause"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onPause()
            }
        }
    }

    Rectangle {
        id: step
        color: "red"
        anchors.left: pause.right
        z:51
        height: parent.height
        width: parent.width/5

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Step"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onStep()
            }
        }
    }

    Rectangle {
        id: reset
        color: "red"
        anchors.right: parent.right
        z:51
        height: parent.height
        width: parent.width/5

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Reset"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onReset()
            }
        }
    }
}
