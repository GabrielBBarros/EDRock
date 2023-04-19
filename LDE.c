#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noLDE
{
    float valor;
    struct noLDE *prox;
}NoLDE;


typedef struct lde
{
    NoLDE *inicio;
    NoLDE *fim;
    int tamanho;
}LDE;


//Inicializar
void InicializarLDE(LDE *Lista){
    Lista->inicio = NULL;
    Lista->fim = NULL;
    Lista->tamanho = 0;
}

//Vazio
bool VaziaLDE(LDE *Lista){
    if (Lista->inicio == NULL)
    {
        printf("Esta vazia");
        return true;
    }
    else{
         printf("Contem elementos");
        return false;
    }
}

//Inserir
bool InserirLDE(LDE *Lista, float valor){
    NoLDE *novo = (NoLDE*)malloc(sizeof(NoLDE));
    if (novo == NULL)
    {
        printf("Erro");
        return false;
    }
    
    novo->valor = valor;
    novo->prox = NULL;

    //Se for o primeiro elemento a ser inserido
    if (Lista->inicio == NULL)
    {
        Lista->inicio = novo;
        Lista->fim = novo;
    }
    else{
        Lista->fim->prox = novo;
        Lista->fim = novo;
    }  
    Lista->tamanho++;
    return true;
}

//Remoção
bool RemoverLDE(LDE *Lista, float valor){
    NoLDE *aux = Lista->inicio;
    NoLDE *ant = NULL;
    if (Lista->inicio == NULL)
    {
        printf("Lista vazia, operação impossivel");
        return false;
    }
    
    while (aux != NULL && aux->valor != valor)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("Não encontrado");
        return true;
    }
    if (ant == NULL)
    {
        Lista->inicio = aux->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }
    free(aux);
    Lista->tamanho--;
    return true;
}


//Imprimir
//Imprimir
void ImprimirLDE(LDE *Lista){
    NoLDE *aux = Lista->inicio;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    printf("Imprimindo:\n");
    while (aux != NULL)
    {
        printf("%lf \n", aux->valor);
        aux = aux->prox;
    }
}


int main(int argc, char const *argv[])
{
    LDE Lista;
    InicializarLDE(&Lista);
    InserirLDE(&Lista, 8);
    InserirLDE(&Lista, 78);
    InserirLDE(&Lista, 12);
    InserirLDE(&Lista, 30);
    RemoverLDE(&Lista, 30);
    ImprimirLDE(&Lista);


    return 0;
}
