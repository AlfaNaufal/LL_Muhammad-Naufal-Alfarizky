/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "spnrsll.h"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList;
		infotype isi;
		address P, Prec;

		/* Program */
		CreateList (&MyList);	//List sudah terbentuk, digunakan untuk memanipulasi elemen
	
	//aksi mahasiswa untuk implementasi studi kasus
	isi = 7;
	InsVFirst(&MyList, isi);
	printf("Setelah menggunakan InsVFirst\n");
	PrintInfo(MyList);
	
	isi = 11;
	InsVLast(&MyList, isi);
	printf("Setelah menggunakan InsVLast\n");
	PrintInfo(MyList);
	
	isi = 9;
	P = Alokasi(isi);
	Prec = Search(MyList, 7);
	InsertAfter(&MyList, P, Prec);
	printf("Setelah Menggunakan InserAfter\n");
	PrintInfo(MyList);
	
	isi = 5;
	P = Alokasi(isi);
	InsertFirst(&MyList, P);
	printf("Setelah menggunakan InsertFirst\n");
	PrintInfo(MyList);
	
	isi = 13;
	P = Alokasi(isi);
	InsertLast(&MyList, P);
	printf("Setelag menggunakan InsertLast\n");
	PrintInfo(MyList);
	
	DelLast(&MyList, &P);
	printf("Setelah menggunakan DelLast\n");
	PrintInfo(MyList);
	
	DelP(&MyList, 7);
	printf("Setelah menggunakan DelP\n");
	PrintInfo(MyList);
	
	DelFirst(&MyList, &P);
	printf("Setelah menggunakan DelFrist\n");
	PrintInfo(MyList);
	
	DelOdd(&MyList);
	printf("Setelah menggunakan DelOdd\n");
	PrintInfo(MyList);

	/* Finishing */
	

	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
	
	return 0;
}

