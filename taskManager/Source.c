#include "Header.h"

void printOptions() {

    printf("Welcome to your task manager\n");
    printf("1) Add new task\n");
    printf("2) Delete an existing task\n");
    printf("3) Update an existing task\n");
    printf("4) Display a single task\n");
    printf("5) Display a range of tasks\n");
    printf("6) Display all tasks\n");
    printf("7) Search for a task\n");
    printf("8) Quit\n");

}

int menu() {

    int inputKey;

        printOptions();

        printf("Please enter the operation number for the desired option: ");
        scanf_s("%d", &inputKey);
        printf("\n");

        switch (inputKey)
        {
        case 1:
            addTask();
            break;
        case 2:
            deleteTask();
            break;
        case 3:
            //Update an existing task
            break;
        case 4:
            // Display a single task
            break;
        case 5:
            displayRangeTask();
            break;
        case 6:
            displayTask();
            break;
        case 7:
            //Search for a task
            break;
        case 0:
            //Quit
            break;

        }


        return inputKey;

}

int main() {

int Key;

     do{

         Key = menu();

    } while (Key != 8); 

}