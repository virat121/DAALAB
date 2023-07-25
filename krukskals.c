#include <stdio.h>
#include <stdlib.h>

#define MAX_HOUSES 100
#define MAX_PIPES 500

struct WaterPipe {
    int house1, house2, cost;
};

// Function to compare water pipes based on their cost (used for sorting)
int compareWaterPipes(const void* a, const void* b) {
    return ((struct WaterPipe*)a)->cost - ((struct WaterPipe*)b)->cost;
}

/* int findParent(int house, int* parent) {
    if (parent[house] != house)
        parent[house] = findParent(parent[house], parent);
    return parent[house];
} */


//using path compression
int findParent(int house, int* parent) {
    if (parent[house] == house)
        return parent[house];
    return parent[house] = findParent(parent[house],parent);
}

void performUnion(int house1, int house2, int* parent, int* rank) {
    int root1 = findParent(house1, parent);
    int root2 = findParent(house2, parent);
    
    if (rank[root1] < rank[root2])
        parent[root1] = root2;
    else if (rank[root1] > rank[root2])
        parent[root2] = root1;
    else {
        parent[root2] = root1;
        rank[root1]++;
    }
}

void minimumSpanningTree(int totalHouses, int totalPipes, struct WaterPipe pipes[]) {
    struct WaterPipe result[MAX_HOUSES]; // MST can have at most totalHouses-1 pipes
    int parent[MAX_HOUSES];
    int rank[MAX_HOUSES];
    
    for (int i = 0; i < totalHouses; i++) {
        parent[i] = i; // Initially, each house is its own parent
        rank[i] = 0;   // Ranks are initially 0
    }

    qsort(pipes, totalPipes, sizeof(struct WaterPipe), compareWaterPipes);

    int mstPipes = 0;
    int i = 0;

    while (mstPipes < totalHouses - 1 && i < totalPipes) {
        struct WaterPipe nextPipe = pipes[i++];
        
        int house1Parent = findParent(nextPipe.house1, parent);
        int house2Parent = findParent(nextPipe.house2, parent);

        if (house1Parent != house2Parent) {
            result[mstPipes++] = nextPipe;
            performUnion(house1Parent, house2Parent, parent, rank);
        }
    }

    printf("Minimum Spanning Tree water pipes:\n");
    int totalCost = 0;
    for (int j = 0; j < mstPipes; j++) {
        printf("House %d - House %d (Cost: %d)\n", result[j].house1, result[j].house2, result[j].cost);
        totalCost += result[j].cost;
    }
    printf("Total cost of the minimum spanning tree: %d\n", totalCost);
}

int main() {
    int totalHouses, totalPipes; // Number of houses and water pipes in the layout
    printf("Enter the number of houses: ");
    scanf("%d", &totalHouses);
    printf("Enter the number of water pipes: ");
    scanf("%d", &totalPipes);

   /*  if (totalHouses > MAX_HOUSES || totalPipes > MAX_PIPES) {
        printf("Maximum number of houses is %d and maximum number of water pipes is %d\n", MAX_HOUSES, MAX_PIPES);
        return 1;
    } */

    struct WaterPipe pipes[MAX_PIPES];

    printf("Enter the water pipe list (house1 house2 cost) for each pipe:\n");
    for (int i = 0; i < totalPipes; i++) {
        scanf("%d %d %d", &pipes[i].house1, &pipes[i].house2, &pipes[i].cost);
    }

    minimumSpanningTree(totalHouses, totalPipes, pipes);

    return 0;
}
