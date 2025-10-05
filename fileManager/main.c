#include "fileManager.h"

int main() {
    fileManager fm = {0, 0, 0, 0};
    taskList list = empty_list();

    // open file
    fm.fp = fopen("..\\TODOs.txt", "r");
    if (NULL == fm.fp) {
        printf("couldn't open file\n");
        exit(EXIT_FAILURE);
    }
    
    // move line by line
    while (fm.read = getline(&fm.line, &fm.len, fm.fp) != -1) {
        printf("Retrieved line of lend %i: \n", fm.read);
        printf("%s", fm.line);
    }

    // close file
    fclose(fm.fp);
    if (fm.line)
        free(fm.line);

    return 0;
}