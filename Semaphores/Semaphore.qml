import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12

Item {
    id: root

    width: 100
    height: 100

    Rectangle {
        id: backgroundRectangle

        color: "black"
        anchors.fill: parent

        ColumnLayout {
            id: columnLayoutContainer

            spacing: 0
            anchors.fill: parent

            Rectangle {
                id: redLight

                color: "red"
                Layout.preferredHeight: 100
                Layout.preferredWidth: 100
                Layout.alignment: Qt.AlignCenter
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.margins: 25
                radius: this.width / 2
            }

            Rectangle {
                id: orangeLight

                color: "orange"
                Layout.preferredHeight: 100
                Layout.preferredWidth: 100
                Layout.alignment: Qt.AlignCenter
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.margins: 25
                radius: this.width / 2
            }

            Rectangle {
                id: greenLight

                color: "green"
                Layout.preferredHeight: 100
                Layout.preferredWidth: 100
                Layout.alignment: Qt.AlignCenter
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.margins: 25
                radius: this.width / 2
            }
        }
    }

    function changeColorsFromState(state)
    {
        switch(state)
        {
        case 0:
            redLight.color = "red"
            orangeLight.color = "gray"
            greenLight.color = "gray"
            break;
        case 1:
            redLight.color = "red"
            orangeLight.color = "orange"
            greenLight.color = "gray"
            break;
        case 2:
            redLight.color = "gray"
            orangeLight.color = "gray"
            greenLight.color = "green"
            break;
        case 3:
            redLight.color = "gray"
            orangeLight.color = "orange"
            greenLight.color = "gray"
            break;
        case 4:
            redLight.color = "gray"
            orangeLight.color = "gray"
            greenLight.color = "gray"
            break;
        case 5:
            redLight.color = "gray"
            orangeLight.color = "orange"
            greenLight.color = "gray"
            break;
        default:
            break;
        }
    }
}
