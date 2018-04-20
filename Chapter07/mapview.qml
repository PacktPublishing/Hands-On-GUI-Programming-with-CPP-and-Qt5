import QtQuick 2.0
import QtLocation 5.3
import QtPositioning 5.0

Item
{
    id: window

    Plugin
    {
        id: mapPlugin
        name: "osm"
    }

    function addMarker(name, latitude, longitude)
    {
        var component = Qt.createComponent("qrc:///qml/marker.qml")
        var item = component.createObject(window, { coordinate: QtPositioning.coordinate(latitude, longitude), labelText: name })
        map.addMapItem(item)
    }

    function addCircle(latitude, longitude, radius, color, borderWidth)
    {
        var component = Qt.createComponent("qrc:///qml/circle.qml")
        var item = component.createObject(window, { center: QtPositioning.coordinate(latitude, longitude), radius: radius, color: color, borderWidth: borderWidth })
        map.addMapItem(item)
    }

    function addRectangle(startLat, startLong, endLat, endLong, color, borderWidth)
    {
        var component = Qt.createComponent("qrc:///qml/rectangle.qml")
        var item = component.createObject(window, { topLeft: QtPositioning.coordinate(startLat, startLong), bottomRight: QtPositioning.coordinate(endLat, endLong), color: color, borderWidth: borderWidth })
        map.addMapItem(item)
    }

    function addPolygon(path, color, borderWidth)
    {
        var component = Qt.createComponent("qrc:///qml/polygon.qml")
        var item = component.createObject(window, { path: path, color: color, borderWidth: borderWidth })
        map.addMapItem(item)
    }

    Map
    {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(40.7264175,-73.99735)
        zoomLevel: 14

        Component.onCompleted:
        {
            // Use QML to add markers to the map
            /*addMarker("Restaurant", 40.7274175,-73.99835)
            addMarker("My Home", 40.7276432,-73.98602)
            addMarker("School", 40.7272175,-73.98935)*/

            //addCircle(40.7274175,-73.99835, 250, "green", 3);
            //addRectangle(40.7274175,-73.99835, 40.7376432, -73.98602, "red", 2)
            var path = [{ latitude: 40.7324281, longitude: -73.97602 },
                        { latitude: 40.7396432, longitude: -73.98666 },
                        { latitude: 40.7273266, longitude: -73.99835 },
                        { latitude: 40.7264281, longitude: -73.98602 }];
            addPolygon(path, "blue", 3);
        }
    }
}
