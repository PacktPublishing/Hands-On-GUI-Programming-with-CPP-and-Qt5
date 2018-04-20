#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Built-in method
	//QMessageBox::question(this, "Alert", "Just to let you know, something happened!");
	//QMessageBox::warning(this, "Alert", "Just to let you know, something happened!");
	//QMessageBox::information(this, "Alert", "Just to let you know, something happened!");
	//QMessageBox::critical(this, "Alert", "Just to let you know, something happened!");
	//QMessageBox::about(this, "No Icon", "This message box carries no icon.");

	// Set buttons
	//QMessageBox::question(this, "Serious Question", "Am I an awesome guy?", QMessageBox::Ignore, QMessageBox::Yes);

	// Manual way
	/*QMessageBox msgBox;
	msgBox.setWindowTitle("Alert");
	msgBox.setText("Just to let you know, something happened!");
	msgBox.exec();*/

	// Custom message box
	/*QMessageBox msgBox;
	msgBox.setWindowTitle("Serious Question");
	msgBox.setText("Am I an awesome guy?");
	msgBox.addButton("Seriously Yes!", QMessageBox::YesRole);
	msgBox.addButton("Well no thanks", QMessageBox::NoRole);
	msgBox.setIcon(QMessageBox::Question);
	msgBox.exec();*/

	// Custom icon
	QMessageBox msgBox;
	msgBox.setWindowTitle("Serious Question");
	msgBox.setText("Am I an awesome guy?");
	msgBox.addButton("Seriously Yes!", QMessageBox::YesRole);
	msgBox.addButton("Well no thanks", QMessageBox::NoRole);
	QPixmap myIcon(":/images/icon.png");
	msgBox.setIconPixmap(myIcon);
	msgBox.exec();

	// Event (Built-in)
	/*if (QMessageBox::question(this, "Question", "Some random question. Yes or no?") == QMessageBox::Yes)
	{
		QMessageBox::warning(this, "Yes", "You have pressed Yes!");
	}
	else
	{
		QMessageBox::warning(this, "No", "You have pressed No!");
	}*/

	// Event (Custom)
	/*QMessageBox msgBox;
	msgBox.setWindowTitle("Serious Question");
	msgBox.setText("Am I an awesome guy?");
	QPushButton* yesButton = msgBox.addButton("Seriously Yes!", QMessageBox::YesRole);
	QPushButton* noButton = msgBox.addButton("Well no thanks", QMessageBox::NoRole);
	msgBox.setIcon(QMessageBox::Question);
	msgBox.exec();

	if (msgBox.clickedButton() == (QAbstractButton*) yesButton)
	{
		QMessageBox::warning(this, "Yes", "Oh thanks! :)");
	}
	else if (msgBox.clickedButton() == (QAbstractButton*) noButton)
	{
		QMessageBox::warning(this, "No", "Oh why... :(");
	}*/

	// File dialog
	/*QString fileName = QFileDialog::getOpenFileName(this);
	qDebug() << fileName;*/

	// Custom file dialog
	//QString fileName = QFileDialog::getOpenFileName(this, "Your title", QDir::currentPath(), "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
	//qDebug() << fileName;
}

MainWindow::~MainWindow()
{
	delete ui;
}
