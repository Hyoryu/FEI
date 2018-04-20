#include <cstdlib>
#include <iostream>

#define condicao valor < anterior->valor

using namespace std;

template <typename T>
class No{
public:
	No* pai;
	No* esquerda; //valores menores
	No *direita; //valores maiores
	T valor;

	No(T _valor): pai(NULL), esquerda(NULL), direita(NULL), valor(_valor){}
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
			anterior =atual;
			if(condicao) //condicao
				atual = atual->esquerda;
			else
				atual = atual->direita;
		}
		if(anterior){
			novo->pai = anterior;
			if(condicao)//condicao
				anterior->esquerda = novo;
			else//valor > anterior->valor
				anterior->direita = novo;
		}else
			raiz = novo;
		qtd++;
		return true;
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
		//lado direito
		arv.inserir(20);
		arv.inserir(15);
		arv.inserir(30);

		arv.imprimir(arv.raiz);
		cout<<"\n\nDeletando\n\n";
	}
	system("pause");
	return 0;
}
