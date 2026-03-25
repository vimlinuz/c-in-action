#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

#define true 1
#define false 0
#define bool int

typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} Queue;

void initialize_queue(Queue *q) {
  q->front = -1;
  q->rear = 0;
}

bool is_empty(Queue *q) { return (q->front == q->rear - 1); }

bool is_full(Queue *q) { return (q->rear == MAX_SIZE); }

void enqueue(Queue *q, int value) {
  if (is_full(q)) {
    printf("Queue is full\n");
    return;
  }
  q->items[q->rear] = value;
  q->rear++;
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Underflow: Queue is empty\n");
    exit(1);
  }
  return q->items[++q->front];
}

int peek(Queue *q) {
  if (is_empty(q)) {
    printf("Underflow: Queue is empty\n");
    exit(1);
  }
  return q->items[q->front + 1];
}

int main() {
  Queue q;
  initialize_queue(&q);

  enqueue(&q, 10);
  assert(!is_empty(&q));

  enqueue(&q, 20);
  assert(!is_full(&q));

  assert(dequeue(&q) == 10);
  assert(dequeue(&q) == 20);

  return 0;
}
