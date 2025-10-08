#include "fileManager/fileManager.h"

void mainLoop(taskList* tasks, taskList* done);
void printMenu();

int main() {
    taskList tasks = empty_list();
    taskList done = empty_list();

    // TODO: read from files

    mainLoop(&tasks, &done);

    clear(&tasks);
    clear(&done);
}

void mainLoop(taskList* tasks, taskList* done) {
    printf("Welcome to your todo list manager\n");
    size_t choice = -1;
    char taskName[50];
    while (choice != 0) {
        printMenu();

        scanf(" %d", &choice);
        while (getchar() != '\n'); // clear leftover '\n'

        switch (choice) {
        case 0: // Exit
            break;
        case 1: // Print Tasks
            print_list(tasks);
            break;
        case 2: // Add Task
            printf("Name the task: ");

            scanf(" %s", &taskName);
            while (getchar() != '\n'); // clear leftover '\n'

            printf("The task %s has been added\n");

            push_back(tasks, taskName);
            break;
        default:
            printf("Invalid input, please try again\n");
            break;
        }
        printf("\n");
    }
    printf("Goodbye");
}

void printMenu() {
    printf("Please choose one of the following options to continue\n");
    printf("1. Print tasks\n");
    printf("2. Add task\n");
    printf("3. Mark task as done\n");
    printf("4. Remove task\n");
    printf("5. Print done tasks\n");
    printf("0. Exit\n");
}
