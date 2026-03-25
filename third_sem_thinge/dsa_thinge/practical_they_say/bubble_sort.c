#include <assert.h>
#include <stdbool.h>
void bubble(int x[], int n) {
  bool switched = true;
  int hold;

  for (int pass = 0; pass < n - 1 && switched == true; pass++) {
    switched = false;
    for (int j = 0; j < n - pass - 1; j++) {
      if (x[j] > x[j + 1]) {
        hold = x[j];
        x[j] = x[j + 1];
        x[j + 1] = hold;
        switched = true;
      }
    }
  }
}
int main() {
  int unsorted[] = {64, 34, 25, 12, 22, 11, 90};
  int lenght = sizeof(unsorted) / sizeof(unsorted[0]);
  bubble(unsorted, lenght);
  int sorted[] = {11, 12, 22, 25, 34, 64, 90};

  for (int i = 0; i < lenght; i++) {
    assert(unsorted[i] == sorted[i]);
  }
}
