import QtQuick 2.0

Item {

    signal dest_reached(string name)

    width: 50
    height: 50
    z: 20

    property int dest_x
    property int dest_y
    property int type
    property string state
    property int timer
    property string pack_name

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
                animation.start()

            }
        }

        ParallelAnimation{
            id:animation

            PropertyAnimation {
                id: x_anim
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
            onStopped: dest_reached(pack_name)

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

