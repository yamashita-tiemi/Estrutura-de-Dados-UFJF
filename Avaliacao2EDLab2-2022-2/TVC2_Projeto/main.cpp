#include <iostream>
#include <cstdlib>
#include "ListaCont.h"
#include "ListaEncad.h"
#include "ListaDupla.h"
#include "FilaEncad.h"
#include "ListaCont.cpp"
#include "ListaEncad.cpp"
#include "ListaDupla.cpp"
#include "FilaEncad.cpp"

using namespace std;

// ----------------------------------------------------------------------------
//Q4
FilaEncad* intercala(FilaEncad *f1, FilaEncad *f2)
{
    // Remova o c�digo abaixo, se necess�rio.
    // return NULL;
    FilaEncad *f3 = new FilaEncad();

    while ((!f1->vazia()) || (!f2->vazia()))
    {
        if (!f1->vazia())
        {
            f3->enfileira(f1->desenfileira());
        }
        if (!f2->vazia())
        {
            f3->enfileira(f2->desenfileira());
        }
    }

    return f3;
}
//-Q4
// ----------------------------------------------------------------------------

int main()
{

    /// ************* TESTES QUEST�O 1 *************** ///
    cout << "==== TESTES QUESTAO 1 ====" << endl << endl;

    ListaCont lc(8), *lr = 0;

    ///insere 8 n�s na lista
    lc.insereFinal(18); lc.insereFinal(5);  lc.insereFinal(6);  lc.insereFinal(7);
    lc.insereFinal(2);  lc.insereFinal(11); lc.insereFinal(22); lc.insereFinal(1);

    cout<<"Lista cont com 8 nos :"<<endl;
    lc.imprime(); cout<<endl<<endl;

    lr = lc.moveParesInvertidos();

    cout<<"Nova lista cont com pares invertidos: :"<<endl;
    if(lr) lr->imprime(); cout<<endl<<endl;

    cout<<"Lista cont original apos operacao :"<<endl;
    lc.imprime();cout<<endl<<endl;

    cout << endl << endl;

    /// ************* TESTES QUEST�O 2 *************** ///
    cout << "==== TESTES QUESTAO 2 ====" << endl << endl;

    ListaEncad lEnc;
    lEnc.insereDepoisMenor(10);  ///tentar inserir o n� com valor -1 ap�s o menor

    lEnc.insereFinal(3); lEnc.insereFinal(2); lEnc.insereFinal(5);
    lEnc.insereFinal(12); lEnc.insereFinal(7); lEnc.insereFinal(9);

    cout<<"Lista para teste"<<endl;
    lEnc.imprime(); cout<<endl;

    cout<<"Lista apos insercao do valor 10 depois do menor"<<endl;
    lEnc.insereDepoisMenor(10);  ///insere o n� com valor 10 ap�s o menor
    lEnc.imprime(); cout<<endl;

    lEnc.insereFinal(1); ///insere o n� com valor 1 no final

    cout<<"Lista apos insercao do valor -9 depois do menor (que era 1)"<<endl;
    lEnc.insereDepoisMenor(-9);  ///insere o n� com valor -9 ap�s o menor
    lEnc.imprime(); cout<<endl;


    cout << endl << endl;

    /// ************* TESTES QUEST�O 3 *************** ///
    cout << "==== TESTES QUESTAO 3 ====" << endl << endl;

    ListaDupla l, lde;

    for(int i=5; i>=1; i--)
        l.insereInicio(i);

    cout<<"LDE l :"<<endl;
    l.imprime();cout<<endl;

    lde.insereInicio(15); lde.insereInicio(8); lde.insereInicio(3);
    cout<<"LDE lde:"<<endl;
    lde.imprime();cout<<endl;

    l.anexar(&lde);

    cout<<"LDE l apos anexacao de lde:"<<endl;
    l.imprime();cout<<endl;

    cout<<"LDE lde apos sua anexacao apos l:"<<endl;
    lde.imprime();cout<<endl;

    cout << endl << endl;

    cout << endl << endl;

    /// ************* TESTES QUEST�O 4 *************** ///
    cout << "==== TESTES QUESTAO 4 ====" << endl << endl;

    FilaEncad f1, f2;
    for(int i=1; i<=4; i++)
        f1.enfileira(i);

    for(int i=5; i<=10; i++)
        f2.enfileira(i);

    cout<<"Fila f1:"<<endl;
    f1.imprime();cout<<endl;
    cout<<"Fila f2:"<<endl;
    f2.imprime();cout<<endl;

    FilaEncad *f3 = 0;

    f3 = intercala(&f1, &f2);
    cout<<"Fila f1 e f2 intercaladas:"<<endl;
    if(lr) f3->imprime();cout<<endl;
    delete f3;
    f3 = 0;


    for(int i=1; i<=4; i++)
        f1.enfileira(i);

    for(int i=5; i<=10; i++)
        f2.enfileira(i);

    f3 = intercala(&f2, &f1);
    cout<<"Fila f2 e f1 intercaladas:"<<endl;
    if(lr) f3->imprime();cout<<endl;
    delete f3;

    cout << endl << endl;
    return 0;
}
