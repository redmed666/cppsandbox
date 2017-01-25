import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

MenuBar {
    Menu {
        title: "File"
        MenuItem { text: "Open..." }
        MenuItem { text: "Close" }
    }

    Menu {
        title: "Edit"
        MenuItem { text: "Cut" }
        MenuItem { text: "Copy" }
        MenuItem { text: "Paste" }
    }
}
