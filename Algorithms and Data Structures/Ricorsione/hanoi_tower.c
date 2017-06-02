#include <stdio.h>

void hanoi(int n, int O, int D, int I) {
	if ( n == 1)
	printf("\nSposto il disco da: %d a: %d\n ", O, D);
	else {
		hanoi(n - 1, O, I, D);
		hanoi(1, O, D, I);
		hanoi(n - 1, I, D, O);
	}
}

int main()
{
	hanoi(3, 0, 1, 2);
	// return 0;
}