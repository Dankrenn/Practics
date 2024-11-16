#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	//Task1();
	//Task2();
	Task3();
	//HomeWork();
	return 0;
}

#define N 10
int Task1() {
	setlocale(LC_CTYPE, "RUS");
	float A[N];
	float B[N];
	float sum = 0;
	for (int i = 0; i < N; i++)
	{
		float c;
		printf("a[%d] = ", i + 1);
		scanf_s("%f", &c);
		A[i] = c;
		sum += A[i];
	}
	//�������� � ������� �������� ������� �������� �������;
	for (int i = 0; i < N; i++)
	{
		float c = A[i];
		B[i] = pow(c, 2);
		//���������� ������� �� ����� � ���� �������, � ������ ������� ������� ������� 
		// ����� ��������, �� ������ � �������� �������, � ������� � ���������������.
		printf("|%d|%5.3f|%5.3f\n", i, A[i], B[i]);
	}
	//��������� ������� �������������� ��������� �������.
	printf("������� ��������: %.3f\n", sum/N);
	printf("\n");
	return 0;
}
int Task2() {
	setlocale(LC_CTYPE, "RUS");
	//y = 1.8x^2 - sin10x
	double A[100];
	double avg;
	double avg_pol = 0;
	double sum = 0;
	double sum_pol = 0;
	double sum_otr = 0;
	int count = 0;
	int count_pol = 0;
	int count_otr = 0;
	for (int i = 0; i < 100; i++)
	{
		double x = 0.2; ;
		A[i] = 1.8 * pow(x, 2) - sin(10 * x);
		if (A[i] >= 0) {
			count_pol++;
			sum_pol += A[i];
		}
		else {
			count_otr ++;
			sum_otr += A[i];
		}
		count ++;
		sum += A[i];
		x += 0.05;

	} 
	avg_pol = (sum_pol != 0 &&  count_pol != 0) ? sum_pol / count_pol : 0;
	avg = sum / count;
	printf("������� �������� ���� ������������� ���������: %lf\n", avg_pol);
	printf("��� �������: %lf\n", avg_pol);
	printf("����������� �������� + %lf |  - %lf: %f\n", sum_pol,sum_otr);
	printf("����� ������������� ���������� - %d , ������������� - %d\n", count_pol,count_otr);
	printf("������� �������� ���� ��������� �������: %lf\n", avg);
	printf("\n");
	return 0;
}

int Task3() {
	setlocale(LC_CTYPE, "RUS");
	float A[10];
	float B[10];
	int rez = 1;
	for (int i = 0; i < 10; i++)
	{
		float c;
		printf("a[%d] = ", i + 1);
		scanf_s("%f", &c);
		A[i] = c;
	}
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > 0)
		{
			rez *= i != 0 ? i :i+1;
			printf("%d , %d\n", i, rez);
		}
	}
	return 0;
}
