#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCameraInfo>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QUrl>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void connectCamera();

private slots:
	void on_connectButton_clicked();
	void on_captureButton_clicked();
	void on_recordButton_clicked();

	void cameraError(QCamera::Error error);
	void recordError(QMediaRecorder::Error error);

private:
	Ui::MainWindow *ui;
	QCamera* camera;
	QCameraViewfinder* viewfinder;
	QCameraImageCapture* imageCapture;
	QMediaRecorder* recorder;

	bool connected;
	bool recording;
};

#endif // MAINWINDOW_H
