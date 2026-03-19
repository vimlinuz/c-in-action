#include <stdio.h>

void printBinary(int value, int bits) {
  for (int i = bits - 1; i >= 0; i--)
    printf("%d", (value >> i) & 1);
}

void restoringDivision(int dividend, int divisor) {
  int negative = 0;

  printf(" Restoring Division \n");
  printf("Dividend : %d\n", dividend);
  printf("Divisor  : %d\n\n", divisor);

  // Handle signed: work with magnitudes
  int M = divisor;
  int Q = dividend;

  if (Q < 0) {
    Q = -Q;
    negative = !negative;
  }
  if (M < 0) {
    M = -M;
    negative = !negative;
  }

  int n = 4; // number of bits
  int A = 0;

  printf("Initial State:\n");
  printf("  A = ");
  printBinary(A, n);
  printf("  Q = ");
  printBinary(Q, n);
  printf("\n\n");

  for (int i = 0; i < n; i++) {
    // Left shift A and Q together
    int sign_bit = (A >> (n - 1)) & 1; // preserve sign before shift
    A = (A << 1) | ((Q >> (n - 1)) & 1);
    Q = Q << 1;

    // Mask to n bits
    A = A & ((1 << n) - 1);
    Q = Q & ((1 << n) - 1);

    printf("Step %d:\n", i + 1);
    printf("  After left shift  -> A = ");
    printBinary(A, n);
    printf("  Q = ");
    printBinary(Q, n);
    printf("\n");

    // Subtract M from A
    int A_new = (A - M) & ((1 << n) - 1);
    printf("  After A - M       -> A = ");
    printBinary(A_new, n);
    printf("\n");

    // Check sign of result (MSB)
    if ((A_new >> (n - 1)) & 1) {
      // Negative: restore A, set Q[0] = 0
      Q = Q & ~1; // Q[0] = 0
      printf("  Result negative   -> Restore A, Q[0] = 0\n");
    } else {
      // Non-negative: keep A, set Q[0] = 1
      A = A_new;
      Q = Q | 1; // Q[0] = 1
      printf("  Result positive   -> Keep A,    Q[0] = 1\n");
    }

    printf("  A = ");
    printBinary(A, n);
    printf("  Q = ");
    printBinary(Q, n);
    printf("\n\n");
  }

  int quotient = Q;
  int remainder = A;

  // Apply sign
  if (negative)
    quotient = -quotient;
  if (dividend < 0)
    remainder = -remainder;

  printf(" Result \n");
  printf("Quotient  = %d\n", quotient);
  printf("Remainder = %d\n", remainder);
  printf("\nVerification: %d / %d = %d, remainder %d\n", dividend, divisor,
         dividend / divisor, dividend % divisor);
}

int main() {
  int dividend, divisor;

  printf("Enter dividend : ");
  scanf("%d", &dividend);
  printf("Enter divisor  : ");
  scanf("%d", &divisor);

  if (divisor == 0) {
    printf("Error: Division by zero!\n");
    return 1;
  }

  printf("\n");
  restoringDivision(dividend, divisor);

  return 0;
}
