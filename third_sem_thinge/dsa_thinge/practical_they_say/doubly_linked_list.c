#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int info;
  struct Node *next;
  struct Node *prev;
} Node;

void check_overflow(Node *newnode) {
  if (newnode == NULL) {
    printf("Error alocating memory overflow occured");
    exit(1);
  }
}

Node *create_node(int info, Node *next, Node *prev) {
  Node *newnode;
  newnode = (Node *)malloc(sizeof(Node));

  check_overflow(newnode);
  newnode->info = info;
  newnode->next = next;
  newnode->prev = prev;
  return newnode;
}

void insert_element_at_beginning(Node **list, int info) {
  if (*list == NULL) {
    *list = create_node(info, NULL, NULL);
  } else {
    Node *newnode = create_node(info, *list, NULL);
    (*list)->prev = newnode;
    *list = newnode;
  }
}

void insert_element_at_end(Node **list, int info) {
  Node *newnode = create_node(info, NULL, NULL);
  if (*list == NULL) {
    *list = newnode;
  } else {
    Node *temp = *list;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
  }
}
void insert_element_at_specific_position(Node **list, int info, int position) {
  Node *newnode = create_node(info, NULL, NULL);

  if (*list == NULL) {
    *list = newnode;
  } else {
    if (position == 0) {
      newnode->next = *list;
      (*list)->prev = newnode;
      *list = newnode;
    } else {
      Node *temp = *list;
      for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
      }
      if (temp != NULL) {
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) {
          temp->next->prev = newnode;
        }
        temp->next = newnode;
      } else {
        printf("Position out of bounds\n");
        free(newnode);
      }
    }
  }
}

int arr[100];
void traverse_list(Node *list) {
  int count = 0;
  Node *temp = list;
  while (temp != NULL) {
    arr[count++] = temp->info;
    temp = temp->next;
  }
}

int main() {
  Node *head = NULL;
  insert_element_at_beginning(&head, 12);
  assert(head->info == 12);

  insert_element_at_end(&head, 15);
  assert(head->next->info == 15);
  assert(head->next->prev->info == 12);

  insert_element_at_specific_position(&head, 10, 1);
  assert(head->next->info == 10);
  assert(head->next->prev->info == 12);

  traverse_list(head);
  assert(arr[0] == 12);
  assert(arr[1] == 10);
  assert(arr[2] == 15);
  return 0;
}
