/*
    NIM                     : 13521116
    Nama                    : Juan Christopher Santoso
    Tanggal                 : 6 November 2022
    Topik praktikum         : Pra Praktikum 10
    Deskripsi               : Implementasi Stack Linked
*/

#include <stdio.h>
#include "stacklinked.h"


/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   
{
    Address temp = (Address) malloc (sizeof(Node));
    if (temp != NIL){
        INFO(temp) = x;
        NEXT(temp) = NIL;
    }
    return temp;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s)
/* Mengirim true jika Stack kosong: TOP(s) = NIL */
{
    return (ADDR_TOP(s) == NIL);
}

int length(Stack s)
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */
{
    Address walker;
    walker = ADDR_TOP(s);
    int count = 0;
    while (walker != NIL){
        walker = NEXT(walker);
        count++;
    }
    return count;
}

void CreateStack(Stack *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    ADDR_TOP(*s) = NIL;
}

void DisplayStack(Stack s)
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */
{
    int i;
    Address walker = ADDR_TOP(s);
    int len = length(s);
    printf("[");
    if (!isEmpty(s)){
        while (NEXT(walker) != NIL){
            printf("%d,", INFO(walker));
            walker = NEXT(walker);
        }
        printf("%d", INFO(walker));
    }
    printf("]");
}

void push(Stack *s, ElType x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    Address p;
    p = newNode(x);
    if (isEmpty(*s)){
        ADDR_TOP(*s) = p;
    } else{
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    Address p;
    p = ADDR_TOP(*s);
    *x = TOP(*s);
    int len = length(*s);

    if (len == 1){
        ADDR_TOP(*s) = NIL;
    } else {
        ADDR_TOP(*s) = NEXT(p);
    }
    free(p);

}