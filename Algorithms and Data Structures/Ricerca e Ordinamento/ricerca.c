#include <stdio.h>

int lineare(int v[], int x) {
	int i;
	for(i=0; x != v[i]; i++); 
	return i;
}

int dicotomica(int v[], int n, int x) {
	int first = 0, last = n-1;
	while(first <= last) {
		int pivot = (first+last)/2; 
		if(v[pivot] == x) return pivot;
		else if(v[pivot] < x) first = pivot + 1;
		else if(v[pivot] > x) last = pivot - 1;
	}
	return -1;
}


int main() {
	int v[20] = {9, 2, 3, 8, 12, 33, 1, 34};
	printf("Ricerca lienare posizione: %i\n", lineare(v, 33));
	int u[20] = {1, 3, 5, 12, 34, 97};
	printf("Ricerca dicotomica posizone:%i\n", dicotomica(u, 6, 34));
}