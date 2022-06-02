typedef struct pesantiket{
	int sesi_1[3];
	int sesi_2[3];
	int jumlah;
	char nama[50];
}order;

typedef struct{
	char Nama[20]; //Nama Makanan
	int Harga;
}Makanan;

//Ini struktur Node Tree
typedef struct Node{
	Makanan Info;
	struct Node *Left;
	struct Node *Right;
}Node;

//Ini struktur Linked List
typedef struct NodeLL{
	int ID;
	int Kelas;
	int Sesi;
	char Nama[50];
	struct NodeLL *next;
}NodeLL;

NodeLL *Head = NULL, *Tail = NULL; //Node Pertama dan Akhir Linked List untuk riwayat pemesanan tiket
Node *Root = NULL; //Node Root dari Tree
int tempID[50];
int menu_utama;

/* Ini Fungsi Tree */
Node *createNodeTree(Makanan M){
	Node *node = (Node*)malloc(sizeof(Node));
	node->Info = M;
	node->Left = NULL;
	node->Right = NULL;
	
	return node;
}

int isTreeEmpty(){
	if(Root == NULL){
		return 1;
	}
	return 0;
}

void insertNode(Node *curr, Makanan M){
	if(curr->Info.Harga < M.Harga){
		if(curr->Right == NULL){
			curr->Right = createNodeTree(M);
		}else{
			insertNode(curr->Right, M);
		}
	}else{
		if(curr->Left == NULL){
			curr->Left = createNodeTree(M);
		}else{
			insertNode(curr->Left, M);
		}
	}
}

void insert(Makanan M){
	if(Root == NULL){
		Root = createNodeTree(M);
	}else{
		insertNode(Root, M);
	}
}

int isExist(Node *curr, int Harga){
	if(curr == NULL){
		return 0;
	}
	
	if(curr->Info.Harga == Harga){
		return 1;
	}else if(curr->Info.Harga < Harga){
		return isExist(curr->Right, Harga);
	}
	return isExist(curr->Left, Harga);
}

void updateNode(Node *curr, Makanan M, int Harga){
	if(curr != NULL){
		if(curr->Info.Harga == Harga){
			curr->Info = M;
		}else if(curr->Info.Harga < Harga){
			updateNode(curr->Right, M, Harga);
		}else{
			updateNode(curr->Left, M, Harga);
		}
	}
}

Node *minValueNode(Node* node){
    Node* curr = node;
	while(curr && curr->Left != NULL){
        curr = curr->Left;
	}
 
    return curr;
}

Node *deleteNode(Node *root, int Harga){
    if(root == NULL){
		return root;
	}
    
	if(Harga < root->Info.Harga){
        root->Left = deleteNode(root->Left, Harga);
	}else if(Harga > root->Info.Harga){
        root->Right = deleteNode(root->Right, Harga);
	}else{
        if(root->Left == NULL){
            Node *temp = root->Right;
            free(root);
            return temp;
        }else if(root->Right == NULL){
            Node *temp = root->Left;
            free(root);
            return temp;
        }
 
        Node *temp = minValueNode(root->Right);
		 
        root->Info = temp->Info;
 
        root->Right = deleteNode(root->Right, temp->Info.Harga);
    }
    
    return root;
}

void preOrder(Node *curr){
	static int index = 1;
	if(curr != NULL){
		printf("| %-20s - Rp. %-6d |                ", curr->Info.Nama, curr->Info.Harga);
		if(index % 2 == 0){	
			printf("\n\n");
		}
		index += 1;
		preOrder(curr->Left);
		preOrder(curr->Right);
	}
}

void inOrder(Node *curr){
	if(curr != NULL){
		inOrder(curr->Left);
		printf("\t\t\t| %-20s | Rp. %-6d |\n", curr->Info.Nama, curr->Info.Harga);
		inOrder(curr->Right);
	}
}
/* Akhir Fungsi Tree */

/* Ini Fungsi Linked List */
NodeLL *createNodeLL(int ID, int Kelas, int Sesi, char *Nama){
	NodeLL *node = (NodeLL*) malloc(sizeof(NodeLL));
	node->ID = ID;
	node->Kelas = Kelas;
	node->Sesi = Sesi;
	strcpy(node->Nama, Nama);
	node->next = NULL;
	
	return node;
}

int isEmpty(){
	if(Head == NULL){
		return 1;
	}
	return 0;
}

void showList(){
	NodeLL *curr = Head;
	
	printf("+====================================================+==================+================================+=============+\n");
	printf("| Nama Penanggung Jawab                              | ID               | Sesi Konser                    | Kelas Tiket |\n");
	printf("+====================================================+==================+================================+=============+\n");
	while(curr != NULL){
		printf("| %-50s | %-16d | %-30s | %-11s |\n", curr->Nama, curr->ID, curr->Sesi == 1 ? "One Stop Entertain Festival" : "Disco and Romantic Love Music", curr->Kelas == 1 ? "Silver" : (curr->Kelas == 2 ? "Gold" : "VIP"));
		curr = curr->next;
	}
	printf("+====================================================+==================+================================+=============+\n");
}

void addLast(int ID, int Kelas, int Sesi, char *Nama){
	NodeLL *node = createNodeLL(ID, Kelas, Sesi, Nama);
	if(Head == NULL){
		Head = Tail = node;
	}else{
		Tail->next = node;
		Tail = node;
	}
}

int isIDExist(int ID){
	NodeLL *curr = Head;
	while(curr != NULL){
		if(curr->ID == ID){
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

/* Akhir Fungsi Linked List */

int isInteger(char str[]){
	int i;
	
	for(i=0; str[i] != '\0'; i++){
		if(isdigit(str[i]) == 0){
			return 0;
		}
	}
	return 1;
}

void DenahKursiKonser(){
	int VIP[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
	system("cls");
	printf("\n\n\t\t\t\t\t*G* ------------- *G*\n");
	printf("\t\t\t\t\t*O* | S T A G E | *O*\n");
	printf("\t\t\t\t\t*L* | S T A G E | *L*\n");
	printf("\t\t\t\t\t*D* ------------- *D*\n");
	printf("\t\t\t\t\t    *************\n");
	printf("\t\t\t\t\t    *  V  I  P  *\n");
	printf("\t\t\t\t\t    *************\n\n");
	printf("\t\t\t\t\t*********************\n");
	printf("\t\t\t\t\t**** S I L V E R ****\n");
	printf("\t\t\t\t\t**** S I L V E R ****\n");
	printf("\t\t\t\t\t*********************\n");
	printf("\t\t\t\t\t\n\n\n");
	printf("Konfigurasi Seat Kelas VIP\n");
	printf("\t\t\t\t\t|*******STAGE*******|\n");
	printf("\t\t\t\t\t|%dA  %dA  %dA  %dA  %dA |\n", VIP[0][0], VIP[0][1], VIP[0][2], VIP[0][3], VIP[0][4]);
	printf("\t\t\t\t\t|%dB  %dB  %dB  %dB  %dB|\n", VIP[1][0], VIP[1][1], VIP[1][2], VIP[1][3], VIP[1][4]);
	printf("\n\n\n");
	printf("===================== !!!Boot Makanan Dengan Berbagai Macam HARGA!!! =====================\n");
	if(Root != NULL){
		preOrder(Root);
		printf("\n");
	}else{
		printf("\nBoot Makanan Belum Tersedia");
	}
	printf("\n\n===================== !!!Boot Makanan Dengan Berbagai Macam HARGA!!! =====================\n\n");
	printf("===================== |                                           | =====================\n");
	printf("===================== !                                           | =====================\n");
	P:
	printf("\nTekan 5 untuk kembali ke menu utama: ");
	scanf("%d",&menu_utama);
	if (menu_utama==5)
		main();
	else 
		printf("\nMaaf input anda salah, mohon berikan input yang sesuai dengan arahan program");
		goto P;
	}
	
void KeteranganJenisKursi(int *sesi1, int *sesi2){
	system("cls");
	printf("Keterangan Jenis Kursi:\n");
	
	printf("\nSESI 1\nKelas Silver\nKapasitas yang Tersedia :%d orang\nHarga Tiket\t\t:Rp 5.000.000,-\n", sesi1[0]);
	printf("\nKelas Gold\nKapasitas yang Tersedia :%d orang\nHarga Tiket\t\t:Rp 3.000.000,-\n", sesi1[1]);
	printf("\nKelas VIP\nKapasitas yang Tersedia :%d orang\nHarga Tiket\t\t:Rp 1.500.000,-\n", sesi1[2]);

	printf("\nSESI 2\nKelas Silver\nKapasitas yang Tersedia :%d orang\nHarga Tiket\t\t:Rp 5.000.000,-\n", sesi2[0]);
	printf("\nKelas Gold\nKapasitas yang Tersedia :%d orang\nHarga Tiket\t\t:Rp 3.000.000,-\n", sesi2[1]);
	printf("\nKelas VIP\nKapasitas yang Tersedia :%d orang\nHarga Tiket\t\t:Rp 1.500.000,-\n", sesi2[2]);
		
	N:
	printf("\nTekan 5 untuk kembali ke menu utama: ");
	scanf("%d",&menu_utama);
	if (menu_utama==5)
		main();
	else 
		printf("\nMaaf input anda salah, mohon berikan input yang sesuai dengan arahan program");
		goto N;
}

void fungsi1(int *ketersediaan, int beli){
	*ketersediaan = *ketersediaan - beli;
}

void display(int *kelas, int *sesi, int n){
	int i, j, sortingID, harga[3]={1500000, 3000000, 5000000};
	order pengguna;
	long int total_harga;
	char temp;
	order *ptr;
	ptr = (order*) malloc (n * sizeof(order));
	system("cls");
	
	printf("\nMasukkan nama yang bertanggung jawab atas pemesanan tiket: ");
	scanf("%c",&temp);
	scanf("%50[^\n]%*c", (ptr)->nama);

	i = 0;
	while(i < n){
		printf("\nMasukkan nomor identitas untuk tiket ke %d, dapat berupa nomor SIM atau KTP: ", i+1);
		scanf("%d", &tempID[i]);
		
		if(isIDExist(tempID[i]) == 0){
			addLast(tempID[i], *kelas, *sesi, (ptr)->nama);
			i += 1;
			printf("\n[!]Nomor Identitas Berhasil Didaftarkan!\n");
		}else{
			printf("\n[!]Gagal Menambahkan, Nomor Identitas Sudah Terdaftar!\n");
		}
	}

	if(*sesi == 1){
		Sleep(1000);
		printf("\nDetail order:\n");
		printf("SESI 1 (13.00 WIB - 17.00 WIB)\n'One Stop Entertain Festival' : #YouthEnergy\nAfghan, Raisa, Kotak, Inul Daratista, HiVi, Nassar, dan Mulan Jameelah\nMC : Raffi Ahmad & Nagita Slavina\n");
		if(*kelas == 1){
			printf("Kelas Silver\n");
			total_harga = sum(harga[0],n);
		}
		else if(*kelas == 2){
			printf("Kelas Gold\n");
			total_harga = sum(harga[1],n);
		}
		else{
			printf("Kelas VIP\n");
			total_harga = sum(harga[2],n);
		}
	}
	
	else if(*sesi == 2){
		Sleep(1000);
		printf("\nDetail order:\n");
		printf("\nSESI 2 (19.00 WIB - 23.00 WIB)\n'Disco and Romantic Love Music' : #NoLoveNoLife\nGangga, Yura Yunita, Awkareen, Maudy Ayunda, Lesti Bilar, dan AgnesMo\nMC : Najwa Shihab & Kaesang\n");
		if(*kelas == 1){
			printf("Kelas Silver\n");
			total_harga =  sum(harga[0],n);
		}
		else if(*kelas == 2){
			printf("Kelas Gold\n");
			total_harga = sum(harga[1],n);
		}
		else{
			printf("Kelas VIP\n");
			total_harga = sum(harga[2],n);
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(tempID[i] < tempID[j]){
				sortingID = tempID[i];
				tempID[i] = tempID[j];
				tempID[j] = sortingID;
			}
		}
	}
	
	printf ("\nAnda memesan %d tiket atas nama %s\n\nBerikut ID untuk setiap tiket yang anda pesan\n", n, (ptr)->nama);
	
	for(i=0; i<n; i++){
		printf("Nomor Identitas: %d\n", tempID[i]);
	}
	printf("\nBiaya total pemesanan %d tiket: %ld\nSilahkan transfer biaya ke bank tertera\n Mandiri\t643872649 (a.n. Salman Elfarizi)\n BRI\t\t748397659 (a.n. Ahmad Fahrezi)\n BNI\t\t76698274 (a.n. Natasya Wilona)\n\n", n, total_harga);
	R:
	printf("\nTekan 5 untuk kembali ke menu utama: ");
	scanf("%d",&menu_utama);
	if (menu_utama==5)
		main();
	else 
		printf("\nMaaf input anda salah, mohon berikan input yang sesuai dengan arahan program");
		goto R;
		
}

void PemesananTiket(int sesi, int *sesi1, int *sesi2){
	int kelas;
	order tiket;
	
	system("cls");
		
	if(sesi == 1){
		printf("Konser Sesi 1\n");
		printf("\nJenis kelas tiket yang tersedia:\n1.Silver\n2.Gold\n3.VIP\nPilih kelas tiket yang anda inginkan: ");
		scanf("%d", &kelas);
		switch(kelas){
			case 1:
				printf("\nAnda memilih kelas Silver.\nBerapa jumlah tiker yang ingin dipesan? ");
				scanf("%d", &tiket.jumlah);
				while(tiket.jumlah <= 0){
					printf("\nInput error tolong masukkan jumlah pesan yang valid: ");
					scanf("%d", &tiket.jumlah);
				}
				if(tiket.jumlah > 0){
					fungsi1(&sesi1[0], tiket.jumlah);
					display(&kelas, &sesi, tiket.jumlah);
				}
				break;
				
			case 2:
				printf("\nAnda memilih kelas Gold.\nBerapa jumlah tiket yang ingin dipesan? ");
				scanf("%d", &tiket.jumlah);
				while(tiket.jumlah <= 0){
					printf("\nInput error tolong masukkan jumlah pesan yang valid: ");
					scanf("%d", &tiket.jumlah);
				}
				if(tiket.jumlah > 0){
					fungsi1(&sesi1[1], tiket.jumlah);
					display(&kelas, &sesi, tiket.jumlah);
				}
				break;
			
			case 3:
				printf("\nAnda memilih kelas VIP.\nBerapa jumlah tiket yang ingin dipesan? ");
				scanf("%d", &tiket.jumlah);
				while(tiket.jumlah <= 0){
					printf("\nInput error tolong masukkan jumlah pesan yang valid: ");
					scanf("%d", &tiket.jumlah);
				}
				if(tiket.jumlah > 0){
					fungsi1(&sesi1[2], tiket.jumlah);
					display(&kelas, &sesi, tiket.jumlah);
				}
				break;
		}
	}
	else if(sesi == 2){
		printf("Konser Sesi 2");
		printf("\nJenis kelas tiket yang tersedia:\n\t1.Silver\n\t2.Gold\n\t3.VIP\nPilih kelas tiket yang anda inginkan: ");
		scanf("%d", &kelas);
		switch(kelas){
			case 1:
				printf("\nAnda memilih kelas Silver.\nBerapa jumlah tiker yang ingin dipesan? ");
				scanf("%d", &tiket.jumlah);
				while(tiket.jumlah <= 0){
					printf("\nInput error tolong masukkan jumlah pesan yang valid: ");
					scanf("%d", &tiket.jumlah);
				}
				if(tiket.jumlah > 0){
					fungsi1(&sesi2[0], tiket.jumlah);
					display(&kelas, &sesi, tiket.jumlah);
				}
				break;
				
			case 2:
				printf("\nAnda memilih kelas Gold.\nBerapa jumlah tiket yang ingin dipesan? ");
				scanf("%d", &tiket.jumlah);
				while(tiket.jumlah <= 0){
					printf("\nInput error tolong masukkan jumlah pesan yang valid: ");
					scanf("%d", &tiket.jumlah);
				}
				if(tiket.jumlah > 0){
					fungsi1(&sesi2[1], tiket.jumlah);
					display(&kelas, &sesi, tiket.jumlah);
				}
				break;
			
			case 3:
				printf("\nAnda memilih kelas VIP.\nBerapa jumlah tiket yang ingin dipesan? ");
				scanf("%d", &tiket.jumlah);
				while(tiket.jumlah <= 0){
					printf("\nInput error tolong masukkan jumlah pesan yang valid: ");
					scanf("%d", &tiket.jumlah);
				}
				if(tiket.jumlah > 0){
					fungsi1(&sesi2[2], tiket.jumlah);
					display(&kelas, &sesi, tiket.jumlah);
				}
				break;
		}
	}
}

int sum(int harga, int n) {
    while(n != 0){
        return harga + sum(harga, n-1); 
}
}

void Searching(){
	int i = 0, identitas;
	order pengguna;
	system("cls");
	
	printf ("\nSilahkan masukkan ID yang telah anda daftarkan = ");
	scanf ("%d", &identitas);
	
	NodeLL *curr = Head;
	
	while(curr != NULL){
		if(identitas == curr->ID){
			i = 1;
			printf ("\nID %d sudah terdaftarkan\n\nBerikut detail pemesanan anda :\n", identitas);
			printf("Nama Penanggung Jawab : %s\n", curr->Nama);
			printf("Nomor identitas       : %d\n", curr->ID);
			printf("Sesi Menonton         : %s\n", curr->Sesi == 1 ? "One Stop Entertain Festival" : "Disco and Romantic Love Music");
			printf("Kelas Tiket           : %s\n", curr->Kelas == 1 ? "Silver" : (curr->Kelas == 2 ? "Gold" : "VIP"));
			system("pause");
			break;
		}
		curr = curr->next;
	}
	
	if(i == 0){
		printf ("\nID %d belum terdaftarkan\n\n", identitas);
		system("pause");
	}
}

void Help(){
	system("cls");
	printf("\nKetika anda menjalankan program, akan muncul 6 tampilan menu untuk melayani kebutuhan anda terkait pemesanan tiket konser\n\nPanduan untuk menggunakan menu tersebut adalah :\n1. User diharapkan memasukkan angka yang diminta oleh program untuk memasuki menu tertentu\n2. Bila terjadi kesalahan penginputan angka, program akan mengarahkan user untuk menginput angka terkait agar dapat tetap mengakses layanan\n3. User diharapkan dapat menginput nama maupun ID yang diminta oleh program dengan benar\n4.Program akan memberikan arahan setiap user memasukkan input yang salah, mohon perhatikan arahan program dan isi input sesuai dengan pilihan pada porgram\n");
    printf("\nSilahkan hubungi call center Konser Mega Super Besar Akhir Tahun di 021-98767898/082345654321\n");
    E:
	printf("\nTekan 5 untuk kembali ke menu utama: ");
	scanf("%d",&menu_utama);
	if (menu_utama==5)
		main();
	else 
		printf("\nMaaf input anda salah, mohon berikan input yang sesuai dengan arahan program");
		goto E;
}
