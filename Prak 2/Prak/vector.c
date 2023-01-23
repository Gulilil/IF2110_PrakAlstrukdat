// NIM              : 13521116
// Nama             : Juan Christopher Santoso
// Tanggal          : 6 September 2022
// Topik praktikum  : Praktikum 2
// Deskripsi        : Membuat realisasi ADT Vector


/* File: vector.c */
/* Tanggal: 03 September 2022 */
#include "point.h"
#include <stdio.h>
#include <math.h>
#include "vector.h"


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
void CreateVector(VECTOR *v, float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{  
    AbsisComponent(*v) = x;
    OrdinatComponent(*v) = y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
    return (sqrt(AbsisComponent(v)*AbsisComponent(v) + OrdinatComponent(v)*OrdinatComponent(v)));
}
VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR c;
    AbsisComponent(c) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a) + OrdinatComponent(b);
    return c;
}
VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR c;
    AbsisComponent(c) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a) - OrdinatComponent(b);
    return c;
}

float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
    float result;
    result = AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b);
    return result;
}
VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * v.x, s * v.y) */
{
    VECTOR u;
    AbsisComponent(u) = AbsisComponent(v) * s;
    OrdinatComponent(u) = OrdinatComponent(v) * s;
    return u;
}
