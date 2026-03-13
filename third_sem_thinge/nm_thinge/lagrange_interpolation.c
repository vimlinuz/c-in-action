#include <stdio.h>

int main(void) {
  const int n = 6;
  float x_table[6] = {0, 10, 15, 20, 22.5f, 30};
  float y_table[6] = {0, 227.04f, 362.78f, 517.35f, 602.97f, 901.67f};
  float x = 16.0;
  float L[6];

  for (int i = 0; i < n; i++) {

    L[i] = 1.0;

    for (int j = 0; j < n; j++) {
      if (j == i)
        continue;
      float denom = x_table[i] - x_table[j];
      if (denom == 0.0f) {
        fprintf(stderr,
                "Error: duplicate x_table entries at indices %d and %d\n", i,
                j);
        return 1;
      }
      L[i] *= (x - x_table[j]) / denom;
    }
  }

  float root = 0.0f;
  for (int i = 0; i < n; i++) {
    root += y_table[i] * L[i];
  }

  printf("The interpolated value v at x = %.2f: %.6f\n", x, root);
  return 0;
}
