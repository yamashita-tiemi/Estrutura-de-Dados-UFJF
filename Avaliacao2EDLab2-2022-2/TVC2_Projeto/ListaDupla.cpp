#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla ()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla ()
{
    // OMITIDO
}

void ListaDupla::insereInicio (int val)
{
    NoDuplo *p = new NoDuplo ();
    p->setInfo (val);
    p->setProx (primeiro);
    p->setAnt (NULL);

    if (n == 0)
        ultimo = p;
    else
        primeiro->setAnt (p);

    primeiro = p;
    n = n + 1;
}

void ListaDupla::imprime ()
{
    cout << "[";
    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx ())
    {
        cout << p->getInfo ();
        if (p->getProx () != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q3
void ListaDupla::anexar(ListaDupla *lde)
{
    if (lde->primeiro != NULL)
    {
        if (primeiro != NULL)
        {
            primeiro->setAnt(lde->ultimo);
            lde->ultimo->setProx(primeiro);

            primeiro = lde->primeiro;
        }
        else
        {
            primeiro = lde->primeiro;
            ultimo = lde->ultimo;
        }

        n = n + lde->n;

        lde->primeiro = NULL;
        lde->ultimo = NULL;
        lde->n = 0;
    }
    else
    {
        cout << "Lista lde vazia" << endl;
    } 
}
//-Q3
// ----------------------------------------------------------------------------
