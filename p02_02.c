#include <stdio.h>
#include <string.h>

int main() {
    
    int N;
    int stok[100];
    char nama[100][50];
    int kategori;
    int total = 0;
    
    printf("Program Menentukan Total Stok Berdasarkan Kategori\n");
    printf("===================================================\n\n");
    
    printf("Masukkan jumlah data barang : ");
    scanf("%d", &N);
    
    // input stok dan nama barang
    for(int i = 0; i < N; i++) {
        printf("\nData barang ke-%d\n", i+1);
        
        printf("Masukkan jumlah stok (pcs) : ");
        scanf("%d", &stok[i]);
        
        getchar(); 
        
        printf("Masukkan nama barang : ");
        fgets(nama[i], sizeof(nama[i]), stdin);
        
        nama[i][strcspn(nama[i], "\n")] = 0;
    }
    
    printf("\nKategori Barang:\n");
    printf("1. Stok Genap\n");
    printf("2. Stok Ganjil\n");
    
    printf("Masukkan kode kategori : ");
    scanf("%d", &kategori);
    
    printf("\nBarang yang termasuk kategori:\n");
    
    for(int i = 0; i < N; i++) {
        
        if(kategori == 1 && stok[i] % 2 == 0) {
            printf("%s (%d pcs)\n", nama[i], stok[i]);
            total += stok[i];
        }
        
        else if(kategori == 2 && stok[i] % 2 != 0) {
            printf("%s (%d pcs)\n", nama[i], stok[i]);
            total += stok[i];
        }
        
    }
    
    printf("\nTotal stok kategori yang dipilih = %d pcs\n", total);
    
    return 0;
}