#ifndef PRODUK_H
#define PRODUK_H

#include <string>
#include <vector>

struct Produk
{
    int kode;
    std::string nama;
    int stok;
    int harga;
};

namespace ProdukManager
{
    void tambahProduk();
    void tampilkanProduk(int kode = 0);
    void editProduk();
    void hapusProduk();
    void cariProduk();
}

extern Produk produk[100];

void tampilkanTabelProduk(bool tampilSemua = true, int kode = 0);
bool cekProduk(int kode, bool tampilkanError = true);

#endif // PRODUK_H
