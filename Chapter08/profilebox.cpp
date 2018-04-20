#include "profilebox.h"

profileBox::profileBox(QGraphicsItem *parent) : QGraphicsItemGroup(parent)
{
	QBrush brush(Qt::white);
	QPen pen(Qt::black);
	QFont font;
	font.setFamily("Arial");
	font.setPointSize(12);

	QGraphicsRectItem* rectangle = new QGraphicsRectItem();
	rectangle->setRect(0, 0, 90, 100);
	rectangle->setBrush(brush);
	rectangle->setPen(pen);

	nameTag = new QGraphicsTextItem();
	nameTag->setPlainText("");
	nameTag->setFont(font);

	QGraphicsPixmapItem* picture = new QGraphicsPixmapItem();
	QPixmap pixmap(":/images/person-icon-blue.png");
	picture->setPixmap(pixmap);
	picture->setPos(15, 30);

	this->addToGroup(rectangle);
	this->addToGroup(nameTag);
	this->addToGroup(picture);

	this->setFlag(QGraphicsItem::ItemIsMovable);
	this->setFlag(QGraphicsItem::ItemIsSelectable);
	this->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

void profileBox::init(QString name, MainWindow *window, QGraphicsScene* scene)
{
	nameTag->setPlainText(name);
	mainWindow = window;
	scene->addItem(this);
}

QVariant profileBox::itemChange(GraphicsItemChange change, const QVariant &value)
{
	if (change == QGraphicsItem::ItemPositionChange)
	{
		qDebug() << "Item moved";

		mainWindow->updateLines();
	}

	return QGraphicsItem::itemChange(change, value);
}
