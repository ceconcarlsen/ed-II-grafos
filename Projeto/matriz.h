#define tamanho 100

//Assinaturas
void iniciliza_matriz(int matriz[tamanho][tamanho]);
void print_matriz(int matriz[tamanho][tamanho], int vertices);
void gravar_grafo(int matriz[tamanho][tamanho], int vertices, int tipo, FILE *f)



//Implementações
void iniciliza_matriz(int matriz[tamanho][tamanho]){//Inicializa todos os elemento da matriz com 0
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            matriz[i][j] = 0;
        }
    }
}

void print_matriz(int matriz[tamanho][tamanho], int vertices){//Print de todos os elementos da matriz
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++)
			printf(" %3d ",matriz[i][j]);
            printf("\n");
	}
	return;
}

void gravar_grafo(int matriz[tamanho][tamanho], int vertices, int tipo, FILE *f){//Gravando grafo no file
    fprintf(f, "%d\n", tipo);
    fprintf(f, "%d\n", vertices);

    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            if ((matriz[i][j] != 0) && (matriz[i][j] == 1))
                fprintf(f, "%d %d 0\n", i, j);
            else if ((matriz[i][j] != 0) && (matriz[i][j] != 1))
                fprintf(f, "%d %d %d\n", i, j, matriz[i][j]);
        }
    }
    return;
}
