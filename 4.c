// ARRAY OF STRUCTURES 

#include <stdio.h>

struct car {
    int fuel_tank_cap;
    int seating_cap;
    float mileage;
};

int main() {
    struct car c[3];
    for (int i = 0; i < 3; i++) { // Changed condition to i < 3
        printf("Enter The Fuel Tank Capacity of car %d: ", i + 1);
        scanf("%d", &c[i].fuel_tank_cap);
        printf("Enter Seating Capacity of car %d: ", i + 1);
        scanf("%d", &c[i].seating_cap);
        printf("Enter Mileage of car %d: ", i + 1);
        scanf("%f", &c[i].mileage);

        printf("\n");
        printf("DETAILS OF CAR %d:\n", i + 1);
        printf("FUEL CAPACITY: %d\n", c[i].fuel_tank_cap);
        printf("SEATING CAPACITY: %d\n", c[i].seating_cap);
        printf("MILEAGE: %.2f\n\n", c[i].mileage);
    }
    return 0;
}
