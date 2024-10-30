#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h.>

int main()
{

    //Task1();
    //Task2();
    HomeWork();
    return 0;
}

#define M_PI            3.14159265358979323846
#define ROW 9
#define COL 9
int Task1() {
   
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; row++) {
        for (col = 1; col <= COL; col++) {
            printf("%5d", col * row);
        }
        printf("\n");
    }

    printf("\n");
    for (row = 1; row <= ROW; row++) {
        for (col = 1; col <= COL; col++) {
            if (col <= row) {
                printf("%5d", col * row);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("\n");
    for (row = 1; row <= ROW; row++) {
        for (col = 1; col <= COL; col++) {
            printf("%2d + %2d = %2d", col, row, col + row);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}



int Task2() {
    while (1) {
        char a;

        int number, countNumber = 1;
        puts("\nВведите целое число ");
        scanf_s("%d", &number);


        for (int i = 10; i > 0; i *= 10) {
            if (number >= i) {
                countNumber++;
            } 
            else
                break;
        }
        printf("Число цифр равно %d", countNumber);

        int grad, VarNum = number, AddVar;
        int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 1, counter8 = 1, counter9 = 0, counter10 = 0, counter11 = 0, counter12 = 0;
        int var = number % 10, var10 = 0, var11 = 0, var12 = 0;


        for (int i = 0; i < countNumber; i++) {
            grad = pow(10, i);
            if (VarNum > 10) {
                VarNum = (number / grad);
                AddVar = VarNum % 10;
            }
            else AddVar = number % 10;

            //1
            if (AddVar == 3)counter1++;
            //2
            if (AddVar == var)counter2++;

            //3
            if (AddVar % 2 == 0)counter3++;

            //4
            if ((AddVar > 5)) counter4++;

            //5
            if (AddVar % 2 != 0)counter5 += AddVar;

            //6
            if ((AddVar >= 7)) counter6 += AddVar;

            //7
            if ((AddVar > 0)) counter7 *= AddVar;

            //8
            if ((i == 1 || i == countNumber - 2)) counter8 *= AddVar;

            //9
            if (AddVar % 2 == 0 && i > 0)counter9 += AddVar;

            //10
            if (AddVar == var10)counter10 = AddVar;
            var10 = AddVar;

            //11
            if (i >= countNumber / 2)counter11 += AddVar; else var11 += AddVar;

            //12
            if (AddVar % 2 == 0)counter12 += AddVar; else var12 += AddVar;
        }

        //Вывод ответов
        printf("\n1) Количество цифр 3 в числе равно %d", counter1);
        printf("\n2) Число повторений последней цифры равно %d", counter2);
        printf("\n3) Число четных чисел равно %d", counter3);
        printf("\n4) Количество цифр больше 5 равно %d", counter4);
        printf("\n5) Сумма нечетных цифр равна %d", counter5);
        printf("\n6) Сумма цифр больших или равных 7 равна %d", counter6);
        printf("\n7) Произведение всех цифр равно %d", counter7);
        printf("\n8) Произведение второй и предпоследней цифр равно %d", counter8);
        printf("\n9) Сумма четных цифр, исключая последнюю, равно %d", counter9);
        if (counter10 != 0)printf("\n10) Рядом расположенные цифры: %d и %d ", counter10, counter10); else printf("\n10) Рядом располоденные нет");
        if (counter11 == var11)printf("\n11) Сумма первой и второй половины равны "); else printf("\n11) Сумма первой и второй половины не равны");
        printf("\n12) Произведение сумм цифр, четных и нечетных разрядов равно %d", counter12 * var12);

        getchar();
        printf("\n\nПродолжить ? (Да - y, нет - n)");
        if ((a = getchar()) == 'n')break;


    }
}



double SideLength(int a, int b, int g) {
    // Преобразуем угол g из градусов в радианы
    double g_rad = g * (M_PI / 180.0);
    // Вычисление длины третьей стороны по теореме косинусов
    double c = sqrt(a * a + b * b - 2 * a * b * cos(g_rad));
    return round(c);
}

int Picher(char ch, int A, int B, int C, int D) {
    // Определим максимальные размеры для рисования
    int max_height = (A > C) ? A : C; // Максимальная высота
    int max_width = (B > D) ? B : D; // Максимальная ширина
    int F = abs(A - C);
    int H = abs(B - D);
    // Рисуем четырехугольник по заданным параметрам
    for (int i = 1; i <= max_height; i++) {
        for (int j = 1; j <= max_width; j++) {
            if (i == 1) {
                printf("%c", ch);
            }
            if (i == max_width && j == 1) {
                for (int k = 1; k <= max_width - H; k++) {
                    printf("%c", ch);
                }
            }
        }
        printf("\n");
        if (i == max_height) break;
        if (i + 1 == max_height) continue;
        printf("%c", ch);
      
    }
    return 1;

}

int HomeWork() {

    while (1) {
        setlocale(LC_ALL, "Rus");
        char ch;
        int d1, d2, g;
        printf("Введите символ которым хотите рисовать: ");
        scanf_s("%c", &ch);
        printf("Введите первую диагональ: ");
        scanf_s("%d", &d1);
        printf("Введите вторую диагональ: ");
        scanf_s("%d", &d2);
        printf("Введите угол в градусах : ");
        scanf_s("%d", &g);
        if (g < 180) {

            int d1_d = d1 / 2;
            int d2_d = d1 / 2;

            //стороны четерехугольника
            int A, B, C, D;
            A = SideLength(d1_d, d2_d, g);
            B = SideLength(d1_d, d2_d, 180 - g);
            C = SideLength(d1_d, d2_d, g);
            D = SideLength(d1_d, d2_d, 180 - g);
            Picher(ch, A, B, C, D);
        } 
        printf("\nЖелаете продолжить? Нажмите любую цифру\n");
        char a = getchar();
        if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' || a == '0') break;
    }
}

