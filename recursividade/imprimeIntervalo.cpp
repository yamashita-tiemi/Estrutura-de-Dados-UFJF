#include <iostream>

using namespace std;

void imprimeIntervalo(int a, int b, int inc)
{
    // for(int i = a; i<=b; i=i+inc)
    // {
    //     cout << i << " ";
    // }
    if(a<=b)
    {
        cout << a << " ";
        imprimeIntervalo(a+inc,b,inc);
    }
}


int main()
{
    int x, y, z;
    cin >> x;
    cin >> y;
    cin >> z;
    imprimeIntervalo(x,y,z);

    return 0;
}