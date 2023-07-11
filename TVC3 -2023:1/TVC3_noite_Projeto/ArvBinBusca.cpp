#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

//-----------------------------------------------------------------------------
//Q1
void ArvBinBusca::imprimeNiveis(int k)
{
    auxImprimeNiveis(raiz,k,0);
}
void ArvBinBusca::auxImprimeNiveis(NoArv *p, int k, int nivelAtual)
{
    if (p != NULL)
    {
        if (nivelAtual == k || nivelAtual == k+1 || nivelAtual == k+2)
        {
            cout << p->getInfo() << "  ";
        }

        if (nivelAtual > k+2)
        {
            return;
        }
        else
        {
            auxImprimeNiveis(p->getEsq(),k,nivelAtual+1);
            auxImprimeNiveis(p->getDir(),k,nivelAtual+1);   
        }
    }  
}
//-Q1

// ----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Q2
int ArvBinBusca::contaFolhas(int a, int b)
{
    int contPar = 0;

    auxContaFolhas(raiz,a,b,&contPar);

    return contPar;
}
void ArvBinBusca::auxContaFolhas(NoArv *p, int a, int b, int *cont)
{
    if (p != NULL)
    {
        if (p->getInfo() < a)
        {
            auxContaFolhas(p->getDir(),a,b,cont);
        }
        else if (p->getInfo() > b)
        {
            auxContaFolhas(p->getEsq(),a,b,cont);
        }
        else
        {
            if (p->getInfo()%2 == 0 && ehFolha(p))
            {
                (*cont)++;
            }
            else
            {
                auxContaFolhas(p->getEsq(),a,b,cont);
                auxContaFolhas(p->getDir(),a,b,cont);
            }
        }
    }
}
bool ArvBinBusca::ehFolha(NoArv *p)
{
    if (p != NULL)
    {
        if (p->getEsq() == NULL && p->getDir() == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
}
//-Q2
//-----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q3
void ArvBinBusca::buscaRemoveNivel(int ch)
{
    if (raiz != NULL)
    {
        NoArv *p = raiz;
        NoArv *aux = NULL;
        int nivel = 0;

        while (p != NULL)
        {
            if (p->getInfo() == ch)
            {
                if (ehFolha(p))
                {
                    if (p == aux->getEsq())
                    {
                        aux->setEsq(NULL);
                    }
                    else
                    {
                        aux->setDir(NULL);
                    }
                    delete p;
                    break;
                }
                else if (p->getEsq() != NULL && p->getDir() != NULL)
                {
                    cout << "nivel: " << nivel << endl;
                    break;
                }
                else
                {
                    cout << "Noh encontrado tem um unico filho" << endl;
                    break;
                }
            }
            else if (p->getInfo() > ch)
            {
                aux = p;
                p = p->getEsq();
                nivel++;
            }
            else
            {
                aux = p;
                p = p->getDir();
                nivel++;
            }
        }
        if (p == NULL)
        {
            cout << "Noh nao encontrado" << endl;
        }
    }
    else
    {
        cout << "Arvore vazia" << endl;
    }
}
// bool ArvBinBusca::ehFolha(NoArv *p)
// {
//     if (p != NULL)
//     {
//         if (p->getEsq() == NULL && p->getDir() == NULL)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     else
//     {
//         return false;
//     }
    
// }
//-Q3
// ----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
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

void ArvBinBusca::imprime()
{
    // cout << "ABB em ordem: ";
    // imprimeEmOrdem(raiz);
    // cout << endl;
    cout << "Arvore: " << endl;
    imprimeNivel(raiz,0);
    cout << endl;
}

void ArvBinBusca::imprimeEmOrdem(NoArv *p)
{
    if(p != NULL)
    {
        imprimeEmOrdem(p->getEsq());
        cout << p->getInfo() << " ";
        imprimeEmOrdem(p->getDir());
    }
}

void ArvBinBusca::imprimeNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for (int i = 1; i < nivel; i++)
            cout << "--";
        cout << " " << p->getInfo() << endl;
        imprimeNivel(p->getEsq(),nivel+1);
        imprimeNivel(p->getDir(),nivel+1);
    }
}
