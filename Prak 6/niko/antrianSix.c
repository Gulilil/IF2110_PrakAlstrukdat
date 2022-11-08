// Nama: Nicholas Liem
// NIM: 13521135
// Tanggal: 13 Oktober 2022
// Topik Praktikum: ADT Queue

#include <stdio.h>
#include "queue.c"

int main(){

    Queue q;
    int op, waktu;
    int jumlahWaktu;
    int jumlahOperasi;
    int sekali = 0;
    int min, max;
    boolean program = 1;
    while(program)
    {
        scanf("%d %d", &op, &waktu);
        if (op == 1){
            if (isFull(q)){
                printf("Queue penuh\n");
            } else {
                if (sekali == 0){
                    sekali++;
                    enqueue(&q, waktu);
                    min = waktu;
                    max = waktu;
                } else {
                    enqueue(&q, waktu);
                }
            }
        } else if (op == 2){
            if (isEmpty(q)){
                printf("Queue kosong\n");
            }
            int tempWaktu;
            dequeue(&q, &tempWaktu);

            if (tempWaktu < min){
                min = tempWaktu;
            } else if (tempWaktu > max){
                max = tempWaktu;
            }
            jumlahWaktu += tempWaktu;
            jumlahOperasi++;
        } else if (op == 0){
            program = 0;
        }
    }
    if (jumlahOperasi == 0){
        printf("0\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%d\n", jumlahOperasi);
        printf("%d\n", min);
        printf("%d\n", max);
        printf("%.2f\n", jumlahWaktu/jumlahOperasi); 
    }


    return 0;
}