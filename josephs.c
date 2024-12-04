#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;

};
struct Node *head;
struct Node* createnode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;

}
void begin(int d){
    struct Node *newnode =createnode(d);
    if(head==NULL){
        head=newnode;
        newnode->next =head;
    }
    else {
        struct Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

}

void circular(int n){
    for(int i=n;i>0;i--){
        begin(i);
    }
}

// void display() {
//     if (head == NULL) {
//         printf("The list is empty.\n");
//         return;
//     }

//     struct Node* temp = head;
//     do {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("(back to head)\n");
// }



void joseph(int n,int k){
    circular(n);
    struct Node *temp=head;
    struct Node *temp1=NULL;
    while(temp->next!=temp){
        for(int i=1;i<k;i++){
        temp1=temp;
        temp=temp->next;
    }

    //elimination
    temp1->next=temp->next;
    free(temp);
    temp=temp1->next;

    }
    printf("The winner is : %d",temp->data);
}

int main(){
    joseph(5,2);
}