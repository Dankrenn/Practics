#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main()
{
	//Task1();
	//Task2();
	Task3();
	//HomeWork();
	return 0;
}

int Task1() {

	char masstr[100] = "";
	fgets(masstr, sizeof(masstr),stdin);
	char start[100] = " hi ";
	rsize_t Size = sizeof(start) - strlen(start) - 1;
	strncat_s(start, sizeof(start), masstr, Size);
	start[Size + 1] = '/0';
	for (int i = 0; i < strlen(start); i++)
	{
		printf("%c", toupper(start[i]));
	}
	//Добавьте к строке приветствия множество восклицательных знаков так, чтобы суммарная длина строки составляла 40 символов. 
	rsize_t Size40 = 40 * sizeof(char);
	strncat_s(start, sizeof(start), "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", Size40);
	printf("%s", start);
	return 0;
}

//Измените первоначальный вариант программы, выводящий строку типа «Привет, Вася!» так, чтобы 
//4) перед каждой последней буквой вставлялся символ подчеркивания;
int Task2() {
	char masstr[100] = "";
	char masstr2[100] = "";
	fgets(masstr, sizeof(masstr), stdin);
	char start[100] = "hi, ";
	char start2[100] = "";
	int index_mstr2 = strlen(masstr) - 1;
	int index_start2 = strlen(start) - 1;
	for (int i = 0; i < strlen(masstr); i++) {
		if (i == index_mstr2 - 1)
		{
			masstr2[i] = '_';
			i++;
			masstr2[i] = masstr[i - 1];
		}
		else {
			masstr2[i] = masstr[i];
		}	
	}
	masstr2[strlen(masstr2) + 1] = ' ';

	for (int i = 0; i < strlen(start); i++) {
		if (i == index_start2 -1 )
		{
			start2[i] = '_';
			i++;
			start2[i] = start[i - 1];
		}
		else {
			start2[i] = start[i];
		}
	}
	start2[strlen(start2) + 1] = ' ';

	rsize_t Size = sizeof(start2) - strlen(start2) - 1;
	strncat_s(start2, sizeof(start2), masstr2, Size);
	start2[Size + 1] = '/0';
	printf("%s", start2);
	return 0;
}

int Task3() {
//самое длинное слово в строке 
	char masstr[100] = "";
	char clov[100] = "";
	int ind_start = 0;
	int sum_left = 0;
	int sum_right = 0;
	fgets(masstr, sizeof(masstr), stdin);
	int ind_end = strlen(masstr) - 1;
	for (int i = 0; i <= strlen(masstr) - 1; i++) {
		if (masstr[i] != ' ')
		{
			sum_left++;
		}
		else {
			if (sum_left > sum_right)
			{
				sum_right = sum_left;
				sum_left = 0;
				ind_end = i - 1;
				ind_start = ind_end - sum_right;
			}
			else {
				sum_left == 0;
			}
		}
	}

	return 0;
}

int HomeWork() {
	setlocale(LC_CTYPE, "RUS");

	return 0;
}
