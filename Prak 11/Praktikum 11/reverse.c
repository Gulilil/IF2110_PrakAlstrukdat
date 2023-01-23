/*
    NIM                 : 13521116
    Nama                : Juan Christopher Santoso
    Tanggal             : 12 November 2022
    Topik praktikum     : Pra Praktikum 11
    Deskripsi           : List Rekursif
*/

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

List reverseList (List l)
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    if (isEmpty(l)){
        return NULL;
    } else {
        return konsb( reverseList(tail(l)) , head(l));
    }
}


void splitK(List l, int count, List *l1, List *l2){
    if (!isEmpty(l)){
        if (count > 0){
            /* masukinnya konso agar terbalik (reverse) */
            *l1 = konso( *l1, head(l));
            splitK(tail(l), count-1, l1, l2);
        } else {
            *l2 = konsb( *l2, head(l));
            splitK(tail(l), count, l1,l2);
        }   
    }
}

void displayInLine( List l){
    if (!isEmpty(l)){
        if (isOneElmt(l)){
            printf("%d\n", head(l));
        } else {
            printf("%d ", head(l));
            displayInLine(tail(l));
        }
    }
}


int main () {
    List l = NULL;
    int n;
    int k;
    scanf("%d %d", &n, &k);

    // memasukkan pada barisan
    int i;
    for (i = 0; i < n; i ++){
        int val;
        scanf("%d", &val);
        l = konsb(l, val);
    }
    //displayList(l);

    List result = NULL;
    
    while (length(l) > k){
        List l1 = NULL;
        List l2 = NULL;
        splitK(l, k, &l1, &l2);

        // masukin hasil l1 ke result
        result = concat(result, l1);
        l = l2;
    }
    List remainder = reverseList(l);
    result = concat(result, remainder);
    displayInLine(result);
 

}