#include "fileManager/fileManager.h"
#include "list/list.h"
#include "string/myString.h"
#include "pair/pairStringToList.h"

#define LIST_AMOUNT 5

void editListLoop(pairSToL pairs[LIST_AMOUNT], size_t index);
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
        printf("0. Exit\n");
        
        scanf(" %d", &choice);
        while (getchar() != '\n'); // clear leftover '\n'

        if (choice <= 0 || choice > LIST_AMOUNT) {
            continue;
        } 
        editListLoop(pairs, choice - 1);
    }
    printf("Goodbye");

    for (size_t i = 0; i < 5; i++) {
        deletePair(&pairs[i]);
    }
}

void editListLoop(pairSToL pairs[LIST_AMOUNT], size_t index) {
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
            print_list(&pairs[index].second);
            break;
        case 2: // Add Task
            printf("Name the task: ");

            scanf(" %s", &taskName);
            while (getchar() != '\n'); // clear leftover '\n'

            push_back(&pairs[index].second, taskName);

            printf("The task %s has been added\n");
            break;
        case 3: // Move Task
            print_list(&pairs[index].second);

            size_t chosenList = -1;
            while (chosenList > LIST_AMOUNT || chosenList == 0) {
                scanf(" %d", &chosenList);
                while (getchar() != '\n'); // clear leftover '\n'
            }

            node* movedNode = popNode(&pairs[index].second, chosenList - 1);

            // push_back(&pairs[chosenList - 1].second, movedNode->str.str); // TODO: replace with pushNode
            free(movedNode);
            printf("The task has been moved\n");

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
    }
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
