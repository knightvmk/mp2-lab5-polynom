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
	system("title Консоль работы с полиномами трёх переменных");
	TList<TPolinom> list;
	//Menu:
	short int x = 0, case1;
	while (x != 4)
	{
		x = 0;
		system("cls");
		printf("***************************************************************\n        Меню\n\n");
		printf("1. Создать полином\n");
		printf("2. Список полиномов\n");
		printf("3. Работать с полиномами\n");
		printf("4. Выход\n ");
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
					printf("***************************************************************\n        Создание полинома\n\n");
					printf("1. Весь полином вводом строки\n");
					printf("2. По очереди вводом мономов\n");
					printf("3. Назад\n ");
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
								printf("\n Правило:\n Каждый моном начинается строго с константы,\n затем следует перменная X и её степень числом,");
								printf("\n затем следует так же Y и Z соответственно.\n Следующий моном должен иметь аналогичный вид.");
								printf("\n Полином заканчивается строго числом - степенью переменной Z последнего монома.\n ");
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
									printf("\nЧуть не упал!\n Необходимо повторить корректный ввод!\n");
									system("pause");
								}
							}
							printf("\n Полином создан\n ");
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
								printf("\n Правило:\n Каждый моном начинается строго с константы,\n затем следует перменная X и её степень числом,");
								printf("\n затем следует так же Y и Z соответственно.\n Следующий моном должен иметь аналогичный вид.");
								printf("\n Моном заканчивается строго числом - степенью переменной Z. Максимальное число мономов - [ %i ]", MAX_MON);
								printf("\n\n Сколько мономов вы хотите ввести?\n ");
								while (much<1 || much>MAX_MON)
									scanf("%i", &much);
								printf(" мономов\n");
								string exp, mon;
								for (register int i = 0; i < much; i++)
								{
									printf("\n Введите %i-ый моном:\n ", i + 1);
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
									printf("\nЧуть не упал!\n Необходимо повторить корректный ввод!\n");
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
			printf("***************************************************************\n        Ваши полиномы\n\n");
			if (list.GetLen() < 1)
			{
				printf("\n У вас ещё нет полиномов!\n");
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
			printf("***************************************************************\n        Ваши полиномы\n\n");
			if (list.GetLen() < 1)
			{
				printf("\n У вас ещё нет полиномов!\n");
				system("pause");
				break;
			}
			for (register int i = 0; i < list.GetLen(); i++)
			{
				cout << i + 1 << ": " << list.GetVal(i).ToString() << endl;
			}
			Sleep(800);
			printf("\n\n***************************************************************\n        Операции над полиномами\n\n");
			printf(" 1. Сложение\n 2. Вычитание\n 3. Умножение\n 4. Умножение на число\n 5. Вычисление в точке\n\n");
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
					printf("\n У вас ещё двух полиномов!\n");
					system("pause");
					break;
				}
				int pol1 = 0, pol2 = 0;
				printf("\n\n Операции будут выполнены в порядке выбора очереди полиномов, будьте внимательны!\n ");
				printf("\n\n Выберете 1-ый полином: \n");
				while (pol1<1 || pol1> list.GetLen())
					scanf("%i", &pol1);
				polynom_1 = list.GetVal(pol1 - 1);
				printf("\n\n Выберете 2-ый полином: \n");
				while (pol2<1 || pol2> list.GetLen())
					scanf("%i", &pol2);
				polynom_2 = list.GetVal(pol2 - 1);
				system("cls");
				printf("***************************************************************\n        Выбранные полиномы\n\n");
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
						printf("\nОшибка!\n");
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
						printf("\nОшибка!\n");
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
						printf("\nОшибка! Степень переменной превысила 9\n");
						system("pause");
					}
					break;
				}
				}
			}
			else if (choise == 4)
			{
				int pol1 = 0;
				printf("\n Выберете полином:\n ");
				while (pol1 < 1 || pol1>list.GetLen())
					scanf("%i", &pol1);
				work = list.GetVal(pol1 - 1);
				system("cls");
				printf("***************************************************************\n        Ваш полином\n\n");
				cout << work.ToString() << endl;
				printf("\n\n Введите значение:\n");
				scanf("%i", &a);
				try
				{
					res = work*a;
				}
				catch (...)
				{
					printf("\n\n Неизвестная ошибка!\n");
					system("pause");
				}
			}
			else
			{
				int pol1 = 0;
				printf("\n Выберете полином:\n ");
				while (pol1 < 1 || pol1>list.GetLen())
					scanf("%i", &pol1);
				work = list.GetVal(pol1 - 1);
				system("cls");
				printf("***************************************************************\n        Ваш полином\n\n");
				cout << work.ToString() << endl;
				printf("\n\n Введите по очереди координаты:\n");
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
					printf("\n Ошибка, вылет за пределы %0.lf", DBL_MAX);
					result = DBL_MAX;
				}
			}
			system("cls");
			printf("***************************************************************\n        Результаты\n\n");
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
				printf("\n\n Записать результат в конец таблицы? \n 0 - Нет, 1 - Да\n");
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
				printf("\n\n Сохранить итоговый полином в конец списка? 0 - Нет, 1 - Да\n ");
				int write = -1;
				while (write < 0 || write>1)
					scanf("%i", &write);
				if (write == 1) list.InsLast(res);
				else break;
				system("pause");
			}
			else
			{
				printf("\n Ваш полином: \n");
				cout << work.ToString() << endl;
				printf("\n\n Результат в точке ( %i , %i , %i ) = %0.lf\n\n", a, b, c, result);
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