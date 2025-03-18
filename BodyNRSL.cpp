/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	 return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 boolean found =  false;
	 /* algoritma */
	 P = First(L);
	 while ((P != Nil) && (!found))
	 {
		if (Info(P) == X)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	 }	/* P = Nil atau Ketemu */
	
	 return (P);
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (PSearch == P)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 
	 return (found);
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = Next(P);
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = Alokasi(X);
	if(ListEmpty(*L)){
		First(*L) = P;
		return;
	}
	
	Next(P) = First(*L);
	First(*L) = P;
	
	
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsVLast (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	/* Kamus Lokal */
	address P;
	address temp = First(*L);
	
	/* Algoritma */
	// P = Alokasi(X);
	// if(ListEmpty(*L)){
	// 	First(*L) = P;
	// 	return;
	// }
	
	// while(Next(temp) != Nil){
	// 	temp = Next(temp);
	// }

	// Next(temp) = P;

	P = Alokasi(X);
    if (P != NULL) {  // Cek apakah alokasi berhasil
        P->next = Nil; // Pastikan elemen baru tidak menunjuk ke mana-mana
        
        if (ListEmpty(*L)) { // Jika list kosong, langsung jadikan elemen pertama
            First(*L) = P;
        } else {
            // Cari elemen terakhir langsung menggunakan First(*L)
            address last = First(*L);
            while (Next(last) != Nil) { 
                last = Next(last);
            }
            Next(last) = P; // Tambahkan di akhir list
        }
    }
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	 if(ListEmpty(*L)){
		printf("List sudah kosong");
	 }else{
		P = First(*L);
		*X = Info(P);
		First(*L) = Next(P);
		free(P);
	 }
	 
	 //Buatkan algoritma sesuai spesifikasi modul ini
	}
	
	void DelVLast (List * L, infotype * X)
	/* IS : L TIDAK Kosong */
	/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
	/* 	dan alamat elemen terakhir di dealokasi */
	{
		/* Kamus Lokal */
		address PDel, temp;
		/* Algoritma */
		if(ListEmpty(*L)){
		   printf("List sudah kosong");
		}else{
			PDel = First(*L);
			if(Next(PDel) == Nil){
				*X = Info(PDel);
				free(PDel);
				First(*L) = Nil;

			}else{
				while(Next(PDel) != Nil){
					temp = PDel;
					PDel = Next(PDel);
				}
				*X = Info(PDel);
				Next(temp) = Nil;
				free(PDel);
				PDel = Nil;
			}
		}
		
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L); // Elemen baru menunjuk ke elemen pertama lama
    First(*L) = P;       // Elemen pertama diperbarui menjadi elemen baru
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertAfter (List * L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    if (Prec != Nil) {
        Next(P) = Next(Prec);
        Next(Prec) = P; 
    }
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	/* Algoritma */
	
	if(ListEmpty(*L)){
		First(*L) = P;
		return;
	}
	
	Last = First(*L);
	while(Next(Last) != Nil){
		Last = Next(Last);
	}

	Next(Last) = P;
	 
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{

	*P = First(*L);
	First(*L) = Next(*P);
	Next(*P) = Nil;
	free(*P);
	*P = Nil;

	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelP (List * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, Prec;
	boolean found=false;
	 
	 /* Algoritma */

	if(ListEmpty(*L)){
		return;
	}

	P = First(*L);

	if(Info(P) == X){
		First(*L) = Next(P);
		free(P);
		found = true;
		return;
	}


    Prec = First(*L);
    while (Next(Prec) != Nil && Info(Next(Prec)) != X) {
        Prec = Next(Prec);
    }


    if (Next(Prec) != Nil) {
        P = Next(Prec);
        Next(Prec) = Next(P);
        free(P); 
		found = true;
    }
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelLast (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Kamus Lokal */
	address Prec;
	 /* Algoritma */
	 if(ListEmpty(*L)){
		return;
	}

	*P = First(*L);

	if(Next(*P) == Nil){
		First(*L) = Nil;
		free(*P);
		*P = Nil;
		return;
	}


    Prec = First(*L);
    while (Next(Next(Prec)) != Nil) {
        Prec = Next(Prec);
    }

	*P = Next(Prec);
	Next(Prec) = Nil;
	free(*P);
	*P = Nil;
	 
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAfter (List * L, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
	if(ListEmpty(*L)){
		return;
	}

	if(Next(Prec) != Nil){
		*Pdel = Next(Prec);
		Next(Prec) = Next(*Pdel);
		free(*Pdel);
		*Pdel = Nil;
	}
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */

	 if(ListEmpty(L)){
		printf("List Kosong");
	}else{
		P = First(L);
		printf("Isi List\n");
		do{
			printf("%d\n", Info(P));
			P = Next(P);
		}while(P != Nil);
	}
	
	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */

	 PDel = First(*L);
	 
	 while(Next(PDel) != Nil){
		First(*L) = Next(PDel);
		free(PDel);
		PDel = First(*L);
	}
	
	First(*L) = Nil;
	PDel = Nil;
	
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelOdd (List * L){
	
	/* Kamus Lokal */
	address PDel, Prec;
	/* Algoritma */
	
	PDel = First(*L);
	Prec = Nil;
	
	while(PDel != Nil){
		if(Info(PDel) % 2 != 0){
			if(Prec == Nil){
				First(*L) = Next(PDel);
			}else{
				Next(Prec) = Next(PDel);
			}
			free(PDel);
			
            // Perbarui PDel
            if (Prec == Nil) {
                PDel = First(*L);
            } else {
                PDel = Next(Prec);
            }
        } else {
            Prec = PDel;
            PDel = Next(PDel);
		}
	}
	
}

