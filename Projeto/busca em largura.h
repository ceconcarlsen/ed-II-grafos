#include <math.h>
#include "queue.h"

//struct
struct busca_largura{
    int tipo;
    int vertices;
    char cor[tamanho];
    int distancia[tamanho];
    int pai[tamanho];
    int adj[tamanho][tamanho];
};

//Assinaturas
void inicializa_largura(struct busca_largura *x, int adj[tamanho][tamanho], int vertices, int tipo);
//Parâmetros: estrutura busca_largura, matriz de adjacência, número de vértices, tipo de grafo
void print_tabela_largura(struct busca_largura *x, FILE *logger_file);
//Parâmetros: estrutura busca_largura, FILE do log de processamento
void gravar_busca_largura(struct busca_largura *x, FILE *f, int raiz, FILE *logger_file);
//Parâmetros: estrutura busca_largura, FILE f grafo lido, inteiro raiz, FILE do log de processamento

//Implementações
void inicializa_largura(struct busca_largura *x, int adj[tamanho][tamanho], int vertices, int tipo){
    x->tipo = tipo;
    x->vertices = vertices;

    for(int i = 0; i < vertices; i++){
        x->cor[i] = 'B';
        x->distancia[i] = 99;
        x->pai[i] = -1;
    }
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            x->adj[i][j] = adj[i][j];
        }
    }
}

void BFS(struct busca_largura* x, int raiz, FILE *logger_file){
    fprintf(logger_file, "Vértice %d fica cinza\n\n", raiz);

    x->cor[raiz] = 'C';
    x->distancia[raiz] = 0;
    fprintf(logger_file, "Vértice %d é a raiz, logo seu pai é inexistente (-1)\n\n", raiz);
    x->pai[raiz] = -1;

    struct queue* fila = (struct queue*)malloc(sizeof(struct queue)); //alocando a struct queue na memória
    fprintf(logger_file, "Inicializa a Fila\n\n");

    inicializa_queue(fila);
    fprintf(logger_file, "Insere %d (raiz) na fila\n\n", raiz);
    queue_insert(fila, raiz);

    struct node* aux;

    while(!is_vazia(fila)){//Enquanto não for vazia

        aux = queue_remove(fila);
        fprintf(logger_file, "Verificando Adjacência com o vértice %d\n\n", aux->value);

        for(int i = 0; i < x->vertices; i++){
            if(x->adj[aux->value][i] != 0){
                if(x->cor[i] == 'B'){
                    fprintf(logger_file, "Vértice %d fica cinza\n\n", i);
                    x->cor[i] = 'C';
                    x->distancia[i] = x->distancia[aux->value] + 1;

                    fprintf(logger_file, "Vértice %d tem distância %d da raiz %d\n\n", i, x->distancia[i], raiz);

                    x->pai[i] = aux->value;
                    fprintf(logger_file, "Vértice %d tem o vértice %d como pai\n\n", i, x->pai[i]);

                    fprintf(logger_file, "Insere %d na fila\n\n", i);
                    queue_insert(fila, i);
                }
            }
        }

        fprintf(logger_file, "Vértice %d fica preto\n\n", aux->value);
        x->cor[aux->value] = 'P';
    }

}

void print_tabela_largura(struct busca_largura *x, FILE *logger_file){
    fprintf(logger_file, "Printando Tabela da Busca em largura no console...\n\n");
    printf("\nTipo: %d", x->tipo);
    printf("\nQuantidade de vertices: %d\n\n", x->vertices);
    printf("Vertice    Cor    Distancia    Pai\n");
    for(int i = 0; i < x->vertices; i++){
        printf("  %2d        %c        %2d        %2d\n", i, x->cor[i], x->distancia[i], x->pai[i]);
    }
    printf("\n\n");
}

void gravar_busca_largura(struct busca_largura *x, FILE *f, int raiz, FILE *logger_file){
    fprintf(f, "Tipo: %d\n", x->tipo);
    fprintf(f, "Vertices: %d\n", x->vertices);
    fprintf(f, "Vertice Raiz: %d\n\n", raiz);
    fprintf(f, "Vertice    Cor    Distancia    Pai\n");
    fprintf(logger_file, "Gravando Tabela no arquivo:\n\n");
    fprintf(logger_file, "Vertice    Cor    Distancia    Pai\n");
    for(int i = 0; i < x->vertices; i++){
        fprintf(logger_file, "  %2d        %c        %2d        %2d \n", i, x->cor[i], x->distancia[i], x->pai[i]);
        fprintf(f, "  %2d        %c        %2d        %2d \n", i, x->cor[i], x->distancia[i], x->pai[i]);
    }
}
