// NIM                      : 13521116
// Nama                     : Juan Christopher Santoso
// Tanggal                  : 29 September 2022
// Topik praktikum          : Praktikum 5
// Deskripsi                : Menghitung kata yang paling panjang dari input

#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"
#include "boolean.h"

boolean EndWord;
Word currentWord;

int main(){
	STARTWORD();
	int longest;
	int count = 0;

	while(!EndWord){
		if (count == 0){
			longest = currentWord.Length;
		}
		else {
			if (currentWord.Length > longest){
				longest = currentWord.Length;
			}
		}
		count++;
		ADVWORD();
	}
	printf("%d\n", longest);



	return 0;
}