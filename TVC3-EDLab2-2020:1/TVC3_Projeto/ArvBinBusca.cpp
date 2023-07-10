#include <iostream>
#include <cmath>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca ()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca ()
{
    // OMITIDO
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq (libera (p->getEsq ()));
        p->setDir (libera (p->getDir ()));
        delete p;
        p = NULL;
    }
    return p;
}

void ArvBinBusca::insere (int val)
{
    raiz = auxInsere (raiz, val);
}

NoArv* ArvBinBusca::auxInsere (NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv ();
        p->setInfo (val);
        p->setEsq (NULL);
        p->setDir (NULL);
    }
    else if (val < p->getInfo ())
        p->setEsq (auxInsere (p->getEsq (), val));
    else
        p->setDir (auxInsere (p->getDir (), val));
    return p;
}

void ArvBinBusca::imprime()
{
    cout << "ABB em ordem: ";
    imprimeEmOrdem (raiz);
    cout << endl;
}

void ArvBinBusca::imprimeEmOrdem (NoArv *p)
{
    if (p != NULL)
    {
        imprimeEmOrdem (p->getEsq ());
        cout << p->getInfo () << " ";
        imprimeEmOrdem (p->getDir ());
    }
}

void ArvBinBusca::removeMenor (int val)
{
    raiz = auxRemoveMenor (raiz, val);
}

// ----------------------------------------------------------------------------
//Q1
int* ArvBinBusca::criaVetFolhas(int k, int *n)
{
    *n = pow(2,k);
    int *vet = new int(*n);
    int indice = 0;

    vet = auxCriaVetFolhas(raiz,k,vet,0,&indice);

    for (int i = indice; i < (*n); i++)
    {
        vet[i] = -1;
    }
    
    return vet;
}
int* ArvBinBusca::auxCriaVetFolhas(NoArv *p, int k, int *vet, int nivelAtual,int *i)
{
    if (p != NULL)
    {
        if (nivelAtual <= k)
        {
            if (p->getEsq() == NULL && p->getDir() == NULL)
            {
                vet[(*i)] = p->getInfo();
                (*i)++;
            }

            auxCriaVetFolhas(p->getEsq(),k,vet,nivelAtual+1,i);
            auxCriaVetFolhas(p->getDir(),k,vet,nivelAtual+1,i);
        }
        else
        {
            return 0;
        }

        return vet;
    }
    else
    {
        return NULL;
    }
    
    
}
//-Q1
// ----------------------------------------------------------------------------

// ------------------------------------------------------------------------
//Q2
int ArvBinBusca::classificaFilhos(NoArv *pai)
{
    if (pai->getEsq() != NULL && pai->getDir() == NULL)
    {
        return -1;
    }
    if (pai->getEsq() == NULL && pai->getDir() == NULL)
    {
        return 0;
    }
    if (pai->getEsq() == NULL && pai->getDir() != NULL)
    {
        return 1;
    }
    else
    {
        return 2;
    }    
}

int ArvBinBusca::contaNos1Filho(int val)
{
    NoArv *p = raiz;
    int cont = 0;

    while (p != NULL)
    {
        if (classificaFilhos(p) == 1 || classificaFilhos(p) == -1)
        {
            cont++;
        }

        if (p->getInfo() == val)
        {
            return cont;
        }
        
        if (p->getInfo() > val)
        {
            p = p->getEsq();
        }
        else if (p->getInfo() < val)
        {
            p = p->getDir();
        }
    }
    return cont;
}
//-Q2
// ------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q3
NoArv* ArvBinBusca::auxRemoveMenor (NoArv *p, int val)
{
    if (p != NULL)
    {
        if (p->getInfo() == val)
        {
            p->setEsq(libera(p->getEsq()));
        }
        else if (p->getInfo() > val)
        {
            p->setEsq(auxRemoveMenor(p->getEsq(),val));
        }
        else
        {
            NoArv *aux = p->getDir();
            p->setEsq(libera(p->getEsq()));
            delete p;
            p = auxRemoveMenor(aux,val);
        }
        return p;
    }
    else
    {
        return NULL;
    }
}
//-Q3
// ----------------------------------------------------------------------------


void ArvBinBusca::imprimeNivel()
{
    auxImprimeNivel(raiz,0);
}

void ArvBinBusca::auxImprimeNivel (NoArv *p, int nivel)
{
    if (p != NULL)
    {
        cout << "("<< nivel << ")";
        for (int i = 1; i <= nivel ; i++)
        {
            cout << "--";
        }
        cout << " " << p->getInfo() << endl;
        auxImprimeNivel(p->getEsq(),nivel+1);
        auxImprimeNivel(p->getDir(),nivel+1);
    }
}