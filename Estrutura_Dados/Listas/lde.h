#include <iostream>
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
		cout<<endl<<valor <<" foi deletado";
	}
	friend class LDE<T>;
};
template <typename T> 
class LDE{
private:
	No<T>* primeiro;
	int qtd;
public:
	LDE(){
		primeiro = NULL;
		qtd=0;
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
	bool primeiroExiste(){
		if(primeiro)
			return true;
		return false;
	}
	int getQuantidade(){return qtd;}
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
		qtd++;
		return true;
	}

	No<T> *buscar(T elemento){
		No<T> *atual = primeiro;
		while(atual && atual->valor < elemento)
			atual = atual->proxEnd;
		if(atual && atual->valor == elemento){
			return atual;
		}
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
		qtd--;
		return true;
	}
	bool imprimir(){
		No<T> *atual = primeiro;
		if(!atual)
			return false;
		int i=0;
		while(atual){
			if(i% 10 ==0)
				cout<<endl;
			cout<<atual->valor<<" ";
			atual = atual->proxEnd;
			i++;
		}
		return true;
	}
};
