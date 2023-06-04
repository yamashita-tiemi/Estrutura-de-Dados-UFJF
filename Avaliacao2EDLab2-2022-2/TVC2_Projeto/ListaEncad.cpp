#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q2
void ListaEncad::insereDepoisMenor(int val)
{
    No *novo = new No();
    novo->setInfo(val);

    No *p = primeiro;

    if (p != NULL)
    {
        No *m;
        int menor = p->getInfo();

        while (p != NULL)
        {
            if (p->getInfo() < menor)
            {
                m = p;
            }
            p = p->getProx();
        }
        if (m == ultimo)
        {
            insereFinal(val);
        }
        else
        {
            novo->setProx(m->getProx());
        }
        m->setProx(novo);
        n++;
    }
    else
    {
        cout << "Lista vazia!" << endl;
    }
    
    
}
//-Q2
// ----------------------------------------------------------------------------

ListaEncad::ListaEncad ()
{
    primeiro = ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad ()
{
    // OMITIDO
}

void ListaEncad::insereFinal(int val)
{
    ///insere um novo nó no fim da lista com valor val
    No *p = new No(); // cria No apontado por p
    p->setInfo(val); // preenche informacao
    p->setProx(NULL);

    if(ultimo != NULL)
        ultimo->setProx(p);
    else
        primeiro = p;

    ultimo = p;
    n++;
}

void ListaEncad::imprime ()
{
    cout << "[";
    for (No *p = primeiro; p != NULL; p = p->getProx ())
    {
        cout << p->getInfo ();
        if (p->getProx () != NULL)
            cout << ", ";
    }
    cout << "]" << endl;
}

