#include <stdio.h>
#include "point.c"
#include "time.c"
#include "garis.c"
#include <stdbool.h>

int main () {

    GARIS L;

    BacaGARIS(&L);

    TulisGARIS(L);
    return 0;
}