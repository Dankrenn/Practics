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
	printf("Точка %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w) {
	float dist = sqrt(pow((w.x - z.x),2) + pow((w.y - z.x),2));
	printf("Расстояние между точками равно: = %f", dist);
}

void average(Point a, Point b) {
	Point c;
	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;
	printf("Средняя точка между 2 другими равна: (%.1f %.1f)", c.x, c.y);
}

void which_quarter(Point z) {
	int quarter = 0;
	if (z.x > 0 && z.y > 0) quarter = 1;
	else if (z.x < 0 && z.y>0) quarter = 2;
	else if (z.x < 0 && z.y < 0) quarter = 3;
	else if (z.x > 0 && z.y < 0) quarter = 4;
	else quarter = 0;
	printf("Точка  %c находится в %d четверти.", z.name, quarter);
}


int Task1() {
	printf("Задание 1.  Напишите программу, работающую с точками на плоскости\n");
	Point b, a;
	a = (Point){ 1.f,3.f,'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	printf("Реализуйте отображение точки в отдельной функции\n");
	put_point(a);
	printf("\n");
	put_point(b);
	printf("\n");
	printf("Добавьте функцию вычисления  декартова расстояния между двумя точками.\n");
	dist(a, b);
	printf("\n");
	printf("Добавьте функцию получения новой точки - середины отрезка между двумя точками. Реализуйте обращение к ней из функции main() для вычисления средней из двух  введенных пользователем точек. \n");
	average(a, b);
	printf("\n");
	printf("Напишите функцию для определения к какой координатной четверти относится точка.\n");
	which_quarter(a);

	printf("ЗАДАНИЕ 1 ЗАВЕРШЕНО\n");
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
	printf("Задание 2. Напишите программу, которая выводит на экран текущее время.\n");
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
	sprintf(array,"Время в Москве %02d:%02d:%02d ",
		mytime->tm_hour, 
		mytime->tm_min, 
		mytime->tm_sec);
	center(array);
	printf("Добавьте вывод «сегодня N-й день года»\n");

	int day = mytime->tm_yday;
	sprintf(array, "Сегодня %d день  года ", day);
	center(array);
	for (int i = 0; i < 80; i++)
	{
		printf("*");
	}
	printf("ЗАДАНИЕ 2 ЗАВЕРШЕНО\n");
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
		printf("Фамилия сотрудника: ");
		scanf("%s", worker-> Surname);

		printf("Должность сотрудника: ");
		scanf("%s", worker -> Post);

		printf("Дата подписания контракта: ");
		scanf("%s", &worker -> DataContract);

		printf("Срок действия контракта: ");
		scanf("%d", &worker -> DataDuration);

		printf("Оклад: ");
		scanf("%f", &worker -> Salary);
		printf("\n");
	return worker;
}

void print_worker(worker_t* worker) {
	printf("Фамилия сотрудника: %s\n", worker -> Surname);
	printf("Должность сотрудника: %s\n", worker->Post);
	printf("Дата подписания контракта: %s\n", worker->DataContract);
	printf("Срок действия контракта: %d\n", worker->DataDuration);
	printf("Оклад: %f\n", worker->Salary);
	printf("\n");
}

int HomeWork() {
	printf("ДЗ.Реализуйте создание структуры «Работник»:, заполнение полей и вывод на экран. \n");
	struct Worker worker1;
	fill_worker(&worker1);
	printf("\n");
	print_worker(&worker1);
	printf("ДЗ ЗАВЕРШЕНО\n");
	printf("\n");
	return 0;
}