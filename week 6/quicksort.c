#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int partitionFirstPivot(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;

        if (i < j)
            swap(&a[i], &a[j]);
        else
            break;
    }
    swap(&a[low], &a[j]);
    return j;
}

void quickSortFirstPivot(int a[], int low, int high) {
    if (low < high) {
        int p = partitionFirstPivot(a, low, high);
        quickSortFirstPivot(a, low, p - 1);
        quickSortFirstPivot(a, p + 1, high);
    }
}

int partitionLastPivot(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSortLastPivot(int a[], int low, int high) {
    if (low < high) {
        int p = partitionLastPivot(a, low, high);
        quickSortLastPivot(a, low, p - 1);
        quickSortLastPivot(a, p + 1, high);
    }
}

int partitionRandomPivot(int a[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&a[randomIndex], &a[high]);
    return partitionLastPivot(a, low, high);
}

void quickSortRandomPivot(int a[], int low, int high) {
    if (low < high) {
        int p = partitionRandomPivot(a, low, high);
        quickSortRandomPivot(a, low, p - 1);
        quickSortRandomPivot(a, p + 1, high);
    }
}

int main() {
    srand(time(NULL));

    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], b[n], c[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
    }

    printf("\nChoose Quick Sort Method:\n");
    printf("1. Pivot = First Element\n");
    printf("2. Pivot = Last Element\n");
    printf("3. Pivot = Random Element\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("\nOriginal Array: ");
    printArray(a, n);

    switch (choice) {
        case 1:
            quickSortFirstPivot(a, 0, n - 1);
            printf("\nSorted Array (First Pivot): ");
            printArray(a, n);
            break;

        case 2:
            quickSortLastPivot(b, 0, n - 1);
            printf("\nSorted Array (Last Pivot): ");
            printArray(b, n);
            break;

        case 3:
            quickSortRandomPivot(c, 0, n - 1);
            printf("\nSorted Array (Random Pivot): ");
            printArray(c, n);
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}
