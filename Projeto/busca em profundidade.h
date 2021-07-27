#include "matriz.h"

struct busca_profundidade{
    int tipo;
    int vertices;
    char cor[tamanho];
    int descoberta[tamanho];
    int finaliza[tamanho];
    int adj[tamanho][tamanho];
};

int tempo = 0;
int debug = 0;

//Assinaturas
void inicializa (struct busca_profundidade *x, int adj[tamanho][tamanho], int vertices, int tipo, FILE* logger_file);
//Parâmetros: estrutura busca_profundidade, matriz de adjacênciam número de vértices, tipo de grafo, FILE do log de processamento
void print_tabela(struct busca_profundidade *x, FILE *logger_file);
//Parâmetros: estrutura busca_profundidade, FILE do log de processamento
void DFS(struct busca_profundidade *x, int pai, FILE* logger_file);
//Parâmetros: estrutura busca_profundidade, inteiro raiz, FILE do log de processamento
void DFS_visit(struct busca_profundidade *x, int vertice, FILE* logger_file);
//Parâmetros: estrutura busca_profundidade, número de vértices, FILE do log de processamento


void pausa(){
    printf("\nPressione qualquer tecla para continuar...");
    getchar();
    getchar();
}

void inicializa (struct busca_profundidade *x, int adj[tamanho][tamanho], int vertices, int tipo, FILE* logger_file){
    x->tipo = tipo;
    x->vertices = vertices;
    for(int i = 0; i < vertices; i++){ //Inicialização da estrutura para busca
        x->cor[i] = 'B';
        x->descoberta[i] = 0;
        x->finaliza[i] = 0;
    }

    fprintf(logger_file, "Matriz de Adjacência:\n\n");
    for(int i = 0; i < vertices; i++){
        fprintf(logger_file, "   ");
        for(int j = 0; j < vertices; j++){
            x->adj[i][j] = adj[i][j];
            fprintf(logger_file, " %d ", x->adj[i][j]);
        }
        fprintf(logger_file, "\n");
    }
}

void print_tabela(struct busca_profundidade *x, FILE *logger_file){
    fprintf(logger_file, "Print da tabela da busca em profundidade no console\n\n");
    printf("Tipo: %d", x->tipo);
    printf("\nQuantidade de vertices: %d\n\n", x->vertices);
    printf("Vertice     Cor    Descoberta    Finaliza\n");
    for(int i = 0; i < x->vertices; i++){
        printf("   %2d        %c         %-2d           %-2d\n", i, x->cor[i], x->descoberta[i], x->finaliza[i]);
    }
    printf("\n\n");
}

void DFS(struct busca_profundidade *x, int pai, FILE* logger_file){
    fprintf(logger_file, "Iniciando a busca em profundidade (Função DFS)\n\n");

    if(x->cor[pai] == 'B')
        DFS_visit(x, pai, logger_file);

    fprintf(logger_file, "Realizou a busca em profundidade por todos os vértices brancos possíveis no caminho\n\n");
    fprintf(logger_file, "Iniciando verificação da existência de algum vértice branco que não pôde ser encontrado\n\n");

    for(int i = 0; i < (x->vertices); i++){
        if(x->cor[i]=='B'){
            fprintf(logger_file, "Vertice branco encontrado: %d", i);
            DFS_visit(x, i, logger_file);
        }
    }
}

void DFS_visit(struct busca_profundidade *x, int vertice, FILE* logger_file){
    fprintf(logger_file, "Vertice %d fica cinza\n\n", vertice);
    x->cor[vertice] = 'C';
    tempo = tempo + 1;
    fprintf(logger_file, "Vertice %d descoberto no tempo %d\n\n", vertice, tempo);
    x->descoberta[vertice] = tempo;
    for(int i = 0; i < (x->vertices); i++){
        if(x->adj[vertice][i] != 0){
            if(x->cor[i] == 'B'){
                fprintf(logger_file, "Visitando o vertice %d a partir do vertice %d\n\n", i, vertice);

                DFS_visit(x, i, logger_file);
            }
        }
    }

    fprintf(logger_file, "Vertice %d fica preto\n\n", vertice);
    x->cor[vertice] = 'P';
    tempo = tempo + 1;
    fprintf(logger_file, "Vertice %d finaliza no tempo %d\n\n", vertice, tempo);
    x->finaliza[vertice] = tempo;
    return;
}

void gravar_busca_profundidade(struct busca_profundidade *x, FILE *f, int raiz, FILE* logger_file){

    fprintf(f, "Tipo: %d\n", x->tipo);
    fprintf(f, "Vertices: %d\n", x->vertices);
    fprintf(f, "Vertice Raiz: %d\n\n", raiz);
    fprintf(f, "Vertice    Cor    Descoberta    Finaliza\n");

    fprintf(logger_file, "Gravando tabela no arquivo: \n");
    fprintf(logger_file, "Vertice    Cor    Descoberta    Finaliza\n");
    for(int i = 0; i < x->vertices; i++){//para todos os vértices, grave no logger_file e f a busca em profundidade
        fprintf(logger_file, "  %2d        %c         %-2d          %-2d\n", i, x->cor[i], x->descoberta[i], x->finaliza[i]);
        fprintf(f, "  %2d        %c         %-2d          %-2d\n", i, x->cor[i], x->descoberta[i], x->finaliza[i]);
    }
}
