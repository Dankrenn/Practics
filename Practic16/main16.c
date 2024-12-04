#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	//Task1();
	//Task2();
	HomeWork();
	return 0;
}


void full_elements(double* ptr_array, int n) {
	printf("y = 1.8x^2 - sin10x интервал от 0.2 до 2.2\n");

	double z = 0;
	printf("Введите значение шага табуляции: ");
	scanf_s("\n%lf", &z);
	double y[20];
	int i = 0;

	for (double x = 0.2; x <= 2.2; x += z, i++)
	{
		y[i] = 1.8 * pow(x, 2) - sin(10 * x);
	}
	for (int i = 0; i <= strlen(y); i++) {
		if (i < n) {
			ptr_array[i] = y[i];
			printf("%lf\n", ptr_array[i]);
		}
	}
}

//-печать элементов массива
void put_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%lf\n", ptr_array[i]);
	}
}

//-обработка элементов массива(см.инд.вариант  зад. 1.3 в работе 11)
void calc_elements(double* ptr_array, int n) {
	double A[100];
	for (int i = 0; i < n; i++)
	{
		double c;
		printf("a[%d] = ", i + 1);
		scanf_s("%lf", &c);
		A[i] = c;
	}
	for (int i = 0; i < n; i++)
	{
		double c = A[i];
		ptr_array[i] = pow(c, 2);
	}
	return 0;
}

int Task1() {
	double* ptr_array;
	int size = 0;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}
	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	printf("\n");
	calc_elements(ptr_array, size);
	printf("\n");
	put_elements(ptr_array, size);
	free(ptr_array);
	return 0;
}



void CalcNabor(double* ptr_array, int n) {
	for (int i = 0; i < n; i++)
	{
		double c;
		printf("a[%d] = ", i);
		scanf_s("%lf", &c);
		ptr_array[i] = c;
	}
}

// Удаление элемента по индексу
int delete_k(double* ptr_arr, int size, int k) {
    for (int i = k; i < size - 1; i++) {
        ptr_arr[i] = ptr_arr[i + 1];
    }
    return size - 1;
}

// Расчёт среднего арифметического
double calculateAverage(double* list, int size) {
    double totalSum = 0;
    for (int i = 0; i < size; i++) {
        totalSum += list[i];
    }
    return totalSum / size;
}

// Удаление всех элементов меньше среднего арифметического
int deleteAvg(double* ptr_array, int size, double avg) {
    int i = 0;
    while (i < size) {
        if (ptr_array[i] < avg) {
            size = delete_k(ptr_array, size, i);
        }
        else {
            i++;
        }
    }
    return size;
}

// Вставка элемента в массив
double* insert(double* ptr_arr, int* size, int index, double num) {
    int new_size = *size + 1;
    double* ptr_arr_n = (double*)realloc(ptr_arr, new_size * sizeof(double));
    if (ptr_arr_n == NULL) {
        printf("Ошибка выделения памяти\n");
        return ptr_arr;
    }
    ptr_arr = ptr_arr_n;
    for (int i = *size; i > index; i--) {
        ptr_arr[i] = ptr_arr[i - 1];
    }
    ptr_arr[index] = num;
    *size = new_size;
    return ptr_arr;
}

// Поиск первого отрицательного элемента и вставка перед ним
double* searchFirstNegative(double* array, int* size, double num) {
    for (int i = 0; i < *size; i++) {
        if (array[i] < 0) {
            array = insert(array, size, i, num);
            break;
        }
    }
    return array;
}

int Task2() {
    double* ptr_array;
    int size = 0;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    // Выделение памяти для массива
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }

    // Ввод массива
    CalcNabor(ptr_array, size);

    // Вывод исходного массива
    printf("Исходный массив:\n");
    put_elements(ptr_array, size);

    // Удаление всех элементов, меньших среднего арифметического
    double avg = calculateAverage(ptr_array, size);
    printf("Среднее арифметическое: %lf\n", avg);
    size = deleteAvg(ptr_array, size, avg);
    printf("Массив после удаления элементов, меньших среднего:\n");
    put_elements(ptr_array, size);

    // Вставка -999 перед первым отрицательным
    double number = -999;
    ptr_array = searchFirstNegative(ptr_array, &size, number);

    printf("Изменённый массив:\n");
    put_elements(ptr_array, size);
    free(ptr_array);
    return 0;
}

/*
* Для реализации заданий используйте функции, разработанные в
заданиях 1-2.
Сгенерировать три массива со случайными вещественными числами а0,
а1, а2, ..., an, b0, b1, b2 ..., bm, с0, с1,с2, ..., сl, количество элементов случайно в
интервале от 10 до 50. Реализовать функцию, которая возвращает новый
массив (см. инд. Вариант). Все 4 массива вывести на экран.

16. Массив d0, d1, d2, ..., dh в котором большее из аi и bi 
принять в качестве четного элементам , а меньшее из сi и bi 
– в качестве нечетного .
*/

//максимальный размер для d
int size_d(int size1, int size2, int size3) {
    return max(size3, max(size1, size2));
}

// Формирование массива d
void d_elements(double* d, int size_d, double* a, int size1, double* b, int size2, double* c, int size3) {
    for (int i = 0; i < size_d; i++) {
        double ai = (i < size1) ? a[i] : 0; 
        double bi = (i < size2) ? b[i] : 0; 
        double ci = (i < size3) ? c[i] : 0; 

        if (i % 2 == 0) {
            // Чётный элемент — большее из ai и bi
            d[i] = (ai > bi) ? ai : bi;
        }
        else {
            // Нечётный элемент — меньшее из ci и bi
            d[i] = (ci < bi) ? ci : bi;
        }
    }
}

int HomeWork() {
    int size1, size2, size3 , size4;
    double *a, *b, *c, *d;
    printf("Введите размер массива 1 (10:50) ");
    scanf_s("%d", &size1);
    printf("Введите размер массива 2 (10:50) ");
    scanf_s("%d", &size2);
    printf("Введите размер массива 3 (10:50) ");
    scanf_s("%d", &size3);
    size4 = size_d(size1, size2, size3);
    a = (double*)malloc(size1 * sizeof(double));
    b = (double*)malloc(size2 * sizeof(double));
    c = (double*)malloc(size3 * sizeof(double));
    d = (double*)malloc(size4 * sizeof(double));
    if (a == NULL || b == NULL || c == NULL || d == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }
    //ввод массивов
    CalcNabor(a, size1);
    printf("\n");
    CalcNabor(b, size2);
    printf("\n");
    CalcNabor(c, size3);
    printf("\n");
    put_elements(a, size1);
    printf("\n");
    put_elements(b, size2);
    printf("\n");
    put_elements(c, size3);
    printf("\n");
    //ИДЗ
    d_elements(d,size4,a,size1, b,size2, c,size3);
    put_elements(d, size4);
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}