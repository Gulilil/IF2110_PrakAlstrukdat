/*
    NIM                     : 13521116
    Nama                    : Juan Christopher Santoso
    Tanggal                 : 6 November 2022
    Topik praktikum         : Praktikum 10
    Deskripsi               : Menggunakan queue untuk perhitungan bulat kotak
*/


#include "boolean.h"
#include "queuelinked.h"
#include "charmachine.h"
#include <stdio.h>

boolean isAllZero(Queue q){
	Address p = ADDR_HEAD(q);
	while (p != NULL){
		if (INFO(p) == 1){
			return false;
		}
		p = NEXT(p);
	}
	return true;
}

boolean isAllOne(Queue q){
	Address p = ADDR_HEAD(q);
	while( p != NULL){
		if (INFO(p) == 0){
			return false;
		}
		p = NEXT(p);
	}
	return true;
}

int main () {
	Queue sandwich;
	Queue siswa;
	Queue nomorSiswa;
	CreateQueue(&sandwich);
	CreateQueue(&siswa);
	CreateQueue(&nomorSiswa);

	int val;
	int valNo;

	boolean afterComma = false;
	int nomor = 0;

	START();
	while(!EOP){
		if (currentChar == ','){
			afterComma = true;
			ADV();
		}
		if (!afterComma){
			if (currentChar == 'B'){
				enqueue(&siswa, 0);
			} else if (currentChar == 'K'){
				enqueue(&siswa, 1);
			}
			nomor++;
			enqueue(&nomorSiswa, nomor);
		} else {
			if (currentChar == 'B'){
				enqueue(&sandwich,0);
			} else if (currentChar == 'K'){
				enqueue(&sandwich,1);
			}
		}
		ADV();
	}
	/*
	DisplayQueue(nomorSiswa);
	DisplayQueue(siswa);
	DisplayQueue(sandwich);
	*/

	boolean possible = true;
	while (!isEmpty(siswa) && possible){
		// check apakah dia possible
		// DisplayQueue(siswa);
		// DisplayQueue(sandwich);
		if ((isAllOne(siswa) && (HEAD(sandwich)== 0) )||(isAllZero(siswa) && (HEAD(sandwich) == 1)) ){
			possible = false;
		}
		if (possible){
			//cek dia sama ato engga
			if (HEAD(siswa) == HEAD(sandwich)){
				dequeue(&siswa, &val);
				dequeue(&sandwich, &val);
				dequeue(&nomorSiswa, &valNo);
				if (val == 0){
					printf("%d -> bulat\n", valNo);
				} else {
					printf("%d -> kotak\n", valNo);
				}
			}
			else {
				dequeue(&siswa, &val);
				dequeue(&nomorSiswa, &valNo);
				enqueue(&siswa, val);
				enqueue(&nomorSiswa, valNo);
			}

		}
	}
	int len = length(siswa);
	printf("%d\n", len);


	return 0;
}