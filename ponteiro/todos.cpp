#include <iostream>

using namespace std;

void troca(int *a, int *b)
{
    int aux = *b;
    *b = *a;
    *a = aux;
}

void divisao(int num, int div, int *q, int *r)
{
    *q = num/div;
    *r = num%div;
}

bool func(int tam, int vet[], int *par, int *impar, int *negativos)
{
    for(int i=0;i<tam;i++)
    {
        if(vet[i]%2 == 0)
        {
            (*par) += 1;
        }
        if(vet[i]%2 != 0)
        {
            *impar += 1;
        }
        if(vet[i] < 0)
        {
            *negativos += 1;
        }
    }

    cout << "Pares: " << *par << endl;
    cout << "Impar: " << *impar << endl;
    cout << "Negativos: " << *negativos << endl;

    if(*negativos == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

float prodEscalar(int n, float x[], float y[])
{
    float prod=0;
    for(int i=0;i<n;i++)
    {
        prod += (x[i]*y[i]);
    }
    return prod;
}

int main()
{
    int n;
    cout << "tamanho: " << endl;
    cin >> n;
    float *vet1 = new float[n];
    float *vet2 = new float[n];

    cout << "vetor 1: " << endl;
    for(int i=0; i<n;i++)
    {
        cin >> vet1[i];
    }
    cout << "vetor 2: " << endl;
    for(int i=0; i<n;i++)
    {
        cin >> vet2[i];
    }

    cout << "Produto escalar: " << prodEscalar(n, vet1, vet2);

    delete [] vet1;
    delete [] vet2;

//    Ex. 5
//    int n;
//    cin >> n;
//    int *vet = new int[n];
//    int soma=0;
//
//    for(int i=0; i<n;i++)
//    {
//        cin >> vet[i];
//        soma += vet[i];
//    }
//    cout << "Media:  " << soma/n;
//    delete [] vet;

//    int x,y;
//    int q,r;
//    int t, a=0, b=0, c=0;
//
//    t = 4;
//
//    int vet[t];
//    int *pt;

//    cin >> x;
//    cin >> y;
//    for(int i=0;i<t;i++)
//    {
//        cin >> vet[i];
//    }

//    Ex. 4
//    cout << func(t, vet, &a, &b, &c);

//    Ex. 3
//    divisao(x,y,&q,&r);
//    cout << "Quociente: " << q << endl;
//    cout << "Resto: " << r << endl;

//    Ex. 2
//    troca(&x, &y);
//    cout << "x:" << x << " y:" <<y << endl;

//    Ex. 1
//    cout << "Endereco pt: " << &pt << endl;
//    cin >> x;
//    pt = &x;
//    cout << "Conteudo x: " << *pt << endl;
//    cout << "Endereco x: " << pt << endl;
//    cout << "Endereco x: " << &x << endl;
//    *pt = *pt*10;
//    cout << "Conteudo apontado: " << *pt << endl;
//    pt = pt+10;
//    cout << "Conteudo apontado: " << *pt << endl;
}