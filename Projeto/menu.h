//Assinaturas
void apresentacao();//Apresentação do trabalho prático
void menu();//Menu de opções
void grafo_selecao();//Seleção do grafo
void menu_propriedades();//Menu de propriedades

//Implementação
void apresentacao(){
    printf("\t\t[Estrutura de Dados 2, Gabriel Cecon Carlsen, 10/03/21]\n\n");
    printf("\t\t\t\tTRABALHO PRÁTICO FINAL\n\n");
    printf("---> Estrutura: Matriz de adjacência\n\n");
    printf("- Implementação de programa para manipulação de grafos\n");
    printf("- Log do processamento\n");
    printf("- Grafo armazenado em arquivo texto\n");
    printf("- Implementação de busca em grafo (Profundidade e Largura)\n");
    printf("- Caminho em dígrafo (DIJKSTRA)\n");
    printf("- Atualização do grafo\n");
    printf("- Verificação de propriedades:\n");
    printf("  Grau dos vértices\n");
    printf("  Ordem e tamanho\n");
    printf("  Listar vértices e arcos/arestas\n");
    printf("  Verificar o número de laços e arestas multiplas\n\n");
    printf("\t\t[Código/projeto/binário, Documentação, Vídeo explicativo]\n\n");

    system("pause");
    system("cls");
}

void menu(){
    system("cls");
    printf("\t[MENU]\n\n");
    printf("1 - Escolher o grafo\n");
    printf("2 - Mostrar matriz de adjacência\n");
    printf("3 - Atualizar o grafo\n");
    printf("4 - Busca em Profundidade\n");
    printf("5 - Busca em Largura\n");
    printf("6 - Caminho de Dijkstra\n");
    printf("7 - Mostrar Tabelas\n");
    printf("8 - Verificação de propriedades\n");
    printf("0 - Sair\n");
    printf("\nEscolha uma opção: ");
}

void grafo_selecao(){
    system("cls");
    printf("1 - Grafo 1.txt\n");
    printf("2 - Grafo 2.txt\n");
    printf("3 - Grafo 3.txt\n");
    printf("\nEscolha uma opção: ");
}

void menu_propriedades(){
    system("cls");
    printf("\t[PROPRIEDADES]\n\n");
    printf("1 - Grau dos vértices\n");
    printf("2 - Ordem e Tamanho\n");
    printf("3 - Listar Vértices/Arestas\n");
    printf("4 - Número de laços (loops)\n");
    printf("0 - Sair\n");
    printf("\nEscolha uma opção: ");
}
