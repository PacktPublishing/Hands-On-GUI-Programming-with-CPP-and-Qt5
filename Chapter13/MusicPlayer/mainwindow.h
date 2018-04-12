#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_actionOpen_File_triggered();

	void on_playButton_clicked();
	void on_pauseButton_clicked();
	void on_stopButton_clicked();

	void stateChanged(QMediaPlayer::State state);
	void positionChanged(qint64 position);

	void on_volume_sliderMoved(int position);
	void on_progressbar_sliderMoved(int position);

private:
	Ui::MainWindow *ui;

	QMediaPlayer* player;
};

#endif // MAINWINDOW_H
