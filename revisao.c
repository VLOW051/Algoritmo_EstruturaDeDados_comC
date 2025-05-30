#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_NOMES 10
#define MAX_BUFFER 100

int main() {
    setlocale(LC_ALL, "Portuguese");
    char **nomes = calloc(MAX_NOMES, sizeof(char*));
    char buffer[MAX_BUFFER];
    int opcao;
    int rodando = 1;

    while (rodando) {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir nome\n");
        printf("2 - Remover nome\n");
        printf("3 - Listar nomes\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d%*c", &opcao) != 1) { // %*c consome o ENTER
            printf("Opção inválida!\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado
            continue;
        }

        switch (opcao) {
            case 1: { // Inserir nome
                int pos = -1;
                for (int i = 0; i < MAX_NOMES; i++) {
                    if (nomes[i] == NULL) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Lista cheia! Não é possível inserir mais nomes.\n");
                    break;
                }
                printf("Digite o nome para inserir: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    size_t len = strlen(buffer);
                    if (len > 0 && buffer[len-1] == '\n') {
                        buffer[len-1] = '\0';
                        len--;
                    }
                    nomes[pos] = malloc((len + 1) * sizeof(char));
                    if (nomes[pos] != NULL) {
                        strcpy(nomes[pos], buffer);
                        printf("Nome inserido na posição %d.\n", pos+1);
                    }
                }
                break;
            }
            case 2: { // Remover nome
                int pos;
                printf("Digite o número do nome para remover (1 a %d): ", MAX_NOMES);
                if (scanf("%d%*c", &pos) != 1 || pos < 1 || pos > MAX_NOMES) {
                    printf("Posição inválida!\n");
                    while (getchar() != '\n');
                    break;
                }
                pos--; // Ajusta para índice do vetor
                if (nomes[pos] != NULL) {
                    free(nomes[pos]);
                    nomes[pos] = NULL;
                    printf("Nome removido da posição %d.\n", pos+1);
                } else {
                    printf("Nenhum nome nessa posição.\n");
                }
                break;
            }
            case 3: // Listar nomes
                printf("\nNomes cadastrados:\n");
                for (int i = 0; i < MAX_NOMES; i++) {
                    if (nomes[i] != NULL) {
                        printf("%d - %s\n", i+1, nomes[i]);
                    }
                }
                break;
            case 4: // Sair
                rodando = 0;
                break;
            default:
                printf("Opção inválida!\n");
        }
    }

    // Libera memória
    for (int i = 0; i < MAX_NOMES; i++) {
        if (nomes[i] != NULL) {
            free(nomes[i]);
        }
    }
    free(nomes);
    printf("Programa encerrado.\n");
    return 0;
}