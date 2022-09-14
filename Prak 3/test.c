#include <stdio.h>
#include "liststatik.c"
// #include "listdin.c"

int main(){


    // INI BUAT LIST STATIK
    ListStatik l;
    readList(&l);

    sortList(&l, true);

    printList(l);

    return 0;




//    // INI BUAT LIST DINAMIS
//    ListDin l;
//    readList(&l);
//    printList(l);



//    return 0;

}