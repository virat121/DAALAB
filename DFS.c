// Lab Program-3
//Date:- 9-May-2023 
#include <stdio.h>
#include <time.h>
#define MAX_SIZE 100

int visited[MAX_SIZE];

void dfs(int adj[][MAX_SIZE], int source_island, int total_islands)
{
    visited[source_island] = 1;
    printf("%d ", source_island);

    for (int i = 0; i < total_islands; i++)
    {
        if (adj[source_island][i] == 1 && visited[i] == 0)
        {
            dfs(adj, i, total_islands);
        }
    }
}

void main()
{
    int total_islands, source_island;
    int adj[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of islands: ");
    scanf("%d", &total_islands);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < total_islands; i++)
    {
        for (int j = 0; j < total_islands; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the source islands: ");
    scanf("%d", &source_island);

    printf("DFS traversal from island %d: ", source_island);

    clock_t time = clock();
    dfs(adj, source_island, total_islands);
    time = clock() - time;
    double runtime = (double)time / CLOCKS_PER_SEC;
    printf("\nThe Runtime is: %f\n", runtime);
}
