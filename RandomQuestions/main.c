#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_LENGTH (1024)

typedef struct Node Node;

struct Node
{
    char data[BUFFER_LENGTH];
    Node* next;
};

Node* top;
int numElements = 0;

void initList()
{
    top = 0;
    numElements = 0;
}

void clearList()
{
    if (top == 0)
    {
        return;
    }

    Node* x = top;
    while (x != 0)
    {
        x = top->next;
        free(top);
        top = x;
    }
}

void insert(char data[BUFFER_LENGTH])
{
    Node* x = (Node*)malloc(sizeof(Node));
    x->next = top;
    strcpy(x->data, data);
    top = x;
    ++numElements;
}

void swap(char data1[BUFFER_LENGTH], char data2[BUFFER_LENGTH])
{
    char tmp[BUFFER_LENGTH];
    strcpy(tmp, data1);
    strcpy(data1, data2);
    strcpy(data2, tmp);
}

Node** question;

int main(int argc, char** argv)
{
    switch (argc)
    {
    case 1:
    {
        printf("No arguments\n");
        printf("Usage: random-question path/to/questions\n");
        printf("Exiting...\n");
        return -1;
    }
    case 2:
    {
        printf("Reading %s\n", argv[1]);
        break;
    }
    default:
    {
        printf("Too many arguments\n");
        printf("Usage: random-question path/to/questions\n");
        printf("Exiting...\n");
        return -1;
    }
    }


    char* filename = argv[1];
    FILE* fp;
    char currentLine[BUFFER_LENGTH];
    int len = 0;
    int read;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    initList();
    rewind(fp);
    while (((fgets(currentLine, &len, fp)) != -1) && (feof(fp) == 0)) {
        insert(currentLine);
    }

    printf("Totale possibile domande: %d\n",numElements);

    question = (Node**)malloc(numElements * sizeof(Node*));
    Node* x = top;
    int numberQuestionsLeft = 0;
    while (x != 0)
    {
        question[numberQuestionsLeft++] = x;
        x = x->next;
    }

    srand(time(NULL));
    while (numberQuestionsLeft > 0)
    {
        int currentQuestion = rand() % numberQuestionsLeft;
        printf("%s", question[currentQuestion]->data);
        system("pause");
        swap(question[currentQuestion]->data, question[--numberQuestionsLeft]->data);
    }

    fclose(fp);
    clearList();
    free(question);
    exit(EXIT_SUCCESS);
}