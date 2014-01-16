import QtQuick 2.0

Item {
    width: parent.width
    height: parent.height

    ListView {
        width: parent.width
        height: parent.height

        model: MenuListModel {}
        delegate: Text {
            text: name
        }
    }
}
