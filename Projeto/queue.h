// Structs
struct node{
    int value;
    struct node* prox;
};

struct queue{
    struct node* first;
    struct node* last;
};

//Assinaturas
void inicializa_queue(struct queue* x);
//Par�metros: estrutura queue
void queue_insert(struct queue* x, int element);
//Par�metros: estrutura queue, elemento inserido na fila
struct node* queue_remove(struct queue* x);
//Par�metros: estrutura queue

void inicializa_queue(struct queue* x){
    x->first = NULL;
    x->last = NULL;
}

int is_vazia(struct queue*x){// � vazia
    if(x->first == NULL){ //Se o ponteiro para o primeiro n� for null, ent�o � vazia
        return 1;
    }
    else return 0;
}

void queue_insert(struct queue* x, int element){//Inser��o
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("[ERRO]: Mem�ria insuficiente!");
        exit(1);
    }

    new_node->value = element;
    new_node->prox = NULL;


    if(x->first == NULL)
        x->first = new_node;
    else
        x->last->prox = new_node;

    x->last = new_node;
}

struct node* queue_remove(struct queue* x){//Remo��o
    if((x == NULL) || (x->first == NULL)){
        printf("\n\nFila Vazia\n\n");
        return NULL;
    }

    struct node* temp = x->first;
    x->first = x->first->prox;

    if(x->first == NULL){
        x->last = NULL;
    }
    return temp;
}

void print_queue(struct queue* x){//Print
    struct node* percorre = x->first;
    while(percorre != NULL){
        printf("%d  ", percorre->value);
        percorre = percorre->prox;
    }
}
