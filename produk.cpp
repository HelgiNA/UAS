#include "produk.h"
#include "func.cpp"
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

void ProdukManager::tambahProduk()
{
    tampilkanHeading("TAMBAH PRODUK BARU");

    int kodeProduk = jumlahProduk;
    cout << "Masukan Nama Produk   : ";
    string nama = getValidString();
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
    // Implementasi tampilkan produk
}

void ProdukManager::editProduk()
{
    // Implementasi edit produk
}

void ProdukManager::hapusProduk()
{
    // Implementasi hapus produk
}
