#include <stdio.h>
#include "listlinier.c"

int main () {
    List l;
    CreateList(&l);
    List k;
    CreateList(&k);
    List j;
    CreateList(&j);
    List m;
    CreateList(&m);
    int val;
    int search;
    int len;
    int test;

    insertFirst(&l, 4);
    insertFirst(&l, 5);
    insertFirst(&l, 9);
    insertAt(&l, 6, 1);
    insertFirst(&l, 7);
    insertLast(&l, 10);
    insertAt(&l, 8, 2);
    displayList(l);

    
    deleteAt(&l,2, &val);

    displayList(l);
    printf("%d\n", val);

    search = indexOf(l, 10);
    printf("%d\n", search);

    len = length(l);
    printf("%d\n", len);

    insertFirst(&k, 4);
    insertLast(&k, 10);
    insertLast(&k, 15);

    j = concat(k, l);
    displayList(j);

    insertLast(&m, 3);
    insertLast(&m, 4);
    deleteAt(&m, 0, &val);
    displayList(m);
    len = length(m);
    printf("%d\n", len);
    printf("%d\n", val);

    test = getElmt(l, 3);
    printf("%d\n", test);

    setElmt(&k, 2, 9);
    displayList(k);


    return 0;
}