#include <stdio.h>

// Maximum capacity of circular queue 
#define MAX 6

// Circular queue array and pointers
int cqueue[MAX];
int front = -1, rear = -1;

// Check if circular queue is full 
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Check if circular queue is empty 
int isEmpty() {
    return (front == -1);
}

// Insert element into circular queue 
void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is FULL! Cannot insert %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    cqueue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Remove element from circular queue 
void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is EMPTY! Nothing to remove.\n");
        return;
    }
    printf("Dequeued: %d\n", cqueue[front]);
    if (front == rear) {
        // Only one element was present 
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display front element without removing 
void peek() {
    if (isEmpty()) {
        printf("Circular Queue is EMPTY! No front element.\n");
        return;
    }
    printf("Front element (Peek): %d\n", cqueue[front]);
}

// Display all elements in the circular queue 
void display() {
    if (isEmpty()) {
        printf("Circular Queue is EMPTY!\n");
        return;
    }
    printf("\n--- Circular Queue Elements ---\n");
    printf("Front -> ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("<- Rear\n");
    printf("-------------------------------\n");
}

int main() {
    int choice, value;

    printf("===== Circular Queue Operations =====\n");

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
