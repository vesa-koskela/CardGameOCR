import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
//import io.qt.trivialocr.tesseractctrl 1.0

Window {
    visible: true
    width: 1040
    height: 480
    title: qsTr("TrivialOCR")

    RowLayout{
        anchors.fill: parent
        Image {
            fillMode: Image.PreserveAspectCrop //+ Image.PreserveAspectFit
            sourceSize.height: 300
            sourceSize.width: 600
            id: srcimg
            source : Qt.resolvedUrl("file:///home/koskela/Downloads/IMG_0001.jpg")
            //source: "../Images/IMG_0001.tiff"
        }

        TextEdit {
            id: name
            text:  tesseractCtrl.text
            Component.onCompleted: console.log(tesseractCtrl.text)
            onTextChanged: {
                console.log("textChanged")
                //name.text = tesseractCtrl.text
            }

            //text: qsTr("text")
        }
        Button {
            text: "OCR"
            onClicked: tesseractCtrl.tessImage()

        }

    }
}
