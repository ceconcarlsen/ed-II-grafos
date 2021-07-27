
//Assinaturas
void grauVertices(FILE *logger_file, int matriz[tamanho][tamanho], int vertices);
//#Par�metros: *FILE para escrita em arquivo, matriz adjac�nte, n�mero de v�rtices
void ordem(FILE *logger_file,int vertices);
//#Par�metros: *FILE para escrita em arquivo, n�mero de v�rtices
void tamanhoTotal(FILE *logger_file,int matriz[tamanho][tamanho], int vertices);
//#Par�metros: *FILE para escrita em arquivo, matriz adjac�nte
void numLacos(FILE *logger_file, int matriz[tamanho][tamanho]);
//#Par�metros: *FILE para escrita em arquivo, matriz adjac�nte
void arestasMult(FILE *logger_file, int matriz[tamanho][tamanho]);
//#Par�metros: *FILE para escrita em arquivo, matriz adjac�nte
void listarVerticesArestas(FILE *logger_file, int matriz[tamanho][tamanho], int vertices);
//#Par�metros: *FILE para escrita em arquivo, matriz adjac�nte, n�mero de v�rtices



//Implementa��es
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

    fprintf(logger_file,"\nCALCULANDO N�MERO DE LA�OS\n");

    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(i==j){//Diagonal Principal: Onde os la�os s�o "guardados"
             if(matriz[i][j]==1)//Elemento == 1, logo � la�o
                cont++;
            }
         }
     }
    fprintf(logger_file,"N�mero de la�os do grafo: %d\n",cont);
    printf("N�mero de la�os: %d\n",cont);
}

void grauVertices(FILE *logger_file, int matriz[tamanho][tamanho], int vertices){


        int matrizGraus[tamanho][tamanho];//Matriz auxiliar para contar os graus de cada v�rtice
            for(int i=0;i<tamanho;i++){
                for(int j=0;j<tamanho;j++){
                    matrizGraus[i][j]=0;
                }
            }

        fprintf(logger_file,"CALCULANDO GRAUS DOS V�RTICES\n\n");
        printf("CALCULANDO GRAUS DOS V�RTICES\n\n");


        for(int i=0;i<vertices;i++){
          for(int j=0;j<vertices;j++){
            if(matriz[i][j]==1){//Significa que algum v�rtice incidiu nele
                matrizGraus[i][j] = matrizGraus[i][j] + 1;//Incremento do Grau desse v�rtice
          }
        }
   }
        fprintf(logger_file,"\nImprimindo a matriz com os graus de cada v�rtice\n");
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

    fprintf(logger_file,"LISTANDO V�RTICES\n\n");
    printf("V�rtices: \n");

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

