import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

ColumnLayout {
    Layout.leftMargin: 100
    Rectangle {
        width: 451
        height: 300
        border.color: "black"
        Image {
            sourceSize.height: 300
            sourceSize.width: 600
            id: srcimg
            source: "../Images/IMG_0001.jpg"
            //source : Qt.resolvedUrl("file:///home/veko/Downloads/IMG_0001.jpg")
        }
    }

    RowLayout{
        Button {
            text: "OCR"
            onClicked: tesseractCtrl.readImage()

        }
        Button {
            text: "Select File"
            onClicked: fileDialog.open()
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
    }

}
