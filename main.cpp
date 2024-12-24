#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

void heading(string label)
{
    cout << "======================================================" << endl;
    cout << "                   PENGELOLAAN PRODUK                 " << endl;
    cout << "======================================================" << endl;
}

struct Produk
{
    int kode;
    string nama;
    int stok;
    int harga;
};

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

// Fungsi untuk menampilkan menu pengelolaan produk
void tambahProduk();
void tampilkanProduk(int kode);
void editProduk();
void hapusProduk();
void cariProduk();
bool cekProduk(int kode);

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
        if (pilihan != 6)
        {
            system("pause");
        }
    } while (pilihan != 6);
}

// Fungsi untuk menambahkan produk
void tambahProduk()
{
    cout << jumlahProduk << endl;
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
    else if (cekProduk(kode))
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

    if (cekProduk(kode))
    {
        tampilkanProduk(kode);

        cout << "\nMemperbarui data :\n";
        cout << "Nama  : ";
        cin >> produk[kode].nama;
        cout << "Harga : ";
        cin >> produk[kode].harga;
        cout << "Stok  : ";
        cin >> produk[kode].stok;
        cout << "Berhasil Memperbarui produk" << endl;
    }
}

// Fungsi untuk menghapus produk
void hapusProduk()
{
    int kode;

    cout << "Masukan kode produk yang ingin dihapus : ";
    cin >> kode;

    if (cekProduk(kode))
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
        cout << "Produk dengan kode produk " << kode << " tidak ditemukan.\n";
    }

    return ditemukan;
}

time_t timestamp = time(NULL);
struct tm datetime = *localtime(&timestamp);
char outputTime[50];

// Struktur untuk menyimpan data transaksi
struct detaiTransaksi
{
    int kodeProduk, idTransaksi, kuantitas, subTotal;
};

struct Transaksi
{
    int idTransaksi;
    string tanggalTransaksi;
    int totalTransaksi = 0;
};

Transaksi transaksi[100];
detaiTransaksi detail[200];
int jumlahTransaksi = 1;
int JumlahDetailTransaksi = 1;

// Fungsi untuk transaksi penjualan
void tambahTransaksi();
void tampilkanTransaksi();

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
            tampilkanTransaksi();
            break;
        case 3:
            break;
        }
        system("pause");
    } while (pilihan != 4);
}

// Fungsi untuk Menambahkan Transaksi
void lihatKeranjangTransaksi(int idTransaksi);
void tambahProdukKeKeranjang();

void tambahTransaksi()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "======================================================" << endl;
        cout << "                   TRANKSAKSI BARU                    " << endl;
        cout << "======================================================" << endl;
        cout << "|                   KERANJANG ANDA                   |" << endl;
        lihatKeranjangTransaksi(jumlahTransaksi);
        cout << "| " << setw(35) << "Total Harga | " << setw(15) << transaksi[jumlahTransaksi].totalTransaksi << " | " << endl;
        cout << "======================================================" << endl;
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Tambahkan Produk ke Dalam Keranjang\n";
        cout << "2. Lihat Daftar Produk\n";
        cout << "3. Keluar dan Simpan\n";
        cout << "======================================================" << endl;
        cout << "Masukan Pilihan Anda : ";
        cin >> pilihan;

        cout << endl;
        switch (pilihan)
        {
        case 1:
        {
            tambahProdukKeKeranjang();
            break;
        }
        case 2:
        {
            tampilkanProduk(0);
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
                int pajak, subTotal, total;
                transaksi[jumlahTransaksi].idTransaksi = jumlahTransaksi;

                subTotal = transaksi[jumlahTransaksi].totalTransaksi;
                pajak = transaksi[jumlahTransaksi].totalTransaksi * 0.1;
                total = transaksi[jumlahTransaksi].totalTransaksi + pajak;

                cout << "======================================================" << endl;
                cout << "|                 CHECKOUT KERANJANG                 |" << endl;
                lihatKeranjangTransaksi(jumlahTransaksi);
                cout << "| " << setw(35) << "SubTotal | " << setw(15) << subTotal << " | " << endl;
                cout << "| " << setw(35) << "Pajak (10%) | " << setw(15) << pajak << " | " << endl;
                cout << "| " << setw(35) << "Total | " << setw(15) << total << " | " << endl;
                cout << "--------------------------------------------------" << endl;

                int bayar;
                cout << "Masukkan pembayaran pelanggan : Rp";
                cin >> bayar;

                if (bayar)
                    cout << "Kembalian                     : Rp35.000" << endl;
                cout << "==================================================" << endl;
                cout << "Transaksi berhasil dicatat!" << endl;

                strftime(outputTime, 50, "%d/%m/%y", &datetime);
                transaksi[jumlahTransaksi].tanggalTransaksi = outputTime;
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

        system("pause");
    } while (pilihan != 3);
}

// Fungsi untuk menambahkan produk ke dalam keranjang
void tambahProdukKeKeranjang()
{
    system("cls");
    int kode = 0, kuantitas = 0;

    cout << "======================================================" << endl;
    cout << "              TAMBAHKAN PRODUK KE KERANJANG           " << endl;
    cout << "======================================================" << endl;
    cout << "Masukkan Kode Produk: ";
    cin >> kode;
    if (!cekProduk(kode))
    {
        return;
    }
    cout << "Masukkan Kuantitas  : ";
    cin >> kuantitas;
    if (produk[kode].stok - kuantitas < 0)
    {
        cout << "Stok tidak mencukupi.\n";
        return;
    }

    int subTotal = produk[kode].harga * kuantitas;

    cout << "------------------------------------------------------" << endl;
    cout << "Nama Produk         : " << produk[kode].nama << endl;
    cout << "Harga Satuan        : " << produk[kode].harga << endl;
    cout << "Subtotal            : " << subTotal << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Produk berhasil ditambahkan ke keranjang!" << endl;

    detail[JumlahDetailTransaksi].idTransaksi = jumlahTransaksi;
    detail[JumlahDetailTransaksi].kodeProduk = produk[kode].kode;
    detail[JumlahDetailTransaksi].kuantitas = kuantitas;
    detail[JumlahDetailTransaksi].subTotal = subTotal;

    transaksi[jumlahTransaksi].totalTransaksi += subTotal;
    JumlahDetailTransaksi++;
}

// Fungsi untuk melihat produk di dalam keranjang
void lihatKeranjangTransaksi(int idTransaksi)
{
    cout << "------------------------------------------------------" << endl;
    cout << "| Kode |    Nama Produk    |  QTY  |   Jumlah Harga  |" << endl;
    for (int i = 1; i <= JumlahDetailTransaksi; i++)
    {
        if (detail[i].idTransaksi == idTransaksi)
        {
            cout << "| " << setw(4) << detail[i].kodeProduk << " | " << setw(17) << produk[detail[i].kodeProduk].nama << " | " << setw(5) << detail[i].kuantitas << " | " << setw(15) << detail[i].subTotal << " | " << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
}

// Fungsi untuk menampilkan daftar traksaksi
void tampilkanTransaksi()
{
    cout << "=======================================================" << endl;
    cout << "                    DAFTAR TRANSAKSI                   " << endl;
    cout << "=======================================================" << endl;
    cout << "|  Tanggal  | Nomor Transaksi | Total Transaksi | Metode |" << endl;
    for (int i = 1; i < jumlahTransaksi; i++)
    {
        cout << "| " << setw(9) << transaksi[i].tanggalTransaksi << " | " << setw(15) << transaksi[i].idTransaksi << " | " << setw(15) << transaksi[i].totalTransaksi << " | "
             << "Tunai" << endl;
    }
    cout << "======================================================" << endl;
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
