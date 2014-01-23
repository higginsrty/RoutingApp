import QtQuick 2.0

//data coloumns for Flooding Routing Table
//populate node names and weights using C??
//used right now for testing purposes

ListModel {

    ListElement {
        e1: " "
        e2: "A"
        e3: "B"
        e4: "C"
        e5: "D"
    }

    ListElement {
        e1: "A"
        e2: "X" //A to A
        e3: "5"
        e4: "2"
        e5: "7"
    }

    ListElement {
        e1: "B"
        e2: "5"
        e3: "X"
        e4: "6"
        e5: "4"
    }

    ListElement {
        e1: "C"
        e2: "2"
        e3: "6"
        e4: "X"
        e5: "3"
    }

    ListElement {
        e1: "D"
        e2: "7"
        e3: "4"
        e4: "3"
        e5: "X"
    }

}//end of ListModel
