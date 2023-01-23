/*
NIM                     : 13521116
Nama                    : Juan Christopher Santoso
Tanggal                 : 24 Oktober 2022
Topik praktikum         : Pra Praktikum 8
Deskripsi               : Implementasi ADT List Linear
*/


#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val)
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
{
    Address temp = (Address) malloc (sizeof(Node));
    INFO(temp) = val;
    NEXT(temp) = NULL;
    return temp;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    Address walker = FIRST(l);
    while (idx > 0){
        walker = NEXT(walker);
        idx--;
    }
    return (INFO(walker));
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    Address walker = FIRST(*l);
    while (idx > 0){
        walker = NEXT(walker);
        idx--;
    }
    INFO(walker) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    int count = 0;
    Address walker = FIRST(l);

    while (walker != NULL){
        if (INFO(walker) == val){
            return count;
        }
        count++;
        walker = NEXT(walker);
    }
    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address newAdrs = newNode(val);
    NEXT(newAdrs) = FIRST(*l);
    FIRST(*l) = newAdrs;
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address newAdrs = newNode(val);
    Address walker = FIRST(*l);

    if (isEmpty(*l)){
        insertFirst(l, val);
    } else {
        while (NEXT(walker) != NULL) {
            walker = NEXT(walker);
        }
        NEXT(walker) = newAdrs;
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address newAdrs = newNode(val);
    Address walker = FIRST(*l);
    if (idx == 0){
        insertFirst(l, val);
    } else {
        while (idx > 1){
            walker = NEXT(walker);
            idx--;
        }
        NEXT(newAdrs) = NEXT(walker);
        NEXT(walker) = newAdrs;

    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address temp = FIRST(*l);
    *val = INFO(temp);

    FIRST(*l) = NEXT(temp);
    free(temp);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address walker = FIRST(*l);
    Address prev = NULL;
    
    while (NEXT(walker) != NULL){
        prev = walker;
        walker = NEXT(walker);
    }
    
    if (prev == NULL) {
        FIRST(*l) = NULL;
        *val = INFO(walker);
    } else {
        NEXT(prev) = NULL;
        *val = INFO(walker);
    }

    free(walker);
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    Address walker = FIRST(*l);

    if (idx == 0){
        deleteFirst(l, val);
    } else {
        while (idx > 1) {       
            // Berhenti di satu elemen sebelum elemen yang ingin dihilangkan
            walker = NEXT(walker);
            idx--;
        }

        Address loc = walker;
        walker = NEXT(walker);
        *val = INFO(walker);
        NEXT(loc) = NEXT(walker);

        free(walker);

    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (isEmpty(l)){
        printf("[]");
    } else {
        printf("[");
        Address walker = FIRST(l);
        while (NEXT(walker) != NULL){
            printf("%d,", INFO(walker));
            walker = NEXT(walker);
        }
        // print elemen terakhir
        printf("%d]", INFO(walker));
    }
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    Address walker = FIRST(l);
    if(!isEmpty(l)){
        while (walker != NULL){
            count++;
            walker = NEXT(walker);
        }
    } 
    return count;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) 
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    CreateList(&l3);

    Address walker = FIRST(l1);
    while(walker != NULL){
        insertLast(&l3, INFO(walker));
        walker = NEXT(walker);
    }

    walker = FIRST(l2);
    while(walker != NULL){
        insertLast(&l3, INFO(walker));
        walker = NEXT(walker);
    }

    return l3;
}