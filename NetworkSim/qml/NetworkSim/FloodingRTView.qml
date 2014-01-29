import QtQuick 2.0

GridView {
    id: frtGridView
    anchors.fill: parent
    //create 4 column grid
    cellWidth: parent.width / 4
    cellHeight: 80
    model: FloodingRTModel {}

    delegate: Column {
        Text { text: eHeader; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e1; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e2; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e3; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e4; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e5; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e6; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e7; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e8; anchors.horizontalCenter: parent.horizontalCenter}
        Text { text: e9; anchors.horizontalCenter: parent.horizontalCenter}
    }//end of Column
}//end of GridView
