// Lab Program-7
// Date:- 06-May-2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1; // as it is zero-based indexing so left child is at (2*i +1)
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        // swapping
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // heapify
        max_heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        // swapping
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        max_heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the number of resumes: ");
    scanf("%d", &n);

    int *rankings = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        rankings[i] = rand() % 100;
    }

    printf("Rankings of resumes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", rankings[i]);
    }
    printf("\n");

    clock_t time = clock();
    heapSort(rankings, n); // calling heap sort function
    time = clock() - time;

    printf("Sorted Rankings:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", rankings[i]);
    }
    printf("\n");

    double runtime = (double)(time) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", runtime);

    free(rankings);
    return 0;
}
