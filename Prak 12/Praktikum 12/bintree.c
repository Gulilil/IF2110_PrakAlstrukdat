/*
    NIM                     : 13521116
    Nama                    : Juan Christopher Santoso
    Tanggal                 : 21 November 2022
    Topik praktikum         : Pra Praktikum 12
    Deskripsi               : Implementasi ADT Binary Tree
*/
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
    BinTree p;

    p = (Address) malloc (sizeof(TreeNode));
    if (p != NULL){
        ROOT(p) = root;
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
{
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
{
    Address branch;

    CreateTree(val, NULL, NULL, &branch);

    return branch;
}

void deallocTreeNode (Address p)
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
{
    free(p);
}

boolean isTreeEmpty (BinTree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    return (p == NULL);
}

boolean isOneElmt (BinTree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
    return (p != NULL && LEFT(p) == NULL && RIGHT(p) == NULL);
}

boolean isUnerLeft (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
{
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL);
}

boolean isUnerRight (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
{
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL);
}

boolean isBinary (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
{
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL);
}

/* ****** Display Tree ***** */
void printPreorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    printf("(");
    if (!isTreeEmpty(p)){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    printf("(");
    if (!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    printf("(");
    if (!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeInDepth(BinTree p, int h, int depth){
/* I.S. p terdefinisi, h adalah jarak indentasi, depth adalah kedalaman
F.S. pohon diprint sesuai dengan kedalamannya*/
    int i;
    if (!isTreeEmpty(p)){
        int indentCount = h*depth;
        for(i = 0; i < indentCount; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));

        printTreeInDepth(LEFT(p), h, depth+1);
        printTreeInDepth(RIGHT(p), h, depth+1);
    }
}
void printTree(BinTree p, int h)
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
{
    printTreeInDepth(p, h, 0);
}

int rob1(BinTree root)
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.
{
    if (isTreeEmpty(root)){
        return 0;
    } else {
        int leftRes = ROOT(root) + rob1(LEFT(root));
        int rightRes = ROOT(root) + rob1(RIGHT(root));
        if (leftRes > rightRes){
            return leftRes;
        } else {
            return rightRes;
        }
    }
}


int rob2(BinTree root)
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.
{
    if (isTreeEmpty(root)){
        return 0;
    }
    else {
        int oddLevel = ROOT(root);
        int evenLevel = 0;
        evenLevel += rob2(LEFT(root)) + rob2(RIGHT(root));
        if (!isTreeEmpty(RIGHT(root))){
            oddLevel += rob2(RIGHT(RIGHT(root))) + rob2(LEFT(RIGHT(root)));
        }
        if (!isTreeEmpty(LEFT(root))){
            oddLevel += rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root)));
        }
        if (oddLevel > evenLevel){
            return oddLevel;
        } else {
            return evenLevel;
        }
    }
}


/*
int oddLevelCounter(BinTree root){
    int oddLevelRes;
    if(isTreeEmpty(root)){
        return 0;
    } else {
        if (LEFT(root) == NULL && RIGHT(root) == NULL){
            oddLevelRes = ROOT(root);
        } else if (LEFT(root) == NULL){
            oddLevelRes = ROOT(root) + oddLevelCounter(LEFT(RIGHT(root))) + oddLevelCounter(RIGHT(RIGHT(root)));
        } else if (RIGHT(root) == NULL){
            oddLevelRes = ROOT(root) + oddLevelCounter(LEFT(LEFT(root))) + oddLevelCounter(RIGHT(LEFT(root)));
        } else {
            oddLevelRes = ROOT(root) + oddLevelCounter(LEFT(LEFT(root))) + oddLevelCounter(RIGHT(LEFT(root))) + oddLevelCounter(LEFT(RIGHT(root))) + oddLevelCounter(RIGHT(RIGHT(root)));
        }
    }
    return oddLevelRes;
}

int evenLevelCounter(BinTree root){
    int evenLevelRes;
    if(isTreeEmpty(root)){
        return 0;
    } else {
        // Hitung basis
        if (isOneElmt(root)){
            evenLevelRes = 0;
        } else if (isUnerLeft(root)){
            evenLevelRes = ROOT(LEFT(root));
        } else if (isUnerRight(root)){
            evenLevelRes = ROOT(RIGHT(root));
        } else {
            evenLevelRes = ROOT(LEFT(root)) + ROOT(RIGHT(root));
        }

        if (LEFT(root) != NULL && LEFT(LEFT(root)) != NULL){
            evenLevelRes += evenLevelCounter(LEFT(LEFT(root)));
        } 
        if (LEFT(root) != NULL && RIGHT(LEFT(root)) != NULL) {
            evenLevelRes += evenLevelCounter(RIGHT(LEFT(root)));
        }
        if (RIGHT(root) != NULL && LEFT(RIGHT(root)) != NULL){
            evenLevelRes += evenLevelCounter(LEFT(RIGHT(root)));
        }if (RIGHT(root) != NULL && RIGHT(RIGHT(root)) != NULL){
            evenLevelRes += evenLevelCounter(RIGHT(RIGHT(root)));
        }
    }
    return evenLevelRes;
}
*/