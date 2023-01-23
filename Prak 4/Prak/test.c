#include <stdio.h>
#include "matrix.c"

int main (){
	
	
	Matrix m;
	int row;
	int col;
	scanf("%d %d\n", &row, &col);
	readMatrix(&m, row, col);

	printf("================================\n");
	displayMatrix(m);
	printf("================================\n");

	// float test;
	// int haha;
	// test = AvgRow(m, 1);
	// printf("%f\n", test);
	// test = AvgCol(m, 1);
	// printf("%f\n", test);
	// haha = CountNumRow(m, 1,4);
	// printf("%d\n", haha);
	// haha = CountNumCol(m, 1,4);
	// printf("%d\n", haha);
	// */

	RotateMat(&m);
	displayMatrix(m);

	return 0;
}