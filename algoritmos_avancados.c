#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria a struct 'Sala'.
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Função que espera um ENTER para continuar o programa.
void pausar() {
    printf("\nPressione ENTER para prosseguir...");
        while(getchar() != '\n');
        getchar();
}

// Função que cria uma sala com um nome, 'strcpy' copia para a struct.
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*)
malloc(sizeof(Sala)); // Aloca memória para a nova sala.
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Função que conecta a sala "origem" com suas saídas esquerda/direita.
void conectarSala(Sala* origem, Sala* esquerda, Sala* direita) {
    if (origem != NULL) {
        origem->esquerda = esquerda;
        origem->direita = direita;
    }
}

// Função recursiva para explorar as salas.
void explorarSalas(Sala* atual) {
    char opcao;

    // Verifica se não é um lugar sem saída.
    if (atual == NULL) {
        printf("\nVocê chegou a um lugar sem saída.\n");
        pausar();
        return;
    }

    // Mostra onde o jogador está atualmente.
    printf("\nVocê está na sala: %s\n", atual->nome);
    printf("Digite (e) para esquerda, (d) para direita, (s) para sair: ");
    scanf(" %c", &opcao);

    // Comandos para o jogador explorar as salas, com sistemas de validação de escolha.
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
    // Criação das salas.
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sotão");
    Sala* jardim = criarSala("Jardim");

    // Conectando as salas para formar a arvore binária.
    conectarSala(hall, biblioteca, cozinha);
    conectarSala(biblioteca, sotao, NULL);
    conectarSala(cozinha, NULL, jardim);

    // Começa a exploração na sala Hall de Entrada.
    explorarSalas(hall);

    // Libera a memória, evita problemas como vazamento de memória.
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(jardim);

    return 0;
}