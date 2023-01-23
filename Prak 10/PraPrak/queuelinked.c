/*
    NIM                     : 13521116
    Nama                    : Juan Christopher Santoso
    Tanggal                 : 6 November 2022
    Topik praktikum         : Pra Praktikum 10
    Deskripsi               : Implementasi Queue Linked
*/

#include <stdio.h>
#include "queuelinked.h"


/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
{
    Address temp = (Address) malloc (sizeof(Node));
    if (temp != NIL){
        INFO(temp) = x;
        NEXT(temp) = NIL;
    }
    return temp;
}
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
{
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
    Address p = ADDR_HEAD(q);
    int count = 0;
    if (!isEmpty(q)){
        while (p != NEXT(ADDR_TAIL(q))){
            p = NEXT(p);
            count++;
        }
    }
    return count;
}

/*** Kreator ***/
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}
void DisplayQueue(Queue q)
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    int i;
    Address walker = ADDR_HEAD(q);
    printf("[");
    if (!isEmpty(q)){
        while (walker != ADDR_TAIL(q)){
            printf("%d,", INFO(walker));
            walker = NEXT(walker);
        }
        printf("%d", INFO(walker));
    }
    printf("]");
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
{
    Address p;
    p = newNode(x);
    if (isEmpty(*q)){
        ADDR_HEAD(*q) = p;
        ADDR_TAIL(*q) = p;
    } else {
        NEXT(ADDR_TAIL(*q)) = p;
        ADDR_TAIL(*q) = p;
    }
}
void dequeue(Queue *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    *x = HEAD(*q);
    Address p;
    p = ADDR_HEAD(*q);
    if(length(*q) == 1){
        ADDR_HEAD(*q) = NIL;
        ADDR_TAIL(*q) = NIL;
    } else {
        ADDR_HEAD(*q) = NEXT(p);
    }
    free(p);
}