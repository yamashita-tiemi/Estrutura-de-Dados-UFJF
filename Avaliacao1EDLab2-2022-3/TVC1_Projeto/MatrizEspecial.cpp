#include <iostream>
#include "MatrizEspecial.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q4
MatrizEspecial::MatrizEspecial(int nn)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    n = nn;
    vet = new int[n];
}

MatrizEspecial::~MatrizEspecial()
{
    // Implemente aqui sua solucao!
    delete [] vet;
}

int MatrizEspecial::detInd(int i, int j)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    if(i >= 0 && i < n && j >= 0 && j < n)
    {
        if (i == j)
        {
            return i;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

int MatrizEspecial::get(int i, int j)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    int k = detInd(i,j);
    if(k == -1)
    {
        cout << "Indice invalido" << endl;
        exit(1);
    }
    if (k == -2)
    {
        if(i>j)
        {
            return i-j;
        }
        else
        {
            return j-i;
        }
    }
    else
    {
        return vet[k];
    }
    
}

void MatrizEspecial::set(int i, int j, int val)
{
    // Implemente aqui sua solucao!
    int k = detInd(i,j);
    if(k == -1)
    {
        cout << "Indice invalido" << endl;
        exit(1);
    }
    if (k == -2)
    {
        if((i>j && val != (i-j)) || (i<j && val != (j-i)))
        {
            cout << "Valor invalido" << endl;
        }
    }
    else
    {
        vet[k] = val;
    }
}
//-Q4
// ----------------------------------------------------------------------------

void MatrizEspecial::imprime()
{
    cout << "Matriz " << n << " x " << n << ":" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << get(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
}
