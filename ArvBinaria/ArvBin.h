#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a arvore esta vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);

    int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    // float mediaNivel(int k);
    // int min();
    // int max();
    // void inverte();
    // void auxInverte(NoArv *p);
    // int noMaisEsquerda();
    // int noMaisDireita();
    // int minSubArvore(NoArv *p);
    // int maxSubArvore(NoArv *p);
    // bool ehABB();
    // bool auxEhABB(NoArv *p);

    void imprime();

  private:
    NoArv *raiz; // ponteiro para o No raiz da arvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);

    void auxImprime(NoArv* r, int x);

    int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
};

#endif // ARVBIN_H_INCLUDED
