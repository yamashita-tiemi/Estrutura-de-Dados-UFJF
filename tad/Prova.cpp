#include "Prova.h"

Prova::Prova(int nq)
{
    // implemente o construtor aqui
    cout << "Criando uma prova" << endl;
    n = nq;
    notasQuestoes =  new double[n];
}

// exercicio 7
// implemente aqui
Prova::~Prova()
{
    delete [] notasQuestoes;
    cout << "Destruindo objeto prova"<< endl;
}

void Prova::leNotas()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nota " << i+1 << ": ";
        cin >> notasQuestoes[i];
    }
}

void Prova::calculaNotaFinal()
{
    int menor = notasQuestoes[0];
    for (int i = 0; i < n; i++)
    {
        if (notasQuestoes[i] < menor)
        {
            menor = notasQuestoes[i];
        }
        notaFinal += notasQuestoes[i];        
    }
    notaFinal = notaFinal - menor;    
}

double Prova::obtemNotaFinal()
{
    return notaFinal;
}