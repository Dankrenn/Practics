#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	//Task1();
	Task2();
	//Task3();
	//HomeWork();
	return 0;
}

int Task1() {
	setlocale(LC_ALL, "Rus");
	int yeas;
	printf("Введите год\n");
	scanf_s("%d", &yeas);
	int isLeapYear = 0;
	if ((yeas % 4 == 0 && yeas % 100 != 0) || (yeas % 400 == 0)) {
		isLeapYear = 1;
	}
	if (isLeapYear) {
		printf("Год %d високосный\n", yeas);
	}
	else {
		printf("Год %d не високосный\n", yeas);
	}
	printf("\n");
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	double x;
	double f;

	printf("Введите x: \n");
	scanf_s("%lf", &x);

	f = x<3.2 ? pow(x, 4) + 9 : (54 * pow(x, 4)) / (-5 * pow(x, 2) + 7);
	printf("X %c 3.2, F(x) = %.3f\n",x>3.2? '>':'<', f);
	// Если x < 3.2, f(x) = x^4 + 9
	//if (x < 3.2) {
	//	f = pow(x, 4) + 9;
	//	printf("X < 3.2, F(x) = %.3f\n", f);
	//}
	//else { // Иначе f(x) = 54x^4 / (-5x^2 + 7)
	//	f = (54 * pow(x, 4)) / (-5 * pow(x, 2) + 7);
	//	printf("X >= 3.2, F(x) = %.4le\n", f);
	//}

	return 0;
}

int Task3() {
	/*
	Написать программу, которая выводит результат сравнения двух
введенных пользователем чисел в виде математического выражения (X<Y
или X=Y или X>Y).
	*/
	setlocale(LC_ALL, "Rus");

	double x;
	double f;

	printf("Введите X: \n");
	scanf_s("%lf", &x);
	printf("Введите Y: \n");
	scanf_s("%lf", &f);

	printf("X");
	if (x>f)
	{
		printf(">");
	}
	else if (x<f) 
	{
		printf("<");
	}
	else 
	{
		printf("=");
	}
	printf("Y\n");

	printf("\n");
	return 0;
}




int HomeWork() {
	setlocale(LC_ALL, "Rus");
	int x;
	int y;;
	printf("Введите X: \n");
	scanf_s("%d", &x);
	printf("Введите Y: \n");
	scanf_s("%d", &y);


	int inCircle = (pow(x, 2) + pow(y, 2) < 36); // Проверка на окружность
	int aboveLine = (y > (3 - x)); // Проверка на прямую
	int inFirstQuadrant = (x > 0 && y > 0); // Проверка на первую четверть

	// Проверка принадлежности к заштрихованной области
	if (inCircle && aboveLine && inFirstQuadrant) {
		printf("Точка (%d, %d) принадлежит заштрихованной области.\n", x, y);
	}
	else {
		printf("Точка (%d, %.d) не принадлежит заштрихованной области.\n", x, y);
	}


	printf("\n");
	return 0;
}

