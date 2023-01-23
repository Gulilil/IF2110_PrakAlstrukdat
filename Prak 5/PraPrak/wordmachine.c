// NIM                      : 13521116
// Nama                     : Juan Christopher Santoso
// Tanggal                  : 26 September 2022
// Topik praktikum          : Pra Praktikum 5
// Deskripsi                : Membuat ADT Mesin Kata

#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"
#include <stdio.h>

boolean EndWord = false;
Word currentWord;


void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK) {
      ADV();
   }

}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   START();
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   } else {
      EndWord = false;
      ADVWORD();
   }
}
void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   } else {
      CopyWord();
      IgnoreBlanks();
   }

}
void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i;

   i = 0;
   while (currentChar != MARK && currentChar != BLANK && i <= NMax){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }

   (i <= NMax) ? (currentWord.Length = i) : (currentWord.Length = NMax);
}

void LowerCase()
{
  int i = 0;
  char newChar;
  for (i = 0; i < currentWord.Length; i++){
    if (currentWord.TabWord[i] <= 90 && currentWord.TabWord[i] >= 65){
      newChar = currentWord.TabWord[i] - 65 + 97;
      currentWord.TabWord[i] = newChar;
    }
  }

}

// Untuk no 2, semua EndWord, ganti jadi endWord