#include <iostream>
#include <cstdlib>
#include "Ponto.h"
#include "ListaContPonto.h"

using namespace std;

ListaContPonto::ListaContPonto(int tam)
{
    cout << "Criando objeto ListaContPonto" << endl;
    max = tam;
    n = 0;
    vet = new Ponto[max];
}

ListaContPonto::~ListaContPonto()
{
    cout << "Destruindo objeto ListaContPonto" << endl;
    delete [] vet;
}

Ponto ListaContPonto::get(int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaContPonto::set(int k, Ponto val)
{
    if(k >= 0 && k < n)
        vet[k] = val;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaContPonto::insereFinal(Ponto val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaContPonto::removeFinal()
{
    if(n == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaContPonto::insereK(int k, Ponto val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if(k >= 0 && k < n)
    {
        for(int i = n-1; i >= k; i--)
            vet[i+1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaContPonto::removeK(int k)
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

void ListaContPonto::insereInicio(Ponto val)
{
    if(n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else
        insereK(0, val);
}

void ListaContPonto::removeInicio()
{
    removeK(0);
}

void ListaContPonto::imprimeDist()
{
    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!"<< endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vet[i].distancia(vet+j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}