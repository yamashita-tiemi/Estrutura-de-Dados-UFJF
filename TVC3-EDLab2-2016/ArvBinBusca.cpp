#include "ArvBinBusca.h"

// ----------------------------------------------------------------------------
//Q1
int ArvBinBusca::contaIntervalo(int a, int b)
{
    // IMPLEMENTE AQUI SUA SOLUCAO
    // REMOVA O COMANDO ABAIXO
    //    return 0;
    int cont = 0;
    No *p = raiz;

    auxContaIntervalo(raiz,a,b,&cont);

    return cont;
}
void ArvBinBusca::auxContaIntervalo(No *p, int a, int b, int *cont)
{
    if (p != NULL)
    {
        cout << *cont << endl;
        if (p->getInfo() >= a && p->getInfo() <= b)
        {
            auxContaIntervalo(p->getEsq(),a,b,cont);
            (*cont) ++;
            auxContaIntervalo(p->getDir(),a,b,cont);
        }
        else if (p->getInfo() < a)
        {
            auxContaIntervalo(p->getDir(),a,b,cont);
        }
        else
        {
            auxContaIntervalo(p->getEsq(),a,b,cont);
        }
    }
}


//-Q1
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//Q2
No * ArvBinBusca::buscaPai(int x)
{
    // IMPLEMENTE AQUI SUA SOLUCAO
    // REMOVA O COMANDO ABAIXO
	// return NULL;
    No *p = raiz;
    No *aux = NULL;

    while (p != NULL)
    {
        if (p->getInfo() == x)
        {
            if (aux == NULL)
            {
                cout << "x é raiz"<< endl;
            }
            return aux;
        }
        else if (p->getInfo() > x)
        {
            aux = p;
            p = p->getEsq();
        }
        else
        {
            aux = p;
            p = p->getDir();
        }
    }
    return p;
}
//-Q2
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q3
int * ArvBinBusca::criaVetNivel(int k)
{
    // IMPLEMENTE AQUI SUA SOLUCAO
    // REMOVA O COMANDO ABAIXO
    // return NULL;
    int *vet = new int(pow(2,k));
    int i = 0;
    int nivel = 0;
    return auxCriaVetNivel(k, raiz, vet, nivel, &i);
}

int * ArvBinBusca::auxCriaVetNivel(int k, No *p, int *vet, int nivel, int *i)
{
    if (p != NULL)
    {
        cout << "nivel: " << nivel << endl;
        if (nivel == k)
        {
            // cout << "entrou: " << p->getInfo() << endl;
            // cout << "i: " << *i << endl;
            vet[(*i)] = p->getInfo();
            (*i)++;
        }
        else 
        {
            auxCriaVetNivel(k, p->getEsq(), vet, nivel + 1, i);
            auxCriaVetNivel(k, p->getDir(), vet, nivel + 1, i);
        }
    }
    return vet;
}
//-Q3
// ----------------------------------------------------------------------------


// Restante da classe da ABB --------------------------------------------------

 ArvBinBusca::ArvBinBusca()
 {
     raiz = NULL;
 }

 ArvBinBusca::~ArvBinBusca()
 {

 }

int ArvBinBusca::consultaRaiz()
{
    if(raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Erro em consultaRaiz(): arvore vazia" << endl;
        exit(1);
    }
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int x)
{
    No * p = auxInsere(raiz, x);
    if (raiz == NULL)
        raiz = p;
}

No * ArvBinBusca::auxInsere(No * p, int x)
{
    if(p == NULL)
    {
        p = new No();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(x < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), x));
    else
        p->setDir(auxInsere(p->getDir(), x));

    return p;
}

bool ArvBinBusca::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBinBusca::auxBusca(No * p, int x)
{
    if(p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (x < p->getInfo() )
        return auxBusca(p->getEsq(), x);
    else
        return auxBusca(p->getDir(), x);
}

void ArvBinBusca::imprime()
{
    auxImprime(raiz, 0);
}

void ArvBinBusca::auxImprime(No * p, int nivel)
{
    if (p != NULL) {
        cout << "(" << nivel << ")";
        for (int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel + 1);
        auxImprime(p->getDir(), nivel + 1);
    }
}

int ArvBinBusca::numNos()
{
    return auxNumNos(raiz);
}

int ArvBinBusca::auxNumNos(No *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + auxNumNos(p->getEsq()) + auxNumNos(p->getDir());
}
