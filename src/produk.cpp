#include "../include/produk.h"
#include "../include/utils.h"

#include <iostream>
#include <iomanip>

// Array untuk menyimpan produk
Produk produk[100] = {
    {},
    {1, "Beras Premium 5kg", 50, 65000},
    {2, "Minyak Goreng 2L", 75, 45000},
    {3, "Gula Pasir 1kg", 100, 15000},
    {4, "Susu UHT 1L", 80, 18000},
    {5, "Telur Ayam 1kg", 60, 28000},
    {6, "Mi Instan Goreng", 200, 3500},
    {7, "Mi Instan Kuah", 200, 3000},
    {8, "Kopi Sachet", 150, 12000},
    {9, "Teh Celup 25pcs", 90, 8000},
    {10, "Sabun Mandi", 120, 5000},
    {11, "Shampo Sachet", 180, 1000},
    {12, "Pasta Gigi", 85, 15000},
    {13, "Deterjen Bubuk 1kg", 70, 25000},
    {14, "Sabun Cuci Piring", 65, 12000},
    {15, "Air Mineral 1.5L", 100, 6000},
    {16, "Roti Tawar", 45, 14000},
    {17, "Sarden Kaleng", 90, 8500},
    {18, "Mie Telor", 75, 7000},
    {19, "Tepung Terigu 1kg", 60, 12000},
    {20, "Tissue 250sheet", 100, 8000},
    {21, "Kecap Manis 600ml", 70, 16000},
    {22, "Saos Sambal 340ml", 65, 12000},
    {23, "Mentega 200g", 50, 8000},
    {24, "Sirup 650ml", 40, 18000},
    {25, "Snack Kentang", 150, 9000}};
int jumlahProduk = 26;

void tampilkanTabelProduk(bool tampilSemua, int kode)
{

    tampilkanHeading("DAFTAR PRODUK", 54);
    cout << "| Kode |    Nama Produk    |   Harga Jual   |  Stok  |\n";
    membuatGaris(54, "-");

    if (jumlahProduk == 1)
    { // Produk 0 biasanya kosong
        cout << "Tidak ada produk yang tersedia.\n";
        return;
    }

    for (int i = 1; i < jumlahProduk; i++)
    {
        if (tampilSemua || produk[i].kode == kode && produk[i].kode != 0)
        {
            cout << "| " << setw(4) << produk[i].kode
                 << " | " << setw(17) << produk[i].nama
                 << " | " << setw(14) << produk[i].harga
                 << " | " << setw(6) << produk[i].stok << " |\n";
        }
    }
    membuatGaris(54, "-");
}

bool cekProduk(int kode, bool tampilkanError)
{
    for (int i = 0; i < jumlahProduk; i++)
    {
        if (produk[i].kode == kode)
        {
            return true;
        }
    }
    if (tampilkanError)
    {
        cout << "Produk dengan kode " << kode << " tidak ditemukan.\n";
    }
    return false;
}

void ProdukManager::tambahProduk()
{
    tampilkanHeading("TAMBAH PRODUK BARU");

    int kodeProduk = jumlahProduk;
    cout << "Masukan Nama Produk   : ";
    string nama = getValidString("");
    cout << "Masukkan Harga Satuan : ";
    int harga = getValidInput(1000);
    cout << "Masukkan Stok Awal    : ";
    int stok = getValidInput();

    produk[kodeProduk] = {
        kodeProduk,
        nama,
        stok,
        harga};

    membuatGaris(52, "-");
    cout << "Produk berhasil ditambahkan ke database!\n";

    jumlahProduk++;
}

void ProdukManager::tampilkanProduk(int kode)
{
    tampilkanTabelProduk();
}

void ProdukManager::editProduk()
{
    tampilkanHeading("PERBARUI INFORMASI PRODUK");
    cout << "Masukan kode produk yang ingin diperbarui : ";
    int kode = getValidInput();

    if (cekProduk(kode))
    {
        tampilkanTabelProduk(false, kode);
        cout << "Masukkan Nama Baru Produk  : ";
        produk[kode].nama = getValidString();
        cout << "Masukkan Harga Baru        : ";
        produk[kode].harga = getValidInput(1000);
        cout << "Berhasil Memperbarui produk" << endl;
    }

    membuatGaris(54, "-");
}

void ProdukManager::hapusProduk()
{
    tampilkanHeading("HAPUS PRODUK", 54);

    cout << "Masukkan Kode Produk : ";
    int kode = getValidInput(1, jumlahProduk);

    if (cekProduk(kode))
    {
        tampilkanTabelProduk(false, kode);

        char konfirmasi;
        cout << "Apakah anda yakin ingin menghapus produk tersebut\n[Y] Hapus  [N] Tidak\nMasukan Pilihan anda : ";
        cin >> konfirmasi;
        if (konfirmasi == 'y' || konfirmasi == 'Y')
        {
            produk[kode] = {};
            cout << "Produk Berhasil di hapus\n";
        }
        else
        {
            cout << "Hapus Produk di batalkan\n";
        }
    }
    membuatGaris(54, "-");
}

void ProdukManager::cariProduk()
{
    cout << "Masukkan nama produk yang ingin dicari: ";
    string nama = getValidString();

    bool ditemukan = false;
    for (int i = 0; i < jumlahProduk; i++)
    {
        if (produk[i].nama == nama)
        {
            tampilkanProduk(i);
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Produk tidak ditemukan.\n";
    }
}