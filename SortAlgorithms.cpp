#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int n;


void pause(int mseconds)
{
    clock_t goal = mseconds+clock();
    while(goal>clock());
}

//Insertion Sort
void insertionSort(int v[], int n)
{
    cout << "INSERTION SORT";
    for(int i=0;i<n;i++)
    {
        unsigned var = v[i];
        int j=i-1;
        while(j>=0 && v[j]>var)
        {
            v[j+1]=v[j];
            j--;
        }
    v[j+1]=var;
    }
}

//Selection Sort
void selectionSort(int v[], int n)
{
    cout << "SELECTION SORT";
    unsigned app;
    int posmin;
    for(int i=0; i<n-1;i++)
    {
        posmin = i;
        int j = i+1;
        while(j<n)
        {
            if (v[j]<v[i])
                posmin = j;
            j++;
        }
        app = v[i];
        v[i] = v[posmin];
        v[posmin] = app;
    }
}

//Bubble Sort
void bubbleSort(int v[], int n)
{
    cout << "BUBBLE SORT";
    unsigned app;
    bool scambio = true;
    while(scambio)
    {
        scambio = false;
        for(int i=0; i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                app = v[i];
                v[i] = v[i+1];
                v[i+1] = app;
                scambio = true;
            }
        }
    }
}

//Quick Sort
void quickSort(int v[], int left, int right)
{
    int i = left, j = right;
    int app;
    int pivot = v[(left+right)/2];

    while(i <= j)
    {
        while(v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if(i <= j)
        {
            app = v[i];
            v[i] = v[j];
            v[j] = app;
            i++;
            j--;
        }
    };
    if(left < j)
        quickSort(v, left, j);
    if(right > i)
        quickSort(v, i, right);
}
void quickSort(int *v, int n)
{
    cout << "QUICK SORT";
    quickSort(v, 0, n-1);
}

//MY SORT
void mySort(int v[], int n)
{
    cout << "MY SORT";
    for(int i=0; i<n;i++)
    {
        for(int j=0; j+i<n;j++)
        {
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}


int (sortAlgorithm) (void (*f)(int[],int), int v[],int n)
{
    cout << "Creazione Struttura" << endl;
    genera(v,n);
    cout << "Ordinamento Struttura: ";
    clock_t start = clock();
    f(v,n);
    clock_t time = clock();
    double diff = (double) (time-start)/CLOCKS_PER_SEC;//*1000.0;
    cout << endl << "Struttura Ordinata" << endl;
    cout << "Tempo impiegato: " << diff << " secondi" << endl << endl;
}


int main()
{
    srand(time(NULL));
    cout << "Dimensione Struttura: ";
    cin >> n;
    int v[n];
    sortAlgorithm(insertionSort, v, n);
    sortAlgorithm(selectionSort, v, n);
    sortAlgorithm(bubbleSort, v, n);
    sortAlgorithm(quickSort, v, n);
    sortAlgorithm(mySort, v, n);
    return 0;
}
