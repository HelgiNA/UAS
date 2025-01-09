#include "../include/utils.h"
#include "../include/transaksi.h"
#include "../include/produk.h"

#include <iostream>
#include <iomanip>

void tampilkanTabelTransaksi(int idTransaksi)
{
    bool transaksiDitemukan = false;

    cout << "------------------------------------------------------\n";
    cout << "| Kode |    Nama Produk    |  QTY  |   Jumlah Harga  |\n";
    for (int i = 1; i <= JumlahDetailTransaksi; i++)
    {
        transaksiDitemukan = true;
        if (detail[i].idTransaksi == idTransaksi)
        {
            cout << "| " << setw(4) << detail[i].kodeProduk
                 << " | " << setw(17) << produk[detail[i].idTransaksi].nama
                 << " | " << setw(5) << detail[i].kuantitas
                 << " | " << setw(15) << detail[i].subTotal << " |\n";
        }
        break;
    }
    cout << "------------------------------------------------------\n";

    if (!transaksiDitemukan)
    {
        cout << "Transaksi dengan ID " << idTransaksi << " tidak ditemukan.\n";
        return;
    }
}

// Fungsi untuk Menambahkan Transaksi
void TransaksiManager::tambahTransaksi()
{
    int pilihan;
    int idTransaksi = jumlahTransaksi;
    do
    {
        system("cls");
        tampilkanHeading("TRANKSAKSI BARU");
        cout << "|                   KERANJANG ANDA                   |" << endl;
        tampilkanTabelTransaksi(idTransaksi);
        cout << "| " << setw(35) << "Total Harga | " << setw(15) << transaksi[jumlahTransaksi].subTotal << " | " << endl;
        membuatGaris(54);
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Tambahkan Produk ke Dalam Keranjang\n";
        cout << "2. Lihat Daftar Produk\n";
        cout << "3. Keluar dan Simpan\n";
        membuatGaris(54);
        cout << "Masukan Pilihan Anda : ";

        pilihan = getValidInput(1, 4);

        cout << endl;
        switch (pilihan)
        {
        case 1:
        {
            tambahProdukKeKeranjang();
            system("pause");
            break;
        }
        case 2:
        {
            tampilkanTabelProduk();
            system("pause");
            break;
        }
        case 3:
        {
            char In;
            cout << "Apakah anda ingin menyimpan Transaksi ini\n[Y] Simpan  [N] Tidak  [C] Batal\nMasukan Pilihan anda : ";
            cin >> In;
            if (In == 'Y' || In == 'y')
            {
                system("cls");

                transaksi[idTransaksi].idTransaksi = idTransaksi;
                hitungTotalTransaksi(transaksi[idTransaksi]);

                cout << "======================================================" << endl;
                cout << "|                 CHECKOUT KERANJANG                 |" << endl;
                tampilkanTabelTransaksi(idTransaksi);
                cout << "| " << setw(35) << "SubTotal | " << setw(15) << transaksi[idTransaksi].subTotal << " | " << endl;
                cout << "| " << setw(35) << "Pajak (10%) | " << setw(15) << transaksi[idTransaksi].pajak << " | " << endl;
                cout << "| " << setw(35) << "Total | " << setw(15) << transaksi[idTransaksi].total << " | " << endl;
                cout << "------------------------------------------------------" << endl;

                cout << "Masukkan pembayaran pelanggan : Rp";
                cin >> transaksi[idTransaksi].bayar;
                cout << "Kembalian                     : Rp" << transaksi[idTransaksi].bayar - transaksi[idTransaksi].total << endl;
                cout << "======================================================" << endl;
                cout << "Transaksi berhasil dicatat!" << endl;

                strftime(outputTime, 50, "%d-%m-%Y", &datetime);
                transaksi[idTransaksi].tanggalTransaksi = outputTime;
                jumlahTransaksi++;
            }
            else if (In == 'N' || In == 'n')
            {
                cout << "Transaksi Tidak disimpan\n";
            }
            else if (In == 'C' || In == 'c')
            {
                cout << "Transaksi dibatalkan\n";
                pilihan = 0;
            }
        }
        break;
        }
    } while (pilihan != 3);
}

// Fungsi untuk menambahkan produk ke dalam keranjang
void tambahProdukKeKeranjang()
{
    system("cls");
    int idTransaksi = jumlahTransaksi;
    int idDetailTransaksi = JumlahDetailTransaksi;
    int kode = 0, kuantitas = 0;

    tampilkanHeading("TAMBAHKAN PRODUK KE KERANJANG");

    cout << "Masukkan Kode Produk: ";
    kode = getValidInput();
    if (!cekProduk(kode, true))
    {
        return;
    }

    cout << "Masukkan Kuantitas  : ";
    kuantitas = getValidInput();
    if (produk[kode].stok - kuantitas < 0)
    {
        cout << "Stok tidak mencukupi.\n";
        return;
    }

    int subTotal = produk[kode].harga * kuantitas;

    membuatGaris(54, "-");
    cout << "Nama Produk         : " << produk[kode].nama << endl;
    cout << "Harga Satuan        : " << produk[kode].harga << endl;
    cout << "Subtotal            : " << subTotal << endl;
    membuatGaris(54, "-");
    cout << "Produk berhasil ditambahkan ke keranjang!" << endl;

    detail[idDetailTransaksi] = {idTransaksi, produk[kode].kode, kuantitas, subTotal};
    JumlahDetailTransaksi++;
}

void hitungTotalTransaksi(Transaksi &transaksi)
{
    if (transaksi.subTotal < 0)
    {
        cout << "Subtotal tidak valid.\n";
        transaksi.subTotal = 0;
    }

    transaksi.pajak = transaksi.subTotal * 0.1;
    transaksi.total = transaksi.subTotal + transaksi.pajak;
}

// // Fungsi untuk melihat produk di dalam keranjang
// void lihatKeranjangTransaksi(int idTransaksi)
// {
//     tampilkanTabelTransaksi(idTransaksi);
// }