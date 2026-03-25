#include <assert.h>

void heapify(int arr[], int n, int i) {

  int largest = i;

  int l = 2 * i + 1;

  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int length) {

  for (int i = length / 2 - 1; i >= 0; i--)
    heapify(arr, length, i);

  for (int i = length - 1; i > 0; i--) {

    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {9, 4, 3, 8, 10, 2, 5};
  int length = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, length);

  int sorted[] = {2, 3, 4, 5, 8, 9, 10};

  for (int i = 0; i < length; i++) {
    assert(arr[i] == sorted[i]);
  }

  return 0;
}
