// NIM                  : 13521116
// Nama                 : Juan Christopher Santoso
// Tanggal              : 11 September 2022
// Topik praktikum      : Pra Praktikum 3
// Deskripsi            : Membaca sekian integer dalam list, mencari maks, min, dan median

#include <stdio.h>
#include "liststatik.h"


int main () {
    ListStatik l;
    int x;
    int i;
    int count = 0;
    int idx;
    int max;
    int min;
    int median;

    readList(&l);
    scanf("%d", &x);
    for (i= 0; i < listLength(l); i++){
        if (ELMT(l, i) == x){
            idx = i;
            count++;
        }
    }
    printList(l);
    printf("\n");

    if (count == 0){
        printf("%d\n", count);
        printf("%d tidak ada\n", x);
    } else {
        sortList(&l, true);
        extremeValues(l, &max,&min);
        
        if (listLength(l) %2 ==1 ){
            median = ELMT(l, ((listLength(l)+1)/2)-1);
        } else {
            median = ELMT(l, ((listLength(l)/2)-1));
        }

        printf("%d\n", count);
        printf("%d\n", idx);

        if (x == max){
            printf("maksimum\n");
        }
        if (x == min){
            printf("minimum\n");
        }
        if (x == median){
            printf("median\n");
        }

    }


    return 0;
}