#include <stdio.h>


int main () {

    int numbers[5] = {10, 20 ,30 ,60 ,80}; // Define Array
    int value = numbers[2]; // Accesses the element in the array
    int size = sizeof(numbers) / sizeof(numbers[0]); // Calculates the number of elements in the array

    int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    }; // Define Matrix

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    } // Read Matrix

   return 0;
}