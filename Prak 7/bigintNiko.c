
#include "stack.c"
#include <stdio.h>
#include <math.h>

void printStack(Stack s){
    int temp;
    while(!IsEmpty(s)){
        Pop(&s, &temp);
        printf("%d\n", temp);
    }
}

int main(){
	Stack S1, S2;
	CreateEmpty(&S1);
	CreateEmpty(&S2);

	char temp;
  	while (true) {
    scanf("%c", &temp);
    if (temp == '\n'){
      break;
    }
    else {
      Push(&S1, temp-48);
    	}
  	}

  	while (true) {
    scanf("%c", &temp);
    if (temp == '\n'){
      break;
    }
    else {
      Push(&S2, temp-48);
    	}
  	}
    
    //Artinya S1 lebih kecil bilangannya dari pada S2
    int dump;
    int count = 0;
    long long int longS1, longS2, hasil;
    
    while(!IsEmpty(S1)){
        Pop(&S1, &dump);
        if (count == 0){
            longS1 = dump;
        } else {
            hasil = dump * pow(10, count);
            longS1 += hasil;
        }
        count++;
    }

    count = 0;
    while(!IsEmpty(S2)){
        Pop(&S2, &dump);
        if (count == 0){
            longS2 = dump;
        } else {
            hasil = dump * pow(10, count);
            longS2 += hasil;
        }
        count++;
    }
    // printf("s1 %lld\n", longS1);
    // printf("s2 %lld\n", longS2);
    
    printf("%lld\n", longS1-longS2);
    
    // // printf("%lld\n", longS1);
    // // printf("%lld\n", longS2);

  	// long long res;
  	// if (longS1 < longS2){
  	// 	res = longS2 - longS1;
  	// } else {
  	// 	res = longS1 - longS2;
  	// }

  	// printf("%lld\n", res);

	return 0;
}