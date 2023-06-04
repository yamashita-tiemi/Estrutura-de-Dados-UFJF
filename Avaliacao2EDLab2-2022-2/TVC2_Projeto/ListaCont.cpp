#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q1
ListaCont* ListaCont::moveParesInvertidos ()
{
    // Remova o código abaixo, se necessário.
    // return NULL;

    ListaCont *nova = new ListaCont(n);
    int cont = 0;

    for (int i = n-1; i >= 0; i--)
    {
        if (vet[i]%2 == 0)
        {
            nova->insereFinal(vet[i]);
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        if (vet[i]%2 == 0)
        {
            removeK(i);
        }
    }

    return nova;
}
//-Q1
// ----------------------------------------------------------------------------

ListaCont::ListaCont (int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont ()
{
    delete [] vet;
}

void ListaCont::insereFinal (int val)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit (1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::imprime ()
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i + 1 < n)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

void ListaCont::removeK(int k)
{
    if(k >= 0 && k < n)
    {
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n = n - 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}
// ----------------------------------------------------------------------------
