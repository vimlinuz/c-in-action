#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #define true 1
// #define false 0
// typedef int bool;

struct Stack {
  int info;
  struct Stack *next;
};

// this will generate new enpty node
void get_node(struct Stack **stack, int info) {
  struct Stack *newnode;
  newnode = (struct Stack *)malloc(sizeof(struct Stack));

  // this is the case of available check
  if (newnode == NULL) {
    printf("Error alocating memory overflow occured");
    exit(1);
  }

  // Initialization of the newnode  with some empty content
  newnode->info = info;
  newnode->next = *stack;
  *stack = newnode;
}

bool is_empty(struct Stack **stack) {
  if (*stack == NULL) {
    return true;
  }
  return false;
}

int free_node(struct Stack *stack) {
  if (is_empty(&stack)) {
    printf("Error underflow");
    exit(1);
  };
  int info = stack->info;
  stack = stack->next;
  return info;
}

int main() {
  struct Stack *stack;
  assert(is_empty(&stack) == true);
  // get_node(&stack, 43);
  // printf("some tings %d", stack->info);
  // printf("some tings %d", stack->next->info);
}
