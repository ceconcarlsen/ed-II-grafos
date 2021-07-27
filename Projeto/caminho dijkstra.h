//Estrutura
struct dijkstra{
    int vertices;
    int distancia[tamanho];
    int pai[tamanho];
    int closed_node[tamanho];
    int open_node[tamanho];
    int adj[tamanho][tamanho];
};

//Assinaturas
void gravar_dijkstra(struct dijkstra *x, int raiz, FILE *f, FILE *logger_file);
//Parâmetros: estrutura dijkstra, inteiro raiz, FILE f grafo lido, FILE do log de processamento
void inicializa_dijkstra(struct dijkstra *x, int vertices, int adj[tamanho][tamanho]);
//Parâmetros: estrutura dijkstra, número de vértices, matriz adjacênte
void relaxa(struct dijkstra *x, int vertice_saida, int vertice_chegada, int peso, FILE *logger_file);
//Parâmetros: estrutura dijkstra, vértice de saída, vértice de chegada, peso do vértice, FILE do log de processamento
short int isAllClosed(struct dijkstra *x);
//Parâmetro: estrutura dijkstra
int min(struct dijkstra *x, FILE *logger_file);
//Parâmetros: estrutura dijkstra, FILE do log de processamento
void dijkstra(struct dijkstra *x, int raiz, FILE *logger_file);
//Parâmetros:estrutura dijkstra, inteiro raiz, FILE do log de processamento
void print_tabela_dijkstra(struct dijkstra *x, FILE *logger_file);
//Parâmetros: estrutura dijkstra, FILE do log de processamento


//Implementações
void inicializa_dijkstra(struct dijkstra *x, int vertices, int adj[tamanho][tamanho]){
    x->vertices = vertices;
    for (int i = 0; i < x->vertices; i++){ //Inserindo valores iniciais
        x->distancia[i] = 999;
        x->pai[i] = -1;
        x->closed_node[i] = 0;
        x->open_node[i] = 1;
    }

    for(int i = 0; i < vertices; i++) //Atribuindo Matriz Adj a struct->Matriz
        for(int j = 0; j < vertices; j++)
            x->adj[i][j] = adj[i][j];
}


void relaxa(struct dijkstra *x, int vertice_saida, int vertice_chegada, int peso, FILE *logger_file){
    fprintf(logger_file, "Relaxando com os vértices (%d, %d) com peso %d\n\n", vertice_saida, vertice_chegada, peso);

    if(x->distancia[vertice_chegada] > (x->distancia[vertice_saida] + peso)){
        fprintf(logger_file, "Distancia do vértice %d, recebe novo valor: %d\n\n", vertice_chegada, (x->distancia[vertice_saida] + peso));

        x->distancia[vertice_chegada] = x->distancia[vertice_saida] + peso;
        x->pai[vertice_chegada] = vertice_saida;
    }
}



short int isAllClosed(struct dijkstra *x){
    for(int i = 0; i < x->vertices; i++){
        if(x->closed_node[i] == 0){
            return 0;
        }
    }
    return 1;
}


int min(struct dijkstra *x, FILE *logger_file){
    fprintf(logger_file, "Extraindo o vértice minimo\n\n");

    int minimo, vertice_min;
    minimo = 999;

    for(int i = 0; i < x->vertices; i++){
        if(x->open_node[i] != 0)
            if(minimo > x->distancia[i]){
                minimo = x->distancia[i];
                vertice_min = i;
            }
    }
    return vertice_min;
}


void dijkstra(struct dijkstra *x, int raiz, FILE *logger_file){
    fprintf(logger_file, "Começando Dijkstra\n\n");
    x->distancia[raiz] = 0;


    int vertice_min = 0;

    while(!isAllClosed(x)){
        vertice_min = min(x, logger_file);
        fprintf(logger_file, "Vértice com distância mínima: %d\n\n", vertice_min);

        fprintf(logger_file, "Fechando o vértice %d\n\n", vertice_min);

        x->closed_node[vertice_min] = 1;
        x->open_node[vertice_min] = 0;


        for(int i = 0; i < x->vertices; i++){
            fprintf(logger_file, "Verificando Adjacência do vértice %d com o vértice %d\n\n", vertice_min, i);

            if(x->adj[vertice_min][i] != 0){
                fprintf(logger_file, "Vértices %d e %d são adjacentes\n\n", vertice_min, i);
                if(x->open_node[i] == 1)
                    relaxa(x, vertice_min, i, x->adj[vertice_min][i], logger_file);
            }
        }
    }
}


void print_tabela_dijkstra(struct dijkstra *x, FILE *logger_file){
    fprintf(logger_file, "Printando a tabela do caminho de Dijkstra no console\n\n");
    printf("Vertices    Distancia    Pai    Open    Closed\n");
    for(int i = 0; i < x->vertices; i++){
        printf("   %3d        %5d      %3d     %2d       %2d  \n", i, x->distancia[i], x->pai[i], x->open_node[i], x->closed_node[i]);
    }
}


void gravar_dijkstra(struct dijkstra *x, int raiz, FILE *f, FILE *logger_file){
    fprintf(f, "Vertice raiz: %d\n", raiz);
    fprintf(f, "Vertices    Distancia    Pai    Open    Closed\n");
    fprintf(logger_file, "Gravando Tabela no arquivo:\n\n");
    fprintf(logger_file, "Vertices    Distancia    Pai    Open    Closed\n");
    for(int i = 0; i < x->vertices; i++){
        fprintf(f, "   %2d        %5d      %3d      %2d       %2d  \n",i, x->distancia[i], x->pai[i], x->open_node[i], x->closed_node[i]);
        fprintf(logger_file, "   %2d        %5d      %3d      %2d       %2d  \n",i, x->distancia[i], x->pai[i], x->open_node[i], x->closed_node[i]);
    }
}
