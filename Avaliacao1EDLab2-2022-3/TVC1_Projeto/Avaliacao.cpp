#include <iostream>
#include "Avaliacao.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q3
Avaliacao::Avaliacao(int n)
{
    // Implemente aqui sua solucao!
    questoes = n;
    notas = new float [questoes];
    valor = 100/questoes;
}

Avaliacao::~Avaliacao()
{
    // Implemente aqui sua solucao!
    delete [] notas;
}

void Avaliacao::leNotas()
{
    // Implemente aqui sua solucao!
    for (int i = 0; i < questoes; i++)
    {
        cin >> notas[i];
        while (notas[i] < 0 || notas[i] > valor)
        {
            cout << "Digite novamente" << endl;
            cin >> notas[i];
        }
    }
}

void Avaliacao::relatorio()
{
    // Implemente aqui sua solucao!
    float notaFinal = 0;
    for (int i = 0; i < questoes; i++)
    {
        notaFinal += notas[i];
        if (notas[i] < (0,6 * valor))
        {
            cout << "questao " << i << " abaixo de 60%" << endl;
        }
    }
    cout << "Nota final: " << notaFinal << endl;
}
//-Q3
// ----------------------------------------------------------------------------
