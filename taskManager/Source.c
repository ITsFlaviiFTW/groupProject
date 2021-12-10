#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "Header.h"

#define MAXLEN 50

void printOptions() {

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

int main()
{

    P_NODE list = NULL;
    char task[MAXLEN];

    printOptions();
    bool continueProgram = true;
    do {

        char inputKey;
        scanf_s("%c", &inputKey);

        switch (inputKey)
        {
        case 'a':
            list = addTask(list);
            break;
        case 'b':
            list = deleteTask(list);
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
            break;
        case 'g':
            searchTask(list, task);
            break;
        case 'h':
            continueProgram = false;
            break;

        }

    } while (continueProgram == true);

}
