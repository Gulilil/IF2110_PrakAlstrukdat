// NIM                  : 13521116
// Nama                 : Juan Christopher Santoso
// Tanggal              : 11 September 2022
// Topik praktikum      : Pra Praktikum 3
// Deskripsi            : Menggabungkan kedua list dan mengurutkannya

#include <stdio.h>
#include "listdin.h"

int main () {
    ListDin l1;
    ListDin l2;
    ListDin l3;
    int count = 0;
    boolean found;
    int i;
    int j;

    CreateListDin(&l1, 200);
    CreateListDin(&l2, 200);
    CreateListDin(&l3, 400);

    readList(&l1);
    readList(&l2);
    

    // masukkin nilai dari l1 ke l3
    if ((NEFF(l3)== 0) && (NEFF(l1) != 0)){
        // nilai pertama dari suatu list otomatis dimasukkan bila list l3 masih kosong
        ELMT(l3, count) = ELMT(l1, 0);
        count ++;
        NEFF(l3) = NEFF(l3)+1;
    } 
    for (i =0; i < NEFF(l1); i++){
        found = false;
        for (j = 0 ; j < NEFF(l3); j++){
            if (ELMT(l1, i) == ELMT(l3, j)){
                found = true;
            }
        }

        if (found == false){
            ELMT(l3, count) = ELMT(l1,i);
            count ++;
            NEFF(l3) = NEFF(l3)+1;
        }
    }

    // masukkin nilai dari l2 ke l3
    if ((NEFF(l3)== 0) && (NEFF(l2) != 0)){
        // nilai pertama dari suatu list otomatis dimasukkan bila list l3 masih kosong
        ELMT(l3, count) = ELMT(l2, 0);
        count ++;
        NEFF(l3) = NEFF(l3)+1;
    } 
    for (i =0; i < NEFF(l2); i++){
        found = false;
        for (j = 0 ; j < NEFF(l3); j++){
            if (ELMT(l2, i) == ELMT(l3, j)){
                found = true;
            }
        }

        if (found == false){
            ELMT(l3, count) = ELMT(l2,i);
            count ++;
            NEFF(l3) = NEFF(l3)+1;
        }
    }

    sort(&l3, true);

    printf("%d\n", NEFF(l3));
    printList(l3);
    printf("\n");


    return 0;
}