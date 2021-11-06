//Edson Ribeiro
#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct lista{
	int num;
	lista *prox;
	lista *ant;
};

void inserir ();
int verificar();
void repete();
int remove1();
void removeTudo();

lista *topo = NULL, *fim = NULL;

int main ()
{
	setlocale (LC_ALL, "portuguese");
	
	char op = '0';
	
	while (op != 'n'){
		cout << "1)Inserir, 2)Verificar, 3)Verificar se repete, 4)Remover 1, 5)Remover tudo, n para sair: ";
		cin >> op;
		if (op == '1'){
			inserir();
		}
		else if (op == '2'){
			verificar();
		}
		else if (op == '3'){
			repete();
		}
		else if (op == '4' and fim != NULL){
			remove1();
		}
		else if (op == '5' and fim != NULL){
			removeTudo();
		}
	}
	
	system ("pause");
	return 0;
	
}


void inserir ()
{
	int valor = 0;
	
	cout << "Inserir Valor: ";
	cin >> valor;
	
	lista *listanovo = new lista;
	lista *aux = fim, *aux2 = NULL;
	
	listanovo->num = valor;
	
	if (topo == NULL and fim == NULL){
		listanovo->prox = topo;
		listanovo->ant = fim;
		topo = listanovo;
		fim = listanovo;
	}
	else{
		while (aux != NULL){
			if (aux->num >= listanovo->num){
				listanovo->prox = aux;
				listanovo->ant = aux->ant;
				aux2 = aux->ant;
				aux->ant = listanovo;
				if (aux == fim){
					fim = listanovo;
				}
				else{
					aux2->prox = listanovo;
				}
				break;
			}
			else if (aux == topo){
				listanovo->ant = aux;
				listanovo->prox = NULL;
				aux->prox = listanovo;
				topo = listanovo;
				break;
			}
			aux = aux->prox;
		}
	}
	
}

int verificar()
{
	
	lista *aux = fim;
	int ver = 0;
	
	cout << "Insira o número que deseja verificar: ";
	cin >> ver;
	
	while (aux != NULL){
		if (aux->num == ver){
			cout << "\nNúmero está na lista" << endl;
			return 0;
		}
		aux = aux->prox;
	}
	
	cout << "\nNúmero não está na lista" << endl;
	
}

void repete()
{
	
	lista *aux = fim;
	int ver = 0, soma = 0;
	
	cout << "Insira o número que deseja verificar: ";
	cin >> ver;
	
	while (aux != NULL){
		if (aux->num == ver){
			soma += 1;
		}
		aux = aux->prox;
	}
	
	cout << "\nNúmero aparece na lista " << soma << " vezes" << endl;
	
}

int remove1()
{
	
	lista *aux = fim, *aux2 = NULL;
	int rem = 0;
	
	cout << "Insira o número que deseja remover: ";
	cin >> rem;
	
	while (aux != NULL){
		if (aux->num == rem)
			break;
		aux = aux->prox;
	}
	
	if (aux == NULL){
		cout << "\nNúmero não está na lista" << endl;
		return 0;
	}
	
	if (aux == topo and aux == fim){
		topo = NULL;
		fim = NULL;
	}
	else if (aux == topo){
		topo = aux->ant;
		aux2 = aux->ant;
		aux2->prox = aux->prox;
	}
	else if (aux == fim){
		fim = aux->prox;
		aux2 = aux->prox;
		aux2->ant = aux->ant;
	}
	else{
	aux2 = aux->prox;
	aux2->ant = aux->ant;
	aux2 = aux->ant;
	aux2->prox = aux->prox;
	}
	
	cout << "Valor liberado: " << aux->num << endl;
	delete aux;
	
}

void removeTudo()
{
	
	lista *aux = fim, *aux2 = NULL;
	int rem = 0;
	
	cout << "Insira o número que deseja remover: ";
	cin >> rem;
	
	while (aux != NULL){
		if (aux->num == rem){
			if (aux == topo and aux == fim){
				topo = NULL;
				fim = NULL;
			}
			else if (aux == topo){
				topo = aux->ant;
				aux2 = aux->ant;
				aux2->prox = aux->prox;
			}
			else if (aux == fim){
				fim = aux->prox;
				aux2 = aux->prox;
				aux2->ant = aux->ant;
			}
			else{
				aux2 = aux->prox;
				aux2->ant = aux->ant;
				aux2 = aux->ant;
				aux2->prox = aux->prox;
			}
		}
		aux = aux->prox;
	}
	
	delete aux;
	
}
