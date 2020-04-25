#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 100

int i=0;

typedef struct
{
	int n;
	int val[MAX];
}LISTA;

void criar_lista(LISTA *a);
int eh_vazia(LISTA *a);
int tam_lista(LISTA *a);
void inserir(LISTA *a,int posicao,int elemento);
void retirar(LISTA *a,int posicao);
int retornar_elemento(LISTA *a, int posicao);
int pertence(LISTA *a,int elemento);
int eh_ordenado(LISTA *a);

main()
{
	setlocale(LC_ALL,"Portuguese");
	LISTA l;
	int posicao, elemento,i,m,n;
	criar_lista(&l);
	
	for(i=0;i<10;i++)
	{
		scanf("%i%i",&m,&n);
		gera_lista(&l,m,n);
		
		printf("A lista é vazia? R = %i\n", eh_vazia(&l));
		printf("O tamanho da lista: %i\n", tam_lista(&l));
		
		scanf("%i%i",&posicao,&elemento);
		inserir(&l,posicao,elemento);
		
		scanf("%i",&posicao);
		retirar(&l,posicao);
		
		scanf("%i",&posicao);
		printf("Elemento retornado: %i\n", retornar_elemento(&l,posicao));
		
		printf("Digite um valor para saber se ele pertence a lista: ");
		scanf("%i", &elemento);
		printf("O valor pertence a lista? R = %i\n\n", pertence(&l,elemento));
		
		if(eh_ordenado(&l))
			printf("A lista está ordenada\n\n\n");
		else
			printf("A lista não está ordenada\n\n\n");
	}
}

void criar_lista(LISTA *a)
{
	a->n=0;
}

int eh_vazia(LISTA *a)
{
	return (a->n == 0);
}

int tam_lista(LISTA *a)
{
	return a->n;
}

void inserir(LISTA *a,int posicao,int elemento)
{	
	int i;
	if(MAX != a->n)
	{
		if(posicao<=(a->n+1) && posicao>0)
		{
			posicao = posicao - 1;
			for(i=a->n; i>(posicao-1); i--)
			{
				a->val[i] = a->val[i-1];
			}
			a->val[posicao-1] = elemento;
			a->n++;
		}
		else
		{
			printf("A posição não faz parte da Lista...\n");
			exit(1);
		}
	}
	else
	{
		printf("ERROR\nA lista já está em sua capacidade máxima\n");
		exit(2);
	}
}

void retirar(LISTA *a,int posicao)
{
	int i;
	if(posicao <= a->n && posicao>0)
	{
		for(i=(posicao-1);i<=a->n;i++)
		{
			a->val[i] = a->val[i+1];
		}
		a->n--;
	}
	else
		printf("A posição não faz parte da Lista...\n");
}

int retornar_elemento(LISTA *a, int posicao)
{
	if(posicao<=a->n && posicao>0)
	{
		return a->val[posicao - 1];
	}
	else
	{
		printf("A posição não faz parte da Lista...\n");
		exit(1);
	}
}

int pertence(LISTA *a,int elemento)
{
	int i;
	for(i=0;i<a->n;i++)
	{
		if(a->val[i] == elemento)
			return 1;
	}
	return 0;
}

int eh_ordenado(LISTA *a)
{
	int i;
	for(i=0;i<(a->n - 1);i++)
	{
		if(a->val[i] >= a->val[i+1])
			return 0;
	}
	return 1;
}

void gera_lista(LISTA *a,int m,int n)
{
	if(m!=n){
		a->val[i] = m;
		i++;
		gera_lista(a, m+1, n);
	}
	else
	{
		a->val[i] = n;
		a->n = i+1;
		i=0;
	}
}
