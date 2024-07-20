#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include "pss.h"

// Almacena la informacion de un archivo
typedef struct {
    char *path;
    time_t mtime;
} FileInfo;

// Funcion de comparacion
int compareFileInfoAdapter(void *ptr, int a, int b) {
    void **array = (void **)ptr;
    return compareFileInfo(array[a], array[b]);
}

int compareFileInfo(const void *a, const void *b) {
    FileInfo *fileA = *(FileInfo **)a;
    FileInfo *fileB = *(FileInfo **)b;
    return difftime(fileB->mtime, fileA->mtime);
}

// list-dir.c


void listDir(const char *path);

int main(int argc, char *argv[]) {
    Queue *fileQueue;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir = argv[1];
    int n = atoi(argv[2]);

    fileQueue = makeQueue();
    listDir(dir);

    int fileCount = queueLength(fileQueue);
    FileInfo **fileArray = malloc(fileCount * sizeof(FileInfo *));
    for (int i = 0; i < fileCount; i++) {
        fileArray[i] = get(fileQueue);
    }
    destroyQueue(fileQueue);

    sortPtrArray((void **)fileArray, 0, fileCount - 1, compareFileInfoAdapter);

    for (int i = 0; i < n && i < fileCount; i++) {
        printf("%s\n", fileArray[i]->path);
        free(fileArray[i]->path);
        free(fileArray[i]);
    }
    free(fileArray);

    return EXIT_SUCCESS;
}
