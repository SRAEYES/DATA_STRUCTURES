#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// INSERT VALUE AT FIRST 
struct Node *InsertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr; // If the list is empty, new node points to itself
        return ptr;
    }

    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = ptr; // Last node now points to the new node
    ptr->next = head; // New node points to the head
    head = ptr;       // New node becomes the head

    return head;
}

// INSERT AT PARTICULAR INDEX
struct Node *InsertAtIndex(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    if (index == 0) {
        return InsertAtFirst(head, data); // If index is 0, insert at the beginning
    }

    while (i != index - 1 && p->next != head) {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// INSERT AT LAST 
struct Node *InsertAtLast(struct Node *head, int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;

    if (head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = ptr; // Last node points to the new node
    ptr->next = head; // New node points to the head

    return head;
}

// DELETE AT BEGINNING
struct Node *DeleteAtBeginning(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node *ptr = head;
    struct Node *temp = head;

    // If there is only one node in the list
    if (head->next == head) {
        free(head);
        return NULL;
    }

    // Move to the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    head = head->next;
    temp->next = head; // Last node now points to the new head
    free(ptr);

    return head;
}

// DELETE AT INDEX
struct Node *DeleteAtIndex(struct Node *head, int index) {
    if (head == NULL) {
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    // If deleting the head
    if (index == 0) {
        return DeleteAtBeginning(head);
    }

    for (int i = 0; i < index - 1 && q->next != head; i++) {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

// DELETE AT LAST 
struct Node *DeleteAtEnd(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    // If there's only one node
    if (head->next == head) {
        free(head);
        return NULL;
    }

    // Traverse to the last node
    while (q->next != head) {
        p = p->next;
        q = q->next;
    }

    p->next = head; // Second last node points to head
    free(q);

    return head;
}

// DISPLAY THE CIRCULAR LINKED LIST
void CLinkListTraversal(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *ptr = head;
    do {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main() {
    // CREATING LINKED LIST 
    struct Node *head = NULL;

    // INSERTING AND DELETING ELEMENTS
    printf("INSERTION AT BEGINNING\n");
    head = InsertAtFirst(head, 56);
    CLinkListTraversal(head);

    printf("INSERTION AT BEGINNING\n");
    head = InsertAtFirst(head, 25);
    CLinkListTraversal(head);

    printf("INSERTION AT INDEX\n");
    head = InsertAtIndex(head, 90, 1);
    CLinkListTraversal(head);

    printf("INSERTION AT LAST\n");
    head = InsertAtLast(head, 10);
    CLinkListTraversal(head);

    printf("DELETION AT BEGINNING\n");
    head = DeleteAtBeginning(head);
    CLinkListTraversal(head);

    printf("DELETION AT PARTICULAR INDEX\n");
    head = DeleteAtIndex(head, 1);
    CLinkListTraversal(head);

    printf("DELETION AT LAST\n");
    head = DeleteAtEnd(head);
    CLinkListTraversal(head);

    return 0;
}
