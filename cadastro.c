#include <stdio.h>
#include <string.h>

int main() {

    struct Musica {
        int id;
        char nome[50];
        char artista[50];
        int duracao;
    };

    struct Musica musicas[10];
    int qtd = 0;
    int opcao;

    do {

        printf("\n==============================\n");
        printf("       APP DE MUSICAS\n");
        printf("==============================\n");
        printf("1 - Cadastrar musica\n");
        printf("2 - Listar musicas\n");
        printf("3 - Buscar musica\n");
        printf("4 - Atualizar musica\n");
        printf("5 - Remover musica\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while(getchar() != '\n');
            opcao = -1;
            continue;
        }

        if (opcao == 1) {

            if (qtd >= 10) {
                printf("Limite atingido!\n");
                continue;
            }

            int novoId, existe = 0;

            printf("ID: ");
            scanf("%d", &novoId);

            for (int i = 0; i < qtd; i++) {
                if (musicas[i].id == novoId) {
                    existe = 1;
                }
            }

            if (existe) {
                printf("ID ja existe!\n");
                continue;
            }

            musicas[qtd].id = novoId;

            printf("Nome: ");
            scanf(" %[^\n]", musicas[qtd].nome);

            printf("Artista: ");
            scanf(" %[^\n]", musicas[qtd].artista);

            printf("Duracao: ");
            scanf("%d", &musicas[qtd].duracao);

            qtd++;
        }

    } while (opcao != 0);

    return 0;
}