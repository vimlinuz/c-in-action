#include <stdio.h>

int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  int number = 0;
  printf("Enter a number: ");
  if (scanf("%d", &number) == 1) {
    if (number < 0) {
      printf("Factorial is not defined for negative numbers.");
      return 1;
    }
  } else {
    printf("Invalid input. Please enter an integer.");
    return 1;
  }
  printf("The factorial of %d is %d", number, factorial(number));
  return 0;
}
