//
// Created by Максим on 12.01.2021.
//

#ifndef DISCMATH_SOURCENATHERION_H
#define DISCMATH_SOURCENATHERION_H

#include <ctype.h>
#define INF 9999
#define N 7

// Dijkstra algorithm
void dijkstra(int graph[N][N], int size, int start);

// Infix to postfix
int priority (char var);
char* to_postfix (char postfix_string[]);

#endif //DISCMATH_SOURCENATHERION_H
