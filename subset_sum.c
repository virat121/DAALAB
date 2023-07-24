#include <stdio.h>

#define MAX_SIZE 100

int subset[MAX_SIZE];
int sum = 0;

void findSubset(int set[], int n, int targetSum, int cindex, int csum)
{
    if (csum == targetSum)
    {
        printf("Subset with the given sum is: ");
        for (int i = 0; i < cindex; i++)
        {
            if (subset[i] != 0)
                printf("%d ", subset[i]);
        }
        printf("\n");
        sum++;
        return;
    }

    if (csum > targetSum || cindex >= n)
        return;

    subset[cindex] = set[cindex];
    findSubset(set, n, targetSum, cindex + 1, csum + set[cindex]);

    subset[cindex] = 0;
    findSubset(set, n, targetSum, cindex + 1, csum);
}

int main()
{
    int n, K;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[MAX_SIZE];

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum K: ");
    scanf("%d", &K);

    printf("Subsets with the sum %d are:\n", K);
    findSubset(set, n, K, 0, 0);

    if (sum == 0)
    {
        printf("No subset found with the given sum.\n");
    }

    return 0;
}
