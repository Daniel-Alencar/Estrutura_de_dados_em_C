#include<stdio.h>
#include<stdlib.h>
#define l 3
#define c 3
main()
{
	//Declaração de variável ponteiro para ponteiro
	int **p;
	
	int i,j;
	
	//alocando o vetor de ponteiros
	p = (int**)malloc(sizeof(int *) * l);
	
	//alocando uma das linhas da matriz
	for(i=0;i<l;i++)
		p[i] = (int*)malloc(sizeof(int) * c);
		
	//preenchendo a matriz com 0s
	for(i=0;i<l;i++)
		for(j=0;j<c;j++)
			p[i][j] = 0;
			
	//preenchendo com valores dados pelo usuário
	for(i=0;i<l;i++)
		for(j=0;j<c;j++)
			scanf("%i", &p[i][j]);
	printf("\n");
			
	//mostrando os elementos da maatriz
	for(i=0;i<l;i++)
	{
		for(j=0;j<c;j++)
		{
			if(j != c-1)
				printf("|%i", p[i][j]);
			else
				printf("|%i|\n", p[i][j]);
		}
	}
	
	//liberando espaço na memória
	//libera cada linha
	for(i=0;i<l;i++)
		free(p[i]);
		
	//libera o vetor de ponteiros
	free(p);
	return 0;
}
