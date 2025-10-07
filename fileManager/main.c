#include "fileManager.h"
#include "../list/list.h"

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
        dropEOL(fm.line);
        push_back(&list, fm.line);
    }

    printf("todo list is: ");
    print_list(&list);

    // close file
    fclose(fm.fp);
    if (fm.line)
        free(fm.line);

    return 0;
}