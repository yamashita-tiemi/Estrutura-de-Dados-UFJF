#include <iostream>
using namespace std;

float menor(int n, float vet[])
{
    // int m = vet[0];
    // for(int i=0; i<n; i++)
    // {
    //     if(vet[i]<m)
    //         m = vet[i];
    // }
    // return m;
    if(n==0)
    {
        return vet[0];
    }
    int m = menor(n-1,vet);
    if (vet[n] > m)
    {
        return m;
    }
    else
    {
        return vet[n];
    }    
}

int main()
{
    int x;
    cin >> x;
    float vet[x];
    for(int i=0; i<x; i++)
    {
        cin >> vet[i];
    }
    cout << menor(x-1, vet);
}
