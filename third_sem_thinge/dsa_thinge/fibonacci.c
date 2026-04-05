#include <stdio.h>

int fibonacci(int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int number = 0;
  printf("Enter a number: ");
  if (scanf("%d", &number) == 0) {
    printf("Invalid input. Please enter an integer.");
  }
  printf("The fibonacci number is :%d", fibonacci(number));
  return 0;
}
