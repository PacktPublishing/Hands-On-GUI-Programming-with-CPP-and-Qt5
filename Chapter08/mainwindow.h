#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QKeyEvent>

#include "profilebox.h"
#include "profileline.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void updateLines();
	void keyReleaseEvent(QKeyEvent* event);

private:
	Ui::MainWindow *ui;

	QGraphicsScene* scene;
	QList<profileLine*> lines;

public slots:
	void selectionChanged();

private slots:
	void on_addButton_clicked();
};

#endif // MAINWINDOW_H
