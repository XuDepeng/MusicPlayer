#include "NoFocusDelegate.h"

NoFocusDelegate::NoFocusDelegate(QObject* parent):
QStyledItemDelegate(parent){

}

void NoFocusDelegate::paint(QPainter *painter, 
	const QStyleOptionViewItem &option, 
	const QModelIndex &index){
	QStyleOptionViewItem itemOption(option);
	if (itemOption.state&QStyle::State_HasFocus){
		itemOption.state = itemOption.state^QStyle::State_HasFocus;
	}
	QStyledItemDelegate::paint(painter, itemOption, index);
}
