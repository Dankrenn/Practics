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
	printf("������� ���\n");
	scanf_s("%d", &yeas);
	int isLeapYear = 0;
	if ((yeas % 4 == 0 && yeas % 100 != 0) || (yeas % 400 == 0)) {
		isLeapYear = 1;
	}
	if (isLeapYear) {
		printf("��� %d ����������\n", yeas);
	}
	else {
		printf("��� %d �� ����������\n", yeas);
	}
	printf("\n");
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	double x;
	double f;

	printf("������� x: \n");
	scanf_s("%lf", &x);

	f = x<3.2 ? pow(x, 4) + 9 : (54 * pow(x, 4)) / (-5 * pow(x, 2) + 7);
	printf("X %c 3.2, F(x) = %.3f\n",x>3.2? '>':'<', f);
	// ���� x < 3.2, f(x) = x^4 + 9
	//if (x < 3.2) {
	//	f = pow(x, 4) + 9;
	//	printf("X < 3.2, F(x) = %.3f\n", f);
	//}
	//else { // ����� f(x) = 54x^4 / (-5x^2 + 7)
	//	f = (54 * pow(x, 4)) / (-5 * pow(x, 2) + 7);
	//	printf("X >= 3.2, F(x) = %.4le\n", f);
	//}

	return 0;
}

int Task3() {
	/*
	�������� ���������, ������� ������� ��������� ��������� ����
��������� ������������� ����� � ���� ��������������� ��������� (X<Y
��� X=Y ��� X>Y).
	*/
	setlocale(LC_ALL, "Rus");

	double x;
	double f;

	printf("������� X: \n");
	scanf_s("%lf", &x);
	printf("������� Y: \n");
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
	printf("������� X: \n");
	scanf_s("%d", &x);
	printf("������� Y: \n");
	scanf_s("%d", &y);


	int inCircle = (pow(x, 2) + pow(y, 2) < 36); // �������� �� ����������
	int aboveLine = (y > (3 - x)); // �������� �� ������
	int inFirstQuadrant = (x > 0 && y > 0); // �������� �� ������ ��������

	// �������� �������������� � �������������� �������
	if (inCircle && aboveLine && inFirstQuadrant) {
		printf("����� (%d, %d) ����������� �������������� �������.\n", x, y);
	}
	else {
		printf("����� (%d, %.d) �� ����������� �������������� �������.\n", x, y);
	}


	printf("\n");
	return 0;
}

