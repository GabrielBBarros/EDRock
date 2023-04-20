#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct noDD
{
    double valor;
    struct noDD *prox;
    struct noDD *ant;
} NoDD;


typedef struct DD
{
    NoDD *frente;
    NoDD *atras;
    int tamanho;
} DD;


// Inicializar
void InicializarDD(DD *Deque){
    Deque->frente = NULL;
    Deque->atras = NULL;
    Deque->tamanho = 0;
}

// Vazio
void VazioDD(DD *Deque){
    if (Deque->frente == NULL)
    {
        printf("Deque vazio \n");
        return;
    }
}

// Inserir na frente
bool InserirFrenteDD(DD *Deque, double valor){
    NoDD *novo = (NoDD *)malloc(sizeof(NoDD));
    if (novo == NULL)
    {
        printf("Erro de alocação \n");
        return false;
    }
    novo->valor = valor;
    novo->prox = Deque->frente;
    novo->ant = NULL;

    if (Deque->frente == NULL)
    {
        Deque->atras = novo;
    }
    else{
        Deque->frente->ant = novo;
    }
    Deque->frente = novo;
    Deque->tamanho++;

    return true;
}

// Inserir atrás
bool InserirAtrasDD(DD *Deque, double valor){
    NoDD *novo = (NoDD *)malloc(sizeof(NoDD));
    if (novo == NULL)
    {
        printf("Erro de alocação \n");
        return false;
    }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = Deque->atras;

    if (Deque->frente == NULL)
    {
        Deque->frente = novo;
    }
    else{
        Deque->atras->prox = novo;
    }
    Deque->atras = novo;
    Deque->tamanho++;

    return true;
}


//Remover na frente
bool RemoverFrenteDD(DD *Deque, double* valor){
    if (Deque == NULL)
    {
        printf("Deque vazio, impossivel fazer a operacao \n");
        return false;
    }
    NoDD *aux = Deque->frente;
    *valor = aux->valor;
    Deque->frente = Deque->frente->prox;

    if (Deque->frente == NULL)
    {
        Deque->frente = NULL;
    }
    else{
        Deque->frente->ant = NULL;
    }

    free(aux);
    Deque->tamanho--;
    return true;
}

//Remover atras
bool RemoverAtrasDD(DD *Deque, double* valor){
    if (Deque == NULL)
    {
        printf("Deque vazio, impossivel fazer a operacao \n");
        return false;
    }
    NoDD *aux = Deque->atras;
    *valor = aux->valor;
    Deque->atras = aux->ant;

    if (Deque->frente == NULL)
    {
        Deque->atras = NULL;
    }
    else{
        Deque->atras->prox = NULL;
    }

    free(aux);
    Deque->tamanho--;
    return true;
}


//Imprimir
void ImprimirDD(DD *Deque){
    if (Deque == NULL)
    {
        printf("Deque vazio");
        return;
    }
    NoDD *aux = Deque->frente;
    printf("Imprimindo: \n");
    while (aux != NULL)
    {
        printf("%lf \n", aux->valor);
        aux = aux->prox;
    }
}

//Busca valor
bool BuscaValor(DD *Deque, double valor){
    if (Deque == NULL)
    {
        printf("Deque vazio \n");
        return false;
    }
    NoDD *aux = Deque->frente;
    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            printf("Encontrado: %lf \n", valor);
            return true;
        }
        aux = aux->prox;

    }
    printf("Valor nao encontrado \n");
    return false;
}

//Busca posição
bool BuscaPosicao(DD *Deque, double valor){
    if (Deque == NULL)
    {
        printf("Deque vazio \n");
        return false;
    }
    NoDD *aux = Deque->frente;
    int i = 0;
    while (aux != NULL){
        if (aux->valor == valor)
        {
            printf("Encontrado, posicao: %d \n", i);
            return true;
        }
        aux =aux->prox;
        i++;
    }

    printf("Valor nao encontrado \n");
    return false;
}







int main(int argc, char const *argv[])
{
    DD Deque;
    InicializarDD(&Deque);
    InserirFrenteDD(&Deque, 10);
    InserirFrenteDD(&Deque, 20);
    InserirAtrasDD(&Deque, 30);
    InserirAtrasDD(&Deque, 40);
    double valor = 10;
    RemoverAtrasDD(&Deque, &valor);
    //RemoverFrenteDD(&Deque, &valor);
    ImprimirDD(&Deque);
    BuscaValor(&Deque, 20);
    BuscaPosicao(&Deque, 30);
    return 0;
}

