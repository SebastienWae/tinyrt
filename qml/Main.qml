import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import com.tinyrt

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("tinyrt")

    Rectangle {
        anchors.fill: parent
        color: Material.background
    }

    RowLayout {
        anchors.fill: parent

        RTRender {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
