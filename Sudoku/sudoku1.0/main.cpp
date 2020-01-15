#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include"sudoku.h"
void SolvSudokuN(char*);
long long check_argument(int , char **);
void CreateSudokuN(long long );

 int main(int argc, char **argv)
 {
	 
	 long long num = check_argument(argc, argv);
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

 long long check_argument(int argc, char **argv)
 {
	 if (argc != 3)
	 {
		 cout << "参数数量不正确！" << endl;
		 exit(-1);
	 }
	 else if (!strcmp("-c", argv[1]))
	 {
		 long long num = atoll(argv[2]);
		 if (num > 1000000 || num <= 0)
		 {
			 cout << "-c功能 没有输入数独数量或者数量过大!" << endl;
			 exit(-1);
		 }
		 return num;

	 }
	 else if (!strcmp("-s", argv[1]))
	 {
		 return 0;
	 }
	 else
	 {
		 cout << "程序没有改功能!" << endl;
		 exit(-1);
	 }
 }
 void CreateSudokuN(long long num)
 {
	 FILE *Write;
	 fopen_s(&Write, TARGET, "w");
	 if (Write == NULL)
	 {
		 cout << "创建文件错误"<<endl;
		 return;
	 }
	 for (long long i = 0; i < num; i++)
	 {

		 Sudoku temp;
		 temp.Create();
		 temp.FillFile(Write);
	 }

	 fclose(Write);
 }
 void SolvSudokuN(char* path)
 {

	 FILE *Read, *Write;
	 fopen_s(&Read, path, "r");
	 fopen_s(&Write, TARGET, "w");
	 if (Write == NULL)
	 {
		 cout << "创建文件错误" << endl;
		 return;
	 }
	 if (Read == NULL)
	 {
		 cout << "读取文件错误" << endl;
		 return;
	 }
	 while (1)
	 {

		 Sudoku temp;
		 if (temp.GetFile(Read))
			 break;
		 temp.Solv(0);
		 temp.FillFile(Write);

	 }

	 fclose(Write);
	 fclose(Read);

 }
