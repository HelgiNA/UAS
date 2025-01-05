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

#endif // PRODUK_H
