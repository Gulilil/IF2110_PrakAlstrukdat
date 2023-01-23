#include <stdio.h>
#include <stdlib.h>
#include "bintree.c"

void FlipTree (BinTree *p){
    if (!isTreeEmpty(*p)){
        BinTree temp = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = temp;

        FlipTree(&LEFT(*p));
        FlipTree(&RIGHT(*p));
    }
}

int main () {
    BinTree p;
    CreateTree(50, NULL, NULL, &p);
    LEFT(p) = newTreeNode(25);
    LEFT(LEFT(p)) = newTreeNode(13);
    LEFT(LEFT(LEFT(p))) = newTreeNode(6);
    RIGHT(LEFT(LEFT(p))) = newTreeNode(19);
    RIGHT(p) = newTreeNode(75);
    LEFT(RIGHT(p)) = newTreeNode(62);
    RIGHT(RIGHT(p)) = newTreeNode(88);

    printTree(p,2); 
    printf("\n");

    FlipTree(&p);
    printTree(p,2);
    printf("\n");
}