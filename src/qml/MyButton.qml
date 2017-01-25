import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

//a button in the middle of the content area
Button {
    text: qsTr("Hello World")
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
}
