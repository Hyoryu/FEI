//#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#define nullptr NULL
using namespace std;

class LDDE;

class No{
private:
    int valor;
    No* proxEnd;
    No* endAnt;
public:
    No(int elemento){
        this->valor = elemento;
        this->proxEnd =nullptr;
        this->endAnt = nullptr;
    }
    ~No(){
        cout<<endl<<this->valor<<" foi deletado\n";
    }
    int getValor(){
        return this->valor;
    }

    friend class LDDE;
};

class LDDE{
private:
    No* primeiro;
    No* ultimo;

public:
    LDDE():primeiro(nullptr), ultimo(nullptr){}
    ~LDDE(){
        No* atual = primeiro;
        No* backup = nullptr; //backup do proximo endereco;
        while(atual){
            backup = atual->proxEnd;
            delete atual;
            atual = backup;
        }
    }
    int getValor1(){
        return primeiro->valor;
    }
    int getValorL(){
        return ultimo->valor;
    }
    bool imprimir(){
        No* atual = primeiro;
        if(!atual){
            cout<<"lista vazia\n";
            return false;
        }
        int i=0;
        while(atual){
           /* if(i%10 ==0)
                cout<<endl;
            */cout<<atual->valor<<" ";
            atual = atual->proxEnd;
            i++;
        }
        cout<<endl;
        return true;
    }

    No *buscar(int elemento){
        No *atual = primeiro;
        while(atual && atual->valor < elemento)
            atual = atual->proxEnd;
        if(atual && atual->valor == elemento)
            return atual;
        cout<<"\nValor nao encontrado\n";
        return nullptr;
    }

    bool Remover(int elemento){
        No *removido = buscar(elemento);
        if(!removido)
            return false;
        No *proximo = removido->proxEnd;
        No *anterior = removido->endAnt;
        if(anterior)
            anterior->proxEnd = proximo;
        else
            primeiro =proximo;
        if(proximo)
            proximo->endAnt = anterior;
        else
            ultimo = anterior;
        delete removido;
        return true;
    }

    bool Inserir(int elemento){
        No* novo = new No(elemento);
        if(!novo)
            return false;
       No *atual = primeiro;
       No *anterior = nullptr;
       while(atual && atual->valor < elemento){
            anterior = atual;
            atual = atual->proxEnd;
       }
       if(anterior){
           anterior->proxEnd = novo;
       }
       else{
           primeiro = novo;
       }
       if(atual){
           atual->endAnt = novo;
       }
       else{
           ultimo = novo;
       }
       novo->endAnt = anterior;
       novo->proxEnd = atual;
       return true;
    }
};

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    LDDE *lista = new LDDE();
    int v[10];
    for(int i=0;i<10;i++){
        if(i%10 == 0)
            cout<<endl;
        v[i]= rand()%100;
        cout<<v[i]<<" ";
    }
    lista->imprimir();

    for(int i=0;i<10;i++){
        lista->Inserir(v[i]);
    }

    cout<<endl<<"\nLista\n";
    lista->imprimir();

    No *buscado = lista->buscar(100);
    if(buscado){
        cout<<"\n\nValor do buscado: "<<buscado->getValor()<<"\nEnd do buscado: "<<buscado;
    }
    for(int i=0;i<10;i+=2){
        lista->Remover(v[i]);
         lista->imprimir();
    }

    lista->Remover(0);
    lista->Inserir(1);
    lista->Inserir(34);
    lista->Inserir(100);
    lista->imprimir();

    delete lista;
    system("Pause");
    return 0;
//    return a.exec();
}
