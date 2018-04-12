#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Breakpoint
	test();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::test()
{
	int amount = 100;
	amount -= 10;
	qDebug() << "You have obtained" << amount << "apples!";
}

void MainWindow::testString()
{
	QString text = "Testing";
	QVERIFY(text.toUpper() == "TESTING");
}

void MainWindow::testGui()
{
	QTest::keyClicks(ui->lineEdit, "testing gui");
	QCOMPARE(ui->lineEdit->text(), QString("testing gui"));
}
