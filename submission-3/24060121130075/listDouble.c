/*********************************************/
/* Program   : listDouble.c                       */
/* Deskripsi : coding List Double Linear        */
/* NIM/Nama  : 24060121130075/Muhamad Ridwan Ash'shidqi*/
/* Tanggal   : 26 november 2022
/*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"

bool ListEmpty(List L){
    return First(L) == Nil && Last(L) == Nil;
    //return First(L) == Nil;
}
void CreateList(List *L){
    First((*L)) = Nil;
    Last((*L)) = Nil;
    //First((*L)) = Nil;
}
address Alokasi(infotype X){
    address P = (address)malloc(sizeof(ElmtList));
    if(P!=Nil){
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}
void Dealokasi(address *P){
    free(*P);
}
address Search(List L, infotype X){
    address P = First(L);
    while(P!=Nil){
        if(X == info(P)){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}
bool FSearch(List L, address P){
    address Q = First(L);
    while(Q!=Nil){
        if(Q==P){
            return true;
        }else{
            Q = next(Q);
        }
    }
    return false;
}
address SearchPrec(List L, infotype X, address *Prec){
    address P = First(L);
    while(next(P)!=Nil){
        if(info(next(P))==X){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}
void InsVFirst(List *L, infotype X){
    address P = Alokasi(X);
    InsertFirst(&(*L),P);
}
void InsVLast(List *L, infotype X){
    address P = Alokasi(X);
    InsertLast(&(*L),P);
}
void InsVAfter(List *L, infotype Prec, infotype X){
    address P = Alokasi(X);
    address Q = First((*L));
    if(ListEmpty((*L))){
        InsVFirst(&(*L),X);
    }else{
        while(info(Q)!=Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}
void DelVFirst(List *L, infotype *X){
    address P;
    DelFirst(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}
void DelVLast(List *L, infotype *X){
    address P;
    DelLast(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}
void DelVAfter(List *L, infotype *X, infotype Y){
    address P = First(*L);
    address Q;
    if(info(First(*L))==Y){
        Q = next(P);
        (*X) = info(P);

    }else{
        while(info(P)!=Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
    }
    next(P) = next(Q);
    next(Q) = Nil;
    //prev(next(Q)) = P;
    Dealokasi(&Q);
}
void InsertFirst(List *L, address P){
    if(!ListEmpty(*L)){
        next(P) = First(*L);
        prev(First(*L)) = P;
    }else{
        Last(*L) = P;
    }
    First(*L) = P;
}
void InsertAfter(List *L, address P, address Prec){
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}
void InsertLast(List *L, address P){
    if(!ListEmpty(*L)){
        prev(P) = Last(*L);
        next(Last(*L)) = P;
    }else{
        First(*L) = P;
    }
    Last(*L) = P;

    // address Last;
    // if (ListEmpty(*L)){
    //     InsertFirst(L, P);
    // }
    // else{
    //     Last = First(*L);
    //     while (next(Last) != Nil)
    //     {
    //         Last = next(Last);
    //     }
    //     next(Last) = P;
    //     prev(P) = Last;
    //     next(P) = Nil;
    // }
}
void DelFirst(List *L, address *P){
    (*P) = First(*L);
    First(*L) = next(First(*L));
    prev(First(*L)) =Nil;
}
void DelLast(List *L, address *P){
    *P = Last(*L);
    Last(*L) = prev(*P);
    if(Last(*L) != Nil){
        next(Last(*L)) = Nil;
    }else{
        First(*L) = Nil;
    }
    prev(*P) = Nil;

    // address Last;
    // if (!(ListEmpty(*L))){
    //     Last = First(*L);
    //     while (next(Last) != Nil)
    //     {
    //         Last = next(Last);
    //     }
    //     (*P) = Last;
    //     if (prev(*P) == Nil)
    //     {
    //         First(*L) = Nil;
    //     }
    //     else
    //     {
    //         Last = prev(*P);
    //         next(Last) = Nil;
    //     }
    // }
}
void DelAfter(List *L, address *Pdel, address Prec){
    address P = next(Prec);
    (*Pdel) = P;
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    Dealokasi(&P);
}
void DelP(List *L, infotype X){
    address P = First(*L);
    address Q;
    if(info(P)==X && next(P) == Nil){
        DelFirst(&(*L),&P);
    }else{
        while(info(next(P)) != X){
            P = next(P);
        }
        DelAfter(&(*L),&Q,P);
    }
}
void Printinfo(List L){
    address P= First(L);
    if (!ListEmpty(L))
    {
        while (next(P) != Nil)
        {
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}
int NbElmt(List L){
    int counter = 0;
    address P = First(L);
    while(P!=Nil){
        counter++;
        P=next(P);
    }
    return counter;
}

void DelAll(List *L){
    //kamus lokal
    address P;
    //algoritma
    P = First(*L);
    while(next(P) != Nil){
        P = next(P);
        Dealokasi(&prev(P));
    }
    Dealokasi(&P);
    First(*L) = Nil;
    Last(*L) = Nil;
}
void InversList (List *L){
//kamus lokal
	address P,Q,N;
//algoritma
	P = next(First(*L));
	Q = Nil;
	N = First(*L);
	while(next(P)!=Nil){
        Q = prev(P);
        N = next(P);
        next(P) = Q;
        prev(Q) = P;
        P = N;
	}
    Q = prev(P);
    next(P) = Q;
    prev(Q) = P;
	Last(*L) = First(*L);
	First(*L) = P;
	next(Last(*L)) = Nil;
	prev(P) = Nil;
}

List FInversList(List L)
{
    //kamus lokal
    List newL;
    address P, newP;
    //algoritma
    CreateList(&newL);
    P = First(L);
    newP = Alokasi(info(P));

    if (newP != Nil)
    {
        InsertFirst(&newL, newP);
    }
    else
    {
        return newL;
    }

    P = next(P);

    while (P != Nil)
    {
        newP = Alokasi(info(P));
        if (newP != Nil)
        {
            InsertFirst(&newL, newP);
        }
        else
        {
            DelAll(&newL);
            break;
        }
        P = next(P);
    }
    return newL;
}
void CopyList(List *L1, List *L2){
    //kamus lokal

    //algoritma
    First(*L2) = First(*L1);
}
List FCopyList(List L)
{
    //kamus lokal
    List newC;
    address P,newP;
    //algoritma
    CreateList(&newC);
    P = First(L);

    newP = Alokasi(info(P));

    if (newP != Nil)
    {
        InsertFirst(&newC, newP);
    }
    else
    {
        return newC;
    }

    P = next(P);

    while (P != Nil)
    {
        newP = Alokasi(info(P));
        if (newP != Nil)
        {
            InsertLast(&newC, newP);
        }
        else
        {
            DelAll(&newC);
            break;
        }
        P = next(P);
    }
    return newC;
}
void CpAlokList(List Lin, List *Lout)
{
    //kamus lokal
    List L;
    //algoritma
    L = FCopyList(Lin);
    (*Lout) = L;
}
void AdrLast (List *L, address *Prec, address *Last){
	/* Kamus Lokal */
	/* Algoritma */
	*Prec = Nil; // Mencari last dan preclast
	*Last = First(*L);
	while(next(*Last)!=Nil){
		*Prec = *Last;
		*Last = next(*Last);
	}
}

void Konkat(List L1, List L2, List *L3){
	/* Kamus Lokal */
	address P, Q;
	/* Algoritma */
	CreateList(L3);
	P = First(L1);
	while (P!=Nil){
		Q = Alokasi(info(P));
		if (Q!=Nil){
			InsertLast(L3,Q);
			P = next(P);
		}else{
			DelAll(L3);
			P = Nil;
		}
	}
	P = First(L2);
	while (P!=Nil){
		Q = Alokasi(info(P));
		if (Q!=Nil){
			InsertLast(L3,Q);
			P = next(P);
		}else{
			DelAll(L3);
			P = Nil;
		}
	}
}
void Konkat1(List *L1, List *L2, List *L3){
	/* Kamus Lokal */
	address Prec, Last;
	/* Algoritma */
	CreateList(L3);
	if (First(*L1)==Nil){
		First(*L3) = First(*L2);
		First(*L2) = Nil;
	}
	else{
		First(*L3) = First(*L1);
		AdrLast(L1, &Prec, &Last);
		next(Last) = First(*L2);
		First(*L1) = Nil;
		First(*L2) = Nil;
	}
}

void PecahList (List *L1, List *L2, List L){
	/* Kamus Lokal */
	address P,E,Prec1,Last1;
	int i, batas;
	/* Algoritma */
	CreateList(L1);
	CreateList(L2);
	P = First(L);
	i = 1;
	batas = NbElmt(L)/2;
	if(!ListEmpty(L)){
        while(P != Nil){
            E = Alokasi(info(P));
			if (i<=batas){
				if (E!=Nil){
					InsertLast(L1,E);
				}else{
					DelAll(L1);
				}
			}
			else{
				if (E!=Nil){
					InsertLast(L2,E);
				}else{
					DelAll(L2);
				}
			}
			P = next(P);
			i++;
        }
	}
}


















