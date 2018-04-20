#include "profileline.h"

profileLine::profileLine(QGraphicsItem *parent) : QGraphicsLineItem(parent)
{
	QPen pen(Qt::black);
	pen.setWidth(2);
	this->setPen(pen);

	this->setZValue(-999);
}

void profileLine::initLine(QGraphicsItem* start, QGraphicsItem* end)
{
	startBox = start;
	endBox = end;

	updateLine();
}

void profileLine::updateLine()
{
	if (startBox != NULL && endBox != NULL)
	{
		this->setLine(startBox->pos().x() + startBox->boundingRect().width() / 2, startBox->pos().y() + startBox->boundingRect().height() / 2, endBox->pos().x() + endBox->boundingRect().width() / 2, endBox->pos().y() + endBox->boundingRect().height() / 2);
	}
}
