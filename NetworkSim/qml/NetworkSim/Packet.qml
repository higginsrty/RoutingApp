import QtQuick 2.0

Item {

    width: 50
    height: 50
    z: 20

    property int dest_x
    property int dest_y
    property int type
    property string state
    property int timer

    signal reached_dest(bool bool)

    Rectangle {
        id: packet
        state: "ACK"

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
                name: "ACK"
                PropertyChanges {
                    target: packet
                    color: "blue"
                }
            },
            State {
                name: "HELLO"
                PropertyChanges {
                    target: packet
                    color: "yellow"
                }
            },
            State {
                name: "DATA"
                PropertyChanges {
                    target: packet
                    color: "red"
                }

            }
        ]


    }
}

