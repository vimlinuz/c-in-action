
void shell_sot(int arr[], int length) {
  for (int gap = length / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < length; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

int main() {
  int data[] = {12, 34, 54, 2, 3, 1, 5, 6, 7, 8, 9, 10};
  int n = sizeof(data) / sizeof(data[0]);
  shell_sot(data, n);

  return 0;
}
