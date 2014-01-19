import QtQuick 2.0

Item {
    id: node

   width: 100
   height: 100

   signal position_changed_sig(real X, real Y)

   Rectangle {
       id: rect_node
       anchors.fill: node
       width: parent.width
       height: parent.height
       radius: width*.5
       state: "enabledNode"
       color: "green"
       MouseArea {
           anchors.fill: parent
           onClicked: (rect_node.state == "enabledNode") ? rect_node.state = "disabledNode" : rect_node.state = "enabledNode"
           drag.target: node
           onPositionChanged: {
               if (drag.active === true)
                   node.position_changed_sig(node.x,node.y)
           }
       }

       states: [
           State {
              name: "disabledNode"
              PropertyChanges {
                  target: rect_node
                  color: "red"
              }
          }, //end of State
          State {
              name: "enabledNode"
              PropertyChanges {
                  target: rect_node
                  color: "green"
              }
          }

       ]//end of states
    } //end of rectangle


} //end of item
