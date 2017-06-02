#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct SQueue {
	int front, back, n, capacity;
	int *a;
}
typedef struct SQueue TQueue;


TQueue queue_create(int capacity) {
	TQueue q;
	q.a = (int *)malloc(capacity*sizeof(int));
	assert(s.a != NULL);
	q.n = 0;
	q.front = 0;
	q.back = 0;
	q.capacity = capacity; 
	return q;
}

void queue_destroy(TQueue *q) {
	q->n = 0;
	q->capacity = 0;
	free(q->a);
	q->a = NULL;
}


void queue_add(TQueue *q, int x) {
	q->a[q->back] = x;
	q->back = (q->back+1)%q->capacity;
	q->n++;
}

int queue_remove(TQueue *q) {
	int x = q->a[q->front];
	q->front = (q->front+1)%q->capacity;
	q->n--;
	return x;
}

int queue_front(TQueue *q) {
	return q->a[q->front];
}

bool queue_empty(TQueue *q) {
	return !(q->n);
}

bool queue_full(TQueue *q) {
	return q->n == q->capacity;
}

int main() {
	
}