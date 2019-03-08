import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

ColumnLayout {
    //Layout.fillWidth: true
    Layout.margins: 10
    TextField{
        text: cardTemplate.blue

        implicitWidth: 500
    }
    TextField {
        text: cardTemplate.pink
        implicitWidth: 500
    }
    TextField {
        text: cardTemplate.yellow
        implicitWidth: 500
    }
    TextField {
        text: cardTemplate.purple
        implicitWidth: 500
    }
    TextField {
        text: cardTemplate.green
        implicitWidth: 500
    }
    TextField {
        text: cardTemplate.orange
        implicitWidth: 500
    }
}


