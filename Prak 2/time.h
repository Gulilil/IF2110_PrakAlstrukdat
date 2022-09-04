/* File: time.h */
/* Tanggal: 3 September 2022 */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"
#include <stdio.h>

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Hour(T) (T).HH
#define Minute(T) (T).MM
#define Second(T) (T).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    if ( H >= 0 && H <= 23 && M >= 0 && M <=59 && S >= 0 && S<=59 ){
        return true;
    } else {
        return false;
    }
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
{
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
{
    int H;
    int M;
    int S;
    scanf("%d %d %d", &H, &M, &S);
    while (IsTIMEValid(H, M, S) == false){
        scanf("%d %d %d", &H, &M, &S);
    }
    CreateTime(T, H, M, S);
}
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return (3600*Hour(T) + 60*Minute(T) + Second(T));
}

TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
    TIME T;
    Hour(T) = (N - N % 3600) /3600;
    Minute(T) = ((N % 3600) - (N % 3600 % 60)) / 60;
    Second(T) = (N % 3600) % 60;
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    if (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)){
        return true;
    } else {
        return false;
    }
}
boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    if (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)){
        return false;
    } else {
        return true;
    }
}
boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
    long int time1 = TIMEToDetik(T1);
    long int time2 = TIMEToDetik(T2);
    if (time1 < time2){
        return true;
    } else {
        return false;
    }
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{
    long int time1 = TIMEToDetik(T1);
    long int time2 = TIMEToDetik(T2);
    if (time1 > time2){
        return true;
    } else {
        return false;
    }
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */
{
    long int time = TIMEToDetik(T);
    time = time +1;
    T = DetikToTIME(time);
    return T;
}
TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
    long int time = TIMEToDetik(T);
    time = time + N;
    T = DetikToTIME(time);
    return T;
}
TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
    long int time = TIMEToDetik(T);
    time = time -1;
    T = DetikToTIME(time);
    return T;
}
TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
{
    long int time = TIMEToDetik(T);
    time = time - N;
    T = DetikToTIME(time);
    return T;
}
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    long int timeAw = TIMEToDetik(TAw);
    long int timeAkh = TIMEToDetik(TAkh);
    long int duration;

    // timeAw < timeAkh
    if (TLT(TAw, TAkh) == true){
        duration = timeAkh - timeAw;
    } else {
        duration = timeAkh + (3600*24 - timeAw);
    }

}
#endif