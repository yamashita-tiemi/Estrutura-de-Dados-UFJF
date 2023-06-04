#ifndef LISTAORDENCAD_H_INCLUDED
#define LISTAORDENCAD_H_INCLUDED

#include "No.h"

class ListaEncad
{
public:
    ListaEncad ();
    ~ListaEncad ();
    void insereFinal(int val);
    void imprime ();

    void insereDepoisMenor(int val);

private:
    No* primeiro, *ultimo;
    int n;
};

#endif
