#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "Header.h"

struct node
{
    int val;
    struct node* next;
};
struct node* head;


void addTask()
{
    int val;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("not able to add the task to the list");
    }
    else
    {
        printf("Enter the task: ");
        scanf_s("%d", &val);
        if (head == NULL)
        {
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head = ptr;

        }
        printf("Task added to the list!");

    }
}

void deleteTask()
{
    int item;
    struct node* ptr;
    if (head == NULL)
    {
        printf("No task available to delete!\n");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Task has been deleted");

    }
}

void displayTask()
{
    int i;
    struct node* ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Task List is empty\n");
    }
    else
    {
        printf("Printing the task list\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}