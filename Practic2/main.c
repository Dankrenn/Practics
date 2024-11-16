#include <stdio.h>
#include <locale.h>

int main()
{
	//Task1();
	//Task2();
	Task3();
	HomeWork();
	return 0;
}

int Task1() {
	setlocale(LC_ALL, "Rus");
	printf("123\n");
	printf("1\n2\n3\n");
	printf("1\n\t2\n\t\t3\n");
	printf("%d\n %3d\n %6d\n %9d\n", 1, 2, 3, 4);
	printf("%10.3f\n", 12.234657);
	printf("%10.5f\n", 12.234657);
	printf("������� �� ������� %d �� %d  ����� %d\n", 5, 2, 5 % 2);
	printf("������� �� ������� %d �� %d  ����� %d\n", 7, 5, 7 % 5);
	printf("��������� %d �� %d  ����� %d\n", 2000, 4, 2000 * 4);
	printf("%g ���������  %e  ����� %f\n", 5., 2., 5. / 2);
	printf("%d ���������  %d  ����� %d\n", 5., 2., 5. / 2);
	printf("%f ���������  %f  ����� %f\n", 5., 2., 5. / 2);
	printf("%g ���������  %g  ����� %g\n", 5., 2., 5. / 2);
	printf("%e ���������  %e  ����� %e\n", 5., 2., 5. / 2);

	printf("\n");
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	int N = 15, K = 27;

	printf("������ %d ����� %d ����� 00 ������\n", N, K);

	int totalMinutesInDay = 24 * 60;
	int currentMinutes = N * 60 + K;
	printf("���� %d ������ �����\n", currentMinutes);

	int minutesUntilMidnight = totalMinutesInDay - currentMinutes;
	int hoursUntilMidnight = minutesUntilMidnight / 60;
	int remainingMinutes = minutesUntilMidnight % 60;
	printf("�� �������� �������� %d ����� � %d �����\n", hoursUntilMidnight, remainingMinutes);
	
	int secondsSinceEight = (N - 8) * 3600 + K * 60;
	printf("� 8.00 ������ %d ������\n", secondsSinceEight);

	float currentHour = N / 24.0f; 
	float currentMinute = K / 60.0f; 
	printf("������� ��� = %.2f ����� � ������� ������ = %.2f ����\n", currentHour, currentMinute);
	printf("\n");
	return 0;
}


int Task3() {
	setlocale(LC_ALL, "Rus");
	double n = 53.754;
	int l = 13;
	double result = n / l;
	int k = result;
	double m = result - k;
	printf("������:  %36s %f / %d\n","",n, l);
	printf("���������: %c ���� %d  ����� ����� � %10.4f ������� ����� \n", (n > 0 && l > 0) ? '+' : '-', k, m);
	printf("\n");
	return 0;
}

int HomeWork() {
	setlocale(LC_ALL, "Rus");
	int n = 3;
	int l = 313;
	double result = n / l;
	int k = result;
	double m = result - k;
	printf("������: %44s %d / %d\n","", n, l);
	printf("���������: %c ���� %d  ����� ����� � %10.4f ������� ����� \n",(n>0&&l>0)?'+' : '-', k, m);
	printf("\n");
	return 0;
}