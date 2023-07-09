#include "ArvBinBusca.h"
#include <cmath>

// ----------------------------------------------------------------------------
//Q1

void ArvBinBusca::nosImpares02Filhos(int *nImp, int *n02F)
{
    *nImp = 0;
    *n02F = 0;
    auxNosImpares02Filhos(raiz, nImp, n02F);
}
void ArvBinBusca::auxNosImpares02Filhos(NoArv *p,int *nImp, int *n02F)
{
    if (p != NULL)
    {
        if (p->getInfo()%2 == 1 || p->getInfo()%2 == -1)
        {
            // cout << p->getInfo() << " ";
            (*nImp)++;
        }

        if (nos02Filhos(p))
        {
            (*n02F)++;
        }

        auxNosImpares02Filhos(p->getEsq(),nImp,n02F);
        auxNosImpares02Filhos(p->getDir(),nImp,n02F);
    }
}
bool ArvBinBusca::nos02Filhos(NoArv *p)
{
    if (p->getEsq() == NULL && p->getDir() == NULL)
    {
        return true;
    }
    else if (p->getEsq() != NULL && p->getDir() != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }  
}


//-Q1

// ----------------------------------------------------------------------------
//Q2

void ArvBinBusca::insNaoRec(int val)
{
    if (raiz != NULL)
    {
        NoArv *p = raiz;
        NoArv *aux = raiz;

        NoArv *novo = new NoArv();
        novo->setInfo(val);

        while (p != NULL)
        {
            // cout << aux->getInfo() << " - " << p->getInfo() << endl; 
            if (p->getInfo() == val)
            {
                cout << "Erro" << endl;
                break;
            }
            else if (p->getInfo() > val)
            {
                aux = p;
                p = p->getEsq();
            }
            else
            {
                aux = p;
                p = p->getDir();
            }


            if (p == NULL)
            {
                if (aux->getInfo() > val)
                {
                    aux->setEsq(novo);
                    break;
                }
                else
                {
                    aux->setDir(novo);
                    break;
                }
            }
            if (aux->getInfo() > val && p->getInfo() < val)
            {
                novo->setEsq(p);
                aux->setEsq(novo);
                break;
            }
            if (aux->getInfo() < val && p->getInfo() > val)
            {
                novo->setDir(p);
                aux->setDir(novo);
                break;
            } 
        }
    }
    else
    {
        NoArv *novo = new NoArv();
        novo->setInfo(val);
        novo->setDir(NULL);
        novo->setEsq(NULL);

        raiz = novo;
    }
}

//-Q2

// ----------------------------------------------------------------------------
//Q3

int* ArvBinBusca::vetIntervalo(int a, int b, int k)
{
    int tam = pow(2,k)+1;
    int *vet = new int(tam);
    int indice = 0;

    vet = auxVetIntervalo(raiz,a,b,k,vet,0,&indice);

    for (int i = indice; i < tam; i++)
    {
        vet[i] = -1;
    }
    
    return vet;
}
int* ArvBinBusca::auxVetIntervalo(NoArv *p, int a, int b, int k, int *vet, int nivelAtual, int *i)
{
    if (p != NULL)
    {
        if (p->getInfo() < a)
        {
            auxVetIntervalo(p->getDir(),a,b,k,vet,nivelAtual+1,i);
        }
        else if (p->getInfo() > b)
        {
            auxVetIntervalo(p->getEsq(),a,b,k,vet,nivelAtual+1,i);
        }
        else
        {
            auxVetIntervalo(p->getEsq(),a,b,k,vet,nivelAtual+1,i);
            //em ordem
            if (nivelAtual == k)
            {
                vet[(*i)] = p->getInfo();
                (*i)++;
            }
            auxVetIntervalo(p->getDir(),a,b,k,vet,nivelAtual+1,i);
        }
    }
    return vet;    
}

//-Q3

// ----------------------------------------------------------------------------
// Restante da classe ArvBinBusca
// ----------------------------------------------------------------------------

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    /// destrutor vazio (s� para avalia��o)
}

void ArvBinBusca::cria(int c, ArvBinBusca *sae, ArvBinBusca *sad)
{///S� para a avalia��o.
    NoArv *p = new NoArv();
    p->setInfo(c);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBinBusca::addValores1()
{//adiciona valores em uma ABB
    ArvBinBusca *arvRaizNula = new ArvBinBusca(), a1, a2;

    a1.cria(-35, arvRaizNula, arvRaizNula);
    this->cria(-19, arvRaizNula, arvRaizNula);
    this->cria(-20, &a1, this);

    a1.cria(-5, arvRaizNula, arvRaizNula);
    a1.cria(10, &a1, arvRaizNula);
    this->cria(-15, this, &a1);

    a1.cria(45, arvRaizNula, arvRaizNula);
    a2.cria(60, arvRaizNula, arvRaizNula);
    a1.cria(50, &a1, &a2);

    a2.cria(80, arvRaizNula, arvRaizNula);
    a1.cria(75, &a1, &a2);

    this->cria(40, this, &a1);
}

void ArvBinBusca::addValores2()
{//adiciona valores em uma ABB
    ArvBinBusca *arvRaizNula = new ArvBinBusca(), a1, a2;

    this->cria(-35, arvRaizNula, arvRaizNula);
    this->cria(-20, this, arvRaizNula);

    a1.cria(-5, arvRaizNula, arvRaizNula);
    a1.cria(10, &a1, arvRaizNula);
    this->cria(-15, this, &a1);

    a1.cria(60, arvRaizNula, arvRaizNula);
    a1.cria(50, arvRaizNula, &a1);
    this->cria(40, this, &a1);
}

// void ArvBinBusca::imprime()
// {
//     auxImprime(raiz);
//     cout << endl;
// }

// void ArvBinBusca::auxImprime(NoArv *p)
// {
//     if(p != NULL)
//     {
//         auxImprime(p->getEsq());
//         cout << p->getInfo() << " ";
//         auxImprime(p->getDir());
//     }
// }


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