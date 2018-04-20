#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// List Widget
	ui->listWidget->addItem("My Test Item");

	QListWidgetItem* listItem = new QListWidgetItem;
	listItem->setText("My Second Item");
	listItem->setData(100, 1000);
	ui->listWidget->addItem(listItem);

	qDebug() << listItem->data(100);

	// Tree Widget
	QTreeWidgetItem* treeItem = new QTreeWidgetItem;
	treeItem->setText(0, "My Test Item");
	ui->treeWidget->addTopLevelItem(treeItem);

	QTreeWidgetItem* treeItem2 = new QTreeWidgetItem;
	treeItem2->setText(0, "My Test Item");
	treeItem->addChild(treeItem2);

	// Table Widget
	QTableWidgetItem* tableItem = new QTableWidgetItem;
	tableItem->setText("Testing");
	ui->tableWidget->setItem(0, 0, tableItem);

	QTableWidgetItem* tableItem2 = new QTableWidgetItem;
	tableItem2->setText("Testing");
	ui->tableWidget->setItem(1, 2, tableItem2);
}

MainWindow::~MainWindow()
{
	delete ui;
}
