#include"sudoku.h"
void Sudoku::Clear()
{
	srand((unsigned)time(NULL));
	cols = rows = SCALE;
	count = 0;
	memset(IfRows, 0, sizeof(IfRows));
	memset(IfCols, 0, sizeof(IfCols));
	memset(grid, 0, sizeof(grid));
	memset(Tgrid, 0, sizeof(Tgrid));
	memset(index, 0, sizeof(index));
	memset(TempArry, 0, sizeof(TempArry));
	IsOver = false;
	memset(arry, 0, sizeof(0));
}
void Sudoku::Create()
{

	dfs(0, 0);
}
void Sudoku::dfs(int currow, int curcol)
{
	if (IsOver)  return;
	if (currow == 9 && curcol == 0)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				arry[i][j] = TempArry[i][j];
				
			}
		}
		IsOver = true;
		return;
	}
	if (currow == 9) {
		return;
	}

	int Gindex = currow / 3 * 3 + curcol / 3 + 1;
	for (int i = 0; i < 9; i++)
	{

		if (!IfRows[currow][base[i]] && !IfCols[curcol][base[i]] && !grid[Gindex][base[i]])
		{
			TempArry[currow][curcol] = base[i];
			IfRows[currow][base[i]] = true;
			IfCols[curcol][base[i]] = true;
			grid[Gindex][base[i]] = true;
			if (curcol == 8)
				dfs(currow + 1, 0);
			else
				dfs(currow, curcol + 1);

			IfRows[currow][base[i]] = false;
			IfCols[curcol][base[i]] = false;
			grid[Gindex][base[i]] = false;
		}
	}
	return;
}
int Sudoku::Solv(int n)
{

	if (n >= count) {
		return 1;
	}
	for (int j = 1; j <= 9; j++) {
		int Gindex = index[n][0] / 3 * 3 + index[n][1] / 3 + 1;
		if (!IfRows[index[n][0]][j] && !IfCols[index[n][1]][j] && !grid[Gindex][j]) {
			IfRows[index[n][0]][j] = true;
			IfCols[index[n][1]][j] = true;
			grid[Gindex][j] = true;
			arry[index[n][0]][index[n][1]] = j;
			if (Solv(n + 1))return 1;
			IfRows[index[n][0]][j] = false;
			IfCols[index[n][1]][j] = false;
			grid[Gindex][j] = false;
		}
	}
	return 0;

}
void Sudoku::rowExchange(const int& r1, const int& r2) {

	for (int i = 0; i < 9; i++) {
		int t = arry[r1][i];
		arry[r1][i] = arry[r2][i];
		arry[r2][i] = t;
	}
}
void Sudoku::GetArry(char*w,long long &stringNum) {

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			w[stringNum++] = (arry[i][j]+'0');
			if (j == 8)
				w[stringNum++] = '\n';
			else
				w[stringNum++]= ' ';
		}
}
}
void Sudoku::GetBase(int *list)
{
	for (int i = 0; i < 9; i++)
	{
		base[i] = list[i];
	}

}
void Sudoku::FillFile(FILE* w)
{
	for (int i = 0; i < rows; i++)
	{
		fprintf(w, "%d %d %d %d %d %d %d %d %d\n", arry[i][0], arry[i][1], arry[i][2], arry[i][3], arry[i][4], arry[i][5], arry[i][6], arry[i][7], arry[i][8]);
	}
	fprintf(w, "\n");
}
int Sudoku::GetFile(FILE *r)
{
	memset(index, 0, sizeof(index));
	char buffer[1024];
	for (int i = 0; i < 9; i++)
	{
		if (fgets(buffer, 1024, r) == NULL)
			return 1;
		for (int j = 0; j < 9; j++) {
			arry[i][j] = buffer[j * 2] - '0';
			int Gindex = i / 3 * 3 + j / 3 + 1;
			if (arry[i][j])
			{
				IfRows[i][arry[i][j]] = 1;
				IfCols[j][arry[i][j]] = 1;
				grid[Gindex][arry[i][j]] = 1;
			}
			else
			{

				index[count][0] = i;
				index[count][1] = j;
				count++;
			}

		}
	}
	fgets(buffer, 1024, r);
	return 0;
}
void Sudoku::GeneratingEndgame()
{
	int brry[100];
	for (int i = 0; i<9; i++)
		for (int j = 0; j < 9; j++)
		{
			int Gindex = i / 3 * 3 + j / 3 + 1;
			Tgrid[Gindex][0]++;
			int index1 = Tgrid[Gindex][0];
			Tgrid[Gindex][index1] = i * 9 + j;
		}
	for (int i = 1; i <= 9; i++)
	{
		int temp = rand() % 9 + 1;
		swap(Tgrid[i][9], Tgrid[i][temp]);
		temp = rand() % 8 + 1;
		swap(Tgrid[i][8], Tgrid[i][temp]);
		for (int j = 0; j < 7; j++)
			brry[i * 7 - 7 + j] = Tgrid[i][j + 1];
	}
	int num = rand() % 31 + 12;
	for (int i = 0; i <= num; i++)
	{
		int temp = rand() % (63 - i);
		swap(brry[temp], brry[63 - i - 1]);
	}

	sort(brry, brry + 63 - num);
	cout << num << endl;
	for (int i = 0; i < 63 - num; i++)
		cout << brry[i] << ends;

	int temp = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			if (temp == 63 - num)
				arry[i][j] = 0;
			else if (brry[temp] == i * 9 + j)
			{
				temp++;
			}
			else
			{
				arry[i][j] = 0;
			}


		}
	}


}
int Sudoku::Check()
{
	memset(IfRows, 0, sizeof(IfRows));
	memset(IfCols, 0, sizeof(IfCols));
	memset(grid, 0, sizeof(grid));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int temp = arry[i][j];
			if (temp == 0)
				return 2;
			int Gindex = i / 3 * 3 + j / 3 + 1;
			if (!IfRows[i][temp] && !IfCols[j][temp] && !grid[Gindex][temp])
			{
				IfRows[i][temp] = true;
				IfCols[j][temp] = true;
				grid[Gindex][temp] = true;

			}
			else
				return 1;

		}


	}
	return 0;


}
