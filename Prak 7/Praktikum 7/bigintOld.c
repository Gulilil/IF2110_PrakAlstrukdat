// NIM                      : 13521116
// Nama                     : Juan Christopher Santoso
// Tanggal                  : 20 Oktober 2022
// Topik praktikum          : Praktikum 7
// Deskripsi                : Menampilkan pengurangan dua buah integer


#include "stack.h"
#include <stdio.h>

void printStack(Stack st){
	int value;
	while (!IsEmpty(st)){
		Pop(&st, &value);
		printf("%d\n", value);
	}
}

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

int main (){
	int count = 0;
	long long int sum = 0;
	int dump;
	int val1;
	int val2;
	long long int temp = 0;
	Stack st1, st2, stmin;
	CreateEmpty(&st1);
	CreateEmpty(&st2);
	CreateEmpty(&stmin);

	while (true) {
		scanf("%c", &temp);
		if (temp == '\n'){
			break;
		}
		else {
			Push(&st1, temp-48);
		}
  	}

  	while (true) {
    	scanf("%c", &temp);
    	if (temp == '\n'){
      		break;
    	}
    	else {
      		Push(&st2, temp-48);
    	}
  	}

	/*
	char c;
	scanf("%c", &c);
	while ( c >=48 && c <= 57){
		if (c >= 48 && c <= 57){
			Push(&st1, c-48);
		}
		scanf("%c", &c);
	}

	c = 0;
	scanf("%c", &c);
	while ( c >=48 && c <= 57){
		if (c >= 48 && c <= 57){
			Push(&st2, c-48);
		}
		scanf("%c", &c);
	}
	*/

	//printStack(st1);
	//printStack(st2);

	

	if (Top(st1) >= Top(st2)){
		while (!IsEmpty(st2)){
			Pop(&st2, &val2);
			Pop(&st1, &val1);
			temp = (val1- val2)* power(10, count);
			sum = sum + temp;
			count++;
		}
		//st2 habis tanpa s1 habis
		while (!IsEmpty(st1)){
			Pop(&st1, &val1);
			temp = (val1) * power(10,count);
			sum = sum + temp;
			count++;
		}
		printf("%lld\n", sum);

	} else {
		while (!IsEmpty(st1)){
			Pop(&st2, &val2);
			Pop(&st1, &val1);
			temp = (val2-val1) * power(10, count);
			sum = sum + temp;
			count++;
		}
		while (!IsEmpty(st2)){
			Pop(&st2, &val2);
			temp = val2 * power(10, count);
			sum = sum + temp;
			count++;
		}
		printf("%lld\n", sum*-1);
	}



	return 0;
}