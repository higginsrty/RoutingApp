import QtQuick 2.0

Item {
    width: parent.width
    height: parent.height

    ListView {
        anchors.fill: parent

        model: MenuListModel {}
        delegate: Text {
            anchors.right: parent.right
            wrapMode: Text.WordWrap
            text: name
        }
    }
}
