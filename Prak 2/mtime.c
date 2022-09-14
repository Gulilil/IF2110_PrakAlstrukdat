// NIM              : 13521116
// Nama             : Juan Christopher Santoso
// Tanggal          : 6 September 2022
// Topik praktikum  : Pra Praktikum 2
// Deskripsi        : Membuat program menggunakan ADT Time

#include <stdio.h>
#include "time.h"

int main(){

    int record;
    TIME J1;
    TIME J2;
    TIME Jmaks;
    TIME Jmin;


    scanf("%d", &record);
    int count = 1;
    for (count; count <= record ; count++){
        printf("[%d]\n", count);
        BacaTIME(&J1);
        BacaTIME(&J2); 

        if (count == 1){
            Jmaks = J1;
            Jmin = J1;
        }
        
        
        if (TGT(J1,J2) == true){
            // J1 > J2
            printf("%d\n", Durasi(J2, J1));
            if (TGT(J1, Jmaks))
            {
                Jmaks = J1;
            }
            if (TLT(J2, Jmin))
            {
                Jmin = J2;
            }

        
        } else {
            // J2 > J1
            printf("%d\n", Durasi(J1, J2));
            if (TGT(J2, Jmaks))
            {
                Jmaks = J2;
            }
            if (TLT(J1, Jmin))
            {
                Jmin = J1;
            } 

        }
        

    }

    TulisTIME(Jmin);
    printf("\n");
    TulisTIME(Jmaks);
    printf("\n");
    
    return 0;
}