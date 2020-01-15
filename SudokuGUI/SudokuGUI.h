#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuGUI.h"
#include"sudoku.h"
#include"qobject.h"

class SudokuGUI : public QMainWindow
{
	Q_OBJECT

public:
	SudokuGUI(QWidget *parent = Q_NULLPTR);
	Sudoku Sudoku;

public slots:
	void FillSudoku();
	void SubmitSudoku();
	void ChangeSudoku(int, int);

private:
	Ui::SudokuGUIClass ui;
};
