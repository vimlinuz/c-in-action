#include <stdio.h>
#include <stdlib.h>

#define N 8

int acc[N], qnum[N], bnum[N], res[N];
int carry = 0;

void toBinary(int val, int arr[]) {
  val = abs(val);
  for (int i = 0; i < N; i++)
    arr[i] = (val >> i) & 1;
}

void add(int num[]) {
  carry = 0;
  for (int i = 0; i < N; i++) {
    int s = acc[i] + num[i] + carry;
    res[i] = s % 2;
    carry = s / 2;
  }
  for (int i = 0; i < N; i++)
    acc[i] = res[i];
}

void rshift() {
  int temp = acc[0];
  for (int i = 0; i < N - 1; i++)
    acc[i] = acc[i + 1];
  acc[N - 1] = carry;
  carry = 0;
  for (int i = 0; i < N - 1; i++)
    qnum[i] = qnum[i + 1];
  qnum[N - 1] = temp;
}

void printBits(int arr[]) {
  for (int i = N - 1; i >= 0; i--)
    printf("%d", arr[i]);
}

int main() {
  // Initially the emultiplicand is in register B and the multiplier in Q.
  int b, q;

  printf(" 8-bit signed magnitude multiplication \n");

  do {
    printf("Enter B (-127 to 127): ");
    scanf("%d", &b);
    printf("Enter Q (-127 to 127): ");
    scanf("%d", &q);
  } while (abs(b) > 127 || abs(q) > 127);

  printf("\nExpected product: %d\n", b * q);

  toBinary(b, bnum);
  toBinary(q, qnum);

  printf("B = ");
  printBits(bnum);
  printf("\n");
  printf("Q = ");
  printBits(qnum);
  printf("\n\n");

  int sign = (b < 0) != (q < 0);

  for (int sc = N; sc > 0; sc--) {
    printf("SC=%d | ACC: ", sc);
    printBits(acc);
    printf(" Q: ");
    printBits(qnum);

    if (qnum[0] == 1) {
      add(bnum);
      printf(" -> ADD B");
    }

    rshift();
    printf(" -> RSH | ACC: ");
    printBits(acc);
    printf(" Q: ");
    printBits(qnum);
    printf("\n");
  }

  printf("\nProduct (sign=%d): %s", sign, sign ? "-" : "+");
  printBits(acc);
  printBits(qnum);
  printf("\n");

  return 0;
}
