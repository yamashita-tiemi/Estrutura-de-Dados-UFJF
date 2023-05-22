#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
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

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(NULL);
	p->setAnt(ultimo);

	if(n == 0) primeiro = p;
	else ultimo->setProx(p);

	ultimo = p;
	n = n + 1;
}

void ListaDupla::removeFinal()
{
    NoDuplo *p;
	if(primeiro != NULL)
	{
		p = ultimo;
		ultimo = p->getAnt();
		delete p;
		n = n - 1;

		if(n == 0) 	primeiro = NULL;
		else ultimo->setProx(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprime()
{
    NoDuplo *p;
    p = primeiro;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << p->getInfo() << " ";
            p = p->getProx();
        }
        cout << endl;
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprimeReverso()
{
    NoDuplo *p;
    p = ultimo;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << p->getInfo() << " ";
            p = p->getAnt();
        }
        cout << endl;
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{
    ListaDupla *nl = new ListaDupla();
    NoDuplo *p;
    NoDuplo *t;

    nl->primeiro = primeiro;

    p = ultimo;
    p->setProx(l2->primeiro);
    t = l2->primeiro;
    t->setAnt(p);

    nl->ultimo = l2->ultimo;

    nl->n = n + l2->n;

    return nl;
}

ListaDupla* ListaDupla::partir(int x)
{
    ListaDupla *nl = new ListaDupla();
    NoDuplo *p;
    NoDuplo *t;
    int i = 0;

    if (primeiro != NULL)
    {
        p = primeiro;

        while (p != NULL)
        {
            if (i == x)
            {
                t = p->getAnt();
                t->setProx(NULL);
                // ultimo = t;

                nl->primeiro = p;
                nl->primeiro->setAnt(NULL);
                nl->ultimo = ultimo;
                nl->n = i;

                n = n - i;
                ultimo = t;

                return nl;
            }
            p = p->getProx();
            i++;
        } 
    }
    else
        cout << "ERRO: lista vazia" << endl;
    
}

void ListaDupla::removeOcorrencias(int val)
{
    NoDuplo *p;
    NoDuplo *t;
    NoDuplo *u;

    if (primeiro != NULL)
    {
        p = primeiro;

        while (p != NULL)
        {
            if (p->getInfo() == val)
            {
                t = p->getAnt();
                u = p->getProx();

                t->setProx(u);
                u->setAnt(t);

                p = p->getProx();
                n = n - 1;
            }
            p = p->getProx();
        } 
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

int ListaDupla::numNos()
{
    return n;
}
