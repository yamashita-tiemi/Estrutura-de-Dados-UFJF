#include <iostream>
using namespace std;

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

int main()
{
    //    Ex. 4
    int t = 4;
    int vet[t];
    int a=0, b=0, c=0;
   for(int i=0;i<t;i++)
   {
       cin >> vet[i];
   }
    cout << func(t, vet, &a, &b, &c);
    return 0;
}
