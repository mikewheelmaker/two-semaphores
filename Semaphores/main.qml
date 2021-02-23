import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12

ApplicationWindow {
    id: mainWindow

    width: 900
    height: 900
    visible: true
    title: qsTr("Semaphores Project")

    Connections {
        target: semaphoreManager
        onStateChanged: updateSemaphore(state)
    }

    function updateSemaphore (state)
    {
        if(state <= 3)
        {
            leftSemaphore.changeColorsFromState(state)
            rightSemaphore.changeColorsFromState((state + 2) % 4)
        }
        else
        {
            leftSemaphore.changeColorsFromState(state)
            rightSemaphore.changeColorsFromState(state)
        }
    }

    RowLayout {
        id: parentLayout

        anchors.fill: parent
        spacing: 0

        //leftSemaphore
        Semaphore {
            id: leftSemaphore

            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            Layout.preferredWidth: 100
        }

        //centreConsole
        Rectangle {
            id: backgroundCentre

            color: "lightgray"
            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            Layout.preferredWidth: 100

            ColumnLayout {
                id: centreConsole

                spacing: 10
                anchors.fill: parent

                Button {
                    id: startButton

                    text: "Start"
                    Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    onClicked: {
                        leftSemaphore.changeColorsFromState(0)
                        rightSemaphore.changeColorsFromState(2)
                        semaphoreManager.isSemaphoreOn = true
                    }
                }

                Text {
                    id: timeElapsed

                    Layout.alignment: Qt.AlignCenter
                    text: semaphoreManager.timeElapsed
                }

                Button {
                    id: stopButton

                    text: "Stop"
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    onClicked: {
                        leftSemaphore.changeColorsFromState(4)
                        rightSemaphore.changeColorsFromState(4)
                        semaphoreManager.isSemaphoreOn = false
                    }
                }
            }
        }

        //rightSemaphore
        Semaphore {
            id: rightSemaphore

            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            Layout.preferredWidth: 100
        }
    }
}
