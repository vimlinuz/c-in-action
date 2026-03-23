#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
};

void check_overflow(struct Node *newnode) {
  if (newnode == NULL) {
    printf("Error alocating memory overflow occured");
    exit(1);
  }
}

// this will generate new enpty node
void insert_element_at_beginning(struct Node **list, int info) {
  struct Node *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));

  check_overflow(newnode);

  // Initialization of the newnode  with some empty content
  newnode->info = info;
  newnode->next = *list;
  *list = newnode;
}

void insert_element_at_the_end(struct Node **list, int info) {
  struct Node *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));

  check_overflow(newnode);

  newnode->info = info;
  newnode->next = NULL;

  if (*list == NULL) {
    *list = newnode;
  } else {
    struct Node *temp = *list;

    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void insert_element_at_specific_position(struct Node **list, int info,
                                         int position) {
  struct Node *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));

  check_overflow(newnode);

  newnode->info = info;
  newnode->next = NULL;

  if (position == 0) {
    newnode->next = *list;
    *list = newnode;
  } else {
    struct Node *temp = *list;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
      temp = temp->next;
    }
    if (temp == NULL) {
      printf("Position out of bounds");
      free(newnode);
      return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }
}

int main() {
  struct Node *head = NULL;

  insert_element_at_beginning(&head, 12);
  assert(head->info == 12);

  insert_element_at_the_end(&head, 14);
  assert(head->next->info == 14);

  insert_element_at_specific_position(&head, 16, 1);
  assert(head->next->info == 16);

  return 0;
}
