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
    float mediaNivel(int k);
    int min();
    int max();
    void inverte();
    int noMaisEsquerda();
    int noMaisDireita();
    int minSubArvore(NoArv *p);
    int maxSubArvore(NoArv *p);
    bool ehABB();

    void imprime();

  private:
    NoArv *raiz; // ponteiro para o No raiz da arvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    NoArv* auxInsere(NoArv *p, int x);


    int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxMediaNivel(NoArv *p, int atual, int k, float *total, int *cont);
    int auxMin(NoArv *p, int *min);
    int auxMax(NoArv *p, int *max);
    void auxInverte(NoArv *p);
    int auxNoMaisEsquerda(NoArv *p);
    int auxNoMaisDireita(NoArv *p);
    bool auxEhABB(NoArv *p);
    
    void auxImprime(NoArv* r, int x);
};

#endif // ARVBIN_H_INCLUDED
