import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3


//import io.qt.trivialocr.tesseractctrl 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 1280
    height: 720
    maximumWidth: 1920
    maximumHeight: 1080
    title: qsTr("TrivialOCR")
    //color: "#44444f"


    menuBar : MenuBar {
        Menu {
            title: "File"
            MenuItem { text: "Open File..."
                    onClicked: fileDialog.open()
            }
            MenuItem { text: "Open Folder..."}
            MenuItem { text: "Select Database"}
        }
    }
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            srcimg.source = fileDialog.fileUrl
            tesseractCtrl.changeImage(fileDialog.fileUrls)
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    RowLayout {
        anchors.fill: parent

        Source{

        }

        Form {

        }
    }



}
