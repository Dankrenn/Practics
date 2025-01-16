#include <stdio.h>
#include <locale.h>
#include<math.h>
#include<time.h>
#include <string.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	Task1();
	Task2();
	HomeWork();
	return 0;
}

struct point {
	float x;
	float y;
	char name;
};
typedef struct point Point;

void put_point(Point z) {
	printf("����� %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w) {
	float dist = sqrt(pow((w.x - z.x),2) + pow((w.y - z.x),2));
	printf("���������� ����� ������� �����: = %f", dist);
}

void average(Point a, Point b) {
	Point c;
	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;
	printf("������� ����� ����� 2 ������� �����: (%.1f %.1f)", c.x, c.y);
}

void which_quarter(Point z) {
	int quarter = 0;
	if (z.x > 0 && z.y > 0) quarter = 1;
	else if (z.x < 0 && z.y>0) quarter = 2;
	else if (z.x < 0 && z.y < 0) quarter = 3;
	else if (z.x > 0 && z.y < 0) quarter = 4;
	else quarter = 0;
	printf("�����  %c ��������� � %d ��������.", z.name, quarter);
}


int Task1() {
	printf("������� 1.  �������� ���������, ���������� � ������� �� ���������\n");
	Point b, a;
	a = (Point){ 1.f,3.f,'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	printf("���������� ����������� ����� � ��������� �������\n");
	put_point(a);
	printf("\n");
	put_point(b);
	printf("\n");
	printf("�������� ������� ����������  ��������� ���������� ����� ����� �������.\n");
	dist(a, b);
	printf("\n");
	printf("�������� ������� ��������� ����� ����� - �������� ������� ����� ����� �������. ���������� ��������� � ��� �� ������� main() ��� ���������� ������� �� ����  ��������� ������������� �����. \n");
	average(a, b);
	printf("\n");
	printf("�������� ������� ��� ����������� � ����� ������������ �������� ��������� �����.\n");
	which_quarter(a);

	printf("������� 1 ���������\n");
	printf("\n");
	return 0;
}


void center(const char* message) {
	int length = strlen(message);
	int padding = (80 - length) / 2;
	for (int i = 0; i < padding; i++)
	{
		printf("*");
	}
	printf("%*s", length, message);
	for (int i = 0; i < padding; i++)
	{
		printf("*");
	}
	printf("\n");
}

int Task2() {
	printf("������� 2. �������� ���������, ������� ������� �� ����� ������� �����.\n");
	struct tm* mytime;
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	for (int i = 0; i < 80; i++)
	{
		printf("*");
	}
	printf("\n");
	char array[200];
	sprintf(array,"����� � ������ %02d:%02d:%02d ",
		mytime->tm_hour, 
		mytime->tm_min, 
		mytime->tm_sec);
	center(array);
	printf("�������� ����� �������� N-� ���� ����\n");

	int day = mytime->tm_yday;
	sprintf(array, "������� %d ����  ���� ", day);
	center(array);
	for (int i = 0; i < 80; i++)
	{
		printf("*");
	}
	printf("������� 2 ���������\n");
	printf("\n");
	return 0;
}




typedef struct Worker {
	char Surname[20];
	char Post[20];
	char DataContract[10];
	int DataDuration;
	float Salary;
} worker_t;

worker_t* fill_worker(worker_t* worker) {
		printf("������� ����������: ");
		scanf("%s", worker-> Surname);

		printf("��������� ����������: ");
		scanf("%s", worker -> Post);

		printf("���� ���������� ���������: ");
		scanf("%s", &worker -> DataContract);

		printf("���� �������� ���������: ");
		scanf("%d", &worker -> DataDuration);

		printf("�����: ");
		scanf("%f", &worker -> Salary);
		printf("\n");
	return worker;
}

void print_worker(worker_t* worker) {
	printf("������� ����������: %s\n", worker -> Surname);
	printf("��������� ����������: %s\n", worker->Post);
	printf("���� ���������� ���������: %s\n", worker->DataContract);
	printf("���� �������� ���������: %d\n", worker->DataDuration);
	printf("�����: %f\n", worker->Salary);
	printf("\n");
}

int HomeWork() {
	printf("��.���������� �������� ��������� ���������:, ���������� ����� � ����� �� �����. \n");
	struct Worker worker1;
	fill_worker(&worker1);
	printf("\n");
	print_worker(&worker1);
	printf("�� ���������\n");
	printf("\n");
	return 0;
}