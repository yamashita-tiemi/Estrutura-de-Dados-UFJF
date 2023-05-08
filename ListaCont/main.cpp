#include <iostream>
#include "Ponto.h"
#include "ListaCont.h"
#include "ListaCont.cpp"
#include "ListaContPonto.h"
#include "ListaContPonto.cpp"


using namespace std;

int main()
{
    ListaCont l(10);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);

    l.imprime();
    cout << "Num de nos: " << l.numNos() << endl;

    int m = 20;
    cout << "Indice do maior q " << m << ": "<< l.buscaMaior(m) << endl;

    // l.limpar();
    // l.imprime();

    int tam = 3;
    int vet[] =  {10, 35, 18};
    l.insereValores(tam, vet);

    l.imprime();
    cout << "Num de nos: " << l.numNos() << endl;

    // -------- Funcao Inseere Metade --------------
    int a = 50;
    ListaCont l1(a);
    ListaCont l2(a/2);
    ListaCont l3(a/2);

    for (int i = 0; i < a; i++)
    {
        l1.insereFinal(i);
    }
    cout << "Lista 1: ";
    l1.imprime();

    for (int i = 0; i < (a/2)-1; i++)
    {
        l2.insereFinal(l1.get(i));
    }
    cout << "Lista 2: ";
    l2.imprime();

    for (int i = a/2; i < a; i++)
    {
        l3.insereFinal(l1.get(i));
    }
    cout << "Lista 3: ";
    l3.imprime();

    // --------- Lista com Pontos ---------------
    int b = 10;
    float x = 3,y = 5;
    
    ListaContPonto lp(b);

    for (int i = 0; i < b; i++)
    {
        Ponto p(rand()%10,rand()%20);
        lp.insereFinal(p);
    }

    // Ponto c(x*1,y*4);
    // Ponto d(x*2,y*3);
    // Ponto e(x*3,y*2);
    // Ponto f(x*4,y*1);

    // lp.insereFinal(c);
    // lp.insereFinal(d);
    // lp.insereFinal(e);
    // lp.insereFinal(f);

    lp.imprimeDist();
    
    return 0;
}
