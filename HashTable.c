#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            printf("Hash Table is full!\n");
            return;
        }
    }
    hashTable[(index + i) % SIZE] = key;
    printf("%d inserted at index %d\n", key, (index + i) % SIZE);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    init();
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    display();
    return 0;
}