#include <stdio.h>
#include <string.h>

#define MAX_MENU 20
#define MAX_ORDER 50
#define DISCOUNT_THRESHOLD 50000
#define DISCOUNT_RATE 0.10

struct Menu {
    int id;
    char nama[50];
    float harga;
};

// Struktur Pesanan
struct Order {
    int idMenu;
    char namaMenu[50];
    int jumlah;
    float subtotal;
};

// Struktur Transaksi
struct Transaksi {
    struct Order orders[MAX_ORDER];
    int totalItem;
    float totalHarga;
    float diskon;
    float totalBayar;
};

// Data Menu Global
struct Menu daftarMenu[MAX_MENU] = {
    {1,"Nasi Goreng",20000},
    {2,"Mie Goreng",18000},
    {3,"Ayam Geprek",22000},
    {4,"Soto Ayam",15000},
    {5,"Bakso",17000},
    {6,"Es Teh",5000},
    {7,"Es Jeruk",7000},
    {8,"Kopi Susu",10000}
};

int jumlahMenu = 8;

// Fungsi tampil menu
void tampilMenu() {

    printf("\n==============================\n");
    printf("        MENU KAFETARIA\n");
    printf("        INSTITUT DEL\n");
    printf("==============================\n");

    for(int i=0;i<jumlahMenu;i++){
        printf("%d. %-15s Rp %.0f\n",
        daftarMenu[i].id,
        daftarMenu[i].nama,
        daftarMenu[i].harga);
    }

    printf("==============================\n");
}

// mencari menu
int cariMenu(int id){

    for(int i=0;i<jumlahMenu;i++){
        if(daftarMenu[i].id==id)
        return i;
    }

    return -1;
}

// proses pemesanan
void buatPesanan(struct Transaksi *trx){

    int id,jumlah;

    tampilMenu();

    printf("\nMasukkan ID Menu : ");
    scanf("%d",&id);

    int index=cariMenu(id);

    if(index==-1){
        printf("Menu tidak ditemukan!\n");
        return;
    }

    printf("Jumlah Pesanan : ");
    scanf("%d",&jumlah);

    struct Order order;

    order.idMenu=id;
    strcpy(order.namaMenu,daftarMenu[index].nama);
    order.jumlah=jumlah;
    order.subtotal=jumlah*daftarMenu[index].harga;

    trx->orders[trx->totalItem]=order;
    trx->totalItem++;

    trx->totalHarga+=order.subtotal;

    printf("Pesanan berhasil ditambahkan!\n");
}

// hitung diskon
void hitungDiskon(struct Transaksi *trx){

    if(trx->totalHarga>=DISCOUNT_THRESHOLD){
        trx->diskon=trx->totalHarga*DISCOUNT_RATE;
    }else{
        trx->diskon=0;
    }

    trx->totalBayar=trx->totalHarga-trx->diskon;
}

// hadiah gift
void cekHadiah(float total){

    if(total>=100000){
        printf("SELAMAT! Anda mendapat hadiah: ICE CREAM GRATIS!\n");
    }
    else if(total>=75000){
        printf("SELAMAT! Anda mendapat hadiah: MINUMAN GRATIS!\n");
    }
}

// tampilkan struk
void tampilStruk(struct Transaksi trx){

    hitungDiskon(&trx);

    printf("\n===================================\n");
    printf("           STRUK PEMBELIAN\n");
    printf("         KAFETARIA IT DEL\n");
    printf("===================================\n");

    for(int i=0;i<trx.totalItem;i++){

        printf("%-15s x%d  Rp %.0f\n",
        trx.orders[i].namaMenu,
        trx.orders[i].jumlah,
        trx.orders[i].subtotal);
    }

    printf("-----------------------------------\n");
    printf("Total Harga : Rp %.0f\n",trx.totalHarga);
    printf("Diskon      : Rp %.0f\n",trx.diskon);
    printf("Total Bayar : Rp %.0f\n",trx.totalBayar);

    printf("===================================\n");

    cekHadiah(trx.totalBayar);
}

// laporan penjualan
void laporanPenjualan(struct Transaksi trx){

    printf("\n========== LAPORAN TRANSAKSI ==========\n");

    for(int i=0;i<trx.totalItem;i++){
        printf("%s - %d porsi\n",
        trx.orders[i].namaMenu,
        trx.orders[i].jumlah);
    }

    printf("Total Penjualan: Rp %.0f\n",trx.totalBayar);

}

// menu utama
void menuUtama(){

    struct Transaksi trx;
    trx.totalItem=0;
    trx.totalHarga=0;
    trx.diskon=0;
    trx.totalBayar=0;

    int pilihan;

    do{

        printf("\n=================================\n");
        printf("   SISTEM KAFETARIA IT DEL\n");
        printf("=================================\n");
        printf("1. Lihat Menu\n");
        printf("2. Pesan Makanan\n");
        printf("3. Lihat Struk\n");
        printf("4. Laporan Penjualan\n");
        printf("5. Keluar\n");
        printf("=================================\n");

        printf("Pilih Menu : ");
        scanf("%d",&pilihan);

        switch(pilihan){

            case 1:
            tampilMenu();
            break;

            case 2:
            buatPesanan(&trx);
            break;

            case 3:
            tampilStruk(trx);
            break;

            case 4:
            laporanPenjualan(trx);
            break;

            case 5:
            printf("Terima kasih telah menggunakan sistem!\n");
            break;

            default:
            printf("Pilihan tidak valid!\n");
        }

    }while(pilihan!=5);

}

int main(){

    menuUtama();

    return 0;
}