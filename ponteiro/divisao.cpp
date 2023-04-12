#include <iostream>
using namespace std;

void divisao(int num, int div, int *q, int *r)
{
    *q = num/div;
    *r = num%div;
}

int main()
{
    //    Ex. 3 - calcular e retornar o quociente e o resto da divisao inteira de num por div
    int x, y, q, r;
    cin >> x;
    cin >> y;
    divisao(x,y,&q,&r);
    cout << "Quociente: " << q << endl;
    cout << "Resto: " << r << endl;
    return 0;
}
