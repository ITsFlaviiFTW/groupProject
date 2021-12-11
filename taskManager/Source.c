#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Header.h"

#define MAXLEN 50

int main() 
{
    P_NODE list = NULL; //list of tasks - empty
    char task[MAXLEN];

    list = readTasks(list);

    printOptions();

    bool continueProgram = true;
    do 
    {
        char inputKey;
        scanf("%c%*c", &inputKey);

        switch (inputKey)
        {
        case 'a':
            list = addTask(list);
            printOptions();
            break;

        case 'b':
            deleteTask(list);
            break;

        case 'c':
            //Update an existing task
            break;

        case 'd':
            // Display a single task
            break;

        case 'e':
            // Display a range of tasks
            break;

        case 'f':
            displayAllTasks(list);
            printOptions();
            break;

        case 'g':
            searchTask(list, task);
            break;

        case 'h':
            continueProgram = false;
            break;

        case '\n':
            break;

        default:
            printf("Invalid Input\n");
            break;
        }

    } while (continueProgram == true);

    saveTasks(list);

    return 0;
}
