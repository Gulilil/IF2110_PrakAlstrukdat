#include <stdio.h>
#include "stacklinked.c"

int main () {
    Stack s;
    int len;
    int dump = 0;
    CreateStack(&s);

    DisplayStack(s);
    len = length(s);
    printf("%d\n", len);

    push(&s, 3);
    push(&s, 4);
    //DisplayStack(s);
    len = length(s);
    printf("%d\n", len);

    push(&s, 5);
    push(&s, 6);
    len = length(s);
    printf("%d\n", len);
    DisplayStack(s);

    pop(&s, &dump);
    pop(&s, &dump);
    DisplayStack(s);
    printf("%d\n", dump);
    


    
}