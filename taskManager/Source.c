#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "Header.h"

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

    printOptions();

    char inputKey;

    printf("Please enter the operation number for the desired option: ");
    scanf_s("%c", &inputKey);
    printf("\n");

    switch (inputKey)
    {
    case 'a':
        addTask();
        return 0;
    case 'b':
        deleteTask();
        return 0;
    case 'c':
        //Update an existing task
        return 0;
    case 'd':
        // Display a single task
        return 0;
    case 'e':
        // Display a range of tasks
        return 0;
    case 'f':
        displayTask();
        return 0;
    case 'g':
        //Search for a task
        return 0;
    case 'h':
        //Quit
        return 0;

    }

}