#include<stdio.h>

int main(){
    char name[50];
    int roll_no;
    float CGPA;

    printf("Enter Ur Name : ");
    scanf("%49s",&name);

    printf("Enter Ur Roll Nnumber : ");
    scanf("%d",&roll_no);

    printf("Enter Ur CGPA : ");
    scanf("%f",&CGPA);

    printf(" Name : %s\n",name);
    printf(" Roll No : %d\n",roll_no);
    printf(" CGPA : %.2f\n",CGPA);
}