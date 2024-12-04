#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	//Task1();
	//Task2();
	HomeWork();
	return 0;
}



int Task1() {
	int A[100][100];
	int s1, s2;
	printf("������� ���������� ����� ������� : ");
	scanf_s("%d", &s1);
	printf("������� ���������� ������� ������� : ");
	scanf_s("%d", &s2);
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			A[i][j] = i + j;
			printf("[%d][%d] %d ", i, j, A[i][j]);
		}
		printf("\n");
	}
	//�������� ������� �� ������ �������, �������������:
	//� ������������� �������(����� �������).
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			if (i == s1 - 2 && j == s2 - 2)
			{
				printf("[%d][%d] %d ", i, j, A[i][j]);
			}
		}
	}

	printf("\n");
	// ����� ������� �������:
	//�) �������� �������� ����� ���������, ������� �� ���������.
	double sc;
	printf("������� ����� ������� ����� ������������: ");
	scanf_s("%lf", &sc);

	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			if (i == j) {
				if (A[i][j] == sc) {
					printf("[%d][%d] %d ", i, j, A[i][j]);
				}
			}
		}
		printf("\n");
	}

	return 0;
}

#define ROWS 7
#define COLS 7

// ������� ��� ������ �������
void printArray(int arr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

// ������� ��� ���������������� �������
void transposeArray(int arr[ROWS][COLS], int trans[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			trans[j][i] = arr[i][j];
		}
	}
}

// ����� 3 ������ ������� �� ����������� 25
int sumThirdRow(int arr[ROWS][COLS]) {
	int rez = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (i == 3 && arr[i][j] <= 25 && arr[i][j] > 0)
			{
				rez += arr[i][j];
			}
		}
	}
	return rez;
}

//������� ����� ��� ���������� �������� ��������� � �������
int countStrPairs(int arr[ROWS][COLS]) {
	int rowPairs = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) rowPairs++;
		}
	}
	return rowPairs;
}
//������� ����� ��� ���������� �������� ��������� � ��������
int countColPairs(int arr[ROWS][COLS]) {
	int colPairs = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			if (arr[i][j] == arr[i + 1][j]) colPairs++;
		}
	}
	return colPairs;
}

//����� ������������� ��������
void MaxCoordinat(int arr[ROWS][COLS]) {
	int max = arr[0][0];
	int maxRow = 0, maxCol = 0;

	for (int j = 0; j < COLS; j++) {
		for (int i = 0; i < ROWS; i++) {
			if (arr[i][j] >= max) {
				max = arr[i][j];
				maxRow = i;
				maxCol = j;
			}
		}
	}
	printf("������������ �������: %d, ����������: [%d][%d]\n", max, maxRow, maxCol);
}


// ������ ����� ���������� ��� �������!!!!!!!!!!!!!!!
int Task2() {
	int array[ROWS][COLS] =
	{
		{ -3,  5,  0, -8, 10, -6,  4 },
		{  7,  7,  9,  1, -5,  3, -10 },
		{  6, -2, -7,  8, -1, 10,  0 },
		{ -9,  4, -5,  3,  2, -8,  7 },
		{ 10,  1, -6,  5, -4,  9,  8 },
		{  1, -3,  2, -7, -4,  6, -1 },
		{  1,  0,  3,  4,   7, -2, -10 }
	};
	int trans[ROWS][COLS];
	printf("�������� ������:\n");
	printArray(array);

	transposeArray(array, trans);
	printf("\n����������������� ������:\n");
	printArray(trans);

	//��������� ����� ��������� ������� ������ �������, �� ����������� 25;
	int rez = sumThirdRow(array);
	printf("����� ��������� ������� ������, �� ����������� 25: %d\n", rez);
	////������� ����� ��� ���������� �������� ���������
	int strpar = countStrPairs(array);
	int colpar = countStrPairs(array);
	printf("��� ���������� ��������� � �������: %d\n", strpar);
	printf("��� ���������� ��������� � ��������: %d\n", colpar);
	//���������� ���������� ������������� ��������. 
	MaxCoordinat(array);
	return 0;
}





#define STUDENTS 20
#define SUBJECTS 10

// ������� ��� ���������� ������� ������ �� ������
double calculateAverage(int list[STUDENTS][SUBJECTS]) {
	int totalSum = 0;
	int totalCount = STUDENTS * SUBJECTS;

	// ��������� ��� ������
	for (int i = 0; i < STUDENTS; i++) {
		for (int j = 0; j < SUBJECTS; j++) {
			totalSum += list[i][j];
		}
	}

	// ��������� ������� ������
	return (double)totalSum / totalCount;
}

int HomeWork() {
	//  � ��������� ������� � ������� �������� ���������� ��
	//  ������� ������� �� 20 �������� ������ �� ���� ��� ����� ��������(�
	//	������ ������ � ���������� �� ������� ������� �������, �� ������ �
	//	������� � �.�.).����� ����� ��������� ����� 10. ���������� �������
	//	������ �� ������ � �����.
	int grades[STUDENTS][SUBJECTS] = {
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{3, 2, 3, 3, 3, 2, 3, 3, 2, 3},
		{3, 2, 3, 3, 3, 2, 3, 3, 2, 3},
		{3, 2, 3, 3, 3, 2, 3, 3, 2, 3},
		{3, 2, 3, 3, 3, 2, 3, 3, 2, 3},
		{3, 2, 3, 3, 3, 2, 3, 3, 2, 3},
		{4, 5, 4, 4, 4, 5, 3, 4, 5, 4},
		{4, 5, 4, 4, 4, 5, 3, 4, 5, 4},
		{4, 5, 4, 4, 4, 5, 3, 4, 5, 4},
		{4, 5, 4, 4, 4, 5, 3, 4, 5, 4},
		{4, 5, 4, 4, 4, 5, 3, 4, 5, 4},
	};

	double avgrage = calculateAverage(grades);
	printf("������� ������ �� ������: %.2f\n", avgrage);

	return 0;
}
