#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T> class Pilha{
private:
	int fim;
	T *v;
	int tam;
public:
	Pilha(int tamanho=5): fim(0), v(new T[tamanho]), tam(tamanho){

	}
	~Pilha(){
		delete []v;
	}
	
	bool empilhar(T valor){
		if(fim+1 == tam ){
			cout<<"\nPilha cheia\n";
			return false;
		}
		v[fim] = valor;
		fim++;
		return true;
	}
	bool desempilhar(T &valor){
		if(fim <0){
			cout<<"\nPilha vazia\n";
			return false;
		}
		valor = v[fim];
		fim--;
		return true;
	}

	void imprimir(){
		for(int i=0; i< fim; i++)
			cout<<endl<<v[i]<<endl;
	}
};

int main(int argc, char const *argv[])
{	Pilha<int> pilha(10);
	int v;
	for(int i=0;i<10;i++)
	    pilha.empilhar(i);
	cout<<"Desempilhar\n";
    while(pilha.desempilhar(v))
	    cout<<v<<endl;
	//preencher de novo
	for(int i=10;i>0;i--)
	    pilha.empilhar(i);
	cout<<"\nDesempilhar\n";
	while(pilha.desempilhar(v))
	    cout<<v<<endl;
	system("pause");
	return 0;
}
