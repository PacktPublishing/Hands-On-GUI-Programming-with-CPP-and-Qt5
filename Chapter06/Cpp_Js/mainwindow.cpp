#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webview = new QWebEngineView(ui->verticalFrame);
    webview->load(QUrl("qrc:///html/test.html"));

    QWebChannel* channel = new QWebChannel(this);
    channel->registerObject("mainwindow", this);
    webview->page()->setWebChannel(channel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doSomething()
{
    ui->label->setText("This text has been changed by javascript!");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    webview->resize(ui->verticalFrame->size());
}

void MainWindow::on_pushButton_clicked()
{
    webview->page()->runJavaScript("hello();");
}
