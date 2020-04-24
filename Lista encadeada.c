#include<stdio.h>
#include<stdlib.h>

typedef struct REG
{
    int conteudo;
    struct REG *prox;
}CELULA;

void criar_LE(CELULA *cabeca);
int eh_vazia(CELULA *cabeca);
void inserir_LE(int num,int pos,CELULA *cabeca);
void imprimir_LE(CELULA *cabeca);
int tamanho_LE(CELULA *cabeca);
void retirar_LE(CELULA *cabeca,int pos);
int pentence_LE(CELULA *cabeca, int elem);
int eh_ordenada(CELULA *cabeca);
int retornar_elem_LE(CELULA *cabeca,int pos);
void gerar_LE(CELULA *cabeca,int m,int n);

int main()
{
    CELULA celula_cabeca;
    int i,num,pos;
    char opcao;


    criar_LE(&celula_cabeca);
    printf("O tamanho da lista encadeada é: %i\n",tamanho_LE(&celula_cabeca));

    printf("Deseja inserir algum valor? [S/n]: ");
    scanf(" %c",&opcao);
    for(i=0; opcao == 'S' || opcao == 's'; i++){
        printf("O conteúdo: ");
        scanf("%i",&num);
        printf("A posição: ");
        scanf("%i",&pos);
        inserir_LE(num,pos,&celula_cabeca);
        /*Parâmetros:
        Conteúdo;
        Posição;
        Endereço de memória da cabeça;
        */

        if(eh_ordenada(&celula_cabeca))
            printf("A lista encadeada É ORDENADA\n\n");
        else
            printf("A lista encadeada NÃO É ORDENADA\n\n");

        printf("Deseja continuar colocando valores? [S/n]: ");
        scanf(" %c",&opcao);
    }
    imprimir_LE(&celula_cabeca);

    printf("O tamanho da lista encadeada é: %i\n",tamanho_LE(&celula_cabeca));
    printf("\n\n");

    printf("Deseja retirar algum valor? [S/n]: ");
    scanf(" %c",&opcao);
    for(i=0; opcao == 'S' || opcao == 's'; i++){
        printf("A posição: ");
        scanf("%i",&pos);
        retirar_LE(&celula_cabeca,pos);
        /*Parâmetros:
        Endereço de memória da cabeça;
        posição;
        */
        imprimir_LE(&celula_cabeca);

        if(eh_ordenada(&celula_cabeca))
            printf("A lista encadeada É ORDENADA\n\n");
        else
            printf("A lista encadeada NÃO É ORDENADA\n\n");

        printf("Deseja continuar retirando valores? [S/n]: ");
        scanf(" %c",&opcao);
    }
    imprimir_LE(&celula_cabeca);
    printf("O tamanho da lista encadeada é: %i\n",tamanho_LE(&celula_cabeca));
    printf("\n\n");

    printf("Deseja verificar se algum valor pertence a lista? [S/n]: ");
    scanf(" %c",&opcao);
    for(i=0;opcao == 'S' || opcao == 's';i++)
    {
        printf("O conteúdo: ");
        scanf("%i",&num);
        if(pertence_LE(&celula_cabeca,num) == 1)
            printf("O elemento %i PERTENCE...\n\n",num);
        else
            printf("O elemento %i NÃO PERTENCE...\n\n",num);

        printf("Deseja verificar se algum valor pertence a lista? [S/n]: ");
        scanf(" %c",&opcao);
    }
    printf("\n\n");

    for(i=0;i<5;i++)
    {
        printf("Digite uma posição: ");
        scanf("%i",&pos);
        num = retornar_elem_LE(&celula_cabeca,pos);
        if(num != -1)
            printf("LISTA_ENCADEADA[ %i ]: %i\n\n\n", pos, num);
    }

    printf("GERAR LISTA...\nDE: ");
    scanf("%i",&num);
    printf("ATÉ: ");
    scanf("%i",&pos);
    gerar_LE(&celula_cabeca,num,pos);
}

void criar_LE(CELULA *cabeca) //Endereço de memória da cabeça;
{
    cabeca->prox = NULL;
    cabeca->conteudo = 0;
}
int eh_vazia(CELULA *cabeca) //Endereço de memória da cabeça;
{
    return (cabeca->prox==NULL);
}
void inserir_LE(int num,int pos,CELULA *cabeca)   //Endereço de memória da cabeça;
{
    CELULA *aux,*aux2;

    if(pos <= 0 || pos>(tamanho_LE(cabeca) + 1))
        printf("\nDesculpe, mas posição informada não é válida!\n\n");
    else
    {
        if(pos==1)
        {
            aux = cabeca->prox;
            cabeca->prox = (CELULA*)malloc(sizeof(CELULA));
            if(cabeca->prox==NULL)
            {
                printf("Não é possível alocar espaço...\n");
                return 0;
            }

            aux2 = cabeca->prox;
            aux2->prox = aux;
            aux2->conteudo = num;
        }
        else
        {
            int i;
            aux = cabeca;
            for(i=1;i<pos;i++)
            {
                aux = aux->prox;
            }
            aux2 = aux->prox;
            aux->prox = (CELULA*)malloc(sizeof(CELULA));
            if(aux->prox==NULL)
            {
                printf("Não é possível alocar espaço...\n");
                return 0;
            }
            aux = aux->prox;

            aux->conteudo = num;
            aux->prox = aux2;
        }
    }

}
void imprimir_LE(CELULA *cabeca) //Endereço de memória da cabeça;
{
    CELULA *aux = cabeca->prox;
    if(aux != NULL)
    {
       printf("%i", aux->conteudo);
       if(aux->prox!=NULL)
            printf(" -> ");

       imprimir_LE(aux);
    }
    else
    {
        printf("\n\n");
        return 0;
    }
}
int tamanho_LE(CELULA *cabeca)
{
    int cont;
    CELULA *aux=cabeca;

    for(cont=0;aux->prox!=NULL;cont++){
        aux=aux->prox;
    }
    return cont;
}
void retirar_LE(CELULA *cabeca,int pos)
{
    if(pos <= 0 || pos > tamanho_LE(cabeca))
    {
        printf("A posição é inválida para a retirada do elemento...\n\n");
        return 0;
    }
    CELULA *aux=cabeca,*aux2;
    int i;

    for(i=0;i!=(pos-1);i++){
        aux = aux->prox;
    }
    aux2 = aux->prox;
    aux->prox = aux2->prox;
}
int pertence_LE(CELULA *cabeca, int elem)
{
    int cont;
    CELULA *aux=cabeca->prox;

    for(cont=0; aux != NULL ;cont++){
        if(aux->conteudo == elem){
            return 1;
        }
        aux=aux->prox;
    }
    return 0;
}
int eh_ordenada(CELULA *cabeca)
{
    int teste;
    CELULA *aux=cabeca->prox;

    teste = aux->conteudo;
    aux = aux->prox;

    while(aux != NULL)
    {
        if(teste > aux->conteudo)
            return 0;
        teste = aux->conteudo;
        aux = aux->prox;
    }
    return 1;
}
int retornar_elem_LE(CELULA *cabeca,int pos)
{
    if(pos <= 0 || pos > tamanho_LE(cabeca))
    {
        printf("A posição é inválida para verificar o elemento...\n\n");
        return -1;
    }
    else
    {
        int i;
        CELULA *aux=cabeca;
        /*
        Bem, eu poderia também não ter criado estas variáveis e feito somente:

            - cabeca = cabeca->prox;     ao invés de:   aux = aux->prox;
            - for(;k>1;k--);             ao invés de:   for(i=0;i<pos;i++)

        ...porque dentro da função o valor de cabeca(por exemplo), pode ser alterado
        (com: cabeca = cabeca->prox por exemplo), porém o valor de cabeca não é alterado de fato com isso,
        no retorno para a main. Funciona como uma espéccie de "faz de conta que mudou..." dentro da função.
        */

        for(i=0;i<pos;i++){
            aux = aux->prox;
        }
        if(aux->conteudo == -1)
            printf("LISTA_ENCADEADA[ %i ]: %i\n\n\n", pos, -1);
        return aux->conteudo;
    }
}
void gerar_LE(CELULA *cabeca,int m,int n)
{
    criar_LE(cabeca);
    if(m>n){
        for(;m>=n;n++){
            inserir_LE(n,1,cabeca);
        }
    }
    else{
        for(;n>=m;n--){
            inserir_LE(n,1,cabeca);
        }
    }
    printf("LISTA ENCADEADA CRIADA...\n");
    imprimir_LE(cabeca);
}
