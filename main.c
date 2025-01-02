#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include <string.h>

#define MAX 20

void main(){
    struct No *raiz = NULL;
    char opcao;
    char *escolha;
    int valor;
    char vaux[MAX];
    while(fgets(vaux, MAX, stdin) != NULL)
    {
        opcao = vaux[0];
        escolha = malloc(sizeof(char)*(MAX-2));
        memcpy(escolha, vaux+2, MAX-2);
        valor = atoi(escolha);
        if(opcao == 'i')
            raiz = insere(raiz, valor);
        if(opcao == 'r')
            raiz = remover(raiz, valor);
        free(escolha);
    }
    emordem(raiz);
    return;
}
