#include<stdio.h>

struct 
{
    char *name;
    int age;
    float salary;
} emp1,emp2 ;

int manager(){
    struct
    {
    int age;
    int salary;
    } manager;

    manager.age = 27;

    if(manager.age>30){
        manager.salary = 55000;
    }
    else{
       manager.salary = 35000;
    }

    return manager.salary;
}

int main(){
    printf("Enter salary of emp1 : ");
    scanf("%d",&emp1.salary);
    printf("Enter salary of emp2 : ");
    scanf("%d",&emp2.salary);
    printf("SALARY OF EMPLOYEE 1 IS %d\n",emp1.salary);
    printf("SALARY OF EMPLOYEE 2 IS %d\n",emp2.salary);
    printf("SALARY OF MANAGER IS : %d\n",manager());

    return 0;
}