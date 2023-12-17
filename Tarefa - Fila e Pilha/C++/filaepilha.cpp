#include <iostream>
#include <vector>

using namespace std;

class lista{
    int *v, tam, tamMax;

    public:
    lista(){
        tam=0;
        tamMax=20;
        v=(int*)malloc(tamMax*sizeof(int));
    }

    ~lista(){
        delete[] v;
    }

    void aumentar(){
        int i;
        tamMax *= 2;
        int *aux = new int[tamMax];

        for(i=0; i<tam; i++){
            aux[i]=v[i];
        }

        delete[] v;

        v=aux;
    }

    void insere(int x) {
        if (tam == tamMax) {
            aumentar();
        }

        for (int i = tam; i > 0; i--) {
            v[i] = v[i - 1];
        }

        v[0] = x;
        tam++;
    }

    virtual void remove(){
        if(tam>0){
            tam--;

        }else {
            std::cout << "Lista Vazia" << std::endl;
        }
    }

    virtual int primeiro(){
        if(tam>0){
            return v[0];
        }
    }

    int tamanho(){
        return tam;
    }


};

class pilha : public lista{
    int *v, tam, tamMax;

    public:
    pilha(): lista(){
        tam=0;
        tamMax=20;
        v=(int*)malloc(tamMax*sizeof(int));
    }

    void push(int x){
        if(tam==tamMax){
            aumentar();
        }

        v[tam]= x;
        tam++;
    }

    void pop(){
        if(tam>0){
            tam--;

        }else {
            std::cout << "Lista Vazia" << std::endl;
        }
    }

    int primeiro(){
        if(tam>0){
            return v[tam-1];
        }
    }

};

class fila : public lista{
    int *v, tam, tamMax;

    public:
    fila() : lista(){
        tam=0;
        tamMax=20;
        v=(int*)malloc(tamMax*sizeof(int));
    }

    void remove(){
        if (tam>0){
            for(int i=0; i<tam; i++){
                v[i]=v[i+1];
            }
        }
        tam--;
    }

    int primeiro(){
        if(tam>0){
            return v[0];
        }
    }
};

