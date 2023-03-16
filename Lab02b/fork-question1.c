#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int fd[2];
pid_t pid;
int value = 5;

if (pipe(fd) == -1) { // creating pipe
  printf("Error creating pipe\n");
  return 1;
}

pid = fork();

if (pid == 0) { // child process
  close(fd[0]); // close read end of pipe
  value += 15;
  write(fd[1], &value, sizeof(value)); // write value to pipe
  close(fd[1]); // close write end of pipe
  return 0;
}
else if (pid > 0) { // parent process
  close(fd[1]); // close write end of pipe
  wait(NULL);
  read(fd[0], &value, sizeof(value)); // read value from pipe
  close(fd[0]); // close read end of pipe
  printf("PARENT: value = %d\n", value);
  return 0;
}
  else { // error creating child process
  printf("Error creating child process\n");
  return 1;
}}
