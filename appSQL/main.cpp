#include <QtGui/QApplication>
#include "appsql.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	appSQL w;
	w.show();
	return a.exec();
}
