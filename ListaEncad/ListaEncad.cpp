#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"
#include "No.h"

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncad::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}


void ListaEncad::insereInicio(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;

    n++;
    if(n == 1) ultimo = p;
}

void ListaEncad::insereFinal(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL) ultimo->setProx(p);
    ultimo = p;

    n++;
    if(n == 1) primeiro = p;
}

void ListaEncad::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}


void ListaEncad::imprime()
{
    No* p = primeiro;
    while (p != NULL) 
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << endl;
}

int ListaEncad::numNos()
{
    return n;
}

int ListaEncad::buscaMaior(int val)
{
    No* p;
    int i = 0;
    if(primeiro != NULL)
    {
        p = primeiro;
        while (p != NULL)
        {
            if (p->getInfo() > val)
            {
                return i;
            }
            else
            {
                p = p->getProx();
                i++;
            }
        }
        return -1;
    }
    else
    {
        cout << "ERRO: lista vazia!" << endl;
        return -1;
    }
}

void ListaEncad::limpar()
{
    primeiro = NULL;
}

float ListaEncad::calculaMedia()
{
    No* p;
    float total = 0;
    if(primeiro != NULL)
    {
        p = primeiro;
        while (p != NULL)
        {
            total += p->getInfo();
            p = p->getProx();
        }
        return total/n;
    }
    else
    {
        cout << "ERRO: lista vazia!" << endl;
        return -1;
    }
}

void ListaEncad::concatena(ListaEncad *l2)
{
    No* p2 = l2->primeiro;
    if(p2 != NULL)
    {
        while (p2 != NULL)
        {
            insereFinal(p2->getInfo());
            p2 = p2->getProx();
        }
    }
    else
        cout << "ERRO: lista 2 vazia!" << endl;
}

ListaEncad* ListaEncad::partir(int x)
{
    ListaEncad* nl = new ListaEncad();
    No* p;
    int i = 0;
    if(primeiro != NULL)
    {
        p = primeiro;
        No* t;
        while (p != NULL)
        {
            if (i == x)
            {
                nl->primeiro = p;
                nl->ultimo = ultimo;
                t->setProx(NULL);
                ultimo = t;
            }
            i++;
            t = p;
            p = p->getProx();
        }
        n = n - x;
        nl->n = x;
        return nl;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

// void ListaEncad::insereOrdenado(int val)
// {
//     No* novo = new No();
//     No* t;
//     No* aux;

//     if (primeiro != NULL)
//     {
//         t = primeiro;

//         while (t!=NULL)
//         {
//             if(t->getInfo() < val){
//                 aux = t;
//                 t = t->getProx();
    
//             }
            
//         }
//         novo->setInfo(val);
//         novo->setProx(t);
//         aux->setProx(p);

//         n++;
//     }
//     else
//     {
//         novo->setInfo(val);
//         novo->setProx(NULL);
//         primeiro = novo;
//         ultimo = primeiro;
//         n++;
//     }
// }

void ListaEncad::insereOrdenado(int val)
{
    No *novo = new No();
    novo->setInfo(val);

    No *p;
    No *t;

    if (primeiro != NULL)
    {
        p = primeiro;

        if (p->getInfo() >= val)
        {
            // novo->setProx(p);
            // primeiro = novo;
            // n++;
            insereInicio(val);
        }
        else
        {
            while (p->getInfo() < val)
            {
                if (p->getProx() == NULL)
                {
                    // p->setProx(novo);
                    // novo->setProx(NULL);
                    // ultimo = novo;
                    // n++;
                    // return;
                    insereFinal(val);
                    return;
                }
                else
                {
                    t = p;
                    p = p->getProx();
                }
                
            }
            t->setProx(novo);
            novo->setProx(p);
            n++;
        }
    }
    else
    {
        novo->setProx(NULL);
        primeiro = novo;
        ultimo = novo;
        n++;
    }
}

void ListaEncad::insereK(int k, int val)
{
    if (k == 0 || primeiro == NULL)
    {
        insereInicio(val);
    }
    else if (k == n || ultimo == NULL)
    {
        insereFinal(val);
    }
    else if (k>0 && k<n)
    {
        No *novo = new No();
        novo->setInfo(val);

        No *p = primeiro;
        No *t;
        int i = 1;

        while (p != NULL)
        {
            // cout << i << " ";
            if (i == k)
            {
                t->setProx(novo);
                novo->setProx(p);
                n++;
                break;
            }
            else
            {
                t = p;
                p = p->getProx();
                i++;
            }
        }
    }
    else
    {
        cout << "Erro: indice invalido" << endl;
    }    
}

void ListaEncad::removeK(int k)
{
    if (k == 0)
    {
        removeInicio();
    }
    else if (k == n)
    {
        removeFinal();
    }
    else if (k>0 && k<n)
    {
        No *p = primeiro;
        No *t;
        int i = 1;

        while (p != NULL)
        {
            if (i == k)
            {
                t->setProx(p->getProx());
                p->setProx(NULL);
                // delete p;
                n--;
                break;
            }
            else
            {
                t = p;
                p = p->getProx();
                i++;
            }
        }
    }
    else
    {
        cout << "Erro: indice invalido" << endl;
    }   
}
