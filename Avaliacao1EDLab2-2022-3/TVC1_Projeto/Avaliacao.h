#ifndef AVALIACAO_H_INCLUDED
#define AVALIACAO_H_INCLUDED

class Avaliacao
{
   private:
       int questoes;
       float valor;
       float *notas;

   public:
       Avaliacao(int n);
       ~Avaliacao();
       void leNotas();
       void relatorio();
};


#endif // AVALIACAO_H_INCLUDED
