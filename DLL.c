#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void DLL(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    //Alocate memory 
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    //value assign karkei link karna hai
    head ->data=11;
    head ->prev=NULL;
    head ->next=second;

    second ->data=22;
    head ->prev=head;
    second->next=third;

    third->data=50;
    head ->prev=second;
    third->next=NULL;

    DLL(head);
}