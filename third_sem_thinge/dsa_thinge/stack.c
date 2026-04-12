#include <assert.h>
#include <stdatomic.h>
#define MAXSIZE 10
#define bool int
#define true 1
#define false 0

typedef struct Stack {
  int tos;
  int items[MAXSIZE];
} stack;

bool isfull(stack *stack) {
  if (stack->tos == MAXSIZE)
    return true;
  return false;
}

bool isempty(stack *stack) {
  if (stack->tos == -1)
    return true;
  return false;
}

void push(stack *stack, int data) {
  if (!isfull(stack)) {
    stack->tos++;
    stack->items[stack->tos] = data;
  }
}

int pop(stack *stack) {
  if (!isempty(stack)) {
    int content = stack->items[stack->tos];
    stack->tos--;
    return content;
  } else {
    return 0; // underflow
  }
}

int peek(stack *stack) {
  if (!isempty(stack)) {
    return stack->items[stack->tos];
  } else {
    return 0; // underflow
  }
}

void isempty_test() {
  stack my_stack;
  my_stack.tos = -1;
  assert(isempty(&my_stack) == true);
}

void isfull_test() {
  stack my_stack;
  my_stack.tos = MAXSIZE;
  assert(isfull(&my_stack) == true);
}

void push_test() {
  stack my_stack;
  my_stack.tos = -1;
  push(&my_stack, 12);
  assert(my_stack.items[my_stack.tos] == 12);
}

void pop_test() {
  stack my_stack;
  my_stack.tos = -1;
  push(&my_stack, 12);
  assert(pop(&my_stack) == 12);
}

void push_multiple_test() {
  stack my_stack;
  my_stack.tos = -1;
  for (int i = 0; i <= MAXSIZE; i++) {
    push(&my_stack, i);
    assert(my_stack.items[my_stack.tos] == i);
  }
  assert(isfull(&my_stack) == true);
}

void pop_empty_test() {
  stack my_stack;
  my_stack.tos = -1;
  int result = pop(&my_stack);
  // under flow so will return 0
  assert(result == 0);
}

void push_pop_sequence_test() {
  stack my_stack;
  my_stack.tos = -1;
  push(&my_stack, 5);
  push(&my_stack, 10);
  assert(pop(&my_stack) == 10);
  assert(pop(&my_stack) == 5);
  assert(isempty(&my_stack) == true);
}

void peek_test() {
  stack my_stack;
  my_stack.tos = -1;
  push(&my_stack, 42);
  assert(peek(&my_stack) == 42);
  assert(isempty(&my_stack) == false); // peek should not remove the item
}

int main() {
  push_multiple_test();
  pop_empty_test();
  push_pop_sequence_test();
  isempty_test();
  isfull_test();
  push_test();
  pop_test();
  peek_test();
  return 0;
}
