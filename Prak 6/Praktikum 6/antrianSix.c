/*
    Nama                : Juan Christopher Santoso
    NIM                 : 13521116
    Tanggal             : 7 Oktober 2022
    Topik praktikum     : Latihan Praktikum 6
    Deskripsi           : Membaca queue dengan menentukan rata-rata, maksimum, dan minimum antrian
*/

#include <stdio.h>
#include "queue.h"
#include "boolean.h"

int main(){
    boolean program = true;
    int time;
    int count = 0;
    int minTime;
    int maxTime;
    int operator;
    int sumTime = 0;
    Queue q;
    CreateQueue(&q);

    while (program){
        scanf("%d", &operator);
        if (operator == 0){
            program = false;
        }
        else if (operator == 1){
            scanf("%d", &time);
            if (isFull(q)){
                printf("Queue penuh\n");
            } else {
                enqueue(&q, time);
            }
        }
        else if (operator == 2){
            if (isEmpty(q)){
                printf("Queue kosong\n");
            } else {
                dequeue(&q, &time);

                count++;
                sumTime += time;
                if (count == 1){
                    minTime = time;
                    maxTime = time;
                } else {
                    if (time < minTime){
                        minTime = time;
                    }
                    if (time > maxTime){
                        maxTime = time;
                    }
                }

            }
        }
    }

    printf("%d\n", count);
    if (count == 0){
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%d\n", minTime);
        printf("%d\n", maxTime);
        printf("%.2f\n", (float) sumTime/ (float) count);
    }

    return 0;
}