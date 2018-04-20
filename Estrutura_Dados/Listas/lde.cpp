#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#define tam 20

using namespace std;

template <typename T> class LDE;
template <typename T> 
class No{
private:
	T valor;
	No<T>* proxEnd;
public:
	T getValor(){
		return valor;
	}
	No(T elemento): valor(elemento), proxEnd(NULL){
	}
	~No(){
		cout<<endl<<valor <<" foi deletado\n";
	}
	friend class LDE<T>;
};
template <typename T> 
class LDE{
private:
	No<T>* primeiro;
public:
	LDE(){
		primeiro = NULL;
	}
	~LDE(){
		if(primeiro){
			No<T> *atual = primeiro;
			No<T> *anterior =NULL;
			while(atual != NULL){
				anterior = atual->proxEnd;
				delete atual;
				atual = anterior;
			}
		}
	}

	bool inserir(T elemento){
		No<T> *novo = new No<T>(elemento);
		if(!novo) //se novo == NULL
			return false;
		No<T> *atual = primeiro;
		No<T> *anterior = NULL;
		//lista: 1, 3,  6, 8, 10 ; Vou inserir 12
		while(atual && atual->valor < elemento){
			anterior = atual;
			atual = atual->proxEnd;
		}
		/*inicial
		se anterior == NULL, nem entro no while
		*/
		if(!anterior){
			primeiro = novo;
			primeiro->proxEnd = atual;
		}
		//se atual nao existir, cheguei no final da lista. inserir no final
		else if(atual == NULL){
			atual = novo;
			anterior->proxEnd = atual;
		}
		else{
			anterior->proxEnd = novo;
			novo->proxEnd = atual;
		}
		return true;
	}

	No<T> *buscar(T elemento){
		No<T> *atual = primeiro;
		while(atual && atual->valor < elemento)
			atual = atual->proxEnd;
		if(atual && atual->valor == elemento)
			return atual;
		cout<<"\nValor nao encontrado\n";
		return NULL;
	}
	
	bool remover(T elemento){
		No<T> *remover = buscar(elemento);
		if(!remover)
			return false;

		No<T> *atual =primeiro;
		No<T> *anterior = NULL;
		while(atual && atual->valor < elemento){
			anterior = atual;
			atual = atual->proxEnd;
		}
		//se for deletar o primeiro
		if(!anterior){
			atual = primeiro->proxEnd;
			delete primeiro;
			primeiro = atual;
		}//se for deletar o ultimo
		else if(!atual->proxEnd){
			anterior->proxEnd = NULL;
			delete atual;
		}
		else{
			anterior->proxEnd = atual->proxEnd;
			delete atual;
		}
		return true;
	}

	bool imprimir(){
		No<T>* atual = primeiro;
        if(!atual){
            cout<<"\nlista vazia\n";
            return false;
        }
        int i=0;
        while(atual){
            if(i% (tam/2) == 0)
                cout<<endl;
            cout<<atual->valor<<" ";
            atual = atual->proxEnd;
            i++;
        }
        cout<<endl;
        return true;
	}
};

void listaNumerica(){
	LDE<int> *lista = new LDE<int>();
	int v[tam];
	cout<<"\nvalores vetor: \n";
	for(int i=0;i<tam;i++){
		if(i% (tam/2) == 0)
			cout<<endl;
		v[i]= rand()% (tam*100)*1.3;
		cout<<v[i]<<" ";
	}
	cout<<"\n\nLista\n";
	for(int i=0;i<tam;i++)
		lista->inserir(v[i]);
	lista->imprimir();
	for(int i=0;i<tam;i+=3)
		lista->remover(v[i]);
    lista->imprimir();
	system("pause");
	system("cls");
	cout<<"Deletando lista\n";
	delete lista;
	system("pause");
	system("cls");
}

void listaString(){
	LDE<string> *lista = new LDE<string>();
	lista->buscar("fdjl");
	lista->remover("rdf");
	lista->inserir("Tiago");
	lista->inserir("Michelle");
	lista->inserir("Vader");
	lista->inserir("Fabio");
	lista->inserir("Andreia");
	lista->inserir("Renata");
	cout<<"\nImprimindo lista\n";
	lista->imprimir();
	lista->remover("Vader");
	lista->remover("Michelle");
	lista->remover("Andreia");
	lista->imprimir();
	
	system("pause");
	system("cls");
	
	cout<<"Deletando lista\n";
	delete lista;
	
	system("pause");
	system("cls");
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	listaNumerica();
	listaString();
	return 0;
}
