#include <iostream>
using namespace std;

int contaPares(int n, int vet[])
{
    // int cont = 0;
    // for(int i=n; i>=0; i--)
    // {
    //     if(vet[i]%2 == 0)
    //     {
    //         cont++;
    //     }
    // }
    // return cont;

    if(n==0)
    {
            if (vet[0]%2==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (vet[n]%2==0)
    {
        return 1 + contaPares(n-1,vet);
    }
    else
    {
        return 0 + contaPares(n-1,vet);
    }
}

int main()
{
    int x;
    cin >> x;
    int vet[x];
    for(int i=0; i<x; i++)
    {
        cin >> vet[i];
    }
    cout << contaPares(x-1, vet);
    
    return 0;
}
