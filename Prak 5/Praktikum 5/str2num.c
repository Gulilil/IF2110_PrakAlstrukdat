// NIM                      : 13521116
// Nama                     : Juan Christopher Santoso
// Tanggal                  : 29 September 2022
// Topik praktikum          : Praktikum 5
// Deskripsi                : Mengubah nilai angka dalam huruf menjadi angka numerik

#include <stdio.h>
#include <string.h>
#include "wordmachine.h"
#include "boolean.h"

boolean endWord;
Word currentWord;


boolean numberCheck(Word word, char *s){
	if (strlen(s) == word.Length){
		int i;
		for (i = 0; i < word.Length; i++){
			if (word.TabWord[i] != s[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

boolean isInNumberList(Word word, char *num[]){
	int i;
	for (i = 0; i< 18; i++){
		if (numberCheck(word, num[i])){
			return true;
		}
	}
	return false;
}

int digit(Word word, char *num[]){
	int i;
	int digit = 0;
	if (numberCheck(word, num[0])){
		return digit;
	} else {
		for (i = 0; i < 10; i++){
			if (numberCheck(word, num[i])){
				digit = i;
			}
		}
	}
	return digit;
}

int main(){
	int n;
	char *numberList[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "belas", "puluh", "seratus", "ratus", "seribu", "ribu"};
	endWord = false;
	STARTWORD();
	while(!endWord){

		if (isInNumberList(currentWord, numberList)){
			// Huruf yang sedang dibaca adalah suatu angka
			n = 0;
			while(isInNumberList(currentWord, numberList)){
				if(numberCheck(currentWord, "sepuluh")){
					n += 10; 
					ADVWORD();
					if (endWord){
						break;
					}
				} else if(numberCheck(currentWord, "sebelas")){
					n += 11;
					ADVWORD();
					if (endWord){
						break;
					}
				} else if (numberCheck(currentWord, "seribu")){
					n += 1000;
					ADVWORD();
					if(endWord){
						break;
					}
				} else if (numberCheck(currentWord, "seratus")){
					n += 100;
					ADVWORD();
					if (endWord){ 
						break;
					}
				} else{
					int tempNum = digit(currentWord, numberList);
					ADVWORD();
					if (endWord) {
						n += tempNum;
						break;
					} else if (numberCheck(currentWord, "ribu")){
						n += tempNum * 1000;
						ADVWORD();
						if (endWord){
							break;
						}
					} else if (numberCheck(currentWord, "ratus")){
						n += tempNum * 100;
						ADVWORD();
						if (endWord){
							break;
						}
					} else if (numberCheck(currentWord, "puluh")){
						n += tempNum * 10;
						ADVWORD();
						if (endWord){
							break;
						}
					} else if (numberCheck(currentWord, "belas")){
						n += tempNum + 10;
						ADVWORD();
						if (endWord){
							break;
						}
					} else {
						n += tempNum;
						break;
					}
				}
			}	
			if (!endWord){
				printf("%d ", n);
			}
			else{
				printf("%d", n);
			}
		}
		else{
			// Jika huruf yang dibaca bukanlah angka 
			for (int i = 0; i < currentWord.Length; i++){
				printf("%c", currentWord.TabWord[i]);
			}
			ADVWORD();
			if (!endWord){
				printf(" ");
			}
		}
	}
	printf("\n");
}