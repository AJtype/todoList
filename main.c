#include "fileManager/fileManager.h"

void printMenu(taskList* tasks, taskList* done);

int main() {
    taskList tasks = empty_list();
    taskList done = empty_list();
    printMenu(&tasks, &done);
}

void printMenu(taskList* tasks, taskList* done) {
    printf("Welcome to your todo list manager\n");
    size_t choice = 0;
    char taskName[50];
    while (choice != 6) {
        printf("Please choose one of the following options to continue\n");
        printf("1. Print tasks\n");
        printf("2. Add task\n");
        printf("3. Mark task as done\n");
        printf("4. Remove task\n");
        printf("5. Print done tasks\n");
        printf("6. Exit\n");

        scanf(" %d", &choice);
        while (getchar() != '\n'); // clear leftover '\n'

        switch (choice) {
        case 1:
            print_list(tasks);
            break;
        case 2:
            printf("Name the task: ");

            scanf(" %s", &taskName);
            while (getchar() != '\n'); // clear leftover '\n'

            printf("The task %s has been added\n");

            push_back(tasks, taskName);
            break;
        case 6:
            break;
        default:
            printf("Invalid input, please try again\n");
            break;
        }
        printf("\n");
    }
    printf("Goodbye");
}