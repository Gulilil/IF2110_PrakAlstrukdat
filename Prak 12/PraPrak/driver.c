#include <stdio.h>
#include "bintree.c"

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

    printPreorder(p); printf("\n");
    printInorder(p); printf("\n");
    printPostorder(p); printf("\n");
    printTree(p,2); printf("\n");

    
    return 0;
}