#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
  public:
    ArvBinBusca() { raiz = NULL; }
    void insere(int val) { raiz = auxInsere(raiz, val); }
    void imprime();

    ///Q1
    void imprimeNiveis(int k);
    ///Q2
    int contaFolhas(int a, int b);
    ///Q3
    void buscaRemoveNivel(int ch);


  private:
    NoArv* raiz; // ponteiro para o No raiz da �rvore
    NoArv* auxInsere(NoArv *p, int val);
    void imprimeEmOrdem(NoArv* p);
    void imprimeNivel(NoArv *p, int nivel);

    void auxImprimeNiveis(NoArv *p, int k, int nivelAtual);
    void auxContaFolhas(NoArv *p, int a, int b, int *cont);
    bool ehFolha(NoArv *p);
};

#endif // ARVBINBUSCA_H_INCLUDED
