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
        if (Top(st) == 0){
            Pop(&st, &value);
            printf("%d\n", value);
        } else {
            Pop(&st, &value);
            printf("%d", value);
        }
	}
}

boolean isGE(Stack st1, Stack st2){
    int val1, val2;
    boolean result = true;
    if (Top(st1) > Top(st2)){
        return true;
    } else if (Top(st2) > Top(st1)) {
        return false;
    } else { 
        // ukurannya sama
        while (!IsEmpty(st1)){
            Pop(&st1, &val1);
            Pop(&st2, &val2);
            if (val1 > val2){
                result = true;
            } else if( val2 > val1){
                result = false;
            }
        }

        return result;
    }
}

void minus(Stack st1, Stack st2, Stack *stRes){
    // kondisi st1 >= st2
    int carry = 0;
    int temp;
    int newTemp;
    int limit = Top(st2);
    int i;
    int val1, val2;
    for (i = 0; i <= limit; i++){
        Pop(&st1, &val1);
        Pop(&st2, &val2);
        temp = val1 - val2 - carry;
        if (temp < 0){
            newTemp = temp + 10;
            carry = 1;
        } else {
            newTemp = temp;
            carry = 0;
        }
        //printf("res %d\n", newTemp);
        Push(stRes, newTemp);
    }
    while (!IsEmpty(st1)){
        Pop(&st1, &val1);
        temp = val1 - carry;
        if (temp < 0){
            newTemp = temp + 10;
            carry = 1;
        } else {
            newTemp = temp;
            carry = 0;
        }
        Push(stRes, newTemp);
    }
}

void delTrailZero( Stack *st){
    int dump;
    while (InfoTop(*st) == 0 && Top(*st)> 0){
        Pop(st, &dump);
    }
}




int main () {
    Stack st1, st2, stRes;
    char string1[200], string2[200];
    CreateEmpty(&st1);
    CreateEmpty(&st2);
    CreateEmpty(&stRes);
    char cChar;

    int i = 0;
    fgets(string1, 200, stdin);
    while(string1[i] != '\n') {
        if (string1[i] >= 48 && string1[i] <= 57){
            Push(&st1, string1[i]-48);
        }
        i++;
    }

    i = 0;
    fgets(string2, 200, stdin);
    while(string2[i] != '\n'){
        if (string2[i] >= 48 && string2[i] <= 57){
            Push(&st2, string2[i]-48);
        }
        i++;
    }
    // printStack(st1);
    // printf("=============\n");
    // printStack(st2);
    if (isGE(st1, st2)){
        //printf("lebih besar\n");
        minus(st1, st2, &stRes);
        delTrailZero(&stRes);
        printStack(stRes);
    } else {
        //printf("lebih kecil\n");
        minus(st2, st1, &stRes);
        delTrailZero(&stRes);
        printf("-");
        printStack(stRes);
    }



    return 0;
}
