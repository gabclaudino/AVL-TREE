#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
 
struct No
{
    int chave;
    struct No *esq;
    struct No *dir;
    int altura;
};
 
int altura_t(struct No *n){
    if(n==NULL)
        return 0;
    return n->altura;
}
 
struct No *cria_No(int chave){
    struct No* no = (struct No *) malloc(sizeof(struct No));
    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;
    return no;
}
 
int maior (int a, int b){
    if(a>b)
        return a;
    return b;
}
 
int FatDeBalanc(struct No * n){
    if(n==NULL)
        return 0;
    return altura_t(n->esq) - altura_t(n->dir);
}
 
struct No* rot_dir(struct No* y){
    struct No* x = y->esq;
    struct No* T2 = x->dir;
    x->dir = y;
    y->esq = T2;
    x->altura = maior(altura_t(x->dir), altura_t(x->esq)) + 1;
    y->altura = maior(altura_t(y->dir), altura_t(y->esq)) + 1;
    return x;
}
 
struct No* rot_esq(struct No* x){
    struct No* y = x->dir;
    struct No* T2 = y->esq;
    y->esq = x;
    x->dir = T2;
    x->altura = maior(altura_t(x->dir), altura_t(x->esq)) + 1;
    y->altura = maior(altura_t(y->dir), altura_t(y->esq)) + 1;
    return y;
}
 
struct No *insere(struct No* no, int chave){
    if (no == NULL)
        return  cria_No(chave);
    if (chave < no->chave)
        no->esq  = insere(no->esq, chave);
    else if (chave > no->chave)
        no->dir = insere(no->dir, chave);
    no->altura = 1 + maior(altura_t(no->esq), altura_t(no->dir));
    int fdb = FatDeBalanc(no);
    if(fdb>1 && chave < no->esq->chave)
        return rot_dir(no);
    if(fdb<-1 && chave > no->dir->chave)
        return rot_esq(no);
    if(fdb>1 && chave > no->esq->chave){
        no->esq = rot_esq(no->esq);
        return rot_dir(no);
    }
    if(fdb<-1 && chave < no->dir->chave){
        no->dir = rot_dir(no->dir);
        return rot_esq(no);
    }
    return no;
}

struct No *remover(struct No* no, int chave){
    if(no == NULL)
        return NULL;
    else
    {
        if (no->chave == chave)
        {
            if(no->esq == NULL && no->dir == NULL)
            {
                free(no);
                return NULL;
            }
            else
            {
                if(no->esq != NULL && no->dir != NULL)
                {
                    struct No *aux = no->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    no->chave = aux->chave;
                    aux->chave = chave;
                    no->esq = remover(no->esq, chave);
                    return no;
                }
                else
                {
                    struct No *aux;
                    if(no->esq != NULL)
                        aux = no->esq;
                    else    
                        aux = no->dir;
                    free(no);
                    return aux;
                }
            }
        }
        else
        {
            if(chave < no->chave)   
                no->esq = remover(no->esq, chave);
            else
                no->dir = remover(no->dir, chave);
        }
    }
    no->altura = maior(altura_t(no->esq), altura_t(no->dir)) + 1;
    int fdb = FatDeBalanc(no);
    if(fdb>1 && chave < no->esq->chave)
        return rot_dir(no);
    if(fdb<-1 && chave > no->dir->chave)
        return rot_esq(no);
    if(fdb>1 && chave > no->esq->chave){
        no->esq = rot_esq(no->esq);
        return rot_dir(no);
    }
    if(fdb<-1 && chave < no->dir->chave){
        no->dir = rot_dir(no->dir);
        return rot_esq(no);
    }
    return no;
}

void emordem(struct No *n){
    if(n != NULL)
    {
        emordem(n->esq);
        printf("%d,%d \n", n->chave, n->altura -1);
        emordem(n->dir);
    }
}
