#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int nl; //número de linhas da matriz original
	int nc; //número de colunas da matriz original
	int *vetor; //vetor de guardar valores
	int **matriz; //guarda as posições dos valores do vetor
	int n; //número de valores significativos
	
}ME;

void criar(ME *a, int nl, int nc);
void atribuir(ME *a);
int consulta_elemento(ME *a, int b, int c);
void imprimir(ME *a);
int procurar_elemento(ME *a,int i,int j);

main()
{
	ME m;
	int nl,nc;
	int i,j;
	
	printf("Para criar a matriz:\n- Valor da linha: ");
	scanf("%i", &nl);
	printf("- Valor da coluna: ");
	scanf("%i", &nc);
	criar(&m,nl,nc);
	
	atribuir(&m);
	
	printf("\n\nAcessar um valor da matriz:\n- Valor da linha: ");
	scanf("%i", &i);
	printf("- Valor da coluna: ");
	scanf("%i", &j);
	if(i <= m.nl && j <= m.nc && i>0 && j>0)
		printf("\nMatriz[%i][%i]: %i\n", i, j, consulta_elemento(&m,i,j));
	else
		printf("\nO índice especificado está fora dos limites da matriz\n");
	
	printf("\n");
	imprimir(&m);
}

void criar(ME *a, int nl, int nc)
{
	int i;
	
	a->nl = nl;
	a->nc = nc;
	
	a->matriz = (int**)malloc(sizeof(int*)*2);
	if(!a->matriz)
	{
		printf("Não foi possível alocar a matriz\n");
		exit(0);
	}
	for(i=0;i<2;i++)
	{
		*(a->matriz + i) = (int *)malloc(sizeof(int)*nl*nc*3/10);
		if(!a->matriz[i])
		{
			printf("Não foi possível alocar a matriz\n");
			exit(0);
		}
	}
	
	a->vetor = (int*)malloc(sizeof(int)*nl*nc*3/10);
	if(!a->vetor)
	{
		printf("Não foi possível alocar a matriz\n");
		exit(0);
	}
}

void atribuir(ME *a)
{
	int i=0;
	char opcao;
	
	printf("Deseja adicionar um valor válido? [S/n]: ");
	scanf(" %c", &opcao);
	for(i=0;opcao == 'S' || opcao == 's';i++)
	{
		printf("\n\nDigite o valor: ");
		scanf("%i", (a->vetor + i));
		printf("Digite a coordenada x: ");
		scanf("%i", &a->matriz[0][i]);
		printf("Digite a coordenada y: ");
		scanf("%i", &a->matriz[1][i]);
		
		printf("Deseja continuar? [S/n]: ");
		scanf(" %c", &opcao);
	}
	a->n = i;
}

int consulta_elemento(ME *a, int b, int c)
{
	int i;
	for(i=0;i<a->n;i++)
	{
		if(a->matriz[0][i] == b && a->matriz[1][i] == c)
		{
			return a->vetor[i];
		}
	}
	return 0;
}

void imprimir(ME *a)
{
	int i,j, teste;
	for(i=0;i<a->nl;i++)
	{
		for(j=0;j<a->nc;j++)
		{
			teste = procurar_elemento(a,i+1,j+1);
			if(teste>=0)
			{
				if((j+1) % a->nc)
					printf("|%5i", a->vetor[teste]);
				else
					printf("|%5i|\n", a->vetor[teste]);
			}
			else
				if((j+1) % a->nc)
					printf("|%5i", 0);
				else
					printf("|%5i|\n", 0);
		}
	}
}

int procurar_elemento(ME *a,int b,int c)
{
	int i;
	for(i=0;i<a->n;i++)
	{
		if(a->matriz[0][i] == b && a->matriz[1][i] == c)
			return i;
	}
	return -1;
}
