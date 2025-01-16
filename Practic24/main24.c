#include <stdio.h>
#include <locale.h>
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <locale.h> 

#define NMAX 100 
#define TYPE char 
#define FTYPE "%3c," 
#define NSTR 100 

int main()
{
	setlocale(LC_CTYPE, "RUS");
	Task1();
	Task2();
	HomeWork();
	return 0;
}


typedef struct Stack {
    int top;
    TYPE data[NMAX];
} stack;

int isempty(stack* s) {
    return s->top == 0;
}

int isfull(stack* s) {
    return s->top == NMAX - 1;
}

int push(stack* s, TYPE a) {
    if (isfull(s)) {
        printf("���� �����. ���������� �������� ������� '%c'.\n", a);
        return 0;
    }
    s->data[++(s->top)] = a;
    return 1;
}

TYPE pop(stack* s) {
    if (isempty(s)) {
        printf("���� ����. ���������� ������� �������.\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

TYPE top(stack* s) {
    if (isempty(s)) {
        printf("���� ����. ������� �����������.\n");
        return '\0';
    }
    return s->data[s->top];
}

void display(stack* s) {
    int i = s->top;
    while (i > 0) {
        printf(FTYPE, s->data[i--]);
    }
    printf("\n");
}

int Task1() {
	printf("������� 1. ���������� ���� �� �������  � ������������ � ������������ ���� �����������\n");
    stack s;
    s.top = 0;

    char input[NMAX];
    printf("������� ������ ��� ���������� � ����: ");
    fgets(input, NMAX, stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    for (size_t i = 0; i < strlen(input); i++) {
        if (!push(&s, input[i])) {
            break;
        }
    }

    printf("���������� �����:\n");
    display(&s);

    printf("��������� �������� �� �����:\n");
    while (!isempty(&s)) {
        printf(FTYPE, pop(&s));
    }
    printf("\n");
    printf("������� 1 ���������\n");
    printf("\n");
    return 0;
}

// ���� ������� 
struct Node {
    TYPE data;
    struct Node* next;
};


typedef struct {
    struct Node* front; 
    struct Node* back;   
} queue_list;

// ���������� �������� � ������� 
void enQueue(queue_list* que, TYPE element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("������: ������ �� ����� ���� ��������.\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;

    if (que->back == NULL) {
        // ���� ������� ����� 
        que->front = que->back = newNode;
        return;
    }

    que->back->next = newNode;
    que->back = newNode;
}

// ���������� �������� �� ������� 
TYPE deQueue(queue_list* que) {
    if (que->front == NULL) {
        printf("������: ������� �����.\n");
        return '\0'; // ���������� null-������ 
    }

    struct Node* temp = que->front;
    TYPE data = temp->data;
    que->front = que->front->next;

    if (que->front == NULL) {
        que->back = NULL;
    }

    free(temp);
    return data;
}

int Task2() {
    printf("������� 2. ���������� ������� �� ��������� ������  � ������������ � ������������ ���� �����������\n");
    queue_list Str;
    Str.back = Str.front = NULL;

    char temp[NSTR];
    system("chcp 1251"); // ������������� ��������� Windows 
    puts("������� ������:");
    fgets(temp, NSTR - 1, stdin);

    for (int i = 0; i < NSTR - 1 && temp[i] != '\n' && temp[i] != '\0'; i++) {
        enQueue(&Str, temp[i]);
    }

    // ������ ������� 
    while (Str.front) {
        printf(FTYPE, deQueue(&Str));
    }
    printf("\n");
    printf("������� 2 ���������\n");
    printf("\n");
	return 0;
}

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;
    QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int HomeWork() {
    printf("��. ��������� ���� �� ��������� �������������� �������\n");
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int a, b;
    printf("������� ������� [a, b]: ");
    scanf_s("%d %d", &a, &b);

    Queue* qLessThanA = createQueue();
    Queue* qInRange = createQueue();
    Queue* qOthers = createQueue();

    int num;
    while (fscanf_s(inputFile, "%d", &num) != EOF) {
        if (num < a) {
            enqueue(qLessThanA, num);
        }
        else if (num >= a && num <= b) {
            enqueue(qInRange, num);
        }
        else {
            enqueue(qOthers, num);
        }
    }

    while (!isEmpty(qLessThanA)) {
        fprintf(outputFile, "%d\n", dequeue(qLessThanA));
    }

    while (!isEmpty(qInRange)) {
        fprintf(outputFile, "%d\n", dequeue(qInRange));
    }

    while (!isEmpty(qOthers)) {
        fprintf(outputFile, "%d\n", dequeue(qOthers));
    }

    fclose(inputFile);
    fclose(outputFile);

    free(qLessThanA);
    free(qInRange);
    free(qOthers);

    printf("\n");
    printf("������� 2 ���������\n");
    printf("\n");
	return 0;
}