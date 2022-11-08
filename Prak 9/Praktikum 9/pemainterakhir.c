/*
    NIM                     : 13521116
    Nama                    : Juan Christopher Santoso
    Tanggal                 : 30 Oktober 2022
    Topik praktikum         : Praktikum 9
    Deskripsi               : Mencari pemain terakhir dari suatu game
*/



#include <stdio.h>
#include "boolean.h"
#include "list_circular.h"

int main () {
	List l;
	CreateList(&l);
	int n;
	scanf("%d", &n);

	int k; // variabel untuk angka ajaib
	scanf("%d", &k);

	// Memasukkan nilai pada list
	int i;
	for (i = 0; i < n; i++){
		insertLast(&l, i+1);
	}

	int val;
	int count = 1;
	int amount = n; // Variabel ini menunjuk pada sisa pemain

	// displayList(l); // Hanya untuk checking

	if (k == 1){
		while (!isEmpty(l) && amount > 1){
			deleteFirst(&l, &val);
			count = 1;
			amount--;
			printf("%d\n", val);
		}
	}
	else {
		while (!isEmpty(l) && amount > 1){
			// dikurangi terus hingga habis
			//printf("%d %d\n", count, INFO(FIRST(l)));
			count++;
			FIRST(l) = NEXT(FIRST(l));

			if (count == k){
				deleteFirst(&l, &val);
				count = 1;
				amount--;
				printf("%d\n", val);
			}
		}
	}
	// berhenti saat amount == 1
	deleteFirst(&l, &val);
	printf("Pemenang %d\n", val);

	return 0;
}