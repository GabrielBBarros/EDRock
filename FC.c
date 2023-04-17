#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Na fila circular, o último elemento aponta para o primeiro
    Adição no final
    Removidos no inicio
    Ela é um tipo de loop infinito
    quando o inicio chega ao final da fila ela volta a ser o ínicio da fila*/


    typedef union valor
    {
        int INT;
        float FLOAT;
        char CHAR;
    }Valor;
    
    typedef struct nofc
    {
        Valor valor;
        struct nofc *prox;
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
}


//Função de inserir
bool InserirFC(FC *Fila, Valor valor){
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


//Remoção
bool RemoverFC(FC *Fila, Valor valor){
    if (Fila->inicio == NULL)
    {
        return false;
    }
    
    NoFC *aux = Fila->inicio;
    NoFC *ant = NULL;
    bool achado = false;
    
    while (aux !=Fila->inicio)
    {
         if (aux->valor.INT == valor.INT || aux->valor.FLOAT == valor.FLOAT || aux->valor.CHAR == valor.CHAR) {
            achado = true;
            break;
        }
        ant = aux;
        aux = aux->prox;
    }

    if (achado)
    {
         if (Fila->inicio == Fila->fim) {  // Fila com um único elemento
            Fila->inicio = NULL;
            Fila->fim = NULL;
        } else if (aux == Fila->inicio) {  // Remoção do primeiro elemento
            Fila->inicio = Fila->inicio->prox;
            Fila->fim->prox = Fila->inicio;
        } else if (aux == Fila->fim) {  // Remoção do último elemento
            Fila->fim = ant;
            Fila->fim->prox = Fila->inicio;
        } else {  // Remoção do elemento do meio
            ant->prox = aux->prox;
        }

        free(aux);
        Fila->tamanho--;
        return true;  // Elemento encontrado e removido    
    }
    else
        {
            return false;
        }
    
}


//Função Impressão
void ImprimirFC(FC *Fila){
    if (Fila->inicio == NULL)
    {
        printf("Fila vazia");
    }
    NoFC *aux = Fila->inicio;
     do {
            if (aux->valor.INT) {
                printf("%d ", aux->valor.INT);
            } else if (aux->valor.FLOAT) {
                printf("%f ", aux->valor.FLOAT);
            } else {
                printf("%c ", aux->valor.CHAR);
            }
            aux = aux->prox;
        } while (aux != Fila->inicio);    
}



//Função buscar
bool BuscarFC(FC *Fila, Valor valor){
    if (Fila->inicio == NULL)
    {
        return false;
    }
    NoFC *aux = Fila->inicio;
    while (aux != Fila->inicio)
    {
        if (aux->valor.INT == valor.INT ||
            aux->valor.FLOAT == valor.FLOAT ||
            aux->valor.CHAR == valor.CHAR)
        {
            return true;
        }
        aux = aux->prox;   
    }
    return false;
}


//Função tamanho
int TamanhoFC(int tamanho){
    return tamanho;
}



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
