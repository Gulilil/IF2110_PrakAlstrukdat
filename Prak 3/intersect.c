// NIM                  : 13521116
// Nama                 : Juan Christopher Santoso
// Tanggal              : 11 September 2022
// Topik praktikum      : Pra Praktikum 3
// Deskripsi            : Mencari elemen yang sama pada kedua list

#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l1;
    ListStatik l2;
    ListStatik l3;
    int i;
    int j;
    int count = 0;

    readList(&l1);
    readList(&l2);

    CreateListStatik(&l3);


    for (i = 0; i < listLength(l1); i++){
        for (j = 0; j < listLength(l2); j++){
            if (ELMT(l1, i) == ELMT(l2, j)){
                ELMT(l3, count) = ELMT(l1, i);
                count++;
            }
        }
    }

    sortList(&l3, true);

    printf("%d\n", count);
    printList(l3);
    printf("\n");





    return 0;
} 