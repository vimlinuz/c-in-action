void merge(int left_array[], int right_array[], int array[], int length) {
  int left_size = length / 2;
  int right_size = length - left_size;
  int i = 0;
  int l = 0;
  int r = 0;

  // check the condition of the left and right array and merge them in the
  // original array
  while (l < left_size && r < right_size) {
    if (left_array[l] < right_array[r]) {
      array[i] = left_array[l];
      l++;
    } else {
      array[i] = right_array[r];
      r++;
    }
    i++;
  }
  // if there are any remaining elements in the left array, add them to the
  // original
  while (l < left_size) {
    array[i] = left_array[l];
    i++;
    l++;
  }

  // if there are any remaining elements in the right array, add them to the
  // original
  while (r < right_size) {
    array[i] = right_array[r];
    i++;
    r++;
  }
}

void merge_sort(int array[], int length) {
  if (length <= 0) {
    return;
  } else {
    int middle = length / 2;

    int left_array[middle];
    int right_array[length - middle];

    // for left array
    int i = 0;
    // for right array
    int j = 0;

    for (; i < length; i++) {

      if (i < middle) {
        // copying the left half of the array to left_array
        left_array[i] = array[i];
      } else {
        //  copying the right half of the array to right_array
        right_array[j] = array[i];
      }
    }
    merge_sort(left_array, middle);
    merge_sort(right_array, length - middle);

    merge(left_array, right_array, array, length);
  }
}

int main() {
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int length = sizeof(array) / sizeof(array[0]);
  merge_sort(array, length);
  return 0;
}
