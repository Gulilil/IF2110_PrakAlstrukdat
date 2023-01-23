// NIM                      : 13521116
// Nama                     : Juan Christopher Santoso
// Tanggal                  : 20 Oktober 2022
// Topik praktikum          : Praktikum 7
// Deskripsi                : Menghtitung hasil kalkulasi dari ekspresi postfix


#include <stdio.h>
#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"
#include <math.h>

int power(int a, int b){
	if (b == 0){
		return 1;
	} else {
		int sum = 1;
		int i;
		for (i = 0; i < b; i++){
			sum = sum *a;
		}
		return sum;
	}
}

int calculate(int a, int b, char c){
	int result = 0;
	if (c == '+'){
		result = a + b;
	} else if ( c == '-'){
		result = a - b;
	} else if ( c == '*'){
		result = a * b;
	} else if (c == '/'){
		result = a / b;
	} else if ( c == '^'){
		result = power(a,b);
	}
	return result;
}


int main (){
	Stack s;
	CreateEmpty(&s);
	int i;
	int sum;
	int val2;
	int val1;
	int result;

	STARTWORD();
	if (endWord){
		printf("Ekspresi kosong\n");
	} else {
		while (!endWord){
			sum = 0;
			if (currentWord.Length == 1){
				// Jika operator
				if (currentWord.TabWord[0] < 48 || currentWord.TabWord[0] > 57){
					Pop(&s, &val2);
					Pop(&s, &val1);
					printf("%d %c %d\n", val1, currentWord.TabWord[0], val2);
					result = calculate(val1, val2, currentWord.TabWord[0]);
					Push(&s, result);
					printf("%d\n", result);
				}
				// Bilangan tapi hanya satu panjangnya
				else {
					Push(&s, currentWord.TabWord[0] -48);
					printf("%d\n", currentWord.TabWord[0] - 48);
				}
			}
			else {
				// Bilangan lebih panjang dari 1 angka
				for (i = 0; i < currentWord.Length; i++){
					sum = sum + (currentWord.TabWord[i] -48)*power(10, currentWord.Length-1-i);
				}
				Push(&s, sum);
				printf("%d\n", sum);
			}
			ADVWORD();
		}

		Pop(&s, &result);
		printf("Hasil=%d\n", result);

	}



	return 0;
}