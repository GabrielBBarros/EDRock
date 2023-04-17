#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef union valor
{
    int INT;
    float FLOAT;
    char CHAR;
}Valor;

typedef struct fe
{
    Valor vFila[MAX];
    int inicio;
    int fim;
    int tamanho;
}FE;

void InicioalizarFE(FE *Fila){
    Fila->inicio = -1;
    Fila->fim = -1;
}

bool VaziaFE(FE *Fila){
    if (Fila->tamanho == 0)
    {
        //Fila vazia
        return true;
    }
    else{
        return false;
    }  
}

bool CheiaFE(FE *Fila){
    if (Fila->fim == MAX)
    {
        //Fila vazia
        return true;
    }
    else{
        return false;
    }  
}

bool InserirFE(FE *Fila, Valor valor){
    if (Fila->fim == MAX) {
        return false; // Fila cheia, não é possível inserir
    }
    else {
        Fila->vFila[Fila->fim] = valor;
        Fila->fim++;
        Fila->tamanho++;
        return true;
    }
}

bool RemoverFE(FE *Fila, Valor *valor){
    if (Fila->inicio == Fila->fim)
    {
        return false;
    }
    else{
        *valor = Fila->vFila[Fila->inicio];
        Fila->inicio++;  
    }
    Fila->tamanho--;
    return true;
}

void ImprimirFE(FE *Fila){
    if (Fila->inicio == Fila->fim)
    {
        printf("Lista vazia");
    }
    else
    {
        for (int i = Fila->inicio; i < Fila->fim; i++)
        {
            if (Fila->vFila[i].INT) {
                printf("%d ", Fila->vFila[i].INT);
            } else if (Fila->vFila[i].FLOAT) {
                printf("%f ", Fila->vFila[i].FLOAT);
            } else {
                printf("%c ", Fila->vFila[i].CHAR);
            }
        }
    }
}


bool BuscarFE(FE *Fila, Valor valor){
    if (Fila->inicio == Fila->fim)
    {
        return false;
    }

        for (int i = Fila->inicio; i < Fila->fim; i++)
        {
            if (Fila->vFila[i].INT == valor.INT || Fila->vFila[i].FLOAT == valor.FLOAT || Fila->vFila[i].CHAR == valor.CHAR)
            {
                return true;
            }
            
        }      
    return false;
}


int TamanhoFE(FE *Fila){
    return Fila->tamanho;
}