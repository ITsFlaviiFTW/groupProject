#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "Header.h"

P_NODE addTask(P_NODE list)
{
    //char val[MAXLEN];
    //int trueVal;
    char task[MAXLEN];

    //printf("Please enter the task number: \n");
    //fgets(val, MAXLEN, stdin);
   // trueVal = atoi(val);

    printf("Please insert the task: \n");
    scanf("%s", &task);
    task[strlen(task) - 1] = '\0';

    //P_NODE newTask = createTask(trueVal, task);
    P_NODE newTask = createTask(task);
    list = updateList(list, newTask);

}

//P_NODE createTask(int val, char task[])
P_NODE createTask(char task[])
{
    P_NODE newTask = (P_NODE)malloc(sizeof(NODE));
    //newTask->val = val;
    strcpy(newTask->task, task);

    newTask->next = NULL;
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

}

void displayAllTasks(P_NODE list) {

    if (list == NULL) {

        return NULL;

    }

    P_NODE currentTask = list;

    if (currentTask == NULL) {

        return NULL;

    }

    while (currentTask != NULL) {


        return currentTask;

    }

    return;

}

void searchTask(P_NODE list, char search_task[])
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
    fp = fopen("taskList", "w+");
    P_NODE currentTask = list;
    while (currentTask != NULL)
    {
        fprintf(fp, "%d\n", currentTask->val);
        fprintf(fp, "%s\n", currentTask->task);
        currentTask = currentTask->next;
    }
    fclose(fp);
}

void readTasks(P_NODE list)
{
    FILE* fp;
    fp = fopen("taskList", "r+");
    char tempVal[MAXLEN];
    char tempTask[MAXLEN];

    while (fgets(tempVal, MAXLEN, fp) != NULL)
    {
    }
}
