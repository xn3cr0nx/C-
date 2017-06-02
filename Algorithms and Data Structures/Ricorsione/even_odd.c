#include <stdio.h>
#include <stdbool.h>



bool is_even(int n) {
	if(!n) return true;
	else is_odd(n-1);
}


bool is_odd(int n) {
	return !(is_even(n));
}


int main() {
	printf("pari: %d\n", is_even(5));
}