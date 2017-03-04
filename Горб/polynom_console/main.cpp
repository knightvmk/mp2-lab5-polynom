#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "tlist.h"
#include "tpolinom.h"
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS_
#define scanf scanf_s
#define DBL_MAX          1.7976931348623158e+308

using namespace std;

int main(int argc, char **argv)
{
	system("mode con cols=90 lines=25");
	setlocale(LC_ALL, "Rus");
	system("color 3F");
	system("title ������� ������ � ���������� ��� ����������");
	TList<TPolinom> list;
	//Menu:
	short int x = 0, case1;
	while (x != 4)
	{
		x = 0;
		system("cls");
		printf("***************************************************************\n        ����\n\n");
		printf("1. ������� �������\n");
		printf("2. ������ ���������\n");
		printf("3. �������� � ����������\n");
		printf("4. �����\n ");
		scanf("%i", &x);
		switch (x)
		{
		case(1):
		{
			{
				case1 = 0;
				while (case1 < 1 || case1>4)
				{
					system("cls");
					printf("***************************************************************\n        �������� ��������\n\n");
					printf("1. ���� ������� ������ ������\n");
					printf("2. �� ������� ������ �������\n");
					printf("3. �����\n ");
					scanf("%i", &case1);
					switch (case1)
					{
					case(1):
					{
						{
							bool create(false);
							while (!create)
							{
								system("cls");
								printf("\n �������:\n ������ ����� ���������� ������ � ���������,\n ����� ������� ��������� X � � ������� ������,");
								printf("\n ����� ������� ��� �� Y � Z ��������������.\n ��������� ����� ������ ����� ����������� ���.");
								printf("\n ������� ������������� ������ ������ - �������� ���������� Z ���������� ������.\n ");
								string exp;
								cin >> exp;
								try
								{
									TPolinom A(exp);
									create = true;
									list.InsLast(A);
								}
								catch (...)
								{
									printf("\n���� �� ����!\n ���������� ��������� ���������� ����!\n");
									system("pause");
								}
							}
							printf("\n ������� ������\n ");
							system("pause");
						}

						break;
					}
					case(2):
					{
						{
							bool create(false);
							while (!create)
							{
								int much = 0;
								system("cls");
								printf("\n �������:\n ������ ����� ���������� ������ � ���������,\n ����� ������� ��������� X � � ������� ������,");
								printf("\n ����� ������� ��� �� Y � Z ��������������.\n ��������� ����� ������ ����� ����������� ���.");
								printf("\n ����� ������������� ������ ������ - �������� ���������� Z. ������������ ����� ������� - [ %i ]", MAX_MON);
								printf("\n\n ������� ������� �� ������ ������?\n ");
								while (much<1 || much>MAX_MON)
									scanf("%i", &much);
								printf(" �������\n");
								string exp, mon;
								for (register int i = 0; i < much; i++)
								{
									printf("\n ������� %i-�� �����:\n ", i + 1);
									cin >> mon;
									if (i != 0 && mon[0] != '-') mon.insert(mon.begin(), '+');
									exp += mon;
								}
								try
								{
									TPolinom A(exp);
									create = true;
									list.InsLast(A);
								}
								catch (...)
								{
									printf("\n���� �� ����!\n ���������� ��������� ���������� ����!\n");
									system("pause");
								}
							}
						}
						break;
					}
					case(3): break;
					}
				}
			}
			break;
		}
		case(2):
		{
			system("cls");
			printf("***************************************************************\n        ���� ��������\n\n");
			if (list.GetLen() < 1)
			{
				printf("\n � ��� ��� ��� ���������!\n");
				system("pause");
				break;
			}
			for (register int i = 0; i < list.GetLen(); i++)
			{
				cout << i + 1 << ": " << list.GetVal(i).ToString() << endl;
			}
			system("pause");
			break;
		}
		case(3):
		{
			system("cls");
			int a = 0, b = 0, c = 0;
			printf("***************************************************************\n        ���� ��������\n\n");
			if (list.GetLen() < 1)
			{
				printf("\n � ��� ��� ��� ���������!\n");
				system("pause");
				break;
			}
			for (register int i = 0; i < list.GetLen(); i++)
			{
				cout << i + 1 << ": " << list.GetVal(i).ToString() << endl;
			}
			Sleep(800);
			printf("\n\n***************************************************************\n        �������� ��� ����������\n\n");
			printf(" 1. ��������\n 2. ���������\n 3. ���������\n 4. ��������� �� �����\n 5. ���������� � �����\n\n");
			int choise = 0;
			while (choise < 1 || choise>5)
				scanf("%i", &choise);
			//block of varables:
			TPolinom work, polynom_1, polynom_2, res;
			double result = 0;
			//end block;
			if (choise != 4 && choise != 5)
			{
				if (list.GetLen() < 2)
				{
					printf("\n � ��� ��� ���� ���������!\n");
					system("pause");
					break;
				}
				int pol1 = 0, pol2 = 0;
				printf("\n\n �������� ����� ��������� � ������� ������ ������� ���������, ������ �����������!\n ");
				printf("\n\n �������� 1-�� �������: \n");
				while (pol1<1 || pol1> list.GetLen())
					scanf("%i", &pol1);
				polynom_1 = list.GetVal(pol1 - 1);
				printf("\n\n �������� 2-�� �������: \n");
				while (pol2<1 || pol2> list.GetLen())
					scanf("%i", &pol2);
				polynom_2 = list.GetVal(pol2 - 1);
				system("cls");
				printf("***************************************************************\n        ��������� ��������\n\n");
				cout << 1 << " : " << polynom_1.ToString() << endl;
				cout << 2 << " : " << polynom_2.ToString() << endl;
				//
				switch (choise)
				{
				case(1):
				{
					try
					{
						res = polynom_1 + polynom_2;
					}
					catch (...)
					{
						printf("\n������!\n");
						system("pause");
					}
					break;
				}
				case(2):
				{
					try
					{
						res = polynom_1 - polynom_2;
					}
					catch (...)
					{
						printf("\n������!\n");
						system("pause");
					}
					break;
				}
				case(3):
				{
					try
					{
						res = polynom_1 * polynom_2;
					}
					catch (...)
					{
						printf("\n������! ������� ���������� ��������� 9\n");
						system("pause");
					}
					break;
				}
				}
			}
			else if (choise == 4)
			{
				int pol1 = 0;
				printf("\n �������� �������:\n ");
				while (pol1 < 1 || pol1>list.GetLen())
					scanf("%i", &pol1);
				work = list.GetVal(pol1 - 1);
				system("cls");
				printf("***************************************************************\n        ��� �������\n\n");
				cout << work.ToString() << endl;
				printf("\n\n ������� ��������:\n");
				scanf("%i", &a);
				try
				{
					res = work*a;
				}
				catch (...)
				{
					printf("\n\n ����������� ������!\n");
					system("pause");
				}
			}
			else
			{
				int pol1 = 0;
				printf("\n �������� �������:\n ");
				while (pol1 < 1 || pol1>list.GetLen())
					scanf("%i", &pol1);
				work = list.GetVal(pol1 - 1);
				system("cls");
				printf("***************************************************************\n        ��� �������\n\n");
				cout << work.ToString() << endl;
				printf("\n\n ������� �� ������� ����������:\n");
				printf("\n [ X ] = \n");
				scanf("%i", &a);
				printf("\n [ Y ] = \n");
				scanf("%i", &b);
				printf("\n [ Z ] = \n");
				scanf("%i", &c);
				try
				{
					result = work.Calculate(a, b, c);
				}
				catch (...)
				{
					printf("\n ������, ����� �� ������� %0.lf", DBL_MAX);
					result = DBL_MAX;
				}
			}
			system("cls");
			printf("***************************************************************\n        ����������\n\n");
			if (choise != 4 && choise != 5)
			{
				cout << 1 << " : " << polynom_1.ToString() << endl;
				switch (choise) {
				case(1):
				{
					printf(" +\n");
					break;
				}
				case(2):
				{
					printf(" -\n");
					break;
				}
				case(3):
				{
					printf(" *\n");
					break;
				}
				}
				cout << 2 << " : " << polynom_2.ToString() << endl;
				cout << 3 << " = " << res.ToString() << endl;
				printf("\n\n �������� ��������� � ����� �������? \n 0 - ���, 1 - ��\n");
				int write = -1;
				while (write < 0 || write>1)
					scanf("%i", &write);
				if (write == 1) list.InsLast(res);
				else break;
			}
			else if (choise == 4)
			{
				printf("\n");
				cout << "  ( " << work.ToString() << " ) ";
				printf(" * %i\ = ", a);
				cout << res.ToString() << endl;
				Sleep(600);
				printf("\n\n ��������� �������� ������� � ����� ������? 0 - ���, 1 - ��\n ");
				int write = -1;
				while (write < 0 || write>1)
					scanf("%i", &write);
				if (write == 1) list.InsLast(res);
				else break;
				system("pause");
			}
			else
			{
				printf("\n ��� �������: \n");
				cout << work.ToString() << endl;
				printf("\n\n ��������� � ����� ( %i , %i , %i ) = %0.lf\n\n", a, b, c, result);
				system("pause");
			}
			// to exit:
			break;
		}
		case(4):
		{
			exit(0);
		}
		}
	}
	return 0;
}