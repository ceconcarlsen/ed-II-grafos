#include <time.h>
#include <string.h>

//Assinatura
void logger(FILE *f, int grafo);
/*#Parâmetros: Recebe um ponteiro para um FILE (arquivo que será escrito)
  e um int (grafo escolhido).

  #Imprime no log de processamneto a data/hora do inicio da execução
  e o grafo escolhido para a manipulaçao.

*/

//Implementação
void logger(FILE *f, int grafo){ //File f e tipo do grafo

    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    fprintf(f,"Data: %d/", data_hora_atual->tm_mday);//dia
    fprintf(f,"%d/",data_hora_atual->tm_mon+1); //mês
    fprintf(f,"%d",data_hora_atual->tm_year+1900); //ano
    fprintf(f,"\nHora: %d:",data_hora_atual->tm_hour);//hora
    fprintf(f,"%d:",data_hora_atual->tm_min);//minuto
    fprintf(f,"%d\n",data_hora_atual->tm_sec);//segundo

    fprintf(f,"Grafo escolhido: Grafo %i\n\n", grafo);//tipo de grafo
}
