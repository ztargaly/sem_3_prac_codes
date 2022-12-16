#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    // Declare and initialize two arrays to represent the sets
    int set1[MAX_SIZE] = {1, 2, 3, 4, 5};
    int set2[MAX_SIZE] = {3, 4, 5, 6, 7};
    int intersection[MAX_SIZE];
    int i, j, k = 0;

    // Loop through the elements of set1
    for (i = 0; i < MAX_SIZE && set1[i] != 0; i++) {
        // Loop through the elements of set2
        for (j = 0; j < MAX_SIZE && set2[j] != 0; j++) {
            // Check if the elements are equal
            if (set1[i] == set2[j]) {
                // Add the element to the intersection set
                intersection[k] = set1[i];
                k++;
            }
        }
    }

    // Print the intersection set
    printf("Intersection: {");
    for (i = 0; i < k; i++) {
        printf(" %d", intersection[i]);
    }
    printf(" }\n");

    return 0;
}
