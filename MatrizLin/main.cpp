#include <iostream>
#include "MatrizLin.h"
#include "MatrizLin.cpp"

using namespace std;

bool simetrica(MatrizLin* mat, int l, int c)
{
    if (l != c)
	{
        cout << "Matriz nao eh quadrada"<< endl;
        return false;
    }
    else
    {
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < c; j++)
            {
                // cout << mat->get(i,j) << " " << mat->get(j,i) << endl;
                if (mat->get(i,j) != mat->get(j,i))
                {
                    return false;
                }      
            }
        }
        return true;
    }
}

float* prodMatVetor(MatrizLin *m, float *v)
{
    float* vet = new float [m->getNl()];
    for (int i = 0; i < m->getNl(); i++)
    {
        float x = 0;
        for (int j = 0; j < m->getNc(); j++)
        {
            x += m->get(i,j) * v[j];
        }
        vet[i] = x;
    }
    return vet;
}


int main()
{
    int m = 7, n = 8;
    MatrizLin mat(m, n);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            float val = j + n*i; /// sequencia numerica no intervalo 0..(m*n-1)
            mat.set(i, j, val);
        }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            float val = mat.get(i, j);
            cout << val << "\t";
        }
        cout << endl;
    }

    mat.imprime(m,n);

    cout << "É simétrica? " << simetrica(&mat,m,n) << endl;

    cout << "Maior: "<< mat.maiorValor() << endl;


    cout << "Transposta :" << endl;
    MatrizLin* mTransposta = mat.transposta();
    mTransposta->imprime(n,m);


    float* x = new float [m];
        for (int i = 0; i < n; i++)
		{
			x[i] = -1;
		}
    cout << "Multiplica por v[";
        for (int i = 0; i < n; i++)
			{
                cout << x[i] << " ";
            }
    cout << "]" << endl;

    float* prod = prodMatVetor(&mat,x);

    cout << "vet[";
        for (int i = 0; i < n; i++)
			{
                cout << prod[i] << " ";
            }
    cout << "]" << endl;

    // -------------------------------------------

    int a=3;
    MatrizLin mat1(a, a);

    for (int i = 0; i < a; i++)
    {
        for(int j = 0; j < a; j++)
        {
            mat1.set(i,j,i);
            mat1.set(j,i,i);
        }
    }
    
    mat1.imprime(a,a);

    cout << "É simétrica? " << simetrica(&mat1,a,a) << endl;

    cout << "Maior: "<< mat1.maiorValor() << endl;


    cout << "Transposta :" << endl;
    MatrizLin* mT = mat1.transposta();
    mT->imprime(a,a);


    float* y = new float [a];
        for (int i = 0; i < a; i++)
		{
			cin >> y[i];
		}
    cout << "Multiplica por v[";
        for (int i = 0; i < a; i++)
			{
                cout << y[i] << " ";
            }
    cout << "] :" << endl;

    float* p = prodMatVetor(&mat1,y);

    cout << "vet[";
        for (int i = 0; i < a; i++)
			{
                cout << p[i] << " ";
            }
    cout << "]" << endl;

    return 0;
}
