#include <stdio.h>

int get_xor(int data) {
  int xor_result = 0;

  for (int i = 3; i >= 0; i--) {
    int bit = (data >> i) & 1;
    xor_result = xor_result ^ bit;
  }
  return xor_result;
}

void print_binary(int data) {
  for (int i = 3; i >= 0; i--) {
    int bit = (data >> i) & 1;
    printf("%d", bit);
  }
}

int main() {
  int data = 0b1011;

  printf("The data is :");
  print_binary(data);

  int xor_result = get_xor(data);
  int parity_flag = !xor_result;

  printf("\nXOR result  : %d\n", xor_result);
  printf("Parity flag : %d\n", parity_flag);

  if (parity_flag == 0) {
    printf("Parity: Odd\n");
  } else {
    printf("Parity: Even\n");
  }

  return 0;
}
