#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int n;
	char *elementos;
	
}MS;

void criar(MS *a, int n);
void inicializar(MS	*a);
void imprimir(MS *a);
int converter_indices(int i, int j);
char consulta_elemento(MS *a, int i, int j);

main()
{
	int ordem,i,j;
	MS m;
	
	printf("Qual a ordem da matriz? ");
	scanf("%i", &ordem);
	
	criar(&m,ordem);
	inicializar(&m);
	imprimir(&m);
	
	printf("\n\nPara acessar um valor da matriz:\n- Valor da linha: ");
	scanf("%i", &i);
	printf("- Valor da coluna: ");
	scanf("%i", &j);
	if(i <= m.n && j <= m.n && i>0 && j>0)
		printf("\nMatriz[%i][%i]: %c\n", i, j, consulta_elemento(&m,i,j));
	else
		printf("\nO índice especificado está fora dos limites da matriz\n");
}

void criar(MS *a, int n)
{
	a->elementos = (char*)malloc(sizeof(char)*(n*(n+1))/2);
	if(!a->elementos)
	{
		printf("Não foi possível alocar a sua matriz\n");
		exit(0);
	}
	a->n = n;
}

void inicializar(MS	*a)
{
	int i,j;
	for(i=0;i<a->n;i++)
	{
		for(j=0;j<a->n;j++)
		{
			if(i>=j)
			{
				printf("Digite matriz[%i][%i]: ",i,j);
				scanf(" %c", &a->elementos[converter_indices(i,j)]);
			}
		}
	}
}

int converter_indices(int i, int j)
{
	return (i*(i+1)/2 + j + 1);
}

void imprimir(MS *a)
{
	int i,j;
	for(i=0;i<a->n;i++)
	{
		for(j=0;j<a->n;j++)
		{
			if(i>=j)
			{
				if((j+1) % a->n)
					printf("|%2c", a->elementos[converter_indices(i,j)]);
				else
					printf("|%2c|\n", a->elementos[converter_indices(i,j)]);
			}
			else
			{
				if((j+1) % a->n)
					printf("|%2c", a->elementos[converter_indices(j,i)]);
				else
					printf("|%2c|\n", a->elementos[converter_indices(j,i)]);
			}
		}
	}
}

char consulta_elemento(MS *a, int i, int j)
{
	if(i>=j)
		return a->elementos[(i*(i-1)/2) + j];
	else
		return a->elementos[(j*(j-1)/2) + i];
}
