#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push onto stack 
void push(char c) {
    stack[++top] = c;
}

// Pop from stack 
char pop() {
    return stack[top--];
}

// Check if stack is empty 
int isEmpty() {
    return top == -1;
}

int main() {
    char expr[MAX];
    int balanced = 1;

    printf("Enter expression: ");
    scanf("%s", expr);

    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') {
            push(expr[i]);          // Push opening bracket
        } else if (expr[i] == ')') {
            if (isEmpty()) {        // No matching opening bracket 
                balanced = 0;
                break;
            }
            pop();                  // Match found, pop 
        }
    }

    // Stack must be empty for balanced expression 
    if (balanced && isEmpty())
        printf("Balanced Expression\n");
    else
        printf("Unbalanced Expression\n");

    return 0;
}