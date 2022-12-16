#include <iostream>
using namespace std;

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
   cout << "In Diagonal Form: " << endl;
   for (int i = 0; i < 3; i++) {
      cout << compact_Form[i] << " ";
   }

   cout << endl << endl << "Displaying the original Matrix: " << endl;
   // Iterate through diagonal_Matrix and display its elements
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         // If the current element is on the diagonal, display the element from compact_Form
         if (i == j) {
            cout << compact_Form[i] << " ";
         } 
         // Otherwise, display the element from diagonal_Matrix
         else {
            cout << diagonal_Matrix[i][j] << " ";
         }
      }
      cout << endl;
   }

   return 0;
}
