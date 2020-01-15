#include "SudokuGUI.h"
#include <QMessageBox>
SudokuGUI::SudokuGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.Start, SIGNAL(clicked()), this, SLOT(FillSudoku()));
	connect(ui.tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(ChangeSudoku(int, int)));
	connect(ui.Submit, SIGNAL(clicked()), this, SLOT(SubmitSudoku()));
	connect(ui.Exit, SIGNAL(clicked()), this, SLOT(close()));
}
void SudokuGUI::SubmitSudoku()
{
	QMessageBox box;
	int flags = Sudoku.Check();
	if (flags == 0) {

		box.information(NULL, "Title", "VICTORY");
		Sudoku.Clear();
		ui.tableWidget->clear();
	}
	else
	{
		box.setIcon(QMessageBox::Critical);
		box.setText("GAME OVER");
		box.addButton("Continue", QMessageBox::RejectRole);
		box.addButton("Restart", QMessageBox::AcceptRole);
		if (box.exec() == QDialog::Accepted)
		{
			ui.tableWidget->clear();
			Sudoku.Clear();
		}
	}

}
void SudokuGUI::ChangeSudoku(int row, int col)
{
	QTableWidgetItem *item = ui.tableWidget->item(row, col);
	QString s = item->text();
	int tempi = s.toInt();
	if (tempi < 10 && tempi > 0)
	{
		Sudoku.arry[row][col] = tempi;
	}
	else
	{
		ui.tableWidget->item(row, col)->setText("");
		QMessageBox::about(NULL, "warm", "Invalid number");
	}
}
void SudokuGUI::FillSudoku()
{
	disconnect(ui.tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(ChangeSuduku(int, int)));
	Sudoku.Clear();
	Sudoku.RandBase();
	Sudoku.Create();
	Sudoku.GeneratingEndgame();
	for (int i = 0; i < SCALE; i++)
	{
		for (int j = 0; j < SCALE; j++)
		{
			if (Sudoku.arry[i][j] != 0) {

				QTableWidgetItem *item = new QTableWidgetItem;
				item->setText(QString(Sudoku.arry[i][j] + '0'));
				ui.tableWidget->setItem(i, j, item);
				ui.tableWidget->item(i, j)->setForeground(QBrush(QColor(255, 0, 0)));
				ui.tableWidget->item(i, j)->setFlags(ui.tableWidget->item(i, j)->flags() & ~Qt::ItemIsEnabled);

			}


		}

	}
	connect(ui.tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(ChangeSuduku(int, int)));

}