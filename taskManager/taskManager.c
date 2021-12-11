#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Header.h"

void printOptions()
{

    printf("\n");
    printf("Welcome to your task manager\n");
    printf("a) Add new task\n");
    printf("b) Delete an existing task\n");
    printf("c) Update an existing task\n");
    printf("d) Display a single task\n");
    printf("e) Display a range of tasks\n");
    printf("f) Display all tasks\n");
    printf("g) Search for a task\n");
    printf("h) Quit\n");
    printf("Please enter the operation number for the desired option: ");
    printf("\n");

}

P_NODE addTask(P_NODE list)
{
    //char val[MAXLEN];
    //int trueVal;
    char task[MAXLEN];

    //printf("Please enter the task number: \n");
    //fgets(val, MAXLEN, stdin);
    //trueVal = atoi(val);

    printf("Please insert the task: \n");
    //scanf("%s", task);
    fgets(task, MAXLEN, stdin);
    task[strlen(task) - 1] = '\0';

    //P_NODE newTask = createTask(trueVal, task);
    P_NODE newTask = createTask(task);
    list = updateList(list, newTask);

    return list;
}

//P_NODE createTask(int val, char task[])
P_NODE createTask(char task[])
{
    P_NODE newTask = (P_NODE)malloc(sizeof(NODE));
    //newTask->val = val;
    strcpy(newTask->task, task);

    newTask->next = NULL;
    newTask->prev = NULL;

    return newTask;
}

P_NODE updateList(P_NODE list, P_NODE newTask)
{
    if (list == NULL)
    {
        list = newTask;
    }
    else 
    {
        P_NODE currentTask = list;
        P_NODE prevTask = list->prev;
        while (currentTask->next != NULL)
        {
            currentTask = currentTask->next;
        }
        prevTask = currentTask;
        currentTask->next = newTask;
        newTask->prev = prevTask;
    }
    return list;
}

P_NODE deleteTask(P_NODE list)
{
    char search_task[MAXLEN];
    printf("Please enter the task to be removed: ");
    scanf("%s", &search_task);
    P_NODE taskToRemove = searchTask(list, search_task);

    if (list == NULL)
    {
        printf("The task list is empty, nothing to delete.");
        return list;
    }
   // if (taskToRemove->prev == NULL)
   //{
   //     list = list->next;
   //     list->prev = NULL;
   //}
    else
    {
        taskToRemove->prev->next = taskToRemove->next;
        taskToRemove->next->prev = taskToRemove->prev;
    }
    free(taskToRemove);

    return list;
}

P_NODE displayAllTasks(P_NODE list) 
{
    if (list == NULL) {

        return NULL;

    }

    P_NODE currentTask = list;

    if (currentTask == NULL) 
    {
       return NULL;
    }

    while (currentTask != NULL) 
    {
        printf("%s\n", currentTask->task);
        currentTask = currentTask->next;
    }

    printf("These are all tasks within the list\n");

    return;

}

P_NODE searchTask(P_NODE list, char search_task[])
{
    if (list == NULL)
    {
        return NULL;
    }

    if (list->next == NULL)
    {
        if (strcmp(list->task, search_task) == 1)
        {
            return list;
        }
        else
        {
            return NULL;
        }
    }

    P_NODE currentTask = list;
    while (currentTask->next != NULL)
    {
        if (!strcmp(currentTask->task, search_task))
        {
            return currentTask;
        }
        else
        {
            currentTask = currentTask->next;
        }
    }
    return NULL;
}

void saveTasks(P_NODE list)
{
    FILE* fp;
    fp = fopen("taskList.txt", "w+");
    P_NODE currentTask = list;
    while (currentTask != NULL)
    {
        //fprintf(fp, "%d\n", currentTask->val);
        fprintf(fp, "%s\n", currentTask->task);
        currentTask = currentTask->next;
    }
    fclose(fp);
}

P_NODE readTasks(P_NODE list)
{
    FILE* fp;
    fp = fopen("taskList.txt", "r+");
    //char tempVal[MAXLEN];
    char tempTask[MAXLEN];
    P_NODE tempLists;

    while (fgets(tempTask, MAXLEN, fp) != NULL)
    {
        tempTask[strlen(tempTask) - 1] = '\0';

        tempLists = createTask(tempTask);
        list = updateList(list, tempLists);
    }
    fclose(fp);

    return list;
}
