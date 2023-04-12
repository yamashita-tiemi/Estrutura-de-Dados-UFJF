#include <iostream>
using namespace std;

void troca(int *a, int *b)
{
    int aux = *b;
    *b = *a;
    *a = aux;
}

int main()
{
    //    Ex. 2 - troca o conteudo de duas variaveis inteiras a e b
    int x,y;
    cin >> x;
    cin >> y;
    troca(&x, &y);
    cout << "x:" << x << " y:" <<y << endl;
    return 0;
}
