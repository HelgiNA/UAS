#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Deklarasi fungsi
void membuatGaris(int panjangGaris, string simbol = "=");
void tampilkanHeading(const string &judul, int panjang = 52, char simbol = '=');
int getValidInput(int min = 1, int max = INT32_MAX);
string getValidString(string pesanKesalahan = "Input tidak valid. Masukkan teks yang benar.");

char outputTime[50];
#endif // UTILS_H
