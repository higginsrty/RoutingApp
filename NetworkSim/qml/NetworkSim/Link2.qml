import QtQuick 2.0

Item{
    id: link
    property real x1: x1
    property real y1: y1

    property real x2: x2
    property real y2: y2

    z:-1

    Rectangle{

        id:area
        property alias x1: link.x1
        property alias y1: link.y1

        property real x2: link.x2
        property real y2: link.y2

        color: "black"
        height: 25
        smooth: true
        antialiasing: true

        x: parent.x1
        y: parent.y1 - height/2

        transformOrigin: Item.Left

        width: getWidth(x1,y1,x2,y2)
        rotation: getSlope(x1,y1,x2,y2)

        function getWidth(sx1,sy1,sx2,sy2)
        {
            var w=Math.sqrt(Math.pow((sx2-sx1),2)+Math.pow((sy2-sy1),2));
            return w;
        }

        function getSlope(sx1,sy1,sx2,sy2)
        {
            var a,m,d;
            var b=sx2-sx1;
            a=sy2-sy1;
            if (b===0) {
                if (a < 0)
                    return -90;
                if (a === 0)
                    return 0;
                if (a > 0)
                    return 90;
            }
            m=a/b;
            d=Math.atan(m)*180/Math.PI;
            if (a<0 && b<0)
                return d + 180;
            else if (a>=0 && b>=0)
                return d;
            else if (a<0 && b>=0)
                return d;
            else if (a>=0 && b<0)
                return d + 180;
            else
                return 0;
        }

        MouseArea{

            anchors.fill: area

            onClicked: {
                console.log("x1: " + x1)
                console.log("y1: " + y1)
                console.log("x2: " + x2)
                console.log("y2: " + y2)
            }

        }

    }

}


