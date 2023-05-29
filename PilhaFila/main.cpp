#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"
#include "PilhaEncad.cpp"
#include "FilaEncad.cpp"

using namespace std;

int* inverte(int *vet, int n)
{
    int *vetNovo = new int [n];
    int x = n-1;
    for (int i = 0; i < n; i++)
    {
        vetNovo[i] = vet[x];
        x--;
    }
    return vetNovo;
}

void inverteFila(FilaEncad *f)
{
    PilhaEncad aux;
    while (!f->vazia())
    {
        aux.empilha(f->desenfileira());
    }
    while (!aux.vazia())
    {
        f->enfileira(aux.desempilha());
    }
}

FilaEncad* concatena(FilaEncad *f1, FilaEncad *f2)
{
    FilaEncad *f3 = new FilaEncad;
    while (!f1->vazia())
    {
        f3->enfileira(f1->desenfileira());
    }
    while (!f2->vazia())
    {
        f3->enfileira(f2->desenfileira());
    }
    return f3;
}

void removeDaPilha(PilhaEncad *p, int x)
{
    PilhaEncad aux;
    int *t;
    
    while (!p->vazia())
    {
        if (p->getTopo() == x)
        {
            p->desempilha();
        }
        else
        {
            aux.empilha(p->desempilha());
        }   
    }
    while (!aux.vazia())
    {
        p->empilha(aux.desempilha());
    }
}

int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;

    for(int i = 0; i < 5; i++) p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    p.imprime();

    for(int i = 20; i < 25; i++) p.empilha(i);
    cout << "Pilha apos inserir mais 5 valores" << endl;
    p.imprime();

    cout << "Tamanho: "<< p.tamanho() << endl;

    PilhaEncad p2;
    p2.imprime();
    cout << "Tamanho: " << p2.tamanho() << endl;

    /// TESTE COM FILA

    FilaEncad f;
    for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();

    for(int i = 20; i < 25; i++) f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    f.imprime();


    // TESTE VET INVERTE
    int x = 5;
    int vet[x];
    cout << "Cria vetor: " << endl;
    for (int i = 0; i < x; i++)
    {
        vet[i] = i;
        cout << vet[i] << " ";
    }
    cout << endl;

    int *vet2 = inverte(vet, x);
    cout << "Vetor invertido: " << endl;
    for (int i = 0; i < x; i++)
    {
        cout << vet2[i] << " ";
    }
    cout << endl;

    // TESTE INVERTE FILA
    f.imprime();
    inverteFila(&f);
    f.imprime();

    // TESTE CONCATENA FILA
    FilaEncad fila1;
    for(int i=0; i<5; i++) fila1.enfileira(i);
    cout << "Fila 1: " << endl;
    fila1.imprime();

    FilaEncad fila2;
    for(int i=10; i<15; i++) fila2.enfileira(i);
    cout << "Fila 2: " << endl;
    fila2.imprime();
    
    cout << "Fila 3: " << endl;
    concatena(&fila1, &fila2)->imprime();
    cout << "Fila 1 apos concatenacao: " << endl;
    fila1.imprime();
    cout << "Fila 2 apos concatenacao: " << endl;
    fila2.imprime();

    // TESTE REMOVE Y PILHA
    PilhaEncad pilha1;
    for(int i = 0; i < 5; i++) pilha1.empilha(i);
    for(int i = 0; i < 5; i++) pilha1.empilha(i);
    cout << "Pilha 1: " << endl;
    pilha1.imprime();

    int y = 2;
    removeDaPilha(&pilha1, y);
    cout << "Pilha 1 sem " << y << ": "<< endl;
    pilha1.imprime();

    return 0;
}
