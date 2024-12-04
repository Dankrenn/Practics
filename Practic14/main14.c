#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	Task1();
	//Task2();
	//Task3();
	HomeWork();
	return 0;
}


//-заполнение массива значени€ми(например, из функции зад.2 лаб.8)
void full_elements(double* ptr_array, int n) {
	printf("y = 1.8x^2 - sin10x интервал от 0.2 до 2.2\n");

	double z = 0;
	printf("¬ведите значение шага табул€ции: ");
	scanf_s("\n%lf", &z);
	double y[20];
	int i = 0;

	for (double x = 0.2; x <= 2.2; x += z, i++)
	{
		y[i] = 1.8 * pow(x, 2) - sin(10 * x);
	}
	for (int i = 0; i <= strlen(y); i++) {
		if (i < n) {
			ptr_array[i] = y[i];
			printf("%lf\n", ptr_array[i]);
		}
	}
}

//-печать элементов массива
void put_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%lf\n", ptr_array[i]);
	}
}

//-обработка элементов массива(см.инд.вариант  зад. 1.3 в работе 11)
void calc_elements(double* ptr_array, int n) {
	double A[100];
	for (int i = 0; i < n; i++)
	{
		double c;
		printf("a[%d] = ", i + 1);
		scanf_s("%lf", &c);
		A[i] = c;
	}
	for (int i = 0; i < n; i++)
	{
		double c = A[i];
		ptr_array[i] = pow(c, 2);
	}
	return 0;
}

void CalcNabor(double* ptr_array, int n) {
	for (int i = 0; i < n; i++)
	{
		double c;
		printf("a[%d] = ", i);
		scanf_s("%lf", &c);
		ptr_array[i] = c;
	}
}

int Task1() {
	double array[100];
	int size;
	printf("¬ведите размер массива > ");
	scanf_s("%d", &size);
	full_elements(array, size);
	printf("\n");
	put_elements(array, size);
	printf("\n");
	calc_elements(array, size);
	printf("\n");
	put_elements(array, size);
	return 0;
}


double sum_elements(double* ptr_array, int begin, int end) {
	double rez = 0;
	for (int i = begin; i <= end; i++) {
		rez += ptr_array[i];
	}
	return rez;
}

int find_element(double* ptr_array, int n, double element) {
	int rez = 0;
	for (int i = 0; i <= n; i++) {
		if (ptr_array[i] == element) {
			rez = i;
			return rez;
		}
		else {
			rez = -1;
		}
	}
	return rez;
}

int Task2() {
	//ƒобавьте функцию вычислени€ суммы элементов массива  
	// от индекса begin до индекса  end включительно :
	double array[100];
	int size;
	printf("¬ведите размер массива > ");
	scanf_s("%d", &size);
	CalcNabor(array, size);
	int start,end;
	printf("¬ведите начальный индекс массива  ");
	scanf_s("%d", &start);
	printf("¬ведите конечный индекс массива  ");
	scanf_s("%d", &end);
	double rez = sum_elements(array, start, end);
	printf("—умма цифр массива с %d до %d  равна %lf\n", start, end, rez);
	//обавьте функцию поиска элемента равного а:
	double a;
	printf("¬ведите число которое хотите найти: ");
	scanf_s("%lf", &a);
	int rez2 = find_element(array, size, a);
	if (rez2 == -1) {
		printf("Ёлемент не найден");
	}
	else
	{
		printf("Ёлемент найден под индексом %d", rez2);
	}
	return 0;
}

double max_elements(double* array,int end) {
	double rez = 0;
	for (int i = 0; i <= end; i++) {
		if (array[i] > rez) {
			rez = array[i];
		}
	}
	return rez;
}

int Task3() {
	//ѕоиск максимального значени€ элемента массива,
	// наход€щихс€ до заданной позиции K включительно.
	double array[100];
	int size;
	printf("¬ведите размер массива > ");
	scanf_s("%d", &size);
	CalcNabor(array, size);
	int end;
	printf("¬ведите конечный индекс массива  ");
	scanf_s("%d", &end);
	double rez = max_elements(array,end);
	printf("Ёлемент с наибольшим числом до индекса %d равен %lf",end,rez);
	return 0;
}


int no_find_element(double* ptr_array, int n, double element) {
	int rez = 0;
	for (int i = 0; i < n; i++) {
		if (ptr_array[i] != element) {
			rez = i;
			return rez;
		}
		else {
			rez = -1;
		}
	}
	return rez;
}

int HomeWork() {
	//ќпределение первого пор€дкового номера элемента не равного ј.
	double array[100];
	int size;
	printf("¬ведите размер массива > ");
	scanf_s("%d", &size);
	CalcNabor(array, size);
	double a;
	printf("¬ведите число которое будет сравниватьс€: ");
	scanf_s("%lf", &a);
	int rez2 = no_find_element(array, size, a);
	if (rez2 == -1) {
		printf("Ёлемент отличный от этого не найден");
	}
	else
	{
		printf("Ёлемент найден под индексом %d", rez2);
	}

	return 0;
}
