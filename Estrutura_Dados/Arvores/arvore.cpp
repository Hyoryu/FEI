#include <cstdlib>
#include <iostream>
#define condicaoInserir valor<anterior->valor
#define condicaoBuscar buscar<atual->valor
//#define condicaoRemover remover<atual->valor
using namespace std;

template <typename T>
class No{
public:
	No* pai;
	No* esquerda; //valores menores
	No *direita; //valores maiores
	T valor;
	No(T _valor): pai(NULL), esquerda(NULL), direita(NULL), valor(_valor){}
	No(): pai(NULL), esquerda(NULL), direita(NULL){}
	~No(){
		cout<<"\nDeletando no "<<valor;
	}
};

template <typename T>
class Arvore{
private:
	int qtd;
public:

	No<T>* raiz;
	Arvore(): raiz(NULL), qtd(0){}
	~Arvore(){
		deletarArvore(raiz);
	}

	bool inserir(T valor){
		No<T>* novo = new No<T>(valor);
		if(!novo)
			return false;
		No<T>* atual = raiz;
		No<T>* anterior = NULL;
		while(atual){
			anterior=atual;
			if(condicaoInserir) //condicaoInserir valor < anterior->valor
				atual = atual->esquerda;
			else
				atual = atual->direita;
		}
		if(anterior){
			novo->pai = anterior;
			if(condicaoInserir)//condicaoInserir valor < anterior->valor
				anterior->esquerda = novo;
			else//valor > anterior->valor
				anterior->direita = novo;
		}else
			raiz = novo;
		qtd++;
		return true;
	}

	bool buscar(T buscar, No<T>* &achou){
		No<T>* atual = raiz;
		while(atual){
			if(atual->valor != buscar){
				if(condicaoBuscar) //condicaoBuscar buscar < atual->valor
					atual = atual->esquerda;
				else
					atual = atual->direita;
			}else{//caso atual->valor == buscar
				achou = atual;
				return true;
			}
		}
		cout<<"Value not found\n";
		return false;
	}

	void imprimir(No<T>* no){
		if(no){
			imprimir(no->esquerda);//comeco imprimindo o lado esquerdo da arvore, a raiz e, por fim, o lado direito
			cout<<no->valor<<endl;
			imprimir(no->direita);
		}
	}

	void deletarArvore(No<T>* no){
		if(no){
			deletarArvore(no->esquerda);
			deletarArvore(no->direita);
			delete no;
		}
	}
};



int main(int argc, char const *argv[]){
	{
		Arvore<int> arv;
		arv.inserir(10);//raiz
		//lado esquerdo
		arv.inserir(9);
		arv.inserir(5);
		arv.inserir(8);
		arv.inserir(3);
		//lado direito
		arv.inserir(30);
		arv.inserir(15);
		arv.inserir(35);
		//testando buscar
		No<int>* buscar = NULL;
		int qtd=10;
		int v[qtd];
		for(int i=0;i<qtd;i++)
		    v[i]= 5*i;
		for(int i=0;i<qtd;i++){
			if(arv.buscar(v[i], buscar))
		    	cout<<"Achou: "<<buscar->valor<<endl;
		}
		cout<<"\n\nImprimir\n\n";
		arv.imprimir(arv.raiz);
		cout<<"\n\nDeletando arv\n\n";
	}
	system("pause");
	return 0;
}
