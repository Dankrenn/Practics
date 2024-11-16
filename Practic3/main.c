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
	puts("Введите число:");
	scanf_s("%d", &num);
	puts("Введите 2 число:");
	scanf_s("%d", &num2);
	printf("Введены числа %d и %d\n", num, num2);
	printf("Произведение равно %d\n", num * num2);
	printf("Сумма равна %d\n", num + num2);
	printf("Разность равна %d\n", num2 - num);
	printf("Частное равна %d\n", num2 / num);
	printf("Остаток от деление %d на %d  равнен %d\n", num2, num, num2 % num);
	printf("\n");

	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	int km;
	puts("Введите число км:");
	scanf_s("%d", &km);
	int m = km * 1000;
	double result = m / M;
	printf("%d равно %f морских миль\n",km,result);
	double result2 = m / S;
	printf("%d равно %f сухопотных миль\n", km, result2);
	double result3 = m / R;
	printf("%d равно %f римских миль\n", km, result3);
	double result4 = m / C;
	printf("%d равно %f старорусских миль\n", km, result4);
	double result5 = m / G;
	printf("%d равно %f географических миль\n", km, result5);
	printf("\n");
	return 0;
}


int Task3() 
{
	setlocale(LC_ALL, "");

	double a, b;
	printf("Введите значение a: ");
	scanf_s("%lf", &a);
	printf("Введите значение b: ");
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
	//Написать и отладить программу пересчета числа прожитых
	//лет в дни и месяцы;
	int years;
	setlocale(LC_ALL, "");
	printf("Введите количество прожитых лет: ");
	scanf_s("%d", &years);

	int months = years * 12; 
	int days = years * 365; 

	printf("Вы прожили: %d лет, что равно:\n", years);
	printf("%d месяцев\n", months);
	printf("%d дней\n", days);
	printf("\n");
	return 0;
}