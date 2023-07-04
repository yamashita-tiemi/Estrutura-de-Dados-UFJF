#include <iostream>
#include "ArvBinBusca.h"
#include "ArvBinBusca.cpp"

using namespace std;


void preencheABB(ArvBinBusca *a, int p, int q)
{
    int meio = (p+q)/2;
    a->insere(meio);

    if (meio == p || meio == q)
    {
        return;
    }
    

    preencheABB(a, p, meio);
    preencheABB(a, meio, q);
}

int main()
{
    ArvBinBusca arv;

    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(16);
    arv.insere(9);
    arv.insere(20);
    arv.insere(7);
    arv.insere(11);
    arv.insere(18);
    arv.insere(24);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);
    arv.insere(12);
    arv.insere(17);
    arv.insere(19);
    arv.imprime();
    cout << endl;

    cout << "Media do caminho ate o no com valor 18: " << arv.mediaCaminho(18) << endl;
    cout << "Maior valor: " << arv.maior() << endl;
    cout << "Menor valor: " << arv.menor() << endl;
    cout << "Remove maior: " << endl;
    arv.removeMaior();
    // arv.imprime();
    cout << "Remove menor: " << endl;
    arv.removeMenor();
    // arv.imprime();
    int x = 12;
    cout << "Quantos pares até o valor " << x << " no Nó: " << arv.contaParesCaminho(x) << endl;


    cout << "Busca o valor 20: " << arv.busca(20) << endl;
    cout << "Busca o valor  5: " << arv.busca(5) << endl;
    cout << endl;

    cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    arv.remove(24);
    arv.remove(6);
    arv.remove(7);
    arv.remove(12);
    arv.remove(18);
    arv.remove(5);
    cout << endl;

    cout << "Arvore Binaria de Busca final:" << endl;
    arv.imprime();

    cout << "Maior valor: " << arv.maior() << endl;
    cout << "Menor valor: " << arv.menor() << endl;

    ArvBinBusca arvCompleta;
    preencheABB(&arvCompleta, 4, 10);
    arvCompleta.imprime();

    return 0;
}

