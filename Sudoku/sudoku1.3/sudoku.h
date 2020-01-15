#ifndef SUDOKU
#define SUDOKU
#include<iostream>
#include<ctime>
#include<algorithm>
#include <cstring>
#define TARGET "sudoku.txt"
#define SCALE 9
#define HEAD 9
using namespace std;
class Sudoku
{
public:
	int arry[9][9];
	int rows;
	int cols;
	bool IsOver;
	int count;
	int index[100][3];
	int IfRows[10][10];  //第i行是否存在j 
	int IfCols[10][10];    //第i列是否存在j 
	int grid[10][10];  //第i个小宫格是否存在j 
	int Tgrid[10][10];
	int TempArry[9][9];
	int base[9] = { HEAD,2,3,4,5,6,7,8,1 };

	Sudoku()
	{
		srand((unsigned)time(NULL));
		cols = rows = SCALE;
		count = 0;
		memset(arry, 0, sizeof(arry));
		memset(IfRows, 0, sizeof(IfRows));
		memset(IfCols, 0, sizeof(IfCols));
		memset(grid, 0, sizeof(grid));
		memset(Tgrid, 0, sizeof(Tgrid));
		memset(index, 0, sizeof(index));
		memset(TempArry, 0, sizeof(TempArry));
		IsOver = false;
		
	}
	void GetBase(int *list);
	void Clear();
	void Create();
	void dfs(int a, int b);
	void FillFile(FILE* w);
	void RandBase();
	int GetFile(FILE*);
	int  Solv(int);
	void GeneratingEndgame();
	void rowExchange(const int& r1, const int& r2);
	void colExchange(const int& c1, const int& c2);
	void GetArry(char *w,long long &num);
	int Check();
};





#endif // DEBUG


#pragma once
