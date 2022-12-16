#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

int *pstack;
int nTop;

void push(int n) {
  printf("\nPush element: %d\n", n);
  if (nTop >= STACK_SIZE - 1) {
    printf("Error: Stack overflow\n");
    return;
  }
  nTop++;
  pstack[nTop] = n;
}

void pop() {
  printf("\nPop topmost element\n");
  if (nTop < 0) {
    printf("Error: Stack underflow\n");
    return;
  }
  pstack[nTop] = -1;
  nTop--;
}

void DisplayStack() {
  int i;
  if (nTop < 0) {
    printf("\nStack is empty\n");
  } else {
    printf("\nDisplay Stack: ");
    for (i = 0; i <= nTop; i++) {
      printf("%d ", pstack[i]);
    }
    printf("\n");
  }
}

int main() {
  int nsize = STACK_SIZE;
  pstack = (int *)malloc(sizeof(int) * STACK_SIZE);
  push(10);
  push(12);
  DisplayStack();
  pop();
  DisplayStack();
  push(45);
  push(24);
  push(12);
  DisplayStack();
  pop();
  pop();
  DisplayStack();
  free(pstack);  // free dynamically allocated memory to prevent a memory leak
  return 0;
}
