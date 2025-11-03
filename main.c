#include "fileManager/fileManager.h"
#include "list/list.h"
#include "string/myString.h"
#include "pair/pairStringToList.h"

#define LIST_AMOUNT 5

void editListLoop(taskList* tasks);
void printMenu();
void printSelectListMenu(pairSToL pairs[LIST_AMOUNT]);

int main() {
    pairSToL pairs[5] = {createPair("Work"), 
        createPair("Personal"), createPair("Shopping"),
        createPair("Chores"), createPair("Done")};

    // TODO: read from files

    size_t choice = -1;
    while (choice != 0) {
        printSelectListMenu(pairs);
        
        scanf(" %d", &choice);
        while (getchar() != '\n'); // clear leftover '\n'

        if (choice <= 0 || choice > LIST_AMOUNT) {
            continue;
        } 
        editListLoop(&pairs[choice - 1].second);
    }
    printf("Goodbye");

    for (size_t i = 0; i < 5; i++) {
        deletePair(&pairs[i]);
    }
}

void editListLoop(taskList* tasks) {
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
}

void printSelectListMenu(pairSToL pairs[LIST_AMOUNT]) {
    printf("Please choose one of the following lists:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("%zu. %s\n", i + 1, pairs[i].first.str);
    } printf("0. Exit\n");
}

void printMenu() {
    printf("Please choose one of the following options to continue\n");
    printf("1. Print tasks\n");
    printf("2. Add task\n");
    printf("3. Move Task\n");
    printf("4. Mark task as done\n");
    printf("5. Remove task\n");
    printf("6. Print done tasks\n");
    printf("0. Choose a different list\n");
}
