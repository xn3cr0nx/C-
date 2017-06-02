#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool DeterminanteNullo(float a[][3], int n) {
	int det = a[0][0];
	for(int i=1; i <= n; i++) det *= a[i][i];
	if(!det) return true;
	return false;
}


float RisoluzioneAllIndietro(float a[][3], float x[3], float b[3], int n) {
	x[n] = b[n]/a[n][n];
	// printf("%f\n", x[n]);
	for(int i=(n-1); i>=0; i -= 1) {
		// printf("%i\n", i);
		float s = 0;
		for(int j=i+1; i <= n; i++) s += a[i][j]*x[j];	
		x[i] = (b[i]-s)/a[i][i];
	}
	for(int i=0; i<=n; i++) printf("%f\n", x[i]);
}



//controlla se un elemento della colonna è zero
//altrimenti mette l'elemento maggiore sulla diagonale
//swappando le righe, questo ottimizza i calcoli
bool SP(float a[][4], int k, int n) {
	float RMAX = fabs(a[k][k]);
	int ind = k;
	for(int i=k+1; i<n; i++) {
		if(fabs(a[i][k] > RMAX)) {
			RMAX = fabs(a[i][k]);
			ind = i;
		}
	}
	if(!RMAX) return false;
	else {
		if(ind != k) {
			float tmp;
			for(int j= k; j < n+1; j++) {
				tmp = a[k][j];
				a[k][j] = a[ind][j];
				a[ind][j] = tmp;
			}
		}
	}
	return true;
}


int RiduzioneAScala(float a[][4], float x[4], float b[4], int n) {
	for(int i=0; i <= n; i++) a[i][n] = b[i];


	for(int i=0; i < n; i++){
		float s = 0;
		for(int j=0; j < n+1; j++) s += a[i][j];
		for(int j=0; j < n+1; j++) a[i][j] /= s;
	}


	for(int k=0; k<n; k++){
		bool flag = SP(a, k, n);
		if(!flag) return -1;
		for(int i=k+1; i < n; i++) {
			float ck = a[i][k]/a[k][k];
			for(int j=k+1; j < n+1; j++) {
				a[i][j] -= ck*a[k][j];
			}
		}
	}
	x[n-1] = a[n-1][n]/a[n-1][n-1];
	for(int i = n-2; i > 0; i--) {
		float s = 0;
		for(int j=i+1; j < n; j++) s += a[i][j]*x[j];
		x[i] = (a[i][n]-s)/a[i][i];
	}
}


int main() {
	float a[4][4];
	float b[4] = {1, 1, 1, 1};
	float x[4] = {0, 0, 0, 0};
	for(int i=0; i < 4; i++) {
		for(int j=0; j < 4; j++) a[i][j] = 1;
	}
	// bool res = DeterminanteNullo(a, 3);
	// if(res) printf("LOL\n");
	// else printf("!NULL\n");
	// RisoluzioneAllIndietro(a, x, b, 2);
	printf("A prima:\n");
	for(int i=0; i <4; i++) {
		for(int j=0; j < 4; j++) printf("%f ", a[i][j]);
		printf("\n");
	}
	printf("\n\n");
	RiduzioneAScala(a, x, b, 3);
		printf("A dopo:\n");

	for(int i=0; i < 4; i++) {
		for(int j=0; j < 4; j++) printf("%f ", a[i][j]);
		printf("\n");
	}
	
}