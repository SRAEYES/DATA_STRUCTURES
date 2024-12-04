#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

// Stack structure definition
struct stack {
    int top;
    double items[MAXCOLS];
};

// Function prototypes
double eval(char expr[]);
double pop(struct stack* s);
void push(struct stack* s, double value);
int isEmpty(struct stack* s);
double operate(int symbol, double op1, double op2);

int main() {
    char expr[MAXCOLS];
    int position = 0;
    char ch;

    printf("Enter a postfix expression: ");
    while ((ch = getchar()) != '\n' && position < MAXCOLS - 1) {
        expr[position++] = ch;
    }
    expr[position] = '\0';

    printf("\nThe original postfix expression is: %s\n", expr);
    printf("\nResult of evaluation: %f\n", eval(expr));

    return 0;
}

// Evaluate a postfix expression
double eval(char expr[]) {
    struct stack operandStack;
    operandStack.top = -1; // Initialize stack

    int position = 0;
    char symbol;
    double op1, op2, value;

    while ((symbol = expr[position++]) != '\0') {
        if (isdigit(symbol)) {
            // Convert character to double and push onto stack
            push(&operandStack, (double)(symbol - '0'));
        } else {
            // Operator
            op2 = pop(&operandStack);
            op1 = pop(&operandStack);
            value = operate(symbol, op1, op2);
            push(&operandStack, value);
        }
    }
    return pop(&operandStack); // Final result
}

// Push a value onto the stack
void push(struct stack* s, double value) {
    if (s->top < MAXCOLS - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

// Pop a value from the stack
double pop(struct stack* s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Check if the stack is empty
int isEmpty(struct stack* s) {
    return s->top == -1;
}

// Perform an operation on two operands
double operate(int symbol, double op1, double op2) {
    switch (symbol) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 != 0)
                return op1 / op2;
            else {
                printf("Error: Division by zero\n");
                exit(1);
            }
        case '^': return pow(op1, op2);
        default:
            printf("Error: Illegal operation\n");
            exit(1);
    }
}
