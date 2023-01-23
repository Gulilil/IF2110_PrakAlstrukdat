

#include <stdio.h>
#include <stdlib.h>
#include "listrec.c"


int main () {
    int len;

    List l = newNode(5);
    if (isOneElmt(l)){
        printf("satu\n");
    }
    List l1 = konso(l, 5);
    List l2 = konso(l1, 4);
    List l3 = konsb(l2, 7);

    len = length(l3);
    printf("%d ========= \n", len);

    displayList(l3);

    if (isMember(l3, 9)){
        printf("test\n");
    } else {
        printf("xixixi\n");
    }

    printf("-----------------\n");
    List l4 = copy(l3);
    displayList(l4);

    List l5 = newNode(5);
    l5 = konso(l5, 7);
    l5 = konso(l5, 8);


    printf("-----------------\n");
    List l6 = concat(l4, l5);
    displayList(l6);

    return 0;

}