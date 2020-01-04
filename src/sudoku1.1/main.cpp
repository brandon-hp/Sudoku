#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<string>
#include"sudoku.h"
void SolvSudokuN(char*);
long long check_argument(int , char **);
void CreateSudokuN(long long );
int Base[9] = { HEAD,2,3,4,5,6,7,8,1 };
long long curnum = 0;
char wfile[200000000] = {0};
long long stringNum = 0;
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
void Perm(int list[], int k, int m,long long num,FILE *w) {
	if (curnum >= num)
		return;
	 if (k == m) {
		 Sudoku temp;
		 temp.GetBase(list);
		 temp.Create();
		 for (int i = 0; i < 2; i++)
		 {
			 for (int j = 0; j < 6; j++)
			 {
				 for (int k = 0; k < 6; k++)
				 {
					 temp.GetArry(wfile,stringNum);
					 wfile[stringNum++] = '\n';
					 curnum++;
					 if (curnum >= num)
						 return;
				
					 switch (k % 2)
					 {
					 case 0:temp.rowExchange(7, 8); break;
					 case 1:temp.rowExchange(6, 7); break;
					 default:break;
					 }
				 }


				 switch (j%2)
				 {
				 case 0:temp.rowExchange(4, 5); break;
				 case 1:temp.rowExchange(3, 4); break;
				 default:break;
				 }
			 }
			 temp.rowExchange(1, 2);
		 }



	 }
	 else {
		 for (int i = k; i <= m; i++) {

			 swap(list[i], list[k]);
			 Perm(list, k + 1, m,num,w);
			 if (curnum >= num)
				 return;
			 swap(list[i],list[k]);
		 }
	 }

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
	 curnum = 0;
	 FILE *Write;
	 fopen_s(&Write, TARGET, "w");
	 if (Write == NULL)
	 {
		 cout << "创建文件错误"<<endl;
		 return;
	 }
	 for (int i = 1; i < 9; i++)  
	 {
		 swap(Base[i], Base[rand() % 8 + 1]);
	 }
	 Perm(Base, 1, 8, num, Write);
	 fprintf(Write, "%s", wfile);
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
