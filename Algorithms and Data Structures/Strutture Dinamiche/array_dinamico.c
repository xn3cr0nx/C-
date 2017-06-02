#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define GROWING_DELTA 10
#define SHRINKING_DELTA 20

#define GROWING_FACTOR 2
#define SHRINKING_FACTOR 4


struct SArray {
	int *item;
	int len;
	int size;
};
typedef struct SArray TArray;


TArray array_create(int len) {
	TArray a;
	a.item = (int *)malloc(len*sizeof(int));
	assert(len == 0 || a.item != NULL);
	a.len = len;
	a.size = len;
	return a;

}

void array_destroy(TArray *a) {
	free(a->item);
	a->item = NULL;
	a->len = 0;
	a->size = 0;
}



void linear_array_resize(TArray *a, int new_len) {
	if( new_len < a->size || new_len < a->size - SHRINKING_DELTA) {
		int new_size = new_len + GROWING_DELTA;
		a->item = realloc(a->item, new_size*sizeof(int));
		assert(new_size == 0 || a->item != NULL);
		a->size = new_size;
	}
	a->len = new_len;
}

void geometric_array_resize(TArray *a, int new_len) {
	if(new_len < a->size || new_len < a->size/SHRINKING_FACTOR) {
		int new_size = new_len*GROWING_FACTOR;
		a->item = realloc(a->item, new_size*sizeof(int));
		assert(new_size == 0 || a->item != 0);
		a->size = new_size;
	}
	a->len = new_len;
}


int main() {
	TArray a = array_create(10);
	printf("%i\n", a.len);
	linear_array_resize(&a, 12);
	printf("%i\n", a.len);
	geometric_array_resize(&a, 20);
	printf("%i\n", a.len);
}