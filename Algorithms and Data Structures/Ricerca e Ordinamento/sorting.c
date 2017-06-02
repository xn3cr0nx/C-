#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int v[], int n) {
	for(int i=0; i < n; i++) {
		printf("%i ", v[i]);
	}
	printf("\n");
}

void copy(int v[], int u[], int n) {
	for(int i=0; i<n; i++) v[i] = u[i];
}

void selection_sort(int v[], int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n;j++) {
			if(v[j] < v[i]) swap(&v[i], &v[j]);
		} 
	}
}


void bubble_sort(int v[], int n) {
	for(int i=0; i<n; i++) {
		bool flag = false;
		for(int j=0; j<n-i-1; j++) {
			if(v[j] > v[j+1]) {
				swap(&v[j], &v[j+1]);
				flag = true;
			}
		}
		if(!flag) break;
	}
}



void shaker_sort(int v[], int n) {
	for(int i=0; i<n/2; i++) {
		bool flag = false;
		for(int j=i; j<n-i-1; j++) {
			if(v[j] > v[j+1]) {
				swap(&v[j], &v[j+1]);
				flag = true;				
			}
		}
		if(flag) {
			for(int j=n-i-1; j>i; j--) {
				if(v[j] < v[j-1]) {
				swap(&v[j], &v[j-1]);
				flag = true;									
				}
			}
		}
		else break;	
	}	
}



void insert_in_order(int v[], int n, int x) {
	int pos;
	//si scorre dalla poszione i-esima all'indietro fin quando
	//gli elementi confrontati sono maggiori dell'elemento in
	//posizione i-esima
	for(pos=n; pos > 0 && v[pos-1] > x; pos--);
	//quindi tutti questi vengono shiftati a destra
	for(int i=n-1; i >= pos; i--) v[i+1] = v[i];
	//in pos finale viene messo x cioè l'elemento v[i]
	v[pos]= x;
}
void insertion_sort(int v[], int n) {
	int i;
	//viene chiamato l'inserimento in ordine per l'elemento i-esimo
	for(i=1; i < n; i++) insert_in_order(v, i, v[i]);
}





void merge(int a1[], int n1, int a2[], int n2, int dest[]) {
	int pos1 = 0, pos2 = 0, k = 0;
	//fa il merge ordinato a due a due tra gli elementi dei vettori
	//fin tanto che entrambi ne contengono ancora
	while(pos1 < n1 && pos2 < n2) {
		if(a2[pos2] < a1[pos1]) dest[k++] = a2[pos2++];
		else dest[k++] = a1[pos1++];
	}
	//qui si aggiungono in coda gli elementi mancanti del vettore più grande
	while(pos1 < n1) dest[k++] = a1[pos1++];
	while(pos2 < n2) dest[k++] = a2[pos2++];
}
void merge_sort(int v[], int n, int temp[]) {
	int i, m = n/2;
	if(n < 2) return;
	//merge ricorsivo sulla prima metà del vettore
	merge_sort(v, m, temp);
	//merge ricorsivo sulla seconda metà del vettore
	merge_sort(v+m, n-m, temp);
	//vengono mergiati i due vettori risultanti
	merge(v, m, v+m, n-m, temp);
	//viene riempito il vettore iniziale copiandoci quello di destinazione ordinato
	for(i=0; i < n; i++) v[i] = temp[i];
}



int partition(int v[], int n) {
	int k = 1;
	//cicliamo tutto l'array
	for(int i = 1; i < n ; i++)
		//così tutti gli elementi minori del pivot li portiamo
		//in prossimità di esso, contigui
		if( v[i] < v[0]) swap(&v[i],&v[k++]);
	//alla fine swappiamo il pivot con l'ultimo degli elementi
	//a lui minori, così alla sua sinistra ci saranno tutti e solo
	//gli elementi a lui minori, a destra i maggiori
	//(k-1) perchè con l'ultimo swap incrementiamo k e siamo
	//sul primo del elementi maggiori
	swap(&v[0],&v[k-1]);
	//restituiamo il pivot
	return k-1;
}
void quick_sort(int v[], int n) {
	int k;
	if(n < 2) return;
	//prendiamo il pivot
	k = partition(v, n);
	//ricorsivamente con il nuovo pivot applichiamo il quick_sort
	//sull'array diviso dal pivot
	quick_sort(v, k);
	//facciamo lo stesso per l'altra metà di array
	quick_sort(v+k+1, n-k-1);
}



int main() {

	printf("Vettore: ");
	int v[30] = {22, 18, 3, 5, 6, 1, 4, 98, 77, 122, 12, 7, 42, 231, 8, 214, 7,5, 536, 3, 643,325};
	print(v, 22);
	int u[30];
	copy(u, v, 22);
	
	printf("Selection Sort: ");
	selection_sort(v, 22);
	print(v, 22);
	copy(v, u, 22);

	printf("Bubble Sort: ");
	bubble_sort(v, 22);
	print(v, 22);
	copy(v, u, 22);
	
	printf("Shaker Sort: ");
	shaker_sort(v, 22);
	print(v, 22);
	copy(v, u, 22);
	
	printf("Insertion Sort: ");
	insertion_sort(v, 22);
	print(v, 22);
	copy(v, u, 22);
	
	printf("Merge Sort: ");
	int lol[30] = {0, 0,0,0,0, 0,0, 0, 0, 0, 0,0, 0, 0,0, 0,0, 0,0, 0, 0};
	merge_sort(v, 22, lol);
	print(v, 22);
	copy(v, u, 22);

	printf("Quick Sort: ");
	quick_sort(v, 22);
	print(v, 22);
	copy(v, u, 22);
}











