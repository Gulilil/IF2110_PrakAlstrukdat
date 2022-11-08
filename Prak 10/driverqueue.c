#include <stdio.h>
#include "queuelinked.c"

int main () {
    Queue q;
    int len;
    int dump;
    CreateQueue(&q);

    DisplayQueue(q);

    enqueue(&q, 3);
    enqueue(&q, 4);
    DisplayQueue(q);
    len = length(q);
    printf("%d\n", len);

    dequeue(&q, &dump);
    len = length(q);
    printf("%d %d\n", len, dump);
    dequeue(&q, &dump);
    DisplayQueue(q);
    
}