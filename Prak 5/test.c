#include <stdio.h>
#include "boolean.h"
#include "wordmachine.c"
#include "charmachine.c"


int main (){
	int i;
    STARTWORD();
    while(!EndWord){
    	LowerCase();
        for (i=0; i < currentWord.Length; i++){
            printf("%c", currentWord.TabWord[i]);
        } 
        printf(" ");
        ADVWORD();
    }


	return 0;
}