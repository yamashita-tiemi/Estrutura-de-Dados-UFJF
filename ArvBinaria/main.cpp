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
    arv2.cria(4, nula, nula);
    arv3.cria(9, &arv1, &arv2);
    arv4.cria(7, nula, nula);
    arv5.cria(10, &arv3, &arv4);
    arv1.anulaRaiz();
    arv2.anulaRaiz();
    arv3.anulaRaiz();
    arv4.anulaRaiz();

    arv5.preOrdem();
    cout << endl;
    arv5.imprime();

    cout << "Num Nos: " << arv5.contaNos() << endl;
    cout << "Num Nos Folhas: " << arv5.contaNosFolhas() << endl;
    cout << "Altura: " << arv5.altura() << endl;
    cout << "Quantos Nos Impares: " << arv5.contaImpar() << endl;
    cout << "Quantos Folhas Impares: " << arv5.contaFolhaImpar() << endl;

    return 0;
}
