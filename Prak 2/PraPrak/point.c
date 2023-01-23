// NIM              : 13521116
// Nama             : Juan Christopher Santoso
// Tanggal          : 6 September 2022
// Topik praktikum  : Pra Praktikum 2
// Deskripsi        : Membuat realisasi ADT Point


/* File: point.h */
/* Tanggal: 3 September 2022 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "boolean.h"
#include <stdio.h>
#include <math.h>
#include <point.h>

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
    {
        Absis(*P) = X;
        Ordinat(*P) = Y;
    }

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    float x; 
    float y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */  
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}              

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))){
        return true;
    } else{
        return false;
    }
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))){
        return false;
    } else{
        return true;
    }
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    if((Absis(P) == 0) && (Ordinat(P) == 0)){
        return true;
    } else {
        return false;
    }
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    if((Ordinat(P) == 0)){
        return true;
    } else {
        return false;
    }
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    if((Absis(P) == 0)){
        return true;
    } else {
        return false;
    }
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */     
{
    if ( Absis(P) > 0){
        if (Ordinat(P) > 0){
            return 1;
        } else {
            return 4;
        }
    } else {
        if (Ordinat(P) > 0){
            return 2;
        } else {
            return 3;
        }
    }
}                      
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */  
{
    Absis(P) = Absis(P) + 1;
    return P;
}            
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    Ordinat(P) = Ordinat(P) + 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    if (SbX){
        Ordinat(P) = Ordinat(P) *-1;
        return P;
    } else {
        Absis(P) = Absis(P) *-1;
        return P;
    }
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return (sqrt( (Absis(P)*Absis(P)) + ((Ordinat(P)*Ordinat(P))) ) );
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
    float xdiff = Absis(P1) - Absis(P2);
    float ydiff = Ordinat(P1) - Ordinat(P2);

    return (sqrt( (xdiff*xdiff) + (ydiff*ydiff) ) );
}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    if (SbX){
        Ordinat(*P) = Ordinat(*P) *-1;
    } else {
        Absis(*P) = Absis(*P) *-1;
    }
}
void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    float Rad;
    float tempX = Absis(*P);
    float tempY = Ordinat(*P);
    float pi = 3.14159265;
    Rad = -1* (Sudut * pi / 180);
    Absis(*P) = tempX * cos(Rad) - tempY * sin(Rad);
    Ordinat(*P) = tempX * sin(Rad) + tempY * cos(Rad);
}