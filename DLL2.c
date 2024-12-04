#include<stdio.h>
#include<stdlib.h>

// CREATING A NODE 
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// INSERT VALUE AT FIRST 
struct Node *InsertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;

    if (head != NULL) {
        head->prev = ptr;
    }

    return ptr;
}

// INSERT AT PARTICULAR INDEX
struct Node *InsertAtIndex(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;

    return head;
}

// INSERT AT LAST 
struct Node *InsertAtLast(struct Node *head, int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;

    if (head == NULL) {
        ptr->prev = NULL;
        return ptr; // If the list is empty, the new node becomes the head
    }

    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

// DELETE AT BEGINNING
struct Node *DeleteAtBeginning(struct Node *head) {
    if (head == NULL) {
        return NULL; // Handle empty list
    }

    struct Node *ptr = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(ptr);

    return head;
}

// DELETE AT INDEX
struct Node *DeleteAtIndex(struct Node *head, int index) {


    struct Node *p = head;
    struct Node *q = NULL;

    // Traverse to the node at the given index
    for (int i = 0; i < index; i++) {
        p = p->next;
    }

    q = p->prev;

    free(p);

    return head;
}

// DELETE AT LAST
struct Node *DeleteAtEnd(struct Node *head) {
    if (head == NULL) {
        return NULL; // Handle empty list
    }

    struct Node *p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    if (p->prev != NULL) {
        p->prev->next = NULL;
    } else { // If there is only one node
        head = NULL;
    }

    free(p);

    return head;
}

// DISPLAYING VALUES 
void display(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    // CREATING DOUBLY LINKED LIST 
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    // ALLOCATING MEMORY FOR IT 
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // PROVIDING DATA AND CONNECTING ALL NODES
    head->data = 25;
    head->next = second;
    head->prev = NULL;

    second->data = 35;
    second->next = third;
    second->prev = head;

    third->data = 11;
    third->next = fourth;
    third->prev = second;

    fourth->data = 3;
    fourth->next = NULL;
    fourth->prev = third;

    printf("BEFORE INSERTION\n");
    display(head);

    printf("INSERTION AT BEGINNING\n");
    head = InsertAtFirst(head, 56);
    display(head);

    printf("INSERTION AT INDEX\n");
    head = InsertAtIndex(head, 90, 2);
    display(head);

    printf("INSERTION AT LAST\n");
    head = InsertAtLast(head, 10);
    display(head);

    printf("DELETION AT BEGINNING\n");
    head = DeleteAtBeginning(head);
    display(head);

    printf("DELETION AT PARTICULAR INDEX\n");
    head = DeleteAtIndex(head, 2);
    display(head);

    printf("DELETION AT LAST\n");
    head = DeleteAtEnd(head);
    display(head);

    return 0;
}
