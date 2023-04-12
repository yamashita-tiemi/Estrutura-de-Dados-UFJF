#include <iostream>
using namespace std;

int main()
{
    //    Ex. 5 - calcular a media dos elementos do vetor
    int n;
    cin >> n;
    int *vet = new int[n];
    int soma=0;

    for(int i=0; i<n;i++)
    {
        cin >> vet[i];
        soma += vet[i];
    }
    cout << "Media:  " << soma/n;
    delete [] vet;
    return 0;
}
