import QtQuick 2.0

Item{

    id: link
    property real x1: parent.x1
    property real y1: parent.y1

    property real x2: parent.x2
    property real y2: parent.y2

    width: parent.width;
    height: parent.height

    Rectangle{

        id:area
        x: link.x1
        y: link.y1
        property alias x1: link.x1
        property alias y1: link.y1

        property real x2: link.x2
        property real y2: link.y2

        color: "blue"
        opacity: 1
        height: 20
        smooth: true
        antialiasing: true

        transformOrigin: Item.TopLeft;

        width: getWidth(x1,y1,x2,y2);
        rotation: getSlope(x1,y1,x2,y2);

        function getWidth(sx1,sy1,sx2,sy2)
        {
            var w=Math.sqrt(Math.pow((sx2-sx1),2)+Math.pow((sy2-sy1),2));
            console.debug("W: "+w);
            return w;
        }

        function getSlope(sx1,sy1,sx2,sy2)
        {
            var a,m,d;
            var b=sx2-sx1;
            if (b===0)
                return 0;
            a=sy2-sy1;
            m=a/b;
            d=Math.atan(m)*180/Math.PI;

            if (a<0 && b<0)
                return d+180;
            else if (a>=0 && b>=0)
                return d;
            else if (a<0 && b>=0)
                return d;
            else if (a>=0 && b<0)
                return d+180;
            else
                return 0;
        }

        MouseArea{

            anchors.fill: area

            onClicked: {
                //(weight_menu.visible == true) ? weight_menu.visible = false : weight_menu.visible = true
                console.log("Clicked")
            }

        }

    }

    Canvas{
        id: canvas
        width: parent.width
        height: parent.height
        anchors.centerIn: parent

        onPaint: {
            var ctx = canvas.getContext('2d')

            ctx.beginPath()


            ctx.moveTo(x1,y1)
            ctx.lineTo(x2,y2)

            ctx.lineWidth = 20
            ctx.stroke()

        }



    }

}


