import QtQuick 2.0
import QtQuick.Layouts 1.12

ColumnLayout {
    TextEdit {
        text: cardTemplate.blue
        //text: tesseractCtrl.text.substring(0,20)
    }
    TextEdit {
        text: tesseractCtrl.text.substring(20,40)
    }
}
