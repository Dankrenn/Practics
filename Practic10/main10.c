#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h.>

#define M_PI 3.1415926535897932384626
//int main()
//{
//    //Task1();
//    //Task2();
//    HomeWork();
//    return 0;
//}

double FUNCTAN(double x) {
    if (fabs(x) >= M_PI / 2) {
        printf("Ошибка: x должен быть в диапазоне |x| < π/2\n");
        return 0;
    }

    double sum = 0.0;
    double term = x;
    int n = 1;

    while (fabs(term) > 1e-5) {
        sum += term;
        n += 2;

        // коэффициент * x^(n) / n!
        term *= -x * x * (n - 2) / n;
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");
    double x;

    printf("Введите значение x (в радианах, |x| < π/2): ");
    scanf_s("%lf", &x);

    double result = FUNCTAN(x);
    if (!isnan(result)) {
        printf("tan(%f) = %f\n", x, result);
    }

    return 0;
}

//Составьте программу вычисления произведения,
//разности квадратов и удвоенной суммы значений двух функций
double F1(double x) {
    double y = 0;
    if (x >= 3) {
        y = x * x + 3 * x + 9;
    }
    else {
        1 / (pow(x, 3) + 3);
    }
    return y;
}

double F2(double x) {
    return x * exp(sin(pow(x, 2)));
}

void Print(double x1, double x2) {
    printf("Произведение функций F1 = %lf и F2 = %lf равно %lf\n", x1, x2, x1 * x2);
    printf("Удвоенная сумма функций F1 = %lf и F2 = %lf равно %lf\n", x1, x2, 2* x1 + 2 * x2);
    printf("Разность квадратов функций F1 = %lf и F2 = %lf равно %lf\n", x1, x2, fabs(x1*x1 - x2*x2));
}

int Task1() {
    setlocale(LC_ALL, "Rus");
    double x,x1,x2;
    printf("Введите значение х:");
    scanf_s("%lf", &x);
    x1 = F1(x);
    x2 = F2(x);
    Print(x1, x2);
    return 0;
}



//Cоставьте программу, которая вычисляет математическую функцию  
//sin(x) тремя различными способами:
double Sin2(double x,int k) {
    double sinx = 0;
    for (int i = 0; i < k; i++) {
        sinx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i - 1) / Fact(2 * i - 1);
    }
    return sinx;
}

int Fact(int f) {
    int factorial = 1;
    for (int j = 1; j <= f; j++) factorial *= j;
    return factorial;
}

double Sin3(double x, double eps) {
    double ans = 0;
    int i = 0;
    double term = 0;
    /*printf("\n|  N  |    sin_N    |  отклонение |");*/
    do {
        /*printf("\n|  %d  |  %+.6f  | %+.5e|", i, term, sin(x) - ans);*/
        term = (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / Fact(2 * i + 1);
        ans += term;
        i++;
    } while (fabs(term) > eps);
    return ans;
}

double sin_N(double x, int n) {
    double sinx = 0;
    printf("\n|   N   |    sin_N    |  отклонение |");
    for (int i = 1; i < n + 1; i++) {
        \
            printf("\n|   %2d  |  %+.6f  | %+.5e|", i, sinx, sin(x) - sinx);
        sinx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / Fact(2 * i + 1);
    }
    return sinx;
}

double func_arcsin(double x) {
    double term = x;  // Текущий член ряда
    double arcsin = term;  // Начальное значение (первый член)
    double numerator = x * x; // Квадрат x для удобства
    double denominator = 1.0; // Знаменатель
    double n = 1.0; // Переменная для вычисления коэффициентов
    const double EPS = 1e-9; // Точность

    // Пока текущий член больше заданной точности
    for (int i = 1; fabs(term) > EPS; ++i) {
        n += 2; // Увеличиваем число
        denominator *= (2 * i) * (2 * i + 1); // Расчет знаменателя (накапливаем произведение)
        term = numerator * term / denominator; // Следующий член
        arcsin += term; // Добавляем к сумме
    }

    return arcsin;
}

int Task2() {
    setlocale(LC_ALL, "Rus");
    double x;
    puts("Введите х в радианах(x <= |6,28|)  ");
    scanf_s("%lf", &x);
    printf("Синус с использованием библиотеки: %f\n", sin(x));
    int k;
    printf("Введите значение k:");
    scanf_s("%d", &k);
    printf("Синус с использованием разложения в ряд Тейлора: %lf\n", Sin2(x, k));
    double eps;
    printf("Введите значение eps:");
    scanf_s("%lf", &eps);
    printf("Синус через ряд Маклорена(ввод точности) равен %lf\n", Sin3(x, eps));

    sin_N(x, k);

    printf("\nАрксинус с использованием разложения в ряд: %lf\n", func_arcsin(sin(x)));
    return 0;
}


//ПЛОЩАДЬ
int area_square(int r)
{
    return r * r * 4;
}

//РИСОВАНИЕ КВАДРАТА
void draw_square(int r)
{
    int side = r * 2;
    char symbol = '*';

    for (int i = 0; i < side; ++i) {
        if (i == 0 || i == side - 1) {
            for (int j = 0; j < side; ++j) {
                printf("%c ", symbol);
            }
            printf("\n");
        }
        else {
            printf("%c", symbol);
            for (int j = 2; j < side * 2 - 1; ++j) {
                printf(" ");
            }
            printf("%c\n", symbol);
        }
    }
}
//РИСОВАНИЕ КВАДРАТА другими символами
void draw_square_w_s(int r, char symbol)
{
    int side = r * 2;

    for (int i = 0; i < side; ++i) {
        if (i == 0 || i == side - 1) {
            for (int j = 0; j < side; ++j) {
                printf("%c ", symbol);
            }
            printf("\n");
        }
        else {
            printf("%c", symbol);
            for (int j = 2; j < side * 2 - 1; ++j) {
                printf(" ");
            }
            printf("%c\n", symbol);
        }
    }
}

void name(int a)
{
    switch (a) {
    case 0: {
        printf("Неизвестна");
        return;
    }
    case 1: {
        printf("Точка");
        return;
    }
    case 2: {
        printf("Прямая");
        return;
    }
    case 3: {
        printf("Треугольник");
        return;
    }
    case 4: {
        printf("Четырехугольник");
        return;
    }
    default:
        printf("Многосторонник");
    }
}

int HomeWork() {
    setlocale(LC_ALL, "Rus");
    int r, a, number;
    char c;
    printf("1 - Рассчитать площадь\n2 - Вывести определение фигуры\n3 - Нарисовать фигуру\n ");
    scanf_s("%d", &number);

    switch (number) 
    {
        case 1: {
        printf("Введите радиус: ");
        scanf_s("%d", &r);
        printf("Площадь: %d", area_square(r));
        break;
        }
        case 2: {
        printf("Введите количество сторон фигуры: ");
        scanf_s("%d", &a);
        printf("Фигура с %d сторонами - ", a);
        name(a);
        break;
        }
        case 3: {
        printf("Введите радиус и символ: ");
        scanf_s("%d", &r);
        scanf_s("%c", &c);
        printf("Рисование квадрата с помощью *:\n");
        draw_square(r);
        printf("\n\nРисование квадрата с помощью введенного символа:\n");
        draw_square_w_s(r, c);
        }
    }
    return 0;
}
