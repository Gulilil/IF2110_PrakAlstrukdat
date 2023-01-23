/*
    NIM                     : 13521116
    Nama                    : Juan Christopher Santoso
    Tanggal                 : 6 November 2022
    Topik praktikum         : Praktikum 10
    Deskripsi               : Menggunakan stack untuk perhitungan string
*/

#include "boolean.h"
#include "stacklinked.h"
#include <stdio.h>
#include "charmachine.h"

int main () {
    Stack s;
    CreateStack(&s);
    int nsiku = 0;
    int nbulat = 0;
    int ntegak = 0;
    int nkurawal = 0;
    int nsegitiga = 0;
    boolean valid = true;
    int max = 0;
    int val;
    START();
    while(currentChar != '.'){
        //printf("%c\n", currentChar);

        // Penambahan
        if(currentChar == '['){
            push(&s, 0);
            nsiku++;
            DisplayStack(s);
            printf("\n");
        } else if (currentChar == '('){
            push(&s, 1);
            nbulat++;
            DisplayStack(s);
            printf("\n");
        } else if (currentChar == '|'){
            if (TOP(s) != 2 || isEmpty(s)){
                // Jika stack kosong dianggap sebagai kurung pembuka
                // Jika kurung terakhir bukan | , maka dianggap sebagai kurung pembuka
                push(&s, 2);
                ntegak++;
                DisplayStack(s);
                printf("\n");
            } else {
                // Tidak kosong, dan top nya adalah 2
                pop(&s, &val);

                DisplayStack(s);
                printf("\n");
            }

        } else if (currentChar == '{'){
            push(&s, 3);
            nkurawal++;
            DisplayStack(s);
            printf("\n");
        } else if (currentChar == '<'){
            push(&s, 4);
            nsegitiga++;
            DisplayStack(s);
            printf("\n");
        }

        int len = length(s);
        if (len > max){
            max = len;
        }

        // Pengurangan
        if (currentChar == ']'){
            // Tidak valid bila penutup saat string kosong
            // Tidak valid bila kurung terakhir bukanlah kurung pembuka pasangannya
            if (isEmpty(s)){
                valid = false;
            } else {
                if (TOP(s) != 0 ){
                    valid = false;
                }
                else {
                    pop(&s, &val);
                }
            }
            DisplayStack(s);
            printf("\n");
        }
        else if (currentChar == ')'){
            // Tidak valid bila penutup saat string kosong
            // Tidak valid bila kurung terakhir bukanlah kurung pembuka pasangannya
            if (isEmpty(s)){
                valid = false;
            } else {
                if (TOP(s) != 1 ){
                    valid = false;
                }
                else {
                    pop(&s, &val);
                }
            }
            DisplayStack(s);
            printf("\n");
        }
        else if (currentChar == '}'){
            // Tidak valid bila penutup saat string kosong
            // Tidak valid bila kurung terakhir bukanlah kurung pembuka pasangannya
            if (isEmpty(s)){
                valid = false;
            } else {
                if (TOP(s) != 3 ){
                    valid = false;
                }
                else {
                    pop(&s, &val);
                }
            }
            DisplayStack(s);
            printf("\n");
        }
        else if (currentChar == '>'){
            // Tidak valid bila penutup saat string kosong
            // Tidak valid bila kurung terakhir bukanlah kurung pembuka pasangannya
            if (isEmpty(s)){
                valid = false;
            } else {
                if (TOP(s) != 4 ){
                    valid = false;
                }
                else {
                    pop(&s, &val);
                }
            }
            DisplayStack(s);
            printf("\n");
        }

        //printf("%c - ", currentChar);
        ADV();
    }
    if (valid && isEmpty(s)){
        printf("kurung valid\n");
        printf("[%d] (%d) |%d| {%d} <%d>\n", nsiku, nbulat, ntegak, nkurawal, nsegitiga);
        printf("MAX %d\n", max);
    } else {
        printf("kurung tidak valid\n");
    }
    return 0;
}

/*
<5,2> dan <7,3> adalah koordinat rahasia dan disana ada agen dengan id {1,8,2,1,3,5}.

[(1+1)*(7/3)-|(6/3+-2*9)|] =x.

[f{e<a}d>c].

(: semoga harimu menyenangkan.

:) semoga harimu menyenangkan.

Hai.
*/

/*
            // cari apakah | adalah yang pembuka atau penutup
            boolean found = false;
            Address p = ADDR_TOP(s);
            while (p != NULL){
                // found = true bila terdapat 2 pada bagian sebelumnya
                if (INFO(p) == 2){
                    found = true;
                }
                p = NEXT(p);
            }


*/