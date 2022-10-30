/*********************************************/
/* Program   : list1.H                       */
/* Deskripsi : file HEADER modul list        */
/* NIM/Nama  : 24060121130075/Muhamad Ridwan Ash'shidqi*/
/* Tanggal   : 30 oktober 2022
/*********************************************/

#ifndef LIST1_H_INCLUDED
#define LIST1_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

typedef char infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
  infotype info;
  address next;
} ElmtList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
typedef struct
{
  address First;
} List;

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean ListEmpty(List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
/****************** Manajemen Memori ******************/
address Alokasi(infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi(address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
boolean FSearch(List L, address P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
address SearchPrec(List L, infotype X, address *Prec);
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast(List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVAfter2(List *L, infotype Prec, infotype X);
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter1(List *L, address Prec, address X);
/* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X);
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVLast(List *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVAfter2(List *L, address *X, address Y);
/* procedure DelVAfter2 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai address Y: nilai address disimpan pada X */
/*      dan alamat elemen X tersebut di-dealokasi */
void DelVAfter1(List *L, infotype *X, infotype Y);
/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter(List *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast(List *L, address P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP(List *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast(List *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter(List *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
int NbElmt(List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/

#endif // LIST1_H_INCLUDED
