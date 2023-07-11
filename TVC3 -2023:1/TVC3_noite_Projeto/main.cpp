#include <iostream>
#include "ArvBinBusca.h"
#include "ArvBinBusca.cpp"

using namespace std;

int main()
{
    ArvBinBusca arv;
    arv.insere(15); arv.insere(9);  arv.insere(20);
    arv.insere(7);  arv.insere(11); arv.insere(18);
    arv.insere(24); arv.insere(6);  arv.insere(8);
    arv.insere(10); arv.insere(12); arv.insere(17);
    arv.insere(-19); arv.imprime(); cout << endl;

    // -----------------------------------------------------------------------------

    cout << "TESTES PARA A QUESTAO 1\n------------------------------------------------" << endl;

    cout << "Valores esperados: 9  7  6  8  11  10  12  20  18  17  24"<<endl;
    cout << "Valores  obtidos : ";
    arv.imprimeNiveis(1);
    cout << endl<<endl;


    cout << "Valores esperados: 6  -19  8  10  12  17"<<endl;
    cout << "Valores  obtidos : ";
    arv.imprimeNiveis(3);
    cout << endl<<endl;

    cout << "Valores esperados: "<<endl;
    cout << "Valores  obtidos : ";
    arv.imprimeNiveis(6);
    cout << endl;


    cout << endl << endl;



    // -----------------------------------------------------------------------------

    cout << "TESTES PARA A QUESTAO 2\n------------------------------------------------" << endl;
    cout << "Valor esperado: 3,  " << "Valor obtido: " << arv.contaFolhas(10, 19) << endl;
    cout << "Valor esperado: 6,  " << "Valor obtido: " << arv.contaFolhas(-59, 25) << endl;
    cout << "Valor esperado: 0,  " << "Valor obtido: " << arv.contaFolhas(60, 90) << endl;
    cout << endl << endl;



    // -----------------------------------------------------------------------------

    cout << "TESTES PARA A QUESTAO 3\n------------------------------------------------" << endl;
    cout<<endl<< "Valor esperado:  0"<<endl;
    arv.buscaRemoveNivel(15);

    cout<<endl<< "Valor esperado:  2"<<endl;
    arv.buscaRemoveNivel(11);

    cout<<endl<< "Valor esperado:  Noh encontrado tem um unico filho"<<endl;
    arv.buscaRemoveNivel(18);

    cout<<endl<<"Valor esperado:  Noh nao encontrado"<<endl;
    arv.buscaRemoveNivel(14);

    cout<<endl<<"Valor esperado:  ABB sem a folha com valor 17"<<endl;
    arv.buscaRemoveNivel(17);
    arv.imprime(); cout << endl;

    cout << endl;

    // -----------------------------------------------------------------------------
    return 0;
}
