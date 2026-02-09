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

int free_node(struct Stack **stack) {
  if (is_empty(stack)) {
    printf("Error underflow");
    exit(1);
  };
  struct Stack *temp = *stack;
  int info = temp->info;
  *stack = temp->next;
  free(temp);
  return info;
}

int main() {
  struct Stack *stack;
  get_node(&stack, 1);
  get_node(&stack, 2);
  get_node(&stack, 3);
  printf("The node is freed so we get following value %d\n", free_node(&stack));
  printf("The node is freed so we get following value %d\n", free_node(&stack));
  printf("The node is freed so we get following value %d\n", free_node(&stack));
  printf("The node is freed so we get following value %d\n", free_node(&stack));
}
