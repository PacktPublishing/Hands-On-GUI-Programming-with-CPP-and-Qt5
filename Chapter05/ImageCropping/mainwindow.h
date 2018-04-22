#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QFileDialog>
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
	void paintImage(QString fileName, int x, int y);

protected:
	virtual void paintEvent(QPaintEvent *event);

private slots:
	void on_browseButton_clicked();
	void on_scaleSlider_valueChanged(int value);
	void on_leftSlider_valueChanged(int value);
	void on_topSlider_valueChanged(int value);
	void on_saveButton_clicked();

private:
	Ui::MainWindow *ui;

	bool canDraw;
	QPixmap* pix;
	QSize imageSize;
	QSize drawSize;
	QPoint drawPos;
};

#endif // MAINWINDOW_H
