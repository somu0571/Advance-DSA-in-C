#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue() {
    int val;
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1) front = 0;
        printf("Enter value to insert: ");
        scanf("%d", &val);
        rear++;
        queue[rear] = val;
        printf("%d inserted.\n", val);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        front = rear = -1;
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Queue Operations ---\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}