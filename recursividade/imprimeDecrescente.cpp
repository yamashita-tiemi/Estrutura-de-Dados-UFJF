#include <iostream>

using namespace std;

void imprimeDecrescente(int n)
{
    // for(int i = n; i>=0; i--)
    // {
    //     cout << i << " ";
    // }
    if(n>=0)
    {
        cout << n << " ";
        imprimeDecrescente(n-1);
    }
}


int main()
{
    int x;
    cin >> x;
    imprimeDecrescente(x);

    return 0;
}