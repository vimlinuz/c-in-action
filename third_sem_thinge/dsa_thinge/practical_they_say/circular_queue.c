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
  q->front = MAX_SIZE - 1;
  q->rear = MAX_SIZE - 1;
}

bool is_empty(Queue *q) { return (q->front == q->rear); }

bool is_full(Queue *q) { return (q->rear + 1) % MAX_SIZE == q->front; }

void enqueue(Queue *q, int value) {
  if (is_full(q)) {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_SIZE;
  q->items[q->rear] = value;
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Underflow: Queue is empty\n");
    exit(1);
  }
  q->front = (q->front + 1) % MAX_SIZE;
  return q->items[q->front];
}

int peek(Queue *q) {
  if (is_empty(q)) {
    printf("Underflow: Queue is empty\n");
    exit(1);
  }
  return q->items[(q->front + 1) % MAX_SIZE];
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
