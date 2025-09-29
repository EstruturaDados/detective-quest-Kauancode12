#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    struct No* esquerda;
    struct No* direita;
} Sala;

Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*)
malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

void conectarSala(Sala* origem, Sala* esquerda, Sala* direita) {
    if (origem != NULL) {
        origem->esquerda = esquerda;
        origem->direita = direita;
    }
}

void explorarSalas(Sala* atual) {
    char opcao;

    if (atual == NULL) {
        printf("Você chegou a um lugar sem saída.\n");
        return;
    }

    printf("\nVocê está na sala: %s\n", atual->nome);
    printf("Digite (e) para esquerda, (d) para direita, (s) para sair: ");
    scanf(" %c", &opcao);

    if (opcao == 's') {
        printf("Saindo da exploração...\n");
        return;
    } else if (opcao == 'e') {
        explorarSalas(atual->esquerda);
    } else if (opcao == 'd') {
        explorarSalas(atual->direita);
    } else {
        printf("Opção inválida!\n");
        explorarSalas(atual);
    }
}

int main() {
    
}