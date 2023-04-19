#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char *argv[]) {
   FILE *arquivo;
    printf("Lendo o arquivo: :%s \n",argv[1]);
   arquivo = fopen (argv[1], "r");
   if (arquivo == NULL) {
      printf ("\nArquivo não encontrado!\n");
      exit (EXIT_FAILURE);
   }  
  char c; 
  c = fgetc(arquivo);
  while (c != EOF){
    printf("%c",c);
    c = fgetc(arquivo);
  }
   fclose (arquivo);
   return EXIT_SUCCESS;
}
