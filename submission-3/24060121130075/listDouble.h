/*********************************************/
/* Program   : listDouble.h                       */
/* Deskripsi : file HEADER modul list        */
/* NIM/Nama  : 24060121130075/Muhamad Ridwan Ash'shidqi*/
/* Tanggal   : 26 november 2022
/*********************************************/
#ifndef LISTDOUBLE_H_INCLUDED
#define LISTDOUBLE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist{
    infotype info;
    address prev;
    address next;
}ElmtList;

typedef struct {
    address First;
    address Last;
}List;

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool ListEmpty(List L);
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
bool FSearch(List L, address P);
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
/*** PENGHAPUSAN ELEMEN ***/
void InsVAfter(List *L, infotype Prec, infotype X);
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void DelVFirst(List *L, infotype *X);
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVLast(List *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVAfter(List *L, infotype *X, infotype Y);
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
void DelP(List *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
int NbElmt(List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max(List L);
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax(List L);
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min(List L);
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin(List L);
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average(List L);
/* Mengirimkan nilai rata-rata info(P) */
/****************** PROSES TERHADAP LIST ******************/
void AdrLast(List *L, address *Prec, address *Last);
/*mencari alamat elemen terakhir dan sebelumnya*/
void DelAll(List *L);
/* Delete semua elemen list dan alamat elemen di-dealokasi */
void InversList(List *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
List FInversList(List L);
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
void CopyList(List *L1, List *L2);
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
List FCopyList(List L);
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
void CpAlokList(List Lin, List *Lout);
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
void Konkat(List L1, List L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang baru */
/* Elemen L3 adalah hasil alokasi elemen yang baru */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
void Konkat1(List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void PecahList(List *L1, List *L2, List L);
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */

#endif
