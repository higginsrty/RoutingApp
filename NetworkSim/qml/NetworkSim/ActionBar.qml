import QtQuick 2.0

Item {
    id: action_bar
    width: parent.width
    height: 100
    z: 50

    signal onStart()
    signal onPause()
    signal onResume()
    signal onReset()
    signal onStep()

    PropertyAnimation {
        id: start_anim_cover_in
        target: start_cover
        property: "opacity"
        duration: 150
        from: 0
        to: 0.6
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: start_anim_cover_out
        target: start_cover
        property: "opacity"
        duration: 150
        from: 0.6
        to: 0
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: step_anim_cover_in
        target: step_cover
        property: "opacity"
        duration: 150
        from: 0
        to: 0.6
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: step_anim_cover_out
        target: step_cover
        property: "opacity"
        duration: 150
        from: 0.6
        to: 0
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: pause_anim_cover_in
        target: pause_cover
        property: "opacity"
        duration: 150
        from: 0
        to: 0.6
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: pause_anim_cover_out
        target: pause_cover
        property: "opacity"
        duration: 150
        from: 0.6
        to: 0
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: resume_anim_cover_in
        target: resume_cover
        property: "opacity"
        duration: 150
        from: 0
        to: 0.6
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: resume_anim_cover_out
        target: resume_cover
        property: "opacity"
        duration: 150
        from: 0.6
        to: 0
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: reset_anim_cover_in
        target: reset_cover
        property: "opacity"
        duration: 150
        from: 0
        to: 0.6
        easing.type: Easing.InOutQuad
    }

    PropertyAnimation {
        id: reset_anim_cover_out
        target: reset_cover
        property: "opacity"
        duration: 150
        from: 0.6
        to: 0
        easing.type: Easing.InOutQuad
    }

    //Start Button
    Rectangle {
        z:51
        id: start
        anchors.left: parent.left

        height: parent.height
        width: parent.width/5

        Image{
             anchors.horizontalCenter: parent.horizontalCenter
             source: "qrc:/images/start"
             height: parent.height
             width: parent.width

        }
        Rectangle {
            id: start_cover
            color: "grey"
            anchors.fill: parent
            opacity: 0
        }

        MouseArea {
            anchors.fill: parent
            onPressed: {
                start_anim_cover_in.start()
            }
            onReleased: {
                start_anim_cover_out.start()
            }

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

        Rectangle {
            id: resume_cover
            color: "grey"
            anchors.fill: parent
            opacity: 0
        }

        MouseArea {
            anchors.fill: parent
            onPressed: {
                resume_anim_cover_in.start()
            }

            onReleased: {
                resume_anim_cover_out.start()
            }

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

        Rectangle {
            id: pause_cover
            color: "grey"
            anchors.fill: parent
            opacity: 0
        }


        MouseArea {
            anchors.fill: parent

            onPressed: {
                pause_anim_cover_in.start()
            }
            onReleased: {
                pause_anim_cover_out.start()
            }

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
            anchors.centerIn: parent
            source: "qrc:/images/step"
            width: parent.width
            height: parent.height
            scale: parent.scale
        }

        Rectangle {
            id: step_cover
            color: "grey"
            anchors.fill: parent
            opacity: 0
        }

        MouseArea {
            anchors.fill: parent

            onPressed: {
                step_anim_cover_in.start()
            }
            onReleased: {
                step_anim_cover_out.start()
            }
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

        Rectangle {
            id: reset_cover
            color: "grey"
            anchors.fill: parent
            opacity: 0
        }

        MouseArea {
            anchors.fill: parent

            onPressed: {
                reset_anim_cover_in.start()
            }
            onReleased: {
                reset_anim_cover_out.start()
            }
            onClicked: {
                action_bar.onReset()
            }
        }
    }
}
