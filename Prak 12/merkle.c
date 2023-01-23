#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "bintree.c"

int checkPowerOf2(int num){
    while (num % 2 == 0){
        num = num / 2;
    }
    return num;
}

int level (int num){
    int depth = 0;
    while (num % 2 == 0){
        num = num /2;
        depth++;
    }
    return depth;
}

BinTree CreateMerkleTree(int level){
    BinTree p1, p2;
    int val;
    if (level == 0){
        scanf ("%d", &val);
        return newTreeNode (val);
    } else {
        p1 = CreateMerkleTree(level-1);
        p2 = CreateMerkleTree(level-1);
        return(NewTree(ROOT(p1)+ROOT(p2), p1, p2));
    }
}

int main () {
    int n;
    scanf("%d", &n);
    if (checkPowerOf2(n) != 1){
        printf("Jumlah masukan tidak sesuai\n");
    } else {
        int lvl = level(n);
        BinTree p = CreateMerkleTree(lvl);
        printTree(p,2);
    }
}