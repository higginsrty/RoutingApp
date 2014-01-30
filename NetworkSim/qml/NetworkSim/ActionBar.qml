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
    //Start Button
    Rectangle {
        z:51
        id: start
        anchors.left: parent.left

        height: parent.height
        width: parent.width/5

        Image{
             anchors.centerIn: parent.horizontalCenter
             source: "qrc:/images/start"
             height: parent.height
             width: parent.width

        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onStart()
            }
        }
    }
    //Resume Button
    Rectangle {
        id: resume
        z:51
        anchors.left: start.right

        height: parent.height
        width: parent.width/5

        Image {
            anchors.horizontalCenter: parent.horizontalCenter

            source: "qrc:/images/resume"
            width: parent.width
            height: parent.height
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onResume()
            }
        }
    }
    //Pause Button
    Rectangle {
        id: pause
        z:51
        anchors.left: resume.right
        height: parent.height
        width: parent.width/5

        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/images/pause"
            height: parent.height
            width: parent.width
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onPause()
            }
        }
    }
    //Step Button
    Rectangle {
        id: step
        anchors.left: pause.right
        z:51
        height: parent.height
        width: parent.width/5

        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/images/pause"
            width: parent.width
            height: parent.height
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onStep()
            }
        }
    }
    //Reset Button
    Rectangle {
        id: reset
        anchors.right: parent.right
        z:51
        height: parent.height
        width: parent.width/5

        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/images/reset"
            height: parent.height
            width: parent.width
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                action_bar.onReset()
            }
        }
    }
}
