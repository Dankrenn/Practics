#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#ifndef _LIST_H
#define _LIST_H

typedef struct List {
	int number;
	char name[80];
	struct List* next;
} List;

//������������� ������ ������ ����������
void initlist(List* head) {
    head = NULL;
}

//������� � ������ ����� ����� �� ��������� ���� number=val
void insertfrontint(List* head, int val) {
    List* temp = (List*)malloc(sizeof(List));
    temp->number = val;
    temp->next = head;
    head = temp;
} 

//������� � ������ ����� ����� �� ��������� str � ���� name
void insertfrontstr(List* head, char* str) {
    List* temp = (List*)malloc(sizeof(List));
    strcpy(temp->name, str);
    temp->next = head;
    head = temp;
}


//���������, �������� �� ������ ������
bool isempty(List* head) {
    return head == NULL;
}

//����������� ����� ������
int length(List list) {
    int count = 0;
    struct List* next_aderess = &list;
    while (next_aderess != NULL) {
        count++;
        next_aderess = next_aderess->next;
    }
}

//������� � ������ ����� ���� �� ��������� ���� number=val
void insertbackint(List* head, int val) {
    List* last = NULL;
    if (head == NULL) {
        last = NULL;
    }
    while (head->next) {
        last = head;
        head = head->next;
    }
    List* temp = (List*)malloc(sizeof(List));
    temp->number = val;
    temp->next = NULL;
    last->next = temp;
}

//������� � ������ ����� ����� �� ��������� str � ���� name 
void insertbackstr(List* head, char* str)
{
    List* last = NULL;
    if (head == NULL) {
        last = NULL;
    }
    while (head->next) {
        last = head;
        head = head->next;
    }
    List* temp = (List*)malloc(sizeof(List));
    strcpy(temp->name, str);
    temp->next = NULL;
    last->next = temp;
}

//�������� ��������� ���� node �� ������ 
void destroyItem(List* head, List node)
{
    List* del;
    List* postdel;
    while (head->next) {
        if (head->next == node.next)
        {
            del = head;
            postdel = head->next;
            del->next = postdel->next;
            free(postdel);
        }
    }
}



//Listitem getitem(List, int n); /* ���������� ���� �� ��������� n � ���� number*/
//Listitem getitem(List, char* str); /* ���������� ���� �� ��������� str � ���� name*/
#endif /* _LIST_H */

int main()
{
    setlocale(LC_ALL, "Rus");
    List list;
    initlist(&list); 
    insertfrontint(&list, 10);
    insertbackstr(&list, "������");
    insertfrontint(&list, 20);
    insertbackstr(&list, "���");

    return 0;
}

