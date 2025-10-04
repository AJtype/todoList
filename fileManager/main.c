#include "fileManager.h"

int main() {
    fileManager fm = {0, 0, 0, 0};

    printf("started program\n");

    fm.fp = fopen("..\\TODOs.txt", "r");
    if (NULL == fm.fp) {
        printf("couldn't open file\n");
        exit(EXIT_FAILURE);
    }
    
    while (fm.read = getline(&fm.line, &fm.len, fm.fp) != -1) {
        printf("Retrieved line of lend %i: \n", fm.read);
        printf("%s", fm.line);
    }

    fclose(fm.fp);
    if (fm.line)
        free(fm.line);

    return 0;
}