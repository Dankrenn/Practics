#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h.>

int main()
{
	//Task1();
	Task2();
	HomeWork();
	return 0;
}

int Task1() {
	setlocale(LC_ALL, "Rus");
	char c;
	int res = 0;
	printf("Введите символ: ");
	scanf_s("%c", &c);//считывание с консоли

	switch (c)
	{
	case '0':
		res = 1;
		break;
	case '1':
		res = 1;
		break;
	case '2':
		res = 1;
		break;
	case '3':
		res = 1;
		break;
	case '4':
		res = 1;
		break;
	case '5':
		res = 1;
		break;
	case '6':
		res = 1;
		break;
	case '7':
		res = 1;
		break;
	case '8':
		res = 1;
		break;
	case '9':
		res = 1;
		break;
	default:
		res = 0;
		break;
	}
	if (res == 1) {
		printf("Это цифра");
	}
	else
	{
		printf("Это буква");
	}
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	char c;
	float x = 0;
	float y = 0;
	float res = 0;
	printf("Введите 3 значения 2 числа и операцию которую хотите с ними произвести ");
	scanf_s("%f %c %f", &x, &c,1, &y);

	switch (c)
	{
	case '*':
		res = x * y;
		break;
	case '/':
		res = x / y;
		break;
	case '+':
		res = x + y;
		break;
	case '-':
		res = x - y;
		break;
	case '|':
		res = fabs(x - y);
		break;
	default:
		printf("Неверный формат строки");
		return 0;
	}
	printf("Результат равен %f", res);
	return 0;
}

int HomeWork() {
	setlocale(LC_ALL, "Rus");

	int res = 0;
	printf("Введите символ:\n ");
	char c =  _getch();//считывание с консоли

	switch (c)
	{
	case '0':
		res = 0;
		break;
	case '1':
		res = 1;
		break;
	case '2':
		res = 2;
		break;
	case '3':
		res = 3;
		break;
	case '4':
		res = 4;
		break;
	case '5':
		res = 5;
		break;
	case '6':
		res = 6;
		break;
	case '7':
		res = 7;
		break;
	case '8':
		res = 8;
		break;
	case '9':
		res = 9;
		break;
	default:
		res = -1;
		break;
	}
	if (9 <= res >= 0) {
		printf("Это цифра %d\n", res);
	}
	else
	{
		printf("неверный формат");
	}
	getchar();
	return 0;
}

