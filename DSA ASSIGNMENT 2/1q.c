#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure 
char stack[MAX];
int top = -1;

// Push character onto stack 
void push(char c) {
    stack[++top] = c;
}

// Pop character from stack 
char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Push all characters onto stack 
    for (int i = 0; i < len; i++)
        push(str[i]);

    // Pop characters to reverse 
    for (int i = 0; i < len; i++)
        str[i] = pop();

    printf("Reversed string: %s\n", str);
    return 0;
}