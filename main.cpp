#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void heading(string label)
{
    cout << "======================================================" << endl;
    cout << "                   PENGELOLAAN PRODUK                 " << endl;
    cout << "======================================================" << endl;
}

// Struktur untuk menyimpan data produk
struct Produk
{
    int kode;
    string nama;
    int stok;
    double harga;
};

// Array untuk menyimpan produk
Produk produk[100];
int jumlahProduk = 1;

// Fungsi untuk menampilkan menu pengelolaan produk
void tambahProduk();
void tampilkanProduk(int kode);
void editProduk();
void hapusProduk();
void cariProduk();

void pengelolaanProduk()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "======================================================" << endl;
        cout << "                   PENGELOLAAN PRODUK                 " << endl;
        cout << "======================================================" << endl;
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Tambah Produk Baru\n";
        cout << "2. Lihat Daftar Produk\n";
        cout << "3. Perbarui Informasi Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "6. Kembali ke Menu Utama\n";
        cout << "======================================================" << endl;
        cout << "Masukan Pilihan Anda : ";
        cin >> pilihan;

        cout << endl;
        switch (pilihan)
        {
        case 1:
            tambahProduk();
            break;
        case 2:
            tampilkanProduk(0);
            break;
        case 3:
            editProduk();
            break;
        case 4:
            hapusProduk();
            break;
        case 5:
            cariProduk();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }

        system("pause");
    } while (pilihan != 6);
}

// Fungsi untuk menambahkan produk
void tambahProduk()
{
    cout << "=== Tambah Produk ===\n";
    cout << "Nama Produk  : ";
    cin >> produk[jumlahProduk].nama;
    cout << "Harga Produk : ";
    cin >> produk[jumlahProduk].harga;
    cout << "Stok Produk  : ";
    cin >> produk[jumlahProduk].stok;
    produk[jumlahProduk].kode = jumlahProduk;
    jumlahProduk++;
    cout << "Produk berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua produk
void tampilkanProduk(int kode)
{
    cout << "======================================================" << endl;
    cout << "                     DAFTAR PRODUK                    " << endl;
    cout << "======================================================" << endl;
    cout << "| Kode |    Nama Produk    |   Harga Jual   |  Stok  |" << endl;

    if (kode == 0)
    {
        for (int i = 1; i < jumlahProduk; i++)
        {
            if (produk[i].kode != 0)
            {
                cout << "| " << setw(4) << produk[i].kode << " | " << setw(17) << produk[i].nama << " | " << setw(14) << produk[i].harga << " | " << setw(6) << produk[i].stok << " | " << endl;
            }
        }
    }
    else
    {
        cout << "| " << setw(4) << produk[kode].kode << " | " << setw(17) << produk[kode].nama << " | " << setw(14) << produk[kode].harga << " | " << setw(6) << produk[kode].stok << " | " << endl;
    }

    cout << "======================================================" << endl;
}

// Fungsi untuk mengedit produk
void editProduk()
{
    int kode;

    cout << "Masukan kode produk yang ingin diperbarui : ";
    cin >> kode;

    if (produk[kode].kode > 0)
    {
        tampilkanProduk(kode);

        cout << "\nMemperbarui data :\n";
        cout << "Nama  : ";
        cin >> produk[kode].nama;
        cout << "Harga : ";
        cin >> produk[kode].harga;
        cout << "Stok  : ";
        cin >> produk[kode].stok;
    }
    else
    {
        cout << "Produk dengan kode produk " << kode << " tidak ditemukan.\n";
    }
}

// Fungsi untuk menghapus produk
void hapusProduk()
{
    int kode;

    cout << "Masukan kode produk yang ingin dihapus : ";
    cin >> kode;

    if (produk[kode].kode > 0)
    {
        tampilkanProduk(kode);

        char konfirmasi;
        cout << "Apakah anda yakin ingin menghapus produk tersebut : ";
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
    else
    {
        cout << "Produk dengan kode produk " << kode << " tidak ditemukan.\n";
    }
}

// Fungsi untuk mencari produk
void cariProduk()
{
    string nama;
    cout << "Masukkan nama produk yang ingin dicari: ";
    cin >> nama;
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

bool cekProduk(int kode)
{
    bool ditemukan = false;
    for (int i = 0; i < jumlahProduk; i++)
    {
        if (produk[i].kode == kode)
        {
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Produk tidak ditemukan.\n";
    }

    return ditemukan;
}

// Struktur untuk menyimpan data transaksi
struct detaiTransaksi
{
    int kodeProduk, idTransaksi, qty, jumlahHarga;
};

struct Transaksi
{
    int kode, totalTransaksi, idDetailTransaksi;
};

Transaksi transaksi[100];
detaiTransaksi detail[200];
int jumlahTransaksi = 1;
int JumlahDetailTransaksi = 1;

// Fungsi untuk transaksi penjualan
void tambahTransaksi();

void transaksiPenjualan()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "======================================================" << endl;
        cout << "                  TRANKSAKSI PENJUALAN                " << endl;
        cout << "======================================================" << endl;
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Buat Transaksi Baru\n";
        cout << "2. Lihat Riwayat Transaksi\n";
        cout << "3. Cetak Struk Penjualan\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "======================================================" << endl;
        cout << "Masukan Pilihan Anda : ";
        cin >> pilihan;

        cout << endl;
        switch (pilihan)
        {
        case 1:
            tambahTransaksi();
            break;
        case 2:
            break;
        case 3:
            editProduk();
            break;
        }

        system("pause");
    } while (pilihan != 4);
}

// Fungsi untuk Menambahkan Transaksi
void keranjangTransaksi(int idTransaksi);

void tambahTransaksi()
{
    transaksi[jumlahTransaksi].kode = jumlahTransaksi;
    int total;

tambahUlang:
{
    system("cls");
    tampilkanProduk(0);

    int jumlah = 0, kode = 0;

    cout << "Masukkan kode produk yang ingin dibeli : ";
    cin >> kode;

    char tambah;
    if (!cekProduk(kode))
    {
        goto tambahUlang;
    }

    cout << "Masukkan jumlah yang ingin dibeli : ";
    cin >> jumlah;
    if (!produk[kode].stok >= jumlah)
    {
        cout << "Stok tidak mencukupi.\n";
        goto tambahUlang;
    }

    produk[kode].stok -= jumlah;
    int jumlahHarga = produk[kode].harga * jumlah;
    cout << "\nBerhasil menambahkan " << produk[kode].nama << " Sebanyak " << jumlah << ".\n";

    detail[JumlahDetailTransaksi].idTransaksi = jumlahTransaksi;
    detail[JumlahDetailTransaksi].kodeProduk = produk[kode].kode;
    detail[JumlahDetailTransaksi].qty = jumlah;
    detail[JumlahDetailTransaksi].jumlahHarga = jumlahHarga;

    total += jumlahHarga;
    keranjangTransaksi(jumlahTransaksi);

    cout << "Apakah anda ingin menambahkan kembali produk ke keranjang : ";
    cin >> tambah;
    if (tambah == 'y' || tambah == 'Y')
    {
        JumlahDetailTransaksi++;
        goto tambahUlang;
    }
}

    transaksi[jumlahTransaksi].totalTransaksi = total;
    jumlahTransaksi++;
}

// Fungsi untuk menyimpan transaksi ke dalam keranjang sementara
void keranjangTransaksi(int idTransaksi)
{
    for (int i = 1; i <= JumlahDetailTransaksi; i++)
    {
        if (detail[i].idTransaksi == idTransaksi)
        {
            cout << detail[i].idTransaksi << endl;
            cout << detail[i].kodeProduk << endl;
            cout << detail[i].qty << endl;
            cout << detail[i].jumlahHarga << endl;
        }
    }
}

// Fungsi menu utama
void menu()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "======================================================" << endl;
        cout << "              SISTEM APLIKASI RETAIL MANAGER          " << endl;
        cout << "======================================================" << endl;
        cout << "Pilih Menu Utama:\n";
        cout << "1. Pengelolaan Produk\n";
        cout << "2. Transaksi Penjualan\n";
        cout << "3. Laporan (comming soon)\n";
        cout << "4. Pengelolaan Stok (comming soon)\n";
        cout << "5. Pengaturan (comming soon)\n";
        cout << "6. Keluar\n";
        cout << "======================================================" << endl;
        cout << "Masukan Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            pengelolaanProduk();
            break;
        case 2:
            transaksiPenjualan();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            cout << "Terima kasih telah menggunakan aplikasi.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 6);
}

// Fungsi utama
int main()
{
    menu();
    return 0;
}
