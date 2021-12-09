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

 char inputKey;
    do {
        printOptions();

   


        printf("Please enter the operation number for the desired option: ");
        scanf_s("%c", &inputKey);
        printf("\n");

        switch (inputKey)
        {
        case 'a':
            addTask();
            break;
        case 'b':
            deleteTask();
            break;
        case 'c':
            //Update an existing task
            break;
        case 'd':
            // Display a single task
            break;
        case 'e':
             displayRangeTask();
            break;
        case 'f':
            displayTask();
            break;
        case 'g':
            //Search for a task
            break;
        case 'h':
            //Quit
            break;

        }

    } while (inputKey != 'h');


}