#include"./Aplicação para pilhas.c"

#define MAXIMUM_EXPRESSION 100

int main() {
    char expressaoInfixada[MAXIMUM_EXPRESSION];
    char expressaoPosFixada[MAXIMUM_EXPRESSION];
    scanf("%[^\n]", expressaoInfixada);
    
    convertInOrderExpressionWithParenthesesToPostFixed(expressaoInfixada, expressaoPosFixada);
    printf("%s = %s = %d%c", expressaoInfixada, expressaoPosFixada, postFixedExpression(expressaoPosFixada), '\n');
    return 0;
}
