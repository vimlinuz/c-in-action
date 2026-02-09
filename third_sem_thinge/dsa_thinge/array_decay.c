#include <stdio.h>
void processArray(int *array) {
  printf("The first element of array is %d", *array);
  printf("The first element of array is %d", array[0]);

  printf("Before modification, in processArray function\n");

  for (int i = 0, j = 5; i < 5; i++, j--) {
    printf("%d\n", array[i]);
    array[i] = j;
  }
}
int main() {
  int array[5] = {1, 2, 3, 4, 5};
  printf("The memory location of array is %p\n", array);
  printf("The memory location of array is %p\n", &array);

  printf("The memory location of first element of array is %p\n", &array[0]);

  // here [0] will just drefrence the first element of the array and will give
  // us the value of it
  printf("The first element of array is %d\n", *array);
  printf("The first element of array is %d\n", array[0]);
  printf("\n");
  printf("\n");
  printf("\n");

  // calling the function
  processArray(array);
  printf("After modification, in main function\n");
  for (int i = 0; i < 5; i++) {
    printf("%d\n", array[i]);
  }
}
