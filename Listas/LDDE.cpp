#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#define tam 15
using namespace std;

template<typename T> class LDDE;

template<typename T> class No{
private:
    T valor;
    No<T>* proxEnd;
    No<T>* endAnt;
public:
    No(T elemento){
        this->valor = elemento;
        this->proxEnd =nullptr;
        this->endAnt = nullptr;
    }
    ~No(){
        cout<<endl<<this->valor<<" foi deletado\n";
    }
    T getValor(){
        return this->valor;
    }

    friend class LDDE<T>;
};

template<typename T> class LDDE{
private:
    No<T>* primeiro;
    No<T>* ultimo;

public:
    LDDE():primeiro(nullptr), ultimo(nullptr){}
    ~LDDE(){
        No<T>* atual = primeiro;
        No<T>* backup = nullptr; //backup do proximo endereco;
        while(atual){
            backup = atual->proxEnd;
            delete atual;
            atual = backup;
        }
    }
    

    bool imprimir(){
        No<T>* atual = primeiro;
        if(!atual){
            cout<<"\nlista vazia\n";
            return false;
        }
        int i=0;
        while(atual){
            if(i%10 ==0)
                cout<<endl;
            cout<<atual->valor<<" ";
            atual = atual->proxEnd;
            i++;
        }
        cout<<endl;
        return true;
    }

    No<T> *buscar(T elemento){
        No<T> *atual = primeiro;
        if(!atual){
            cout<<"\nLista vazia\n";
            return nullptr;
        }
        while(atual && atual->valor < elemento)
            atual = atual->proxEnd;
        if(atual && atual->valor == elemento)
            return atual;
        cout<<"\nValor nao encontrado\n";
        return nullptr;
    }

    bool Remover(T elemento){
        No<T> *removido = buscar(elemento);
        if(!removido)
            return false;
        No<T> *proximo = removido->proxEnd;
        No<T> *anterior = removido->endAnt;
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

    bool Inserir(T elemento){
        No<T>* novo = new No<T>(elemento);
        if(!novo){
            cout<<"\nNao foi possivel alocar a memoria\n";
            return false;
        }
       No<T> *atual = primeiro;
       No<T> *anterior = nullptr;
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

void listaString(){
    LDDE<string> *lista = new LDDE<string>();
    No<string> *buscado = lista->buscar("43");
    lista->Inserir("Felipe");
    lista->Inserir("Tiago");
    lista->Inserir("Caio");
    lista->Inserir("Paulo");

    lista->Inserir("Andre");

	lista->imprimir();
  	buscado = lista->buscar("Felipe");
    if(buscado){
        cout<<"\n\nValor do buscado: "<<buscado->getValor();
    }
    buscado = lista->buscar("Geovani");

    lista->Remover("499");
    lista->Remover("Tiago");
    lista->Remover("Caio");
    lista->Remover("Andre");
    lista->imprimir();
    cout<<"\n\nInserindo de novo\n";
    lista->Inserir("Bruno");
    lista->Inserir("Marcos");
    lista->imprimir();
    system("Pause");
    system("cls");
    cout<<"Deletando lista\n";
    delete lista;
    cout<<"\nFinal LDDE String\n";
    system("Pause");
    system("cls");
    
}

void listaNumerica(){
    LDDE<float> *lista = new LDDE<float>();
    No<float> *buscado = lista->buscar(500);
    float v[tam];
    cout<<"Valores para popular a lista\n";
    for(int i=0;i<tam;i++){
        if(i%(tam/2) == 0)
            cout<<endl;
        v[i]= (rand()% (tam*20))*1.3;
        cout<<v[i]<<" ";
    }
    for(int i=0;i<tam;i++){
        lista->Inserir(v[i]);
    }

    cout<<endl<<"\nLista";
    lista->imprimir();

    buscado = lista->buscar(rand()% (tam*2)*1.3);
    if(buscado)
        cout<<"\n\nValor do buscado: "<<buscado->getValor();
   for(int i=0;i<tam;i+=3){
        lista->Remover(v[i]);
    }
    lista->Remover(rand()% (tam*2)*1.3);
    cout<<endl<<"\nLista";
    lista->imprimir();
    system("Pause");
    system("cls");
    cout<<"Deletando lista\n";
    delete lista;
    cout<<"\nFinal LDDE Numerica\n";
    system("Pause");
    system("cls");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(nullptr));
    listaString();
    listaNumerica();
    return a.exec();
}
