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

//инициализация списка пустым содержимым
void initlist(List* head) {
    head = NULL;
}

//вставка в список перед узлом со значением поля number=val
void insertfrontint(List* head, int val) {
    List* temp = (List*)malloc(sizeof(List));
    temp->number = val;
    temp->next = head;
    head = temp;
} 

//вставка в список перед узлом со значением str в поле name
void insertfrontstr(List* head, char* str) {
    List* temp = (List*)malloc(sizeof(List));
    strcpy(temp->name, str);
    temp->next = head;
    head = temp;
}


//проверяет, является ли список пустым
bool isempty(List* head) {
    return head == NULL;
}

//определение длины списка
int length(List list) {
    int count = 0;
    struct List* next_aderess = &list;
    while (next_aderess != NULL) {
        count++;
        next_aderess = next_aderess->next;
    }
}

//вставка в список после узла со значением поля number=val
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

//вставка в список перед узлом со значением str в поле name 
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

//удаление заданного узла node из списка 
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



//Listitem getitem(List, int n); /* нахождение узла со значением n в поле number*/
//Listitem getitem(List, char* str); /* нахождение узла со значением str в поле name*/
#endif /* _LIST_H */

int main()
{
    setlocale(LC_ALL, "Rus");
    List list;
    initlist(&list); 
    insertfrontint(&list, 10);
    insertbackstr(&list, "Привет");
    insertfrontint(&list, 20);
    insertbackstr(&list, "Мир");

    return 0;
}

