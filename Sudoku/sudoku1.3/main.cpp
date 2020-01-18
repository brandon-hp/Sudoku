#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<string>
#include"UsingSudoku.h"
#include"sudoku.h"
 int main(int argc, char **argv)
 {

	 long long num= check_argument(argc, argv);
	 if (num > 0)
	 {
		 CreateSudokuN(num);
	 }
	 else if (num == 0)
	 {
		 SolvSudokuN(argv[2]);
	 }
	 return 0;
 }
