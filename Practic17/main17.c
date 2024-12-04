#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	//Task1();
	Task2();
	//Task3();
	//HomeWork();
	return 0;
}

void full_elements(double* ptr_array, int n) {
	printf("y = 1.8x^2 - sin(10x), интервал от 0.2 до 2.2\n");

	double z = 0;
	printf("¬ведите значение шага табул€ции: ");
	scanf_s("%lf", &z);

	for (int i = 0; i < n; i++) {
		double x = 0.2 + i * z; // шаг от 0.2 с шагом z
		ptr_array[i] = 1.8 * pow(x, 2) - sin(10 * x);
		printf("%lf\n", ptr_array[i]);
	}
}

void CalcNabor(int* ptr_array, int n) {
	for (int i = 0; i < n; i++)
	{
		int c;
		printf("a[%d] = ", i);
		scanf_s("%d", &c);
		ptr_array[i] = c;
	}
}

void put_elements(int* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", ptr_array[i]);
	}
}

//пузырьком
void sort_buble(int* ptrarr, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (ptrarr[i] > ptrarr[i + 1]) {
				int b = ptrarr[i];
				ptrarr[i] = ptrarr[i + 1];
				ptrarr[i + 1] = b;
			}
		}
	}
}

//шейкером
void sort_sheker(int* ptrarr, int n) {
	int left = 0, right = n - 1;
	int flag = 1;
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (ptrarr[i] > ptrarr[i + 1]) 
			{
				int b = ptrarr[i];
				ptrarr[i] = ptrarr[i + 1];
				ptrarr[i + 1] = b;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (ptrarr[i - 1] > ptrarr[i]) // если предыдущий элемент больше текущего,
			{            // мен€ем их местами
				int b = ptrarr[i];
				ptrarr[i] = ptrarr[i - 1];
				ptrarr[i - 1] = b;
				flag = 1;
			}
		}
		left++;
		if (flag == 0) break;
	}
}

//выбором
void sort_select(int* ptrarr, int n) {
	for (int i = 0; i < n; i++)
	{
		int minPosition = i;
		for (int j = i + 1; j < n; j++)
		{
			if (ptrarr[minPosition] > ptrarr[j])
			{
				minPosition = j;
				int b = ptrarr[minPosition];
				ptrarr[minPosition] = ptrarr[i];
				ptrarr[i] = b;
			}
		}		
	}
}

//вставка
void sort_insert(int* ptrarr, int n) {
	for (int i = 1; i < n; i++) {
		int key = ptrarr[i];
		int j = i - 1;
		while (j >= 0 && ptrarr[j] > key) {
			ptrarr[j + 1] = ptrarr[j];
			j--;
		}
		ptrarr[j + 1] = key;
	}
}

int Task1() {
	int ptr_array[100] = {3,6,5,2,8,7,5,3,9,8,0};
	int size = 11;
	//printf("¬ведите размер массива: ");
	//scanf_s("%d", &size);

	//CalcNabor(ptr_array, size);
	//printf("\n");
	put_elements(ptr_array, size);
	printf("\n");
	sort_buble(ptr_array, size);
	printf("\n");
	sort_sheker(ptr_array, size);
	printf("\n");
	sort_select(ptr_array, size);
	sort_insert(ptr_array, size);
	put_elements(ptr_array, size);
	printf("\n");


	return 0;
}
int Task2() {
	double ptr_array[50];
	int size = 0;
	printf("¬ведите размер массива: ");
	scanf_s("%d", &size);

	full_elements(ptr_array, size);
	printf("\n");

	clock_t t;
	t = clock();
	sort_insert((int*)ptr_array, size); 
	t = clock() - t; 

	double time_taken = ((double)t) / CLOCKS_PER_SEC; 
	printf("\n¬рем€ выполнени€ сортировки вставками: %.9f секунд\n", time_taken);
	printf("\nќтсортированный массив:\n");
	put_elements(ptr_array, size);
	return 0;
}

int Task3() {
	printf(" _  _         _     \n");
	printf("| | _|  | |  | | |_|\n");
	printf("|_| |_ .| |. |_|   |\n");
	printf("\n");
	return 0;
}

int HomeWork() {
	printf("       ______\n");
	printf("      /|_||_\\`.__\n");
	printf("     (   _    _ _\\\n");
	printf("      `-(_)--(_)-'\n");
	printf("\n");
	return 0;
}