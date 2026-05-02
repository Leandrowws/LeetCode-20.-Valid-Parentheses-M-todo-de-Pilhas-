#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char* s) {

    int i = 0;

    typedef struct no {
        char parenteses;
        struct no *prox;
    } No;

    typedef struct {
        No *topo;
    } Pilha;

    Pilha pilha;
    pilha.topo = NULL;

    while(s[i] != '\0') {

        if( s[i] == '(' ||  s[i] == '{' || s[i]== '[' ) {

            No *novo = (No*)malloc(sizeof(No));

            novo->parenteses = s[i];
            novo->prox = pilha.topo;
            pilha.topo = novo; 

        } else {

            if(pilha.topo == NULL) return false;

            char topo = pilha.topo->parenteses;

            if( s[i] == ')' && topo != '(' ||
                s[i] == ']' && topo != '[' || 
                s[i] == '}' && topo != '{')  {
                    return false;
                }
           
            No *aux = pilha.topo;
            pilha.topo = aux->prox;
            free(aux);
        }


        i++;
    }


    return pilha.topo == NULL;
}

int main() {
    
    char string[7] = {'(', ')', '{', '}', '[', ']', '\0'};


    if(isValid(string)) {
        printf("Valido");
    } else {
        printf("Invalido");
    }

    return 0;
}
