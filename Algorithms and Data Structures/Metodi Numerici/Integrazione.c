#include <stdio.h>
#include <math.h>
// #include <cstdlib>

float f(float x) {
	// return (15*pow(x,8) + 4*pow(x,3) + 18);
	// return atan(x);
	// return sin(2*x);
	return (2*x + 1);
}

float metodoRettangoli(float a, float b, int n) {
	float x = a;
	int H = (b-a)/n;
	float S = 0;
	for(int i=1; i<=n; i++) {
		S += f(x);
		x += H;
	} 
	float Area = H*S;
	printf("Rettagoli Standard: %f\n", Area);
	return Area;
}


// Rettangoli ottimizzato è esattamente un trapezio
float metodoRettangoliOttimizzato(float a, float b, int n) {
	float H = (b-a)/n;
	float x = a + H;
	float S = 0;
	for(int i=1; i<=n; i++) {
		S += f(x);
		x = x + H;
	}

	float S1 = S - f(b);
	// float S2 = S + f(a);
	float AreaD = S1*H;
	float AreaE = S*H;
	float AreaM = (AreaE+AreaD)/2;
	printf("Rettangoli Ottimizzato: ");
	printf("AreaE: %f, ", AreaE);
	printf("AreaD: %f, ", AreaD);
	printf("AreaM: %f", AreaM);
	printf("\n");
	return AreaM;
}



float TrapezioAutomatizzato(float a, float b, int n, int NMAX, float eps) {
	float H = (b-a)/n;
	float x = a;
	float S = 0;
	for(int i=1; i<n; i++) {
		x += H;
		S += f(x);
	}
	float FAB = (f(a)+f(b))/2;
	float Area = (FAB+S)*H;
	//Il metodo del trapezio finisce qui
	printf("Trapezio: %f\n", Area);
	int nit = 0;
	float err;
	do {
		x = a + H/2;
		for(int i=1; i<=n; i++) {
			S += f(x);
			x += H;
		}
		float Area1 = (FAB+S)*H/2;
		nit++;
		H /= 2;
		err = fabs(Area-Area1);
		Area = Area1;
		n *= 2;
	} while(err > eps && nit < NMAX);
	printf("Trapezio Automatizzato: %f\n",Area);
}


float SimpsonAutomatizzato(float a, float b, int n, float eps, int NMAX) {
	if((n/2)*2!=n) n++;
	float H = (b-a)/n;
	float FAB = f(a)+f(b);
	float SD = 0;
	float SP = 0;
	float x = a+H;
	for(int i=1; i<n-1; i+=2) {
		SD += f(x);
		x += H;
		SP += f(x);
		x += H;
	}
	SD += f(x);
	float Area = (FAB + 4*SD + 2*SP)*H/3;
	// Il metodo di Simpson finisce qui
	printf("Simpson: %f\n", Area);
	int nit = 0;
	float err;
	do {
		x = a + H/2;
		SP += SD;
		SD = 0;
		for(int i = 0; i <= n; i++) {
			SD += f(x);
			x += H;
		}
		float Area1 = (FAB + 4*SD + 2*SP)*H/6;
		err = fabs(Area - Area1);
		H /= 2;
		n *= 2;
		nit++;
		Area = Area1;
	} while(err > eps && nit < NMAX);
	printf("Simpson Automatizzato: %f\n", Area);
}

int main() {
	metodoRettangoli(0, 10, 2);
	metodoRettangoliOttimizzato(0, 10, 300);
	TrapezioAutomatizzato(0, 10, 300, 20, 0.0001);
	SimpsonAutomatizzato(0, 10, 300, 50, 0.0000001);
}