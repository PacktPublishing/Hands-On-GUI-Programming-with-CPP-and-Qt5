import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 800
    height: 600
    title: qsTr("My App")

    MainForm
    {
        anchors.fill: parent

        emailTouch.onClicked:
        {
            emailDisplay.visible = false;	// Hide emailDisplay
            emailInput.forceActiveFocus();	// Focus emailInput
            Qt.inputMethod.show();			// Activate virtual keyboard
        }

        emailInput.onFocusChanged:
        {
            if (emailInput.focus == false && emailInput.text == "")
            {
                emailDisplay.visible = true;	// Show emailDisplay if emailInput is empty when loses focus
            }
        }

        passwordTouch.onClicked:
        {
            passwordDisplay.visible = false;	// Hide passwordDisplay
            passwordInput.forceActiveFocus();	// Focus passwordInput
            Qt.inputMethod.show();				// Activate virtual keyboard
        }

        passwordInput.onFocusChanged:
        {
            if (passwordInput.focus == false && passwordInput.text == "")
            {
                passwordDisplay.visible = true;	// Show passwordDisplay if passwordInput is empty when loses focus
            }
        }

        loginMouseArea.onClicked:
        {
            console.log("Login pressed");
        }
    }
}
