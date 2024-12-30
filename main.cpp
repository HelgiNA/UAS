#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

time_t timestamp = time(NULL);
struct tm datetime = *localtime(&timestamp);
char outputTime[50];

void membuatGaris(int panjangGaris, string simbol = "=")
{
    string garis;
    for (int i = 0; i < panjangGaris; i++)
    {
        garis += simbol;
    }

    cout << garis << endl;
}

void heading(string label, int panjang = 52)
{
    membuatGaris(panjang);
    cout << setw((panjang / 2) - (label.length() / 2)) << "" << label << endl;
    membuatGaris(panjang);
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

// fungsi untuk pengelolaan produk
void pengelolaanProduk()
{
    int pilihan;
    do
    {
        system("cls");
        heading("PENGELOLAAN PRODUK");
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

// Struktur untuk menyimpan data transaksi
struct detaiTransaksi
{
    int kodeProduk, idTransaksi, kuantitas, subTotal;
};

struct Transaksi
{
    int idTransaksi;
    string tanggalTransaksi;
    int subTotal = 0, pajak = 0, total = 0;
    int bayar = 0;
};

Transaksi transaksi[100];
detaiTransaksi detail[200];
int jumlahTransaksi = 1;
int JumlahDetailTransaksi = 1;

// Fungsi untuk transaksi penjualan
void tambahTransaksi();
void tampilkanTransaksi();
void lihatKeranjangTransaksi(int idTransaksi);
void tambahProdukKeKeranjang();
void cetakStrukPenjualan();

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

        switch (pilihan)
        {
        case 1:
            tambahTransaksi();
            break;
        case 2:
            tampilkanTransaksi();
            break;
        case 3:
            cetakStrukPenjualan();
            break;
        }
        system("pause");
    } while (pilihan != 4);
}

// Fungsi untuk Menambahkan Transaksi
void tambahTransaksi()
{
    int pilihan;
    int idTransaksi = jumlahTransaksi;
    do
    {
        system("cls");
        cout << "======================================================" << endl;
        cout << "                   TRANKSAKSI BARU                    " << endl;
        cout << "======================================================" << endl;
        cout << "|                   KERANJANG ANDA                   |" << endl;
        lihatKeranjangTransaksi(jumlahTransaksi);
        cout << "| " << setw(35) << "Total Harga | " << setw(15) << transaksi[jumlahTransaksi].subTotal << " | " << endl;
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
            system("pause");
            break;
        }
        case 2:
        {
            tampilkanProduk(0);
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
                transaksi[idTransaksi].pajak = transaksi[idTransaksi].subTotal * 0.1;
                transaksi[idTransaksi].total = transaksi[idTransaksi].subTotal + transaksi[idTransaksi].pajak;

                cout << "======================================================" << endl;
                cout << "|                 CHECKOUT KERANJANG                 |" << endl;
                lihatKeranjangTransaksi(idTransaksi);
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

    detail[idDetailTransaksi].idTransaksi = idTransaksi;
    detail[idDetailTransaksi].kodeProduk = produk[kode].kode;
    detail[idDetailTransaksi].kuantitas = kuantitas;
    detail[idDetailTransaksi].subTotal = subTotal;

    transaksi[idTransaksi].subTotal += subTotal;
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
void tampilkanDetailTransaksi(int id);
void tampilkanTransaksi()
{
    system("cls");
    int idTransaksi;
    cout << "=======================================================" << endl;
    cout << "                    DAFTAR TRANSAKSI                   " << endl;
    cout << "=======================================================" << endl;
    cout << "|  Tanggal  | Nomor Transaksi | Total Transaksi | Metode |" << endl;
    for (int i = 1; i < jumlahTransaksi; i++)
    {
        cout << "| " << setw(9) << transaksi[i].tanggalTransaksi
             << " | " << setw(15) << transaksi[i].idTransaksi
             << " | " << setw(15) << transaksi[i].subTotal
             << " | " << "Tunai" << endl;
    }
    cout << "======================================================" << endl;
    cout << "Masukan Nomor Transaksi Untuk Detail : ";
    cin >> idTransaksi;

    if (transaksi[idTransaksi].idTransaksi != 0)
    {
        tampilkanDetailTransaksi(idTransaksi);
    }
    else
    {
        cout << "Transaksi Dengan Kode " << idTransaksi << " Tidak di Temukan!" << endl;
    }
}

void tampilkanDetailTransaksi(int idTransaksi)
{
    system("cls");

    cout << "======================================================" << endl;
    cout << "                   DETAIL TRANSAKSI                   " << endl;
    cout << "======================================================" << endl;
    cout << "Nomor Transaksi : " << transaksi[idTransaksi].idTransaksi << endl;
    cout << "Tanggal/Waktu   : " << transaksi[idTransaksi].tanggalTransaksi << endl;
    cout << "======================================================" << endl;
    cout << "|                 Produk Yang di Beli                |" << endl;
    lihatKeranjangTransaksi(idTransaksi);
    cout << "| " << setw(35) << "SubTotal | " << setw(15) << transaksi[idTransaksi].subTotal << " | " << endl;
    cout << "| " << setw(35) << "Pajak (10%) | " << setw(15) << transaksi[idTransaksi].pajak << " | " << endl;
    cout << "| " << setw(35) << "Total | " << setw(15) << transaksi[idTransaksi].total << " | " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Metode          : Tunai" << endl;
    cout << "Kasir           : Hans" << endl;
    cout << "======================================================" << endl;
}

void cetakStrukPenjualan()
{
    system("cls");
    int idTransaksi;

    heading("CETAK STRUK PENJUALAN");
    cout << "Masukkan Nomor Transaksi: ";
    cin >> idTransaksi;

    // Periksa apakah transaksi ada
    if (transaksi[idTransaksi].idTransaksi != 0)
    {
        system("cls");
        heading("STRUK TRANSAKSI", 50);
        cout << "Toko Retail XYZ\n";
        cout << "Tanggal  : " << transaksi[idTransaksi].tanggalTransaksi << endl;
        cout << "Kasir    : Hans" << endl; // Anda dapat mengganti nama kasir
        membuatGaris(50, "-");
        cout << "Produk" << setw(31 - sizeof("Produk")) << ""
             << "Qty" << setw(6 - sizeof("Qty")) << ""
             << "Harga" << setw(9 - sizeof("Harga")) << ""
             << "Total" << endl;

        // Ambil detail transaksi
        for (int i = 1; i <= JumlahDetailTransaksi; i++)
        {
            if (detail[i].idTransaksi == idTransaksi)
            {
                cout << produk[detail[i].kodeProduk].nama << setw(30 - produk[detail[i].kodeProduk].nama.length()) << ""
                     << detail[i].kuantitas << setw(5 - to_string(detail[i].kuantitas).length()) << ""
                     << produk[detail[i].kodeProduk].harga << setw(8 - to_string(produk[detail[i].kodeProduk].harga).length()) << ""
                     << detail[i].subTotal << endl;
            }
        }

        membuatGaris(50, "-");
        cout << "Subtotal                     : " << transaksi[idTransaksi].subTotal << endl;
        cout << "Pajak (10%)                  : " << transaksi[idTransaksi].pajak << endl;
        membuatGaris(50, "-");
        cout << "Total                        : " << transaksi[idTransaksi].total << endl;
        cout << "Tunai                        : " << transaksi[idTransaksi].bayar << endl;
        cout << "Kembalian                    : " << transaksi[idTransaksi].bayar - transaksi[idTransaksi].total << endl;
        heading("Terima kasih telah berbelanja!", 50);
    }
    else
    {
        cout << "Transaksi dengan nomor " << idTransaksi << " tidak ditemukan!\n";
    }
}

//
void laporanHarian();
void laporanBulanan();
void laporanTahunan();

void laporan()
{
    int pilihan;
    do
    {
        system("cls");
        heading("LAPORAN");
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Laporan Harian\n";
        cout << "2. Laporan Bulanan\n";
        cout << "3. Laporan Tahunan\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Masukan Pilihan Anda : ";
        cin >> pilihan;

        cout << endl;
        switch (pilihan)
        {
        case 1:
            laporanHarian();
            break;
        case 2:
            laporanBulanan();
            break;
        case 3:
            laporanTahunan();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
        if (pilihan != 4)
        {
            system("pause");
        }
    } while (pilihan != 4);
}

void laporanHarian()
{
    system("cls");
    heading("LAPORAN HARIAN");

    // Input tanggal (opsional)
    string tanggal;
    cout << "Masukkan tanggal (DD-MM-YYYY) atau tekan Enter untuk hari ini: ";
    cin.ignore();
    getline(cin, tanggal);

    // Gunakan tanggal hari ini jika input kosong
    if (tanggal.empty())
    {
        strftime(outputTime, 50, "%d-%m-%Y", &datetime);
        tanggal = outputTime;
    }

    // Variabel untuk menyimpan data laporan
    int totalPenjualan = 0;
    int laporanJumlahTransaksi = 0;
    int pendapatanProduk[100] = {0}; // Pendapatan per produk berdasarkan kode produk
    int kuantitasProduk[100] = {0};  // Kuantitas terjual per produk

    // Iterasi melalui transaksi untuk tanggal yang dimasukkan
    for (int i = 1; i < jumlahTransaksi; i++)
    {
        if (transaksi[i].tanggalTransaksi == tanggal)
        {
            laporanJumlahTransaksi++;
            totalPenjualan += transaksi[i].subTotal;
            // Iterasi melalui detail transaksi
            for (int j = 1; j <= JumlahDetailTransaksi; j++)
            {
                if (detail[j].idTransaksi == transaksi[i].idTransaksi)
                {
                    pendapatanProduk[detail[j].kodeProduk] += detail[j].subTotal;
                    kuantitasProduk[detail[j].kodeProduk] += detail[j].kuantitas;
                }
            }
        }
    }

    // Tampilkan laporan
    cout << "==================================================\n";
    cout << "Tanggal               : " << tanggal << endl;
    cout << "Total Penjualan       : Rp " << totalPenjualan << endl;
    cout << "Jumlah Transaksi      : " << laporanJumlahTransaksi << endl;
    cout << "--------------------------------------------------\n";
    cout << "Rincian Produk Terjual:\n";
    cout << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
         << "QTY" << " | "
         << "Pendapatan" << endl;
    cout << "--------------------------------------------------\n";

    for (int i = 1; i < jumlahProduk; i++)
    {
        if (pendapatanProduk[i] > 0)
        {
            cout << produk[i].nama << setw(32 - produk[i].nama.length()) << " | "
                 << kuantitasProduk[i] << setw(3 - to_string(kuantitasProduk[i]).length()) << "" << " | "
                 << "Rp " << pendapatanProduk[i] << endl;
        }
    }

    cout << "--------------------------------------------------\n";
    cout << "Laporan harian selesai ditampilkan.\n";
}

void laporanBulanan()
{
    system("cls");
    heading("LAPORAN BULANAN");

    // Input bulan (opsional)
    string bulan;
    cout << "Masukkan bulan (MM-YYYY) atau tekan Enter untuk bulan ini: ";
    cin.ignore();
    getline(cin, bulan);

    // Gunakan bulan saat ini jika input kosong
    if (bulan.empty())
    {
        strftime(outputTime, 50, "%m-%Y", &datetime);
        bulan = outputTime;
    }

    // Variabel untuk menyimpan data laporan
    int totalPenjualan = 0;
    int laporanJumlahTransaksi = 0;
    int pendapatanProduk[100] = {0}; // Pendapatan per produk berdasarkan kode produk
    int kuantitasProduk[100] = {0};  // Kuantitas terjual per produk
    int totalKuantitas = 0;          // Total kuantitas semua produk

    // Iterasi melalui transaksi untuk bulan yang dimasukkan
    for (int i = 1; i < jumlahTransaksi; i++)
    {
        // Ambil bulan transaksi (format MM-YYYY)
        string bulanTransaksi = transaksi[i].tanggalTransaksi.substr(3, 7);
        if (bulanTransaksi == bulan)
        {
            laporanJumlahTransaksi++;
            totalPenjualan += transaksi[i].subTotal;

            // Iterasi melalui detail transaksi
            for (int j = 1; j <= JumlahDetailTransaksi; j++)
            {
                if (detail[j].idTransaksi == transaksi[i].idTransaksi)
                {
                    pendapatanProduk[detail[j].kodeProduk] += detail[j].subTotal;
                    kuantitasProduk[detail[j].kodeProduk] += detail[j].kuantitas;
                    totalKuantitas += detail[j].kuantitas;
                }
            }
        }
    }

    // Tampilkan laporan
    cout << "==================================================\n";
    cout << "Bulan                   : " << bulan << endl;
    cout << "Total Penjualan         : Rp " << totalPenjualan << endl;
    cout << "Jumlah Transaksi        : " << laporanJumlahTransaksi << endl;
    cout << "--------------------------------------------------\n";
    cout << "Produk Terlaris:\n";
    cout << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
         << "QTY" << " | "
         << "Persentase" << endl;
    cout << "--------------------------------------------------\n";

    for (int i = 1; i < jumlahProduk; i++)
    {
        if (pendapatanProduk[i] > 0)
        {
            float persentase = (float(kuantitasProduk[i]) / totalKuantitas) * 100;
            cout << produk[i].nama << setw(32 - produk[i].nama.length()) << " | "
                 << kuantitasProduk[i] << setw(3 - to_string(kuantitasProduk[i]).length()) << "" << " | "
                 << fixed << setprecision(1) << persentase << "%" << endl;
        }
    }

    // Hitung laba/rugi (opsional)
    int biayaOperasional = 20000000; // Contoh biaya operasional tetap
    int labaRugi = totalPenjualan - biayaOperasional;
    cout << "--------------------------------------------------\n";
    cout << "Laba/Rugi            : Rp " << labaRugi << endl;
    cout << "--------------------------------------------------\n";
    cout << "Laporan bulanan selesai ditampilkan.\n";
}

void laporanTahunan()
{
    system("cls");
    heading("LAPORAN TAHUNAN");

    // Input tahun (opsional)
    string tahun;
    cout << "Masukkan tahun (YYYY) atau tekan Enter untuk tahun ini: ";
    cin.ignore();
    getline(cin, tahun);

    // Gunakan tahun saat ini jika input kosong
    if (tahun.empty())
    {
        strftime(outputTime, 50, "%Y", &datetime);
        tahun = outputTime;
    }

    // Variabel untuk menyimpan data laporan
    int totalPenjualan = 0;
    int laporanJumlahTransaksi = 0;
    int pendapatanPerBulan[12] = {0}; // Pendapatan per bulan
    int pendapatanProduk[100] = {0};  // Pendapatan per produk berdasarkan kode produk
    int kuantitasProduk[100] = {0};   // Kuantitas terjual per produk
    int totalKuantitas = 0;           // Total kuantitas semua produk

    // Iterasi melalui transaksi untuk tahun yang dimasukkan
    for (int i = 1; i < jumlahTransaksi; i++)
    {
        // Ambil tahun transaksi (format YYYY)
        string tahunTransaksi = transaksi[i].tanggalTransaksi.substr(6, 4);
        if (tahunTransaksi == tahun)
        {
            laporanJumlahTransaksi++;
            totalPenjualan += transaksi[i].subTotal;

            // Hitung pendapatan per bulan
            int bulanIndex = stoi(transaksi[i].tanggalTransaksi.substr(3, 2)) - 1; // Ambil bulan (0-11)
            pendapatanPerBulan[bulanIndex] += transaksi[i].subTotal;

            // Iterasi melalui detail transaksi
            for (int j = 1; j <= JumlahDetailTransaksi; j++)
            {
                if (detail[j].idTransaksi == transaksi[i].idTransaksi)
                {
                    pendapatanProduk[detail[j].kodeProduk] += detail[j].subTotal;
                    kuantitasProduk[detail[j].kodeProduk] += detail[j].kuantitas;
                    totalKuantitas += detail[j].kuantitas;
                }
            }
        }
    }

    // Cari bulan terbaik dan terburuk
    int bulanTerbaik = 0, bulanTerburuk = 0;
    for (int i = 1; i < 12; i++)
    {
        if (pendapatanPerBulan[i] > pendapatanPerBulan[bulanTerbaik])
            bulanTerbaik = i;
        if (pendapatanPerBulan[i] < pendapatanPerBulan[bulanTerburuk])
            bulanTerburuk = i;
    }

    // Tampilkan laporan
    const string namaBulan[] = {
        "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    cout << "==================================================\n";
    cout << "Tahun                   : " << tahun << endl;
    cout << "Total Penjualan         : Rp " << totalPenjualan << endl;
    cout << "Jumlah Transaksi        : " << laporanJumlahTransaksi << endl;
    cout << "--------------------------------------------------\n";
    cout << "Bulan Terbaik           : " << namaBulan[bulanTerbaik]
         << " (Rp " << pendapatanPerBulan[bulanTerbaik] << ")" << endl;
    cout << "Bulan Terburuk          : " << namaBulan[bulanTerburuk]
         << " (Rp " << pendapatanPerBulan[bulanTerburuk] << ")" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Produk Terlaris Sepanjang Tahun:\n";
    cout << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
         << "QTY" << " | "
         << "Pendapatan" << endl;
    cout << "--------------------------------------------------\n";

    for (int i = 1; i < jumlahProduk; i++)
    {
        if (pendapatanProduk[i] > 0)
        {
            cout << produk[i].nama << setw(32 - produk[i].nama.length()) << " | "
                 << kuantitasProduk[i] << setw(3 - to_string(kuantitasProduk[i]).length()) << "" << " | "
                 << "Rp " << pendapatanProduk[i] << endl;
        }
    }

    // Hitung laba/rugi (opsional)
    int biayaOperasionalTahunan = 240000000; // Contoh biaya operasional tetap
    int labaRugi = totalPenjualan - biayaOperasionalTahunan;
    cout << "--------------------------------------------------\n";
    cout << "Laba/Rugi Tahunan      : Rp " << labaRugi << endl;
    cout << "--------------------------------------------------\n";
    cout << "Laporan tahunan selesai ditampilkan.\n";
}

//
void cekStokProduk();
void tambahStokProduk();
void lihatLogStok();

void pengelolaanStok()
{
    int pilihan;
    do
    {
        system("cls");
        heading("PENGELOLAAN STOK");
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Cek Stok Produk\n";
        cout << "2. Tambah Stok Baru\n";
        cout << "3. Lihat Log Perubahan Stok\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Masukan Pilihan Anda : ";
        cin >> pilihan;

        cout << endl;
        switch (pilihan)
        {
        case 1:
            cekStokProduk();
            break;
        case 2:
            tambahStokProduk();
            break;
        case 3:
            lihatLogStok();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
        if (pilihan != 4)
        {
            system("pause");
        }
    } while (pilihan != 4);
}
//
void cekStokProduk()
{
    system("cls");
    heading("CEK STOK PRODUK");

    // Input ID atau nama produk
    int input;
    cout << "Masukkan ID produk (angka): ";
    cin >> input;

    if (cekProduk(input))
    {
        membuatGaris(52, "-");
        cout << "Nama Produk    : " << produk[input].nama << endl;
        cout << "Stok Tersedia  : " << produk[input].stok << " unit" << endl;
        cout << "Lokasi         : Gudang A" << endl; // Lokasi default
        membuatGaris(52, "-");
    }
}

struct LogStok
{
    string tanggal;
    string namaProduk;
    int perubahan; // Positif untuk penambahan
    string alasan; // Alasan perubahan (e.g., Restock)
};

LogStok logStok[200];
int jumlahLog = 0;

void tambahLogStok(string namaProduk, int perubahan, string alasan)
{
    strftime(outputTime, 50, "%d-%m-%Y", &datetime); // Mendapatkan tanggal saat ini
    logStok[jumlahLog].tanggal = outputTime;
    logStok[jumlahLog].namaProduk = namaProduk;
    logStok[jumlahLog].perubahan = perubahan;
    logStok[jumlahLog].alasan = alasan;
    jumlahLog++;
}

void tambahStokProduk()
{
    system("cls");
    heading("TAMBAH STOK BARU");

    int kode;
    int jumlah;
    bool ditemukan = false;

    // Input ID atau nama produk
    cout << "Masukkan Kode Produk: ";
    cin >> kode;
    if (cekProduk(kode))
    {
        cout << "Masukkan jumlah stok yang ingin ditambahkan: ";
        cin >> jumlah;

        // Update stok dan tampilkan informasi
        int stokLama = produk[kode].stok;
        produk[kode].stok += jumlah;

        cout << "--------------------------------------------------\n";
        cout << "Nama Produk    : " << produk[kode].nama << endl;
        cout << "Stok Lama      : " << stokLama << " unit" << endl;
        cout << "Stok Baru      : " << produk[kode].stok << " unit" << endl;
        cout << "--------------------------------------------------\n";
        cout << "Stok berhasil diperbarui!\n";

        // Tambahkan ke log
        tambahLogStok(produk[kode].nama, jumlah, "Restock");
    }
}

void lihatLogStok()
{
    system("cls");
    heading("LOG PERUBAHAN STOK");

    if (jumlahLog == 0)
    {
        cout << "Belum ada log perubahan stok.\n";
        return;
    }
    cout << "Produk" << setw(15 - sizeof("Tanggal")) << " | "
         << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
         << "Perubahan" << setw(13 - sizeof("Perubahan")) << " | "
         << "Alasan" << endl;

    cout << "------------------------------------------------------\n";
    for (int i = 0; i < jumlahLog; i++)
    {
        cout << logStok[i].tanggal << setw(13 - logStok[i].tanggal.length()) << " | "
             << logStok[i].namaProduk << setw(32 - logStok[i].namaProduk.length()) << " | "
             << logStok[i].perubahan << setw(12 - to_string(logStok[i].perubahan).length()) << " | "
             << logStok[i].alasan << endl;
    }
    cout << "------------------------------------------------------\n";
}

// Fungsi menu utama
void menu()
{
    int pilihan;
    do
    {
        system("cls");
        heading("SISTEM APLIKASI RETAIL MANAGER");
        cout << "Pilih Menu Utama:\n";
        cout << "1. Pengelolaan Produk\n";
        cout << "2. Transaksi Penjualan\n";
        cout << "3. Laporan\n";
        cout << "4. Pengelolaan Stok\n";
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
            laporan();
            break;
        case 4:
            pengelolaanStok();
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
