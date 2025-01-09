#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include <string>
#include <vector>

struct detaiTransaksi
{
    int kodeProduk, idTransaksi, kuantitas, subTotal;
};

struct Transaksi
{
    int idTransaksi;
    std::string tanggalTransaksi;
    int subTotal = 0;
    int pajak = 0;
    int total = 0;
    int bayar = 0;
};

Transaksi transaksi[100];
detaiTransaksi detail[200];
int jumlahTransaksi = 1;
int JumlahDetailTransaksi = 1;

namespace TransaksiManager
{
    void tambahTransaksi();
    void tampilkanTransaksi(int kode = 0);
    void cetakStrukPenjualan();
}

void tampilkanTabelTransaksi(int idTransaksi);
void tambahProdukKeKeranjang();
void hitungTotalTransaksi(Transaksi &transaksi);
#endif // TRANSAKSI_H
