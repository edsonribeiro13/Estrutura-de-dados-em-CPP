//Edson Ribeiro
#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct fila{
	int num;
	fila *apontar;
};

void inserir ();
void remover();
void verificar();

fila *topo = NULL, *fim = NULL;

int main ()
{
	setlocale (LC_ALL, "portuguese");
	
	char op = '0';
	
	while (op != 'n'){
		cout << "1)Inserir, 2)Remover, 3)Verificar, n para sair: ";
		cin >> op;
		if (op == '1'){
			inserir();
		}
		else if (op == '2' and topo != NULL and fim != NULL){
			remover();
		}
		else if (op == '3'){
			verificar();
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
	
	fila *filanovo = new fila;

	filanovo->num = valor;
    
    filanovo->apontar = fim;
	
	if (topo == NULL and fim == NULL){
		topo = filanovo;
		fim = filanovo;
	}
	else
		fim = filanovo;
	
}

void remover()
{
	
	fila *aux = fim, *aux2 = NULL;
	while (aux != topo){
		aux2 = aux;
		aux = aux->apontar;
	}
	if (topo == fim)
		fim = NULL;
	aux = topo;
	topo = aux2;
	cout << "Valor liberado: " << aux->num << endl;
	delete aux;
	
}

void verificar ()
{
	
	if (topo == NULL and fim == NULL)
		cout << "Sem nada na fila" << endl;
	
}
