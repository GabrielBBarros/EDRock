# EDRock
Biblioteca em C para auxiliar no estudo de Estrutura de Dados


## Resumo

Será implementado uma biblioteca em C para o auxílio dos alunos interessados na disciplina de Estrutura de Dados utilizando a linguagem C, dessa forma será possível ver o código sendo executado na prática além no caso de possível dúvida é fazível entrar dentro da biblioteca e ver como o código foi implementado, verificando sua lógica passo a passo, de modo que seguro e rápido.

Serão feitos 23 tipos de estrutura de dados, classificados em 7 tipos (Lista, Pilha, Fila, Hashing, Lista Cruzada, Matriz Esparsa e Árvore), além de implementação de String Dinâmica em todas as listas dinâmicas e uma simulação genérica em todos os tipos de Fila. Ao todo serão implementados em torno de 169 funções dos mais diversos tipos, fora a implementação de cada estrutura em si. 

Após toda a aplicação feita, será feito um estudo de “traduzir” esse código da biblioteca em Javascript em uma renovação do PFC, dessa forma será possível colocá-lo dentro da plataforma já feita Cadilag. Com isso, depois de um ano completo, pretende-se criar duas bibliotecas, uma para C e outra para JavaScript, ampliando bastante a efetividade no estudo de Estrutura de Dados dentro e fora da sala de aula.



## Estrutura de Dados Utilizadas

Listas

	Lista Estatística Encadeada (LEE);
	Lista Estática Duplamente Encadeada (LEDE);
	Lista Dinâmica Encadeada (LDE);
	Lista Dinâmica Duplamente Encadeada (LDDE);
	Implementação da String Dinâmica.

Pilha

	Pilha Estática (PE);
	Pilha Dinâmica (PD);
	Pilha Múltipla Estática (PME).

Fila

	Fila Estática (FE);
	Fila Dinâmica (FD); 
	Fila Circular (FC);
	Fila Múltipla (FM);
	Fila de Prioridade Estática (FPE);
	Fila de Prioridade Dinâmica (FPD);
	Deck (D);
	Simulação Genérica.

Hashing 

	Hashing (com lista estática e tratamento de colisão) (HLE);
	Hashing (com lista dinâmica e tratamento de colisão) (HLD).

Lista Cruzada
	
	Lista Cruzada (LC).


Matriz Esparsa

	Matriz Esparsa (ME).

Árvore 

	Árvore Binária (AB);
	Árvore Binária de Busca (ABB);
	Árvore Estritamente Binária (AEB);
	Árvore AVL (AAVL);
	Árvore Rubro-Negra (ARN);
	




## Funções Aplicadas

Listas

	Inicialização (void);
	Inserção simples (bool);
	Inserção ordenada (bool);
	Remoção (bool);
	Busca (bool);
	Impressão (void);
	Ordenação (void);
	Cheia, para listas do tipo estática (bool);
	Vazia, para listas do tipo estática (bool);

Pilha

	Inicialização (void);
	Push (bool);
	Pop (bool);
	Busca (bool);
	Impressão (void);
	Cheia, para listas do tipo estática (bool);
	Vazia, para listas do tipo estática (bool);

Fila

	Inicialização (void);
	Inserção (bool);
	Remoção (bool);
	Busca (bool);
	Impressão (void);
	Cheia, para listas do tipo estática (bool);
	Vazia, para listas do tipo estática (bool);

Hashing 

	Inicialização (void);
	Inserção (bool);
	Remoção (bool);
	Busca (bool);
	Impressão (void);

Lista Cruzada
	
	Inicialização (void);
	Inserção  (bool);
	Remoção (bool);
	Busca (bool);
	Impressão (void);


Matriz Esparsa

	Inicialização (void);
	Inserção (bool);
	Remoção (bool);
	Busca (bool);
	Impressão (void);

Árvore 

	Inicialização (void);
	Inserção (bool);
	Remoção (bool);
	Busca (bool);
	Impressão (void);
	Cheia, para listas do tipo estática (bool);
	Vazia, para listas do tipo estática (bool);




## Declaração

	O chamamento da função e sua declaração aparecerá assim em um em uma main como em :

	Nome da Função + Tipo de Dado em Sigla

	Exemplo:
						ImprimirLEE()





## Bibliotecas Auxiliares

	
	stdio.h
	stdbool.h
	string.h
	

## Documentação auxiliar de código

	-Proximo = prox;
	
	-Anterior = ant;
	
	-Base = base;
	
	-Topo = topo;
	
	-Auxiliar = aux;
	
	-Valor = valor;
	
	-Inicio = inicio;
	
	-Fim = fim;
	
	-No = no/No+Sigla
	
	
