#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;

  } pessoas_1 ;

  
  

int main() {



  printf("Digite o nome da pessoa: ");
      fgets(pessoas_1.nome, sizeof(pessoas_1.nome), stdin);
      size_t len = strlen(pessoas_1.nome);
         if (len > 0 && pessoas_1.nome[len-1] == '\n') {
        pessoas_1.nome[len-1] = '\0';
    }

  printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoas_1.idade);

}