#include <cstdlib>
#include <iostream>

using namespace std;
/***
	Lista Dinamica encadeada
	criado por: Hyoryu 14/03/18
	ultima edicao: Hyoryu 16/03/2018
	
	
***/

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
            if(i%10 ==0)
                cout<<endl;
            cout<<atual->valor<<" ";
            atual = atual->proxEnd;
            i++;
        }
        return true;
	}
};
int main(int argc, char const *argv[])
{
	LDE<int> lista;
	int v[20];
	for(int i=0;i<20;i++){
		if(i%10 == 0)
			cout<<endl;
		v[i]= rand()%100;
		cout<<v[i]<<" ";
	}
	cout<<"\n\n";
	for(int i=0;i<20;i++)
		lista.inserir(v[i]);
	lista.imprimir();
	for(int i=0;i<20;i++)
		lista.remover(v[i]);
    lista.imprimir();
	system("pause");
	return 0;
}
