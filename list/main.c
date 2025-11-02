#include "list.h"

// constructor tests
void check_copyConstructor();
void check_operatorEqual();

// getter setter tests
void check_print_list();
void check_erase();
void check_unique();
void check_swap();
void check_popNode();

// funcs
void check_sort();
void check_merge();


int main() {
    check_print_list();

    check_erase();

    check_popNode();

    return 0;
}

void check_print_list() {
    taskList list = empty_list();

    push_front(&list, "lesson");
    push_back(&list, "breakfast");
    push_front(&list, "ride");

    printf("print list = ");
    print_list(&list);

    clear(&list);

    printf("list after clear = ");
    print_list(&list);

    string popped = pop_front(&list);
    if (0 != strcmp(popped.str, "-1")) {
        printf("deleting the string: \"%s\"\n", popped.str);
        free(popped.str);
    }

    printf("list after pop again = ");
    print_list(&list);

    clear(&list);
}

void check_erase() {
    taskList list = empty_list();
    
    printf("\n---testing erase func---\n");

    push_back(&list, "1");
    push_back(&list, "2");
    push_back(&list, "3");
    push_back(&list, "4");
    push_back(&list, "5");
    push_back(&list, "6");
    push_back(&list, "7");
    push_back(&list, "8");
    push_back(&list, "9");
    push_back(&list, "10");
    push_back(&list, "11");

    printf("len = %d\t", list.length);
    printf("pre-erase list = ");
    print_list(&list);
    
    printf("len = %d\t", list.length);
    printf("post-erase front list = ");
    erase(&list, 0);
    print_list(&list);

    printf("len = %d\t", list.length);
    printf("post-erase front again list = ");
    erase(&list, 0);
    print_list(&list);
    
    printf("len = %d\t", list.length);
    printf("post-erase second list = ");
    erase(&list, 1);
    print_list(&list);

    printf("len = %d\t", list.length);
    printf("post-erase before last list = ");
    erase(&list, 6);
    print_list(&list);

    printf("len = %d\t", list.length);
    printf("post-erase last list = ");
    erase(&list, 6);
    print_list(&list);

    printf("len = %d\t", list.length);
    printf("post-erase last list = ");
    erase(&list, 6);
    print_list(&list);

    clear(&list);

    printf("\n---end of erase test---\n");
}

void check_popNode() {
    taskList list = empty_list();
    node* popped = NULL;
    
    printf("\n---testing popNode func---\n\n");

    printf("poping 0 and 1 on an empty list\tlist->len = %d\n", list.length);
    popNode(&list, 0);
    popNode(&list, 1);

    printf("\npushing 2 items than popping front of both\n");
    push_back(&list, "1");
    push_back(&list, "2");

    popped = popNode(&list, 0);
    printf("popped string = %s\n", popped->str.str);
    free(popped); popped = NULL;
    popped = popNode(&list, 0);
    printf("popped string = %s\n", popped->str.str);
    free(popped); popped = NULL;

    printf("\npushing 2 items than popping back of both\n");
    push_back(&list, "1");
    push_back(&list, "2");

    popped = popNode(&list, 1);    
    printf("popped string = %s\n", popped->str.str);
    free(popped); popped = NULL;
    popped = popNode(&list, 0);
    printf("popped string = %s\n", popped->str.str);
    free(popped); popped = NULL;

    printf("\npushing 3 items than popping middle\n");
    push_back(&list, "1");
    push_back(&list, "2");
    push_back(&list, "3");

    popped = popNode(&list, 1);    
    printf("popped string = %s\n", popped->str.str);
    free(popped); popped = NULL;

    printf("list = ");
    print_list(&list);

    popped = popNode(&list, 1);    
    printf("popped string = %s\n", popped->str.str);
    free(popped); popped = NULL;
    printf("popped back\tlist = ");
    print_list(&list);

    clear(&list);

    printf("\n---end of popNode test---\n");
}

/*void check_copyConstructor() {
    list<int> l;

    std::cout << "\n---testing copy constructor func---" << std::endl;

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    list<int> copiedList = l;
    std::cout << "copiedList before deleting the original list = ";
    print_list(copiedList);

    l.clear();
    std::cout << "copiedList after deleting the original list = ";
    print_list(copiedList);

    std::cout << "---end of copy constructor test---\n" << std::endl;
}

void check_operatorEqual() {
    list<int> l;
    list<int> copiedList;

    std::cout << "\n---testing = func---" << std::endl;

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    copiedList = l;
    std::cout << "copiedList before deleting the original list = ";
    print_list(copiedList);

    l.clear();
    std::cout << "copiedList after deleting the original list = ";
    print_list(copiedList);

    l.emplace_back(1);
    l.emplace_front(4);

    copiedList = l;
    std::cout << "copied a shorted list = ";
    print_list(copiedList);

    copiedList = copiedList;
    std::cout << "copied the list into itself = ";
    print_list(copiedList);

    std::cout << "---end of = test---\n" << std::endl;
}

void check_clear() {
    list<int> l;
    
    std::cout << "\n---testing clear func---" << std::endl;

    std::cout << "empty list = ";
    print_list(l);

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    std::cout << "list = ";
    print_list(l);

    l.clear();
    std::cout << "cleared list = ";
    print_list(l);

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    std::cout << "list = ";
    print_list(l);

    std::cout << "---end of clear test---\n" << std::endl;
}

void check_unique() {
    list<int> l;
    
    std::cout << "\n---testing unique func---" << std::endl;

    l.emplace_back(1);
    l.emplace_back(1);
    l.emplace_back(2);
    l.emplace_back(2);
    l.emplace_back(2);
    l.emplace_back(3);
    l.emplace_back(2);
    l.emplace_back(1);
    l.emplace_back(1);
    l.emplace_back(2);
    l.emplace_back(2);

    std::cout << "pre-unique list = ";
    print_list(l);

    l.unique();
    std::cout << "post-unique list = ";
    print_list(l);

    std::cout << "---end of unique test---\n" << std::endl;
}

void check_swap() {
    list<int> list1;
    list<int> list2;
    
    std::cout << "\n---testing swap func---" << std::endl;

    list1.emplace_back(1);
    list1.emplace_back(2);
    list1.emplace_back(3);

    list2.emplace_back(4);
    list2.emplace_back(5);
    list2.emplace_back(6);

    std::cout << "pre-swapped list1 = ";
    print_list(list1);
    std::cout << "pre-swapped list2 = ";
    print_list(list2);
    
    list1.swap(list2);

    std::cout << "post-swapped list1 = ";
    print_list(list1);
    std::cout << "post-swapped list2 = ";
    print_list(list2);

    list1.emplace_front(3);
    list1.emplace_back(7);
    list2.emplace_front(0);
    list2.emplace_back(4);

    std::cout << "added 3 at beginning and 7 at the end list1 = ";
    print_list(list1);
    std::cout << "added 0 at beginning and 4 at the end list2 = ";
    print_list(list2);

    list2.swap(list1);

    std::cout << "post-swapped list1 = ";
    print_list(list1);
    std::cout << "post-swapped list2 = ";
    print_list(list2);

    list1.emplace_front(-1);
    list1.emplace_back(5);
    list2.emplace_front(2);
    list2.emplace_back(8);

    std::cout << "added -1 at beginning and 5 at the end list1 = ";
    print_list(list1);
    std::cout << "added 2 at beginning and 8 at the end list1 = ";
    print_list(list2);

    list1.swap(list1);
    std::cout << "swapped with self list1 = ";
    print_list(list1);

    std::cout << "---end of swap test---\n" << std::endl;
}

void check_sort() {
    list<int> list1;

    std::cout << "\n---testing sort func---" << std::endl;

    list1.emplace_back(11);
    list1.emplace_back(1);
    list1.emplace_back(31);
    list1.emplace_back(5);

    std::cout << "pre-sorted list1 = ";
    print_list(list1); // {11, 1, 31, 5}
    std::cout << "end = " << list1.back()  << "\tlen = " << list1.size() << std::endl;

    list1.sort();
    std::cout << "\npost-sort list1 = "; // should have all elements sorted
    print_list(list1); // {1, 5, 11, 31}
    std::cout << "end = " << list1.back()  << "\tlen = " << list1.size()  << std::endl;

    list1.emplace_front(0);
    list1.emplace_back(49);
    list1.emplace_back(101);

    std::cout << "\nadded 0 at the beginning and 49 and 101 at the end list1 = "; // list should still be sorted
    print_list(list1); // {0, 1, 5, 11, 31, 49, 101}

    list1.sort();
    std::cout << "post-sort list1 = "; // nothing should happen
    print_list(list1); // {0, 1, 5, 11, 31, 49, 101}
    std::cout << "end = " << list1.back() << "\tlen = " << list1.size() << std::endl;

    list1.emplace_front(5);
    list1.emplace_back(38);

    std::cout << "\nadded 5 at the beginning and 38 at the end list1 = "; // list should still be sorted
    print_list(list1); // {5, 0, 1, 5, 11, 31, 49, 101, 38}

    list1.sort();
    std::cout << "post-sort list1 = "; // sorted list after adding to it, also has the same element twice
    print_list(list1); // {0, 1, 5, 5, 11, 31, 38, 49, 101}
    std::cout << "end = " << list1.back() << "\tlen = " << list1.size() << std::endl;

    std::cout << "---end of merge test---\n" << std::endl;
}

void check_merge() {
    list<int> list1;
    list<int> list2;
    
    std::cout << "\n---testing merge func---" << std::endl;

    list2.emplace_back(10);
    list2.emplace_back(20);
    list2.emplace_back(30);

    // both lists must be sorted
    // list1.sort();
    // list2.sort();

    std::cout << "pre-merged list1 = ";
    print_list(list1); // {}
    std::cout << "len = " << list1.size() << std::endl;
    std::cout << "pre-merged list2 = ";
    print_list(list2); // {10, 20, 30}
    std::cout << "end = " << list2.back() << "\tlen = " << list2.size() << std::endl;
    
    std::cout << "\nmerged empty list with sorted list" << std::endl;
    list1.merge(list2); 
    std::cout << "post-merged list1 = "; // should have all elements sorted
    print_list(list1); // {10, 20, 30}
    std::cout << "end = " << list1.back() << "\tlen = " << list1.size() << std::endl;
    std::cout << "post-merged list2 = "; // should be empty
    print_list(list2); // {}
    std::cout << "len = " << list2.size() << std::endl;

    std::cout << "\nmerged list with empty list" << std::endl;
    list1.merge(list2);
    std::cout << "post-merged list1 = "; // should have all elements sorted
    print_list(list1); // {10, 20, 30}
    std::cout << "end = " << list1.back() << "\tlen = " << list1.size() << std::endl;
    std::cout << "post-merged list2 = "; // should be empty
    print_list(list2); // {}
    std::cout << "len = " << list2.size() << std::endl;

    list2.emplace_back(5);
    list2.emplace_back(6);
    list2.emplace_back(10);

    std::cout << "\nmerged list with low list" << std::endl;
    list1.merge(list2);
    std::cout << "post-merged list1 = "; // should have all elements sorted
    print_list(list1); // {5, 6, 7, 10, 20, 30}
    std::cout << "end = " << list1.back() << "\tlen = " << list1.size() << std::endl;
    std::cout << "post-merged list2 = "; // should be empty
    print_list(list2); // {}
    std::cout << "len = " << list2.size() << std::endl;

    list2.emplace_back(30);
    list2.emplace_back(32);
    list2.emplace_back(33);

    std::cout << "\nmerged list with high list" << std::endl;
    list1.merge(list2);
    std::cout << "post-merged list1 = "; // should have all elements sorted
    print_list(list1); // {5, 6, 7, 10, 20, 30, 30, 32, 33}
    std::cout << "end = " << list1.back() << "\tlen = " << list1.size() << std::endl;
    std::cout << "post-merged list2 = "; // should be empty
    print_list(list2); // {}
    std::cout << "len = " << list2.size() << std::endl;

    list2.emplace_back(20);
    list2.emplace_back(25);
    list2.emplace_back(31);

    std::cout << "\nmerged list with mid list" << std::endl;
    list1.merge(list2);
    std::cout << "post-merged list1 = "; // should have all elements sorted
    print_list(list1); // {5, 6, 7, 10, 20, 20, 25, 30, 30, 31, 32, 33}
    std::cout << "end = " << list1.back() << "\tlen = " << list1.size() << std::endl;
    std::cout << "post-merged list2 = "; // should be empty
    print_list(list2); // {}
    std::cout << "len = " << list2.size() << std::endl;

    std::cout << "---end of merge test---\n" << std::endl;
}
*/
