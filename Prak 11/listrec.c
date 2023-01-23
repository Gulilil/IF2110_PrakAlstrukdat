/*
    NIM                 : 13521116
    Nama                : Juan Christopher Santoso
    Tanggal             : 12 November 2022
    Topik praktikum     : Pra Praktikum 11
    Deskripsi           : List Rekursif
*/


#include "listrec.h"
#include <stdio.h>

/* Manajemen Memori */
Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
{
    Node* adrs = (Node*) malloc(sizeof(Node));
    if ( adrs != NULL){
        INFO(adrs) = x;
        NEXT(adrs) = NULL;
    }
    return adrs;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    return l == NIL;
}
boolean isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    return l != NIL && NEXT(l) == NIL;
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    return (INFO(l));
}
List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    return (NEXT(l));
}
List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
{
    Address p = newNode(e);
    if (p != NIL){
        NEXT(p) = l;
        return p;
    } else {
        return l;
    }
    
}
List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
{
    if (isEmpty(l)){
        Address p = newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}
List copy(List l)
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
{
    if (isEmpty(l)){
        return NIL;
    } else {
        return (konso( copy(tail(l)), head(l) ));
    }
}
List concat(List l1, List l2)
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
{
    if (isEmpty(l1)){
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    if (isEmpty(l)){
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}
boolean isMember(List l, ElType x)
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
{
    if (isEmpty(l)){
        return false;
    } else {
        if (INFO(l) == x){
            return true;
        } else {
            return isMember(tail(l), x);
        }
    }
}
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    if (!isEmpty(l)){
        if (isOneElmt(l)) {
            printf("%d\n", INFO(l));
        } else {
            printf("%d\n", INFO(l));
            displayList(tail(l));
        }
    }
}
