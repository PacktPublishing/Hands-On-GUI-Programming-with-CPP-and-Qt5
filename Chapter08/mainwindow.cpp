#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connected = false;
	recording = false;
	camera = new QCamera();

	qDebug() << QCameraInfo::availableCameras().count();

	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	foreach (const QCameraInfo &cameraInfo, cameras)
	{
		qDebug() << cameraInfo.deviceName() << cameraInfo.description() << cameraInfo.position();

		ui->deviceSelection->addItem(cameraInfo.description());
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::connectCamera()
{
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	foreach (const QCameraInfo &cameraInfo, cameras)
	{
		qDebug() << cameraInfo.description() << ui->deviceSelection->currentText();

		if (cameraInfo.description() == ui->deviceSelection->currentText())
		{
			camera = new QCamera(cameraInfo);
			viewfinder = new QCameraViewfinder(this);
			camera->setViewfinder(viewfinder);
			ui->webcamLayout->addWidget(viewfinder);

			connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(cameraError(QCamera::Error)));

			connected = true;
			ui->connectButton->setText("Disconnect");

			camera->start();

			return;
		}
	}
}

void MainWindow::on_connectButton_clicked()
{
	if (!connected)
	{
		connectCamera();
	}
	else
	{
		camera->stop();
		viewfinder->deleteLater();
		ui->connectButton->setText("Connect");
		connected = false;
	}
}

void MainWindow::on_captureButton_clicked()
{
	if (connected)
	{
		imageCapture = new QCameraImageCapture(camera);
		camera->setCaptureMode(QCamera::CaptureStillImage);
		camera->searchAndLock();
		imageCapture->capture(qApp->applicationDirPath());
		camera->unlock();
	}
}

void MainWindow::on_recordButton_clicked()
{
	if (connected)
	{
		if (!recording)
		{
			recorder = new QMediaRecorder(camera);
			connect(recorder, SIGNAL(error(QMediaRecorder::Error)), this, SLOT(cameraError(QCamera::Error)));
			camera->setCaptureMode(QCamera::CaptureVideo);
			recorder->setOutputLocation(QUrl(qApp->applicationDirPath()));
			recorder->record();
			recording = true;
		}
		else
		{
			recorder->stop();
			recording = false;
		}
	}
}

void MainWindow::cameraError(QCamera::Error error)
{
	qDebug() << error;

	connected = false;
	camera->stop();
	ui->connectButton->setText("Connect");
}

void MainWindow::recordError(QMediaRecorder::Error error)
{
	qDebug() << recorder->errorString();
}
