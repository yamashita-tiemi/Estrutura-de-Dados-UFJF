#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"
#include "ListaEncad.cpp"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleat�rio entre a e b
}

int main()
{
    ListaEncad l; /// cria lista vazia
    int NumNos = 12;

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

    cout << "Imprime: " << endl;
    l.imprime();

    cout << "Numeros de Nos: " << l.numNos() << endl;

    cout << "Busca maior que 20, na posicao: " << l.buscaMaior(20) << endl;

    cout << "Media: " << l.calculaMedia() << endl;

    ListaEncad l2;
    int NumNos2 = 5;
    cout << "Inserindo valores em l2: ";
    for(int i = 1; i <= NumNos2; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        l2.insereInicio(val);
    }
    cout << endl;

    cout << "Imprime l2: " << endl;
    l2.imprime();

    l.concatena(&l2);
    cout << "Imprime l1 + l2: " << endl;
    l.imprime();

    cout << "Segunda metade da lista: " << endl;
    l.partir((NumNos+NumNos2)/2)->imprime();


//  --------- Lista Ordenada ----------------
    ListaEncad l_ord;
    int num = 5;
    cout << "Inserindo valores em l_ord: ";
    for(int i = 1; i <= num; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        l_ord.insereOrdenado(val);
    }
    cout << endl;

    cout << "Imprime l_ord: " << endl;
    l_ord.imprime();
    
    

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    return 0;
};

