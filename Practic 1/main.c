#include <stdio.h>
#include <locale.h>

int main() 
{
	Task1();
	Task2();
	Task3();
	HomeWork();
	return 0;
}

int Task1() {
	setlocale(LC_CTYPE, "RUS");
	puts("��� ���������");
	puts("Hello Word");
	puts("������� Enter ��� �����������...");
	getchar(); // �������� ������� Enter
	puts("����������� ���������");
	printf("\n");
	return 0;
}
int Task2() {
	printf("********************************************\n");
	printf("*  ����: ���������� ����������� ���������� *\n");
	printf("*                                          *\n");
	printf("*        ��������: ������� �.�.            *\n");
	printf("********************************************\n");
	printf("\n");
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