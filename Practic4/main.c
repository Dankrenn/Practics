#include <stdio.h>
#include <locale.h>
#include <math.h>

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
	char c1 = "(";
	int i1 = 2;
	float f1 = 3.14f;
	double d1 = 5e-12;

	printf("%c\n", c1);
	printf("%d\n", i1);
	printf("%f\n", f1);
	printf("%e\n", d1);

	printf("Введите значение : char \n");
	scanf_s("%c", &c1);
	printf("Введите значение : int\n");
	scanf_s("%d", &i1);
	printf("Введите значение : float\n");
	scanf_s("%f", &f1);
	printf("Введите значение : double\n");
	scanf_s("%e", &d1);

	printf("%c\n", c1);
	printf("%d\n", i1);
	printf("%f\n", f1);
	printf("%e\n", d1);

	printf("\n");
	//1.a
	float f2;
	int c2;
	float d2;

	printf("Введите значение : float\n");
	scanf_s("%f", &f2);
	c2 = f2;
	d2 = f2 - c2;

	printf("%f\n", f2);
	printf("%d\n", c2);
	printf("%f\n", d2);

	printf("\n");
	//1.b
	char c3;

	printf("Введите значение : char\n");
	scanf_s("%c", &c3);
	printf("%c == %d\n", c3, c3);
	printf("%c == %x\n", c3, c3);
	printf("%c == %o\n", c3, c3);

	printf("\n");
	//1.v
	int c4;

	printf("Введите значение: int\n");
	scanf_s("%d", &c4);
	printf("%d %2f", c4, .1 / c4);
	printf("\n");
	return 0;
}

int Task2() {
	setlocale(LC_ALL, "Rus");
	int a = 11;
	int b = 3;
	int x;
	float y;
	double z;

	x = a % b;
	y = a * b;
	z = a / b;
	printf("%d %f %lf\n", x, y, z);

	printf("%f\n", (double)a / b);
	printf("%lf\n", (float)a / b);
	printf("\n");
	return 0;
}


int Task3() {
	setlocale(LC_ALL, "Rus");
	int a;
	printf("Введите значение: int \n");
	scanf_s("%d", &a);
	int one = a / 100 % 10;
	int tho = a / 10 % 10;
	int three = a % 10;

	printf("Последняя цифра %d;Первая цифра %d;Сумма цифр данного числа %d;Число в обратном порядке %d\n", three,one,one+tho+three,three*100+tho*10+one);
	printf("\n");
}




int HomeWork() {
	/*Недалеко от реки на берегу горит костер. На том же берегу находится человек с
ведром. Определить минимальное расстояние, которое должен пройти человек, до
костра, зачерпнув по дороге к нему воды в реке, если из-вестны расстояния от реки до
костра и до человека, и расстояние от костра до человека по течению реки. Река в
этом месте течет по прямой.
	*/
	setlocale(LC_ALL, "Rus");
	double d1, d2, d3;


	printf("Введите расстояние от человека до реки (d1): ");
	scanf_s("%lf", &d1);

	printf("Введите расстояние от костра до реки (d2): ");
	scanf_s("%lf", &d2);

	printf("Введите расстояние по течению реки от костра до человека (d3): ");
	scanf_s("%lf", &d3);

	double verticalDistance = d2 - d1; 
	double distanceToFire = d1 + sqrt((d3 * d3) + (verticalDistance * verticalDistance));

	// Вывод результата
	printf("Минимальное расстояние, которое должен пройти человек: %.2lf\n", distanceToFire);
	printf("\n");
	return 0;
}

