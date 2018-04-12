#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtTest/QtTest>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void test();

private:
	Ui::MainWindow *ui;

private slots:
	void testString();
	void testGui();
};

#endif // MAINWINDOW_H
