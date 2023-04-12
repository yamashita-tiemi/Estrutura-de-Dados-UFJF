#include "Aluno.h"

Aluno::Aluno(string n, string m)
{
    cout << "Criando aluno" << endl;
    nome = n;
    matricula = m;
}

Aluno::~Aluno()
{
    cout << "Destruindo objeto aluno" << endl;
}

// ----------------------------------------------------------------------------
// Exercicio 1
// ----------------------------------------------------------------------------

void Aluno::leNotas()
{
    // Implemente sua solucao aqui
    for(int i=0; i<7; i++)
    {
        cout << "Nota " << i+1 << ":" << endl;
        cin >> notas[i];
    }
}

double Aluno::calculaMedia()
{
    // Implemente sua solucao aqui
    float media = 0;
    for(int i=0; i<7; i++)
    {
        media += notas[i];
    }
    return media/7;
}

// ----------------------------------------------------------------------------

void Aluno::setNome(string novo)
{
    nome = novo;
}

string Aluno::getNome()
{
    return nome;
}

// ----------------------------------------------------------------------------
// Exercicio 2
// ----------------------------------------------------------------------------

// Implemente aqui a sua solucao
void Aluno::setIdade(int novo)
{
    idade = novo;
}

int Aluno::getIdade()
{
    return idade;
}


// ----------------------------------------------------------------------------
// Exercicio 3
// ----------------------------------------------------------------------------

// Implemente aqui sua solucao
void Aluno::setMatricula(string novo)
{
    matricula = novo;
}

string Aluno::getMatricula()
{
    return matricula;
}

// Exercício 4
void Aluno::leFrequencia()
{
    for(int i=0; i<7; i++)
    {
        cout << "Frequencia " << i+1 << ":" << endl;
        cin >> frequencia[i];
    }
}


void Aluno::relatorio()
{
    cout << "Nome do aluno(a): " << getNome() << endl;
    cout << "Idade do aluno(a): " << getIdade() << endl;
    cout << "Matricula do aluno(a): " << getMatricula() << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Disciplina " << i+1 << ": ";
        if (frequencia[i] == 1)
        {
            cout << "Aprovado por frequencia - ";
            if (notas[i] >= 60)
            {
                cout << "Aprovado por nota" << endl;
            }
            else
            {
                cout << "Reprovado por nota" << endl;
            }
        }
        else
        {
            cout << "Reprovado por frequencia - ";
            if (notas[i] >= 60)
            {
                cout << "Aprovado por nota" << endl;
            }
            else
            {
                cout << "Reprovado por nota" << endl;
            }
        }

        // if (frequencia[i]==1 && notas[i]>=60)
        // {
        //     cout << "Aprovado(a)!" << endl;
        // }
        // else
        // {
        //     cout << "Reprovado(a)" << endl;
        // }
    } 
}
