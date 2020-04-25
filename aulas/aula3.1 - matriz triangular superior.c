#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int n;
	int *elementos;
	
}MTS;

void criar(MTS *a, int n);
void inicializar(MTS *a);
int converter_indice(int i,int j);
void imprimir(MTS *a);
int consulta_elemento(MTS *a, int i, int j);

main()
{
	int n,i,j;
	MTS m;
	
	printf("Ordem da matriz: ");
	scanf("%i", &n);
	criar(&m,n);
	
	inicializar(&m);
	imprimir(&m);
	
	printf("\n\nPara acessar um valor da matriz:\n- Valor da linha: ");
	scanf("%i", &i);
	printf("- Valor da coluna: ");
	scanf("%i", &j);
	if(i <= m.n && j <= m.n && i>0 && j>0)
		printf("\nMatriz[%i][%i]: %i\n", i, j, consulta_elemento(&m,i,j));
	else
		printf("\nO índice especificado está fora dos limites da matriz\n");
}

void criar(MTS *a, int n)
{
	a->elementos = (int*)malloc(sizeof(int)*(n*(n+1))/2);
	if(!a->elementos)
	{
		printf("Não foi possível alocar esta matriz\n");
		exit(0);
	}
	a->n = n;
}

void inicializar(MTS *a)
{
	int i,j;
	for(j=0;j<a->n;j++)
	{
		for(i=0;i<a->n;i++)
		{
			if(j>=i)
			{
				printf("Matriz[%i][%i]: ",i+1,j+1);
				scanf("%i", &a->elementos[converter_indice(i,j)]);
			}
		}
	}
}

int converter_indice(int i,int j)
{
	return (j*(j+1)/2 + i);
}

void imprimir(MTS *a)
{
	int i,j;
	for(i=0;i<a->n;i++)
	{
		for(j=0;j<a->n;j++)
		{
			if(j>=i)
			{
				if((j+1) % a->n)
					printf("|%5i", a->elementos[converter_indice(i,j)]);
				else
					printf("|%5i|\n", a->elementos[converter_indice(i,j)]);
			}
			else
			{
				printf("|%5i", 0);
			}
		}
	}
}
int consulta_elemento(MTS *a, int i, int j)
{
	if(j>=i)
	{
		return a->elementos[converter_indice(i-1,j-1)];
	}
	else
		return 0;
}
