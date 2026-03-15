#include <stdio.h>
#include <string.h>

#define MAX 64

// Find 1's complement (flip all bits)
void ones_complement(char *binary, char *result) {
  int len = strlen(binary);
  for (int i = 0; i < len; i++) {
    result[i] = (binary[i] == '0') ? '1' : '0';
  }
  result[len] = '\0';
}

// Find 2's complement (1's complement + 1)
void twos_complement(char *ones, char *result) {
  int len = strlen(ones);
  strcpy(result, ones);

  int carry = 1;
  for (int i = len - 1; i >= 0 && carry; i--) {
    int sum = (result[i] - '0') + carry;
    result[i] = (sum % 2) + '0';
    carry = sum / 2;
  }
}

int is_valid_binary(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] != '0' && str[i] != '1')
      return 0;
  }
  return 1;
}

int main() {
  char binary[MAX], ones[MAX], twos[MAX];

  printf("Enter a binary number: ");

  // MAX is 64, so 63 chars + '\0'
  if (scanf("%63s", binary) != 1) {
    printf("Error: Failed to read input.\n");
    return 1;
  }

  if (!is_valid_binary(binary)) {
    printf("Error: Invalid binary number. Use only 0s and 1s.\n");
    return 1;
  }

  ones_complement(binary, ones);
  twos_complement(ones, twos);

  printf("\nBinary Number  : %s\n", binary);
  printf("1's Complement : %s\n", ones);
  printf("2's Complement : %s\n", twos);

  return 0;
}
