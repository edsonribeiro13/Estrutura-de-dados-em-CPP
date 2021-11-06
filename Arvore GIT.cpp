//Edson Ribeiro
#include <iostream>
#include <clocale>

using namespace std;

struct arvore{
	string nome;
	arvore *filhoD;
	arvore *filhoE;
};

void inserir(string, string);

arvore *raiz = NULL;

int main ()
{
	setlocale (LC_ALL, "portuguese");
	
	string h = "0", m = "0";
	
	system ("pause");
	return 0;
	
}


void inserir (string H, string M)
{	

	arvore *arvorenovo = new arvore;
	arvore *arvorenovo2 = new arvore;
	arvore *aux = raiz;
	char op = '0';
	
	if(raiz == NULL){
		arvorenovo->nome = H;
		arvorenovo->filhoD = NULL;
		arvorenovo->filhoE = NULL;
		raiz = arvorenovo;
	}
	else{
		if (aux->filhoD == NULL and aux->filhoE == NULL){
			arvorenovo->nome = H;
			arvorenovo2->nome = M;
			aux->filhoD = arvorenovo;
			aux->filhoE = arvorenovo2;
			arvorenovo->filhoD = NULL;
			arvorenovo->filhoE = NULL;
			arvorenovo2->filhoD = NULL;
			arvorenovo2->filhoE = NULL;
		}
		else{
			while(op != 's'){
				cout << "Inserir do lado do pai ou da mãe?d(pai),e(mãe),s(sair e inserir): ";
				cin >> op;
				if (op == 'd' and aux->filhoD != NULL){
					aux = aux->filhoD;
				}
				else if (op == 'e' and aux->filhoE != NULL){
					aux = aux->filhoE;
				}
			}
			arvorenovo->nome = H;
			arvorenovo2->nome = M;
			aux->filhoD = arvorenovo;
			aux->filhoE = arvorenovo2;
			arvorenovo->filhoD = NULL;
			arvorenovo->filhoE = NULL;
			arvorenovo2->filhoD = NULL;
			arvorenovo2->filhoE = NULL;
		}
	}
	
} 
