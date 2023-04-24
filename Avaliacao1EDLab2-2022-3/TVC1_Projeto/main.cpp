#include <iostream>
#include "Avaliacao.h"
#include "MatrizEspecial.h"
#include "Avaliacao.cpp"
#include "MatrizEspecial.cpp"

/// NOME:
/// MATR�CULA:

using namespace std;

// ----------------------------------------------------------------------------
//Q1
int* vetorNegativos(int vet[], int n, int *t)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    *t = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            (*t)++;
        }
        
    }
    if (*t == 0)
    {
        return NULL;
    }
    else
    {
        int j = 0;
        int* v = new int [*t];
        for (int i = 0; i < n; i++)
        {
            if (vet[i] < 0)
            {
                v[j++] = vet[i];
            }
        }
        return v;   
    }
    
    
}
//-Q1
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q2
bool verificaIguais(int vet1[], int vet2[], int n)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    // for (int i = 0; i < n; i++)
    // {
    //     if (vet1[i] != vet2[i])
    //     {
    //         return false;
    //     }
        
    // }
    // return true;

    if (n == 0)
    {
        return true;
    }
    else if (vet1[n-1] != vet2[n-1])
    {
        return false;
    }
    else
    {
        return verificaIguais(vet1,vet2,n-1);
    }
}
//-Q2
// ----------------------------------------------------------------------------

int main()
{
    // TESTES PARA A QUESTAO 1 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 1" << endl;
    cout << "Resultado esperado: -5 -50 -12" << endl;
    cout << "Resultado obtido:   ";
    int v11[] = {12, 10, -5, 0, -50, 34, -12, 8, 42, 11}, t;
    int *r = vetorNegativos(v11, 10, &t);
    if(r)
        for(int i = 0; i < t; i++)
            cout << r[i] << " ";
    cout << endl;

    cout << "Resultado esperado: " << endl;
    cout << "Resultado obtido:   ";
    int v12[] = {2, 1, 25, 10, 19, 20, 23};
    r = vetorNegativos(v12, 7, &t);
    if(r)
        for(int i = 0; i < t; i++)
            cout << r[i] << " ";
    cout << endl;
    cout << endl << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 2 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 2" << endl;
    cout << "Resultado esperado: 1" << endl;
    cout << "Resultado obtido:   ";
    int v21[] = {12, 10, -5, 0, -50, 34, -12, 8, 42, 11};
    int v22[] = {12, 10, -5, 0, -50, 34, -12, 8, 42, 11};
    cout << verificaIguais(v21, v22, 10) << endl;

    cout << "Resultado esperado: 0" << endl;
    cout << "Resultado obtido:   ";
    int v23[] = {12, 10, -5, 1, -50, 34, -12, 8, 42, 11};
    int v24[] = {12, 10, -5, 0, -50, 34, -12, 8, 42, 11};
    cout << verificaIguais(v23, v24, 10) << endl;
    cout << endl << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 3 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 3" << endl;
    Avaliacao a(5);
    a.leNotas();
    a.relatorio();
    cout << endl << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 4 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 4" << endl;
    int dim = 5;
    MatrizEspecial mat5(dim);
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            mat5.set(i, j, 8);

    cout << "Matriz esperada:" << endl;
    cout << "Matriz 5 x 5:" << endl;
    cout << "8\t1\t2\t3\t4" << endl;
    cout << "1\t8\t1\t2\t3" << endl;
    cout << "2\t1\t8\t1\t2" << endl;
    cout << "3\t2\t1\t8\t1" << endl;
    cout << "4\t3\t2\t1\t8" << endl << endl;

    cout << "Matriz obtida:" << endl;
    mat5.imprime();

    dim = 6;
    MatrizEspecial mat6(dim);
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            mat6.set(i, j, (i+2)*(j+1));

    cout << "Matriz esperada:" << endl;
    cout << "Matriz 6 x 6:" << endl;
    cout << "2\t1\t2\t3\t4\t5" << endl;
    cout << "1\t6\t1\t2\t3\t4" << endl;
    cout << "2\t1\t12\t1\t2\t3" << endl;
    cout << "3\t2\t1\t20\t1\t2" << endl;
    cout << "4\t3\t2\t1\t30\t1" << endl;
    cout << "5\t4\t3\t2\t1\t42" << endl << endl;

    cout << "Matriz obtida:" << endl;
    mat6.imprime();
    // ------------------------------------------------------------------------

    return 0;
}
