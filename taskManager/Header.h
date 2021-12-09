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
void addTask();
void deleteTask();
void displayRangeTask();
void displayTask();