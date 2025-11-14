#include <stdio.h>
#include <stdlib.h>

// =========================
// Estrutura da Sala (Nó)
// =========================
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// =========================
// Função para criar sala
// =========================
Sala* criarSala(char nome[]) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// =========================
// Explorar a mansão
// =========================
void explorarSalas(Sala *atual) {
    char opcao;

    if (atual == NULL) return;

    while (1) {
        printf("\nVocê está na sala: %s\n", atual->nome);

        // Caso seja nó-folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou ao fim do caminho! (Nó-folha)\n");
            return;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL) printf("  (e) Ir para a esquerda → %s\n", atual->esquerda->nome);
        if (atual->direita != NULL)  printf("  (d) Ir para a direita → %s\n", atual->direita->nome);
        printf("  (s) Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Não existe caminho para a esquerda!\n");

        } else if (opcao == 'd' || opcao == 'D') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Não existe caminho para a direita!\n");

        } else if (opcao == 's' || opcao == 'S') {
            printf("\nExploração encerrada.\n");
            return;

        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// =========================
// Montagem da Árvore (Mapa)
// =========================
Sala* montarMansao() {
    // Criando as salas (nós)
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *quarto1 = criarSala("Quarto 1");
    Sala *quarto2 = criarSala("Quarto 2");
    Sala *porao = criarSala("Porão");

    // Ligações da árvore
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = quarto1;
    salaEstar->direita = quarto2;

    cozinha->direita = porao;

    return hall;  // Raiz da árvore
}

// =========================
// Função principal
// =========================
int main() {
    Sala *raiz = montarMansao();

    printf("===== EXPLORADOR DA MANSÃO =====\n");

    explorarSalas(raiz);

    return 0;
}
