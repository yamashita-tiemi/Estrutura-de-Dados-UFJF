#include <iostream>
using namespace std;

float soma(int n, float vet[])
{
    // int s=0;
    // for(int i=0; i<n; i++)
    // {
    //     s+=vet[i];
    // }
    // return s;
    if (n==0)
    {
        return vet[0];
    }
    else
    {
        return vet[n] + soma(n-1,vet);
    }
}

int main()
{
    int x;
    cin >> x;
    // float vet[x];
    float *vet = new float[x];
    for(int i=0; i<x; i++)
    {
        cin >> vet[i];
    }
    cout << soma(x-1, vet);
    
    delete [] vet;

    return 0;
}
