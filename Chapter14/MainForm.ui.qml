import QtQuick 2.6

Item {
    id: loginForm
    width: 400
    height: 400

    property alias emailTouch: emailTouch
    property alias emailDisplay: emailDisplay
    property alias emailInput: emailInput
    property alias passwordTouch: passwordTouch
    property alias passwordDisplay: passwordDisplay
    property alias passwordInput: passwordInput
    property alias loginMouseArea: loginMouseArea

    Image {
        id: background
        enabled: true
        anchors.rightMargin: -1
        anchors.leftMargin: -1
        anchors.bottomMargin: -1
        anchors.topMargin: -1
        visible: true
        sourceSize.height: 1275
        sourceSize.width: 1920
        fillMode: Image.PreserveAspectCrop
        z: -1
        anchors.fill: parent
        source: "images/background.jpg"

        Rectangle {
            id: loginRect
            x: 0
            y: 95
            width: 402
            height: 210
            color: "#fcf9f4"
            anchors.horizontalCenter: parent.horizontalCenter
            enabled: true
            anchors.verticalCenterOffset: 50
            border.color: "#efedeb"
            border.width: 1
            anchors.verticalCenter: parent.verticalCenter

            Rectangle {
                id: emailRect
                height: 35
                color: "#ffffff"
                radius: 0
                border.color: "#efedeb"
                border.width: 1
                anchors.verticalCenterOffset: -55
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 25
                anchors.right: parent.right
                anchors.rightMargin: 25

                TextInput {
                    id: emailInput
                    height: 20
                    text: qsTr("")
                    font.wordSpacing: 1
                    selectionColor: "#4f0080"
                    activeFocusOnPress: false
                    font.family: "Verdana"
                    anchors.verticalCenterOffset: 3
                    anchors.right: parent.right
                    anchors.rightMargin: 40
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                }

                Image {
                    id: emailIcon
                    width: 18
                    height: 18
                    enabled: false
                    opacity: 0.6
                    fillMode: Image.PreserveAspectFit
                    sourceSize.height: 18
                    sourceSize.width: 18
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    source: "images/email-icon.png"
                }

                MouseArea {
                    id: emailTouch
                    hoverEnabled: true
                    anchors.fill: parent
                    cursorShape: containsMouse ? Qt.IBeamCursor : Qt.ArrowCursor
                }

                Text {
                    id: emailDisplay
                    color: "#cbbdbd"
                    text: qsTr("E-Mail")
                    enabled: false
                    anchors.verticalCenterOffset: -1
                    anchors.left: parent.left
                    anchors.leftMargin: 21
                    anchors.right: parent.right
                    anchors.rightMargin: 40
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                }
            }

            Rectangle {
                id: passwordRect
                height: 35
                color: "#ffffff"
                radius: 2
                border.color: "#efedeb"
                border.width: 1
                anchors.verticalCenterOffset: -18
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 25
                anchors.left: parent.left
                anchors.leftMargin: 25

                TextInput {
                    id: passwordInput
                    height: 20
                    text: qsTr("")
                    activeFocusOnPress: false
                    echoMode: TextInput.Password
                    anchors.verticalCenterOffset: 2
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    anchors.right: parent.right
                    anchors.rightMargin: 40
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                }

                Image {
                    id: passwordIcon
                    width: 18
                    height: 18
                    enabled: false
                    opacity: 0.6
                    fillMode: Image.PreserveAspectFit
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    sourceSize.height: 18
                    sourceSize.width: 18
                    source: "images/password-icon.png"
                }

                MouseArea {
                    id: passwordTouch
                    hoverEnabled: true
                    anchors.fill: parent
                    cursorShape: containsMouse ? Qt.IBeamCursor : Qt.ArrowCursor
                }

                Text {
                    id: passwordDisplay
                    color: "#cbbdbd"
                    text: qsTr("Password")
                    enabled: false
                    anchors.verticalCenterOffset: -1
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 41
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    font.pixelSize: 12
                }
            }

            Rectangle {
                id: loginButton
                height: 40
                color: loginMouseArea.pressed ? "#1c914f" : "#27ae61"
                radius: 2
                enabled: true
                border.width: 0
                anchors.verticalCenterOffset: 35
                anchors.left: parent.left
                anchors.leftMargin: 25
                anchors.right: parent.right
                anchors.rightMargin: 25
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    id: loginMouseArea
                    hoverEnabled: true
                    anchors.fill: parent
                    cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
                }

                Text {
                    id: loginText
                    color: "#ffffff"
                    text: qsTr("LOGIN")
                    enabled: false
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.family: "Arial"
                    font.pixelSize: 12
                }
            }

            Image {
                id: logoDisplay
                width: 300
                height: 82
                fillMode: Image.PreserveAspectFit
                anchors.top: parent.top
                anchors.topMargin: -110
                anchors.horizontalCenter: parent.horizontalCenter
                sourceSize.height: 82
                sourceSize.width: 300
                source: "images/logo_sample.png"
            }
        }
    }
}
