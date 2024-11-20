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

	// ������ ���������� (��� ���������)
	printf("������ ��������� �� char: %lu ����\n", sizeof(pc));
	printf("������ ��������� �� int: %lu ����\n", sizeof(pi));
	printf("������ ��������� �� double: %lu ����\n", sizeof(pd));
	printf("������ ��������� �� float: %lu ����\n", sizeof(pf));

	// ������ ��������, �� ������� ��� ���������
	printf("������ �������� ���� char: %lu ����\n", sizeof(*pc));
	printf("������ �������� ���� int: %lu ����\n", sizeof(*pi));
	printf("������ �������� ���� double: %lu ����\n", sizeof(*pd));
	printf("������ �������� ���� float: %lu ����\n", sizeof(*pf));

	return 0;
}

int Task2() {
	setlocale(LC_CTYPE, "RUS");
	float PI = 3.14159, * p1, * p2;

	p1 = p2 = &PI;

	printf("�� ������ p1=%p �������� *p1=%g\n", p1, *p1);

	printf("�� ������ p2=%p �������� *p2=%g\n", p2, *p2);

	printf("�� ������ p1=%x �������� *p1=%g\n", p1, *p1);

	printf("�� ������ p2=%x �������� *p2=%g\n", p2, *p2);
	return 0;
}

int Task3() {
	setlocale(LC_CTYPE, "RUS");
	int *pa, x = 5;
	pa = &x;
	printf("�� ������ %p �������� *ptr=%g\n", pa, *pa);
	pa++;
	printf("�� ������ %p �������� *ptr=%g\n", pa, *pa);
	pa--;
	printf("�� ������ %p �������� *ptr=%g\n", pa, *pa);

	double* pd, y = 5.0;
	pd = &y;
	printf("�� ������ %p �������� *ptr=%g\n", pd, *pd);
	pd++;
	printf("����� ���������� ��������� ��������� �� %p\n", pd);
	pd--;
	printf("����� ���������� ��������� ��������� �� %p\n", pd);
	/*
	�� ������ 0x7ffee38c98c0 �������� *ptr=5.000000
	����� ���������� ��������� ��������� �� 0x7ffee38c98c8 (���������� �� 8 ����)
	����� ���������� ��������� ��������� �� 0x7ffee38c98c0 (���������� �� 8 ����)
	*/

	char* pc, c = 'A';
	pc = &c;
	printf("�� ������ %p �������� *ptr=%c\n", pc, *pc);
	pc++;
	printf("����� ���������� ��������� ��������� �� %p\n", pc);
	pc--;
	printf("����� ���������� ��������� ��������� �� %p\n", pc);
	/*
	�� ������ 0x7ffee38c98bf �������� *ptr=A
	����� ���������� ��������� ��������� �� 0x7ffee38c98c0 (���������� �� 1 ����)
	����� ���������� ��������� ��������� �� 0x7ffee38c98bf (���������� �� 1 ����)
	*/

	long double* pld, ld = 3.14159L;
	pld = &ld;
	printf("�� ������ %p �������� *ptr=%Lf\n", pld, *pld);
	pld++;
	printf("����� ���������� ��������� ��������� �� %p\n", pld);
	pld--;
	printf("����� ���������� ��������� ��������� �� %p\n", pld);
	/*
	* 16 ����.
	*/

	short unsigned int* psi, sui = 42;
	psi = &sui;
	printf("�� ������ %p �������� *ptr=%u\n", psi, *psi);
	psi++;
	printf("����� ���������� ��������� ��������� �� %p\n", psi);
	psi--;
	printf("����� ���������� ��������� ��������� �� %p\n", psi);
    /*
	2 �����. 
	*/

	_Bool* pb, b = 1;
	pb = &b;
	printf("�� ������ %p �������� *ptr=%d\n", pb, *pb);
	pb++;
	printf("����� ���������� ��������� ��������� �� %p\n", pb);
	pb--;
	printf("����� ���������� ��������� ��������� �� %p\n", pb);
	/*
	1 ����.
	*/

	return 0;
}

int Task4() {
	setlocale(LC_CTYPE, "RUS");
	// 4.0 ��������� � �������������� ������
	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1 };
	float* ptr_a;

	// 4.1 ��������, ��� ��� ������� � ��� ��� �����
	printf("����� array: %p\n", array);
	printf("����� &array[0]: %p\n", &array[0]);
	printf("����� &array: %p\n", &array);

	// 4.2 ��������� ��������� �� ������ ������� � �������� ��������
	ptr_a = array;
	printf("\nptr_a = %p, �������� *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a++;  // ����� �� ���� ������� ������
	printf("����� ptr_a++: ptr_a = %p, �������� *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a += 4;  // ����� �� 4 �������� ������
	printf("����� ptr_a+4: ptr_a = %p, �������� *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a -= 2;  // ����� �� 2 �������� �����
	printf("����� ptr_a-2: ptr_a = %p, �������� *ptr_a = %.1f\n", ptr_a, *ptr_a);

	// 4.3 ������ ������ �� ������� � ����� 2
	printf("\n������ ������ �� ������� � ����� 2:\n");
	for (ptr_a = array; ptr_a < array + 10; ptr_a += 2) {
		printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
	}

	// 4.4 �������� ������ �� �������
	printf("\n�������� ������ �� �������:\n");
	for (ptr_a = array + 9; ptr_a >= array; ptr_a--) {
		printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
	}

	return 0;
}


void print_bytes(const void* ptr, size_t size) {
	const unsigned char* byte = (const unsigned char*)ptr;
	printf("����� ����������:\n");
	for (size_t i = 0; i < size; i++) {
		printf("%02X ", byte[i]); // ����� ������ � ����������������� �������
	}
	printf("\n");
}

int Task5() {
	setlocale(LC_CTYPE, "RUS");
	int x = 0x12345678;//���������� ������������������ ��������� 0x12345678 
	int* prt; //��������� ��� ����������� ���������� 
	unsigned char *a1, *a2, *a3, *a4; //��������� �� �����
	unsigned char* a; //��������� �� ����
	prt = &x;//��������� ������ ����������
	a = (unsigned char*)prt;//�������������� ���� ��� ��������� ���������
	//�� ���� ����
	a1 = a + 3;// ��������� 4-�� ����� ����� �
	a2 = a + 2; 
	a3 = a + 1; 
	a4 = a; // ��������� ������� ����� ����� � 
	printf("8.2x\n8.2x\n8.2x\n8.2x\n", *a1, *a2, *a3, *a4);
;

	// 1. ��������� ������� ������ �� ������� int
	int y = 0x12345678;
	printf("���������� x = 0x12345678 (int):\n");
	print_bytes(&y, sizeof(y));

	// 2. ��������� ����� ��� ������ �����
	float f = 12345.0f;
	printf("\n���������� f = 12345.0 (float):\n");
	print_bytes(&f, sizeof(f));

	double d = 12345.0;
	printf("\n���������� d = 12345.0 (double):\n");
	print_bytes(&d, sizeof(d));
	return 0;
}

int HomeWork() {
	setlocale(LC_CTYPE, "RUS");
	// 1. char
	char char_array[2];
	printf("������ char: %ld ����\n", (long)(&char_array[1]) - (long)(&char_array[0]));

	// 2. short int
	short int short_array[2];
	printf("������ short int: %ld ����\n", (long)(&short_array[1]) - (long)(&short_array[0]));

	// 3. unsigned short int
	unsigned short int ushort_array[2];
	printf("������ unsigned short int: %ld ����\n", (long)(&ushort_array[1]) - (long)(&ushort_array[0]));

	// 4. int
	int int_array[2];
	printf("������ int: %ld ����\n", (long)(&int_array[1]) - (long)(&int_array[0]));

	// 5. unsigned char
	unsigned char uchar_array[2];
	printf("������ unsigned char: %ld ����\n", (long)(&uchar_array[1]) - (long)(&uchar_array[0]));

	// 6. wchar_t
	wchar_t wchar_array[2];
	printf("������ wchar_t: %ld ����\n", (long)(&wchar_array[1]) - (long)(&wchar_array[0]));

	// 7. long long int
	long long int llong_array[2];
	printf("������ long long int: %ld ����\n", (long)(&llong_array[1]) - (long)(&llong_array[0]));

	// 8. size_t
	size_t size_t_array[2];
	printf("������ size_t: %ld ����\n", (long)(&size_t_array[1]) - (long)(&size_t_array[0]));

	// 9. float
	float float_array[2];
	printf("������ float: %ld ����\n", (long)(&float_array[1]) - (long)(&float_array[0]));

	// 10. double
	double double_array[2];
	printf("������ double: %ld ����\n", (long)(&double_array[1]) - (long)(&double_array[0]));

	// 11. signed int
	signed int sint_array[2];
	printf("������ signed int: %ld ����\n", (long)(&sint_array[1]) - (long)(&sint_array[0]));

	return 0;
}



