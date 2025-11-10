#include "list/list.h"
#include "string/myString.h"
#include "pair/pairStringToList.h"

#define LIST_AMOUNT 5

void editListLoop(pairSToL pairs[LIST_AMOUNT], size_t index);
void printMenu();
void printSelectListMenu(pairSToL pairs[LIST_AMOUNT]);
int writeListToFile(const taskList* this, const char* fileName);

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
            printf("Current tasks in list %s:\n", pairs[index].first.str);
            print_list(&pairs[index].second);

            if (0 == pairs[index].second.length) {
                printf("No tasks to move\n");
                break;
            }
            

            printf("Select the task position to remove.\n");
            size_t movedTask = -1;
            while (movedTask > pairs[index].second.length || movedTask == 0) {
                printf("Please enter a valid task position (1 to %d): ", 
                    pairs[index].second.length);
                scanf(" %d", &movedTask);
                while (getchar() != '\n'); // clear leftover '\n'
            }
            node* movedNode = popNode(&pairs[index].second, movedTask - 1);

            printf("Select the list to move the task to:\n");
            printSelectListMenu(pairs);
            size_t chosenList = -1;
            while (chosenList > LIST_AMOUNT || chosenList == 0) {
                scanf(" %d", &chosenList);
                while (getchar() != '\n'); // clear leftover '\n'
            }

            pushNodeBack(&pairs[chosenList - 1].second, movedNode);
            printf("The task %s has been moved from list %s to list %s.\n", 
                movedNode->str.str, pairs[index].first.str, 
                pairs[chosenList - 1].first.str);

            break;
        case 4: // Remove Task
            printf("Current tasks in list %s:\n", pairs[index].first.str);
            print_list(&pairs[index].second);

            if (0 == pairs[index].second.length) {
                printf("No tasks to remove\n");
                break;
            }

            printf("Select the task position to remove.\n");
            size_t removedTask = -1;
            while (removedTask > pairs[index].second.length || removedTask == 0) {
                printf("Please enter a valid task position (1 to %d): ", 
                    pairs[index].second.length);
                scanf(" %d", &removedTask);
                while (getchar() != '\n'); // clear leftover '\n'
            }

            string removedStr = erase(&pairs[index].second, removedTask - 1);
            printf("The task %s has been removed from the list %s.\n", 
                removedStr.str, pairs[index].first.str);
            deleteString(&removedStr);

            break;
        case 5: { // Write to File
            string fileName = copyString(&pairs[index].first);
            appendChars(&fileName, ".txt");

            writeListToFile(&pairs[index].second, fileName.str);

            printf("The list %s has been written to file %s.\n", 
                pairs[index].first.str, fileName.str);

            deleteString(&fileName);
            break;
        } case 6: // Read from File
            printf("Feature not implemented yet.\n");
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

int writeListToFile(const taskList *this, const char *fileName) {
    // Open the file for writing
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file %s for writing.\n", fileName);
        return -1;
    }

    // Write each task to the file
    node* current = this->head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->str.str);
        current = current->next;
    }

    fclose(file);
    return 0;
}

void printMenu() {
    printf("Please choose one of the following options to continue\n");
    printf("1. Print tasks\n");
    printf("2. Add task\n");
    printf("3. Move Task\n");
    printf("4. Remove task\n");
    printf("5. Write to File\n");
    printf("6. Read from File (Not implemented)\n");
    printf("0. Choose a different list\n");
}
