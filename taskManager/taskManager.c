// PROG71985 - Group Project
// Task Manager Source File
// Dante Palalas-Mouradian DEC / 2021
// Flavius Porumbiel       DEC / 2021
// Hayden Auterhoff        DEC / 2021

//Version History
// 0.1 created menu and populated with options
// 0.2 created addTask, deleteTask, createTask and File I/O functions
// 0.3 created display functions (displayAllTasks, displayRangeOfTasks)
// 0.4 created updateList function
// 0.5 updated deleteTask function
// 0.6 created displayRecentTask function
// 0.7 created displayOldestTask function
// 0.8 updated displayRecentTask and created getLastItemInList function to help clean code
// 0.9 created searchTask function
// 1.0 added comments and cleaned up code


#include "Header.h"

//this menu displays all the possible options of the program
void printOptions() 
{
    printf("\n");
    printf("Welcome to your task manager\n");
    printf("a) Add new task\n");
    printf("b) Delete an existing task\n");
    printf("c) Display the oldest entered task\n");
    printf("d) Display most recently entered task\n");
    printf("e) Display 'x' number of tasks\n");
    printf("f) Display all tasks\n");
    printf("g) Search for a task\n");
    printf("h) Quit\n");
    printf("Please enter the operation number for the desired option: ");
    printf("\n");

}


//this function (addTask) works in conjuction with the createTask function to create and add tasks to the list
//the addTask function also asks for user input to add a task to
P_NODE addTask(P_NODE list) {

    char task[MAXLEN];

    printf("Please insert the task: \n");

    fgets(task, MAXLEN, stdin);
    task[strlen(task) - 1] = '\0';


    P_NODE newTask = createTask(task);
    list = updateList(list, newTask);

    return list;
}

P_NODE createTask(char task[])
{
    P_NODE newTask = (P_NODE)malloc(sizeof(NODE));
    //newTask->val = val;
    strcpy(newTask->task, task);

    newTask->next = NULL;

    return newTask;
}

//this function updates the list when adding, deleting or getting the order of a task
P_NODE updateList(P_NODE list, P_NODE newTask) {
    if (list == NULL)
    {
        list = newTask;
    }
    else
    {
        P_NODE last = getLastItemInList(list);
        if (last != NULL) {
            last->next = newTask;
        }
    }
    return list;
}
//this function is the "back-end" for the "displayRecentTask" function and it gets the last task in the list, if any
P_NODE getLastItemInList(P_NODE list) {
    if (list == NULL) 
    {
        return NULL;
        
    }
    P_NODE current = list;
    P_NODE prev = NULL;
    //if the list is populated, the function will bring the latest task forward
    while (current != NULL)
    {
        prev = current;
        current = current->next;
    }
    return prev;
}

//this function deletes a task from the list
P_NODE deleteTask(P_NODE list)
{
   
    if (list == NULL)
    {
        printf("No tasks available to delete!\n");
        return;
    }
    char search_task[MAXLEN];
    printf("Please enter the task to be removed: ");
    fgets(search_task, MAXLEN, stdin);
    search_task[strlen(search_task) - 1] = '\0';

    //
    P_NODE current = list;
    P_NODE prev = NULL;
    //
    do {
        //compares the string value from the node to the string value received from the user
        //if the strings are the same, the task will be deleted
        if (strcmp(current->task, search_task) == 0) 
        { // Match found
            if (prev == NULL) 
            { // At the head of the list
                list = current->next;
            }
            else 
            {
                prev->next = current->next;
            }
            free(current);
            return list;
        }

        prev = current;
        current = current->next;

    } 
    while (current != NULL);
}

//this function is the "front-end" and it lets the user know the what the last task in the list is, if any
P_NODE displayRecentTask(P_NODE list) {


    if (list == NULL) 
    {
        printf("No task to display!\n");
        return NULL;
    }

    P_NODE mostRecent = getLastItemInList(list);

    printf("This is the most recent task within the list: %s\n", mostRecent->task);
}

//this function displays the oldest (or first) task in the list
P_NODE displayOldestTask(P_NODE list) {

    if (list == NULL) 
    {
        return NULL;
    }

    P_NODE currentTask = list;

    if (currentTask == NULL) 
    {
        return NULL;
    }
    else {
        printf("%s\n", currentTask->task);
    }

    printf("This is the oldest task within the list: %s\n", currentTask->task);
    return;
}

//this function displays a range of tasks, if any from the user's choice.
P_NODE displayRangeOfTasks(P_NODE list) {

    int i;
    int end;

    if (list == NULL) 
    {
        return NULL;
    }

    P_NODE currentTask = list;

    if (currentTask == NULL) 
    {
        return NULL;
    }

    printf("How many tasks would you like shown?\n");
    scanf_s("%d", &end);

    for (i = 0; i < end; i++) 
    {
        printf("%s\n", currentTask->task);
        currentTask = currentTask->next;
    }
    printOptions();
}

// this function displays all the available tasks within a list, if any are available
P_NODE displayAllTasks(P_NODE list) {

    if (list == NULL) 
    {
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
//this function asks the user to input the name of a specific task within a list, and, if any exist or match the user's input, the task will be displayed
P_NODE searchTask(P_NODE list)
{
    char search_task[MAXLEN];
    printf("Please enter the task you would like to search: ");
    fgets(search_task, MAXLEN, stdin);
    search_task[strlen(search_task) - 1] = '\0';

    if (list == NULL) // No list to search for task
    {
        printf("There are no tasks in the list.\n");
        return NULL;
    }
    if (list->next == NULL) // Only one task in the list
    {
        if (strcmp(list->task, search_task) == 1)
        {
            printf("There is a match!\n");
            return list;
        }
        else
        {
            printf("There is no match!\n");
            return NULL;
        }
    }

    P_NODE currentTask = list;
    while (currentTask->next != NULL) // There are multiple tasks in the list
    {
        if (!strcmp(currentTask->task, search_task))
        {
            printf("There is a match!\n");
            return currentTask;
        }
        else
        {
            currentTask = currentTask->next;
        }
    }
    if (currentTask->next == NULL) // The search function has iterated through the list until the last task
    {
        if (!strcmp(currentTask->task, search_task))
        {
            printf("There is a match!\n");
            return currentTask;
        }
        else
        {
            printf("There is a no match!\n");
            return NULL;
        }
    }
}

//this is a File I/O function that saves the user input to a text file
void saveTasks(P_NODE list) {
    FILE* fp;
    fp = fopen("taskList.txt", "w+");
    P_NODE currentTask = list;
    while (currentTask != NULL)
    {
        fprintf(fp, "%s\n", currentTask->task);
        currentTask = currentTask->next;
    }
    fclose(fp);
}

//this is a File I/O function that reads the data, if any, from the text file that has been created
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