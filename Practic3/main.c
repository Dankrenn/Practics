#include <stdio.h>
#include <locale.h>

#define      M       1.852
#define      S       1609
#define      R       1475
#define      C       7468
#define      G       7412600

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
	int num;
	int num2;
	puts("������� �����:");
	scanf_s("%d", &num);
	puts("������� 2 �����:");
	scanf_s("%d", &num2);
	printf("������� ����� %d � %d\n", num, num2);
	printf("������������ ����� %d\n", num * num2);
	printf("����� ����� %d\n", num + num2);
	printf("�������� ����� %d\n", num2 - num);
	printf("������� ����� %d\n", num2 / num);
	printf("������� �� ������� %d �� %d  ������ %d\n", num2, num, num2 % num);
	printf("\n");

	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	int km;
	puts("������� ����� ��:");
	scanf_s("%d", &km);
	int m = km * 1000;
	double result = m / M;
	printf("%d ����� %f ������� ����\n",km,result);
	double result2 = m / S;
	printf("%d ����� %f ���������� ����\n", km, result2);
	double result3 = m / R;
	printf("%d ����� %f ������� ����\n", km, result3);
	double result4 = m / C;
	printf("%d ����� %f ������������ ����\n", km, result4);
	double result5 = m / G;
	printf("%d ����� %f �������������� ����\n", km, result5);
	printf("\n");
	return 0;
}


int Task3() 
{
	setlocale(LC_ALL, "");

	double a, b;
	printf("������� �������� a: ");
	scanf_s("%lf", &a);
	printf("������� �������� b: ");
	scanf_s("%lf", &b);

	double multiplication = a * b;
	double addition = a + b;
	double subtraction = a - b;


	printf("_________________________________________\n");
	printf("| %11s | %11s | %11s |\n", "a * b", "a + b", "a - b");
	printf("-----------------------------------------\n");
	printf("| %4g * %-4g | %4g + %-4g | %4g - %-4g |\n", a, b, a, b, a, b);
	printf("-----------------------------------------\n");
	printf("| %11.4e | %11.4e | %11.4e |\n", multiplication, addition, subtraction);
	printf("-----------------------------------------\n");

	printf("\n");
	return 0;
}

int HomeWork() {
	//�������� � �������� ��������� ��������� ����� ��������
	//��� � ��� � ������;
	int years;
	setlocale(LC_ALL, "");
	printf("������� ���������� �������� ���: ");
	scanf_s("%d", &years);

	int months = years * 12; 
	int days = years * 365; 

	printf("�� �������: %d ���, ��� �����:\n", years);
	printf("%d �������\n", months);
	printf("%d ����\n", days);
	printf("\n");
	return 0;
}