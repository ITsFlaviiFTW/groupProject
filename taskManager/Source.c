#include "Header.h"



int main()
{
    P_NODE list = NULL; //list of tasks - empty
    char task[MAXLEN];

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