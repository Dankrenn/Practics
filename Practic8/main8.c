#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h.>

int main()
{
    //Task0();
    //Task1();
    Task2();
    //HomeWork();
    return 0;
}
int Task0() {
    setlocale(LC_ALL, "Rus");
    //Напечатайте 10 символов '*' с использованием цикла for
    for (int start = 1; start <= 10; start++)
    {
        printf("%c", "*");
    }

    //Исправьте программу, предусмотрев возможность ввода 
    // количества печатаемых символов и вида символов.
    int count = 0;
    char ch = '*';
    printf("\nВведите число символов: ");
    scanf_s("\n%d", &count);

    printf("Введите обозначающий символ: ");
    scanf_s("\n%c", &ch);
    for (int start = 1; start <= count; start++)
    {
        printf("%c", ch);
    }

    printf("\n");
    //*) напечатайте в начале и\или в конце символ '+';
    for (int start = 1; start <= count; start++)
    {
        printf("%c", ch);
        if (start + 1 > count)
        {
            printf("%c", "+");
        }
    }

    printf("\n");
    //**) напечатайте полстроки одним символом, а вторую половину другим
    for (int start = 1; start <= count; start++)
    {
        if (start >= count / 2)
        {
            printf("%c", "+");
        }
        else
        {
            printf("%c", ch);
        }
    }

    printf("\n");
    //***) печатайте после каждого символа восклицательный знак!
    for (int start = 1; start <= count; start++)
    {
        printf("%c", ch);
        printf("%c", "!");
    }

    return 0;
}

int Task1() {
    //программа для вычисления суммы 2 чисел от m до n 
    setlocale(LC_ALL, "Rus");
    int n, m, sum = 0;
    printf("Введите число 1: ");
    scanf_s("\n%d", &m);
    printf("Введите число 2: ");
    scanf_s("\n%d", &n);
    for (int i = m; i <= n; i++)
    {
        sum += i;
    }
    printf("Сумма равна: %d\n", sum);

    printf("\n");
    //напечатать в столбик все значения 2 в степени n
    for (int i = 0; i <= n; i++)
    {
        double sum2 = pow(2, i);
        double res = sum2 / 1024;

        //сформировать запись для каждого значения вида : 2^3 = 8 + 
        //выровнять значения по правому краю +
        //преобразуйте программу, чтобы она выводила степени 2 до 
        //заданного целого числа m и выводила результат c точностью 0.1, 
        printf("2^%2d = %5.1f K\n", i, res);
    }


    return 0;
}


// не получается организовать ввод пользователем числа с плавающей запятой 
// в остальном код работает нормально, возможно связано с локальностью
int Task2() {
    //функция табулирования с произвольным шагом
    setlocale(LC_ALL, "Rus");

    // В качестве  приглашения к вводу вывести вычисляемую функцию. 
    printf("y = 1.8x^2 - sin10x интервал от 0.2 до 2.2\n");

    //Организовать возможность ввода значения шага табуляции.
    double n, y = 0;
    printf("Введите значение шага табуляции: ");
    scanf_s("\n%f", &n);

    for (double x = 0.2; x <= 2.2; x += n)
    {
        y = 1.8 * pow(x, 2) - sin(10 * x); // exp(log(a) * 2) так как ругается линтер
        //Результаты оформить в виде таблицы.
        printf("____________________\n");
        printf("| %1.1f | %5.5f |\n", x, y);
        if (x += 1 >= 2.2)
        {
            printf("____________________\n");
        }
    }
    return 0;
}




double chet(int n)
{
    double sinx = 0;
    double res = 0;
    if (n > 0) {

        for (int i = 1; i <= n; i++)
        {
            sinx += sin(i);
        }
        res = 1 / sinx + chet(n - 1);
    }
    else {
        res = 0;
    }
    return res;
}



//не получается сделать так как в языке си нет рефлексии 
// и мы не можем сделать цикл который будет правильно работать 
//
int HomeWork() {
    //Вычислите с использованием цикла for значение для заданного N
    setlocale(LC_ALL, "Rus");
    int n;
    double res = 0;
    printf("Введите значение n: ");
    scanf_s("%d", &n);
    res = chet(n);
    printf("Результат: %f", res);
    return 0;
}
