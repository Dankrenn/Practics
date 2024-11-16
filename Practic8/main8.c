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
    //����������� 10 �������� '*' � �������������� ����� for
    for (int start = 1; start <= 10; start++)
    {
        printf("%c", "*");
    }

    //��������� ���������, ������������ ����������� ����� 
    // ���������� ���������� �������� � ���� ��������.
    int count = 0;
    char ch = '*';
    printf("\n������� ����� ��������: ");
    scanf_s("\n%d", &count);

    printf("������� ������������ ������: ");
    scanf_s("\n%c", &ch);
    for (int start = 1; start <= count; start++)
    {
        printf("%c", ch);
    }

    printf("\n");
    //*) ����������� � ������ �\��� � ����� ������ '+';
    for (int start = 1; start <= count; start++)
    {
        printf("%c", ch);
        if (start + 1 > count)
        {
            printf("%c", "+");
        }
    }

    printf("\n");
    //**) ����������� ��������� ����� ��������, � ������ �������� ������
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
    //***) ��������� ����� ������� ������� ��������������� ����!
    for (int start = 1; start <= count; start++)
    {
        printf("%c", ch);
        printf("%c", "!");
    }

    return 0;
}

int Task1() {
    //��������� ��� ���������� ����� 2 ����� �� m �� n 
    setlocale(LC_ALL, "Rus");
    int n, m, sum = 0;
    printf("������� ����� 1: ");
    scanf_s("\n%d", &m);
    printf("������� ����� 2: ");
    scanf_s("\n%d", &n);
    for (int i = m; i <= n; i++)
    {
        sum += i;
    }
    printf("����� �����: %d\n", sum);

    printf("\n");
    //���������� � ������� ��� �������� 2 � ������� n
    for (int i = 0; i <= n; i++)
    {
        double sum2 = pow(2, i);
        double res = sum2 / 1024;

        //������������ ������ ��� ������� �������� ���� : 2^3 = 8 + 
        //��������� �������� �� ������� ���� +
        //������������ ���������, ����� ��� �������� ������� 2 �� 
        //��������� ������ ����� m � �������� ��������� c ��������� 0.1, 
        printf("2^%2d = %5.1f K\n", i, res);
    }


    return 0;
}


// �� ���������� ������������ ���� ������������� ����� � ��������� ������� 
// � ��������� ��� �������� ���������, �������� ������� � ������������
int Task2() {
    //������� ������������� � ������������ �����
    setlocale(LC_ALL, "Rus");

    // � ��������  ����������� � ����� ������� ����������� �������. 
    printf("y = 1.8x^2 - sin10x �������� �� 0.2 �� 2.2\n");

    //������������ ����������� ����� �������� ���� ���������.
    double n, y = 0;
    printf("������� �������� ���� ���������: ");
    scanf_s("\n%f", &n);

    for (double x = 0.2; x <= 2.2; x += n)
    {
        y = 1.8 * pow(x, 2) - sin(10 * x); // exp(log(a) * 2) ��� ��� �������� ������
        //���������� �������� � ���� �������.
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



//�� ���������� ������� ��� ��� � ����� �� ��� ��������� 
// � �� �� ����� ������� ���� ������� ����� ��������� �������� 
//
int HomeWork() {
    //��������� � �������������� ����� for �������� ��� ��������� N
    setlocale(LC_ALL, "Rus");
    int n;
    double res = 0;
    printf("������� �������� n: ");
    scanf_s("%d", &n);
    res = chet(n);
    printf("���������: %f", res);
    return 0;
}
