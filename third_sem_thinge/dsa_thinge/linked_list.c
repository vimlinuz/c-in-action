#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct Stack {
  int info;
  struct Stack *next;
};

// this will generate new enpty node
struct Stack *getnode() {
  struct Stack *newnode;
  newnode = (struct Stack *)malloc(sizeof(struct Stack));

  // Initialization of the newnode  with some empty content
  newnode->info = 0;
  newnode->next = NULL;

  if (newnode == NULL) {
    printf("Error alocating memory overflow occured");
    exit(1);
  }
  return newnode;
};

int is_empty(struct Stack *pointer) { return false; }

int main() {
  printf("this is teh main function ");
  return 0;
}
