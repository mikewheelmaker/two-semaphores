import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQml

ApplicationWindow {
    id: mainWindow

    height: 900
    width: 700
    visible: true
    title: qsTr("Two Semaphores Project")

    Connections {
        target: semaphoreManager

        function onStateChanged(state)
        {
            if(state <= 3)
            {
                if(semaphoreManager.syncedOnState === false)
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
            else
            {
                if(semaphoreManager.syncedOffState === false)
                {
                    leftSemaphore.changeColorsFromState(((state + 1) % 2) + 4)
                    rightSemaphore.changeColorsFromState((state % 2) + 4)
                }
                else
                {
                    leftSemaphore.changeColorsFromState(state)
                    rightSemaphore.changeColorsFromState(state)
                }
            }
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
            Layout.preferredHeight: 900
            Layout.preferredWidth: 300
        }

        //centreConsole
        Rectangle {
            id: backgroundCentre

            color: "lightgray"
            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 900
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
                        if(semaphoreManager.syncedOnState === true) {
                            leftSemaphore.changeColorsFromState(0)
                            rightSemaphore.changeColorsFromState(0)
                        }
                        else {
                            leftSemaphore.changeColorsFromState(0)
                            rightSemaphore.changeColorsFromState(2)
                        }
                        semaphoreManager.isSemaphoreOn = true
                    }
                }

                Button {
                    id: stopButton

                    text: "Stop"
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    onClicked: {
                        if(semaphoreManager.syncedOffState === true) {
                            leftSemaphore.changeColorsFromState(4)
                            rightSemaphore.changeColorsFromState(4)
                        }
                        else {
                            leftSemaphore.changeColorsFromState(4)
                            rightSemaphore.changeColorsFromState(5)
                        }
                        semaphoreManager.isSemaphoreOn = false
                    }
                }

                Text {
                    id: timeElapsed

                    Layout.alignment: Qt.AlignCenter
                    text: {
                        if(semaphoreManager.isSemaphoreOn === true) {
                            semaphoreManager.timeElapsed + 1
                        }
                        else {
                            ""
                        }
                    }
                }

                Button {
                    id: alternateOnStateButton

                    text: {
                        if(semaphoreManager.syncedOnState === true) {
                            "Unsync On State"
                        }
                        else {
                            "Sync On State"
                        }
                    }

                    Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    onClicked: {
                        semaphoreManager.syncedOnState = !semaphoreManager.syncedOnState
                    }
                }

                Button {
                    id: alternateOffStateButton

                    text: {
                        if(semaphoreManager.syncedOffState === true) {
                            "Unsync Off State"
                        }
                        else {
                            "Sync Off State"
                        }
                    }

                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    onClicked: {
                        semaphoreManager.syncedOffState = !semaphoreManager.syncedOffState
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
            Layout.preferredHeight: 900
            Layout.preferredWidth: 300
        }
    }
}
