#include <iostream>
using namespace std;

void gerak(int &x, int &y, int &baterai) {
    if (baterai <= 0) {
        cout << "Baterai habis! Robot tidak bisa bergerak." << endl;
        return;
    }

    string arah;
    cout << "Arah (kanan/kiri/atas/bawah) : "; getline(cin, arah);

    if (arah == "kanan")      x++;
    else if (arah == "kiri")  x--;
    else if (arah == "atas")  y++;
    else if (arah == "bawah") y--;
    else { cout << "Arah tidak valid!" << endl; return; }

    baterai -= 10;
    cout << "Posisi : (" << x << ", " << y << ") | Baterai : " << baterai << "%" << endl;
}

int main() {
    int x = 0, y = 0, baterai = 100;

    cout << "=== SIMULASI ROBOT ===" << endl;
    cout << "Posisi awal : (0, 0) | Baterai: 100%" << endl;

    string input;
    int pilih = 0;

    do {
        cout << "\n1. Gerakkan robot" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilihan : "; getline(cin, input);

        if (input == "1") gerak(x, y, baterai);
        else if (input == "2") cout << "Simulasi selesai." << endl;
        else cout << "Pilihan tidak valid!" << endl;

        if (!input.empty() && input[0] >= '0' && input[0] <= '9') pilih = stoi(input);

    } while (pilih != 2);

    return 0;
}