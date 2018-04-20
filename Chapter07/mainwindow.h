#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QQuickItem>
#include <QQuickView>

#include <QDebug>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>

#include <QGeoServiceProvider>
#include <QGeoRoutingManager>
#include <QGeoRouteRequest>
#include <QGeoRouteReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;

private slots:
	void positionUpdated(const QGeoPositionInfo &info);

	void routeCalculated(QGeoRouteReply *reply);
	void routeError(QGeoRouteReply *reply, QGeoRouteReply::Error error, const QString &errorString);
};

#endif // MAINWINDOW_H
