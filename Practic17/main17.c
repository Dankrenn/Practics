#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
	setlocale(LC_CTYPE, "RUS");
	Task1();
	Task2();
	HomeWork();
	return 0;
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

//���������
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

//��������
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
			if (ptrarr[i - 1] > ptrarr[i]) // ���� ���������� ������� ������ ��������,
			{            // ������ �� �������
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

//�������
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

//�������
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
	printf("������� 1.  ����������� ������� ���������� ������� ����� ����� �� ���������� ���������\n");
	int ptr_array1[100] = {3,6,5,2,8,7,5,3,9,8,0};
	int ptr_array2[100] = { 3,6,5,2,8,7,5,3,9,8,0 };
	int ptr_array3[100] = { 3,6,5,2,8,7,5,3,9,8,0 };
	int ptr_array4[100] = { 3,6,5,2,8,7,5,3,9,8,0 };
	int size = 11;

	put_elements(ptr_array1, size);
	printf("\n");
	printf("���������\n");
	sort_buble(ptr_array1, size);
	put_elements(ptr_array1, size);
	printf("\n");
	printf("��������\n");
	sort_sheker(ptr_array2, size);
	put_elements(ptr_array2, size);
	printf("\n");
	printf("������� �������\n");
	sort_select(ptr_array3, size);
	put_elements(ptr_array3, size);
	printf("��������\n");
	sort_insert(ptr_array4, size);
	put_elements(ptr_array4, size);
	printf("\n");

	printf("������� 1 ���������\n");
	printf("\n");
	return 0;
}

void full_elements(int* ptr_array, int n) {
	printf("y = 1.8x^2 - sin(10x), �������� �� 0.2 �� 2.2\n");

	double z = 0;
	printf("������� �������� ���� ���������: ");
	scanf_s("%lf", &z);

	for (int i = 0; i < n; i++) {
		int x = 0.2 + i * z; // ��� �� 0.2 � ����� z
		ptr_array[i] = 1.8 * pow(x, 2) - sin(10 * x);
	}
}

int Task2() {
	printf("������� 2.  ����������� ����������� �������� ��� ���������� �������������� ������������� �� ������ ������������� ����������.\n");

	int ptr_array[50];
	int size = 0;
	printf("������� ������ �������: ");
	scanf_s("%d", &size);

	full_elements(ptr_array, size);
	printf("\n");
	printf("\n�������� ������:\n");
	put_elements(ptr_array, size);

	clock_t t;
	t = clock();
	sort_insert(ptr_array, size); 
	double time_taken = clock() - t *1 / CLOCKS_PER_SEC ;
	printf("\n����� ���������� ���������� ���������: %.9f ������\n", time_taken);
	printf("\n��������������� ������:\n");
	put_elements(ptr_array, size);
	printf("������� 2 ���������\n");
	printf("\n");
	return 0;
}


void generate_random_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void compare_sorting_times(int* arr, int size) {
	int arr_copy[MAX_SIZE];

	for (int i = 0; i < size; i++) arr_copy[i] = arr[i];
	clock_t t = clock();
	sort_buble(arr_copy, size);
	double time_taken = clock() - t * 1 / CLOCKS_PER_SEC;
	printf("����� ���������� ����������� ����������: %.9f ������\n", time_taken);

	for (int i = 0; i < size; i++) arr_copy[i] = arr[i];
	t = clock();
	sort_select(arr_copy, size);
    time_taken = clock() - t * 1 / CLOCKS_PER_SEC;
	printf("����� ���������� ���������� �������: %.9f ������\n", time_taken);

	for (int i = 0; i < size; i++) arr_copy[i] = arr[i];
	t = clock();
	sort_sheker(arr_copy, size);
	time_taken = clock() - t * 1 / CLOCKS_PER_SEC;
	printf("����� ���������� ����������� ����������: %.9f ������\n", time_taken);

	for (int i = 0; i < size; i++) arr_copy[i] = arr[i];
	t = clock();
	sort_insert(arr_copy, size);
	time_taken = clock() - t * 1 / CLOCKS_PER_SEC;
	printf("����� ���������� ���������� ���������: %.9f ������\n", time_taken);
}

int HomeWork() {
	printf("��. ��������� �������������� ����������� �� ������ �� ���������\n");
	printf("1) ��������� ������� ���������� (�������, �����������, ����������, ���������) ��� ��������� �������� �������  100, 1000, 10000 ��������\n");

	int sizes[] = { 10, 89, 100 };
	for (int i = 0; i < 3; i++) {
		int size = sizes[i];
		int arr[MAX_SIZE];
		generate_random_array(arr, size);
		printf("\n��������� ���������� ��� ������� ������� %d\n", size);
		compare_sorting_times(arr, size);
	}
	return 0;
}