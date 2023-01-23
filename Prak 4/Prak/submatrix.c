/* 
    NIM					: 13521116
    Nama				: Juan Christopher Santoso
    Tanggal				: 22 September 2022
    Topik praktikum		: Praktikum 4
    Deskripsi			:

 */

#include <stdio.h>
#include "matrix.h"

int zeroCounter(Matrix m){
	// fungsi untuk menghitung banyaknya 0 pada suatu matriks
	int i;
	int j;
	int count = 0;
	for (i = 0; i < ROW_EFF(m); i++){
		for (j = 0; j < COL_EFF(m); j++){
			if (ELMT(m, i,j) == 0){
				count++;
			}
		}
	}
	return count;
}


int main (){
	int n;
	int m;
	int count; // variabel penghitung 0
	int min; // variabel untuk penyimpan paling banyak tidak nol
	// Asumsikan terlebih dahulu bahwa nilai min 0 terdapat pada daerah 1;
	int minCount;
	// minCount adalah variabel untuk menyimpan berapa banyak 0 pada daerah minimum 0
	int i;
	int j;

	int k;
	int l;
	int tempRow;
	int tempCol;
	int index;

	scanf("%d", &n);
	scanf("%d", &m);

	int rowDaerah = n - m + 1;
	int colDaerah = n - m + 1;

	Matrix matriks;
	readMatrix(&matriks, n, n);

	// loop sebanyak yang dibutuhkan
	for (i = 0; i < rowDaerah ; i++){
		for (j = 0; j < colDaerah; j++){

			index = (n-m+1)*i + j + 1;

			Matrix mTemp;
			createMatrix(m, m, &mTemp);


			tempRow = 0;
			// Membuat sub matriks baru
			for (k = i; k < i+m; k++ ){
				tempCol = 0;
				for (l = j; l < j+m; l++){
					ELMT(mTemp, tempRow, tempCol ) = ELMT(matriks, k, l);
					tempCol++;
				}
				tempRow++;
			}

			//displayMatrix(mTemp);

			// Selesai membuat matriks baru maka dihitung banyaknya tidak 0
			count = zeroCounter(mTemp);
			if (index == 1){
				min = 1;
				minCount = count;
			} else {
				if (count < minCount){
					min = index;
					minCount = count;
				}
			}
			//printf("%d %d\n", count, min);

		}
	}
	printf("%d\n", min);

	return 0;
}