#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	//Task1();
	//Task2();
	//Task3();
	//Task4();
	//Task5();
	HomeWork();
	return 0;
}

int Task1() {
	setlocale(LC_CTYPE, "RUS");

	char c = 'A';
	int i = 42;
	double d = 3.14;
	float f = 2.1f;

	char* pc = &c;
	int* pi = &i;
	double* pd = &d;
	float* pf = &f;

	// Размер указателей (они одинаковы)
	printf("Размер указателя на char: %lu байт\n", sizeof(pc));
	printf("Размер указателя на int: %lu байт\n", sizeof(pi));
	printf("Размер указателя на double: %lu байт\n", sizeof(pd));
	printf("Размер указателя на float: %lu байт\n", sizeof(pf));

	// Размер значений, на которые они указывают
	printf("Размер значения типа char: %lu байт\n", sizeof(*pc));
	printf("Размер значения типа int: %lu байт\n", sizeof(*pi));
	printf("Размер значения типа double: %lu байт\n", sizeof(*pd));
	printf("Размер значения типа float: %lu байт\n", sizeof(*pf));

	return 0;
}

int Task2() {
	setlocale(LC_CTYPE, "RUS");
	float PI = 3.14159, * p1, * p2;

	p1 = p2 = &PI;

	printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);

	printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);

	printf("По адресу p1=%x хранится *p1=%g\n", p1, *p1);

	printf("По адресу p2=%x хранится *p2=%g\n", p2, *p2);
	return 0;
}

int Task3() {
	setlocale(LC_CTYPE, "RUS");
	int *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);

	double* pd, y = 5.0;
	pd = &y;
	printf("По адресу %p хранится *ptr=%g\n", pd, *pd);
	pd++;
	printf("После инкремента указатель ссылается на %p\n", pd);
	pd--;
	printf("После декремента указатель ссылается на %p\n", pd);
	/*
	По адресу 0x7ffee38c98c0 хранится *ptr=5.000000
	После инкремента указатель ссылается на 0x7ffee38c98c8 (увеличение на 8 байт)
	После декремента указатель ссылается на 0x7ffee38c98c0 (уменьшение на 8 байт)
	*/

	char* pc, c = 'A';
	pc = &c;
	printf("По адресу %p хранится *ptr=%c\n", pc, *pc);
	pc++;
	printf("После инкремента указатель ссылается на %p\n", pc);
	pc--;
	printf("После декремента указатель ссылается на %p\n", pc);
	/*
	По адресу 0x7ffee38c98bf хранится *ptr=A
	После инкремента указатель ссылается на 0x7ffee38c98c0 (увеличение на 1 байт)
	После декремента указатель ссылается на 0x7ffee38c98bf (уменьшение на 1 байт)
	*/

	long double* pld, ld = 3.14159L;
	pld = &ld;
	printf("По адресу %p хранится *ptr=%Lf\n", pld, *pld);
	pld++;
	printf("После инкремента указатель ссылается на %p\n", pld);
	pld--;
	printf("После декремента указатель ссылается на %p\n", pld);
	/*
	* 16 байт.
	*/

	short unsigned int* psi, sui = 42;
	psi = &sui;
	printf("По адресу %p хранится *ptr=%u\n", psi, *psi);
	psi++;
	printf("После инкремента указатель ссылается на %p\n", psi);
	psi--;
	printf("После декремента указатель ссылается на %p\n", psi);
    /*
	2 байта. 
	*/

	_Bool* pb, b = 1;
	pb = &b;
	printf("По адресу %p хранится *ptr=%d\n", pb, *pb);
	pb++;
	printf("После инкремента указатель ссылается на %p\n", pb);
	pb--;
	printf("После декремента указатель ссылается на %p\n", pb);
	/*
	1 байт.
	*/

	return 0;
}

int Task4() {
	setlocale(LC_CTYPE, "RUS");
	// 4.0 Объявляем и инициализируем массив
	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1 };
	float* ptr_a;

	// 4.1 Убедимся, что имя массива — это его адрес
	printf("Адрес array: %p\n", array);
	printf("Адрес &array[0]: %p\n", &array[0]);
	printf("Адрес &array: %p\n", &array);

	// 4.2 Установим указатель на начало массива и выполним операции
	ptr_a = array;
	printf("\nptr_a = %p, значение *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a++;  // Сдвиг на один элемент вперед
	printf("После ptr_a++: ptr_a = %p, значение *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a += 4;  // Сдвиг на 4 элемента вперед
	printf("После ptr_a+4: ptr_a = %p, значение *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a -= 2;  // Сдвиг на 2 элемента назад
	printf("После ptr_a-2: ptr_a = %p, значение *ptr_a = %.1f\n", ptr_a, *ptr_a);

	// 4.3 Прямой проход по массиву с шагом 2
	printf("\nПрямой проход по массиву с шагом 2:\n");
	for (ptr_a = array; ptr_a < array + 10; ptr_a += 2) {
		printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
	}

	// 4.4 Обратный проход по массиву
	printf("\nОбратный проход по массиву:\n");
	for (ptr_a = array + 9; ptr_a >= array; ptr_a--) {
		printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
	}

	return 0;
}


void print_bytes(const void* ptr, size_t size) {
	const unsigned char* byte = (const unsigned char*)ptr;
	printf("Байты переменной:\n");
	for (size_t i = 0; i < size; i++) {
		printf("%02X ", byte[i]); // Вывод байтов в шестнадцатеричном формате
	}
	printf("\n");
}

int Task5() {
	setlocale(LC_CTYPE, "RUS");
	int x = 0x12345678;//переменная инициализированная значением 0x12345678 
	int* prt; //указатель для исследуемой переменной 
	unsigned char *a1, *a2, *a3, *a4; //указатели на байты
	unsigned char* a; //указатель на байт
	prt = &x;//получение адреса переменной
	a = (unsigned char*)prt;//преобразование типа для получения указателя
	//на один байт
	a1 = a + 3;// получение 4-го байта числа х
	a2 = a + 2; 
	a3 = a + 1; 
	a4 = a; // получение первого байта числа х 
	printf("8.2x\n8.2x\n8.2x\n8.2x\n", *a1, *a2, *a3, *a4);
;

	// 1. Исследуем порядок байтов на примере int
	int y = 0x12345678;
	printf("Переменная x = 0x12345678 (int):\n");
	print_bytes(&y, sizeof(y));

	// 2. Побайтный вывод для других типов
	float f = 12345.0f;
	printf("\nПеременная f = 12345.0 (float):\n");
	print_bytes(&f, sizeof(f));

	double d = 12345.0;
	printf("\nПеременная d = 12345.0 (double):\n");
	print_bytes(&d, sizeof(d));
	return 0;
}

int HomeWork() {
	setlocale(LC_CTYPE, "RUS");
	// 1. char
	char char_array[2];
	printf("Размер char: %ld байт\n", (long)(&char_array[1]) - (long)(&char_array[0]));

	// 2. short int
	short int short_array[2];
	printf("Размер short int: %ld байт\n", (long)(&short_array[1]) - (long)(&short_array[0]));

	// 3. unsigned short int
	unsigned short int ushort_array[2];
	printf("Размер unsigned short int: %ld байт\n", (long)(&ushort_array[1]) - (long)(&ushort_array[0]));

	// 4. int
	int int_array[2];
	printf("Размер int: %ld байт\n", (long)(&int_array[1]) - (long)(&int_array[0]));

	// 5. unsigned char
	unsigned char uchar_array[2];
	printf("Размер unsigned char: %ld байт\n", (long)(&uchar_array[1]) - (long)(&uchar_array[0]));

	// 6. wchar_t
	wchar_t wchar_array[2];
	printf("Размер wchar_t: %ld байт\n", (long)(&wchar_array[1]) - (long)(&wchar_array[0]));

	// 7. long long int
	long long int llong_array[2];
	printf("Размер long long int: %ld байт\n", (long)(&llong_array[1]) - (long)(&llong_array[0]));

	// 8. size_t
	size_t size_t_array[2];
	printf("Размер size_t: %ld байт\n", (long)(&size_t_array[1]) - (long)(&size_t_array[0]));

	// 9. float
	float float_array[2];
	printf("Размер float: %ld байт\n", (long)(&float_array[1]) - (long)(&float_array[0]));

	// 10. double
	double double_array[2];
	printf("Размер double: %ld байт\n", (long)(&double_array[1]) - (long)(&double_array[0]));

	// 11. signed int
	signed int sint_array[2];
	printf("Размер signed int: %ld байт\n", (long)(&sint_array[1]) - (long)(&sint_array[0]));

	return 0;
}



