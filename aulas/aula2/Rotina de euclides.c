#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int num;
	int den;
	
}RACIONAL;

void criar_racional(int numerador, int denominador, RACIONAL *racional) {
	racional->num = numerador;
	racional->den = denominador;
}

void tornar_irredutivel(RACIONAL *r) {
	int a, b;
	int quociente;
	int resto;
	
	if (r->num > r->den) {
		a = r->num;
		b = r->den;
	} else {
		a = r->den;
		b = r->num;
	}

	while (b != 0) {
		resto = a % b;

		a = b;
		b = resto;
	}
	r->num = r->num / a;
	r->den = r->den / a;
}
int main() {
    int n1, n2;
    RACIONAL racional;

    scanf("%i", &n1);
    scanf("%i", &n2);

    criar_racional(n1, n2, &racional);

    printf("Tornando irredutível...\n");
    tornar_irredutivel(&racional);
    printf("Resultado da operação: ");
		printf("%i/%i\n\n", racional.num, racional.den);
}