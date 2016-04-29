#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	DoReMiPlayer w;
	w.show();
	return a.exec();
}