//Edson Ribeiro
#include <iostream>
#include <clocale>

using namespace std;

struct arvore{
	int num;
	arvore *filhoD;
	arvore *filhoE;
};

void inserir();
void organizar();
void menu();
void remover();
void tamanho(int *, int *, arvore *, arvore *);

arvore *raiz = NULL;

int main ()
{
	setlocale (LC_ALL, "portuguese");
	
	char op = '0';
	
	arvore *aux = NULL, *aux2 = NULL;
	
	int ladoD = 0, ladoE = 0, *pontD = &ladoD, *pontE = &ladoE;
	
	while(op != '4'){
		menu();
		cin >> op;
		switch(op){
			case '1':
				inserir();
			case '2':
				remover();
			case '3':
				aux = raiz->filhoD;
				aux2 = raiz->filhoE;
				tamanho(pontD, pontE, aux, aux2);
				if ((ladoD - ladoE) > 1 or (ladoD - ladoE) < -1)
					cout << "\nÁrvore desequilibrada" << endl;
				else
					cout << "\nÁrvore equilibrada" << endl;
			case '4':
				break;
			default:
				cout << "\nOpção inválida";
		}
	}
	
	system ("pause");
	return 0;
	
}

void menu()
{
	
	cout << "1)Inserir\n2)Remover\n3)Verificar tamanho\n4)sair\n\t\topc: ";
	
}

void inserir ()
{	

	arvore *arvorenovo = new arvore;
	arvore *aux = raiz;
	int nume = 0;
	
	cout << "Insira o novo número: ";
	cin >> nume;
	
	if(raiz == NULL){
		arvorenovo->num = nume;
		arvorenovo->filhoD = NULL;
		arvorenovo->filhoE = NULL;
		raiz = arvorenovo;
	}
	else{
		while (5 > 4){
			if (nume >= aux->num){
				if (aux->filhoD == NULL){
					arvorenovo->num = nume;
					arvorenovo->filhoD = NULL;
					arvorenovo->filhoE = NULL;
					aux->filhoD = arvorenovo;
					break;
				}
				aux = aux->filhoD;
			}
			else{
				if (aux->filhoE == NULL){
					arvorenovo->num = nume;
					arvorenovo->filhoD = NULL;
					arvorenovo->filhoE = NULL;
					aux->filhoE = arvorenovo;
					break;
				}
				aux = aux->filhoE;
			}
		}
	}
	
	organizar();
	
}

void organizar()
{
	
	arvore *aux = NULL, *aux2 = NULL;
	
	int ladoD = 0, ladoE = 0, *pontD = &ladoD, *pontE = &ladoE;
	
	aux = raiz->filhoE->filhoD;
	aux2 = raiz->filhoE->filhoE;
	
	tamanho(pontD, pontE, aux, aux2);
	
	if ((ladoD - ladoE) > 1){
		while ((ladoD - ladoE) > 1){
			aux = raiz->filhoD;
			aux2 = aux->filhoD;
			raiz->filhoD = aux2;
			aux->filhoD = aux2->filhoE;
			aux2->filhoE = aux;
			ladoE++;
		}
	}
	else if ((ladoD - ladoE) < -1){
		while ((ladoD - ladoE) < -1){
			aux = raiz->filhoD;
			aux2 = aux->filhoE;
			raiz = aux2;
			aux->filhoE = aux2->filhoD;
			aux2->filhoD = aux;
			ladoD++;
		}
	}
	
	aux = raiz->filhoD->filhoD;
	aux2 = raiz->filhoD->filhoE;
	
	ladoD = 0;
	ladoE = 0;
	
	tamanho(pontD, pontE, aux, aux2);
	
	if ((ladoD - ladoE) > 1){
		while ((ladoD - ladoE) > 1){
			aux = raiz->filhoD;
			aux2 = aux->filhoD;
			raiz->filhoD = aux2;
			aux->filhoD = aux2->filhoE;
			aux2->filhoE = aux;
			ladoE++;
		}
	}
	else if ((ladoD - ladoE) < -1){
		while ((ladoD - ladoE) < -1){
			aux = raiz->filhoD;
			aux2 = aux->filhoE;
			raiz->filhoD = aux2;
			aux->filhoE = aux2->filhoD;
			aux2->filhoD = aux;
			ladoD++;
		}
	}
	
	aux = raiz->filhoD;
	aux2 = raiz->filhoE;
	
	ladoD = 0;
	ladoE = 0;
	
	tamanho(pontD, pontE, aux, aux2);
	
	if ((ladoD - ladoE) > 1){
		while ((ladoD - ladoE) > 1){
			aux = raiz;
			aux2 = aux->filhoD;
			raiz = aux2;
			aux->filhoD = aux2->filhoE;
			aux2->filhoE = aux;
			ladoE++;
		}
	}
	else if ((ladoD - ladoE) < -1){
		while ((ladoD - ladoE) < -1){
			aux = raiz;
			aux2 = aux->filhoE;
			raiz = aux2;
			aux->filhoE = aux2->filhoD;
			aux2->filhoD = aux;
		}
	}
	
}

void tamanho(int *PD, int *PE, arvore *A1, arvore *A2)
{
	
	while(A1 != NULL){
		*PD += 1;
		if (A1->filhoD == NULL and A1->filhoE != NULL)
			A1 = A1->filhoE;
		else
			A1 = A1->filhoD;
	}
	
	while(A2 != NULL){
		*PE += 1;
		if (A2->filhoE == NULL and A2->filhoD != NULL)
			A1 = A1->filhoE;
		else
			A1 = A1->filhoD;
	}
	
}

void remover()
{
	
	arvore *aux = raiz, *aux2 = raiz, *aux3 = NULL;
	int nume = 0;
	
	cout << "Insira o número a ser removido: ";
	cin >> nume;
	
	while (5 > 4){
		if (nume > aux2->num){
			aux = aux2;
			aux2 = aux->filhoD;
		}
		else if (nume < aux2->num){
			aux = aux2;
			aux2 = aux->filhoE;
		}
		else{
			if (aux2 == raiz){
				if (aux->filhoD != NULL){
					raiz = aux2->filhoD;
					if (raiz->filhoE == NULL){
						raiz->filhoE = aux2->filhoE;
					}
					else{
						aux3 = aux2->filhoE;
						while (5 > 4){
							if (aux3->num >= aux->num){
								if (aux->filhoD == NULL){
									aux->filhoD = aux3;
									break;
								}
								aux = aux->filhoD;
							}
							else{
								if (aux->filhoE == NULL){
									aux->filhoE = aux3;
									break;
								}
								aux = aux->filhoE;
							}
						}
					}
				}
				else if (aux->filhoE != NULL){
					raiz = aux2->filhoE;
					if (raiz->filhoD == NULL){
						raiz->filhoD = aux2->filhoD;
					}
					else{
						aux3 = aux2->filhoD;
						while (5 > 4){
							if (aux3->num >= aux->num){
								if (aux->filhoD == NULL){
									aux->filhoD = aux3;
									break;
								}
								aux = aux->filhoD;
							}
							else{
								if (aux->filhoE == NULL){
									aux->filhoE = aux3;
									break;
								}
								aux = aux->filhoE;
							}
						}
					}
				}
				else
					raiz = NULL;
			}
			else{
				if (aux->filhoD == aux2){
					aux->filhoD = aux2->filhoD;
					if (aux2->filhoE != NULL){
						aux3 = aux2->filhoE;
						while (5 > 4){
							if (aux3->num >= aux->num){
								if (aux->filhoD == NULL){
									aux->filhoD = aux3;
									break;
								}
								aux = aux->filhoD;
							}
							else{
								if (aux->filhoE == NULL){
									aux->filhoE = aux3;
									break;
								}
								aux = aux->filhoE;
							}
						}
					}
				}
				if (aux->filhoE == aux2){
					aux->filhoE = aux2->filhoE;
					if (aux2->filhoD != NULL){
						aux3 = aux2->filhoD;
						while (5 > 4){
							if (aux3->num >= aux->num){
								if (aux->filhoD == NULL){
									aux->filhoD = aux3;
									break;
								}
								aux = aux->filhoD;
							}
							else{
								if (aux->filhoE == NULL){
									aux->filhoE = aux3;
									break;
								}
								aux = aux->filhoE;
							}
						}
					}
				}
			}
		}
	}
	
	delete aux2;
	
	organizar();
	
}
