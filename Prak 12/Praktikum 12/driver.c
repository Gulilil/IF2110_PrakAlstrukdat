#include <stdio.h>
#include "bintree.c"

int main () {

    BinTree p;
    CreateTree(3, NULL, NULL, &p);
    LEFT(p) = newTreeNode(4);
    LEFT(LEFT(p)) = newTreeNode(1);
    RIGHT(LEFT(p)) = newTreeNode(3);
    //LEFT(LEFT(LEFT(p))) = newTreeNode(5);
    //RIGHT(LEFT(LEFT(p))) = newTreeNode(7);
    RIGHT(p) = newTreeNode(5);
    LEFT(RIGHT(p)) = newTreeNode(1);
    //RIGHT(RIGHT(p)) = newTreeNode(6);

    printTree(p,2); printf("\n");

    int res = rob1(p);
    printf("%d\n", res);

/*
    printf("=================\n");
    int odd = oddLevelCounter(p);
    printf("%d\n", odd);

    int even = evenLevelCounter(p);
    printf("%d\n", even); */

    int res2 = rob2(p);
    printf("%d\n", res2);


    
    return 0;
}