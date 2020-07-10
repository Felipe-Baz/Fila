/* Programa: Lab 6
Autor: Felipe Baz Mitsuishi
Versao: 1.0 - 01/10/2019
*/
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>
// ########################## TAD X.h ######################################
struct Fila{
    int primeiro;
    int ultimo;
    int elementos[100];
};
typedef struct Fila tipoFilaSC;

void inicializafila(tipoFilaSC *filaAux){
    int i;
    filaAux->primeiro = -1;
    filaAux->ultimo = -1;
    for (i = 0; i < 100; i++)
        filaAux->elementos[i] = 0;
}

int filaCheia(tipoFilaSC *filaAux){
    if(((filaAux->ultimo+1)%100)==filaAux->primeiro)
        return 1; //Cheia
    else return 0;//Não esta cheia
}

void insere(tipoFilaSC *filaAux, int element){
    if (filaAux->primeiro == -1 && filaAux->ultimo == -1){
        filaAux->elementos[0] = element;
        filaAux->primeiro = 0;
        filaAux->ultimo = 0;
    }else{
        filaAux->elementos[(filaAux->ultimo + 1) % 100] = element;
        filaAux->ultimo = (filaAux->ultimo + 1) % 100;
    }
}

void removefirst(tipoFilaSC *filaAux){
    if (filaAux->primeiro == filaAux->ultimo){ //unico e primeiro
        filaAux->elementos[filaAux->primeiro] = 0;
        filaAux->primeiro = -1;
        filaAux->ultimo = -1;
    }else{ //primeiro
        filaAux->elementos[filaAux->primeiro] = 0;
        filaAux->primeiro = (filaAux->primeiro + 1) % 100;
    }
}

void Printa(tipoFilaSC *filaAux){
    int i;
    for (i = filaAux->ultimo; i > filaAux->primeiro; i = ((100 + i) - 1) % 100){
        printf("%d ", filaAux->elementos[i]);
    }
    printf("%d\n", filaAux->elementos[filaAux->primeiro]);
}
// ###################### Funcoes e Procedimentos do programa ###############
// ############################ Principal ###################################

int main(){
    int OP, i, num, quant;
   tipoFilaSC MyList;
   inicializafila(&MyList);
   scanf("%d", &quant);
   for (i = 0; i < quant; i++) {
       scanf("%d", &OP);
       if (OP == 1){
            if(filaCheia(&MyList)) {
                printf("A fila está vazia\n");
            }else{
                scanf("%d", &num);
                insere(&MyList, num);
            }
       }else if(OP == 2)
       {
           if (MyList.primeiro == -1 && MyList.ultimo == -1)
           {
               printf("A fila está vazia\n");
           }else{
               removefirst(&MyList);
           }
       }
       else{

           if (MyList.primeiro == -1 && MyList.ultimo == -1)
           {
               printf("A fila está vazia\n");
           }
           else
           {
               num = MyList.elementos[MyList.primeiro];
               removefirst(&MyList);
               insere(&MyList, num);
           }          
       }
   }
   Printa(&MyList);
   return 0;
}
