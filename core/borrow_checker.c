#include <stdio.h>
#include <stdlib.h>

// void take_immutable_ownership(const int *vector)
void take_mutable_ownership(int *vector) {
  printf("The vector is: ");
  for (int i = 0; i < 10; i++) {
    // here like the array we are drefrencing the pointer to access the value
    // at that index, and we can do that because we have ownership of the
    // vector, so we can access it and modify it as we want, but in C we don't
    // have a borrow checker to prevent us from doing that, so we can still
    // access it after the function call because we didn't free it, but it
    // will lead to undefined behavior because we are accessing memory that
    // has been freed.
    printf("%d ", vector[i]);
  }
  printf("\n");
  // since we took ownership of the vector, we can free that

  free(vector);
}

void take_refrence(int *vector) {
  printf("The vector is: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  // since we only took a reference to the vector, we can't free it because we
  // don't have ownership of it, but we can still access it after the function
  // call because we didn't free it.
  // free(vector)
}

int main() {
  int capacity = 10;
  int *vector = (int *)(malloc(sizeof(int) * capacity));

  if (!vector) {
    perror("Memory allocation failed\n");
  }

  for (int i = 0; i < capacity; i++) {
    vector[i] = i + 1;
  }

  printf("The initial vector is: ");

  for (int i = 0; i < capacity; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  // gave the ownership of the vector to the function, so we can't access it
  // anymore in rust because the function will free the memory after using it,
  // but in C we can still access it because we don't have a borrow checker to
  // prevent us from doing so, but it will lead to undefined behavior because
  // we are accessing memory that has been freed.
  take_mutable_ownership(vector);

  printf("Trying to access the vector after taking ownership...\n");
  for (int i = 0; i < capacity; i++) {
    printf("%d ", vector[i]);
  }

  return 0;
}
