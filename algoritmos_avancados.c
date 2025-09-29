#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

void pausar() {
    printf("\nPressione ENTER para prosseguir...");
        while(getchar() != '\n');
        getchar();
}

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
        printf("\nVocê chegou a um lugar sem saída.\n");
        pausar();
        return;
    }

    printf("\nVocê está na sala: %s\n", atual->nome);
    printf("Digite (e) para esquerda, (d) para direita, (s) para sair: ");
    scanf(" %c", &opcao);

    if (opcao == 's') {
        printf("\nSaindo da exploração...\n");
        return;
    } else if (opcao == 'e') {
        explorarSalas(atual->esquerda);
    } else if (opcao == 'd') {
        explorarSalas(atual->direita);
    } else {
        printf("\nOpção inválida!\n");
        pausar();
        explorarSalas(atual);
    }
}

int main() {
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sotão");
    Sala* jardim = criarSala("Jardim");

    conectarSala(hall, biblioteca, cozinha);
    conectarSala(biblioteca, sotao, NULL);
    conectarSala(cozinha, NULL, jardim);

    explorarSalas(hall);

    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(jardim);

    return 0;
}