#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"
#include "ListaDupla.cpp"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1); /// retorna um numero inteiro aleat�rio entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;

    srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        l.insereInicio(i);
    }

    cout << "Lista: " << endl;
    l.imprime();

    l.insereFinal(10);
    l.insereFinal(2);
    cout << "Lista + insere final: " << endl;
    l.imprime();

    l.removeFinal();
    cout << "Lista + remove final: " << endl;
    l.imprime();

    cout << "Lista reversa: " << endl;
    l.imprimeReverso();
    cout << "Num Nos: " << l.numNos() <<endl;

    ListaDupla l2;
    for (int i = 0; i < 5; i++)
    {
        l2.insereInicio(i);
        l2.insereInicio(i);
    }
    cout << "Lista 2: " << endl;
    l2.imprime();
    
    // l.concatena(&l2);
    cout << "Lista concatenada: " << endl;
    l.concatena(&l2)->imprime();
    cout << "Num Nos: " << l.numNos() << endl;

    // cout << "Lista partida: " << endl;
    // l.partir(4)->imprime();
    // cout << "Num Nos partida: " << l.numNos() << endl;
    // l.imprime();

    l.removeOcorrencias(1);
    cout << "Lista sem ocorrencias: " << endl;
    l.imprime();


    bool existe = l.busca(20);
    cout << endl << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    return 0;
};

