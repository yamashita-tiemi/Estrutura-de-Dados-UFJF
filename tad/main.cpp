#include <iostream>
#include "Aluno.h"
#include "Prova.h"
#include "Aluno.cpp"
#include "Prova.cpp"

using namespace std;

int main()
{
    cout << "LABORATORIO DE PROGRAMACAO II - AULA 04\n" << endl;

    // ------------------------------------------------------------------------
    // EXERCICIO 1
    // ------------------------------------------------------------------------
    Aluno a("Carlos", "201566123AB");

    // leitura das notas do aluno
    a.leNotas();
    double m = a.calculaMedia();

    cout << "Media do aluno(a): " << m << endl;

    // ------------------------------------------------------------------------
    // EXERCICIO 3
    // ------------------------------------------------------------------------

    // Implemente aqui
    int age=0;
    cout << "Idade de " << a.getNome() << ": " << endl;
    cin >> age;
    a.setIdade(age);

    cout << "Nome do aluno(a): "<< a.getNome() << endl;
    cout << "Idade do aluno(a): "<< a.getIdade() << endl;
    cout << "Matricula do aluno(a): "<< a.getMatricula() << endl;


    // ------------------------------------------------------------------------
    // EXERCICIO 5
    // ------------------------------------------------------------------------

    // Implemente aqui
    a.leFrequencia();


    // ------------------------------------------------------------------------
    // EXERCICIO 6
    // ------------------------------------------------------------------------

    // Implemente aqui
    a.relatorio();

    // ------------------------------------------------------------------------
    // EXERCICIO 7
    // ------------------------------------------------------------------------

    Prova p(3);

    p.leNotas();
    p.calculaNotaFinal();

    cout << "Nota final: " << p.obtemNotaFinal() << endl;

    return 0;
}
