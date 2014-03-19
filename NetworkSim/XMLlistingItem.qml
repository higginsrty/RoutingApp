import QtQuick 2.0
import Qt 4.7
import com.nokia.meego 2.0

Item {

    id: listitems
    signal loadnewmodel
    property string samplename: "node1"
    property string fontName: "Helvetica"
    property int titleFontSize: 17
    property int fontSize: 14
    property color fontColorTitle: "black"
    property color fontColor: "black"
    property int margins: 8
    property real detailsOpacity : 0

    width: xmldatalistingview.width
    height: 85


    // Lay out the page: picture, title and ingredients at the top, and method at the
    // bottom.  Note that elements that should not be visible in the list
    // mode have their opacity set to recipe.detailsOpacity.
    Row {
        id: topLayout
        x: 10; y: 18; height: 100; width: parent.width
        spacing: 16


        Column {
            // Leave some room on top.
            y: 2
            x: 13

            Text {
                id: listitemnum

                anchors {
                    leftMargin: listitems.margins
                    rightMargin: listitems.margins
                }

                text: model.modelData.getItemNumber //get item number
                wrapMode: Text.WordWrap
                font {
                    family: listitems.fontName
                    pointSize: listitems.titleFontSize

                }
                font.bold: true;
                color: fontColorTitle

            }
            Text {
                id: listitemid
                y: 4

                anchors {
                    left: parent.left
                    rightMargin: listitems.margins*3
                }

                text: model.modelData.getItemId // get item id
                font {
                    family: listitems.fontName
                    pointSize: listitems.fontSize
                }
                color: fontColor
            }


            Text {
                id: listitemname
                y: 6
                width: parent.width
                anchors {
                    leftMargin: listitems.margins
                    rightMargin: listitems.margins
                }
                text: model.modelData.getItemName // get item name
                wrapMode: Text.WordWrap
                font {
                    family: listitems.fontName
                    pointSize: listitems.fontSize
                }
                color: listitems.fontColor
            }


        }



    }

}
