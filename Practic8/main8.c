#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h.>

int main()
{
	//Task1();
	//Task2();
	//HomeWork();
	return 0;
}

int Task1() {
	setlocale(LC_ALL, "Rus");
	int a, b,k = 0, res = 0;
	printf("������� ����� a: ");
	scanf_s("%d", &a);
	printf("������� ����� b: ");
	scanf_s("%d", &b);
	if (a > b) {
		for (int i = a; i >= b; i--) {
			res += i;
			printf("���������� %d ���\n", k++);
		}
		printf("����� ����� : %d\n", res);
	}
	else
	{
		printf("a < b ");
	}
	int n,res1 = 0;
	printf("������� ����� n: ");
	scanf_s("%d", &n);
	for (int i = 0; i <= n; i++) {
		int sum = pow(2, i);
		res1 += sum;
		printf("%d\n",sum);
	}
	printf("����� ����� : %d\n", res1); 
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	printf(" y = 2^x - 2x^2 - 1");
	int tab;
	printf("������� �������� ���������: ");
	scanf_s("%d", &tab);
	for (int i = 1; i <= 4; i++) {
		printf("--------------");

	}
	return 0;
}

int HomeWork() {
	setlocale(LC_ALL, "Rus");

	int res = 0;
	printf("������� ������:\n ");
	char c = _getch();//���������� � �������

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
		printf("��� ����� %d\n", res);
	}
	else
	{
		printf("�������� ������");
	}
	getchar();
	return 0;
}

