//Assinaturas
void apresentacao();//Apresenta��o do trabalho pr�tico
void menu();//Menu de op��es
void grafo_selecao();//Sele��o do grafo
void menu_propriedades();//Menu de propriedades

//Implementa��o
void apresentacao(){
    printf("\t\t[Estrutura de Dados 2, Gabriel Cecon Carlsen, 10/03/21]\n\n");
    printf("\t\t\t\tTRABALHO PR�TICO FINAL\n\n");
    printf("---> Estrutura: Matriz de adjac�ncia\n\n");
    printf("- Implementa��o de programa para manipula��o de grafos\n");
    printf("- Log do processamento\n");
    printf("- Grafo armazenado em arquivo texto\n");
    printf("- Implementa��o de busca em grafo (Profundidade e Largura)\n");
    printf("- Caminho em d�grafo (DIJKSTRA)\n");
    printf("- Atualiza��o do grafo\n");
    printf("- Verifica��o de propriedades:\n");
    printf("  Grau dos v�rtices\n");
    printf("  Ordem e tamanho\n");
    printf("  Listar v�rtices e arcos/arestas\n");
    printf("  Verificar o n�mero de la�os e arestas multiplas\n\n");
    printf("\t\t[C�digo/projeto/bin�rio, Documenta��o, V�deo explicativo]\n\n");

    system("pause");
    system("cls");
}

void menu(){
    system("cls");
    printf("\t[MENU]\n\n");
    printf("1 - Escolher o grafo\n");
    printf("2 - Mostrar matriz de adjac�ncia\n");
    printf("3 - Atualizar o grafo\n");
    printf("4 - Busca em Profundidade\n");
    printf("5 - Busca em Largura\n");
    printf("6 - Caminho de Dijkstra\n");
    printf("7 - Mostrar Tabelas\n");
    printf("8 - Verifica��o de propriedades\n");
    printf("0 - Sair\n");
    printf("\nEscolha uma op��o: ");
}

void grafo_selecao(){
    system("cls");
    printf("1 - Grafo 1.txt\n");
    printf("2 - Grafo 2.txt\n");
    printf("3 - Grafo 3.txt\n");
    printf("\nEscolha uma op��o: ");
}

void menu_propriedades(){
    system("cls");
    printf("\t[PROPRIEDADES]\n\n");
    printf("1 - Grau dos v�rtices\n");
    printf("2 - Ordem e Tamanho\n");
    printf("3 - Listar V�rtices/Arestas\n");
    printf("4 - N�mero de la�os (loops)\n");
    printf("0 - Sair\n");
    printf("\nEscolha uma op��o: ");
}
