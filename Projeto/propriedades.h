
//Assinaturas
void grauVertices(FILE *logger_file, int matriz[tamanho][tamanho], int vertices);
//#Parâmetros: *FILE para escrita em arquivo, matriz adjacênte, número de vértices
void ordem(FILE *logger_file,int vertices);
//#Parâmetros: *FILE para escrita em arquivo, número de vértices
void tamanhoTotal(FILE *logger_file,int matriz[tamanho][tamanho], int vertices);
//#Parâmetros: *FILE para escrita em arquivo, matriz adjacênte
void numLacos(FILE *logger_file, int matriz[tamanho][tamanho]);
//#Parâmetros: *FILE para escrita em arquivo, matriz adjacênte
void arestasMult(FILE *logger_file, int matriz[tamanho][tamanho]);
//#Parâmetros: *FILE para escrita em arquivo, matriz adjacênte
void listarVerticesArestas(FILE *logger_file, int matriz[tamanho][tamanho], int vertices);
//#Parâmetros: *FILE para escrita em arquivo, matriz adjacênte, número de vértices



//Implementações
void ordem(FILE *logger_file, int vertices){
    fprintf(logger_file,"\nCALCULANDO ORDEM\n");
    fprintf(logger_file,"Ordem: %d\n",vertices);

    printf("Ordem: %d\n",vertices);
}

void tamanhoTotal(FILE *logger_file,int matriz[tamanho][tamanho], int vertices){
     int cont=0;
     int total=0;

     fprintf(logger_file,"\nCALCULANDO TAMANHO\n");

     for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(matriz[i][j]==1)cont++;
         }
     }

     total = vertices + cont;

     fprintf(logger_file,"Tamanho: %d\n",total);
     printf("Tamanho: %d\n",total);
}

void numLacos(FILE *logger_file, int matriz[tamanho][tamanho]){
    int cont=0;

    fprintf(logger_file,"\nCALCULANDO NÚMERO DE LAÇOS\n");

    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(i==j){//Diagonal Principal: Onde os laços são "guardados"
             if(matriz[i][j]==1)//Elemento == 1, logo é laço
                cont++;
            }
         }
     }
    fprintf(logger_file,"Número de laços do grafo: %d\n",cont);
    printf("Número de laços: %d\n",cont);
}

void grauVertices(FILE *logger_file, int matriz[tamanho][tamanho], int vertices){


        int matrizGraus[tamanho][tamanho];//Matriz auxiliar para contar os graus de cada vértice
            for(int i=0;i<tamanho;i++){
                for(int j=0;j<tamanho;j++){
                    matrizGraus[i][j]=0;
                }
            }

        fprintf(logger_file,"CALCULANDO GRAUS DOS VÉRTICES\n\n");
        printf("CALCULANDO GRAUS DOS VÉRTICES\n\n");


        for(int i=0;i<vertices;i++){
          for(int j=0;j<vertices;j++){
            if(matriz[i][j]==1){//Significa que algum vértice incidiu nele
                matrizGraus[i][j] = matrizGraus[i][j] + 1;//Incremento do Grau desse vértice
          }
        }
   }
        fprintf(logger_file,"\nImprimindo a matriz com os graus de cada vértice\n");
        fprintf(logger_file,"[MATRIZ DE GRAUS]\n\n");

        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++)
                fprintf(logger_file," %3d ",matrizGraus[i][j]);
                fprintf(logger_file,"\n");
            }


        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++)
                printf(" %3d ",matrizGraus[i][j]);
                printf("\n");
            }
}

void listarVerticesArestas(FILE *logger_file, int matriz[tamanho][tamanho], int vertices){

    fprintf(logger_file,"LISTANDO VÉRTICES\n\n");
    printf("Vértices: \n");

    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if(matriz[i][j]==1)
                    printf("%d\n",i);
            }
    }

    fprintf(logger_file,"LISTANDO ARESTAS\n\n");
    printf("\nArestas: \n");

        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                if(matriz[i][j]==1)
                    printf("(%d, %d)\n",i,j);
            }

        }
    }

