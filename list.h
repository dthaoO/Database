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


int scan(base* b, int size); // ���������� ���������� �����
void print_data(base* b, int num); // ������� ��� ������
void printfile(base* b, int num); // ��������� ������ �� �����
void writefile(char* fname, base* bike, int size); // ���������� ������ � ����
void print_str(base* b, int i);// ������� ������ � �������
void record(base* b); // ��������� ������
base* delete_d(base* b, int num, int n);// ������� ������ �� ������
base* find_1(base* b, int num, char* str1, int str2);// �����
base* find_2(base* b, int num, int str);
base* find_3(base* b, int num, char* str);
base* sort(base* b, int num);// ����������


#endif /* _LIST_H */
