#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <algorithm> // Tambahkan ini
#include <cctype>    // Untuk std::isspace
using namespace std;

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

int getValidInput(int min = 1, int max = INT32_MAX);
string getValidString(string pesanKesalahan = "Input tidak valid. Masukkan teks yang benar.");
bool cekProduk(int kode, bool tampilkanError = true);
void tampilkanTabelProduk(bool tampilSemua = true, int kode = 0);
void tampilkanTabelTransaksi(int idTransaksi);
void hitungTotalTransaksi(Transaksi &transaksi);

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

void tampilkanHeading(const string &judul, int panjang = 52, char simbol = '=')
{
    system("cls");
    membuatGaris(panjang, string(1, simbol));
    cout << setw((panjang / 2) - (judul.length() / 2)) << "" << judul << endl;
    membuatGaris(panjang, string(1, simbol));
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

// fungsi untuk pengelolaan produk
void pengelolaanProduk()
{
    int pilihan;
    do
    {
        tampilkanHeading("PENGELOLAAN PRODUK");
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Tambah Produk Baru\n";
        cout << "2. Lihat Daftar Produk\n";
        cout << "3. Perbarui Informasi Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "6. Kembali ke Menu Utama\n";
        cout << "======================================================" << endl;
        cout << "Masukan Pilihan Anda : ";

        pilihan = getValidInput(1, 6);

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
        case 6:
            cout << "Keluar dari menu pengelolaan produk" << endl;
            break;
        }

        system("pause");
    } while (pilihan != 6);
}

// Fungsi untuk menambahkan produk
void tambahProduk()
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

// Fungsi untuk menampilkan semua produk
void tampilkanProduk(int kode)
{
    tampilkanTabelProduk(kode);
}

// Fungsi untuk mengedit produk
void editProduk()
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

// Fungsi untuk menghapus produk
void hapusProduk()
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

// Fungsi untuk mencari produk
void cariProduk()
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
        tampilkanHeading("TRANKSAKSI PENJUALAN");
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Buat Transaksi Baru\n";
        cout << "2. Lihat Riwayat Transaksi\n";
        cout << "3. Cetak Struk Penjualan\n";
        cout << "4. Kembali ke Menu Utama\n";
        membuatGaris(52);
        cout << "Masukan Pilihan Anda : ";

        pilihan = getValidInput(1, 4);

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
        case 4:
            cout << "keluar dari menu transaksi penjualan" << endl;
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

    tampilkanHeading("TAMBAHKAN PRODUK KE KERANJANG");

    cout << "Masukkan Kode Produk: ";
    kode = getValidInput();
    if (!cekProduk(kode))
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

// Fungsi untuk melihat produk di dalam keranjang
void lihatKeranjangTransaksi(int idTransaksi)
{
    tampilkanTabelTransaksi(idTransaksi);
}

// Fungsi untuk menampilkan daftar traksaksi
void tampilkanDetailTransaksi(int id);
void tampilkanTransaksi()
{
    system("cls");
    int idTransaksi;
    tampilkanHeading("DAFTAR TRANSAKSI", 54);
    cout << "|  Tanggal  | Nomor Transaksi | Total Transaksi | Metode |" << endl;
    for (int i = 1; i < jumlahTransaksi; i++)
    {
        cout << "| " << setw(9) << transaksi[i].tanggalTransaksi
             << " | " << setw(15) << transaksi[i].idTransaksi
             << " | " << setw(15) << transaksi[i].subTotal
             << " | " << "Tunai" << endl;
    }
    membuatGaris(54);
    cout << "Masukan Nomor Transaksi Untuk Detail : ";
    idTransaksi = getValidInput();

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

    tampilkanHeading("DETAIL TRANSAKSI", 54);
    cout << "Nomor Transaksi : " << transaksi[idTransaksi].idTransaksi << endl;
    cout << "Tanggal/Waktu   : " << transaksi[idTransaksi].tanggalTransaksi << endl;
    cout << "======================================================" << endl;
    cout << "|                 Produk Yang di Beli                |" << endl;
    tampilkanTabelTransaksi(idTransaksi);
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

    tampilkanHeading("CETAK STRUK PENJUALAN");
    cout << "Masukkan Nomor Transaksi: ";
    int idTransaksi = getValidInput();

    // Periksa apakah transaksi ada
    if (transaksi[idTransaksi].idTransaksi != 0)
    {
        system("cls");
        tampilkanHeading("STRUK TRANSAKSI", 50);
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
        tampilkanHeading("Terima kasih telah berbelanja!", 50);
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
        tampilkanHeading("LAPORAN");
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Laporan Harian\n";
        cout << "2. Laporan Bulanan\n";
        cout << "3. Laporan Tahunan\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Masukan Pilihan Anda : ";

        pilihan = getValidInput(1, 4);

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
    tampilkanHeading("LAPORAN HARIAN");

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
    tampilkanHeading("LAPORAN BULANAN");

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
    tampilkanHeading("LAPORAN TAHUNAN");

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
        tampilkanHeading("PENGELOLAAN STOK");
        cout << "Pilih Menu Utama:" << endl;
        cout << "1. Cek Stok Produk\n";
        cout << "2. Tambah Stok Baru\n";
        cout << "3. Lihat Log Perubahan Stok\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Masukan Pilihan Anda : ";

        pilihan = getValidInput(1, 4);

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
    tampilkanHeading("CEK STOK PRODUK");

    // Input ID atau nama produk
    cout << "Masukkan ID produk (angka): ";
    int input = getValidInput();

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
    tampilkanHeading("TAMBAH STOK BARU");

    // Input ID atau nama produk
    cout << "Masukkan Kode Produk: ";
    int kode = getValidInput();
    if (cekProduk(kode))
    {
        cout << "Masukkan jumlah stok yang ingin ditambahkan: ";
        int jumlah = getValidInput();

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
    tampilkanHeading("LOG PERUBAHAN STOK");

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
        tampilkanHeading("SISTEM APLIKASI RETAIL MANAGER");
        cout << "Pilih Menu Utama:\n";
        cout << "1. Pengelolaan Produk\n";
        cout << "2. Transaksi Penjualan\n";
        cout << "3. Laporan\n";
        cout << "4. Pengelolaan Stok\n";
        cout << "5. Pengaturan (comming soon)\n";
        cout << "6. Keluar\n";
        membuatGaris(54);
        cout << "Masukan Pilihan Anda : ";

        pilihan = getValidInput(1, 6); // Validasi input angka

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
            cout << "Fitur belum tersedia.\n";
            break;
        case 6:
            cout << "Terima kasih telah menggunakan aplikasi.\n";
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

int getValidInput(int min, int max)
{
    int input;
    while (true)
    {
        cin >> input;

        // Jika input gagal atau di luar batas
        if (cin.fail() || input < min || input > max)
        {
            cin.clear();                // Reset flag kesalahan
            cin.ignore(INT8_MAX, '\n'); // Abaikan input yang salah
            if (max == INT32_MAX)
            {
                cout << "Input tidak valid. Masukkan angka lebih dari " << min << ": ";
            }
            else
            {
                cout << "Input tidak valid. Masukkan angka antara " << min << " dan " << max << ": ";
            }
        }
        else
        {
            cin.ignore(INT8_MAX, '\n'); // Abaikan karakter tambahan
            break;
        }
    }
    return input;
}

string getValidString(string pesanKesalahan)
{
    string input;
    while (true)
    {
        getline(cin, input); // Gunakan getline untuk mendukung spasi

        // Validasi input kosong atau hanya spasi
        if (input.empty() || all_of(input.begin(), input.end(), [](char c)
                                    { return isspace(c); }))
        {
            cout << pesanKesalahan << endl;
        }
        else
        {
            break;
        }
    }
    return input;
}

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
        if (tampilSemua || produk[i].kode == kode)
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
                 << " | " << setw(17) << produk[detail[i].kodeProduk].nama
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