// PROG71985 - Group Project
// Task Manager Source File
// Dante Palalas-Mouradian DEC / 2021
// Flavius Porumbiel       DEC / 2021
// Hayden Auterhoff        DEC / 2021

//Version History
// 0.1 created switch case with the cases "a" to "h" to match the menu options
// 0.2 created and distributed the different functions to the different cases
// 0.3 added the "saveTasks" File I/O function so that the user input saves to a text file
// 0.4 added the "readTasks" File I/O function so that the user input loads from the text file into the program
// 0.5 added comments and cleaned up code

#include "Header.h"


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
            list = deleteTask(list);
            printOptions();
            break;

        case 'c':
            displayOldestTask(list);
            printOptions();
            break;

        case 'd':
            displayRecentTask(list);
            printOptions();
            break;

        case 'e':
            displayRangeOfTasks(list);
            printOptions();
            break;

        case 'f':
            displayAllTasks(list);
            printOptions();
            break;

        case 'g':
            printf("What task do you want to search for?: ");
            scanf("%s", &task);
            searchTask(list, task);
            printOptions();
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