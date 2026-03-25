#include <assert.h>

void selection_sort(int unsorted[], int length) {
  for (int i = 0; i < length - 1; i++) {

    int min_index = i;
    for (int j = i + 1; j < length; j++) {
      if (unsorted[j] < unsorted[min_index]) {
        min_index = j;
      }
    }

    int temp = unsorted[min_index];
    unsorted[min_index] = unsorted[i];
    unsorted[i] = temp;
  }
}

int main() {
  int unsorted[] = {5, 2, 9, 1, 5, 6};
  int length = sizeof(unsorted) / sizeof(unsorted[0]);

  selection_sort(unsorted, length);
  int sorted[] = {1, 2, 5, 5, 6, 9};

  for (int i = 0; i < length; i++) {
    assert(unsorted[i] == sorted[i]);
  }
  return 0;
}
