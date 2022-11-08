/*
NIM                     : 13521116
Nama                    : Juan Christopher Santoso
Tanggal                 : 24 Oktober 2022
Topik praktikum         : Praktikum 8
Deskripsi               : Menghitung ratio adanya suatu val pada linked list
*/


#include <stdio.h>
#include "listlinier.h"

int main () {

	int nElmt;
	int n;
	int i;
	int val;
	int idx;
	int temp;
	float hitCount = 0;
	List l;
	CreateList(&l);

	scanf("%d", &nElmt);
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &val);
		idx = indexOf(l, val);

		if (nElmt == 0){
			printf("miss ");
			displayList(l);
			printf("\n");
		}
		else {
			// Kondisi untuk kondisi maks n tidak 0
			if (idx == IDX_UNDEF){
				// Kondisi untuk miss
				printf("miss ");
				if (length(l) < nElmt){
					insertFirst(&l, val);
				} else {
					deleteLast(&l, &temp);
					insertFirst(&l, val);
				}
				displayList(l);
				printf("\n");
			} else {
				// Untuk hit
				printf("hit ");
				if (length(l) < nElmt){
					deleteAt(&l, idx, &temp);
					insertFirst(&l, val);
				} else {
					deleteAt(&l, idx, &temp);
					insertFirst(&l, val);
				}
				displayList(l);
				printf("\n");
				hitCount++;
			}

		}
	}
	if (n == 0 || nElmt == 0){
		printf("hit ratio: 0.00\n");
	} else {
	printf("hit ratio: %.2f\n", (float) hitCount/ (float) n);
	}

	return 0;
}