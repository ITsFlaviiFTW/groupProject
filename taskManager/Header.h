#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int val;
    struct node* next;
};
struct node* head;

void printOptions();
void addTask();
void deleteTask();
void displayRangeTask();
void displayTask();