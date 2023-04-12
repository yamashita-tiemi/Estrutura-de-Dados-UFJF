#include <iostream>
using namespace std;

int main()
{
    //    Ex. 1
    int *pt;
    cout << "Endereco de pt: " << &pt << endl;
    int x;
    cin >> x;
    pt = &x;   //pt aponta para x
    cout << "Conteudo da variavel pt: " << *pt << endl;
    cout << "Endereco de x: " << pt << endl;
    //cout << "Endereco x: " << &x << endl;
    *pt = *pt*10;   //altera valor usando ponteiro
    cout << "Conteudo apontado por pt: " << *pt << endl;
    pt = pt+10;
    cout << "Conteudo apontado por pt apos somar 10: " << *pt << endl;
    return 0;
}
