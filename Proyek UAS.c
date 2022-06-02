#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "Header.h"

void DenahKursiKonser();
void KeteranganJenisKursi(int *sesi1, int *sesi2);
void fungsi1(int*, int);
void display(int*, int*, int);
void PemesananTiket(int sesi, int *sesi1, int *sesi2);
int sum(int, int);
void Searching();
void Help();

int main(){
	order tiket;
	char hargaChar[50];
	tiket.sesi_1[0] = tiket.sesi_2[0] = 50;
	tiket.sesi_1[1] = tiket.sesi_2[1] = 20;
	tiket.sesi_1[2] = tiket.sesi_2[2] = 10;
	
	int menu, menupesan, menuMakanan, sesi, Harga;
	Makanan makanan;
	system("COLOR F0");
	system("cls");

	do{
		printf("\n\t\t\tSelamat Datang di Konser Mega Super Besar Akhir Tahun!!!!!!!\n\t\t\t  'Menghibur Anda Yang Tidak Punya Partner Tahun Baruan!!!'\n\n");
		printf("Terdapat beberapa menu yang tersedia di bawah ini:\n\t1.Denah Kursi Konser\n\t2.Keterangan Jenis Kursi\n\t3.Pemesanan Tiket Konser\n\t4.Pencarian tiket\n\t5.Menu Bantuan\n\t6.Riwayat Tiket\n\t7.Kelola Makanan\n\t8.Keluar Program");
		printf("\n\nPilih menu yang anda inginkan: ");
		scanf("%d",&menu);
		
		if(menu == 1){
			DenahKursiKonser();
		}
		else if(menu == 2){
			KeteranganJenisKursi(tiket.sesi_1, tiket.sesi_2);
		}
		else if(menu == 3){
			system("cls");
			printf("Hai, apakah anda sudah siap untuk memesan tiket?\n1. Ya\t2. Tidak, Kembali ke menu utama\n");
			scanf("%d", &menupesan);
			
			while(menupesan != 1 && menupesan !=2){
				printf("\nInput anda salah, tolong masukan input yang benar.\n1. Beli tiket\t2. Ke menu utama\n");
				scanf("%d", &menupesan);
			}
			if(menupesan == 1){
				printf("\nKonser Mega Super Besar Akhir Tahun menghadirkan jajaran penyanyi ternama Indonesia\nTerdapat 2 sesi, yaitu:\n\nSESI 1 (13.00 WIB - 17.00 WIB)\n\t'One Stop Entertain Festival' : #YouthEnergy\n\t Menghadirkan = Afghan, Raisa, Kotak, Inul Daratista, HiVi, Nassar, dan Mulan Jameelah\n\t Dipandu dengan MC kebanggaan : Raffi Ahmad & Nagita Slavina\n\n");
				printf("SESI 2 (19.00 WIB - 23.00 WIB)\n\t'Disco and Romantic Love Music' : #NoLoveNoLife\n\t Menghadirkan : Gangga, Yura Yunita, Awkareen, Maudy Ayunda, Lesti Bilar, dan AgnesMo\n\t Dipandu dengan MC kebanggaan : Najwa Shihab & Kaesang");
				printf("\n\nPilih sesi yang ingin anda tonton: ");
				scanf("%d",&sesi);
				while (sesi != 1 && sesi !=2){
					printf ("\nInput anda salah, tolong masukkan input yang benar\n1. Sesi 1\t2. Sesi 2\n");
					scanf ("%d", &sesi);
				}
				PemesananTiket(sesi, tiket.sesi_1, tiket.sesi_2);
			}
			
			else if(menupesan == 2){
				//do nothing
			}
		}
		else if(menu == 4){
			Searching();
		}
		else if (menu == 5){
			Help();
		}
		else if(menu == 6){
			if(isEmpty() == 1){
				system("cls");
				printf("Tidak ada riwayat pemesanan tiket\n\n");
				system("pause");
			}
			else{
				system("cls");
				showList();
				printf("\n");
				system("pause");
			}
		}
		else if(menu == 7){
			system("cls");
			do{
				printf("\n\t\t\tKELOLA MAKANAN\n");
				printf("\t\t\t1.Tambah Boot Makanan\n");
				printf("\t\t\t2.Update Boot Makanan\n");
				printf("\t\t\t3.Delete Boot Makanan\n");
				printf("\t\t\t4.Lihat Boot Makanan Terurut dari Harga Terendah\n");
				printf("\t\t\t5.Keluar\n");
				do{
					printf("\t\t\tPilih [1..5] > "), scanf("%d", &menuMakanan); getchar();
				}while(menuMakanan < 1 || menuMakanan > 5);
				printf("\n");
				switch(menuMakanan){
					case 1:{
						while(1 == 1){
							printf("\t\t\tMasukkan Harga Makanan : ");
							scanf("%49[^\n]%*c", hargaChar);
							printf("\n");
							if(isInteger(hargaChar) == 1){
								makanan.Harga = atoi(hargaChar);
								if(isExist(Root, makanan.Harga) == 1){
									printf("\t\t\t[!] Makanan dengan harga %d Sudah terdaftar!\n\n");
								}else{
									break;
								}
							}else{
								printf("\t\t\t[!] Harga tidak boleh mengandung huruf!\n\n");
							}
						}
						
						printf("\t\t\tMasukkan Nama Makanan : ");
						scanf("%19[^\n]%*c", makanan.Nama);
						
						insert(makanan);
						
						printf("\n\t\t\tMakanan dengan Nama %s dan Harga %d berhasil ditambahkan\n", makanan.Nama, makanan.Harga);
						
						break;
					}
					
					case 2:{
						if(isTreeEmpty() == 1){
							printf("\t\t\tBoot Makanan Masih Kosong!\n");
						}else{
							printf("\t\t\tMasukkan Harga Makanan yang ingin Diubah : ");
							scanf("%d", &Harga);
							
							if(isExist(Root, Harga) == 1){
								do{
									printf("\n\t\t\tMasukkan Harga Baru [Masukkan -1 jika tidak ingin ubah harga] : ");
									scanf("%d", &makanan.Harga); getchar();
									printf("\n");
									if(isExist(Root, makanan.Harga) == 1){
										printf("\t\t\t[!] Makanan dengan harga %d Sudah terdaftar!\n");
									}
								}while(makanan.Harga != -1 && isExist(Root, makanan.Harga) == 1);
								
								printf("\t\t\tMasukkan Nama Baru : ");
								scanf("%19[^\n]%*c", makanan.Nama);
								
								if(makanan.Harga == -1){
									makanan.Harga = Harga;
								}
								
								updateNode(Root, makanan, Harga);
								
								printf("\n\t\t\tMakanan dengan Nama %s dan Harga %d berhasil di-update\n", makanan.Nama, makanan.Harga);
							}else{
								printf("\t\t\tMakanan dengan Harga %d tidak ditemukan, Gagal update!\n", makanan.Harga);
							}
						}
						break;
					}
					
					case 3:{
						if(isTreeEmpty() == 1){
							printf("\t\t\tBoot Makanan Masih Kosong!\n");
						}else{
							printf("\t\t\tMasukkan Harga Makanan yang ingin Dihapus : ");
							scanf("%d", &makanan.Harga);
							
							if(isExist(Root, makanan.Harga) == 1){
								deleteNode(Root, makanan.Harga);
								printf("\t\t\tMakanan dengan Harga %d berhasil dihapus\n", makanan.Harga);
							}else{
								printf("\t\t\tMakanan dengan Harga %d tidak ditemukan, Gagal hapus!\n", makanan.Harga);
							}
						}
						break;
					}
					
					case 4:{
						if(isTreeEmpty() == 1){
							printf("\t\t\tBoot Makanan Masih Kosong!\n");
						}else{
							printf("\t\t\tData Boot Makanan :\n");
							printf("\t\t\t+======================+============+\n");
							printf("\t\t\t| Nama Makanan         | Harga      |\n");
							printf("\t\t\t+======================+============+\n");
							inOrder(Root);
							printf("\t\t\t+======================+============+\n");
						}
						break;
					}
					
					case 5:{
						printf("\t\t\tKeluar dari Kelola Makanan\n");
						break;
					}
				}
				
				if(menuMakanan != 5){
					printf("\n");
					system("pause");
					system("cls");
				}
			}while(menuMakanan != 5);
		}
		else if(menu == 8){
			break;
		}

		else{
			system("cls");
			printf("Input tidak sesuai, mohon berikan input yang sesuai dengan pilihan menu.\n\n");
			system("pause");
		}
		
		system("cls");
	}while(menu != 8);
	
	system("cls");
	printf("\nTerimakasih telah menggunakan program kami");
	
	return 0;
}
