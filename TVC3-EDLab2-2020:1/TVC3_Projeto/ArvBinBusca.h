#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    void insere(int val);
    void imprime();
    void removeMenor(int val);

    //Q1
    int* criaVetFolhas(int k, int *n);

    //Q2
    int contaNos1Filho(int val);

    void imprimeNivel();

private:
    NoArv* raiz; // ponteiro para o No raiz da �rvore

    NoArv* libera(NoArv *p);
    NoArv* auxInsere(NoArv *p, int val);
    void imprimeEmOrdem(NoArv* p);

    //Q2
    int classificaFilhos(NoArv *pai);

    //Q3
    NoArv* auxRemoveMenor(NoArv *p, int val);

    int* auxCriaVetFolhas(NoArv *p, int k, int *vet, int nivelAtual, int *i);

    void auxImprimeNivel (NoArv *p, int nivel);
};

#endif // ARVBINBUSCA_H_INCLUDED
