#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

typedef double (*TFun)(double);

double funcY(double x);
double funcV(double x);
double funcS(double x);
void calculate(TFun prtf, double* x, int n);
void printTable(TFun func, double xn, double xk, double h, const char* name);
void calculateRange(TFun func, double* xValues, int n);

int Task1();
int Task2();
void HomeWork();

int main() {
    setlocale(LC_CTYPE, "RUS");
    Task1();
    Task2();
    HomeWork();
    return 0;
}

int Task1() {
    printf("������� 1. ������������ ��������� ��������� ���� �������� �������, ��������� �� ���� ��������� �������������� ������� � ������� ������ ������� ��������, ������� ��������� � �������� ��������� - ��������� �� ��������� �������������� �������.\n");

    double a, b, h;
    double xValues[100];
    int n = 0;
    int choice;

    printf("������� ��������� �������� (a), �������� �������� (b) � ��� (h): ");
    scanf_s("%lf %lf %lf", &a, &b, &h);

    for (double x = a; x <= b; x += h) {
        xValues[n++] = x;
    }

    printf("\n�������� ������� ��� ���������:\n");
    printf("1. Y(x) = ln(sqrt(x^3)), x > 0\n");
    printf("2. V(x) - �������� �������\n");
    printf("3. S(x) - ���������� � ���\n");
    printf("������� ��� ����� (1-3): ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printTable(funcY, a, b, h, "Y(x)");
        calculate(funcY, xValues, n);
        break;
    case 2:
        printTable(funcV, a, b, h, "V(x)");
        calculate(funcV, xValues, n);
        break;
    case 3:
        printTable(funcS, a, b, h, "S(x)");
        calculate(funcS, xValues, n);
        break;
    default:
        printf("�������� �����.\n");
    }

    printf("������� 1 ���������\n");
    printf("\n");
    return 0;
}

int Task2() {
    printf("������� 2. ��������� ��������� ����, ����������� �������� ������� � �������� � ����.\n");

    double a, b, h;
    double xValues[100];
    int n = 0;
    int choice;

    printf("������� ��������� �������� (a), �������� �������� (b) � ��� (h): ");
    scanf_s("%lf %lf %lf", &a, &b, &h);

    for (double x = a; x <= b; x += h) {
        xValues[n++] = x;
    }

    printf("\n�������� ������� ��� ������:\n");
    printf("1. Y(x) = ln(sqrt(x^3)), x > 0\n");
    printf("2. V(x) - �������� �������\n");
    printf("3. S(x) - ���������� � ���\n");
    printf("������� ��� ����� (1-3): ");
    scanf_s("%d", &choice);

    TFun selectedFunc;
    switch (choice) {
    case 1:
        selectedFunc = funcY;
        break;
    case 2:
        selectedFunc = funcV;
        break;
    case 3:
        selectedFunc = funcS;
        break;
    default:
        printf("�������� �����.\n");
        return 0;
    }

    calculateRange(selectedFunc, xValues, n);

    printf("������� 2 ���������\n");
    printf("\n");
    return 0;
}

void HomeWork() {
    printf("��. ���������� ����������� �������� ������� ��� �������� �������� ������� x.\n");

    double a, b, h;
    double xValues[100];
    int n = 0;
    int choice;

    printf("������� ��������� �������� (a), �������� �������� (b) � ��� (h): ");
    scanf_s("%lf %lf %lf", &a, &b, &h);

    for (double x = a; x <= b; x += h) {
        xValues[n++] = x;
    }

    printf("\n�������� ������� ��� ������:\n");
    printf("1. Y(x) = ln(sqrt(x^3)), x > 0\n");
    printf("2. V(x) - �������� �������\n");
    printf("3. S(x) - ���������� � ���\n");
    printf("������� ��� ����� (1-3): ");
    scanf_s("%d", &choice);

    TFun selectedFunc;
    switch (choice) {
    case 1:
        selectedFunc = funcY;
        break;
    case 2:
        selectedFunc = funcV;
        break;
    case 3:
        selectedFunc = funcS;
        break;
    default:
        printf("�������� �����.\n");
        return;
    }

    calculate(selectedFunc, xValues, n);

    printf("�� ���������\n");
    printf("\n");
}

void calculate(TFun prtf, double* x, int n) {
    double minValue = prtf(x[0]);
    for (int i = 1; i < n; i++) {
        double currentValue = prtf(x[i]);
        if (currentValue < minValue) {
            minValue = currentValue;
        }
    }
    printf("����������� �������� �������: %.6f\n", minValue);
}

double funcY(double x) {
    if (x <= 0) {
        printf("Y(x) �� ���������� ��� x <= 0.\n");
        return NAN;
    }
    return log(fabs(sqrt(pow(x, 3))));
}

double funcV(double x) {
    double y;
    if (x > 1) {
        y = sqrt(tan(x * x - 1));
        if (isnan(y)) {
            y = 0;
        }
    }
    else if (x >= 0 && x <= 1) {
        y = -2 * x;
    }
    else {
        y = exp(cos(x));
    }
    return y;
}

double funcS(double x) {
    double term1 = (x - 1) / (x + 1);
    double y = term1 + (1.0 / 3.0) * pow(term1, 3) + (1.0 / 5.0) * pow(term1, 5) + (1.0 / 7.0) * pow(term1, 7);
    return y;
}

void printTable(TFun func, double xn, double xk, double h, const char* name) {
    printf("\n������� �������� %s:\n", name);
    printf("-----------------------------\n");
    printf("|    x    |      %s(x)      |\n", name);
    printf("-----------------------------\n");

    for (double x = xn; x <= xk; x += h) {
        double result = func(x);
        printf("| %7.2f | %15.6f |\n", x, result);
    }
    printf("-----------------------------\n");
}

void calculateRange(TFun func, double* xValues, int n) {
    double minX = xValues[0];
    double maxX = xValues[0];
    double minY = func(xValues[0]);
    double maxY = func(xValues[0]);

    for (int i = 1; i < n; i++) {
        double x = xValues[i];
        double y = func(x);

        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    double rangeX = maxX - minX;
    double rangeY = maxY - minY;

    printf("������ ������� �� ��� X: %.6f\n", rangeX);
    printf("������ ������� �� ��� Y: %.6f\n", rangeY);
}
