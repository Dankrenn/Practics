#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	Task1();
	Task2();
	HomeWork();
	return 0;
}



int Task1() {
	printf("Задание 1. Создать и заполнить статический двухмерный массив, размерность которого задается пользователем.\n ");
	printf("Каждый элемент задаетс по сумме индексов этого элемента\n ");
	int A[100][100];
	int s1, s2;
	printf("Введите количество строк массива : ");
	scanf_s("%d", &s1);
	printf("Введите количество колонок массива : ");
	scanf_s("%d", &s2);
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			A[i][j] = i + j;
			printf("[%d][%d] %d ", i, j, A[i][j]);
		}
		printf("\n");
	}
	printf("Отдельно вывести на печать элемент, расположенный в предпоследнем столбце(любой элемент)\n ");
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			if (i == s1 - 2 && j == s2 - 2)
			{
				printf("[%d][%d] %d ", i, j, A[i][j]);
			}
		}
	}
	printf("\n");

	printf("Найти заданное значение среди элементов, лежащих на диагонале.\n ");
	double sc;
	printf("Введите число которое будет сравниваться: ");
	scanf_s("%lf", &sc);

	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			if (i == j) {
				if (A[i][j] == sc) {
					printf("[%d][%d] %d ", i, j, A[i][j]);
				}
			}
		}
	}
	printf("\n");
	printf("ЗАДАНИЕ 1 ЗАВЕРШЕНО.\n ");
	printf("\n");
	return 0;
}

#define ROWS 7
#define COLS 7

// Функция для вывода массива
void printArray(int arr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

// Функция для транспонирования массива
void transposeArray(int arr[ROWS][COLS], int trans[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			trans[j][i] = arr[i][j];
		}
	}
}

// сумма 3 строки массива не превыщающих 25
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

//найдите число пар одинаковых соседних элементов в строках
int countStrPairs(int arr[ROWS][COLS]) {
	int rowPairs = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) rowPairs++;
		}
	}
	return rowPairs;
}
//найдите число пар одинаковых соседних элементов в столбцах
int countColPairs(int arr[ROWS][COLS]) {
	int colPairs = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			if (arr[i][j] == arr[i + 1][j]) colPairs++;
		}
	}
	return colPairs;
}

//поиск максимального элемента
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
	printf("Максимальный элемент: %d, координаты: [%d][%d]\n", max, maxRow, maxCol);
}



int Task2() {
	printf("Задание 2. Составьте программу, которая формирует двумерный массив целых чисел от -10 до 10 (размерностью 7 на 7)  и транспонирует его (заменяет строки на столбцы).  \n ");

	int array[ROWS][COLS] =
	{
		{ -3,  5,  0, -8, 10, -6,  4 },
		{  7,  7,  9,  1, -5,  3, -10 },
		{  6, -2, -7,  8, -1, 10,  0 },
		{ -9,  4, -5,  3,  2, -8,  7 },
		{ 10,  1, -6,  5, -4,  9,  8 },
		{  1, -3,  4, -7, -4,  6, -1 },
		{  1,  0,  3,  4,   7, -2, -10 }
	};
	int trans[ROWS][COLS];
	printf("Исходный массив:\n");
	printArray(array);

	transposeArray(array, trans);
	printf("\nТранспонированный массив:\n");
	printArray(trans);

	printf("Вар 2. Вычислить сумму элементов третьей строки массива, не превышающих 25;\n");
	int rez = sumThirdRow(array);
	printf("Сумма элементов третьей строки, не превышающих 25: %d\n", rez);
	printf("Найдите число пар одинаковых соседних элементов\n");

	int strpar = countStrPairs(array);
	int colpar = countStrPairs(array);
	printf("Пар одинаковых элементов в строках: %d\n", strpar);
	printf("Пар одинаковых элементов в столбцах: %d\n", colpar);
	printf("\n");
	printf("Определите координаты максимального элемента.\n");
	MaxCoordinat(array);
	printf("ЗАДАНИЕ 2 ЗАВЕРШЕНО.\n");
	printf("\n");
	return 0;
}


#define STUDENTS 20
#define SUBJECTS 10

// Функция для вычисления средней оценки по классу
double calculateAverage(int list[STUDENTS][SUBJECTS]) {
	int totalSum = 0;
	int totalCount = STUDENTS * SUBJECTS;

	// Суммируем все оценки
	for (int i = 0; i < STUDENTS; i++) {
		for (int j = 0; j < SUBJECTS; j++) {
			totalSum += list[i][j];
		}
	}

	// Вычисляем среднюю оценку
	return (double)totalSum / totalCount;
}

int HomeWork() {
	printf("ДЗ.\n ");
	printf("В двумерном массиве в строках хранится информация об.\n ");
	printf("оценках каждого из 20 учеников класса по тому или иному предмету(в.\n ");
	printf("первой строке — информация об оценках первого ученика, во второй —\n ");
	printf("второго и т.д.).Общее число предметов равно 10. Определить среднюю\n ");
	printf("оценку по классу в целом.\n ");

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
	printf("Средняя оценка по классу: %.2f\n", avgrage);
	printf("ДЗ ЗАВЕРШЕНО.\n");
	printf("\n");
	return 0;
}
