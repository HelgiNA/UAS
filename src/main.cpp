#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "../include/utils.h"
#include "../include/produk.h"
#include "../include/transaksi.h"
using namespace std;

// Struktur untuk menyimpan data transaksi

void tampilkanTabelTransaksi(int idTransaksi);
void hitungTotalTransaksi(Transaksi &transaksi);

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
        membuatGaris(54);
        cout << "Masukan Pilihan Anda : ";

        pilihan = getValidInput(1, 6);

        switch (pilihan)
        {
        case 1:
            ProdukManager::tambahProduk();
            break;
        case 2:
            ProdukManager::tampilkanProduk();
            break;
        case 3:
            ProdukManager::editProduk();
            break;
        case 4:
            ProdukManager::hapusProduk();
            break;
        case 5:
            ProdukManager::cariProduk();
            break;
        case 6:
            cout << "Keluar dari menu pengelolaan produk" << endl;
            break;
        }

        system("pause");
    } while (pilihan != 6);
}

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
            TransaksiManager::tambahTransaksi();
            break;
        case 2:
            // tampilkanTransaksi();
            break;
        case 3:
            // cetakStrukPenjualan();
            break;
        case 4:
            cout << "keluar dari menu transaksi penjualan" << endl;
            break;
        }
        system("pause");
    } while (pilihan != 4);
}

//

// // Fungsi untuk menampilkan daftar traksaksi
// void tampilkanDetailTransaksi(int id);
// void tampilkanTransaksi()
// {
//     system("cls");
//     int idTransaksi;
//     tampilkanHeading("DAFTAR TRANSAKSI", 54);
//     cout << "|  Tanggal  | Nomor Transaksi | Total Transaksi | Metode |" << endl;
//     for (int i = 1; i < jumlahTransaksi; i++)
//     {
//         cout << "| " << setw(9) << transaksi[i].tanggalTransaksi
//              << " | " << setw(15) << transaksi[i].idTransaksi
//              << " | " << setw(15) << transaksi[i].subTotal
//              << " | " << "Tunai" << endl;
//     }
//     membuatGaris(54);
//     cout << "Masukan Nomor Transaksi Untuk Detail : ";
//     idTransaksi = getValidInput();

//     if (transaksi[idTransaksi].idTransaksi != 0)
//     {
//         tampilkanDetailTransaksi(idTransaksi);
//     }
//     else
//     {
//         cout << "Transaksi Dengan Kode " << idTransaksi << " Tidak di Temukan!" << endl;
//     }
// }

// void tampilkanDetailTransaksi(int idTransaksi)
// {
//     system("cls");

//     tampilkanHeading("DETAIL TRANSAKSI", 54);
//     cout << "Nomor Transaksi : " << transaksi[idTransaksi].idTransaksi << endl;
//     cout << "Tanggal/Waktu   : " << transaksi[idTransaksi].tanggalTransaksi << endl;
//     cout << "======================================================" << endl;
//     cout << "|                 Produk Yang di Beli                |" << endl;
//     tampilkanTabelTransaksi(idTransaksi);
//     cout << "| " << setw(35) << "SubTotal | " << setw(15) << transaksi[idTransaksi].subTotal << " | " << endl;
//     cout << "| " << setw(35) << "Pajak (10%) | " << setw(15) << transaksi[idTransaksi].pajak << " | " << endl;
//     cout << "| " << setw(35) << "Total | " << setw(15) << transaksi[idTransaksi].total << " | " << endl;
//     cout << "------------------------------------------------------" << endl;
//     cout << "Metode          : Tunai" << endl;
//     cout << "Kasir           : Hans" << endl;
//     cout << "======================================================" << endl;
// }

// void cetakStrukPenjualan()
// {
//     system("cls");

//     tampilkanHeading("CETAK STRUK PENJUALAN");
//     cout << "Masukkan Nomor Transaksi: ";
//     int idTransaksi = getValidInput();

//     // Periksa apakah transaksi ada
//     if (transaksi[idTransaksi].idTransaksi != 0)
//     {
//         system("cls");
//         tampilkanHeading("STRUK TRANSAKSI", 50);
//         cout << "Toko Retail XYZ\n";
//         cout << "Tanggal  : " << transaksi[idTransaksi].tanggalTransaksi << endl;
//         cout << "Kasir    : Hans" << endl; // Anda dapat mengganti nama kasir
//         membuatGaris(50, "-");
//         cout << "Produk" << setw(31 - sizeof("Produk")) << ""
//              << "Qty" << setw(6 - sizeof("Qty")) << ""
//              << "Harga" << setw(9 - sizeof("Harga")) << ""
//              << "Total" << endl;

//         // Ambil detail transaksi
//         for (int i = 1; i <= JumlahDetailTransaksi; i++)
//         {
//             if (detail[i].idTransaksi == idTransaksi)
//             {
//                 cout << produk[detail[i].kodeProduk].nama << setw(30 - produk[detail[i].kodeProduk].nama.length()) << ""
//                      << detail[i].kuantitas << setw(5 - to_string(detail[i].kuantitas).length()) << ""
//                      << produk[detail[i].kodeProduk].harga << setw(8 - to_string(produk[detail[i].kodeProduk].harga).length()) << ""
//                      << detail[i].subTotal << endl;
//             }
//         }

//         membuatGaris(50, "-");
//         cout << "Subtotal                     : " << transaksi[idTransaksi].subTotal << endl;
//         cout << "Pajak (10%)                  : " << transaksi[idTransaksi].pajak << endl;
//         membuatGaris(50, "-");
//         cout << "Total                        : " << transaksi[idTransaksi].total << endl;
//         cout << "Tunai                        : " << transaksi[idTransaksi].bayar << endl;
//         cout << "Kembalian                    : " << transaksi[idTransaksi].bayar - transaksi[idTransaksi].total << endl;
//         tampilkanHeading("Terima kasih telah berbelanja!", 50);
//     }
//     else
//     {
//         cout << "Transaksi dengan nomor " << idTransaksi << " tidak ditemukan!\n";
//     }
// }

// //
// void laporanHarian();
// void laporanBulanan();
// void laporanTahunan();

// void laporan()
// {
//     int pilihan;
//     do
//     {
//         system("cls");
//         tampilkanHeading("LAPORAN");
//         cout << "Pilih Menu Utama:" << endl;
//         cout << "1. Laporan Harian\n";
//         cout << "2. Laporan Bulanan\n";
//         cout << "3. Laporan Tahunan\n";
//         cout << "4. Kembali ke Menu Utama\n";
//         cout << "Masukan Pilihan Anda : ";

//         pilihan = getValidInput(1, 4);

//         switch (pilihan)
//         {
//         case 1:
//             laporanHarian();
//             break;
//         case 2:
//             laporanBulanan();
//             break;
//         case 3:
//             laporanTahunan();
//             break;
//         default:
//             cout << "Pilihan tidak valid.\n";
//             break;
//         }
//         if (pilihan != 4)
//         {
//             system("pause");
//         }
//     } while (pilihan != 4);
// }

// void laporanHarian()
// {
//     system("cls");
//     tampilkanHeading("LAPORAN HARIAN");

//     // Input tanggal (opsional)
//     string tanggal;
//     cout << "Masukkan tanggal (DD-MM-YYYY) atau tekan Enter untuk hari ini: ";
//     cin.ignore();
//     getline(cin, tanggal);

//     // Gunakan tanggal hari ini jika input kosong
//     if (tanggal.empty())
//     {
//         strftime(outputTime, 50, "%d-%m-%Y", &datetime);
//         tanggal = outputTime;
//     }

//     // Variabel untuk menyimpan data laporan
//     int totalPenjualan = 0;
//     int laporanJumlahTransaksi = 0;
//     int pendapatanProduk[100] = {0}; // Pendapatan per produk berdasarkan kode produk
//     int kuantitasProduk[100] = {0};  // Kuantitas terjual per produk

//     // Iterasi melalui transaksi untuk tanggal yang dimasukkan
//     for (int i = 1; i < jumlahTransaksi; i++)
//     {
//         if (transaksi[i].tanggalTransaksi == tanggal)
//         {
//             laporanJumlahTransaksi++;
//             totalPenjualan += transaksi[i].subTotal;
//             // Iterasi melalui detail transaksi
//             for (int j = 1; j <= JumlahDetailTransaksi; j++)
//             {
//                 if (detail[j].idTransaksi == transaksi[i].idTransaksi)
//                 {
//                     pendapatanProduk[detail[j].kodeProduk] += detail[j].subTotal;
//                     kuantitasProduk[detail[j].kodeProduk] += detail[j].kuantitas;
//                 }
//             }
//         }
//     }

//     // Tampilkan laporan
//     cout << "==================================================\n";
//     cout << "Tanggal               : " << tanggal << endl;
//     cout << "Total Penjualan       : Rp " << totalPenjualan << endl;
//     cout << "Jumlah Transaksi      : " << laporanJumlahTransaksi << endl;
//     cout << "--------------------------------------------------\n";
//     cout << "Rincian Produk Terjual:\n";
//     cout << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
//          << "QTY" << " | "
//          << "Pendapatan" << endl;
//     cout << "--------------------------------------------------\n";

//     for (int i = 1; i < jumlahProduk; i++)
//     {
//         if (pendapatanProduk[i] > 0)
//         {
//             cout << produk[i].nama << setw(32 - produk[i].nama.length()) << " | "
//                  << kuantitasProduk[i] << setw(3 - to_string(kuantitasProduk[i]).length()) << "" << " | "
//                  << "Rp " << pendapatanProduk[i] << endl;
//         }
//     }

//     cout << "--------------------------------------------------\n";
//     cout << "Laporan harian selesai ditampilkan.\n";
// }

// void laporanBulanan()
// {
//     system("cls");
//     tampilkanHeading("LAPORAN BULANAN");

//     // Input bulan (opsional)
//     string bulan;
//     cout << "Masukkan bulan (MM-YYYY) atau tekan Enter untuk bulan ini: ";
//     cin.ignore();
//     getline(cin, bulan);

//     // Gunakan bulan saat ini jika input kosong
//     if (bulan.empty())
//     {
//         strftime(outputTime, 50, "%m-%Y", &datetime);
//         bulan = outputTime;
//     }

//     // Variabel untuk menyimpan data laporan
//     int totalPenjualan = 0;
//     int laporanJumlahTransaksi = 0;
//     int pendapatanProduk[100] = {0}; // Pendapatan per produk berdasarkan kode produk
//     int kuantitasProduk[100] = {0};  // Kuantitas terjual per produk
//     int totalKuantitas = 0;          // Total kuantitas semua produk

//     // Iterasi melalui transaksi untuk bulan yang dimasukkan
//     for (int i = 1; i < jumlahTransaksi; i++)
//     {
//         // Ambil bulan transaksi (format MM-YYYY)
//         string bulanTransaksi = transaksi[i].tanggalTransaksi.substr(3, 7);
//         if (bulanTransaksi == bulan)
//         {
//             laporanJumlahTransaksi++;
//             totalPenjualan += transaksi[i].subTotal;

//             // Iterasi melalui detail transaksi
//             for (int j = 1; j <= JumlahDetailTransaksi; j++)
//             {
//                 if (detail[j].idTransaksi == transaksi[i].idTransaksi)
//                 {
//                     pendapatanProduk[detail[j].kodeProduk] += detail[j].subTotal;
//                     kuantitasProduk[detail[j].kodeProduk] += detail[j].kuantitas;
//                     totalKuantitas += detail[j].kuantitas;
//                 }
//             }
//         }
//     }

//     // Tampilkan laporan
//     cout << "==================================================\n";
//     cout << "Bulan                   : " << bulan << endl;
//     cout << "Total Penjualan         : Rp " << totalPenjualan << endl;
//     cout << "Jumlah Transaksi        : " << laporanJumlahTransaksi << endl;
//     cout << "--------------------------------------------------\n";
//     cout << "Produk Terlaris:\n";
//     cout << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
//          << "QTY" << " | "
//          << "Persentase" << endl;
//     cout << "--------------------------------------------------\n";

//     for (int i = 1; i < jumlahProduk; i++)
//     {
//         if (pendapatanProduk[i] > 0)
//         {
//             float persentase = (float(kuantitasProduk[i]) / totalKuantitas) * 100;
//             cout << produk[i].nama << setw(32 - produk[i].nama.length()) << " | "
//                  << kuantitasProduk[i] << setw(3 - to_string(kuantitasProduk[i]).length()) << "" << " | "
//                  << fixed << setprecision(1) << persentase << "%" << endl;
//         }
//     }

//     // Hitung laba/rugi (opsional)
//     int biayaOperasional = 20000000; // Contoh biaya operasional tetap
//     int labaRugi = totalPenjualan - biayaOperasional;
//     cout << "--------------------------------------------------\n";
//     cout << "Laba/Rugi            : Rp " << labaRugi << endl;
//     cout << "--------------------------------------------------\n";
//     cout << "Laporan bulanan selesai ditampilkan.\n";
// }

// void laporanTahunan()
// {
//     system("cls");
//     tampilkanHeading("LAPORAN TAHUNAN");

//     // Input tahun (opsional)
//     string tahun;
//     cout << "Masukkan tahun (YYYY) atau tekan Enter untuk tahun ini: ";
//     cin.ignore();
//     getline(cin, tahun);

//     // Gunakan tahun saat ini jika input kosong
//     if (tahun.empty())
//     {
//         strftime(outputTime, 50, "%Y", &datetime);
//         tahun = outputTime;
//     }

//     // Variabel untuk menyimpan data laporan
//     int totalPenjualan = 0;
//     int laporanJumlahTransaksi = 0;
//     int pendapatanPerBulan[12] = {0}; // Pendapatan per bulan
//     int pendapatanProduk[100] = {0};  // Pendapatan per produk berdasarkan kode produk
//     int kuantitasProduk[100] = {0};   // Kuantitas terjual per produk
//     int totalKuantitas = 0;           // Total kuantitas semua produk

//     // Iterasi melalui transaksi untuk tahun yang dimasukkan
//     for (int i = 1; i < jumlahTransaksi; i++)
//     {
//         // Ambil tahun transaksi (format YYYY)
//         string tahunTransaksi = transaksi[i].tanggalTransaksi.substr(6, 4);
//         if (tahunTransaksi == tahun)
//         {
//             laporanJumlahTransaksi++;
//             totalPenjualan += transaksi[i].subTotal;

//             // Hitung pendapatan per bulan
//             int bulanIndex = stoi(transaksi[i].tanggalTransaksi.substr(3, 2)) - 1; // Ambil bulan (0-11)
//             pendapatanPerBulan[bulanIndex] += transaksi[i].subTotal;

//             // Iterasi melalui detail transaksi
//             for (int j = 1; j <= JumlahDetailTransaksi; j++)
//             {
//                 if (detail[j].idTransaksi == transaksi[i].idTransaksi)
//                 {
//                     pendapatanProduk[detail[j].kodeProduk] += detail[j].subTotal;
//                     kuantitasProduk[detail[j].kodeProduk] += detail[j].kuantitas;
//                     totalKuantitas += detail[j].kuantitas;
//                 }
//             }
//         }
//     }

//     // Cari bulan terbaik dan terburuk
//     int bulanTerbaik = 0, bulanTerburuk = 0;
//     for (int i = 1; i < 12; i++)
//     {
//         if (pendapatanPerBulan[i] > pendapatanPerBulan[bulanTerbaik])
//             bulanTerbaik = i;
//         if (pendapatanPerBulan[i] < pendapatanPerBulan[bulanTerburuk])
//             bulanTerburuk = i;
//     }

//     // Tampilkan laporan
//     const string namaBulan[] = {
//         "Januari", "Februari", "Maret", "April", "Mei", "Juni",
//         "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

//     cout << "==================================================\n";
//     cout << "Tahun                   : " << tahun << endl;
//     cout << "Total Penjualan         : Rp " << totalPenjualan << endl;
//     cout << "Jumlah Transaksi        : " << laporanJumlahTransaksi << endl;
//     cout << "--------------------------------------------------\n";
//     cout << "Bulan Terbaik           : " << namaBulan[bulanTerbaik]
//          << " (Rp " << pendapatanPerBulan[bulanTerbaik] << ")" << endl;
//     cout << "Bulan Terburuk          : " << namaBulan[bulanTerburuk]
//          << " (Rp " << pendapatanPerBulan[bulanTerburuk] << ")" << endl;
//     cout << "--------------------------------------------------\n";
//     cout << "Produk Terlaris Sepanjang Tahun:\n";
//     cout << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
//          << "QTY" << " | "
//          << "Pendapatan" << endl;
//     cout << "--------------------------------------------------\n";

//     for (int i = 1; i < jumlahProduk; i++)
//     {
//         if (pendapatanProduk[i] > 0)
//         {
//             cout << produk[i].nama << setw(32 - produk[i].nama.length()) << " | "
//                  << kuantitasProduk[i] << setw(3 - to_string(kuantitasProduk[i]).length()) << "" << " | "
//                  << "Rp " << pendapatanProduk[i] << endl;
//         }
//     }

//     // Hitung laba/rugi (opsional)
//     int biayaOperasionalTahunan = 240000000; // Contoh biaya operasional tetap
//     int labaRugi = totalPenjualan - biayaOperasionalTahunan;
//     cout << "--------------------------------------------------\n";
//     cout << "Laba/Rugi Tahunan      : Rp " << labaRugi << endl;
//     cout << "--------------------------------------------------\n";
//     cout << "Laporan tahunan selesai ditampilkan.\n";
// }

// //
// void cekStokProduk();
// void tambahStokProduk();
// void lihatLogStok();

// void pengelolaanStok()
// {
//     int pilihan;
//     do
//     {
//         system("cls");
//         tampilkanHeading("PENGELOLAAN STOK");
//         cout << "Pilih Menu Utama:" << endl;
//         cout << "1. Cek Stok Produk\n";
//         cout << "2. Tambah Stok Baru\n";
//         cout << "3. Lihat Log Perubahan Stok\n";
//         cout << "4. Kembali ke Menu Utama\n";
//         cout << "Masukan Pilihan Anda : ";

//         pilihan = getValidInput(1, 4);

//         switch (pilihan)
//         {
//         case 1:
//             cekStokProduk();
//             break;
//         case 2:
//             tambahStokProduk();
//             break;
//         case 3:
//             lihatLogStok();
//             break;
//         default:
//             cout << "Pilihan tidak valid.\n";
//             break;
//         }
//         if (pilihan != 4)
//         {
//             system("pause");
//         }
//     } while (pilihan != 4);
// }
// //
// void cekStokProduk()
// {
//     system("cls");
//     tampilkanHeading("CEK STOK PRODUK");

//     // Input ID atau nama produk
//     cout << "Masukkan ID produk (angka): ";
//     int input = getValidInput();

//     if (cekProduk(input))
//     {
//         membuatGaris(52, "-");
//         cout << "Nama Produk    : " << produk[input].nama << endl;
//         cout << "Stok Tersedia  : " << produk[input].stok << " unit" << endl;
//         cout << "Lokasi         : Gudang A" << endl; // Lokasi default
//         membuatGaris(52, "-");
//     }
// }

// struct LogStok
// {
//     string tanggal;
//     string namaProduk;
//     int perubahan; // Positif untuk penambahan
//     string alasan; // Alasan perubahan (e.g., Restock)
// };

// LogStok logStok[200];
// int jumlahLog = 0;

// void tambahLogStok(string namaProduk, int perubahan, string alasan)
// {
//     strftime(outputTime, 50, "%d-%m-%Y", &datetime); // Mendapatkan tanggal saat ini
//     logStok[jumlahLog].tanggal = outputTime;
//     logStok[jumlahLog].namaProduk = namaProduk;
//     logStok[jumlahLog].perubahan = perubahan;
//     logStok[jumlahLog].alasan = alasan;
//     jumlahLog++;
// }

// void tambahStokProduk()
// {
//     system("cls");
//     tampilkanHeading("TAMBAH STOK BARU");

//     // Input ID atau nama produk
//     cout << "Masukkan Kode Produk: ";
//     int kode = getValidInput();
//     if (cekProduk(kode))
//     {
//         cout << "Masukkan jumlah stok yang ingin ditambahkan: ";
//         int jumlah = getValidInput();

//         // Update stok dan tampilkan informasi
//         int stokLama = produk[kode].stok;
//         produk[kode].stok += jumlah;

//         cout << "--------------------------------------------------\n";
//         cout << "Nama Produk    : " << produk[kode].nama << endl;
//         cout << "Stok Lama      : " << stokLama << " unit" << endl;
//         cout << "Stok Baru      : " << produk[kode].stok << " unit" << endl;
//         cout << "--------------------------------------------------\n";
//         cout << "Stok berhasil diperbarui!\n";

//         // Tambahkan ke log
//         tambahLogStok(produk[kode].nama, jumlah, "Restock");
//     }
// }

// void lihatLogStok()
// {
//     system("cls");
//     tampilkanHeading("LOG PERUBAHAN STOK");

//     if (jumlahLog == 0)
//     {
//         cout << "Belum ada log perubahan stok.\n";
//         return;
//     }
//     cout << "Produk" << setw(15 - sizeof("Tanggal")) << " | "
//          << "Nama Produk" << setw(33 - sizeof("Nama Produk")) << " | "
//          << "Perubahan" << setw(13 - sizeof("Perubahan")) << " | "
//          << "Alasan" << endl;

//     cout << "------------------------------------------------------\n";
//     for (int i = 0; i < jumlahLog; i++)
//     {
//         cout << logStok[i].tanggal << setw(13 - logStok[i].tanggal.length()) << " | "
//              << logStok[i].namaProduk << setw(32 - logStok[i].namaProduk.length()) << " | "
//              << logStok[i].perubahan << setw(12 - to_string(logStok[i].perubahan).length()) << " | "
//              << logStok[i].alasan << endl;
//     }
//     cout << "------------------------------------------------------\n";
// }

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
            // transaksiPenjualan();
            break;
        case 3:
            // laporan();
            break;
        case 4:
            // pengelolaanStok();
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
