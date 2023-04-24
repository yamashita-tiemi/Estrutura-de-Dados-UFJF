#include <iostream>

using namespace std;

// string* binario(int n)
// {
//     string* b = new string[n];
//     for (int i = n-1; i >= 0; i--)
//     {
//         if (n%2 == 0)
//         {
//             b[i] = "0";
//         }
//         else
//         {
//             b[i] = "1";
//         }
//         n = n/2;
//     }
//     return b;
// }

string binario(int n)
{
    if (n == 0)
    {
        return "0";
    }
    if (n == 1)
    {
        return "1";
    }
    if (n%2 == 0)
    {
        return binario(n/2) + "0";
    }
    else
    {
        return binario(n/2) + "1";
    }
}


int main()
{
    int x;
    cin >> x;

    // string* bin = binario(x);
    // for (int i = 0; i < x; i++)
    // {
    //     cout << bin[i];
    // }
    
    cout << binario(x);

    return 0;
}