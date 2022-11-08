/*
    NIM                     : 13521116
    Nama                    : Juan Christopher Santoso
    Tanggal                 : 30 Oktober 2022
    Topik praktikum         : Pra Praktikum 9
    Deskripsi               : Implementasi List Sirkuler
*/


#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (FIRST(l) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FIRST(*l) = NULL;
}   

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    ElmtList *adrs = (ElmtList *)malloc(sizeof(ElmtList));
    if ( adrs != NULL){
        INFO(adrs) = val;
        NEXT(adrs) = NULL;
    }
    return adrs;

}
void deallocate(Address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    if (!isEmpty(l)){
        Address walker = NEXT(FIRST(l));
        while (INFO(walker) != val && walker != FIRST(l)){
            walker = NEXT(walker);
        }
        if (INFO(walker) == val){
            return walker;
        } 
    }
    // Jika empty, maka return NULL
    // Jika tidak empty, tapi tidak ditemukan, juga return NULL;
    return NULL;
}

boolean addrSearch(List l, Address p)
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    if (!isEmpty(l)){
        Address walker = NEXT(FIRST(l));
        while (walker != p && walker != FIRST(l)){
            walker = NEXT(walker);
        }
        if (walker == p){
            return true;
        }
    }
    // jika l empty, maka return False
    // jika l tidak empty, tapi tidak ditemukan, juga return false
    return false;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
{
    if (isEmpty(*l)){
        Address p = allocate(val);
        if (p != NULL){
            NEXT(p) = p;
            FIRST(*l) = p;
        }
    } else {
        // List tidak kosong
        Address p = allocate(val);
        Address last = FIRST(*l);
        if (p != NULL){
            while (NEXT(last) != FIRST(*l)){
                last = NEXT(last);
            }
            // berhenti saat NEXT dari last adalah FIRST
            NEXT(p) = FIRST(*l);
            NEXT(last) = p;
            FIRST(*l) = p;
        }
    }
}
void insertLast(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
{
    if (isEmpty(*l)){
        insertFirst(l, val);
    } else {
        // List tidak kosong
        Address p = allocate(val);
        Address last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }
        // berhenti saat NEXT dari last adalah FIRST
        NEXT(p) = NEXT(last);
        NEXT(last) = p;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val)
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
{
    if (NEXT(FIRST(*l)) == FIRST(*l)){
        //handle list 1 element
        *val = INFO(FIRST(*l));
        Address temp = FIRST(*l);
        FIRST(*l) = NULL;
        deallocate(temp);
    } else {
        *val = INFO(FIRST(*l));
        Address temp = FIRST(*l);
        Address last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }
        // berhenti saat NEXT dari last adalah FIRST
        NEXT(last) = NEXT(FIRST(*l));
        FIRST(*l) = NEXT(FIRST(*l));
        deallocate(temp);
    }

}
void deleteLast(List *l, ElType * val)
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */
{
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        deleteFirst(l, val);
    } else {
        Address secondLast = FIRST(*l);
        while (NEXT(NEXT(secondLast)) != FIRST(*l)){
            secondLast = NEXT(secondLast);
        }
        // berhenti saat NEXT dari NEXT secondLast adalah FIRST
        Address last = NEXT(secondLast);
        *val = INFO(last);
        NEXT(secondLast) = NEXT(last);
        deallocate(last);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (isEmpty(l)){
        printf("[]");
    }
    else {
        printf("[");
        Address walker = FIRST(l);
        while (NEXT(walker) != FIRST(l)){
            printf("%d,", INFO(walker));
            walker = NEXT(walker);
        }
        printf("%d]", INFO(walker));
    }
}