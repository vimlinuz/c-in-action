#include <stdio.h>
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    // this type of recursion is called tail
    return gcd(b, a % b);
  }
}

int main() {
  int a, b;
  printf("Enter the two numbers:");

  if (scanf("%d %d", &a, &b) == 0) {
    printf("Invalid input.");
  };

  printf("The gcd of %d and %d is %d", a, b, gcd(a, b));
  return 0;
}
