#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define qntDeThreads 5
#define verde "\033[32m"
#define vermelho "\x1b[31m"

int numGarfos = 5, garfos[] = {0, 0, 0, 0, 0};
pthread_mutex_t mutex;// Lock , para testar funções.
// Funções que vão ser usadas no programa
void pensar(int i);
void comer(int i);
void *rotina_filosofos(void *arg);

// Programa Principal
int main() {
    //Vetor dos filosofos como threads.
    pthread_t filosofos[qntDeThreads];
    pthread_mutex_init(&mutex,NULL);
    for (int i = 0; i < qntDeThreads; i++) {
        if (pthread_create(&filosofos[i], NULL, rotina_filosofos, (void *)(intptr_t)i) != 0) {
            printf("Erro ao criar thread\n");
        }
        printf("O filósofo %d sentou-se à mesa\n", i + 1);
    }
    // Join das threads , em for separado.
    for (int i = 0; i < qntDeThreads; i++) {
        if (pthread_join(filosofos[i], NULL) != 0) {
            printf("Erro ao dar join na thread\n");
        }
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}

// Filósofo realiza a ação de pensar
void pensar(int i) {
    sleep(2);
    printf(vermelho"\nO filósofo %d está pensado", i + 1);
    sleep(5);// Pensa por 5 segundos
}

//Desenvolvimento das funções.

// Função comer: envolve comer, pegar os garfos e deixar os garfos na mesa.
void comer(int i) {
    int garfosEmUso = 0; // Contabilizador de garfos na mão

    // Tenta pegar o garfo da esquerda
    pthread_mutex_lock(&mutex);
    if (garfos[i] == 0) {
        garfos[i] = i + 1;// Reserva o garfo da esquerda com o seu ID
        garfosEmUso += 1;// Incrementa numero de garfos
    }
    pthread_mutex_unlock(&mutex);

    // Tenta pegar o garfo da direita
    pthread_mutex_lock(&mutex);
    if (garfos[(i + 1) % numGarfos] == 0) {
        garfos[(i + 1) % numGarfos] = i + 1;// Reserva o garfo da direita com o seu ID
        garfosEmUso += 1;// Incrementa numero de garfos
    }
    pthread_mutex_unlock(&mutex);

    // Caso tenha 2 garfos, come e devolve para a mesa
    if (garfosEmUso == 2) {
        sleep(2);
        printf(verde"\nO filósofo %d está comendo", i + 1);
        sleep(5);
        // Devolve os garfos à mesa
        pthread_mutex_lock(&mutex);
        garfos[i] = 0;// Garfo da esquerda disponivel
        pthread_mutex_unlock(&mutex);

        pthread_mutex_lock(&mutex);
        garfos[(i + 1) % numGarfos] = 0;// Garfo da direita disponivel
        pthread_mutex_unlock(&mutex);
    }
    // Caso contrário, devolve os garfos à mesa
    else {
        pthread_mutex_lock(&mutex);
        garfos[i] = 0;// Garfo da esquerda disponivel
        pthread_mutex_unlock(&mutex);

        pthread_mutex_lock(&mutex);
        garfos[(i + 1) % numGarfos] = 0;// Garfo da direita disponivel
        pthread_mutex_unlock(&mutex);
    }
}

// Ações possíveis dos filosofos na mesa
void *rotina_filosofos(void *arg) {
    int i = (intptr_t)arg;
    while (1) {
        pensar(i);
        comer(i);
        printf("\n");
        }
}
