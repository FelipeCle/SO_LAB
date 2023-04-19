#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int fd[2];
pid_t pid;
int value = 5;

if (pipe(fd) == -1) { // criando pipe
    printf("Erro ao criar o pipe\n");
    return 1;
}

pid = fork();

if (pid == 0) { // processo filho
    close(fd[0]); // fechar a extremidade de leitura do pipe
    value += 15;
    write(fd[1], &value, sizeof(value)); // escrever o valor no pipe
    close(fd[1]); // fechar a extremidade de escrita do pipe
    return 0;
}
else if (pid > 0) { // processo pai
    close(fd[1]); // fechar a extremidade de escrita do pipe
    wait(NULL);
    read(fd[0], &value, sizeof(value)); // ler o valor do pipe
    close(fd[0]); // fechar a extremidade de leitura do pipe
    printf("PARENT: value = %d\n", value);
    return 0;
}
else { // erro ao criar processo filho
    printf("Erro ao criar processo filho\n");
    return 1;
}}
