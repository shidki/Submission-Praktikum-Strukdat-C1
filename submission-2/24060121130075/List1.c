/*********************************************/
/* Program   : list1.c                       */
/* Deskripsi : file HEADER modul list        */
/* NIM/Nama  : 24060121130075/Muhamad Ridwan Ash'shidqi*/
/* Tanggal   : 30 oktober 2022
/*********************************************/

#ifndef List1_c
#define List1_c

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/****************** TEST LIST KOSONG ******************/
boolean ListEmpty(List L){
/* Mengirim true jika list kosong */

/*Kamus Lokal*/

/*Algortima*/
    return First(L) == Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L){
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

/*Kamus Lokal*/

/*Algoritma*/
    First((*L)) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = (address)malloc(sizeof(ElmtList));
    if(P != Nil){
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/*Kamus Lokal*/

/*Algortima*/
    info((*P)) = 0;
    next((*P)) = Nil;
    (*P) = Nil;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/*Kamus Lokal*/
    address P;
    boolean found;
/*Algoritma*/
    P = First(L);
    found = false;
    while((P != Nil)&&(!found)){
        if(info(P)==X){
            found = true;
        }
        else{
            P = next(P);
        }
    }
    return P;
}

boolean FSearch(List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

/*Kamus Lokal*/
    boolean found;
    address PSearch;
/*Algoritma*/
    PSearch = First(L);
    found = false;
    while((PSearch != Nil)&&(!found)){
        if(PSearch = P){
            found = true;
        }
        else{
            PSearch = next(PSearch);
        }
    }
    return found;
}

address SearchPrec(List L, infotype X, address *Prec){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/

/*Kamus Lokal*/
    address P;
    //address Prec;
    boolean found;
/*Algortima*/
    (*Prec) = Nil;
    P = First(L);
    while((P != Nil)&&(!found)){
        if(info(P) == X){
            found = true;
        }
        else{
            (*Prec) = P;
            P = next(P);
        }
    }
    if(found){
        return (*Prec);
    }
    else{
        Prec = Nil;
        return (*Prec);
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertLast(L, P);
    }
}

void InsVAfter2(List *L, infotype Prec, infotype X){
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */

/*Kamus Lokal*/
    address P;
    address Q;
/*Alogritma*/
    P = Alokasi(X);
    Q = First(*L);
    if(ListEmpty((*L))){
        InsVFirst(&(*L), X);
    }
    else{
        while(info(Q) != Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

void InsVAfter1(List *L, address Prec, address X){
/* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */

/*Kamus Lokal*/

/*Algoritma*/
    next(X) = next(Prec);
    next(Prec) = X;
}
// void AdrLast (List *L, address *Prec, address *Last){
// /*procedure AdrLast (input/output L : List, output Prec,Last : address)*/
// /*I.S. List tidak kosong, dimungkinkan kosong*/
// /*F.S. menghasilkan alamat elemen terakhir (Last) dan sebelumnya (Prec)*/

//     /*Kamus Lokal*/

//     /*Algoritma*/
//     if(ListEmpty(*L)){
//         Prec = Nil;
//         Last = Nil;
//     }
//     else{
//         Prec = Nil;
//         Last = First(L);
//         while(next(Last) != Nil){
//             Prec = Last;
//             Last = next(Last);
//         }
//     }
// }


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X){
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */

/*Kamus Lokal*/
    address P;
/*Algortima*/
    P = First(*L);
    (*X) = info(P);
    First(*L) = next(P);
    next(P) = Nil;
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */

/*Kamus Lokal*/
    address P;
/*Algoritma*/
    DelLast(L, &P);
    (*X) = info(P);
    Dealokasi(&P);
}

void DelVAfter2(List *L, address *X, address Y){
/* procedure DelVAfter2 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai address Y: nilai address disimpan pada X */
/*      dan alamat elemen X tersebut di-dealokasi */

/*Kamus Lokal*/
    address P;
/*Algortima*/
    (*X) = next(Y);
    next(Y) = next(next(Y));
    Dealokasi(&(*X));
}

void DelVAfter1(List *L, infotype *X, infotype Y){
/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */

/*Kamus Lokal*/
    address P;
    address Q;
/*Algoritma*/
    P = First(*L);
    if(info(First(*L)) == Y){
        Q = next(P);
        (*X) = info(Q);
        next(P) = next(Q);
        next(Q) = Nil;
        Dealokasi(&Q);
    }
    else{
        while(info(P) != Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
        next(P) = next(Q);
        next(Q) = Nil;
        Dealokasi(&Q);
    }
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P){
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

/*Kamus Lokal*/

/*Algoritma*/
    next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*Kamus Lokal*/

/*Algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;
}

void InsertLast(List *L, address P){
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*Kamus Lokal*/
    address Last;
/*Algoritma*/
    if (First(*L) == Nil){
        InsertFirst (&(*L), P);
    }
    else{
        Last = First((*L));
        while((next(Last)) != Nil){
            Last = next(Last);
        }
        InsertAfter(&(*L), P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

/*Kamus Lokal*/

/*Algoritma*/
    if(!ListEmpty((*L))){
        (*P) = First(*L);
        First(*L) = next(First(*L));
    }
    else{
        printf("List Kosong");
    }
}

void DelP(List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/*Kamus Lokal*/
    address P;
    address Prec;
/*Algoritma*/
    if(!ListEmpty(*L)){
        if(info(First(*L)) == X){
            DelFirst(&(*L), &P);
        }
        else{
            Prec = First(*L);
            while(info(next(Prec)) != X){
                Prec = next(Prec);
            }
            DelAfter(&(*L), &P, Prec);
        }
    }
}

void DelLast(List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */

/*kamus Lokal*/
    address Last;
    address PrecLast;
/*Algoritma*/
    Last = First(*L);
    PrecLast = Nil;

    while(next(Last) != Nil){
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if(PrecLast == Nil){
        First(*L) = Nil;
    }
    else{
        next(PrecLast) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */

/*Kamus Lokal*/

/*Algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
    Dealokasi(&(*Pdel));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */

/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = First(L);
    if(P == Nil){
        printf("list Kosong\n");
    }
    else{
        while(next(P) != Nil){
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}

int NbElmt(List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/

/*Kamus Lokal*/
    int counter;
    address P;
/*Algoritma*/
    counter = 0;
    if(!ListEmpty(L)){
        P = First(L);
        while(P != Nil){
            counter++;
            P = next(P);
        }
    }
    return counter;
}

#endif /*List1_c*/
