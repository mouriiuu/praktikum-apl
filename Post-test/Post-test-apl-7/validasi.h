#ifndef VALIDASI_H
#define VALIDASI_H

#include <string>
#include <stdexcept>
using namespace std;

int isAngka(string s) {
    if (s.empty() || s.size() > 15) return 0;
    for (int k = 0; k < (int)s.size(); k++) {
        if (s[k] < '0' || s[k] > '9') return 0;
    }
    return 1;
}

int konversiHari(string s) {
    string angka = "";
    int i = 0;
    while (i < (int)s.size() && s[i] == ' ') i++;
    while (i < (int)s.size() && s[i] >= '0' && s[i] <= '9') {
        angka += s[i];
        i++;
    }
    if (angka.empty()) return 0;
    int nilai = stoi(angka);

    string satuan = "";
    while (i < (int)s.size()) {
        if (s[i] != ' ') satuan += (char)tolower(s[i]);
        i++;
    }

    if (satuan == "tahun")      return nilai * 365;
    else if (satuan == "bulan") return nilai * 30;
    else                        return nilai;
}

long long validasiBudget(const string& input) {
    if (input.empty())
        throw invalid_argument("Budget tidak boleh kosong!");
    if (!isAngka(input))
        throw invalid_argument("Budget harus berupa angka! Contoh: 5000000");
    long long val = stoll(input);
    if (val <= 0)
        throw out_of_range("Budget harus lebih dari 0!");
    return val;
}

string validasiTeks(const string& input, const string& namaField) {
    if (input.empty())
        throw invalid_argument(namaField + " tidak boleh kosong!");
    return input;
}

#endif