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

//Inserir no inicio
bool InseririnicioLDE(LDE *Lista, float valor){
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
        novo->prox = Lista->inicio;
        Lista->inicio = novo;
    }  
    Lista->tamanho++;
    return true;
}

//Inserir no final
bool InserirFinalLDE(LDE *Lista, float valor){
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


//Inserir ordenadamente
bool InserirOrdenadamenteLDE(LDE *Lista, float valor){
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
        Lista->tamanho++;
    }
    //Insere se o valor a ser inserido é menor que o primeiro
    if (valor < Lista->inicio->valor)
    {
        novo->prox = Lista->inicio;
        Lista->inicio = novo;
        Lista->tamanho++;
        return true;
    }
    //Apartir do segundo nó insere no lugar certo
    NoLDE *atual = Lista->inicio->prox;
    NoLDE *ant = Lista->inicio;
    while (atual != NULL && valor > atual->valor)
    {
        ant = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    ant->prox = novo;
    
    //Caso esse novo nó for o fim, atualiza ele
    if (atual == NULL)
    {
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

//Buscar valor
bool BuscarValorLDE(LDE *Lista, double valor){
    NoLDE *aux = Lista->inicio;
    while (aux!=NULL)
    {
        if (aux->valor == valor)
        {
            printf("Achado: %lf \n",valor);
            return true;
        }
        aux = aux->prox;
    }
    printf("Valor nao encontrado \n");
    return false;  
}

//Buscar posição
int BuscarPosicaoValorLDE(LDE *Lista, double valor){
    NoLDE *aux = Lista->inicio;
    int posicao = 1;

    while (aux !=NULL)
    {
        if (aux->valor == valor)
        {
            printf("Posicao: %lf \n",posicao);
             return posicao;
        }
        aux = aux->prox;
        posicao++;    
    }
    //Valor não achado
    printf("Valor não encontrado \n");
    return -1;
}

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
    InseririnicioLDE(&Lista, 8);
    InseririnicioLDE(&Lista, 78);
    InseririnicioLDE(&Lista, 12);
    InseririnicioLDE(&Lista, 30);
    RemoverLDE(&Lista, 30);
    ImprimirLDE(&Lista);


    return 0;
}
