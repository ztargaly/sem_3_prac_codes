#include <stdio.h>

int main(void)
{
    int array1[10][10], i, j, m, n, sum = 0;

    printf("Enter no. of rows :: ");
    scanf("%d", &m);

    printf("\nEnter no. of cols :: ");
    scanf("%d", &n);

    printf("\nEnter values to the matrix :: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\nEnter a[%d][%d] value :: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    printf("\nThe Diagonals elements of a matrix are :: \n\n");
    if (m == n) {
        for (i = 0; i < n; i++) {
            if (i == n - j - 1) {
                printf("\t%d", array1[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n\n");
    } else {
        printf("\nMatrix is not a Square Matrix.");
    }

    return 0;
}
