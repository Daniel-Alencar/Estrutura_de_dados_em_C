#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int nl;
	int nc;
	int *ppe;
	
}MATRIZ;

main()
{
	MATRIZ m1,m2,m3;
	int a, b;
	
	scanf("%i %i", &a, &b);
	
	criar_matriz(a,b,&m1);
	inicializar_matriz(&m1);
	imprimir_matriz(&m1);
	
	scanf("%i %i", &a, &b);
	
	criar_matriz(a,b,&m2);
	inicializar_matriz(&m2);
	imprimir_matriz(&m2);
	printf("\n\n");
	
	if(!somar_matrizes(&m1,&m2,&m3))
	{
		printf("\nA soma das matrizes é igual a:\n");
		imprimir_matriz(&m3);
	}
	
	if(!subtrair_matrizes(&m1,&m2,&m3))
	{
		printf("\nA subtração das matrizes é igual a:\n");
		imprimir_matriz(&m3);
	}
	
	if(!multiplicar_matrizes(&m1,&m2,&m3))
	{
		printf("\nA multiplicação das matrizes é igual a:\n");
		imprimir_matriz(&m3);
	}
}
void criar_matriz(int nl, int nc, MATRIZ *p)
{
	p->nl = nl;
	p->nc = nc;
	
	p->ppe = (int*)malloc(sizeof(int)*p->nl*p->nc);
	if(!p->ppe)
	{
		printf("N�o foi poss�vel reservar mem�ria para a matriz\n");
		exit(0);
	}
}

void inicializar_matriz(MATRIZ *p)
{
	int i;
	for(i=0;i<(p->nl*p->nc);i++)
		scanf("%i", (p->ppe + i));
}

void imprimir_matriz(MATRIZ *p)
{
	int i;
	for(i=0;i<(p->nl * p->nc);i++)
	{
		if((i+1) % (p->nc))
			printf("|%5i", *(p->ppe + i));
		else
			printf("|%5i|\n", *(p->ppe + i));
	}
}

int somar_matrizes(MATRIZ *p1, MATRIZ *p2, MATRIZ *p3)
{
	int i;
	if((p1->nc == p2->nc) && (p1->nl == p2->nl))
	{
		p3->nl = p1->nl;
		p3->nc = p1->nc;
		criar_matriz(p3->nl, p3->nc, p3);
		
		for(i=0;i<(p1->nl * p1->nc);i++)
		{
			*(p3->ppe + i) = *(p1->ppe + i) + *(p2->ppe + i);
		}
		return 0;
	}
	else
	{
		printf("A soma entre estas matrizes n�o � poss�vel...\n");
		return 1;
	}
		
}
int subtrair_matrizes(MATRIZ *p1, MATRIZ *p2, MATRIZ *p3)
{
	int i;
	if((p1->nc == p2->nc) && (p1->nl == p2->nl))
	{
		p3->nl = p1->nl;
		p3->nc = p1->nc;
		criar_matriz(p3->nl, p3->nc, p3);
		
		for(i=0;i<(p1->nl * p1->nc);i++)
		{
			*(p3->ppe + i) = *(p1->ppe + i) - *(p2->ppe + i);
		}
		return 0;
	}
	else
	{
		printf("A subtra��o entre estas matrizes n�o � poss�vel...\n");
		return 1;
	}
		
}
int multiplicar_matrizes(MATRIZ *p1, MATRIZ *p2, MATRIZ *p3)
{
	int i,j;
	int k,l;
	
	if(p1->nc == p2->nl)
	{
		p3->nl = p1->nl;
		p3->nc = p2->nc;
		criar_matriz(p3->nl, p3->nc, p3);
		
		for(i=0;i<(p3->nl*p3->nc);i++)
			*(p3->ppe + i) = 0;
			
		i=0;
		for(l=0;l<(p1->nl);l++)
			for(k=0;k<(p2->nc);k++)
			{
				for(j=0;j<(p1->nc);j++)
				{
					*(p3->ppe + i) = *(p3->ppe + i) + (p1->ppe[j + (p1->nc*l)] * p2->ppe[(j * p2->nc) + k]);
				}
				i++;
			}
		return 0;
	}
	else
	{
		printf("A multiplica��o entre estas matrizes n�o � poss�vel...\n");
		return 1;
	}
}
