#include "SudokuGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SudokuGUI w;
	w.show();
	return a.exec();
}
