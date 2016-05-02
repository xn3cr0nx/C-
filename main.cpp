#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>


using namespace std;

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{

int cartella[10];
int estrazioni[90];
int mancanti = 0;



sleep(1000000);
cout << "Benvenuti alla tombola" << endl;
sleep(1000000);
cout << "Per giocare: " << endl;
sleep(1000000);
cout << "Scegliere i  10 numeri della vostra cartella" << endl;
sleep(3000000);
cout << "I numeri vanno scritti uno alla volta, dopo aver premuto invio" << endl;
sleep(3000000);
cout << "Si possono scegliere numeri compresi tra 1 e 90" << endl;
sleep(3000000);
cout << "Non è possibile inserire due numeri uguali nella stessa cartella" << endl;

for(int i=1; i <= 10; i++)
{
    cout << "Numero " << i << ": ";
    cin >> cartella[i];
        if(cartella[i] > 90 || cartella[i] < 1)
        {
            cout << "Non corretto, numero fuori dall' intervallo, reinserire il numero" << endl;
            i = i - 1;
        }

        for(int b=1; b < i; b++)
        {
            if(cartella[i]==cartella[b])
            {
                cout << "Il numero inserito è uguale ad uno precedente, inserire un'altro numero" << endl;
                i = i - 1;
            }
        }
}

sleep(1000000);
cout << "Hai scelto la tua cartella: " << endl << endl;
cout << "---------------------------" << endl;
cout << "| " << cartella[1] << " | " << cartella[2] << " | ";
cout << cartella[3] << "  | " << cartella[4] << " | " << cartella[5] << " |" << endl;
cout << "|-------------------------|" << endl;
cout << "| " << cartella[6] << " | " << cartella[7] << " | ";
cout << cartella[8] << "  | " << cartella[9] << " | " << cartella[10] << " |" << endl;
cout << "---------------------------" << endl << endl;

sleep(5000000);

cout << "Comincia l' estrazione" << endl;
sleep(2000000);
cout << "Pronti..." << endl;
sleep(3000000);
cout << "Attenti..." << endl;
sleep(3000000);
cout << "Via!!" << endl;

for(int c=1; c <= 90; c++)
{
if(mancanti==10)
{
  break;
}
srand(time(NULL));
int tmp = (rand() % 90 + 1);
    for(int d = 1; d <= c; d++)
    {
        if(estrazioni[d] == tmp)
        {
            c = c - 1;
            break;
        }
        else
            if (d == c)
            {
                sleep(1000000);
                cout << "Estrazione numero " << c << ": ";
                estrazioni[c] = tmp;
                cout << estrazioni[c] << endl;
                for(int k=1; k != 11; k++)
                {
                    if(estrazioni[c] == cartella[k])
                    {
                        cout << "Il numero estratto è presente nella tua cartella" << endl; sleep(1000000);
                        mancanti++;
                        if((10 - mancanti) > 0)
                        {
                        cout << "Ti mancano " << (10 - mancanti) << " numeri" << endl;
                        }
                        break;
                    }
                }
            }
    }
}
cout << "Tutti i tuoi numeri sono stati estratti" << endl;
sleep(1000000);
cout << "Hai vinto!!" << endl;
}
