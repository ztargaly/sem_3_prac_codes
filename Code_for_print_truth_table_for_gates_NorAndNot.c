#include <stdio.h>

int main() {
  // Define the input values for x and y
  int x[2] = {0, 1};
  int y[2] = {0, 1};

  // Print the header row
  printf("| x | y | x && y | x || y | !x |\n");
  printf("| - | - | ------ | ------ | --- |\n");

  // Iterate through all possible combinations of x and y
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      // Print the row for this combination of x and y
      printf("| %d | %d | %d      | %d      | %d   |\n", x[i], y[j], x[i] && y[j], x[i] || y[j], !x[i]);
    }
  }

  return 0;
}
