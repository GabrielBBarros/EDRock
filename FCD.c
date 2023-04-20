#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Na fila circular, o último elemento aponta para o primeiro
    Adição no final
    Removidos no inicio
    Ela é um tipo de loop infinito
    quando o inicio chega ao final da fila ela volta a ser o ínicio da fila*/

    
    typedef struct noFC
    {
        double valor;
        struct noFC *prox;
    }NoFC;
    
    typedef struct fc
    {
        NoFC *inicio;
        NoFC *fim;
        int tamanho;
    }FC;

//Função de inicializar  
void InicializarFC(FC *Fila){
    Fila->inicio = NULL;
    Fila->fim = NULL;
    Fila->tamanho = 0;
}


//Função de inserir
bool InserirFC(FC *Fila, double valor){
    NoFC *novo = (NoFC *)malloc(sizeof(NoFC));
    if (novo == NULL)
    {
        return false;
    }

    novo->valor = valor;
    novo->prox = NULL;

    //Inserção com fila vazia
    if (Fila->inicio == NULL)
    {
        Fila->inicio=novo;
        Fila->fim = novo;
        novo->prox = novo;
    }
    //Inserção 
    else
    {
        Fila->fim->prox = novo;
        Fila->fim = novo;
        novo->prox = Fila->inicio;
    }
    Fila->tamanho++;
    return true;
}

//Função Remoção
bool RemoverFC(FC *Fila, double valor){
    if (Fila->inicio == NULL)
    {
        printf("Filaz vazia, impossível fazer operação");
        return false;
    }
    NoFC *aux = Fila->inicio;
    NoFC *ant = Fila->fim;
    while (aux != Fila->fim)
    {
        if (aux->valor == valor)
        {
            //Remoção do primeiro elemento
            if (aux == Fila->inicio)
            {
                Fila->inicio = aux->prox;
                Fila->fim->prox = Fila->inicio;
            }
            //Remoção de outros elementos
            else
            {
                ant->prox = aux->prox;
                if (aux == Fila->fim)
                {
                    Fila->fim = ant;
                }
            }
            free(aux);
            Fila->tamanho--;
            return true;
        }
        ant = aux;
        aux = aux->prox;
    }
    //Verifica se o último elemento é o valor a ser removido
    if (aux->valor == valor)
    {
        //Remoção do último elemento
        if (Fila->inicio == Fila->fim)
        {
            Fila->inicio = NULL;
            Fila->fim = NULL;
        }
        else
        {
            ant->prox = Fila->inicio;
            Fila->fim = ant;
        }
        free(aux);
        Fila->tamanho--;
        return true;
    }
    return false;
}




//Função Impressão
void ImprimirFC(FC *Fila){
    if (Fila->inicio == NULL)
    {
        printf("Fila vazia\n");
        return;
    }
    NoFC *aux = Fila->inicio;
    printf("\nImprimindo:\n");
    while (aux != Fila->fim) {
        printf("%lf \n", aux->valor);
        aux = aux->prox;
    }
    printf("%lf ", aux->valor);
}




//Função buscar
double BuscarValorFC(FC *Fila, double valor){
    if (Fila->inicio == NULL)
    {
        printf("Lista vazia\n");
        return -1;
    }
    NoFC *aux = Fila->inicio;
    while (aux != Fila->fim)
    {
        if (aux->valor == valor)
        {
            printf("Valor encontrado: %lf\n", valor);
            return valor;
        }
        aux = aux->prox;   
    }
    // Verifica se o último elemento da fila é igual ao valor buscado
    if (Fila->fim->valor == valor)
    {
         printf("Valor encontrado: %lf\n", valor);
        return valor;
    }
    printf("\nValor nao encontrado\n");
    return -1;
}


//Função buscar posição
int BuscarFC(FC Fila, double valor){
    if (Fila.inicio == NULL)
    {
        printf("Não encontrado\n");
        return -1;
    }
    NoFC * aux = Fila.inicio;
    int i = 0;
    do {
        if (aux->valor == valor)
        {
            printf("Posicao: %d\n", i);
            return i;
        }
        aux=aux->prox;
        i++;
    } while (aux != Fila.inicio);
    printf("Não encontrado\n");
    return -1;
}



int main(int argc, char const *argv[])
{
    printf("\n\n");
    FC fila;
    InicializarFC(&fila);
    InserirFC(&fila, 1);
    InserirFC(&fila, 2);
    //RemoverFC(&fila, 2);
    BuscarValorFC(&fila, 1);
    BuscarFC(fila, 2);
    ImprimirFC(&fila);

    return 0;
}
