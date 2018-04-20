#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class PilhaLDE;

template <typename T>
class No{
private:
	T valor;
	No<T> *endAnt;
public:
	No(T _valor): valor(_valor), endAnt(NULL){
	}
	T getValor(){
		return valor;
	}
	friend class PilhaLDE<T>;
};


template<typename T>
class PilhaLDE{
private:
	No<T>* topo;
public:
	PilhaLDE(): topo(NULL){}
	~PilhaLDE(){
		No<T> *atual = topo;
		No<T> *backup = NULL;
		while(atual){
			backup = atual->endAnt;
			delete atual;
			atual = backup;
		}
	}

	bool empilhar(T valor){
		No<T> *novo = new No<T>(valor);
		if(!novo){
			cout<<"\nDeu ruim\n";
			return false;
		}
		novo->endAnt = topo;
		topo = novo;
		return true;
	}

	bool desempilhar(T &valor){
		if(!topo){
			cout<<"\nPilha vazia\n";
			return false;
		}
		No<T> *backup =topo->endAnt;
		valor = topo->getValor();
		delete topo;
		topo = backup;
		return true;
	}

	bool imprimir(){
		if(!topo)
			return false;
		No<T>* atual = topo;
		cout<<endl;
		while(atual){
			cout<<atual->getValor()<<endl;
			atual = atual->endAnt;
		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	PilhaLDE<int> pilha;
	for(int i=0; i<5;i++)
		pilha.empilhar(i);
	int valor;
//	pilha.imprimir();
	cout<<"\nDesempilhar\n";
	while(pilha.desempilhar(valor))
		cout<<valor<<endl;
	for(int i=10;i>0;i--)
	    pilha.empilhar(i);
//    pilha.imprimir();
	cout<<"\nDesempilhar de novo\n";
	while(pilha.desempilhar(valor))
		cout<<valor<<endl;
	system("Pause");
	return 0;
}
