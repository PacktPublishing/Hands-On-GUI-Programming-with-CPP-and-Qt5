#ifndef PROFILEBOX_H
#define PROFILEBOX_H

#include <QWidget>
#include <QDebug>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#include "mainwindow.h"

class MainWindow;

class profileBox : public QGraphicsItemGroup
{
public:
	explicit profileBox(QGraphicsItem* parent = nullptr);
	void init(QString name, MainWindow* window, QGraphicsScene* scene);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

signals:

public slots:

private:
	MainWindow* mainWindow;
	QGraphicsTextItem* nameTag;
};

#endif // PROFILEBOX_H
