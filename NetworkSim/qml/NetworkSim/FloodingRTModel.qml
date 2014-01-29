import QtQuick 2.0

//data coloumns for Flooding Routing Table
//populate node names and weights using C++??
//used right now for testing purposes

ListModel {

    ListElement {
        //Source Node
        //Doesn't Change
        eHeader: "Source"
        e1: "A"
        e2: "A"
        e3: "A"
    }

    ListElement {
        //Destination Nodes
        eHeader: "Destination"
        e1: "B"
        e2: "C"
        e3: "D"
    }

    ListElement {
        //Weight
        eHeader: "Weight"
        e1: "4"
        e2: "3"
        e3: "8"
    }

    ListElement {
        //Gateway
        eHeader: "Gateway"
        e1: " "
        e2: " "
        e3: "C"
    }

}//end of ListModel
