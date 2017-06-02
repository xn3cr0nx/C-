#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 10

struct SStack {
	int n;
	int a[CAPACITY];
};
typedef struct SStack TStack;


TStack create_stack() {
	TStack s;
	s.n = 0;
	return s;
}

void destroy_stack(TStack *s) {
	s->n = 0;
}


void stack_push(TStack *s, int x) {
	s->a[s->n++] = x;
}

int stack_pop(TStack *s) {
	return s->a[--s->n];
}

int stack_top(TStack *s) {
	return s->a[s->n-1];
}

bool stack_empty(TStack *s) {
	return !(s->n);
}


bool stack_full(TStack *s) {
	return (s->n == CAPACITY);
}


int main() {
	TStack s;
	s = create_stack();
	stack_push(&s, 12);
	stack_push(&s, 22);
	printf("%i\n", stack_top(&s));
	stack_pop(&s);
	printf("%i\n", stack_top(&s));
	printf("%i\n", stack_full(&s));
}


