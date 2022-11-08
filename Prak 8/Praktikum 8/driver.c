#include <stdio.h>
#include "listlinier.c"

int main () {
	List l;
	CreateList(&l);
	List l2;
	CreateList(&l2);
	List l3;
	CreateList(&l3);
	List lnew;
	CreateList(&lnew);


	insertLast(&l, 2);

	insertLast(&l, 10);
	insertLast(&l, 3);
	insertLast(&l, 7);
	insertLast(&l, 8);
	insertLast(&l, 5);
	insertLast(&l, 1);
	insertLast(&l, 10);
	insertLast(&l, 7);

	displayList(l); printf("\n");
	int nmax;
	nmax = max(l);
	printf("%d\n", nmax);
	Address haha = searchPrec(l, nmax);
	printf("%d\n", INFO(haha));

	/*
	deleteAll(&l);
	displayList(l); printf("\n");
	copyList(&l, &l2);
	inverseList(&l);
	displayList(l);printf("\n");
	*/

	splitList(&l2, &l3, l);
	displayList(l2);printf("\n");
	displayList(l3);printf("\n");
	lnew = concat(l3, l2);
	displayList(lnew); printf("\n");
	displayList(l); printf("\n");

	/*
	Address hehe = searchPrec(l, 7);
	int hua = INFO(hehe);
	printf("%d\n", hua);

	boolean test = fSearch(l, hehe);
	if (test){
		printf("bener\n");
	} else {
		printf("salah\n");
	}
	*/
	/*
	float huehue = 152.31;
	float huahua = 190;
	printf("%f", (huehue+huahua)/380);
	*/
}