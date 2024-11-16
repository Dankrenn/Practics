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
	printf("Остаток от деления %d на %d  равен %d\n", 5, 2, 5 % 2);
	printf("Остаток от деления %d на %d  равен %d\n", 7, 5, 7 % 5);
	printf("Умножение %d на %d  равно %d\n", 2000, 4, 2000 * 4);
	printf("%g разделить  %e  равно %f\n", 5., 2., 5. / 2);
	printf("%d разделить  %d  равно %d\n", 5., 2., 5. / 2);
	printf("%f разделить  %f  равно %f\n", 5., 2., 5. / 2);
	printf("%g разделить  %g  равно %g\n", 5., 2., 5. / 2);
	printf("%e разделить  %e  равно %e\n", 5., 2., 5. / 2);

	printf("\n");
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	int N = 15, K = 27;

	printf("Сейчас %d часов %d минут 00 секунд\n", N, K);

	int totalMinutesInDay = 24 * 60;
	int currentMinutes = N * 60 + K;
	printf("Идет %d минута суток\n", currentMinutes);

	int minutesUntilMidnight = totalMinutesInDay - currentMinutes;
	int hoursUntilMidnight = minutesUntilMidnight / 60;
	int remainingMinutes = minutesUntilMidnight % 60;
	printf("До полуночи осталось %d часов и %d минут\n", hoursUntilMidnight, remainingMinutes);
	
	int secondsSinceEight = (N - 8) * 3600 + K * 60;
	printf("С 8.00 прошло %d секунд\n", secondsSinceEight);

	float currentHour = N / 24.0f; 
	float currentMinute = K / 60.0f; 
	printf("Текущий час = %.2f суток и текущая минута = %.2f часа\n", currentHour, currentMinute);
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
	printf("Данные:  %36s %f / %d\n","",n, l);
	printf("Результат: %c знак %d  целой части и %10.4f дробной части \n", (n > 0 && l > 0) ? '+' : '-', k, m);
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
	printf("Данные: %44s %d / %d\n","", n, l);
	printf("Результат: %c знак %d  целой части и %10.4f дробной части \n",(n>0&&l>0)?'+' : '-', k, m);
	printf("\n");
	return 0;
}