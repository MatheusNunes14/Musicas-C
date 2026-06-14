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
        printf("Musicas cadastradas: %d/10\n", qtd);
        printf("------------------------------\n");
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
                printf("Limite de 10 musicas atingido!\n");
                continue;
            }

            int novoId;
            int existe = 0;

            do {

                printf("ID (1 ate 9999): ");

                if (scanf("%d", &novoId) != 1) {
                    while(getchar() != '\n');
                    novoId = -1;
                }

                if (novoId <= 0 || novoId > 9999) {
                    printf("ID invalido! Digite um valor entre 1 e 9999.\n");
                }

            } while (novoId <= 0 || novoId > 9999);

            for (int i = 0; i < qtd; i++) {

                if (musicas[i].id == novoId) {
                    existe = 1;
                    break;
                }
            }

            if (existe) {
                printf("ID ja cadastrado!\n");
                continue;
            }

            musicas[qtd].id = novoId;

            do {
                printf("Nome: ");
                scanf(" %49[^\n]", musicas[qtd].nome);

                if (strlen(musicas[qtd].nome) == 0) {
                    printf("Nome nao pode ficar vazio!\n");
                }

            } while (strlen(musicas[qtd].nome) == 0);

            do {
                printf("Artista: ");
                scanf(" %49[^\n]", musicas[qtd].artista);

                if (strlen(musicas[qtd].artista) == 0) {
                    printf("Artista nao pode ficar vazio!\n");
                }

            } while (strlen(musicas[qtd].artista) == 0);

            do {

                printf("Duracao em segundos: ");

                if (scanf("%d", &musicas[qtd].duracao) != 1) {
                    while(getchar() != '\n');
                    musicas[qtd].duracao = -1;
                }

                if (musicas[qtd].duracao <= 0) {
                    printf("Duracao invalida! Digite apenas numeros positivos.\n");
                }

            } while (musicas[qtd].duracao <= 0);

            qtd++;

            printf("Musica cadastrada com sucesso!\n");
        }

        else if (opcao == 2) {

            if (qtd == 0) {
                printf("Nenhuma musica cadastrada!\n");
                continue;
            }

            printf("\n===== LISTA DE MUSICAS =====\n");
            printf("Total: %d musica(s)\n", qtd);

            for (int i = 0; i < qtd; i++) {

                int min = musicas[i].duracao / 60;
                int seg = musicas[i].duracao % 60;

                printf("\n-------------------------\n");
                printf("ID: %04d\n", musicas[i].id);
                printf("Nome: %s\n", musicas[i].nome);
                printf("Artista: %s\n", musicas[i].artista);
                printf("Duracao: %d:%02d\n", min, seg);
                printf("-------------------------\n");
            }
        }

        else if (opcao == 3) {

            if (qtd == 0) {
                printf("Nenhuma musica cadastrada!\n");
                continue;
            }

            int busca;
            int encontrado = 0;

            printf("Digite o ID: ");

            if (scanf("%d", &busca) != 1) {
                printf("Entrada invalida!\n");
                while(getchar() != '\n');
                continue;
            }

            for (int i = 0; i < qtd; i++) {

                if (musicas[i].id == busca) {

                    int min = musicas[i].duracao / 60;
                    int seg = musicas[i].duracao % 60;

                    printf("\n===== MUSICA ENCONTRADA =====\n");
                    printf("ID: %04d\n", musicas[i].id);
                    printf("Nome: %s\n", musicas[i].nome);
                    printf("Artista: %s\n", musicas[i].artista);
                    printf("Duracao: %d:%02d\n", min, seg);

                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Musica nao encontrada!\n");
            }
        }
                else if (opcao == 4) {

            if (qtd == 0) {
                printf("Nenhuma musica cadastrada!\n");
                continue;
            }

            int busca;
            int encontrado = 0;

            printf("Digite o ID da musica: ");

            if (scanf("%d", &busca) != 1) {
                printf("Entrada invalida!\n");
                while(getchar() != '\n');
                continue;
            }

            for (int i = 0; i < qtd; i++) {

                if (musicas[i].id == busca) {

                    int min = musicas[i].duracao / 60;
                    int seg = musicas[i].duracao % 60;

                    printf("\n===== MUSICA ATUAL =====\n");
                    printf("ID: %04d\n", musicas[i].id);
                    printf("Nome: %s\n", musicas[i].nome);
                    printf("Artista: %s\n", musicas[i].artista);
                    printf("Duracao: %d:%02d\n", min, seg);
                    printf("------------------------\n");

                    printf("Novo nome: ");
                    scanf(" %49[^\n]", musicas[i].nome);

                    printf("Novo artista: ");
                    scanf(" %49[^\n]", musicas[i].artista);

                    do {

                        printf("Nova duracao em segundos: ");

                        if (scanf("%d", &musicas[i].duracao) != 1) {
                            while(getchar() != '\n');
                            musicas[i].duracao = -1;
                        }

                        if (musicas[i].duracao <= 0) {
                            printf("Duracao invalida!\n");
                        }

                    } while (musicas[i].duracao <= 0);

                    printf("Musica atualizada com sucesso!\n");

                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("ID nao encontrado!\n");
            }
        }

        else if (opcao == 5) {

            if (qtd == 0) {
                printf("Nenhuma musica cadastrada!\n");
                continue;
            }

            int busca;
            int encontrado = 0;
            char confirmar;

            printf("Digite o ID da musica: ");

            if (scanf("%d", &busca) != 1) {
                printf("Entrada invalida!\n");
                while(getchar() != '\n');
                continue;
            }

            for (int i = 0; i < qtd; i++) {

                if (musicas[i].id == busca) {

                    int min = musicas[i].duracao / 60;
                    int seg = musicas[i].duracao % 60;

                    printf("\n===== MUSICA ENCONTRADA =====\n");
                    printf("ID: %04d\n", musicas[i].id);
                    printf("Nome: %s\n", musicas[i].nome);
                    printf("Artista: %s\n", musicas[i].artista);
                    printf("Duracao: %d:%02d\n", min, seg);
                    printf("-----------------------------\n");

                    printf("Remover \"%s\"? (S/N): ", musicas[i].nome);
                    scanf(" %c", &confirmar);

                    if (confirmar == 'S' || confirmar == 's') {

                        for (int j = i; j < qtd - 1; j++) {
                            musicas[j] = musicas[j + 1];
                        }

                        qtd--;

                        printf("Musica removida com sucesso!\n");
                    }
                    else {
                        printf("Remocao cancelada.\n");
                    }

                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("ID nao encontrado!\n");
            }
        }

        else if (opcao == 0) {
            printf("Encerrando aplicativo...\n");
        }

        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}