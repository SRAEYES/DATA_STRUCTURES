#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void CLT(struct Node *head){
    struct Node *ptr = head;
   do{
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    } while(ptr!=head);
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
    head->next=second;

    second ->data=22;
    second->next=third;

    third->data=50;
    third->next=head;

    CLT(head);
}