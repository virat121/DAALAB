// Lab Program -2
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//only for digraph 
void bfs(int adj[][10], int total_city, int s_city)
{
    int visited[10];
    for (int i = 0; i < total_city; i++)
        visited[i] = 0;

    int q[10], front = 0, rear = -1;
    q[++rear] = s_city;
    visited[s_city] = 1;
    int curr_city; // current visited city
    printf("BFS Traversal of Dgital Map\n");
    while (front <= rear)
    {
        curr_city = q[front++];
        // v --> adjacent city
        for (int v = 0; v < total_city; v++)
        {
            if (adj[curr_city][v] == 1 && visited[v] == 0)
            {
                q[++rear] = v;
                printf("%d --> %d\n", curr_city, v);
            }
        }
    }
}

void main()
{
    int adj[10][10]; // adjacency matrix
    int total_city;  // total cities (each node as a city)
    printf("Enter total number of cities: ");
    scanf("%d", &total_city);
    printf("Enter the matrix representation of digital map:\n");
    for (int i = 0; i < total_city; i++)
        for (int j = 0; j < total_city; j++)
            scanf("%d", &adj[i][j]);
    int s_city; // source city from where traversal starts
    printf("Enter a source city: ");
    scanf("%d", &s_city);
    clock_t time_taken = clock();
    bfs(adj, total_city, s_city);
    time_taken = clock() - time_taken;
    double runtime = (double)time_taken / CLOCKS_PER_SEC;
    printf("The total runtime is %f\n", runtime);
}


