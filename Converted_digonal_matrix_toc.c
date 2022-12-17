#include <stdio.h>

int main() {
// Declare and initialize diagonal_Matrix
int diagonal_Matrix[3][3] = {{5,0,0}, {0,6,0}, {0,0,2}};

// Declare compact_Form
int compact_Form[3];

// Iterate through diagonal_Matrix and store the diagonal elements in compact_Form
for (int i = 0; i < 3; i++) {
compact_Form[i] = diagonal_Matrix[i][i];
}
// Display compact_Form
printf("In Diagonal Form: \n");
for (int i = 0; i < 3; i++) {
printf("%d ", compact_Form[i]);
}

printf("\n\nDisplaying the original Matrix: \n");
// Iterate through diagonal_Matrix and display its elements
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
// If the current element is on the diagonal, display the element from compact_Form
if (i == j) {
printf("%d ", compact_Form[i]);
}
// Otherwise, display the element from diagonal_Matrix
else {
printf("%d ", diagonal_Matrix[i][j]);
}
}
printf("\n");
}

return 0;
}
