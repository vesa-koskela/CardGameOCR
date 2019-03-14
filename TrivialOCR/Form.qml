import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

ColumnLayout {
    //Layout.fillWidth: true
    Layout.margins: 10
    ColumnLayout {
        RadioButton {
            //checked: cardTemplate.side
            text: qsTr("QuestionSide")
        }
        RadioButton {
            text: qsTr("AnswerSide")
        }

    }

    RowLayout {
        Rectangle {
            width: 10
            height: 10
            color: "blue"
        }
        TextField{
            text: cardTemplate.blue
            implicitWidth: Math.max(500,this.contentWidth)
        }
    }
    RowLayout {
        Rectangle {
            width: 10
            height: 10
            color: "pink"
        }
        TextField{
            placeholderText: "pink"
            text: cardTemplate.pink
            implicitWidth: Math.max(500,(this.contentWidth+25))

        }
    }
    RowLayout {
        Rectangle {
            width: 10
            height: 10
            color: "yellow"
        }
        TextField{

            text: cardTemplate.yellow
            implicitWidth: Math.max(500,(this.contentWidth+10))
        }
    }
    RowLayout {
        Rectangle {
            width: 10
            height: 10
            color: "purple"
        }
        TextField{
            text: cardTemplate.purple
            implicitWidth: Math.max(500,this.contentWidth)
        }
    }
    RowLayout {
        Rectangle {
            width: 10
            height: 10
            color: "green"
        }
        TextField{
            text: cardTemplate.green
            implicitWidth: Math.max(500,this.contentWidth)
        }
    }
    RowLayout {
        Rectangle {
            width: 10
            height: 10
            color: "orange"
        }
        TextField{
            text: cardTemplate.orange
            implicitWidth: Math.max(500,this.contentWidth)
        }
    }
    RowLayout{
        Text {
            text: qsTr("Card #")
        }
        TextField{
            text: cardTemplate.cardNumber
        }
    }
    RowLayout{
        Text {
            text: qsTr("Edition: ")
        }
        ComboBox {
            model: ["0","1", "2", "3"]
        }
    }
}


