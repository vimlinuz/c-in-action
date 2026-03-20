#include <stdio.h>

#define BITS 4
#define MASK ((1u << BITS) - 1)

void print_bin(unsigned int n) {
  for (int i = BITS - 1; i >= 0; i--)
    printf("%u", (n >> i) & 1);
}

unsigned int lsl(unsigned int n, int p) { return (n << p) & MASK; }
unsigned int lsr(unsigned int n, int p) { return (n & MASK) >> p; }
unsigned int rol(unsigned int n, int p) {
  p %= BITS;
  return ((n << p) | (n >> (BITS - p))) & MASK;
}
unsigned int ror(unsigned int n, int p) {
  p %= BITS;
  return ((n >> p) | (n << (BITS - p))) & MASK;
}

void show(const char *name, unsigned int n, unsigned int res) {
  printf("%-28s ", name);
  print_bin(n);
  printf(" -> ");
  print_bin(res);
  printf(" (%u)\n", res);
}

int main(void) {
  unsigned int n = 0b1011;
  int p = 3;

  printf("Input: ");
  print_bin(n);
  printf(" (%u),  shift = %d\n\n", n, p);

  show("Logical Left Shift   (<<)", n, lsl(n, p));
  show("Logical Right Shift  (>>)", n, lsr(n, p));
  show("Circular Left Shift  (ROL)", n, rol(n, p));
  show("Circular Right Shift (ROR)", n, ror(n, p));

  return 0;
}
