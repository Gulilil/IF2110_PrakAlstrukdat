#include <stdio.h>
#include "list_circular.c"

void deleteRR (List *l, ElType tQ){
    int val;
        // Handle list kosong
    if (isEmpty(*l)){
        printf("List kosong\n");
    }
    else {
        // Mengambil val dari last
        deleteLast(l, &val);
        if (val > tQ){
            insertFirst(l, val-tQ);
            printf("%d\n", tQ);
        } else {
            // Menampilkan x
            printf("%d\n", val);
        }
        // Jika val <= tq delete saja
    }

}

float average (List l){
/* Menghasilkan nilai rata-rata elemen l. L tidak kosong*/
    float count = 0;
    float sum = 0;
    int val;
    while (!isEmpty(l)){
        deleteFirst(&l, &val);
        sum += val;
        count ++;
    }
    return (sum/count);

}

int main () {
    List cl;
    CreateList(&cl);
    int tq;
    char operator;
    int time;
    int val;

    scanf("%d", &tq);
    //printf("%d", tq);
    while (tq <= 0){
        scanf("%d", &tq);
    }
    boolean program = true;

    while (program){
        scanf(" %c", &operator);

        if (operator == 'F'){
            program = false;
        } else if (operator == 'A'){
            scanf("%d", &time);
            // Hanya dilakukan bila time lebih dari 0
            if (time > 0){
                insertFirst(&cl, time);
            }
        } else if (operator == 'D'){
            deleteRR(&cl, tq);
        } else {
            printf("Kode salah\n");
        }
    }

    if (isEmpty(cl)){
        printf("Proses selesai\n");
    } else {
        float avg = average(cl);
        printf("%.2f\n", avg);
    }
}