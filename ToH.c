#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    // Base case: If there's only one disk, just move it
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", fromRod, toRod);
        return;
    }   
    // Step 1: Move top n-1 disks from fromRod to auxRod, using toRod as auxiliary
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    // Step 2: Move the nth disk from fromRod to toRod
    printf("Move disk %d from %c to %c\n", n, fromRod, toRod);
    // Step 3: Move the n-1 disks from auxRod to toRod, using fromRod as auxiliary
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n); 
    // Start the recursion with rods A, B, and C
    towerOfHanoi(n, 'A', 'C', 'B');  
    return 0;
}
