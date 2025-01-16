#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <locale.h> 

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

int main() {
    setlocale(LC_CTYPE, "RUS");
    Task1();
    Task2();
    HomeWork();
    return 0;
}



void initlist(List* list) {
    *list = NULL;

}

bool isempty(List* list) {
    return *list == NULL;
}

int length(List list) {
    int len = 0;
    while (list != NULL) {
        len++;
        list = list->next;
    }
    return len;
}

void insertfront_num(List* list, int val) {
    List new_node = (List)malloc(sizeof(struct listitem));
    new_node->number = val;
    new_node->name[0] = '\0';
    new_node->next = *list;
    *list = new_node;
}

void insertback_num(List* list, int val) {
    List new_node = (List)malloc(sizeof(struct listitem));
    new_node->number = val;
    new_node->name[0] = '\0';
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
        return;
    }

    List temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertfront_str(List* list, char* str) {
    List new_node = (List)malloc(sizeof(struct listitem));
    new_node->number = 0;
    strncpy_s(new_node->name, sizeof(new_node->name), str, _TRUNCATE);
    new_node->next = *list;
    *list = new_node;
}

void insertback_str(List* list, char* str) {
    List new_node = (List)malloc(sizeof(struct listitem));
    new_node->number = 0;
    strncpy_s(new_node->name, sizeof(new_node->name), str, _TRUNCATE);
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
        return;
    }

    List temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void destroyItem(List* list, List node) {
    if (*list == NULL || node == NULL) return;

    if (*list == node) {
        *list = (*list)->next;
        free(node);
        return;
    }

    List temp = *list;
    while (temp->next != NULL && temp->next != node) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    temp->next = node->next;
    free(node);
}

void clearlist(List* list) {
    while (*list != NULL) {
        List temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

List getitem_num(List list, int n) {
    while (list != NULL) {
        if (list->number == n) return list;
        list = list->next;
    }
    return NULL;
}

List getitem_str(List list, char* str) {
    while (list != NULL) {
        if (strcmp(list->name, str) == 0) return list;
        list = list->next;
    }
    return NULL;
}

void printlist(List list) {
    while (list != NULL) {
        printf("Number: %d, Name: %s\n", list->number, list->name);
        list = list->next;
    }
}

int Task1() {
    printf("������� 1. ���������� ����������� �������� ������, �������� ����������, ��������������� � ������������ ����� list.h\n");
    List mylist;
    initlist(&mylist);
    insertfront_str(&mylist, "daniil");
    insertfront_num(&mylist, 42);
    insertback_str(&mylist, "ruzenko");
    insertback_num(&mylist, 77);


    printf("���������� ������:\n");
    printlist(mylist);

    printf("\n����� ������: %d\n", length(mylist));

    List found = getitem_str(mylist, "Alexander");
    if (found) {
        printf("\n������ ����: Name = %s\n", found->name);
        destroyItem(&mylist, found);
    }

    printf("\n������ ����� �������� ����:\n");
    printlist(mylist);

    clearlist(&mylist);

    printf("������� 1 ���������\n");
    printf("\n");
    return 0;
}

struct listitem2 {
    int value;
    struct listitem2* next;
};

typedef struct listitem2* List2;

// ������� ��� �������� ������ ���� 
List2 createNode(int value) {
    List2 newNode = (List2)malloc(sizeof(struct listitem2));
    if (!newNode) {
        printf("������ ��������� ������.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void initList2(List2* list) {
    *list = NULL;
}

void appendNode2(List2* list, int value) {
    List2 newNode = createNode(value);
    if (*list == NULL) {
        *list = newNode;
    }
    else {
        List2 temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList2(List2 list) {
    while (list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }
    printf("NULL\n");
}

int getLength2(List2 list) {
    int length = 0;
    while (list != NULL) {
        length++;
        list = list->next;
    }
    return length;
}

void insertAtPosition2(List2* list, int value, int position) {
    List2 newNode = createNode(value);
    if (position == 0) {
        newNode->next = *list;
        *list = newNode;
        return;
    }

    List2 temp = *list;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtPosition2(List2* list, int position) {
    if (*list == NULL) {
        printf("������ ����, �������� ����������.\n");
        return;
    }

    List2 temp = *list;
    if (position == 0) {
        *list = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("������� ��� ������ ������.\n");
        return;
    }

    List2 toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int calculateAverage2(List2 list) {
    int sum = 0, count = 0;
    while (list != NULL) {
        sum += list->value;
        count++;
        list = list->next;
    }
    return count > 0 ? sum / count : 0;
}

int Task2() {
    setlocale(LC_CTYPE, "RUS");
    printf("������� 2. ������������ ���������, ������������ ���������� ���������� ������  �������� �������� (����������� ������� ������ �� ����� �� � ����� ��������������)\n");
    printf("������� �������� ���������������� ������ � ��������� ��������� ����������� ��������. �������� ������� �������� � �������� ������.\n");

    List2 myList;
    initList2(&myList);

    srand(time(NULL));
    int numElements = rand() % 10 + 5;
    for (int i = 0; i < numElements; i++) {
        appendNode2(&myList, rand() % 100);
    }

    printf("������ �� ��������������:\n");
    printList2(myList);
    int avg = calculateAverage2(myList);
    int middlePosition = getLength2(myList) / 2;
    insertAtPosition2(&myList, avg, middlePosition);

    printf("������ ����� ���������� �������� �������� (%d):\n", avg);
    printList2(myList);

    int numOperations;
    printf("\n������� ���������� �������� ������� ��� ��������: ");
    scanf("%d", &numOperations);

    for (int i = 0; i < numOperations; i++) {
        int operation;
        printf("\n�������� �������� (0 - �������, 1 - ��������): ");
        scanf("%d", &operation);

        if (operation == 0) {
            int value, position;
            printf("������� �������� ��� �������: ");
            scanf("%d", &value);
            printf("������� ������� ��� ������� (0 ��� ������): ");
            scanf("%d", &position);
            insertAtPosition2(&myList, value, position);
            printf("������ ����� �������:\n");
            printList2(myList);
        }
        else if (operation == 1) {
            int position;
            printf("������� ������� ��� ��������: ");
            scanf("%d", &position);
            deleteAtPosition2(&myList, position);
            printf("������ ����� ��������:\n");
            printList2(myList);
        }
        else {
            printf("�������� ��������. �������.\n");
        }
    }
    printf("\n�������� ������:\n");
    printList2(myList);
    printf("������� 2 ���������\n");
    printf("\n");
    return 0;
}



typedef struct Cornice {
    int length;
    int ceilingWidth;
    int wallHeight;
    char material[20];
    struct Cornice* next;
} cornice_t;

cornice_t* createNode2(int length, int ceilingWidth, int wallHeight, const char* material) {
    cornice_t* newNode = (cornice_t*)malloc(sizeof(cornice_t));
    if (!newNode) {
        printf("������ ��������� ������.\n");
        exit(1);
    }
    newNode->length = length;
    newNode->ceilingWidth = ceilingWidth;
    newNode->wallHeight = wallHeight;
    strncpy_s(newNode->material, sizeof(newNode->material), material, _TRUNCATE);
    newNode->next = NULL;
    return newNode;
}

void appendNode(cornice_t** head, int length, int ceilingWidth, int wallHeight, const char* material) {
    cornice_t* newNode = createNode2(length, ceilingWidth, wallHeight, material);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        cornice_t* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(cornice_t* head) {
    while (head != NULL) {
        printf("�����: %d, ������ �������: %d, ������ �����: %d, ��������: %s\n",
            head->length, head->ceilingWidth, head->wallHeight, head->material);
        head = head->next;
    }
}

cornice_t* mergeSortedLists(cornice_t* a, cornice_t* b, int field) {
    if (!a) return b;
    if (!b) return a;

    cornice_t* result = NULL;
    int comparison;

    if (field == 1) {
        comparison = (a->length <= b->length);
    }
    else if (field == 2) {
        comparison = (a->ceilingWidth <= b->ceilingWidth);
    }
    else if (field == 3) {
        comparison = (a->wallHeight <= b->wallHeight);
    }
    else if (field == 4) {
        comparison = (strcmp(a->material, b->material) <= 0);
    }
    else {
        printf("����������� ���� ����������.\n");
        exit(1);
    }

    if (comparison) {
        result = a;
        result->next = mergeSortedLists(a->next, b, field);
    }
    else {
        result = b;
        result->next = mergeSortedLists(a, b->next, field);
    }
    return result;
}

void splitList(cornice_t* source, cornice_t** front, cornice_t** back) {
    cornice_t* fast;
    cornice_t* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(cornice_t** headRef, int field) {
    cornice_t* head = *headRef;
    if (!head || !head->next) return;

    cornice_t* a;
    cornice_t* b;

    splitList(head, &a, &b);

    mergeSort(&a, field);
    mergeSort(&b, field);

    *headRef = mergeSortedLists(a, b, field);
}

cornice_t* searchByField(cornice_t* head, int field, const char* value) {
    while (head != NULL) {
        if (field == 1 && head->length == atoi(value)) {
            return head;
        }
        else if (field == 2 && head->ceilingWidth == atoi(value)) {
            return head;
        }
        else if (field == 3 && head->wallHeight == atoi(value)) {
            return head;
        }
        else if (field == 4 && strcmp(head->material, value) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void freeList(cornice_t* head) {
    while (head != NULL) {
        cornice_t* temp = head;
        head = head->next;
        free(temp);
    }
}

int HomeWork() {
    printf("��.  ������������� ������ �������� ������ 21 � ��������� ������ � ����������� ������ � ���������� �������� � ������������ � ��������\n");
    cornice_t* cornices = NULL;

    appendNode(&cornices, 2500, 80, 50, "��������");
    appendNode(&cornices, 1700, 45, 60, "������");
    appendNode(&cornices, 2000, 30, 70, "������");
    appendNode(&cornices, 1500, 40, 65, "�������");

    printf("������ �� ����������:\n");
    printList(cornices);
    int sortField;
    printf("\n�������� ���� ��� ����������:\n");
    printf("1 - �����\n2 - ������ �������\n3 - ������ �����\n4 - ��������\n");
    printf("��� �����: ");
    scanf("%d", &sortField);

    mergeSort(&cornices, sortField);

    printf("\n������ ����� ����������:\n");
    printList(cornices);

    int searchField;
    char searchValue[20];
    printf("\n�������� ���� ��� ������:\n");
    printf("1 - �����\n2 - ������ �������\n3 - ������ �����\n4 - ��������\n");
    printf("��� �����: ");
    scanf("%d", &searchField);
    printf("������� �������� ��� ������: ");
    scanf("%s", searchValue);

    cornice_t* found = searchByField(cornices, searchField, searchValue);
    if (found) {
        printf("\n������ �������: �����: %d, ������ �������: %d, ������ �����: %d, ��������: %s\n",
            found->length, found->ceilingWidth, found->wallHeight, found->material);
    }
    else {
        printf("\n������� �� ������.\n");
    }

    freeList(cornices);

    return 0;
    printf("�� ���������\n");
    printf("\n");
    return 0;
}
