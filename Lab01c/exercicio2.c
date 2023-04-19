#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  FILE *in_file, *out_file;
  char c;

  in_file = fopen(argv[1], "r");
  if (in_file == NULL) {
    printf("Erro ao abrir o arquivo de entrada.\n");
    exit (EXIT_FAILURE);
  }

  out_file = fopen(argv[2], "w");
  if (out_file == NULL) {
    printf("Erro ao criar o arquivo de saída.\n");
    exit (EXIT_FAILURE);
  }

  while ((c = fgetc(in_file)) != EOF) {
    fputc(c, out_file);
  }

  fclose(in_file);
  fclose(out_file);

  printf("Arquivo copiado com sucesso.\n");
  return EXIT_SUCCESS;
}
