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
            printf("Cadastrar musica\n");
        }

    } while (opcao != 0);

    return 0;
}