
#include "Header.h"


void printOptions(){

    printf("\n");
    printf("Welcome to your task manager\n");
    printf("a) Add new task\n");
    printf("b) Delete an existing task\n");
    printf("c) Update an existing task\n");
    printf("d) Display most recently entered task\n");
    printf("e) Display oldest task in the list\n");
    printf("f) Display 'x' number of tasks\n");
    printf("g) Display all tasks\n");
    printf("h) Search for a task\n");
    printf("i) Quit\n");
    printf("Please enter the operation number for the desired option: ");
    printf("\n");

}



P_NODE addTask(P_NODE list) {

    char task[MAXLEN];

    printf("Please insert the task: \n");
  
    fgets(task, MAXLEN, stdin);
    task[strlen(task) - 1] = '\0';

    
    P_NODE newTask = createTask(task);
    list = updateList(list, newTask);

    return list;
}


P_NODE updateList(P_NODE list, P_NODE newTask){
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

P_NODE deleteTask(P_NODE list) {
    char search_task[MAXLEN];
    printf("Please enter the task to be removed: ");
    scanf("%s", &search_task);
    P_NODE taskToRemove = searchTask(list, search_task);

    if (list == NULL)
    {
        printf("The task list is empty, nothing to delete.");
        return list;
    }

    else
    {
        taskToRemove->prev->next = taskToRemove->next;
        taskToRemove->next->prev = taskToRemove->prev;
    }
    free(taskToRemove);

    return list;
}

P_NODE displayRecentTask(P_NODE list) {

    if (list == NULL) {

        return NULL;

    }

    P_NODE currentTask = list;

    if (currentTask == NULL) {

        return NULL;

    }

    else {

        printf("%s\n", currentTask->task);

    }

    printf("This is the most recent task within the list\n");

    return;

}

P_NODE displayOldestTask(P_NODE list) {


    if (list == NULL) {

        return NULL;

    }

    P_NODE currentTask = list;

    if (currentTask == NULL) {

        return NULL;

    }

    while (currentTask->next != NULL) {

        currentTask = currentTask->next;

    }

    printf("Your oldest task is %s\n", currentTask->task);

}

P_NODE displayRangeOfTasks(P_NODE list) {

    int i;
    int end;

    if (list == NULL) {

        return NULL;

    }

    P_NODE currentTask = list;

    if (currentTask == NULL) {

        return NULL;

    }

    printf("How many tasks would you like shown?\n");
    scanf_s("%d", &end);

    for (i = 0; i < end; i++) {

        printf("%s\n", currentTask->task);
        currentTask = currentTask->next;


    }


}


P_NODE displayAllTasks(P_NODE list) {

    if (list == NULL) {

        return NULL;

    }

    P_NODE currentTask = list;

    if (currentTask == NULL) {

        return NULL;

    }

    while (currentTask != NULL) {

        printf("%s\n", currentTask->task);
        currentTask = currentTask->next;

    }

    printf("These are all tasks within the list\n");

    return;

}

P_NODE searchTask(P_NODE list, char search_task[]) {
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

void readTasks(P_NODE list) {
    FILE* fp;
    fp = fopen("taskList.txt", "r+");
    char tempVal[MAXLEN];
    char tempTask[MAXLEN];

    while (fgets(tempVal, MAXLEN, fp) != NULL)
    {

    }
}