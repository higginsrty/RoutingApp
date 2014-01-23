import QtQuick 2.0

GridView {
    id: frtGridView
    anchors.fill: parent
    cellWidth: 80
    cellHeight: 80
    model: FloodingRTModel {}

    delegate: Column {
        Text { text: e1; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e2; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e3; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e4; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e5; anchors.horizontalCenter: parent.horizontalCenter}
    }//end of Column
}//end of GridView
