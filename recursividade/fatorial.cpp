#include <iostream>

using namespace std;

int fatorial(int n)
{
    // int f=1;
    // for(int i=n; i>0; i--)
    // {
    //     f = f*i;
    // }
    // return f;
    if (n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n * fatorial(n-1);
    }
}


int main()
{
    int x;
    cin >> x;
    cout << fatorial(x);

    return 0;
}