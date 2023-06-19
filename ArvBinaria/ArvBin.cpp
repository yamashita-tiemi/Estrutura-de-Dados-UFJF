#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Arvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}
int ArvBin::auxContaNos(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        int esq = auxContaNos(p->getEsq());
        int dir = auxContaNos(p->getDir());
	
        return esq + dir + 1;
    }
}

int ArvBin::contaNosFolhas()
{
    return auxContaNosFolhas(raiz);
}
int ArvBin::auxContaNosFolhas(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        int esq = auxContaNosFolhas(p->getEsq());
        int dir = auxContaNosFolhas(p->getDir());

        int cont = esq + dir;
	
        if (p->getEsq() == NULL && p->getDir() == NULL)
		cont++;

        return cont;
    }
}

int ArvBin::altura()
{
    return auxAltura(raiz);
}
int ArvBin::auxAltura(NoArv *p)
{
    if (vazia())
        return -1;
    else
    {
        if (p == NULL)
            return -1;
        else
        {
            int esq = auxContaNosFolhas(p->getEsq());
            int dir = auxContaNosFolhas(p->getDir());

            if (esq >= dir)
                return esq + 1;
            else
                return dir + 1;
        }
    }
}

int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}
int ArvBin::auxContaImpar(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        int esq = auxContaImpar(p->getEsq());
        int dir = auxContaImpar(p->getDir());
	
        int cont = esq + dir;
	
        if (p->getInfo()%2 == 1)
		    cont++;

        return cont;
    }
}

int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);
}
int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if (p == NULL)
        return 0;
    else
    {
        int esq = auxContaFolhaImpar(p->getEsq());
        int dir = auxContaFolhaImpar(p->getDir());
	
        int cont = esq + dir;
	
        if (p->getEsq() == NULL && p->getDir() == NULL)
            if (p->getInfo()%2 == 1)
                cont++;

        return cont;
    }
}
    
// void ArvBin::imprimeNivel(int k)
// {
//     auxImpNivel(raiz, 0, k);
// }
// void ArvBin::auxImpNivel(NoArv *p, int atual, int k)
// {
//     if (atual == k)
//     {
//         cout << p->getInfo() << " ";
//     }
    
// }
    // float ArvBin::mediaNivel(int k);
    // int ArvBin::min();
    // int ArvBin::max();
    // void ArvBin::inverte();
    // void ArvBin::auxInverte(NoArv *p);
    // int ArvBin::noMaisEsquerda();
    // int ArvBin::noMaisDireita();
    // int ArvBin::minSubArvore(NoArv *p);
    // int ArvBin::maxSubArvore(NoArv *p);
    // bool ArvBin::ehABB();
    // bool ArvBin::auxEhABB(NoArv *p);

void ArvBin::imprime()
{
	cout << "Arvore:" << endl;
	auxImprime(raiz, 0);
	cout << endl;
}

void ArvBin::auxImprime(NoArv* p, int nivel)
{
	if (p != NULL)
	{
		cout << "Nivel:(" << nivel << ") " << p->getInfo() << endl;
		auxImprime(p->getEsq(), nivel + 1);
		auxImprime(p->getDir(), nivel + 1);
	}
}