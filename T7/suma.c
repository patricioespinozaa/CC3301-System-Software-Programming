#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "suma.h"

typedef unsigned long long Set;

Set buscar(int a[], int n, int p) {
    int fd[p][2];                                       // Pipelines array; 1. para escribir, 0. para leer
    pid_t pids[p];                                      // Array de los PIDs de los procesos hijos

    for (int i = 0; i < p; i++) {                       // Crear p pipelines y p procesos hijos
        // Manejo de error
        if (pipe(fd[i]) == -1) {
            perror("pipe");
            exit(1);
        }

        pid_t pid = fork();                             // Crear un proceso hijo
        pids[i] = pid;                                  // Guarda el PID del hijo

        // Proceso hijo
        if (pid == 0) {
            close(fd[i][0]);                            // Cerrar el extremo de lectura del pipe en el hijo, el hijo solo escribe
            Set comb = (1<<(n-1)<<1)-1;                 // Cantidad de combinaciones de subconjuntos: 2^n - 1

            for (Set k = i + 1; k <= comb; k += p) {    // Dividir el trabajo entre hijos
                long long sum = 0;                      // Suma de los elementos del subconjunto
                for (int j = 0; j < n; j++) {           // Calcular la suma si el bit j está activado
                    if (k & ((Set)1 << j)) {
                        sum += a[j];
                    }
                }

                if (sum == 0) {                         // Si la suma es 0, devolver el subconjunto
                    write(fd[i][1], &k, sizeof(Set));
                    close(fd[i][1]);                    // Cerrar el extremo de escritura del pipe en el hijo
                    exit(0);                            // Terminar el proceso hijo
                }
            }
            close(fd[i][1]);                            // Cerrar el extremo de escritura del pipe en el hijo
            exit(0);                                    // Terminar el proceso hijo
        } else {
            close(fd[i][1]);                            // Cerrar el extremo de escritura del pipe en el padre
        }
    }

    // Proceso padre
    Set result = 0;                                     // Inicializa en 0 el resultado
    for (int i = 0; i < p; i++) {
        Set k;
        if (read(fd[i][0], &k, sizeof(Set)) > 0) {      // Si se puede leer del pipe, asignar el resultado a k
            result = k;
        }
        close(fd[i][0]);                                // Cerrar el extremo de lectura del pipe en el padre
        waitpid(pids[i], NULL, 0);                      // Esperar a que terminen los hijos
    }
    return result;
}

