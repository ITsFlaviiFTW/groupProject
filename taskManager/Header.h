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
    struct node* prev;
} NODE, * P_NODE;

void printOptions();
P_NODE addTask(P_NODE);
P_NODE updateList(P_NODE, P_NODE);
P_NODE deleteTask(P_NODE);
P_NODE displayRecentTask(P_NODE);
P_NODE displayOldestTask(P_NODE);
P_NODE displayRangeOfTasks(P_NODE);
P_NODE displayAllTasks(P_NODE);
P_NODE searchTask(P_NODE, char[]);
void saveTasks(P_NODE);

