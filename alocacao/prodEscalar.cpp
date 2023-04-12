#include <iostream>
using namespace std;

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
    //    Ex. 6 - calcula o produto escalar entre dois vetores
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

    return 0;
}
