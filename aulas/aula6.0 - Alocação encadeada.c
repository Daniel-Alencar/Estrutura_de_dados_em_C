#include<stdio.h>
#define MAX 100

typedef struct
{
	float dado;
	int proximo;
}NO;

typedef struct
{
	int inicio;
	int nodo_livre;
	NO elementos[MAX];
}LE;

main()
{
	
}

void criar_lista(LE *a)
{
	int i;
	a->inicio = -1;
	a->nodo_livre = NULL;
	for(i=0;i<MAX-1;i++)
		a->elementos[i].proximo = i+1;
	a->elementos[i].proximo = -1;
}

int eh_vazia(LE *a)
{
	return (a->inicio == -1);
}

int tamanho_lista(LE *a)
{
	int cont=0, indice = a->inicio;
	while(indice!=-1)
	{
		cont++;
		indice = a->elementos[indice].proximo;
	}
	return cont;
}
void inserir_elemento(LE *a,int posicao,int elemento)
{
	if(posicao<1 || posicao > tamanho_lista(a) + 1){
		printf("Posição inválida\n");
		exit(1);
	}
	else{
		if(a->nodo_livre == -1){
			printf("Não espaço suficiente\n");
			exit(2);
		}
		else{
			int aux;
			if(posicao == 1){
				a->elementos[a->nodo_livre].dado = elemento;
				aux = a->elementos[a->nodo_livre].proximo;
				a->elementos[a->nodo_livre].proximo = a->inicio;
				a->inicio = a->nodo_livre;
				a->nodo_livre = aux;
			}
			else{
				int indice;
				for(indice = a->inicio; --posicao-1; indice = a->elementos[indice].proximo);
				
				a->elementos[a->nodo_livre].dado = elemento;
				aux = a->elementos[a->nodo_livre].proximo;
				
				a->elementos[a->nodo_livre].proximo = a->elementos[indice].proximo;
				
				a->elementos[indice].proximo = a->nodo_livre;
				a->nodo_livre = aux;
			}
		}
	}
}
