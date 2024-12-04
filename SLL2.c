#include<stdio.h>
#include<stdlib.h>

// CREATING A NODE 
struct Node {
    int data;
    struct Node *next;
};

// INSERT VALUE AT FIRST 
struct Node *InsertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
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
    ptr->data = data; // setting data
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// INSERT AT LAST 
struct Node *InsertAtLast(struct Node *head, int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr; // If the list is empty, the new node becomes the head
    }

    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;

    return head;
}

// DELETE AT BEGINNING
struct Node *DeleteAtBeginning(struct Node *head) {
    
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

//DELETE AT INDEX
struct Node *DeleteAtIndex(struct Node *head,int index){
    struct Node *p = head;
    struct Node *q = head ->next;

    for (int i = 0 ; i< index-1;i++){
        p = p->next;
        q = q->next;
    }

    p ->next = q->next;
    free(q);

    return head;
}

//DELETION AT LAST 
struct Node *DeleteAtEnd(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while (q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next=NULL;
    free(q);

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
    // CREATING LINKED LIST 
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // ALLOCATING MEMORY FOR IT 
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // PROVIDING DATA AND CONNECTING ALL NODES
    head->data = 25;
    head->next = second;

    second->data = 35;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = NULL;

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
    head = DeleteAtIndex(head,2);
    display(head);

    printf("DELETION AT LAST\n");
    head=DeleteAtEnd(head);
    display(head);

    return 0;
}
