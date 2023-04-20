#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


typedef struct fce
{
    double valores[MAX];
    int inicio;
    int fim;
    int tamanho;
}FCE;

//Inicialização
void InicializarFCE(FCE *Fila){
    Fila->inicio = 0;
    Fila->fim = -1;
    Fila->tamanho = 0;
}

//Vazio
bool VazioFCE (FCE *Fila){
    if (Fila->tamanho == 0)
    {
        printf("Fila vazia \n");
        return true;
    }
    else
    {
        printf("Fila com elementos \n");
        return false;
    }
    

}

//Cheio
bool CheiaFCE(FCE *Fila){
    if (Fila->tamanho == MAX)
    {
        printf("Fila cheia\n");
        return true;
    }
    else{
        printf("A fila nao esta cheia\n");
        return false;   
    }
    
}

//Inserir
bool InserirFCE(FCE *Fila, double valor){
    if (Fila->tamanho == MAX)
    {
        printf("Fila cheia, não e possivel adicionar mais. \n");
        return false;
    }
    Fila->fim = (Fila->fim+1) % MAX;
    Fila->valores[Fila->fim] = valor;
    Fila->tamanho++;
    return true;
}

//Remover
bool RemoverFCE(FCE *Fila, double *valor){
    if (Fila->tamanho == 0)
    {
        printf("Fila vazia, não é possível fazer a operacao \n");
        return false;
    }
    *valor = Fila->valores[Fila->inicio];
    Fila->inicio = (Fila->inicio+1) % MAX;
    Fila->tamanho--;
    return true;   
}

//Imprimir
void ImprimirFCE(FCE *Fila){
    if (Fila->tamanho == 0)
    {
        printf("Fila vazia");
        return;
    }
    int i = Fila->inicio;
    int cont = 0;
    while (cont < Fila->tamanho)
    {
        printf("%lf \n", Fila->valores[i]);
        i = (i+1)%MAX;
        cont++;
    }    
}

//Busca valor
bool BuscarValor(FCE *Fila, double valor){
    if (Fila->tamanho == 0)
    {
        printf("Fila vazia \n");
        return false;
    }
    int i = Fila->inicio;
    int fim = (Fila->inicio+Fila->tamanho-1) % MAX;

    while (i <= fim)
    {
         if (Fila->valores[i] == valor)
    {
        printf("Valor encontrado \n", valor);
        return true;
    }
    i++;
    }
    printf("Valor nao encontrado \n");
    return false;  
}

//Busca posição
bool BuscarPosicao(FCE *Fila, double valor){
    if (Fila->tamanho == 0)
    {
        printf("Fila vazia \n");
        return false;
    }
    int i = Fila->inicio;
    int fim = (Fila->inicio+Fila->tamanho-1) % MAX;
    while (i <= fim)
    {
        if (Fila->valores[i] == valor)
    {
        printf("Encontrado, posicao: %d \n", i);
        return true;
    }
    i++;
    }
    printf("Valor nao encontrado \n");
    return false;  
}

int main(int argc, char const *argv[])
{
    FCE minhaFila;
    InicializarFCE(&minhaFila);
    
    // Testa o estado da fila
    VazioFCE(&minhaFila);
    CheiaFCE(&minhaFila);

    // Insere alguns elementos na fila
    InserirFCE(&minhaFila, 10);
    InserirFCE(&minhaFila, 20);
    InserirFCE(&minhaFila, 30);

    // Imprime os elementos da fila
    ImprimirFCE(&minhaFila);

    // Remove um elemento da fila
    double valorRemovido;
    RemoverFCE(&minhaFila, &valorRemovido);

    // Testa a busca de valor e de posição
    BuscarValor(&minhaFila, 20);
    BuscarValor(&minhaFila, 40);

    BuscarPosicao(&minhaFila, 20);
    BuscarPosicao(&minhaFila, 40);

    return 0;
    return 0;
}


