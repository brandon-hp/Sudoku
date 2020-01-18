#include"sudoku.h"
int Base[9] = { HEAD,2,3,4,5,6,7,8,1 };
//当前生成数独数量
long long curnum = 0;
//保存所有数独终局
char wfile[200000000] = { 0 };
long long stringNum = 0;
//对基础序列进行排列然后生成数独
//参数list1-9全排列，k，m序列的下标当k=m生成一个全排列
//num指定的数独终局数量
void Perm(int list[], int k, int m, long long num) {
	//若数独数量达到指标则退出
	if (curnum >= num)
		return;
	//若找到一个全排列
	if (k == m) {
		Sudoku temp;
		//以这个全排列生成DFS基础数独
		temp.GetBase(list);
		//生成数独
		temp.Create();
		//进行（2！*3！*3!)^2的行列交换
		for (int Ri = 0; Ri < 2; Ri++)
		{
			for (int Rj = 0; Rj < 6; Rj++)
			{
				for (int Rk = 0; Rk < 6; Rk++)
				{
					for (int Ci = 0; Ci < 2; Ci++)
					{
						for (int Cj = 0; Cj < 6; Cj++)
						{
							for (int Ck = 0; Ck < 6; Ck++)
							{
								//获取数独写入wfile中
								temp.GetArry(wfile, stringNum);
								//判断数独数量是否达标
								curnum++;
								if (curnum >= num)
									return;
								//空一行
								wfile[stringNum++] = '\n';
								wfile[stringNum++] = '\n';
								//以下为行列交互
								switch (Ck % 2)
								{
								case 0:temp.colExchange(7, 8); break;
								case 1:temp.colExchange(6, 7); break;
								default:break;
								}
							}
							switch (Cj % 2)
							{
							case 0:temp.colExchange(4, 5); break;
							case 1:temp.colExchange(3, 4); break;
							default:break;
							}
						}
						temp.colExchange(1, 2);
					}
					switch (Rk % 2)
					{
					case 0:temp.rowExchange(7, 8); break;
					case 1:temp.rowExchange(6, 7); break;
					default:break;
					}
				}


				switch (Rj % 2)
				{
				case 0:temp.rowExchange(4, 5); break;
				case 1:temp.rowExchange(3, 4); break;
				default:break;
				}
			}
			temp.rowExchange(1, 2);
		}



	}//使用搜索进行全排列
	else {
		for (int i = k; i <= m; i++) {

			swap(list[i], list[k]);
			Perm(list, k + 1, m, num);
			if (curnum >= num)
				return;
			swap(list[i], list[k]);
		}
	}

}
//参数为cmd指令参数
long long check_argument(int argc, char** argv)
{
	//判断命令参数是否是3个
	if (argc != 3)
	{
		cout << "参数数量不正确！" << endl;
		exit(-1);
	}//判断是否是-c命令
	else if (!strcmp("-c", argv[1]))
	{
		//-c命令数量是否超出范围
		long long num = atoll(argv[2]);
		if (num > 1000000 || num <= 0)
		{
			cout << "-c功能 没有输入数独数量或者数量过大!" << endl;
			exit(-1);
		}
		//返回生成终局数
		return num;

	}//判断是否是-s命令，若是返回0
	else if (!strcmp("-s", argv[1]))
	{
		return 0;
	}
	else//其他指令报错
	{
		cout << "程序没有改功能!" << endl;
		exit(-1);
	}
}
//生成num个数独,参数为数独数
void CreateSudokuN(long long num)
{
	curnum = 0;
	FILE* Write;
	//打开目标文件
	fopen_s(&Write, TARGET, "w");
	if (Write == NULL)
	{
		cout << "创建文件错误" << endl;
		return;
	}
	//随机基础数列
	for (int i = 1; i < 9; i++)
	{
		swap(Base[i], Base[rand() % 8 + 1]);
	}
	//对基础数列进行全排列
	Perm(Base, 1, 8, num);
	//将数独集写入文件
	fprintf(Write, "%s", wfile);
	fclose(Write);
}
//解数独，参数为残局存放路径
void SolvSudokuN(char* path)
{

	FILE* Read, * Write;
	//打开残局存放文件和写入终局的文件
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
	int flags = 0;
	//循环存文件中读取残局，然后写入文件
	while (1)
	{
		Sudoku temp;
		//读取一个残局
		if (temp.GetFile(Read))
			break;
		//解残局
		temp.Solv(0);
		if (flags == 0)
			flags = 1;
		else
			fprintf(Write, "\n\n");
		//写入终局
		temp.FillFile(Write);

	}

	fclose(Write);
	fclose(Read);

}
