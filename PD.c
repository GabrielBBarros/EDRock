#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef union valor
{
    int INT;
    float FLOAT;
    char CHAR;
}Valor;

typedef struct noPD
{
    Valor valor;
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
bool PushPD(PD *Pilha, Valor valor){
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
bool PopPD(PD *Pilha, Valor *valor){
    if (Pilha->topo==NULL)
    {
        return false;
    }
    NoPD *aux = Pilha->topo;
    *valor = aux->valor;
    Pilha->topo = aux->prox;
    free(aux);
    Pilha->tamanho--;
    return true;  
}

//Impressão
void ImprimirPD(PD *Pilha){
    if (Pilha->topo == NULL)
    {
        printf("Pilha vazia");
    }
    NoPD *aux = Pilha->topo;
    while (aux !=NULL)
    {
        if (aux->valor.INT) {
            printf("%d ", aux->valor.INT);
        }
        else if (aux->valor.FLOAT) {
            printf("%f ", aux->valor.FLOAT);
        } 
        else {
            printf("%c ", aux->valor.CHAR);
        }
        aux = aux->prox;

    } 
}

//Busca
int Buscar(PD *Pilha, Valor valor) {
    int posicao = 0;
    NoPD *aux = Pilha->topo;
    while (aux != NULL) {
        if (aux->valor.INT == valor.INT || aux->valor.FLOAT == valor.FLOAT || aux->valor.CHAR == valor.CHAR) {
            return true;
        }
        aux = aux->prox;
        posicao++;
    }
    return false; // elemento não encontrado
}



//Tamanho
int TamanhoPD(PD *Pilha){
    return Pilha->tamanho;
}

