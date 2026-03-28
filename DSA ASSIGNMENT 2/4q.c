#include <stdio.h>
#include <string.h>

// Maximum number of documents in the queue 
#define MAX 10
#define DOC_LEN 50

// Queue structure for printer 
char queue[MAX][DOC_LEN];
int front = -1, rear = -1, size = 0;

// Check if queue is full 
int isFull() {
    return size == MAX;
}

// Check if queue is empty 
int isEmpty() {
    return size == 0;
}

// Add document to the queue 
void addDocument(char docName[]) {
    if (isFull()) {
        printf("Printer queue is full! Cannot add '%s'.\n", docName);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    strcpy(queue[rear], docName);
    size++;
    printf("Document '%s' added to the printer queue.\n", docName);
}

// Print (remove) the front document 
void printDocument() {
    if (isEmpty()) {
        printf("No pending documents in the queue.\n");
        return;
    }
    printf("Printing document: '%s'\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    size--;
}

// Display all pending documents 
void displayQueue() {
    if (isEmpty()) {
        printf("No pending documents. Queue is empty.\n");
        return;
    }
    printf("\n--- Pending Documents (%d) ---\n", size);
    int i = front, count = 0;
    while (count < size) {
        printf("  %d. %s\n", count + 1, queue[i]);
        i = (i + 1) % MAX;
        count++;
    }
    printf("------------------------------\n");
}

int main() {
    int choice;
    char docName[DOC_LEN];

    printf("===== Printer Queue Simulation =====\n");

    do {
        printf("\n1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Pending Documents\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); //flush newline 

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                fgets(docName, DOC_LEN, stdin);
                docName[strcspn(docName, "\n")] = '\0'; //remove newline 
                addDocument(docName);
                break;
            case 2:
                printDocument();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting printer queue. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
