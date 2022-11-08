/*
    Nama                : Juan Christopher Santoso
    NIM                 : 13521116
    Tanggal             : 7 Oktober 2022
    Topik praktikum     : Latihan Praktikum 6
    Deskripsi           : Membuat ADT untuk prioqueuetime
*/

#include <stdio.h>
#include "prioqueuetime.h"

int main () {
    int n;
    int i;
    int time; int info;
    PrioQueueTime q;
    PrioQueueTime resQ;
    scanf("%d", &n);
    boolean program = true;
    int secCounter = 0;
    int currentTime = 0;
    int startTime;
    int endTime = 999;
    boolean processing = false;
    infotype var;

    MakeEmpty(&q, n);
    MakeEmpty(&resQ, n);

    // Masih ada yang dimasukkan
    for (i = 0; i < n; i++){
        // PrintPrioQueueTime(q);
        // dequeue dulu baru masukin yang baru
        if (currentTime == endTime){
            processing = false;
        }
        // masukin elemen baru
        infotype process;
        scanf("%d %c", &time, &info);
        Time(process) = time;
        Info(process) = info;
        Enqueue(&q, process);

        // setiap memulai process baru, dimasukkan ke dalam resQ
        if (!processing) {
            endTime = currentTime + Time(Elmt(q, Head(q)));
            processing = true;
            infotype history;
            Time(history) = currentTime;
            Info(history) = Info(Elmt(q,Head(q)));
            Enqueue(&resQ, history);
            Dequeue(&q, &var);
        }

        currentTime++;
    }

    // kasih handle buat yang udah ga ada masukkan
    while (!IsEmpty(q)){
        // PrintPrioQueueTime(q);
        // dilakukan hingga elemen pada q bersisa 1
        // case terakhir tidak perlu di print
        if (currentTime == endTime){
            processing = false;
        }
        if (!processing) {
            endTime = currentTime + Time(Elmt(q, Head(q)));
            processing = true;
            infotype history;
            Time(history) = currentTime;
            Info(history) = Info(Elmt(q,Head(q)));
            Enqueue(&resQ, history);
            Dequeue(&q, &var);
        }

        currentTime++;
    }

    // print nya sedikit berbeda dengan PrintPrioQueueTime(resQ);
    if (Tail(resQ) < Head(resQ)){
        // Melakukan print mulai dari Head - MaxEl, lalu 0 - Tail
        for (i = Head(resQ); i < MaxEl(resQ);i++){
            printf("%d %c\n", Time(Elmt(resQ,i)), Info(Elmt(resQ,i)));
        }
        for (i = 0; i <= Tail(resQ); i++){
            printf("%d %c\n", Time(Elmt(resQ,i)), Info(Elmt(resQ,i)));
        }
    }else{
        for (i = Head(resQ); i <= Tail(resQ);i++){
            // Melakukan print mulai dari Head - Tail
            printf("%d %c\n", Time(Elmt(resQ,i)), Info(Elmt(resQ,i)));
        }
    }


    return 0;
}