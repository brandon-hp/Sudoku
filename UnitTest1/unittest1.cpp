#include "stdafx.h"
#include "CppUnitTest.h"
#include"../sudoku/sudoku.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(GUITest)
	{
	public:
		TEST_METHOD(Test_Init)
		{
			Sudoku s;
			int base1[9] = { HEAD,2,3,4,5,6,7,8,1 };
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					Assert::IsTrue(s.arry[i][j] == 0);
					Assert::IsTrue(s.IfRows[i][j] == 0);
					Assert::IsTrue(s.IfCols[i][j] == 0);
					Assert::IsTrue(s.grid[i][j] == 0);
					Assert::IsTrue(s.Tgrid[i][j] == 0);
					Assert::IsTrue(s.TempArry[i][j] == 0);

				}
				Assert::IsTrue(s.base[i] == base1[i]);
			}
			for(int i=9;i<10;i++)
				for (int j = 9; j < 10; j++)
				{
					Assert::IsTrue(s.IfRows[i][j] == 0);
					Assert::IsTrue(s.IfCols[i][j] == 0);
					Assert::IsTrue(s.grid[i][j] == 0);
					Assert::IsTrue(s.Tgrid[i][j] == 0);

				}
			for (int i = 0; i < 100; i++)
				for (int j = 0; j < 3; j++)
					Assert::IsTrue(s.index[i][j] == 0);
		
			Assert::IsTrue(s.cols == SCALE);
			Assert::IsTrue(s.rows == SCALE);
			Assert::IsTrue(s.IsOver == false);
			Assert::IsTrue(s.count == 0);
		}
		TEST_METHOD(Test_Clear)
		{
			Sudoku s;
			

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					s.arry[i][j] =4;
					s.IfRows[i][j] =3;
					s.IfCols[i][j] =9;
					s.grid[i][j] =7;
					s.Tgrid[i][j] =4;
					s.TempArry[i][j] = 4;

				}
			}
			for (int i = 9; i<10; i++)
				for (int j = 9; j < 10; j++)
				{
					s.IfRows[i][j] =4;
					s.IfCols[i][j] =3;
					s.grid[i][j] =2;
					s.Tgrid[i][j] =1;

				}
			for (int i = 0; i < 100; i++)
				for (int j = 0; j < 3; j++)
					s.index[i][j] =7;

			s.rows = 13;
			s.cols = 14;
			s.IsOver =1;
			s.count = 1;
			s.Clear();
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					Assert::IsTrue(s.arry[i][j] == 0);
					Assert::IsTrue(s.IfRows[i][j] == 0);
					Assert::IsTrue(s.IfCols[i][j] == 0);
					Assert::IsTrue(s.grid[i][j] == 0);
					Assert::IsTrue(s.Tgrid[i][j] == 0);
					Assert::IsTrue(s.TempArry[i][j] == 0);

				}
			}
			for (int i = 9; i<10; i++)
				for (int j = 9; j < 10; j++)
				{
					Assert::IsTrue(s.IfRows[i][j] == 0);
					Assert::IsTrue(s.IfCols[i][j] == 0);
					Assert::IsTrue(s.grid[i][j] == 0);
					Assert::IsTrue(s.Tgrid[i][j] == 0);

				}
			for (int i = 0; i < 100; i++)
				for (int j = 0; j < 3; j++)
					Assert::IsTrue(s.index[i][j] == 0);

			Assert::IsTrue(s.cols == SCALE);
			Assert::IsTrue(s.rows == SCALE);
			Assert::IsTrue(s.IsOver == false);
			Assert::IsTrue(s.count == 0);

		}
		TEST_METHOD(Test_Check)
		{
			int true_arry1[9][9] = {
			{2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 },
			{3 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,8 },
			{7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{1 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,7 },
			{8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 }
			};
			int error_arry2[9][9]= {
			{ 2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 },
			{ 3 ,4 ,1 ,9 ,6 ,5 ,4 ,7 ,8 },
			{ 7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{ 5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,6 ,8 ,6 ,2 ,7 },
			{ 8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{ 9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{ 4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 }
			};
			Sudoku Ts, Es;
			for(int i=0;i<9;i++)
				for (int j = 0; j < 9; j++)
				{
					Ts.arry[i][j] = true_arry1[i][j];
					Es.arry[i][j] = error_arry2[i][j];


				}
			Assert::IsTrue(Ts.Check() == 0);
			Assert::IsFalse(Es.Check() == 0);
		}
		TEST_METHOD(Test_GeneratingEndgame)
		{
			int true_arry1[9][9] = {
				{ 2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 },
			{ 3 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,8 },
			{ 7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{ 5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,7 },
			{ 8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{ 9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{ 4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 }
			};
			Sudoku s;
			for (int i = 0; i<9; i++)
				for (int j = 0; j < 9; j++)
				{
					s.arry[i][j] = true_arry1[i][j];
				}
			s.GeneratingEndgame();
			int num = 0;
			for(int k=0;k<3;k++)
				for (int w = 0; w < 3; w++) {
					int flags = 0;
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
						{
							if (s.arry[i+3*k][j+3*w] == 0)
							{
								flags++;
								num++;
							}
						}
					Assert::IsTrue(flags >= 2);
					
				}
			Assert::IsTrue(num >= 30 && num <= 60);
		}
		TEST_METHOD(Test_RandBase)
		{
			Sudoku s;
			s.RandBase();
			int brry[10] = { 0 };
			for (int i = 0; i < 9; i++)
				brry[s.base[i]]++;
			for(int i=1;i<=9;i++)
			Assert::IsTrue(brry[i]==1);
		}
	};
	TEST_CLASS(CreateTest)
	{
	public:
		
		TEST_METHOD(Test_Create)
		{
			Sudoku s1, s2;
			int list[10] = { 1,2,4,5,3,6,7,8,9 };
			int list2[10] = { 1,2,5,4,3,6,7,9,8 };
			for (int i = 0; i < 9; i++)
			{
				s1.base[i] = list[i];
				s2.base[i] = list2[i];
			}
			s1.Create();
			s2.Create();
			Assert::IsTrue(s1.Check() == 0);
			Assert::IsTrue(s2.Check() == 0);
			int flags = 0;
			for(int i=0;i<9;i++)
				for (int j = 0; j < 9; j++)
				{
					if (s1.arry[i][j] != s2.arry[i][j])
					{
						flags = 1;
							break;
					}


				}
			Assert::IsTrue(flags == 1);
			


		}
		TEST_METHOD(Test_GetArry)
		{
			int true_arry1[9][9] = {
				{ 2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 },
			{ 3 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,8 },
			{ 7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{ 5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,7 },
			{ 8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{ 9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{ 4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 }
			};
			Sudoku s;
			for (int i = 0; i<9; i++)
				for (int j = 0; j < 9; j++)
				{
					s.arry[i][j] = true_arry1[i][j];
				}
			char w[10000];
			long long num = 0;
			s.GetArry(w, num);
			num = 0;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					Assert::IsTrue(w[num++]==(s.arry[i][j] + '0'));
					if (j == 8) {
						if(i!=8)
						Assert::IsTrue(w[num++] == '\n');
					}
					else
						Assert::IsTrue(w[num++] == ' ');
				}
			}
		}
		TEST_METHOD(Test_GetBase)
		{
			int list[10] = { 1,2,4,5,3,6,7,8,9 };
			Sudoku s;
			s.GetBase(list);
			for (int i = 0; i < 9; i++)
			{
				Assert::IsTrue(list[i] == s.base[i]);
			}
		}
		TEST_METHOD(Test_rowExchange)
		{
			int true_arry1[9][9] = {
				{ 2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 },
			{ 3 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,8 },
			{ 7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{ 5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,7 },
			{ 8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{ 9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{ 4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 }
			};
			Sudoku s;
			for (int i = 0; i<9; i++)
				for (int j = 0; j < 9; j++)
				{
					s.arry[i][j] = true_arry1[i][j];
				}
			s.rowExchange(0, 8);
			int true_arry2[9][9] = {
				{ 4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 },
			{ 3 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,8 },
			{ 7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{ 5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,7 },
			{ 8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{ 9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{ 2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 }
			};
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++) {
					Assert::IsTrue(true_arry2[i][j] == s.arry[i][j]);

				}
			}

		}
		TEST_METHOD(Test_colExchange)
		{
			int true_arry1[9][9] = {
				{ 2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 },
			{ 3 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,8 },
			{ 7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{ 5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,7 },
			{ 8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{ 9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{ 4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 }
			};
			Sudoku s;
			for (int i = 0; i<9; i++)
				for (int j = 0; j < 9; j++)
				{
					s.arry[i][j] = true_arry1[i][j];
				}
			s.colExchange(0, 8);
			int true_arry2[9][9] = {
				{ 1 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,2 },
			{ 8 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,3 },
			{ 4 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,7 },
			{ 9 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,5 },
			{ 7 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,1 },
			{ 5 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,8 },
			{ 3 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,9 },
			{ 2 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,6 },
			{ 6 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,4 }
			};
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++) {
					Assert::IsTrue(true_arry2[i][j] == s.arry[i][j]);

				}
			}

		}
		TEST_METHOD(Test_FillFile)
		{
			int true_arry1[9][9] = {
				{ 2 ,6 ,8 ,4 ,7 ,3 ,9 ,5 ,1 },
			{ 3 ,4 ,1 ,9 ,6 ,5 ,2 ,7 ,8 },
			{ 7 ,9 ,5 ,8 ,1 ,2 ,3 ,6 ,4 },
			{ 5 ,7 ,4 ,6 ,2 ,1 ,8 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,4 ,8 ,6 ,2 ,7 },
			{ 8 ,2 ,6 ,3 ,9 ,7 ,4 ,1 ,5 },
			{ 9 ,1 ,7 ,2 ,8 ,6 ,5 ,4 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,7 ,9 ,2 },
			{ 4 ,5 ,2 ,7 ,3 ,9 ,1 ,8 ,6 }
			};
			Sudoku s;
			for (int i = 0; i<9; i++)
				for (int j = 0; j < 9; j++)
				{
					s.arry[i][j] = true_arry1[i][j];
				}
			FILE  *Write;
			fopen_s(&Write, "FillFile.txt", "w");
			if (Write == NULL)
				return;
			s.FillFile(Write);
			fclose(Write);
			FILE *Read;
			fopen_s(&Read, "FillFile.txt", "r");
			if (Read == NULL)
				return;
			char buffer[20];
			for (int i = 0; i < 9; i++)
			{
				if (fgets(buffer, 20, Read) == NULL)
					break;
				for (int j = 0; j < 9; j++) {
					int temp = buffer[j * 2] - '0';
					Assert::IsTrue(temp == s.arry[i][j]);

				}
			}
			fclose(Read);

		}

	};
	TEST_CLASS(SolvTest)
	{
	public:
		TEST_METHOD(Test_Solv)
		{
			int true_arry1[9][9] = {
				{ 2 ,6 ,8 ,4 ,0 ,3 ,0,5 ,1 },
			{ 3 ,4 ,0 ,9 ,6 ,5 ,2 ,7 ,8 },
			{ 7 ,0 ,5 ,8 ,0 ,2 ,3 ,6 ,0},
			{ 5 ,7 ,0 ,6 ,2 ,1 ,0 ,3 ,9 },
			{ 1 ,3 ,9 ,5 ,4 ,0 ,6 ,2 ,0 },
			{ 8 ,0 ,6 ,0 ,9 ,7 ,0 ,1 ,5 },
			{ 0 ,1 ,7 ,0 ,8 ,6 ,5 ,0 ,3 },
			{ 6 ,8 ,3 ,1 ,5 ,4 ,0 ,9 ,2 },
			{ 4 ,0,2 ,7 ,3 ,0 ,1 ,8 , 0}
			};
			Sudoku s;
			for (int i = 0; i<9; i++)
				for (int j = 0; j < 9; j++)
				{
					s.arry[i][j] = true_arry1[i][j];
					int Gindex = i / 3 * 3 + j / 3 + 1;
					if (s.arry[i][j])
					{
						s.IfRows[i][s.arry[i][j]] = 1;
						s.IfCols[j][s.arry[i][j]] = 1;
						s.grid[Gindex][s.arry[i][j]] = 1;
					}
					else
					{

						s.index[s.count][0] = i;
						s.index[s.count][1] = j;
						s.count++;
					}
				}
			s.Solv(0);
			Assert::IsTrue(s.Check() == 0);


		}
		TEST_METHOD(Test_GetFile)
		{

			Sudoku s;
			
			FILE *Read1;
			fopen_s(&Read1, "GetFile.txt", "r");
			if (Read1 == NULL)
				return;
			s.GetFile(Read1);
			fclose(Read1);
			FILE *Read2;
			fopen_s(&Read2, "GetFile.txt", "r");
			if (Read2 == NULL)
				return;
			char buffer[1024];
			for (int i = 0; i < 9; i++)
			{
				if (fgets(buffer, 1024, Read2) == NULL)
					break;
				for (int j = 0; j < 9; j++) {
					int temp = buffer[j * 2] - '0';
					Assert::IsTrue(temp == s.arry[i][j]);
				}
			}
			fclose(Read2);


		}
	};
	TEST_CLASS(big_bang_Test)
	{
	public:
		TEST_METHOD(Test_CreateSudoku)
		{

			Sudoku temp;
			int list[10] = { 9,8,7,6,5,4,3,2,1 };
			char wfile[1000] = { 0 };
			long long len = 0;
			temp.GetBase(list);
			temp.Create();
			temp.colExchange(2, 3);
			temp.rowExchange(4, 5);
			temp.GetArry(wfile, len);
			char truewfile[1000] = { "9 8 6 7 5 4 3 2 1\n6 5 3 4 2 1 9 8 7\n3 2 9 1 8 7 6 5 4\n8 9 7 6 4 5 2 1 3\n2 1 8 3 9 6 7 4 5\n7 4 2 5 1 3 8 9 6\n5 7 4 9 6 8 1 3 2\n4 6 1 8 3 2 5 7 9\n1 3 5 2 7 9 4 6 8" };
			Assert::IsTrue(strcmp(wfile,truewfile)==0);
		}
		TEST_METHOD(Test_SolvSudoku)
		{

			FILE *Read, *Write;
			fopen_s(&Read, "sudoku2.txt", "r");
			fopen_s(&Write, "sudoku1.txt", "w");
			if (Write == NULL||Read==NULL)
				return;
			Sudoku temp;
			temp.GetFile(Read);
			temp.Solv(0);
			temp.FillFile(Write);
			fclose(Write);
			fclose(Read);
			fopen_s(&Write, "sudoku1.txt", "w");
			if (Write == NULL)
				return;
			temp.GetFile(Write);
			Assert::IsTrue(temp.Check()==0);
			fclose(Write);

		}
	};
}
