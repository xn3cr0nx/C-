#include <stdio.h>

long fibonacci(long n) {
	if(!n || n == 1) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
	printf("Fibonacci: %li\n", fibonacci(8));

}