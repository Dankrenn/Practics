#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	Task1();
	return 0;
}


typedef double (*TFun)(double);

double funcY(double x);
double funcV(double x); 
double funcS(double x);
void calculate(TFun prtf, double* x, int n);

void printTable(TFun func, double xn, double xk, double h, const char* name);

int Task1() {
    double a, b, h; 
    double xValues[100]; 
    int n = 0;
    int choice;

    printf("Введите начальное значение (a), конечное значение (b) и шаг (h): ");
    scanf_s("%lf %lf %lf", &a, &b, &h);

    for (double x = a; x <= b; x += h) {
        xValues[n++] = x;
    }
    printf("\nВыберите функцию для табуляции:\n");
    printf("1. Y(x) = ln(sqrt(x^3)), x > 0\n");
    printf("2. V(x) - кусочная функция\n");
    printf("3. S(x) - разложение в ряд\n");
    printf("Введите ваш выбор (1-3): ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printTable(funcY, a, b, h, "Y(x)");
        calculate(funcY, xValues, n);
        break;
    case 2:
        printTable(funcV, a, b, h, "V(x)");
        calculate(funcY, xValues, n);
        break;
    case 3:
        printTable(funcS, a, b, h, "S(x)");
        calculate(funcY, xValues, n);
        break;
    default:
        printf("Неверный выбор.\n");
    }
    return 0;
}
void calculate(TFun prtf, double* x, int n) {
    double minValue = prtf(x[0]); 
    for (int i = 1; i < n; i++) { 
        double currentValue = prtf(x[i]); 
        if (currentValue < minValue) { 
            minValue = currentValue;
        }
    }
    printf("Минимальное значение функции: %.6f\n", minValue);
}

double funcY(double x) {
    if (x <= 0) {
        printf("Y(x) не определена при x <= 0.\n");
        return 0;
    }
    return log(fabs(sqrt(pow(x, 3))));     
}


double funcV(double x) {
    double y;
    if (x > 1)
    {
        y = sqrt(tan(x * x - 1));
        if (y = NAN)
        {
            y = 0;
        }
    }
    else if (x >= 0 && x <= 1)
    {
        y = -2 * x;
    }
    else
    {
        y = exp(cos(x));
    }
    return y;
}

double funcS(double x) {
    double term1 = (x - 1) / (x + 1);
    double y = term1 + (1.0 / 3.0) * pow(term1, 3) +(1.0 / 5.0) * pow(term1, 5) + (1.0 / 7.0) * pow(term1, 7);
    return y;
}

void printTable(TFun func, double xn, double xk, double h, const char* name) {
    printf("\nТаблица значений %s:\n", name);
    printf("-----------------------------\n");
    printf("|    x    |      %s(x)      |\n", name);
    printf("-----------------------------\n");

    for (double x = xn; x <= xk; x += h) {
        double result = func(x); 
        printf("| %7.2f | %15.6f |\n", x, result);
    }
    printf("-----------------------------\n");
}
