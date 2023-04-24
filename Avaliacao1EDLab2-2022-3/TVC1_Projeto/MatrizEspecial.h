#ifndef MATRIZESPECIAL_H_INCLUDED
#define MATRIZESPECIAL_H_INCLUDED

class MatrizEspecial
{
    public:
        MatrizEspecial(int nn);
        ~MatrizEspecial();
        int get(int i, int j);
        void set(int i, int j,  int val);
        void imprime();

    private:
        int n;
        int *vet;
        int detInd(int i, int j);
};

#endif // MATRIZESPECIAL_H_INCLUDED
