#include <stdio.h>


long factorial(long n) {
	if(!n) return 1;
	return n*factorial(n-1);
}

int main() {
	printf("%li\n", factorial(18));
}