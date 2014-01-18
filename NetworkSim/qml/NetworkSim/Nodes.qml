import QtQuick 2.0

Item {

   width: 100
   height: 100

   Rectangle {
       id: myNode
       width: parent.width
       height: parent.height
       radius: width*.5
       state: "enabledNode"
       color: "green"
       MouseArea {
           anchors.fill: parent
           onClicked: (myNode.state == "enabledNode") ? myNode.state = "disabledNode" : myNode.state = "enabledNode"
           drag.target: parent
       }

       states: [
           State {
              name: "disabledNode"
              PropertyChanges {
                  target: myNode
                  color: "red"
              }
          }, //end of State
          State {
              name: "enabledNode"
              PropertyChanges {
                  target: myNode
                  color: "green"
              }
          }

       ]//end of states
    } //end of rectangle


} //end of item
