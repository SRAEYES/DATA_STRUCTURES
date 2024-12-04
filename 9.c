/*
Create a structure called "Student" with members name, age, and total marks.
 Write a C program to input data for two students, display their information, 
 and find the average of total marks.
*/

#include<stdio.h>

struct Student 
{
    char Name[50];
    int Age;
    float Marks;
};

int main(){
    float Total_Marks;
    struct Student student1,student2;
    printf("Student 1 Information \n");
    printf("Enter Name : ");
    scanf("%s",&student1.Name);

    printf("Enter Age : ");
    scanf("%d",&student1.Age);

    printf("Enter Marks : ");
    scanf("%f",&student1.Marks);
    
    printf("Student 2 Information \n");
    printf("Enter Name : ");
    scanf("%s",&student2.Name);

    printf("Enter Age : ");
    scanf("%d",&student2.Age);

    printf("Enter Marks : ");
    scanf("%f",&student2.Marks);
    
    Total_Marks = student1.Marks+student2.Marks;
    printf("Total_Marks : %.2f",Total_Marks);

    return 0;
}