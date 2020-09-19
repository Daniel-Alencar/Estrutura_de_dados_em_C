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

void multiplicar_racionais(RACIONAL *racional1, RACIONAL *racional2, RACIONAL *racional3) {
	racional3->num = racional1->num * racional2->num;
	racional3->den = racional1->den * racional2->den;
}

void soma_de_racionais(RACIONAL *racional1, RACIONAL *racional2, RACIONAL *soma) {

	soma->num = (racional1->num * racional2->den) + (racional2->num * racional1->den);
	soma->den = racional1->den * racional2->den;
}

int equivalencia_de_racionais(RACIONAL *racional1, RACIONAL *racional2) {
	return (racional1->num * racional2->den) == (racional1->den * racional2->num);
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
	char opcao;
	RACIONAL r1, r2, r3;

	printf("Criando racional...\n");
	printf("Qual o numerador e denominador respectivamente?\n");
	scanf("%i %i", &n1, &n2);
	criar_racional(n1, n2, &r1);

	printf("Tornando irredutível...\n");
	tornar_irredutivel(&r1);
	printf("Resultado da operação: ");
	printf("%i/%i\n\n", r1.num, r1.den);

	printf("Qual o numerador e denominador respectivamente?\n");
	scanf("%i %i", &n1, &n2);
	criar_racional(n1, n2, &r2);

	printf("Tornando irredutível...\n");
	tornar_irredutivel(&r2);
	printf("Resultado da operação: ");
	printf("%i/%i\n\n", r2.num, r2.den);

	printf("Qual opção você quer? ");
	scanf(" %c", &opcao);

	switch (opcao)
	{
	case '+':
		soma_de_racionais(&r1, &r2, &r3);
		break;
	case '*':
		multiplicar_racionais(&r1, &r2, &r3);
		break;
	case '=':
		printf("%s\n", equivalencia_de_racionais(&r1, &r2)?"Os racionais são iguais":"Os racionais são diferentes");
		exit(0);

	default:
		printf("Você não digitou nenhum tipo de operação válida\n\n");
		exit(0);
	}
	printf("Resultado da operação: ");
	printf("%i/%i\n\n", r3.num, r3.den);
}