#include <stdio.h>
#include <string.h>
#define MAX 50 

int scoreOfString(char* s);

int main (){

  char str[MAX], *s;
  s = str;

  printf("Digite uma string: ");
  fgets(s, MAX, stdin);
  int teste = s[1] + s[2]; 

  printf("%d\n ", teste);


  printf("Score da string: %d\n", scoreOfString(s) );

  return 0;
}

int scoreOfString(char* s)  {
    
    int score = 0  ;

    size_t len = strlen(s);

    for( size_t i = 0 ; i < len - 1 ; i++){

      int soma = 0 ;

      soma = s[i] - s[i+1]; 
      score += soma; 

  }
    
    return score; 

} 