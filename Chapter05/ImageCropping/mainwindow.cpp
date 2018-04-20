#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	canDraw = false;
	pix = new QPixmap;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
	if (canDraw)
	{
		paintImage("", ui->productImage->pos().x(), ui->productImage->pos().y());
	}
}

void MainWindow::paintImage(QString fileName, int x, int y)
{
	QPainter painter;
	QImage saveImage(150, 150, QImage::Format_RGB16);

	if (fileName != "")
	{
		painter.begin(&saveImage);
	}
	else
	{
		painter.begin(this);
	}

	if (!pix->isNull())
	{
		painter.setClipRect(x, y, 150, 150);
		painter.fillRect(QRect(x, y, 150, 150), Qt::SolidPattern);
		painter.drawPixmap(x - drawPos.x(), y - drawPos.y(), drawSize.width(), drawSize.height(), *pix);
	}

	painter.end();

	if (fileName != "")
	{
		saveImage.save(fileName);
		QMessageBox::information(this, "Success", "Image has been successfully saved!");
	}
}

void MainWindow::on_browseButton_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(), tr("Image Files (*.jpg *.jpeg)"));

	if (fileName != "")
	{
		QPixmap* newPix = new QPixmap(fileName);

		if (!newPix->isNull())
		{
			if (newPix->width() < 150 || newPix->height() < 150)
			{
				QMessageBox::warning(this, tr("Invalid Size"), tr("Image size too small. Please use an image larger than 150x150."));
				return;
			}

			pix = newPix;
			imageSize = pix->size();
			drawSize = pix->size();

			canDraw = true;
		}
		else
		{
			canDraw = false;

			QMessageBox::warning(this, tr("Invalid Image"), tr("Invalid or corrupted file. Please try again with another image file."));
		}
	}
}

void MainWindow::on_scaleSlider_valueChanged(int value)
{
	drawSize = imageSize * value / 100;
	update();
}

void MainWindow::on_leftSlider_valueChanged(int value)
{
	drawPos.setX(value * drawSize.width() / 100 * 0.5);
	update();
}

void MainWindow::on_topSlider_valueChanged(int value)
{
	drawPos.setY(value * drawSize.height() / 100 * 0.5);
	update();
}

void MainWindow::on_saveButton_clicked()
{
	if (canDraw)
	{
		if (!pix->isNull())
		{
			// Save new pic from painter
			paintImage(QCoreApplication::applicationDirPath() + "/image.jpg", 0, 0);
		}
	}
}
