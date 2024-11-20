#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h.>

#define M_PI 3.1415926535897932384626
int main()
{
    //Task1();
    //Task2();
    HomeWork();
    return 0;
}


//��������� ��������� ���������� ������������,
//�������� ��������� � ��������� ����� �������� ���� �������
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
    printf("������������ ������� F1 = %lf � F2 = %lf ����� %lf\n", x1, x2, x1 * x2);
    printf("��������� ����� ������� F1 = %lf � F2 = %lf ����� %lf\n", x1, x2, 2* x1 + 2 * x2);
    printf("�������� ��������� ������� F1 = %lf � F2 = %lf ����� %lf\n", x1, x2, fabs(x1*x1 - x2*x2));
}

int Task1() {
    setlocale(LC_ALL, "Rus");
    double x,x1,x2;
    printf("������� �������� �:");
    scanf_s("%lf", &x);
    x1 = F1(x);
    x2 = F2(x);
    Print(x1, x2);
    return 0;
}



//C�������� ���������, ������� ��������� �������������� �������  
//sin(x) ����� ���������� ���������:
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
    /*printf("\n|  N  |    sin_N    |  ���������� |");*/
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
    printf("\n|   N   |    sin_N    |  ���������� |");
    for (int i = 1; i < n + 1; i++) {
        \
            printf("\n|   %2d  |  %+.6f  | %+.5e|", i, sinx, sin(x) - sinx);
        sinx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / Fact(2 * i + 1);
    }
    return sinx;
}

double func_arcsin(double x) {
    double term = x;  // ������� ���� ����
    double arcsin = term;  // ��������� �������� (������ ����)
    double numerator = x * x; // ������� x ��� ��������
    double denominator = 1.0; // �����������
    double n = 1.0; // ���������� ��� ���������� �������������
    const double EPS = 1e-9; // ��������

    // ���� ������� ���� ������ �������� ��������
    for (int i = 1; fabs(term) > EPS; ++i) {
        n += 2; // ����������� �����
        denominator *= (2 * i) * (2 * i + 1); // ������ ����������� (����������� ������������)
        term = numerator * term / denominator; // ��������� ����
        arcsin += term; // ��������� � �����
    }

    return arcsin;
}

int Task2() {
    setlocale(LC_ALL, "Rus");
    double x;
    puts("������� � � ��������(x <= |6,28|)  ");
    scanf_s("%lf", &x);
    printf("����� � �������������� ����������: %f\n", sin(x));
    int k;
    printf("������� �������� k:");
    scanf_s("%d", &k);
    printf("����� � �������������� ���������� � ��� �������: %lf\n", Sin2(x, k));
    double eps;
    printf("������� �������� eps:");
    scanf_s("%lf", &eps);
    printf("����� ����� ��� ���������(���� ��������) ����� %lf\n", Sin3(x, eps));

    sin_N(x, k);

    printf("\n�������� � �������������� ���������� � ���: %lf\n", func_arcsin(sin(x)));
    return 0;
}


//�������
int area_square(int r)
{
    return r * r * 4;
}

//��������� ��������
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
//��������� �������� ������� ���������
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
        printf("����������");
        return;
    }
    case 1: {
        printf("�����");
        return;
    }
    case 2: {
        printf("������");
        return;
    }
    case 3: {
        printf("�����������");
        return;
    }
    case 4: {
        printf("���������������");
        return;
    }
    default:
        printf("��������������");
    }
}

int HomeWork() {
    setlocale(LC_ALL, "Rus");
    int r, a, number;
    char c;
    printf("1 - ���������� �������\n2 - ������� ����������� ������\n3 - ���������� ������\n ");
    scanf_s("%d", &number);

    switch (number) 
    {
        case 1: {
        printf("������� ������: ");
        scanf_s("%d", &r);
        printf("�������: %d", area_square(r));
        break;
        }
        case 2: {
        printf("������� ���������� ������ ������: ");
        scanf_s("%d", &a);
        printf("������ � %d ��������� - ", a);
        name(a);
        break;
        }
        case 3: {
        printf("������� ������ � ������: ");
        scanf_s("%d", &r);
        scanf_s("%c", &c);
        printf("��������� �������� � ������� *:\n");
        draw_square(r);
        printf("\n\n��������� �������� � ������� ���������� �������:\n");
        draw_square_w_s(r, c);
        }
    }
    return 0;
}
