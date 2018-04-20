#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);

	connect(scene, SIGNAL(selectionChanged()), this, SLOT(selectionChanged()));

	// Draw simple graphics
	/*
	QBrush greenBrush(Qt::green);
	QBrush blueBrush(Qt::blue);
	QPen pen(Qt::black);
	pen.setWidth(2);

	QGraphicsRectItem* rectangle = scene->addRect(80, 0, 80, 80, pen, greenBrush);
	rectangle->setFlag(QGraphicsItem::ItemIsMovable);
	rectangle->setFlag(QGraphicsItem::ItemIsSelectable);

	QGraphicsEllipseItem* ellipse = scene->addEllipse(0, -80, 200, 60, pen, blueBrush);
	ellipse->setFlag(QGraphicsItem::ItemIsMovable);
	ellipse->setFlag(QGraphicsItem::ItemIsSelectable);

	QGraphicsTextItem* text = scene->addText("Hello World!", QFont("Times", 25));
	text->setFlag(QGraphicsItem::ItemIsMovable);
	text->setFlag(QGraphicsItem::ItemIsSelectable);
	*/
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::updateLines()
{
	if (lines.size() > 0)
	{
		for (int i = 0; i < lines.size(); i++)
		{
			lines.at(i)->updateLine();
		}
	}
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
	qDebug() << "Key pressed: " + event->text();

	if (event->key() == Qt::Key_Delete)
	{
		if (scene->selectedItems().size() > 0)
		{
			QGraphicsItem* item = scene->selectedItems().at(0);
			scene->removeItem(item);

			for (int i = lines.size() - 1; i >= 0; i--)
			{
				profileLine* line = lines.at(i);

				if (line->startBox == item || line->endBox == item)
				{
					lines.removeAt(i);
					scene->removeItem(line);
					delete line;
				}
			}
			delete item;
		}
	}
}

void MainWindow::selectionChanged()
{
	qDebug() << "Item selected";
}

void MainWindow::on_addButton_clicked()
{
	bool ok;
	QString name = QInputDialog::getText(this, tr("Employee Name"), tr("Please insert employee's full name here:"), QLineEdit::Normal, "John Doe", &ok);
	if (ok && !name.isEmpty())
	{
		profileBox* box = new profileBox();
		box->init(name, this, scene);

		if (scene->selectedItems().size() > 0)
		{
			profileLine* line = new profileLine();
			line->initLine(box, scene->selectedItems().at(0));
			scene->addItem(line);

			lines.push_back(line);
		}
	}
}
