#include <stdio.h>

int ackermann(int m, int n) {
	if(m < 0 || n < 0) return -1;
	if(!m) return n+1;
	else {
		if(!n) return ackermann(m-1, 1);
		else 
			return ackermann(m-1, ackermann(m, n-1));
	}
}


int main() {
	printf("Ackermann %i\n", ackermann(3,2));
}