import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

ApplicationWindow {

    //title of the application
    title: qsTr("Hello World")
    visible: true
    width: 640
    height: 480

    //menu containing two menu items
    MyMenuBar {
    }

    //Content Area
    MyButton {
    }

}
