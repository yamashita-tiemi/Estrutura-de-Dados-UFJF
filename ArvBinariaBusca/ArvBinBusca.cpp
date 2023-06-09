#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}

int ArvBinBusca::maior()
{
    if (vazia())
    {
        cout << "Arvore vazia" << endl;
        exit(1);
    }
    else
        return auxMaior(raiz);
}
int ArvBinBusca::auxMaior(NoArv *p)
{
    if (p->getDir() == NULL)
    {
        return p->getInfo();
    }
    return auxMaior(p->getDir());
}

int ArvBinBusca::menor()
{
    if (vazia())
    {
        cout << "Arvore vazia" << endl;
        exit(1);
    }
    else
        return auxMenor(raiz);
}
int ArvBinBusca::auxMenor(NoArv *p)
{
    if (p->getEsq() == NULL)
    {
        return p->getInfo();
    }
    return auxMenor(p->getEsq());
}

void ArvBinBusca::removeMaior()
{
    NoArv *p = raiz;
    NoArv *aux;
    while (p->getDir() != NULL)
    {
        aux = p;
        p = p->getDir();
    }

    if (p == raiz)
    {
        raiz = p->getEsq();
        delete p;
    }
    else
    {
        if (p->getEsq() == NULL)
        {
            aux->setDir(removeFolha(p));
        }
        else
        {
            aux->setDir(remove1Filho(p));
        }
    }
}

void ArvBinBusca::removeMenor()
{
    NoArv *p = raiz;
    NoArv *aux;
    while (p->getEsq() != NULL)
    {
        aux = p;
        p = p->getEsq();
    }

    if (p == raiz)
    {
        raiz = p->getDir();
        delete p;
    }
    else
    {
        if (p->getDir() == NULL)
        {
            aux->setEsq(removeFolha(p));
        }
        else
        {
            aux->setEsq(remove1Filho(p));
        }
    }
}

int ArvBinBusca::contaParesCaminho(int x)
{
    int par = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        if (p->getInfo()%2 == 0)
        {
            par++;
        }

        if(x == p->getInfo())
            break;
        else if(x > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return par;
}

NoArv* ArvBinBusca::maiorSubArvEsq(NoArv *p)
{
    NoArv *aux = p->getEsq();
    while(aux->getDir() != NULL)
        aux = aux->getDir();
    return aux;
}

void ArvBinBusca::contaMaiores(int val)
{
    auxContaMaiores(raiz, val);
}

void ArvBinBusca::auxContaMaiores(NoArv *p,int val)
{
    if (p != NULL)
    {
        if (p->getInfo() > val)
        {
            cout << p->getInfo() << endl;
            auxContaMaiores(p->getEsq(), val);
            cout << p->getInfo() << endl; //imprime em ordem crescente
            auxContaMaiores(p->getDir(), val);
        }
        else
        {
            auxContaMaiores(p->getDir(), val);
        }
    }
}

void ArvBinBusca::auxContaMenores(NoArv *p,int val)
{
    if (p != NULL)
    {
        if (p->getInfo() < val)
        {
            cout << p->getInfo() << endl;
            auxContaMenores(p->getEsq(), val);
            cout << p->getInfo() << endl; //imprime em ordem crescente
            auxContaMenores(p->getDir(), val);
        }
        else
        {
            auxContaMenores(p->getEsq(), val);
        }
    }
}

// void ArvBinBusca::auxContaMenores(NoArv *p,int a, int b)
// {
//     if (p != NULL)
//     {
//         if (p->getInfo() < val)
//         {
//             cout << p->getInfo() << endl;
//             auxContaMenores(p->getEsq(), val);
//             cout << p->getInfo() << endl; //imprime em ordem crescente
//             auxContaMenores(p->getDir(), val);
//         }
//         else
//         {
//             auxContaMenores(p->getEsq(), val);
//         }
//     }
// }

void ArvBinBusca::contaPreencheVet(NoArv *p,int a, int b)
{
    // int n = auxContaNos(raiz);
    int n = 10;
    int *vet = new int[n];
    // int *i = new int;
    // *i = 0;
    int i = 0;

    auxContaPreencheVet(raiz,a,b,vet,&i);
}

void ArvBinBusca::auxContaPreencheVet(NoArv *p,int a, int b, int vet[], int *i)
{
    if (p != NULL)
    {
        if (p->getInfo() >= a && p->getInfo() <= b)
        {
            auxContaPreencheVet(p->getEsq(),a,b,vet,i);
            vet[*i] = p->getInfo();
            (*i)++;
            auxContaPreencheVet(p->getDir(),a,b,vet,i);
        }
        else if (p->getInfo() < a)
        {
            auxContaPreencheVet(p->getDir(),a,b,vet,i);
        }
        else //valor do no é maior q b
        {
            auxContaPreencheVet(p->getEsq(),a,b,vet,i);
        }
    }
}

void ArvBinBusca::contaParesImparesCaminho(int x, int *pares, int *impares)
{
    *pares = *impares = 0;

    NoArv *p = raiz;
    while(p != NULL)
    {
        if (p->getInfo()%2 == 0)
            (*pares)++;
        else
            (*impares)++;
        

        if(x == p->getInfo())
            break;
        else if(x > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
}

