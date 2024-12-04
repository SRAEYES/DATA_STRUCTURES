#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;       // Coefficient
    int power;       // Power of x
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in a polynomial
void insertNode(Node** head, int coeff, int power) {
    Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to subtract two polynomials
Node* subtractPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertNode(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            insertNode(&result, -poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            int diffCoeff = poly1->coeff - poly2->coeff;
            if (diffCoeff != 0) {
                insertNode(&result, diffCoeff, poly1->power);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertNode(&result, -poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(Node* poly) {
    while (poly != NULL) {
        if (poly->coeff > 0 && poly != NULL) {
            printf(" + ");
        }
        printf("%dx^%d", poly->coeff, poly->power);
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Create first polynomial: 3x^2 + 5x^1 + 6
    insertNode(&poly1, 3, 2);
    insertNode(&poly1, 5, 1);
    insertNode(&poly1, 6, 0);

    // Create second polynomial: 6x^1 + 8
    insertNode(&poly2, 6, 1);
    insertNode(&poly2, 8, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Node* diff = subtractPolynomials(poly1, poly2);
    printf("Difference (Poly1 - Poly2): ");
    displayPolynomial(diff);

    return 0;
}
