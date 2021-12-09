#include "Header.h"


void addTask()
{
    int val;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("not able to add the task to the list\n");
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
        printf("Task added to the list!\n");

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
        printf("Task has been deleted\n");

    }
}


void displayRangeTask()
{
    int i;
    int start;
    int end;
    struct node* ptr;
    ptr = head;

    printf("Input the start of the range");
    scanf_s("%d", &start);

    printf("Input the end of the range");
    scanf_s("%d", &end);

    if (ptr == NULL)
    {
        printf("Task List is empty\n");
    }
    else
    {
        printf("Printing the task list\n");

        for (start; start < end; start++) {

            printf("%d\n", ptr->val = start);
            ptr = ptr->next;

        }
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