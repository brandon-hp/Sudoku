#include"sudoku.h"
int Base[9] = { HEAD,2,3,4,5,6,7,8,1 };
//��ǰ������������
long long curnum = 0;
//�������������վ�
char wfile[200000000] = { 0 };
long long stringNum = 0;
//�Ի������н�������Ȼ����������
//����list1-9ȫ���У�k��m���е��±굱k=m����һ��ȫ����
//numָ���������վ�����
void Perm(int list[], int k, int m, long long num) {
	//�����������ﵽָ�����˳�
	if (curnum >= num)
		return;
	//���ҵ�һ��ȫ����
	if (k == m) {
		Sudoku temp;
		//�����ȫ��������DFS��������
		temp.GetBase(list);
		//��������
		temp.Create();
		//���У�2��*3��*3!)^2�����н���
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
								//��ȡ����д��wfile��
								temp.GetArry(wfile, stringNum);
								//�ж����������Ƿ���
								curnum++;
								if (curnum >= num)
									return;
								//��һ��
								wfile[stringNum++] = '\n';
								wfile[stringNum++] = '\n';
								//����Ϊ���н���
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



	}//ʹ����������ȫ����
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
//����Ϊcmdָ�����
long long check_argument(int argc, char** argv)
{
	//�ж���������Ƿ���3��
	if (argc != 3)
	{
		cout << "������������ȷ��" << endl;
		exit(-1);
	}//�ж��Ƿ���-c����
	else if (!strcmp("-c", argv[1]))
	{
		//-c���������Ƿ񳬳���Χ
		long long num = atoll(argv[2]);
		if (num > 1000000 || num <= 0)
		{
			cout << "-c���� û��������������������������!" << endl;
			exit(-1);
		}
		//���������վ���
		return num;

	}//�ж��Ƿ���-s������Ƿ���0
	else if (!strcmp("-s", argv[1]))
	{
		return 0;
	}
	else//����ָ���
	{
		cout << "����û�иĹ���!" << endl;
		exit(-1);
	}
}
//����num������,����Ϊ������
void CreateSudokuN(long long num)
{
	curnum = 0;
	FILE* Write;
	//��Ŀ���ļ�
	fopen_s(&Write, TARGET, "w");
	if (Write == NULL)
	{
		cout << "�����ļ�����" << endl;
		return;
	}
	//�����������
	for (int i = 1; i < 9; i++)
	{
		swap(Base[i], Base[rand() % 8 + 1]);
	}
	//�Ի������н���ȫ����
	Perm(Base, 1, 8, num);
	//��������д���ļ�
	fprintf(Write, "%s", wfile);
	fclose(Write);
}
//������������Ϊ�оִ��·��
void SolvSudokuN(char* path)
{

	FILE* Read, * Write;
	//�򿪲оִ���ļ���д���վֵ��ļ�
	fopen_s(&Read, path, "r");
	fopen_s(&Write, TARGET, "w");
	if (Write == NULL)
	{
		cout << "�����ļ�����" << endl;
		return;
	}
	if (Read == NULL)
	{
		cout << "��ȡ�ļ�����" << endl;
		return;
	}
	int flags = 0;
	//ѭ�����ļ��ж�ȡ�о֣�Ȼ��д���ļ�
	while (1)
	{
		Sudoku temp;
		//��ȡһ���о�
		if (temp.GetFile(Read))
			break;
		//��о�
		temp.Solv(0);
		if (flags == 0)
			flags = 1;
		else
			fprintf(Write, "\n\n");
		//д���վ�
		temp.FillFile(Write);

	}

	fclose(Write);
	fclose(Read);

}
