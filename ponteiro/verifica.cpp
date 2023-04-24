#include <iostream>
using namespace std;

int main()
{
    // Ponteiro e aritmetica de ponteiro. Faca esse exercicio com auxilio do computador e verifique o entendimento das operacoes
    // Sejam  i e j sao variaveis inteiras e  p e q ponteiros para inteiros
    // Quais das seguintes expressoes de atribuicao sao incorretas?
    
    int i = 2, j = 3;
    
    cout << "Conteudo de i: " << i << " -> Endereco de i: " << &i << endl;
    cout << "Conteudo de j: " << j << " -> Endereco de j: " << &j << endl;

    int *p;
    int *q;

    p = &i;
    cout << "p = &i;" << endl << "Conteudo de p: " << *p << " -> Endereco de p: " << p << endl;

    // *q=&j;
    // cout << "*q=&j;" << endl << "Conteudo de q: " << *q << " -> Endereco de q: " << q << endl;
    
    p=&*&i;
    cout << "p=&*&i;" << endl << "Conteudo de p: " << *(&*&i) << " -> Endereco de p: " << p << endl;

    // i=(*&)j;
    // cout << "i=(*&)j;" << endl << "Conteudo de i: " << *((*&)j) << " -> Endereco de i: " << &i << endl;

    i=*&*&j;
    cout << "i=*&*&j;" << endl << "Conteudo de i: " << *&*&j << " -> Endereco de i: " << &i << endl;

    // q=&p;
    // cout << "q=&p;" << endl << "Conteudo de q: " << *(*q) << " -> Endereco de q: " << q << endl;

    i=(*p)++ + *q;
    cout << "i=(*p)++ + *q;" << endl << "Conteudo de i: " << (*p)++ + *q << " -> Endereco de i: " << &i << endl;

    // if(p==i)i++;
    // cout << "if(p==i)i++;" << endl << "Conteudo de : " << *() << " -> Endereco de : " <<  << endl;
    
    return 0;
}
