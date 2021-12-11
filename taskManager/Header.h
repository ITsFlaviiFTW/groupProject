// PROG71985 - Group Project
// Task Manager Header File
// Dante Palalas-Mouradian DEC / 2021
// Flavius Porumbiel       DEC / 2021
// Hayden Auterhoff        DEC / 2021

//Version History
// 0.1 created the struct called "node" as well as populating it with fields
// 0.2 created the addTask, deleteTask, createTask and File I/O prototypes to connect to the respective called functions
// 0.3 created display (displayAllTasks, displayRangeOfTasks) prototypes to connect to the respective called functions
// 0.4 created updateList prototype to connect to the respective called function
// 0.5 created displayRecentTask prototype to connect to the respective called function
// 0.6 created displayOldestTask prototype to connect to the respective called function
// 0.7 added comments and cleaned up code



#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXLEN 100
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    int val;
    char task[MAXLEN];
    struct node* next;
} NODE, * P_NODE;

void printOptions();
P_NODE addTask(P_NODE);
P_NODE createTask(char[]);
P_NODE updateList(P_NODE, P_NODE);
P_NODE deleteTask(P_NODE);
P_NODE displayRecentTask(P_NODE);
P_NODE displayOldestTask(P_NODE);
P_NODE displayRangeOfTasks(P_NODE);
P_NODE displayAllTasks(P_NODE);
P_NODE searchTask(P_NODE);
P_NODE getLastItemInList(P_NODE);
void saveTasks(P_NODE);
P_NODE readTasks(P_NODE);

