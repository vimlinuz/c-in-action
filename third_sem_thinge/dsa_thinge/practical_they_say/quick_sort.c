#include <assert.h>
#define SIZE 10

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1, j;

  for (j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return i + 1;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};

  quick_sort(arr, 0, SIZE - 1);

  int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i = 0; i < SIZE; i++) {
    assert(arr[i] == sorted[i]);
  }

  return 0;
}
