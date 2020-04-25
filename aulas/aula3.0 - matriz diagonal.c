#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int n;
	int *elementos;
	
}MD;

void criar_matriz(MD *matriz, int a);
void inicializar(MD *a);
void imprimir(MD *matriz);
int consulta_elemento(MD *matriz, int a,int b);

main()
{
	int n;
	int i,j;
	MD m;
	
	printf("Qual a ordem da matriz? ");
	scanf("%i", &n);
	criar_matriz(&m, n);
	
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

void criar_matriz(MD *matriz, int n)
{
	int i,j;
	matriz->n = n;
	matriz->elementos = (int*)malloc(sizeof(int)*matriz->n);
	if(!matriz->elementos)
	{
		printf("Não é possível alocar a matriz\n");
		exit(0);
	}
}

void inicializar(MD *a)
{
	int i;
	for(i=0;i<a->n;i++)
		scanf("%i", &a->elementos[i]);
}

void imprimir(MD *matriz)
{
	int i,j;
	for(i=0;i<matriz->n;i++)
		for(j=0;j<matriz->n;j++)
		{
			if(i==j)
			{
				if((j+1)==matriz->n)
					printf("|%i|\n", matriz->elementos[i]);
				else
					printf("|%i", matriz->elementos[i]);
			}
			else
			{
				if((j+1) % matriz->n)
					printf("|%i", 0);
				else
					printf("|%i|\n", 0);
			}
		}
}

int consulta_elemento(MD *matriz, int i, int j)
{
	if(i==j)
		return matriz->elementos[i-1];
	else
		return 0;
}
