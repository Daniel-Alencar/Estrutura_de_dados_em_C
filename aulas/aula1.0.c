#include<stdio.h>
typedef struct
{
	int num;
	int den;
	
}RACIONAL;

int equivalencia_racional(RACIONAL *a, RACIONAL *b)
{
	return (a->num * b->den) == (b->num * a->den);
}

void soma_racional(RACIONAL *a, RACIONAL *b, RACIONAL *c)
{
	c->num = b->den * a->num + a->den * b->num;
	c->den = b->den * a->den;
}
main()
{
	
}
