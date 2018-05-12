#include <iostream>
#include <cstdlib>
#include "lde.h"
using namespace std;
/*
hash com método da divisão usando um vetor de lde para armazenar os dados
quando acontecer n colisões. N = tamanho do vetor de lde
*/
class Hash{
private:
int tam, qtd;
bool preenchido, colisao;
LDE<int> *v;
public:
	Hash(int size=10):tam(size), preenchido(false){
		v = new LDE<int>[tam];
	}
	~Hash(){
		delete []v;
	}
	int hash(int x){ return x % tam;}

	bool inserir(int valor){
		int index = hash(valor);
		if(v[index].getQuantidade() > tam-1)
			return false;
		qtd++;
		return v[index].inserir(valor);
	}
	bool remover(int valor){
		int index = hash(valor);
		if(!v[index].remover(valor))
			return false;
		qtd--;
		return true;
	}
	bool buscar(int valor){
		int index = hash(valor);
		No<int> *auxNo = v[index].buscar(valor);
		if(!auxNo){
			cout<<"\nValor nao encontrado\n";
			return false;
		}
		cout<<endl<<auxNo->getValor()<<" encontrado\n";
		return true;
	}

	void imprimir(){
		for(int i=0; i< tam;i++){
			if(v[i].primeiroExiste()){
				cout<<"\n\nLDE V["<<i<<"]\n";
			}
			v[i].imprimir();
		}
	}
};

int main(int argc, char const *argv[])
{
	{Hash h(20);
 	/*h.inserir(5);
	h.inserir(4);
	h.inserir(45);
	h.inserir(71);
	h.inserir(33);
	h.inserir(784);
	*/
	for(int i=0;i<800;i++)
	    h.inserir(i);
	h.remover(4);
	h.remover(20);
	h.remover(0);
	h.buscar(45);
	cout<<endl;
	h.imprimir();
	cout<<endl<<endl;
	system("pause");
	system("cls");
	}
	system("pause");
	return 0;
}
