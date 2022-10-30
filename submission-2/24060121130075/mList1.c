/*********************************************/
/* Program   : list1.H                       */
/* Deskripsi : file HEADER modul list        */
/* NIM/Nama  : 24060121130075/Muhamad Ridwan Ash'shidqi*/
/* Tanggal   : 30 oktober 2022
/*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List1.c"

int main(void){
    /*Kamus Lokal*/
    List L1, L2, L3, L4;
    address P1, P2, P3, P4, P5;
    address F1, F2, F3, Prec1, Prec2;
    infotype T1;

    /*Algoritma*/

    /*Membuat List*/
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);

    /*Memeriksa apakah list kosong*/
    printf("======================CEK APAKAH LIST KOSONG=============================\n");
    printf("Apakah List L1 Kosong : %s\n", ListEmpty(L1)?"True":"False");
    printf("Apakah List L2 Kosong : %s\n", ListEmpty(L2)?"True":"False");
    printf("Apakah List L3 Kosong : %s\n", ListEmpty(L3)?"True":"False");
    printf("\n");

    /*Melakukan alokasi dan memasukan nilainya kedalam List */
    P1 = Alokasi(1);
    P2 = Alokasi(2);
    P3 = Alokasi(6);
    P4 = Alokasi(3);
    P5 = Alokasi(5);

	printf("======================CEK APAKAH ELEMEN LIST KOSONG=============================\n");
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    printf("Elemen pada List L2 adalah : ");
    Printinfo(L2);
    printf("Elemen pada List L3 adalah : ");
    Printinfo(L3);
    printf("\n");

	printf("======================MEMASUKKAN ELEMEN =============================\n");
    InsertFirst(&L1, P1);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, P4);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, P5);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertAfter(&L1, P2, P1);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertLast(&L1, P3);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    printf("\n");

   
    printf("======================PRINT ALAMAT=============================\n");
    printf("Alamat elemen pertama L1 adalah : %d\n", First(L1));
    F1 = Search(L1, 1);
    printf("Alamat elemen terakhir L1 adalah : %d\n", F1);
    printf("\n");

    /*mencari elemen pada list*/
    printf("======================SEARCH ELEMEN=============================\n");
    F1 = Search(L1, 2);
    printf("elemen 3, ditemukan pada alamat = %d\n", F1);
    printf("apakah address P1 sama dengan F1? %d\n", P1 == F1);

    printf("\nmencari elemen pada list dengan fungsi Fsearch\n");
	printf("Apakah terdapat alamat %d didalam list? %d\n", P2, FSearch(L1, P2));

	printf("\nmencari elemen pada list dengan fungsi SearchPrec\n");
	printf("alamat sebelum elemen 2 pada list L1 adalah = %d\n\n", SearchPrec(L1, 2, &Prec1));

	/*menghapus elemen pada list*/
	printf("======================DELETE ELEMEN=============================\n");
	printf("\nmenghapus elemen pertama pada list dengan fungsi DelFirst\n");
	DelFirst(&L1, &F1);
	printf("address elemen pertama adalah %d, address elemen yang dihapus adalah %d\n", P5, F1);
	printf("info pada address P5 adalah %d, info pada address F1 adalah %d\n", info(P5), info(F1));
	Printinfo(L1);

	printf("\nmenghapus elemen 3 dari list dengan fungsi DelP\n");
	DelP(&L1, 3);
	Printinfo(L1);

	printf("\nmenghapus elemen terakhir dari list dengan fungsi DelLast\n");
	DelLast(&L1, &F1);
	Printinfo(L1);

	printf("\nmenghapus elemen kedua dari list dengan fungsi DelAfter\n");
	DelAfter(&L1, &F1, P4);
	Printinfo(L1);

	
	printf("======================MEMASUKKAN ELEMEN PRIMITIF BERDASAR NILAI=============================\n");
	printf("\nmemasukkan elemen 15 kedalam list L2 dengan fungsi InsVFirst\n");
	InsVFirst(&L2, 15);
	Printinfo(L2);

	printf("\nmemasukkan elemen 14 kedalam list L2 dengan fungsi InsVLast\n");
	InsVLast(&L2, 14);
	Printinfo(L2);

	printf("\nmemasukkan elemen tambahan kedalam list L2\n");
	InsVFirst(&L2, 16);
	InsVFirst(&L2, 17);
	InsVLast(&L2, 13);
	Printinfo(L2);

	/*menghapus elemen pada list v2*/
	printf("======================MENGHAPUS ELEMEN PRIMITIF BERDASAR NILAI=============================\n");
	printf("\nmenghapus elemen pertama dari list L2 dengan fungsi DelVFirst\n");
	DelVFirst(&L2, &T1);
	Printinfo(L2);

	printf("\nmenghapus elemen terakhir dari list L2 dengan fungsi DelVLast\n");
	DelVLast(&L2, &T1);
	Printinfo(L2);

	/*menambahkan elemen*/
	printf("======================MENAMBAHKAN ELEMEN AFTER=============================\n");
	printf("\nmemasukkan elemen 15 kedalam list L3 dengan fungsi InsVFirst\n");
	InsVLast(&L3, 15);
	Printinfo(L3);
	printf("\nmenambahkan elemen dengan fungsi InsVAfter1\n");
	P1 = Alokasi(1);
	InsertFirst(&L3, P1);
	InsVAfter1(&L3, P1, Alokasi(12));
	Printinfo(L3);

	printf("\nmenambahkan elemen dengan fungsi InsVAfter2\n");
	InsVAfter2(&L3, 15, 30);
	Printinfo(L3);

	/*menghapus elemen*/
	printf("======================MENGHAPUS ELEMEN AFTER=============================\n");
	printf("\nmenghapus elemen dengan fungsi DelVAfter1\n");
	DelVAfter1(&L3, &T1, 12);
	Printinfo(L3);

	printf("\nmenghapus elemen dengan fungsi DelVAfter2\n");
	DelVAfter2(&L3, &F1, P1);
	Printinfo(L3);

	/*menghitung jumlah elemen*/
	printf("\nmenghitung jumlah elemen pada L3, dengan fungsi NbElmt\n");
	printf("Jumlah elemen pada L3 adalah: %d\n", NbElmt(L3));

    return 0;
}
