#include <stdio.h>
#include <string.h>

struct Kota {
    char kode[4];
    char nama[20];
    int ongkir;
    char keterangan[20];
};

int main() {

    /* Daftar kota Del-Express */
    struct Kota daftarKota[4] = {
        {"MDN","Medan",8000,"Dalam Pulau"},
        {"BLG","Balige",5000,"Dalam Pulau"},
        {"JKT","Jakarta",12000,"Luar Pulau"},
        {"SBY","Surabaya",13000,"Luar Pulau"}
    };

    char kodeInput[10];
    int berat;

    int beratButet = 0;
    int beratUcok = 0;
    int totalBerat = 0;

    int totalOngkir = 0;
    int i;
    int jumlahInput = 0;

    int luarPulau = 0;

    printf("=== SISTEM LAYANAN DEL - EXPRESS ===\n");
    printf("Masukkan data pengiriman\n");
    printf("Format : KodeKota Berat\n");
    printf("Contoh : MDN 5\n");
    printf("Ketik END untuk selesai\n\n");

    while (1) {

        printf("Input : ");
        scanf("%s", kodeInput);

        if(strcmp(kodeInput,"END") == 0) {
            break;
        }

        scanf("%d",&berat);

        for(i=0;i<4;i++) {

            if(strcmp(kodeInput, daftarKota[i].kode)==0) {

                if(jumlahInput % 2 == 0)
                    beratButet += berat;
                else
                    beratUcok += berat;

                totalBerat += berat;

                totalOngkir += berat * daftarKota[i].ongkir;

                if(strcmp(daftarKota[i].keterangan,"Luar Pulau")==0)
                    luarPulau = 1;

                printf("Tujuan : %s\n", daftarKota[i].nama);
                printf("Ongkir/kg : %d\n\n", daftarKota[i].ongkir);

                jumlahInput++;
                break;
            }
        }
    }

    float diskon = 0;
    float totalBayar;

    if(totalBerat > 10) {
        diskon = 0.10 * totalOngkir;
    }

    totalBayar = totalOngkir - diskon;

    printf("\n==============================\n");
    printf("      STRUK DEL - EXPRESS\n");
    printf("==============================\n");

    printf("Berat Paket Butet : %d kg\n", beratButet);
    printf("Berat Paket Ucok  : %d kg\n", beratUcok);

    printf("Total Berat       : %d kg\n", totalBerat);

    printf("Total Ongkir      : Rp %d\n", totalOngkir);

    if(diskon > 0)
        printf("Promo Lebaran     : Diskon 10%% (Rp %.0f)\n", diskon);
    else
        printf("Promo Lebaran     : Tidak ada\n");

    if(luarPulau == 1)
        printf("Asuransi          : Gratis (Luar Pulau)\n");
    else
        printf("Asuransi          : Tidak ada\n");

    printf("------------------------------\n");
    printf("Total Bayar       : Rp %.0f\n", totalBayar);
    printf("==============================\n");

    return 0;
}