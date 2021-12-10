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

}

int main() {

    P_NODE list = NULL;

    char inputKey;
    char task[MAXLEN];
    printOptions();
    printf("Please enter the operation number for the desired option: ");
    scanf_s("%c", &inputKey);
    printf("\n");
    do {

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
           // displayTask();
            break;
        case 'g':
            searchTask(list, task);
            break;
        case 'h':
            //Quit
            break;

        }

    } while (inputKey != 'h');


}