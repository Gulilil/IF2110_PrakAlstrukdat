/*
    Nama                : Juan Christopher Santoso
    NIM                 : 13521116
    Tanggal             : 7 Oktober 2022
    Topik praktikum     : Latihan Praktikum 6
    Deskripsi           : Membuat ADT untuk prioqueuetime
*/

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	return (Head(Q)==Nil && Tail(Q)==Nil);
};

boolean IsFull (PrioQueueTime Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmt(Q) == MaxEl(Q));
};

int NBElmt (PrioQueueTime Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if (IsEmpty(Q)){
		return 0 ;
	}else{
        int diff = Tail(Q) - Head(Q);
		if (Head(Q) <= Tail(Q)){
	            return diff + 1;
	        }else{
	            return diff + MaxEl(Q) + 1;
	        }
	}
};


/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

{
	(*Q).T= (infotype*) malloc ( (Max) * sizeof(infotype));
    // if ((*Q).T == NULL){
    //     // Alokasi Gagal
    //     MaxEl(*Q) = 0;
    //     Head(*Q) = Nil;
    //     Tail(*Q) = Nil; 
    // } else {
    MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    //}
};

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	free(Q->T);
    // Head(*Q) = Nil;
    // Tail(*Q) = Nil;
	MaxEl(*Q)=0; 
};


/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
TAIL "maju" dengan mekanisme circular buffer; */
    // boolean checkDiffTime = true;
    // boolean checkSameTime = true;
    int i;
    int j;
    int idx;
    int prevIdx;

    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Elmt(*Q, Head(*Q)) = X;
    } else {
        // Memasukkan index ke belakang tail
        if (Tail(*Q) == MaxEl(*Q)-1){
            Tail(*Q) = 0;
            Elmt(*Q, Tail(*Q)) = X;
        } else {
            Tail(*Q) += 1;
            Elmt(*Q,Tail(*Q)) = X;
        }
        idx = Tail(*Q);

        while (idx != Head(*Q)){
            if (idx == 0){
                prevIdx = MaxEl(*Q)-1;
            } else {
                prevIdx = idx -1;
            }

            if ( Time(Elmt(*Q, idx)) < Time(Elmt(*Q, prevIdx))){
                infotype temp = Elmt(*Q, prevIdx);
                Elmt(*Q, prevIdx) = Elmt(*Q, idx);
                Elmt(*Q, idx) = temp;
            }
            idx = prevIdx;
        }
        
    }
};

void Dequeue (PrioQueueTime * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
Q mungkin kosong */
	*X = Elmt(*Q, Head(*Q));
	if (Head(*Q)==Tail(*Q)){
	        // jika hanya 1 elemen pada Queue, maka Queue menjadi kosong
	        Head(*Q) = Nil;
	        Tail(*Q) = Nil;
    }else{
        if (Head(*Q) == MaxEl(*Q)-1){
            Head(*Q) = 0;
        }else{
            Head(*Q)++;
        }
    }
};

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
    int i;
	if (IsEmpty(Q)){
 		printf("#\n");
	}else{
		if (Tail(Q) < Head(Q)){
            // Melakukan print mulai dari Head - MaxEl, lalu 0 - Tail
            for (i = Head(Q); i < MaxEl(Q);i++){
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
            }
            for (i = 0; i <= Tail(Q); i++){
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
            }
            printf("#\n");
        }else{
            for (i = Head(Q); i <= Tail(Q);i++){
                // Melakukan print mulai dari Head - Tail
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
            }
            printf("#\n");
        }
    }
};

// OPERASI TAMBAHAN UNTUK DRIVER
void ReadPrioQueueTime(PrioQueueTime *Q, int max){
    int i;
    int n;
    int time; char info;
    scanf("%d", &n);
    MakeEmpty(Q, max);

    for (i = 0; i < n; i++){
        infotype var;
        scanf("%d %c", &time, &info);
        Time(var) = time;
        Info(var) = info;
        Enqueue(Q, var);
    }
}


// Algoritma Enqueue yang tidak jadi dipakai
// // Mencari idx yang tepat untuk dimasukkan nilai X
// int idx = Head(*Q);
// while (checkDiffTime && idx <= Tail(*Q)){
//     printf("%d", idx);
//     if (Time(Elmt(*Q,idx)) > Time(X)){
//         checkDiffTime = false;
//     } else {
//         if (idx == MaxEl(*Q) -1){
//             // pengecekan sudah sampai di index terakhir
//             idx = 0;
//         } else {
//             idx++;
//         }
//     }
// }
// while(checkSameTime && idx <= Tail(*Q)){
//     if (Time(Elmt(*Q, idx)) != Time(X)){
//         checkSameTime = false;
//     } else {
//         if (idx == MaxEl(*Q) -1){
//             idx = 0;
//         } else {
//             idx++;
//         }
//     }
// }

// // menggeser semua nilai dari ke belakang mulai dari idx sampai tail
// if (idx < Tail(*Q)){
//     for (i = Tail(*Q); i <= idx; i--){
//         Elmt(*Q, i+1) = Elmt(*Q,i);
//     }
// } else {
//     for (i = Tail(*Q); i <= 0; i--){
//         Elmt(*Q, i+1) = Elmt(*Q, 1);
//     }
//     Elmt(*Q,0) = Elmt(*Q, MaxEl(*Q)-1);
//     for (i = MaxEl(*Q)-2; i <= idx; i--){
//         Elmt(*Q, i+1) = Elmt(*Q, i);
//     }
// }
// // Memasukkan nilai X
// Elmt(*Q, idx) = X;




// Algoritma enqueue yang tidak jadi dipakai (2)
// // Mengurutkan menggunakan insertion sort
//         if (NBElmt(*Q) > 1){
//             if (Head(*Q) < Tail(*Q)){
//                 // Handel untuk Head < Tail
//                 for (i = Head(*Q)+1; i <= Tail(*Q); i++){
//                     infotype temp = Elmt(*Q, i);
//                     j = i-1;
//                     while ( (Time(temp) < Time(Elmt(*Q, j))) && j > Head(*Q)){
//                         Elmt(*Q, j+1) = Elmt(*Q,j);
//                         j = j-1;
//                     }
//                     if (Time(temp) >= Time(Elmt(*Q, j))){
//                         Elmt(*Q, j+1) = temp;
//                     } else {
//                         Elmt(*Q, j+1) = Elmt(*Q, j);
//                         Elmt(*Q, j) = temp;
//                     }

//                 }
//             } else {
//                 // Handle untuk Tail < Head
//                 for (i = 1; i <= Tail(*Q); i++){
//                     infotype temp = Elmt(*Q, i);
//                     j = i-1;
//                     while ( (Time(temp) < Time(Elmt(*Q, j))) && j > 0){
//                         Elmt(*Q, j+1) = Elmt(*Q,j);
//                         j = j-1;
//                     }
//                     if (Time(temp) >= Time(Elmt(*Q, j))){
//                         Elmt(*Q, j+1) = temp;
//                     } else {
//                         Elmt(*Q, j+1) = Elmt(*Q, j);
//                         Elmt(*Q, j) = temp;
//                     }
//                 }
//                 if (Time(Elmt(*Q,0)) < Time(Elmt(*Q, MaxEl(*Q)-1))){
//                     // Di cek apabila time elemen pertama lebih kecil dari elemen terakhir
//                     infotype temp = Elmt(*Q,0);
//                     Elmt(*Q, 0) = Elmt(*Q,MaxEl(*Q)-1);
//                     Elmt(*Q, MaxEl(*Q)-1) = temp;

//                     for (i = Head(*Q)+1; i <= MaxEl(*Q)-1; i++){
//                         infotype temp = Elmt(*Q, i);
//                         j = i-1;
//                         while ( (Time(temp) < Time(Elmt(*Q, j))) && j > Head(*Q)){
//                             Elmt(*Q, j+1) = Elmt(*Q,j);
//                             j = j-1;
//                         }
//                         if (Time(temp) >= Time(Elmt(*Q, j))){
//                             Elmt(*Q, j+1) = temp;
//                         } else {
//                             Elmt(*Q, j+1) = Elmt(*Q, j);
//                             Elmt(*Q, j) = temp;
//                         }
//                     }
//                 }
//             }
//         }
//         // belum ada handle sort untuk case tail < head
