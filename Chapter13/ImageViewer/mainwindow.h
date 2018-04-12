#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	virtual void paintEvent(QPaintEvent *event);
	void resizeImage();

private slots:
	void on_actionOpen_triggered();

private:
	Ui::MainWindow *ui;
	QPixmap* imageBuffer;
};

#endif // MAINWINDOW_H
