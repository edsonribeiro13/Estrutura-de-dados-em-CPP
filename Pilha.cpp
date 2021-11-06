//Edson Ribeiro
//Essa pilha carrega algumas funções básicas
#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct pilha{
	int num;
	pilha *apontar;
};

void inserir ();
void remover();
void verificar();

pilha *topo = NULL;


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
		else if (op == '2' and topo != NULL){
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
	
	pilha *pilhanovo = new pilha;

	pilhanovo->num = valor;
    
	if (topo == NULL)
        pilhanovo->apontar = NULL;
	else
        pilhanovo->apontar = topo;
		
	topo = pilhanovo;
	
}

void remover()
{
	
	pilha *aux = topo;
	topo = topo->apontar;
	cout << "Valor liberado: " << aux->num << endl;
	delete aux;
	
}

void verificar ()
{
	
	if (topo == NULL)
		cout << "Sem nada na pilha" << endl;
	
}
