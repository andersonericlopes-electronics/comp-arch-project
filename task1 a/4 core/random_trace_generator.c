#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define MAX_TRACES 1000
#define MAX_NAME_LEN 256

int main() {
    DIR *dir;
    struct dirent *entry;

    char traces[MAX_TRACES][MAX_NAME_LEN];
    int count = 0;

    dir = opendir("dpc3_traces");

    if (dir == NULL) {
        printf("Error: Cannot open dpc3_traces directory.\n");
        return 1;
    }

    /* Read all .xz files */
    while ((entry = readdir(dir)) != NULL) {
        char *ext = strrchr(entry->d_name, '.');

        if (ext != NULL && strcmp(ext, ".xz") == 0) {
            strcpy(traces[count], entry->d_name);
            count++;
        }
    }

    closedir(dir);

    if (count < 4) {
        printf("Error: Less than 4 trace files found.\n");
        return 1;
    }

    /* Seed random number generator */
    srand((unsigned int)time(NULL));

    /* Fisher-Yates shuffle */
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char temp[MAX_NAME_LEN];
        strcpy(temp, traces[i]);
        strcpy(traces[i], traces[j]);
        strcpy(traces[j], temp);
    }

    printf("=========================================\n");
    printf(" Randomly Selected Traces for 4-Core Run\n");
    printf("=========================================\n");

    for (int i = 0; i < 4; i++) {
        printf("Core %d : %s\n", i, traces[i]);
    }

    return 0;
}