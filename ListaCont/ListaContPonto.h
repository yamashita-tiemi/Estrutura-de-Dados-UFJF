#ifndef LISTACONTPONTO_H_INCLUDED
#define LISTACONTPONTO_H_INCLUDED
#include "Ponto.h"

class ListaContPonto
{
private:
    int max;
    int n;
    Ponto *vet;

public:
    ListaContPonto(int tam);
    ~ListaContPonto();

    Ponto get(int k);
    void set(int k, Ponto val);
    void insereFinal(Ponto val);
    void insereK(int k, Ponto val);
    void insereInicio(Ponto val);
    void removeFinal();
    void removeK(int k);
    void removeInicio();
    void imprimeDist();
};

#endif // LISTACONT_H_INCLUDED
