#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES
#define M_PI            3.14159265358979323846
#define P           0.5

int main()
{
    //Primer();
	//Task1();
	//Task2();
	//Task3();
	HomeWork();
	return 0;
}

int Primer() {
	setlocale(LC_ALL, "Rus");
	
	double x, y;

	printf("������� �������� x: double \n");
	scanf_s("%f", &x);
	printf("������� �������� y: double \n");
	scanf_s("%f", &y);

	double Res1 = 0.5 * y;
	double Res2 = pow(x, Res1);
	double Res3 = sin(Res2);
	double Res4 = y + 8e-4;
	double Res5 = pow(Res4, 1 / 5.f);
	double Result = Res3 + Res5; 
	//��� ��
	double Result1 = sin(pow(x, 0.5 * y)) + pow(y + 8e-4, 1 / 5.f);

	printf("�����: % .3f", sin(pow(x, 0.5 * y)) + pow(y + 8e-4, 1 / 5.f));

	printf("\n");
	return 0;
}

int Task1() {
	setlocale(LC_ALL, "Rus");
	
	int gr;
	int gr30 = 30;
	int gr60 = 60;
	int gr90 = 90;
	printf("������� ������\n");
	scanf_s("%d", &gr);

	double rad = gr * M_PI / 180;
	double rad30 = gr * M_PI / 180;
	double rad60 = gr * M_PI / 180;
	double rad90 = gr * M_PI / 180;
	printf("�����: % .6f", rad);
	printf("����� ��� 30 ��������: % .6f", rad30);
	printf("����� ��� 60 ��������: % .6f", rad60);
	printf("����� ��� 90 ��������: % .6f", rad90);
	printf("\n");
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	double x = 2.1;
	printf("������� x\n");
	scanf_s("%lf", &x);

	double a = log(pow(P, 2) + pow(x, 3)); // ln(0.5^2 + 2.1^2)
	double b = exp(sqrt(fabs(x))); // e^(sqrt(|2.1|))
	double y = pow(a, 3) / pow(b, 2);

	printf("���������: % .4lf \n", a);
	printf("���������: % .4lf \n", b);
	printf("���������: % .4lf \n",y);
	printf("\n");
	return 0;
}


int Task3() {
	setlocale(LC_ALL, "Rus");
	double x = 2.1;
	printf("������� x\n");
	scanf_s("%lf", &x);

	double a = log(pow(P, 2) + pow(x, 3)); // ln(0.5^2 + 2.1^2)
	double b = exp(sqrt(fabs(x))); // e^(sqrt(|2.1|))
	double y = pow(a, 3) / pow(b, 2);
	int A = a;
	int B = b;
	int C = y;
	bool chek = false;
	if (A % 2 == 0 || B % 2 == 0)
	{
		printf("������� � ���������\n");
		chek = true;
	}
	if (A % 3 == 0 && B % 3 == 0 && C % 3 == 0)
	{
		printf("������� � ���������\n");
		chek = true;
	}
	if(!chek)
	{
		printf("������� �� ���������\n");
	}

	printf("A =%d B = %d C=%d\n", A,B,C);
	printf("\n");
	return 0;
}




int HomeWork() {
	setlocale(LC_ALL, "Rus");
	double x =  -0.02235;
	double y = 2.23;
	double z = 15.221;
	double w;
	double res1 = pow((pow(x,6) + pow(log(y),2)), 1. / 3);
	double res2 = exp(fabs(x - y))* pow(fabs(x-y), (x + y));
	double res3 = (atan(x)) + atan(z);;
	double result = res1 + res2 / res3;
	printf("���������: % .3f\n", res1);
	printf("���������: % .3f\n", res2);
	printf("���������: % .3f\n", res3);
	printf("���������: % .3f\n",result);
	printf("\n");
	return 0;
}

