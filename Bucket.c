#include <stdio.h>
#define N 10

void bucketSort(float arr[], int n) {
    int i, j;
    float b[N][N];
    int count[N] = {0};

    for (i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi][count[bi]++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 1; j < count[i]; j++) {
            float key = b[i][j];
            int k = j - 1;
            while (k >= 0 && b[i][k] > key) {
                b[i][k + 1] = b[i][k];
                k--;
            }
            b[i][k + 1] = key;
        }
    }

    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Sorted array using Bucket Sort:\n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
    return 0;
}