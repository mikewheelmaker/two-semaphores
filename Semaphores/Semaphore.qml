import QtQuick
import QtQuick.Layouts
import QtQml

Item {
    id: root

    height: 300
    width: 100

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
        // RED_STATE
        case 0:
            redLight.color = "red"
            orangeLight.color = "gray"
            greenLight.color = "gray"
            break;
        // RED_ORANGE_STATE
        case 1:
            redLight.color = "red"
            orangeLight.color = "orange"
            greenLight.color = "gray"
            break;
        // GREEN_STATE
        case 2:
            redLight.color = "gray"
            orangeLight.color = "gray"
            greenLight.color = "green"
            break;
        // ORANGE_STATE
        case 3:
            redLight.color = "gray"
            orangeLight.color = "orange"
            greenLight.color = "gray"
            break;
        // OFF_OFF_STATE
        case 4:
            redLight.color = "gray"
            orangeLight.color = "gray"
            greenLight.color = "gray"
            break;
        // ORANGE_OFF_STATE
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
