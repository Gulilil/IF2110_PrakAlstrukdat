#include <stdio.h>
#include "wordmachine.c"
#include "charmachine.c"

int main (){
    int i;
    STARTWORD();
    while(!EndWord){
        for (i=0; i < currentWord.Length; i++){
            printf("%c", currentWord.TabWord[i]);
        } 
        printf("\n");
        ADVWORD();
    }

    return 0;
}