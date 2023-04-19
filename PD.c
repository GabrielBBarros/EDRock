#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct noPD
{
    double valor;
    struct noPD *prox;
}NoPD;

typedef struct pd
{
    NoPD *topo;
    int tamanho;
}PD;

//Inicialização
void InicializarPD(PD *Pilha){
    Pilha->topo = NULL;
}

//Vazia
bool VaziaPD(PD*Pilha){
    if (Pilha->topo == NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

//Push
bool PushPD(PD *Pilha, double valor){
    NoPD *novo = (NoPD*)malloc(sizeof(NoPD));
    novo->valor = valor;
    if (Pilha->topo == NULL)
    {
        novo->prox=NULL;
    }
    else{
        novo->prox = Pilha->topo;
    }
    Pilha->topo = novo;
    Pilha->tamanho++;
    return true;
}

//Pop
bool PopPD(PD *Pilha){
    if (Pilha->topo == NULL)
    {
        printf("Pilha vazia\n");
        return false;
    }

    NoPD *aux = Pilha->topo;
    Pilha->topo = aux->prox;
    double valor = aux->valor;
    free(aux);
    Pilha->tamanho--;
    printf("Desempilhou: %lf", valor);
    return true;
}


//Impressão
void ImprimirPD(PD *Pilha){
    if (Pilha->topo == NULL)
    {
        printf("Pilha vazia \n");
    }
    NoPD *aux = Pilha->topo;
    printf("\nImprimindo:\n");
    while (aux != NULL)
    {
        printf("%lf \n", aux->valor);
        aux = aux->prox;
    }
    
    
}

//Busca valor
double BuscarValorPD(PD *Pilha, double valor) {
    int posicao = 0;
    NoPD *aux = Pilha->topo;
    while (aux != NULL) {
        if (aux->valor == valor) {
            printf("\nEncontrado: %lf\n", valor);
            return valor;
        }
        aux = aux->prox;
        posicao++;
    }
    return -1; 
}

//Buscar
int BuscarPD(PD *Pilha, double valor){
    NoPD *aux = Pilha->topo;
    int posicao = 0;
    while (aux != NULL) {
        if (aux->valor == valor) {
            printf("\nPosicao: %d\n", posicao);
            return posicao;
        }
        aux = aux->prox;
        posicao++;
    }
    printf("\nValor nao encontrado\n");
    return -1;
}


int main(int argc, char const *argv[])
{
    PD pilha;
    InicializarPD(&pilha);
    PushPD(&pilha, 89);
    PushPD(&pilha, 2);
    PushPD(&pilha, 3);
    PushPD(&pilha, 4);
    PushPD(&pilha, 5);
    PopPD(&pilha);
    BuscarValorPD(&pilha, 89);
    BuscarPD(&pilha, 89);
    ImprimirPD(&pilha);
}


