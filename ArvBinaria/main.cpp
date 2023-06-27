#include <iostream>
#include "ArvBin.h"
#include "ArvBin.cpp"
using namespace std;

int main()
{
    ArvBin arv;
    // arv.montaArvore();
    // arv.insere(15);
    // arv.insere(25);
    // arv.insere(10);
    // arv.preOrdem();

    ArvBin arv1, arv2, arv3, arv4, arv5;
    ArvBin *nula = new ArvBin;
    arv1.cria(3, nula, nula);
    arv2.cria(5, nula, nula);
    arv3.cria(4, &arv1, &arv2);
    arv4.cria(12, nula, nula);
    arv5.cria(10, &arv3, &arv4);
    arv1.anulaRaiz();
    arv2.anulaRaiz();
    arv3.anulaRaiz();
    arv4.anulaRaiz();

    // -----10-----
    // ---9----7---
    // 3---4-------

    arv5.preOrdem();
    cout << endl;
    arv5.imprime();

    cout << "Num Nos: " << arv5.contaNos() << endl;
    cout << "Num Nos Folhas: " << arv5.contaNosFolhas() << endl;
    cout << "Altura: " << arv5.altura() << endl;
    cout << "Quantos Nos Impares: " << arv5.contaImpar() << endl;
    cout << "Quantos Folhas Impares: " << arv5.contaFolhaImpar() << endl;

    int x = 1;
    cout << "Nos do nivel " << x << ": ";
    arv5.imprimeNivel(x);
    cout << endl;

    cout << "Media dos Nos do nivel " << x << ": " << arv5.mediaNivel(x) << endl;
    cout << "Menor valor da arvore: " << arv5.min() << endl;
    cout << "Maior valor da arvore: " << arv5.max() << endl;

    // arv5.inverte();
    // -----10-----
    // --7----9----
    // -----4---3--
    arv5.imprime();

    cout << "No mais a esquerda: " << arv5.noMaisEsquerda() << endl;
    cout << "No mais a direita: " << arv5.noMaisDireita() << endl;
    cout << "Menor valor da subArvore: " << arv5.min() << endl;
    cout << "Se é arvore de busca(ABB): " << arv5.ehABB() << endl;

    return 0;
}
