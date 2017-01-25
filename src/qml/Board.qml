import QtQuick 2.0

Rectangle {
  id: mainRectangle
  property alias gameName: gameText.text
  width: 600
  height: 400
  color: "#246612"

  Text {
    id: gameText
    color: "#f3eaea"
    font.pointSize: 50
    opacity: 0.3
    anchors.bottom: mainRectangle.bottom
    anchors.bottomMargin: 10
    anchors.horizontalCenter: mainRectangle.horizontalCenter
    font.family: "Verdana"
  }
}
