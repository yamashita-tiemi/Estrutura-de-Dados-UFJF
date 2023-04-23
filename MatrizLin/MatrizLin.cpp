#include <iostream>
#include <cstdlib>

#include "MatrizLin.h"

using namespace std;

MatrizLin::MatrizLin(int mm, int nn)
{
    cout << "Criando um objeto MatrizLin" << endl;
    nl = mm;
    nc = nn;
    vet = new float[nl*nc];
}

MatrizLin::~MatrizLin()
{
    cout << "Destruindo um objeto MatrizLin" << endl;
    delete [] vet;
}

int MatrizLin::detInd(int i, int j)
{
    if(i >= 0 && i < nl && j >= 0 && j < nc)
        return nc*i + j;
    else
        return -1;
}

float MatrizLin::get(int i, int j)
{
    int k = detInd(i, j);
    if(k != -1)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void MatrizLin::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if(k != -1)
        vet[k] = val;
    else
        cout << "ERRO: Indice invalido!" << endl;
}

void MatrizLin::imprime(int m, int n)
{
    for (int i = 0; i < (m); i++)
    {
        for(int j = 0; j < n; j++)
        {
            int val = j + n*i;

            if(i == (m-1) && j == (n-1))
                cout << get(i, j);
            else
                cout << get(i, j) << "," << "\t";
        }
        cout << endl;
    }
}

float MatrizLin::maiorValor()
{
    float maior = vet[0];
    for(int i = 0; i < nl*nc; i++)
    {
        if (vet[i] > maior)
        {
            maior = vet[i];
        }
    }
    return maior;
}

MatrizLin* MatrizLin::transposta()
{
    MatrizLin* matT = new MatrizLin(nc, nl);
    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            int k = detInd(i, j);
            float val = vet[k];
            matT->set(j, i, val);
        }
    }
    return matT;
}

int MatrizLin::getNl()
{
    return nl;
}

int MatrizLin::getNc()
{
    return nc;
}