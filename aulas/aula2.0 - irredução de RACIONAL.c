#include<stdio.h>
typedef struct
{
	int n;
	int d;
	
}RACIONAL;

void tornar_irredutivel(RACIONAL *p)
{
	int a, b, q, r;
	if(p->n > p->d)
	{
		a = p->n;
		b = p->d;	
	}
	else
	{
		b = p->n;
		a = p->d;	
	}
	while(b)
	{
		q = a/b;
		r = a%b;
		a=b;
		b=r;
	}
	p->n = p->n / a;
	p->d = p->d / a;	
}

main()
{
	RACIONAL a;
	scanf("%i %i",&a.n,&a.d);
	
	printf("\n%i/%i = ", a.n,a.d);
	tornar_irredutivel(&a);
	
	printf("%i/%i\n", a.n,a.d);
}
