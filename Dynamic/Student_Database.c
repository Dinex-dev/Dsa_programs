#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char name[20], grade;
    int rollno, marks[5], average;
    struct student *next;
} student;
student *head = NULL;

void enqueue(student **head, char name[], int rollno, int marks[])
{
    student *new_node = (student *)malloc(sizeof(student));
    strcpy(new_node->name, name);
    new_node->rollno = rollno;
    int average = 0;
    for (int i = 0; i < 5; i++)
        for (int i = 0; i < 5; i++)
        {
            new_node->marks[i] = marks[i];
            average += marks[i];
        }
    new_node->average = average / 5;
    new_node->grade = (average / 5) < 50 ? 'F' : 'P';
    new_node->next = NULL;
    if (*head == NULL)
        *head = new_node;
    else
    {
        student *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void dequeue(student **head)
{
    student *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(student **head)
{
    student *temp = *head;
    while (temp != NULL)
    {
        printf("%s\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %c\n", temp->name, temp->rollno, temp->marks[0], temp->marks[1], temp->marks[2], temp->marks[3], temp->marks[4], temp->average, temp->grade);
        temp = temp->next;
    }
}

int main()
{
    char name[20];
    int rollno, marks[5],choice;
    while (1)
    {
        printf("\n1. Add Student\n2. Delete Student\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Rollno: ");
            scanf(" %d", &rollno);
            printf(" Enter Marks: ");
            for (int i = 0; i < 5; i++)
                scanf("%d", &marks[i]);
            enqueue(&head, name, rollno, marks);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            printf("\nName\tRollno\tSub1\tSub2\tSub3\tSub4\tSub5\tAverage\tGrade\n");
            display(&head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
}
