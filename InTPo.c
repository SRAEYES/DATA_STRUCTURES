#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Function to push an operator onto the stack
void push(char op) {
    if (top < MAX - 1) {
        stack[++top] = op;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an operator from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Function to check the precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            push(ch);
        }
        // If the character is ')', pop and add to output until '(' is found
        else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop '(' from the stack
        }
        // If the character is an operator
        else {
            while (top >= 0 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all remaining operators in the stack
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
