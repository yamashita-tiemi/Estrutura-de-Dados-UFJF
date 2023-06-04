#include <iostream>
#include <cstdlib>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    inicio = NULL;
    fim = NULL;
}

FilaEncad::~FilaEncad()
{
    ///omitido
}

bool FilaEncad::vazia()
{
    if(inicio == NULL)
        return true;
    else
        return false;
}

void FilaEncad::enfileira(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        inicio = p;
    else
        fim->setProx(p);
    fim = p;
}

int FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}

int FilaEncad::desenfileira()
{
    No* p;
    if(inicio != NULL)
    {
        p = inicio;
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL;
        int val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::imprime ()
{
    cout << "[";
    for (No *p = inicio; p != NULL; p = p->getProx ())
    {
        cout << p->getInfo ();
        if (p->getProx () != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
