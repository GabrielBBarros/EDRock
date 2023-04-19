#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct fe
{
    double vFila[MAX];
    int inicio;
    int fim;
    int tamanho;
}FE;

void InicioalizarFE(FE *Fila){
    Fila->inicio = -1;
    Fila->fim = -1;
    Fila->tamanho = 0;
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

bool InserirFE(FE *Fila, double valor){
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

bool RemoverFE(FE *Fila, double valor){
    if (Fila->inicio == Fila->fim)
    {
        return false;
    }
    else{
        valor = Fila->vFila[Fila->inicio];
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
        printf("\nImprimindo \n");
        for (int i = Fila->inicio; i < Fila->fim; i++)
        {
            printf("%lf \n", Fila->vFila[i]);
        }
    }
}

//Buscar valor
double BuscarValorFE(FE *Fila, double valor){
    if (Fila->inicio == Fila->fim)
    {
        printf("Valor não encontrado \n");  
        return -1;
    }

        for (int i = Fila->inicio; i < Fila->fim; i++)
        {
            if (Fila->vFila[i] == valor)
            {
                printf("Encontrado: %lf\n", valor);
                return valor;
            }
            
        }   
    printf("Valor não encontrado \n");  
    return -1;
}

//Buscar Posição




int main(int argc, char const *argv[])
{
    FE Fila;
    InicioalizarFE(&Fila);
    InserirFE(&Fila, 5);
    InserirFE(&Fila, 8);
    InserirFE(&Fila, 69);
    //RemoverFE(&Fila, 5);
    BuscarValorFE(&Fila, 5);
    BuscarFE(&Fila, 8);
    ImprimirFE(&Fila);

    return 0;
}
