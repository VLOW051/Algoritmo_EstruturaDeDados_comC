#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 
  void *pBuffer = malloc(sizeof(int)* 2);
  
  *(int*)pBuffer = 0 ; 
  *((int*)pBuffer + 1) = 0;


  int opcao;
  do {
    printf("===== MENU =====\n");
    printf("1- Adicionar Pessoa (Nome, Idade, email)\n");
    printf("2- Remover Pessoa\n");
    printf("3- Buscar Pessoa\n");
    printf("4- Listar todos\n");
    printf("5- Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (*(int*)pBuffer = 0 ;) {
      case 1
        // Adicionar Pessoa
        break;
      case 2:
        // Remover Pessoa
        break;
      case 3:
        // Buscar Pessoa
        break;
      case 4:
        // Listar todos
        break;
      case 5:
        printf("Saindo...\n");
        break;
      default:
        printf("Opcao invalida!\n");
        break;
    }
  } while (*(int*)pBuffer = 0  != 5);
  