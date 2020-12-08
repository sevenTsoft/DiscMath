#include <stdio.h>
#define INF 9999
#define N 7

void dijkstra(int graph[N][N], int size, int start) {
    int weight_matrix[N][N], distance[N] = {0}, previous[N] = {0};
    int visited[N] = {0}, count, min_distance, next_vertex, i, j;

    for (i = 0; i < size; ++i) //Будуємо матрицю ваг
        for (j = 0; j < size; ++j) 
            if (graph[i][j] == 0) 
                weight_matrix[i][j] = INF;
            else 
                weight_matrix[i][j] = graph[i][j];
        
    for (i = 0; i < size; ++i) { // задаємо вхідні дані, тобто 1 рядок з матриці ваг записуємо в distance, і обнуляємо масив відвіданих вершин
        distance[i] = weight_matrix[start][i];
        visited[i] = 0;
    }

    distance[start] = 0; // задаємо стартову вершину 'a'
    visited[start] = 1; // позначаємо стартову вершину як відвідану
    count = 1;

    while (count < size - 1) { // цикл для пошуку найкоротшого шляху від 1 до 6, оскільки шукаємо шлях від 'a' до 6-ти інших вершин
        min_distance = INF; // задаємо поточний найкоротший шлях

        for (i = 0; i < size; ++i) 
            if (distance[i] < min_distance && !visited[i]) { // вибираємо вершину, відстань в яку з 'a' найменша на даний момент, і ця вершина не відвідана
                min_distance = distance[i]; 
                next_vertex = i;
            }

        visited[next_vertex] = 1; // позначаємо вибрану вершину, як відвідану

        for (i = 0; i < size; ++i) // з визначеної раніше вершини шукаємо всі можливі шляхи в інші вершини 
            if (!visited[i]) 
                if (min_distance + weight_matrix[next_vertex][i] < distance[i]) {
                    distance[i] = min_distance + weight_matrix[next_vertex][i]; // визначаємо поточну відстань від 'a' до вершини, в яку прийшли з минулої вершини
                }
            count++; // повторюємо
    }

    for (i = 0; i < size; ++i) { // виводимо результати на екран
        if (i != start) {
            if (i == 1) {
                printf("\nВідстань від 'a' до 'b' = %d,\n", distance[i]);
            } else if (i == 2) {
                printf("\nВідстань від 'a' до 'c' = %d,\n", distance[i]);
            } else if (i == 3) {
                printf("\nВідстань від 'a' до 'd' = %d,\n", distance[i]);
            } else if (i == 4) {
                printf("\nВідстань від 'a' до 'e' = %d,\n", distance[i]);
            } else if (i == 5) {
                printf("\nВідстань від 'a' до 'f' = %d,\n", distance[i]);
            } else if (i == 6) {
                printf("\nВідстань від 'a' до 'g' = %d.\n\n", distance[i]);
            }
        }
    }
}