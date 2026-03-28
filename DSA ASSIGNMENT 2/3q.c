#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int peek() {
    return stack[top];
}

int main() {
    int arr[MAX], nge[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Traverse from right to left 
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements smaller or equal to current 
        while (!isEmpty() && peek() <= arr[i])
            pop();

        // If stack empty, no greater element exists 
        nge[i] = isEmpty() ? -1 : peek();

        push(arr[i]);   // Push current element 
    }

    // Print result 
    printf("\nElement -> Next Greater Element\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", arr[i], nge[i]);

    return 0;
}