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
        puts("\n������� ����� ����� ");
        scanf_s("%d", &number);


        for (int i = 10; i > 0; i *= 10) {
            if (number >= i) {
                countNumber++;
            } 
            else
                break;
        }
        printf("����� ���� ����� %d", countNumber);

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

        //����� �������
        printf("\n1) ���������� ���� 3 � ����� ����� %d", counter1);
        printf("\n2) ����� ���������� ��������� ����� ����� %d", counter2);
        printf("\n3) ����� ������ ����� ����� %d", counter3);
        printf("\n4) ���������� ���� ������ 5 ����� %d", counter4);
        printf("\n5) ����� �������� ���� ����� %d", counter5);
        printf("\n6) ����� ���� ������� ��� ������ 7 ����� %d", counter6);
        printf("\n7) ������������ ���� ���� ����� %d", counter7);
        printf("\n8) ������������ ������ � ������������� ���� ����� %d", counter8);
        printf("\n9) ����� ������ ����, �������� ���������, ����� %d", counter9);
        if (counter10 != 0)printf("\n10) ����� ������������� �����: %d � %d ", counter10, counter10); else printf("\n10) ����� ������������� ���");
        if (counter11 == var11)printf("\n11) ����� ������ � ������ �������� ����� "); else printf("\n11) ����� ������ � ������ �������� �� �����");
        printf("\n12) ������������ ���� ����, ������ � �������� �������� ����� %d", counter12 * var12);

        getchar();
        printf("\n\n���������� ? (�� - y, ��� - n)");
        if ((a = getchar()) == 'n')break;


    }
}



double SideLength(int a, int b, int g) {
    // ����������� ���� g �� �������� � �������
    double g_rad = g * (M_PI / 180.0);
    // ���������� ����� ������� ������� �� ������� ���������
    double c = sqrt(a * a + b * b - 2 * a * b * cos(g_rad));
    return round(c);
}

int Picher(char ch, int A, int B, int C, int D) {
    // ��������� ������������ ������� ��� ���������
    int max_height = (A > C) ? A : C; // ������������ ������
    int max_width = (B > D) ? B : D; // ������������ ������
    int F = abs(A - C);
    int H = abs(B - D);
    // ������ ��������������� �� �������� ����������
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
        printf("������� ������ ������� ������ ��������: ");
        scanf_s("%c", &ch);
        printf("������� ������ ���������: ");
        scanf_s("%d", &d1);
        printf("������� ������ ���������: ");
        scanf_s("%d", &d2);
        printf("������� ���� � �������� : ");
        scanf_s("%d", &g);
        if (g < 180) {

            int d1_d = d1 / 2;
            int d2_d = d1 / 2;

            //������� ����������������
            int A, B, C, D;
            A = SideLength(d1_d, d2_d, g);
            B = SideLength(d1_d, d2_d, 180 - g);
            C = SideLength(d1_d, d2_d, g);
            D = SideLength(d1_d, d2_d, 180 - g);
            Picher(ch, A, B, C, D);
        } 
        printf("\n������� ����������? ������� ����� �����\n");
        char a = getchar();
        if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' || a == '0') break;
    }
}

