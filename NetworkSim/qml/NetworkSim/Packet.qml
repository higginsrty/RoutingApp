import QtQuick 2.0

Item {
    width: 50
    height: 50
    property int dest_x
    property int dest_y
    z: 20
    property int timer
    timer: 500
    Rectangle {
        id: packet
        state: "Hello"
        width: parent.width
        height: parent.height
        radius: width*.5
        MouseArea{
            anchors.fill: parent
            onClicked:{
                console.log("clicked")
                animation.running = true
            }
        }
        ParallelAnimation{
            id:animation

            PropertyAnimation {
                target: packet
                property: "x"
                to: dest_x-x
                duration: timer

            }

            PropertyAnimation{
                target: packet
                property: "y"
                to: dest_y-y
                duration: timer
            }
        }
        states: [
            State {
                name: "Acknowldgement"
                PropertyChanges {
                    target: packet
                    color: "blue"
                }
            },
            State {
                name: "Hello"
                PropertyChanges {
                    target: packet
                    color: "yellow"
                }
            },
            State {
                name: "Data"
                PropertyChanges {
                    target: packet
                    color: "red"
                }

            }
        ]


    }
}

