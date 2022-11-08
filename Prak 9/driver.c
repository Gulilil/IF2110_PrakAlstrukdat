#include "boolean.h"
#include "list_circular.c"


int main () {
    List l;
    CreateList(&l);
    int n = 5;
    int i;
    int dump;
    Address p;

    displayList(l);
    insertFirst(&l, 7);
    displayList(l);
    insertFirst(&l, 8);
    insertFirst(&l, 5);
    insertLast(&l, 6);
    insertLast(&l, 9);
    displayList(l);
    printf("\n");
    // for (i = 0; i < n; i++){
    //     deleteLast(&l, &dump);
    //     displayList(l);printf("%d\n", dump);
    // }

    p = search(l, 12);
    if (p == NULL){
        printf("NULL\n");
    } else {
        printf("%d %d\n", INFO(p), INFO(NEXT(p)));
    }

    boolean test = addrSearch(l, p);
    if (test){
        printf("ada\n");
    } else {
        printf("ga ada\n");
    }

    return 0;
}