/* C program for sortAndFindMedian
 * Author : Saikiran Voddaboina
 * Email ID : voddaboinas@gmail.com */



#include <stdio.h>
#include <stdlib.h>

// Function to sort the array using Bubble Sort
void sort(int *numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the median
double sortAndFindMedian(int *numbers, int n) {
    sort(numbers, n); // Sort the array

    // Calculate median
    if (n % 2 == 0) {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else {
        return numbers[n / 2];
    }
}

int main() {
    int n;

    // Get the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Calculate and print the median
    double median = sortAndFindMedian(numbers, n);
    printf("The median is: %.2f\n", median);

    free(numbers); // Free allocated memory
    return 0;
}
