#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
  char *queue[MAX_QUEUE_SIZE];
  int front;
  int rear;
} Queue;

void initQueue(Queue *queue) {
  queue->front = 0;
  queue->rear = 0;
}

int isQueueFull(Queue *queue) {
  return queue->rear == MAX_QUEUE_SIZE;
}

int isQueueEmpty(Queue *queue) {
  return queue->front == queue->rear;
}

void enqueue(Queue *queue, char *str) {
  if (isQueueFull(queue)) {
    printf("Queue is full!\n");
    return;
  }

  queue->queue[queue->rear] = str;
  queue->rear++;
}

char *dequeue(Queue *queue) {
  if (isQueueEmpty(queue)) {
    printf("Queue is empty!\n");
    return NULL;
  }

  char *str = queue->queue[queue->front];
  queue->front++;

  return str;
}

void popAllStringsOutQueue(Queue *queue) {
  while (!isQueueEmpty(queue)) {
    char *str = dequeue(queue);
    printf("%s\n", str);
  }
}

int main() {
  Queue queue;
  initQueue(&queue);

  char str[100];
  printf("Enter a string to enqueue: ");
  scanf("%s", str);

  enqueue(&queue, str);

  popAllStringsOutQueue(&queue);

  return 0;
}