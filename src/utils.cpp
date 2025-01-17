#include "../include/utils.h"
using namespace std;

time_t timestamp = time(NULL);
struct tm datetime = *localtime(&timestamp);
char outputTime[50];

void membuatGaris(int panjangGaris, string simbol)
{
    string garis;
    for (int i = 0; i < panjangGaris; i++)
    {
        garis += simbol;
    }

    cout << garis << endl;
}

void tampilkanHeading(const string &judul, int panjang, char simbol)
{
    system("cls");
    membuatGaris(panjang, string(1, simbol));
    cout << setw((panjang / 2) - (judul.length() / 2)) << "" << judul << endl;
    membuatGaris(panjang, string(1, simbol));
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
