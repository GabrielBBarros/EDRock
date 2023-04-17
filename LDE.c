#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef union valor
{
    int INT;
    float FLOAT;
    char CHAR;
} Valor;

typedef struct nolde
{
    Valor valor;
    struct nolde *prox;

}NoLDE;

typedef struct lde
{
    NoLDE *inicio;
    NoLDE *fim;
    int tamanho;
}LDE;




//Inserção no ínicio
int inserirInicioLDE (LDE *L, Valor valor, int tamanho){
    
    //Alocação dinâmica
    NoLDE *novo = (NoLDE*) malloc(sizeof(NoLDE));
    //Ver se a alocação está errada
    if (novo == NULL)
    {
        //Erro na alocação
        return 0;
    }
    //Define o valor do novo nó
    novo->valor = valor;
    //Define o proximo do novo nó
    novo->prox = L->inicio;
        //Verifica se coloca ele no inicio
        if (L->inicio ==  NULL)
        {
            //Insere no inicio e no fim, por ser o primeiro nó
            L->fim = novo;
        }
        //Caso não insere depois do primeiro valor adicionado
        else{
            novo->prox = L->inicio;
        }
        L->inicio = novo;
        //Incrementa o tamanho da lista
        tamanho ++;
        return 1;
}



//Inserção no fim
int inserirFimLDE (LDE *L, Valor valor, int tamanho){
    
    //Alocação dinâmica
    NoLDE *novo = (NoLDE*) malloc(sizeof(NoLDE));
    //Ver se a alocação está errada
    if (novo == NULL)
    {
        //Erro na alocação
        return 0;
    }
    //Define o valor do novo nó
    novo->valor = valor;
    //Define o proximo do novo nó
    novo->prox = L->inicio;
        //Verifica se coloca ele no inicio
        if (L->inicio ==  NULL)
        {
            //Insere no inicio, por ser o primeiro nó
            L->inicio = novo;
        }
        //Caso não insere depois do primeiro valor adicionado
        else{
            L->fim->prox = novo;
        }
        L->fim = novo;
        //Incrementa o tamanho da lista
        tamanho ++;
        return 1;
}


//Inserção ordenada




//Remoção
int removerLDE (LDE *L, Valor valor, int tamanho){
    if (L->tamanho == 0)
    {
        printf("Lista vazia, não é possível fazer a operação \n");
        return 0;
    }

    NoLDE *aux = L -> inicio;

    NoLDE *ant = NULL;


    //Procurar nó
    while (aux != NULL)
    {
        /* code */
    }
    


    
    
}





//Busca
bool buscaLDE(LDE *L, Valor valor){
    NoLDE *aux = L->inicio;
    while (aux != NULL)
    {
        if (aux->valor.INT == valor.INT && aux->valor.FLOAT == valor.FLOAT && aux->valor.CHAR == valor.CHAR)
        {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}




//Impressão
void impressaoLDE(LDE *L){
    typedef enum tipo_valor { INT, FLOAT, CHAR } TipoValor;
    if (L->tamanho == 0)
    {
        printf("A lista está vazia");
    }
    
    NoLDE *aux;

    for (aux = L->inicio; aux != NULL; aux = aux->prox)
    {
        TipoValor tipo = INT;

        if (aux->valor.INT) {
            tipo = INT;
        } else if (aux->valor.FLOAT) {
            tipo = FLOAT;
        } else if (aux->valor.CHAR) {
            tipo = CHAR;
        }

        switch (tipo)
        {
        case INT:
            printf("%d ", aux->valor.INT);
            break;
        case FLOAT:
            printf("%.2f ", aux->valor.FLOAT);
            break;
        case CHAR:
            printf("%c ", aux->valor.CHAR);
            break;
        
        default:
            break;
        }
        
    }
}



//Ordenação


//Tamanho
int tamanhoLDE(LDE *L, int tamanho){
    return tamanho;
}




int main(int argc, char const *argv[])
{
    
    return 0;
}
