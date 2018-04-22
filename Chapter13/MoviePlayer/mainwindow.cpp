#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	player = new QMediaPlayer(this);

	QVideoWidget* videoWidget = new QVideoWidget(this);
	ui->movieLayout->addWidget(videoWidget);
	player->setVideoOutput(videoWidget);

	player->setVolume(ui->volume->value());
	connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::stateChanged);
	connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Select Movie File", qApp->applicationDirPath(), "MP4 (*.mp4);;MOV (*.mov)");
	QFileInfo fileInfo(fileName);

	player->setMedia(QUrl(fileName));

	if (player->isMetaDataAvailable())
	{
		QString albumTitle = player->metaData(QMediaMetaData::AlbumTitle).toString();
		ui->movieNameDisplay->setText("Playing " + albumTitle);
	}
	else
	{
		ui->movieNameDisplay->setText("Playing " + fileInfo.fileName());
	}

	ui->playButton->setEnabled(true);
	ui->playButton->click();
}

void MainWindow::on_playButton_clicked()
{
	player->play();
}

void MainWindow::on_pauseButton_clicked()
{
	player->pause();
}

void MainWindow::on_stopButton_clicked()
{
	player->stop();
}

void MainWindow::stateChanged(QMediaPlayer::State state)
{
	if (state == QMediaPlayer::PlayingState)
	{
		ui->playButton->setEnabled(false);
		ui->pauseButton->setEnabled(true);
		ui->stopButton->setEnabled(true);
	}
	else if (state == QMediaPlayer::PausedState)
	{
		ui->playButton->setEnabled(true);
		ui->pauseButton->setEnabled(false);
		ui->stopButton->setEnabled(true);
	}
	else if (state == QMediaPlayer::StoppedState)
	{
		ui->playButton->setEnabled(true);
		ui->pauseButton->setEnabled(false);
		ui->stopButton->setEnabled(false);
	}
}

void MainWindow::positionChanged(qint64 position)
{
	if (ui->progressbar->maximum() != player->duration())
		ui->progressbar->setMaximum(player->duration());

	ui->progressbar->setValue(position);

	int seconds = (position/1000) % 60;
	int minutes = (position/60000) % 60;
	int hours = (position/3600000) % 24;
	QTime time(hours, minutes,seconds);
	ui->durationDisplay->setText(time.toString());
}

void MainWindow::on_volume_sliderMoved(int position)
{
	player->setVolume(position);
}

void MainWindow::on_progressbar_sliderMoved(int position)
{
	player->setPosition(position);
}
