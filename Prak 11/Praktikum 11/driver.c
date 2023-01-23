

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

    //displayList(l3);

    if (isMember(l3, 9)){
        printf("test\n");
    } else {
        printf("xixixi\n");
    }

    printf("-----------------\n");
    List l4 = copy(l3);
    //displayList(l4);

    List l5 = newNode(5);
    l5 = konso(l5, 7);
    l5 = konso(l5, 8);


    printf("-----------------\n");
    List l6 = concat(l4, l5);
    l6 = konso(l6, -1);
    l6 = konsb(l6, -7);
    displayList(l6);


    printf("-----------------\n");
    int max = maxList(l6);
    printf("%d\n", max);
    int min = minList(l6);
    printf("%d\n", min);
    float avg = averageList(l6);
    printf("%.2f\n", avg);

    printf("-----------------\n");
    List invL = inverseList(l6);
    displayList(invL);

    printf("-----------------\n");
    List la; List lb;
    splitOnX(invL, 4, &la,&lb);
    displayList(la);
    printf("-----------------\n");
    displayList(lb);
    
    List l7 = konso(l6, 100);

    boolean ada = isAllExist(l7, invL);
    if (ada) {
        printf("test\n");
    } else {
        printf("nope\n");
    }
    return 0;

}