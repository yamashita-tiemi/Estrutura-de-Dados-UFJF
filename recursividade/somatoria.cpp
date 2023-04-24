#include <iostream>

using namespace std;

int somatoria(int n)
{
    // int s=0;
    // for(int i = n; i>0; i--)
    // {
    //     s += i;
    // }
    // return s;
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + somatoria(n-1);
    }
    
    
}


int main()
{
    int x;
    cin >> x;

    cout << somatoria(x);

    return 0;
}