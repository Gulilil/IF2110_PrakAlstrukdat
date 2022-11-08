#include <stdio.h>
#include "prioqueuetime.c"

int main() {
    int max;
    infotype haha;
    PrioQueueTime q;
    scanf("%d", &max);

    ReadPrioQueueTime(&q, max);

    printf("===========================\n");

    Dequeue(&q, &haha);
    printf("%d %c\n", Time(haha), Info(haha));
    printf("===========================\n");
    PrintPrioQueueTime(q);
    printf("%d\n", NBElmt(q));

    return 0;
}