#include<stdio.h>

struct car {
    int fuel_tank_cap;
    int seating_cap;
    float mileage;
};

int main()
{
    struct car c[3];
     for(int i=0;i<=3;i++){
        printf("Enter The Fuel Tank Capacity of car %d : ");
        scanf("%d",&c[i].fuel_tank_cap);
        printf("Enter seating capacity of car %d : ");
        scanf("%d",&c[i].seating_cap);
        printf("Enter Mileage of car %d : ");
        scanf("%f",&c[i].mileage);

        printf("DETAILS OF %d ST CAR ");
        printf("FUEL CAPACITY IS ",&c[i].fuel_tank_cap);
        printf("SEATING CAPACITY IS ",&c[i].seating_cap);
        printf("MILEAGE IS ",&c[i].mileage);

        return 0;

     }
}