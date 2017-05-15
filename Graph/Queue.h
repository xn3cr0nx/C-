#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <stdlib.h>
using namespace std;

/* Definizione della struttura dati */
struct SQueue {
  int n;
  int front;
  int back;
  int capacity;
  int* a ;
};
typedef struct SQueue TQueue ;

/* Crea una coda */
TQueue queue_create (int capacity) {
  TQueue s;
  s.n = 0;
  s.front = 0;
  s.back = 0;
  s.capacity = capacity;
  s.a = (int*)malloc(sizeof(int)*capacity);
  // s.a = (int*)malloc(capacity);
  // assert(s.a != NULL);
  return s;
}

/* Distrugge una coda*/
void queue_destroy (TQueue* queue) {
  queue->n = 0;
  queue->capacity = 0;
  free(queue->a);
  queue->a = NULL;
}

/* Accoda un elemento*/
void queue_add(TQueue* queue, int x) {
  queue->a[queue->back] = x;
  queue->back = (queue->back+1) % queue->capacity;
  queue->n++;
}

/* Preleva un elemento*/
int queue_remove(TQueue* queue) {
  int x = queue->a[queue->front];
  queue->front = (queue->front+1) % queue->capacity;
  queue->n--;
  return x;
}

/* Primo elemento*/
int queue_front(TQueue* queue) {
  return queue->a[queue->front];
}

/* Verifica se la coda è vuota*/
bool queue_is_empty(TQueue* queue) {
  return queue->n == 0;
}

/* Verifica se la coda è piena*/
bool queue_is_full(TQueue* queue) {
  return queue->n == queue->capacity;
}


#endif
