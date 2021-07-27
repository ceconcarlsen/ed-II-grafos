#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "busca em profundidade.h"
#include "busca em largura.h"
#include "caminho dijkstra.h"
#include "logger.h"
#include "menu.h"
#include "propriedades.h"

int main(){

/* TESTE DE ESCRITA EM FILE
    FILE *teste;
    teste = fopen("Logger.txt","w+");
    logger(teste,1);
    fclose(teste);
*/


    //Locale
    setlocale(LC_ALL,"portuguese");

    //Chamada da função apresentação(), biblioteca "menu.h"
    apresentacao();

    //Variáveis
    int matriz_adj[tamanho][tamanho], prop_selection, menu_selection, grafo_selecionado ,tipo, vertices, saida, chegada, peso, pai, aux[3], min_alcancado;
    FILE *f, *arquivoDestino_profundidade, *arquivoDestino_largura, *grafo, *arquivoDestino_dijkstra, *logger_file;

    //Estruturas das buscas e caminhos
    struct busca_profundidade *raiz_profundidade = (struct busca_profundidade*) malloc (sizeof(struct busca_profundidade));
    struct busca_largura *raiz_largura = (struct busca_largura*) malloc (sizeof(struct busca_largura));
    struct dijkstra *raiz_dijkstra = (struct dijkstra*) malloc (sizeof(struct dijkstra));

    //Inicialização
    menu_selection = pai = -1;

    //Abertura dos arquivos de buscas e caminhos (w+, reescrever se já existir)
    arquivoDestino_profundidade = fopen("BuscaProfundidadeGrafo.txt", "w+");
    arquivoDestino_largura = fopen("BuscaLarguraGrafo.txt", "w+");
    grafo = fopen("Grafo.txt", "w+");
    logger_file = fopen("Logger.txt", "w+");



    do{
        system("cls");
        //Chamada da função menu(), biblioteca "menu.h"
        menu();
        scanf("%d", &menu_selection);

        switch(menu_selection){
            case 0: menu_selection=0;
                    break;

            case 1: //Seleção do grafo
                grafo_selecao();
                scanf("%d", &grafo_selecionado);

                //Abertura do grafo selecionado (r+, leitura e escrita, apaga se já existir)
                if(grafo_selecionado == 1)
                    f = fopen("1.txt", "r");

                 else if(grafo_selecionado == 2)
                        f = fopen("2.txt", "r");

                    else
                        f = fopen("3.txt", "r");

                //Verificação de erro na abertura dos arquivos
                if (f == NULL || arquivoDestino_profundidade == NULL || grafo == NULL || arquivoDestino_largura == NULL || arquivoDestino_dijkstra == NULL ){
                    printf("[ERRO]: Impossível abrir um dos arquivos!");
                    exit(1);
                }

                //Leitura do tipo e da quantidade de vertices
                fscanf(f, "%i", &tipo); //0:digrafo, 1:grafo
            	fscanf(f, "%i", &vertices); //nº de vértices

                iniciliza_matriz(matriz_adj); //Inicialmente todos com todos os elementos sendo 0

                //Verificação para o print das tabelas
                aux[0] = 0;
                aux[1] = 0;
                aux[2] = 0;

                //Matriz de adjacência
                while(fscanf(f, "%d %d %d", &saida, &chegada, &peso) != EOF){ //Enquanto a leitura não chegar no fim do arquivo
                    if (peso == 0){ //Se tiver peso 0, grava 1 para dizer que existe uma aresta que liga a saida com a chegada
                        matriz_adj[saida][chegada] += 1; //Digrafo
                        if(tipo == 0) //Grafo
                            matriz_adj[chegada][saida] += 1;
                    }
                    else { //Se não grava o peso daquela aresta
                        matriz_adj[saida][chegada] += peso; //Digrafo
                        if(tipo == 0) //Grafo
                            matriz_adj[chegada][saida] += peso;
                    }
                }

                logger(logger_file, grafo_selecionado);

                //Escolha da raiz para o grafo
                while(pai < 0 || pai > vertices){
                    fprintf(logger_file, "Escolhendo a raiz do grafo\n");

                    system("cls");

                    printf("Digite o pai (Raiz): ");
                    scanf("%d", &pai);
                    fprintf(logger_file, "Raiz do grafo escolhida com sucesso: %d\n\n", pai);
                }

                fprintf(logger_file, "Gravando grafo a partir da matriz de Adjacência\n\n");
                fprintf(logger_file, "\n\nTipo do Grafo: %d", tipo);
                fprintf(logger_file, "\nQuantidade de Vertices: %d\n\n", vertices);
                gravar_grafo(matriz_adj, vertices, tipo, grafo);

                break;

            case 2: //Impressão da matriz
                system("cls");
                printf("\n");
                print_matriz(matriz_adj, vertices);
                pausa();
                break;

            case 3: //Atualização
                system("cls");

                fprintf(logger_file, "Atualizando o grafo\n\n");
                fprintf(logger_file, "Escolhendo o vertice de saida\n\n");

                printf("Qual e o vertice de saida?: ");
                scanf("%d", &saida);https://visualgo.net/pt
                fprintf(logger_file, "Vertice de saida escolhido: Vertice %d\n\n", saida);

                system("cls");

                fprintf(logger_file, "Escolhendo o vertice de chegada...\n\n");

                printf("Qual e o vertice de chegada?: ");
                scanf("%d", &chegada);

                fprintf(logger_file, "Vertice de chegada escolhido: Vertice %d\n\n", chegada);

                system("cls");

                fprintf(logger_file, "Escolhendo o peso da aresta(%d, %d)...\n\n", saida, chegada);

                printf("Qual e o peso da aresta?: ");
                scanf("%d", &peso);

                fprintf(logger_file, "Peso da aresta (%d, %d): %d\n\n", saida, chegada, peso);

                system("cls");

                printf("MATRIZ ANTERIOR: \n");
                print_matriz(matriz_adj, vertices);

                matriz_adj[saida][chegada] = peso;

                printf("\n\nMATRIZ ATUALIZADA: \n");
                print_matriz(matriz_adj, vertices);

                pausa();
                break;

            case 4: //Busca em Profundidade
                system("cls");
                printf("REALIZANDO BUSCA EM PROFUNDIDADE [resultado: logger.txt]\n\n");
                fprintf(logger_file, "\n\n\nINICIANDO BUSCA EM PROFUNDIDADE\n\n");
                fprintf(logger_file, "Iniciando estrutura da profundidade\n\n");
                inicializa(raiz_profundidade, matriz_adj, vertices, tipo, logger_file);

                fprintf(logger_file, "\nINICIANDO BUSCA EM PROFUNDIDADE\n\n");

                DFS(raiz_profundidade, pai, logger_file);//struct, pai, arquivo log

                fprintf(logger_file, "Gravando busca em profundidade no arquivo\n");

                gravar_busca_profundidade(raiz_profundidade, arquivoDestino_profundidade, pai, logger_file);//struct, file(não está gravando), int(raiz), file

                aux[0] = 1;
                pausa();
                break;

            case 5: //Busca em Largura
                system("cls");
                printf("REALIZANDO BUSCA EM LARGURA [resultado: logger.txt]\n\n");
                fprintf(logger_file, "\n\n\nINICIANDO BUSCA EM LARGURA\n\n");
                fprintf(logger_file, "Inicializando estrutura da largura\n\n");
                inicializa_largura(raiz_largura, matriz_adj, vertices, tipo);

                fprintf(logger_file, "INICIANDO BUSCA EM LARGURA\n\n");

                BFS(raiz_largura, pai, logger_file);//struct, pai, arquivo log

                fprintf(logger_file, "Verificando existência de algum outro vértice branco\n\n");
                for(int i = 0; i < raiz_largura->vertices; i++)
                    if(raiz_largura->cor[i] == 'B'){//Se ainda existir vértice não visitado (branco)
                        fprintf(logger_file, "Vértice branco encontrado: %d\n\n", i);
                        BFS(raiz_largura, i, logger_file);
                    }

                fprintf(logger_file, "Gravando busca em largura no arquivo\n\n");
                gravar_busca_largura(raiz_largura, arquivoDestino_largura, pai, logger_file);
                aux[1] = 1;
                pausa();
                break;

            case 6://Caminho de DIJKISTRA
                system("cls");
                printf("REALIZANDO CAMINHO DE DIJKSTRA [resultado: logger.txt]\n");
                fprintf(logger_file, "\n\n\nINICIANDO CAMINHO DE DIJKSTRA\n\n");
                fprintf(logger_file, "Inicializando estrutura\n\n");
                inicializa_dijkstra(raiz_dijkstra, vertices, matriz_adj);

                fprintf(logger_file, "Caminho de Dijkstra\n\n");

                int isPossivel = 1;
                for(int i = 0; i < vertices; i++){
                    for(int j = 0; j < vertices; j++){
                        if(matriz_adj[i][j] < 0){//Se a matriz conter algum elemento negativo
                            printf("\n\nO GRAFO POSSUI ARESTAS COM PESO NEGATIVO\n\n");
                            isPossivel = 0; //Não é possível continuar
                        }
                    }
                }
                if(isPossivel) dijkstra(raiz_dijkstra, pai, logger_file);

                fprintf(logger_file, "Gravando caminho de Dijkstra no arquivo\n\n");
                gravar_dijkstra(raiz_dijkstra, pai, arquivoDestino_dijkstra, logger_file);
                aux[2] = 1;
                pausa();
                break;

            case 7://Print Tabelas
                system("cls");
                printf("MOSTRANDO AS TABELAS\n\n");//aux: vetor booleano

                if(aux[0]){
                    printf("Tabela Busca em Profundidade: \n\n");
                    print_tabela(raiz_profundidade, logger_file);
                }

                if(aux[1]){
                    printf("\n\nTabela Busca em Largura: \n\n");
                    print_tabela_largura(raiz_largura, logger_file);
                }

                if(aux[2]){
                    printf("\n\nTabela Caminho de Dijkstra: \n\n");
                    print_tabela_dijkstra(raiz_dijkstra, logger_file);
                }
                pausa();
                break;

            case 8://Propriedades
                 do{
                menu_propriedades();
                scanf("%d", &prop_selection);

                //--------------------------------------------------------------------------------------------------
                switch (prop_selection){

                case 0: prop_selection=0;break;

                case 1: system("cls");
                        fprintf(logger_file,"\nCHAMADA DA FUNCAO: grauVertices()\n");
                        grauVertices(logger_file,matriz_adj, vertices);
                        pausa();
                        break;

                case 2: system("cls");
                        fprintf(logger_file,"\nCHAMADA DA FUNCAO: ordem()\n");
                        ordem(logger_file,vertices);
                        fprintf(logger_file,"\nCHAMADA DA FUNÇÃO: tamanhoTotal()\n");
                        tamanhoTotal(logger_file,matriz_adj,vertices);
                        pausa();
                        break;

                case 3: system("cls");
                        listarVerticesArestas(logger_file,matriz_adj, vertices);
                        pausa();
                        break;

                case 4: system("cls");
                        fprintf(logger_file,"CHAMADA DA FUNCAO: grauVertices()");
                        numLacos(logger_file,matriz_adj);
                        pausa();
                        break;
                }

             }while(prop_selection);//loop do menu de propriedades

                 //--------------------------------------------------------------------------------------------------
                pausa();
                break;

        }//Switch

    }while(menu_selection);//Enquanto menu_selction !=0 (Sair)

    fprintf(logger_file,"\n[Fechando os arquivos]\n\n");
    fprintf(logger_file,"\n\n****FIM****\n\n");
     printf("\n\n****FIM****\n\n");

    fclose(f);
    fclose(arquivoDestino_profundidade);
    fclose(arquivoDestino_largura);
    fclose(arquivoDestino_dijkstra);
    fclose(grafo);

    return 0;
}
