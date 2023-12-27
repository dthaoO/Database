#ifndef _LIST_H
#define _LIST_H

typedef struct
{
	int day;
	int mes;
	int year;
} data;

typedef struct
{
	char name[10];
	int age;
	char city[10];
	char hobbi[10];
	data registr;
} base;


int scan(base* b, int size); // возвращает количество строк
void print_data(base* b, int num); // выводит все записи
void printfile(base* b, int num); // считывает записи из файла
void writefile(char* fname, base* bike, int size); // записывает данные в файл
void print_str(base* b, int i);// выводит запись в консоль
void record(base* b); // добавляет запись
base* delete_d(base* b, int num, int n);// удаляет запись по номеру
base* find_1(base* b, int num, char* str1, int str2);// поиск
base* find_2(base* b, int num, int str);
base* find_3(base* b, int num, char* str);
base* sort(base* b, int num);// сортировка


#endif /* _LIST_H */
