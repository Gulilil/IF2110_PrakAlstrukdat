// NIM                  : 13521116
// Nama                 : Juan Christopher Santoso
// Tanggal              : 11 September 2022
// Topik praktikum      : Pra Praktikum 3
// Deskripsi            : Membuat ADT Untuk List Dinamis

#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (ElType*)malloc((capacity) * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l));
    NEFF(*l) = 0;
    CAPACITY(*l)=0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    // Menggunakan < karena index (CAPACITY) berada di luar range
    return ((i >= IDX_MIN) && (i < CAPACITY(l)));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return ((i >= IDX_MIN) && (i <= NEFF(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    if (NEFF(l) == 0) {
        return true;
    } else {
        return false;
    }
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    if (NEFF(l) == CAPACITY(l)){
        return true;
    } else {
        return false;
    }
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int n;
    int i;
    int element;
    scanf("%d\n", &n);
    while ( n < IDX_MIN || n > CAPACITY(*l)) {
        scanf("%d\n", &n);
    }
    for (i=0; i < n; i++){
        scanf("%d", &element);
        ELMT(*l, i) = element;
    }
    NEFF(*l) = n;


}
void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    int i;
    printf("[");
    for(i = 0; i < NEFF(l); i++){
        if (i == NEFF(l)-1){
            printf("%d", ELMT(l,i));
        } else {
            printf("%d,", ELMT(l,i));
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    int i;
    ListDin(l3);
    CreateListDin(&l3, NEFF(l1));
    NEFF(l3) = NEFF(l1);
    CAPACITY(l3) = CAPACITY(l1);
    
    if (plus) {
        for (i=0; i < NEFF(l1); i++){
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for (i=0; i < NEFF(l1); i++){
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    int i;
    if (NEFF(l2) != NEFF(l1)){
        return false;
    } else {
        for (i = 0; i < NEFF(l1); i++){
            if (ELMT(l1, i) != ELMT(l2, i)){
                return false;
            }
        }
        return true;
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    int i;
    if (NEFF(l) == 0){
        return IDX_UNDEF;
    } else {
        for (i = 0; i < NEFF(l); i++){
            if (ELMT(l, i) == val){
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    int i;
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    for (i = 0; i < NEFF(l); i++){
        if (ELMT (l, i) > *max){
            *max = ELMT(l, i);
        } 
        if (ELMT (l, i) < *min){
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    int i;

    //BUFFER(*lOut) = BUFFER(lIn);

    CreateListDin(lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }

    NEFF(*lOut) = NEFF(lIn);
    CAPACITY(*lOut) = CAPACITY(lIn);
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    int sum = 0;
    if (NEFF(l) == 0){
        return sum;
    } else {
        for (i = 0; i < NEFF(l); i++){
            sum = sum + ELMT(l, i);
        }
        return sum;
    }
}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    int count = 0;
    if (NEFF(l) == 0){
        return count;
    } else {
        for (i = 0; i < NEFF(l); i++){
            if (ELMT(l, i) == val){
                count = count +1;
            }
        }
        return count;
    }
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int i;
    int j;
    int length = NEFF(*l);
    int temp;


    // Jika list kosong atau hanya berisi 1, tidak ada yang perlu diurutkan
    // Insertion sort
    if (length > 1){
        if ( asc ){
            for (i = 1; i < length; i++){
                temp = ELMT(*l, i);
                j = i-1;
                while ( (temp < ELMT (*l, j)) && (j > 0)){
                    ELMT(*l,j+1) = ELMT(*l, j);
                    j = j-1;
                }
                if (temp >= (ELMT(*l, j))){
                    ELMT(*l, j+1) = temp;
                } else {
                    ELMT(*l, j+1) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        } else {
            for (i = 1; i < length; i++){
                temp = ELMT(*l, i);
                j = i-1;
                while ( (temp > ELMT (*l, j)) && (j > 0)){
                    ELMT(*l,j+1) = ELMT(*l, j);
                    j = j-1;
                }
                if (temp <= (ELMT(*l, j))){
                    ELMT(*l, j+1) = temp;
                } else {
                    ELMT(*l, j+1) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
        
    }

}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) = NEFF(*l) +1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, NEFF(*l)-1);
    NEFF(*l) = NEFF(*l) -1;

}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    CAPACITY(*l) = CAPACITY(*l) +  num;
    BUFFER(*l) = realloc(BUFFER(*l), (CAPACITY(*l)) * sizeof(ElType));
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    CAPACITY(*l) = CAPACITY(*l) - num;
    BUFFER(*l) = realloc(BUFFER(*l), (CAPACITY(*l)) * sizeof(ElType));
}

void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    BUFFER(*l) = realloc(BUFFER(*l), (NEFF(*l)) * sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}