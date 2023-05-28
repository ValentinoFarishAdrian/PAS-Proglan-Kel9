/*
Proyek Akhir Semester
Kelompok 9
Muhammad Daffa Rizkyandri (NPM)
Surya Dharmasaputra Soeroso (NPM)
Valentino Farish Adrian (2206825896)
Variabel:
	(Komunikasi + Kerjasama) * 25%
	(Inisiatif + Kontribusi) * 30%
	(Tepat Waktu + Kualitas Hasil) * 30%
	(Kehadiran) * 15%
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct node{
    char nama[50];
    float intrpers;
	float dedct;
	float qual;
	float disc;
	float res;
    struct node *next;
}node;


void menu();
void about();
void display(node *head);
void printlist(node *current);
void inputnode(node **head);
void delnode(node **head, int position);
void open_file();
void open_newfile();
void searchnode();
void sortnode_name();
void sortnode_score();
void calculate();

int main(){
	menu();
}

void menu(){
	node *head = NULL;
    int i, input, menu, tambah, posisi;
    float sum = 0;
	system("cls");
    while(1){
        printf("====================================================\n"
               "|             DATABASE PERFORMA KARYAWAN           |\n"
               "====================================================\n"
               "|                    Menu Utama:                   |\n"
               "|                                                  |\n"
               "|   1. Input Data Karyawan                         |\n"
               "|   2. List Data Performa Karyawan                 |\n"
               "|   3. Cari Data Karyawan                          |\n"
			   "|   4. Simpan Data Ke File                         |\n"
               "|   5. Buat File Baru                              |\n"
               "|   6. Tentang Program                             |\n"
               "|   0. Exit                                        |\n"
               "====================================================\n"
               "\nMasukkan Pilihan : ");
	    scanf("%d", &menu);
	    switch (menu){
	    case 1:
	        system("cls");
			printf("============================================\n");
			printf("|           INPUT DATA KARYAWAN            |\n");
			printf("============================================\n\n");
	        printf("Masukkan Jumlah Karyawan: ");
	        scanf("%d", &input);
	        for(i=0; i<input; i++){
	            printf("\nKaryawan ke-%d:\n", i+1);
	            inputnode(&head); 
	        }
	        break;
	    case 2:
	        system("cls");
	        display(head);
            printf("\n\nTekan apa saja untuk keluar...");
            getch();	
	        break;
	    case 3:
	        system("cls");
    		printf("\n==== Tambah Makanan ====\n");
	        printf("Masukkan Jumlah Makanan: ");
	        scanf("%d", &tambah);
	        for(i=0; i<tambah; i++){
	            printf("\nMakanan ke-%d:\n", i+1);
	            inputnode(&head);
	        }
	        break;
	    case 4:
			system("cls");
			printf("\n==== Hapus Data ====\n");
			printlist(head);
			printf("\nPilih data yang ingin dihapus: ");
			scanf("%d", &posisi);
			delnode(&head, posisi);
            printf("\n\nTekan apa saja untuk keluar...");
            getch();
			break;
		case 5:
			system("cls");
			open_newfile();
			printf("\nTekan apa saja untuk keluar...");
			getch();
			break;
		case 6:
			system("cls");
			about();
			printf("\nTekan apa saja untuk keluar...");
			getch();
			break;
	    case 0:
			system("cls");
	        while(head!=NULL){
	            node *temp = head;
	            head = head->next;
	            free(temp);
	        }
			printf("Terima Kasih Telah Menggunakan Program~~~");
	        exit(0);
	    default:
	        printf("INPUT TIDAK VALID!!!");
	        break;
	    }
		system("cls");
	}
}

void display(node *head){
	int i, choice, posisi, tambah;
	printf("=================================================\n");
	printf("|               LIST DATA KARYAWAN              |\n");
	printf("=================================================\n\n");
    printf("=================================================\n"
           "|   1. Sorting Berdasarkan Nama	                |\n"
           "|   2. Sorting Berdasarkan Nilai                |\n"
           "|   3. Tambah Data Karyawan                     |\n"
           "|   4. Hapus Data Karyawan                      |\n"
           "|   5. Kembali Ke Menu                          |\n"
           "=================================================\n"
           "Masukkan Pilihan: ");
    scanf("%d", &choice);								//Input Pilihan	
    switch (choice){
    case 1:
        sortnode_name();						//Display List Sorted berdasarkan Status 		
        printlist(head);
        break;
    case 2:
        sortnode_score();						//Display List Sorted berdasarkan Jadwal
		printlist(head);
        break;
    case 3:
		system("cls");
		printf("\n==== Tambah Data ====\n");
		printf("Masukkan Jumlah Karyawan: ");
		scanf("%d", &tambah);
		for(i=0; i<tambah; i++){
			printf("\nKaryawan ke-%d:\n", i+1);
			newnode(&head);
		}
		break;
    case 4:
		system("cls");
		printf("\n==== Hapus Data ====\n");
		printlist(head);
		printf("\nPilih data yang ingin dihapus: ");
		scanf("%d", &posisi);
		delnode(&head, posisi);
		printf("\n\nTekan apa saja untuk keluar...");
		getch();
        return;
	case 5:
        return;
    default:
        break;
    }
}	

void printlist(node *current){
    while(current!=NULL){
		printf("-----------------------------------------");
        printf("\n\n%s", current->nama);
        printf("\n%.2f", current->harga);
        printf("-----------------------------------------");
        current = current->next;
    }
}

void inputnode(node **head){
    node *find = (*head);
    node *new_node = malloc(sizeof(node));
    char nama[50];
    float harga;
    printf("Nama Makanan: ");
    scanf(" %[^\n]s", &nama);
    printf("Harga Makanan: ");
    scanf("%f", &harga); 
    strcpy(new_node->nama, nama);
    new_node->harga = harga;
    new_node->next = NULL;
    if(*head==NULL){
        *head = new_node;
        return;
    }
    while(find->next!=NULL){
        find = find->next;
    }
    find->next = new_node;
}

void delnode(node **head, int position){
	node *current = (*head);
	node *prev = (*head);
	if(*head==NULL)
		printf("Tidak Ada List!!!");
	else if(position == 1){
		*head = current->next;
		free(current);
		current = NULL;
		printf("Data Sudah Dihapus~~~");
	}
	else{
		while(position!=1){
			prev = current;
			current = current->next;
			position--;
		}
		prev->next = current->next;
		free(current);
		current = NULL;
		printf("Data Sudah Dihapus~~~");
	}
}
