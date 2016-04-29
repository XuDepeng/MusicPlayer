#pragma once

#include <QStyledItemDelegate>

class NoFocusDelegate :public QStyledItemDelegate{
public:
	NoFocusDelegate(QObject* parent = 0);

	void paint(QPainter *painter, 
		const QStyleOptionViewItem &option, 
		const QModelIndex &index);
};