#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list.h"


void main()
{
	setlocale(LC_ALL, "RUS");
	puts(
		"\t************************************************************************************************************\n"
		"\t*                                              Социальная сеть                                             *\n"
		"\t* Работу выполнила: До Фыонг Тхао                                                                          *\n"
		"\t* Группа: бИСТ-231                                                                                         *\n"
		"\t* Руководитель: Минакова О.В.                                                                              *\n"
		"\t*                                                                                                          *\n"
		"\t************************************************************************************************************\n");
	base* main_bd;
	main_bd = (base*)malloc(sizeof(base) * 100);
	int flag = 0;
	while (flag != 8)
	{
		puts("Выберите действие:\n" "1 - Загрузить записи из файла\n" "2 - Вывести записи на экран\n" "3 - Добавить запись\n" "4 - Удалить запись\n" "5 - Найти запись\n" "6 - Сортировка\n" "7 - Сохранение\n" "8 - Закрытие\n" "Ваш выбор: ");
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
		{
			printfile(main_bd, scan(main_bd, 100));
			puts("\n");
			break;
		}
		case 2:
		{
			print_data(main_bd, scan(main_bd, 100));
			puts("\n");
			break;
		}
		case 3:
		{
			record(main_bd);
			puts("-----------------------------------------------------------------\n"
				"|    Имя     |  Возраст  |    Город   |   Хобби    |    Дата    |\n"
				"-----------------------------------------------------------------");
			print_str(main_bd, scan(main_bd, 100) - 1);
			puts("\n");
			flag = 0;
			while (flag != 2)
			{
				puts("Вы хотите добавить ещё запись?\n"
					"1 - Да\n"
					"2 - Нет\n"
					"Ваш выбор: ");
				scanf("%d", &flag);
				if (flag == 1)
				{
					record(main_bd);
					puts("-----------------------------------------------------------------\n"
						"|    Имя     |  Возраст  |    Город   |   Хобби    |    Дата    |\n"
						"-----------------------------------------------------------------");
					print_str(main_bd, scan(main_bd, 100) - 1);
					puts("\n");
				}
			}
			break;
		}
		case 4:
		{
			puts("Введите номер записи для удаления:\n");
			int number = 0;
			scanf("%d", &number);
			main_bd = delete_d(main_bd, scan(main_bd, 100), number);
			print_data(main_bd, scan(main_bd, 100));
			puts("\n");
			break;
		}
		case 5:
		{
			int flag2 = 0;
			puts("Критерий поиска:\n"
				"1 - Возраст и город\n"
				"2 - Возраст\n"
				"3 - Город\n"
				"Ваш выбор: ");
			scanf("%d", &flag2);
			switch (flag2)
			{
			case 1:
			{
				int poisk1;
				char poisk2[20];
				puts("Введите возраст: ");
				scanf("%d", &poisk1);
				puts("Введите город: ");
				scanf("%s", poisk2);
				base* c = find_1(main_bd, scan(main_bd, 100), poisk2, poisk1);
				print_data(c, scan(c, 100));
				break;
			}
			case 2:
			{
				puts("Возраст: ");
				int poisk;
				scanf("%d", &poisk);
				base* c = find_2(main_bd, scan(main_bd, 100), poisk);
				print_data(c, scan(c, 100));
				break;
			}
			case 3:
			{
				puts("Введите город: ");
				char poisk[20];
				scanf("%s", poisk);
				base* c = find_3(main_bd, scan(main_bd, 100), poisk);
				print_data(c, scan(c, 100));
				break;
			}
			}
			puts("\n");
			break;
		}

		case 6:
		{
			base* c = sort(main_bd, scan(main_bd, 100));
			print_data(c, scan(c, 100));
			puts("\n");
			break;
		}

		case 7:
		{
			puts("Название нового файла .txt:");
			char new_name[20];
			scanf("%s", new_name);
			writefile(new_name, main_bd, scan(main_bd, 100));
			puts("\n");
			break;
		}

		};
	}
}
void print_data(base* b, int num)
{
	puts("-------------------------------------------------------------------------\n"
		"| Номер |    Имя     |  Возраст  |    Город   |   Хобби    |    Дата    |\n"
		"-------------------------------------------------------------------------");
	for (int i = 0; i < num; i++)
	{
		printf("|  %3d  ", i + 1);
		print_str(b, i);
	}
	puts("-------------------------------------------------------------------------\n");
}
void print_str(base* b, int i)
{
	printf("| %10s | %9d | %10s | %10s | %2d.%02d.%4d |\n",
		(b + i)->name, (b + i)->age, (b + i)->city, (b + i)->hobbi, (b + i)->registr.day, (b + i)->registr.mes, (b + i)->registr.year);
}
int scan(base* b, int size)
{
	int n = 0;
	for (int i = 0; i < size; i++)
		if ((b + i)->age > 0)
		{
			n++;
		}
	return n;
}
void record(base* b)
{
	base c;
	puts("Имя:");
	scanf("%s", c.name);
	puts("Возраст:");
	scanf("%d", &c.age);
	puts("Город:");
	scanf("%s", c.city);
	puts("Хобби:");
	scanf("%s", c.hobbi);
	puts("Дата регистрации (пример 30.01.2015):");
	scanf("%d.%d.%d", &c.registr.day, &c.registr.mes, &c.registr.year);
	*(b + scan(b, 100)) = c;
}

base* find_1(base* b, int num, char* str1, int str2)
{
	base* main1_bd;
	main1_bd = (base*)malloc(sizeof(base) * 100);
	int n = 0;
	for (int i = 0; i < num; i++)
	{
		if (strcmp((b + i)->city, str1) == 0 && (b + i)->age == str2)
		{
			*(main1_bd + n) = *(b + i);
			n += 1;
		}
	}
	return main1_bd;
}
base* find_2(base* b, int num, int str)
{
	base* main2_bd;
	main2_bd = (base*)malloc(sizeof(base) * 100);
	int n = 0;
	for (int i = 0; i < num; i++)
	{
		if ((b + i)->age == str)
		{
			*(main2_bd + n) = *(b + i);
			n += 1;
		}
	}
	return main2_bd;
}
base* find_3(base* b, int num, char* str)
{
	base* main3_bd;
	main3_bd = (base*)malloc(sizeof(base) * 100);
	int n = 0;
	for (int i = 0; i < num; i++)
	{
		if (strcmp((b + i)->city, str) == 0)
		{
			*(main3_bd + n) = *(b + i);
			n += 1;
		}
	}
	return main3_bd;
}

base* sort(base* b, int num)
{
	base* main4_bd;
	main4_bd = b;
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j > 0 && ((main4_bd + j - 1)->registr.day + (main4_bd + j - 1)->registr.mes * 30 + (main4_bd + j - 1)->registr.year * 12 * 30) < ((main4_bd + j)->registr.day + (main4_bd + j)->registr.mes * 30 + (main4_bd + j)->registr.year * 12 * 30); j--)
		{
			base c;
			c = *(main4_bd + j);
			*(main4_bd + j) = *(main4_bd + j - 1);
			*(main4_bd + j - 1) = c;
		}
	}
	return main4_bd;
}
void printfile(base* b, int num)
{
	FILE* in;
	puts("Введите название вашего файла .txt:");
	char file_name[20];
	scanf("%s", file_name);
	int i = num;
	in = fopen(file_name, "r");
	while (!feof(in))
	{
		fscanf(in, "%s %d %s %s %d.%d.%d\n", (b + i)->name, &(b + i)->age, (b + i)->city, (b + i)->hobbi, &(b + i)->registr.day, &(b + i)->registr.mes, &(b + i)->registr.year);
		i++;
	}

	fclose(in);
}


base* delete_d(base* b, int num, int n)
{
	base* base5;
	base5 = (base*)malloc(sizeof(base) * 100);
	int index = n - 1;
	for (int i = 0; i < index; i++)
	{
		*(base5 + i) = *(b + i);
	}
	for (int i = index; i < num - 1; i++)
	{
		*(base5 + index) = *(b + index + 1);
		index++;
	}

	return base5;
}
void writefile(char* fname, base* b, int size)
{
	FILE* out;
	if ((out = fopen(fname, "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	for (int i = 0; i < size; i++)
		fprintf(out, "%s %d %s %s %d.%d.%d\n", (b + i)->name, (b + i)->age, (b + i)->city, (b + i)->hobbi, (b + i)->registr.day, (b + i)->registr.mes, (b + i)->registr.year);
	fclose(out);
}