#include <iostream>
using namespace std;

#define MAX_USER 50
#define MAX_PERJALANAN 100

struct user {
    string username, password;
};

struct detailPerjalanan {
    long long budget;
    string tipe;
};

struct perjalanan {
    string nama, perjalanan, destinasi, tanggal, durasi, cerita;
    detailPerjalanan detail;
};

int main() {
    user daftarUser[MAX_USER];
    int jumlahUser = 0;

    perjalanan daftarPerjalanan[MAX_PERJALANAN];
    int jumlahPerjalanan = 0;

    string userLogin = "";

    daftarUser[0].username = "Mutia";
    daftarUser[0].password = "040";
    jumlahUser = 1;

    daftarPerjalanan[0].nama            = "Mutia";
    daftarPerjalanan[0].perjalanan      = "Liburan ke Bali";
    daftarPerjalanan[0].destinasi       = "Bali";
    daftarPerjalanan[0].tanggal         = "1 Januari 2025";
    daftarPerjalanan[0].durasi          = "5 hari";
    daftarPerjalanan[0].detail.budget   = 5000000;
    daftarPerjalanan[0].cerita          = "Seru banget";
    daftarPerjalanan[0].detail.tipe     = "Domestik";
    jumlahPerjalanan = 1;

    string input;
    int pilihAwal = 0;

    do {
        cout << "\n=== JURNAL PERJALANAN ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan : "; getline(cin, input);

        if (input.empty()) { cout << "Tidak boleh kosong!" << endl; continue; }
        bool angka = true;
        for (int k = 0; k < (int)input.size(); k++) if (input[k] < '0' || input[k] > '9') { angka = false; break; }
        if (!angka) { cout << "Pilihan tidak valid!" << endl; continue; }
        pilihAwal = stoi(input);
        if (pilihAwal < 1 || pilihAwal > 3) { cout << "Pilihan tidak valid!" << endl; continue; }

        if (pilihAwal == 3) { cout << "Sampai jumpa!" << endl; break; }

        if (pilihAwal == 2) {
            cout << "\n=== REGISTER ===" << endl;
            string username, password;

            while (true) {
                cout << "username : "; getline(cin, username);
                if (!username.empty()) break;
                cout << "Username tidak boleh kosong!" << endl;
            }

            while (true) {
                cout << "Password : "; getline(cin, password);
                if (!password.empty()) break;
                cout << "Password tidak boleh kosong!" << endl;
            }

            bool sudahAda = false;
            for (int i = 0; i < jumlahUser; i++) {
                if (daftarUser[i].username == username) { sudahAda = true; break; }
            }

            if (sudahAda) {
                cout << "Username sudah digunakan!" << endl;
            } else {
                daftarUser[jumlahUser].username = username;
                daftarUser[jumlahUser].password = password;
                jumlahUser++;
                cout << "Register berhasil!" << endl;
            }
        }

        if (pilihAwal == 1) {
            cout << "\n=== LOGIN ===" << endl;
            int percobaan = 0;
            bool loginBerhasil = false;

            while (percobaan < 3) {
                string username, password;
                cout << "\nPercobaan " << percobaan + 1 << "/3" << endl;
                cout << "username : "; getline(cin, username);
                cout << "password : "; getline(cin, password);

                for (int i = 0; i < jumlahUser; i++) {
                    if (daftarUser[i].username == username && daftarUser[i].password == password) {
                        userLogin = username;
                        loginBerhasil = true;
                        break;
                    }
                }

                if (loginBerhasil) {
                    cout << "Login berhasil! Selamat datang, " << userLogin << endl;
                    break;
                }

                percobaan++;
                cout << "Username atau password salah!" << endl;
            }

            if (!loginBerhasil) {
                cout << "Login gagal. Program berhenti." << endl;
                return 0;
            }

            int pilihMenu = 0;
            do {
                cout << "\n=== MENU [" << userLogin << "] ===" << endl;
                cout << "1. Lihat perjalanan yang sudah ditempuh" << endl;
                cout << "2. Catat perjalanan baru" << endl;
                cout << "3. Edit perjalanan" << endl;
                cout << "4. Hapus perjalanan" << endl;
                cout << "5. Logout" << endl;
                cout << "Pilihan : "; getline(cin, input);

                if (input.empty()) { cout << "Tidak boleh kosong!" << endl; continue; }
                bool valid = true;
                for (int k = 0; k < (int)input.size(); k++) if (input[k] < '0' || input[k] > '9') { valid = false; break; }
                if (!valid) { cout << "Pilihan tidak valid!" << endl; continue; }
                pilihMenu = stoi(input);

                if (pilihMenu == 1) {
                    cout << "\n=== SEMUA PERJALANAN ===" << endl;
                    if (jumlahPerjalanan == 0) {
                        cout << "Belum ada perjalanan apapun." << endl;
                    } else {
                        for (int i = 0; i < jumlahPerjalanan; i++) {
                            cout << i + 1 << ". [" << daftarPerjalanan[i].nama << "] "
                                 << daftarPerjalanan[i].perjalanan
                                 << " - " << daftarPerjalanan[i].destinasi
                                 << " (" << daftarPerjalanan[i].detail.tipe << ")"
                                 << " - " << daftarPerjalanan[i].tanggal
                                 << " - " << daftarPerjalanan[i].durasi
                                 << " - Rp " << daftarPerjalanan[i].detail.budget << endl;
                            cout << "   Cerita: " << daftarPerjalanan[i].cerita << endl;
                        }
                    }
                }

                else if (pilihMenu == 2) {
                    cout << "\n=== CATAT PERJALANAN BARU ===" << endl;
                    cout << "(Tekan Enter kosong = Kembali ke menu)" << endl;
                    perjalanan p;
                    p.nama = userLogin;
                    bool batal = false;

                    cout << "Nama Perjalanan      : "; getline(cin, input);
                    if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; }
                    else p.perjalanan = input;

                    if (!batal) {
                        cout << "Destinasi            : "; getline(cin, input);
                        if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; }
                        else p.destinasi = input;
                    }
                    if (!batal) {
                        cout << "Tanggal Pergi        : "; getline(cin, input);
                        if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; }
                        else p.tanggal = input;
                    }
                    if (!batal) {
                        cout << "Berapa Lama          : "; getline(cin, input);
                        if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; }
                        else p.durasi = input;
                    }
                    if (!batal) {
                        while (true) {
                            cout << "Budget               : "; getline(cin, input);
                            if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; break; }
                            bool vld = true;
                            if (input.size() > 15) vld = false;
                            for (int k = 0; k < (int)input.size(); k++) if (input[k] < '0' || input[k] > '9') { vld = false; break; }
                            if (!vld) { cout << "Pilihan tidak valid!" << endl; continue; }
                            p.detail.budget = stoll(input); break;
                        }
                    }
                    if (!batal) {
                        cout << "Cerita / Experience  : "; getline(cin, p.cerita);
                    }
                    if (!batal) {
                        int tipe = 0;
                        while (tipe != 1 && tipe != 2) {
                            cout << "Tipe Perjalanan      :" << endl;
                            cout << "  1. Domestik" << endl;
                            cout << "  2. Internasional" << endl;
                            cout << "Pilih (1/2)          : "; getline(cin, input);
                            if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; break; }
                            if (input == "1") tipe = 1;
                            else if (input == "2") tipe = 2;
                            else cout << "Pilihan tidak valid!" << endl;
                        }
                        if (!batal) {
                            p.detail.tipe = (tipe == 2) ? "Internasional" : "Domestik";
                            daftarPerjalanan[jumlahPerjalanan++] = p;
                            cout << "Perjalanan berhasil dicatat!" << endl;
                        }
                    }
                }

                else if (pilihMenu == 3) {
                    cout << "\n=== EDIT PERJALANAN ===" << endl;
                    cout << "(Enter kosong = kembali ke menu)" << endl;

                    int indeks[MAX_PERJALANAN];
                    int count = 0;
                    for (int i = 0; i < jumlahPerjalanan; i++) {
                        if (daftarPerjalanan[i].nama == userLogin) {
                            indeks[count++] = i;
                            cout << count << ". " << daftarPerjalanan[i].perjalanan
                                 << " - " << daftarPerjalanan[i].destinasi
                                 << " (" << daftarPerjalanan[i].detail.tipe << ")"
                                 << " - " << daftarPerjalanan[i].tanggal << endl;
                        }
                    }

                    if (count == 0) {
                        cout << "Kamu belum punya perjalanan." << endl;
                    } else {
                        int no = 0;
                        bool batal = false;
                        while (no < 1 || no > count) {
                            cout << "\nPilih nomor yang diedit : "; getline(cin, input);
                            if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; break; }
                            bool vld = true;
                            for (int k = 0; k < (int)input.size(); k++) if (input[k] < '0' || input[k] > '9') { vld = false; break; }
                            if (!vld) { cout << "Pilihan tidak valid!" << endl; continue; }
                            no = stoi(input);
                            if (no < 1 || no > count) { cout << "Pilihan tidak valid!" << endl; no = 0; }
                        }

                        if (!batal) {
                            int i = indeks[no - 1];

                            cout << "(Enter kosong = tidak diubah )" << endl;
                            cout << "Nama baru      [" << daftarPerjalanan[i].perjalanan << "]: ";
                            getline(cin, input);
                            if (!input.empty()) daftarPerjalanan[i].perjalanan = input;

                            cout << "Destinasi baru [" << daftarPerjalanan[i].destinasi << "]: ";
                            getline(cin, input);
                            if (!input.empty()) daftarPerjalanan[i].destinasi = input;

                            cout << "Tanggal baru   [" << daftarPerjalanan[i].tanggal << "]: ";
                            getline(cin, input);
                            if (!input.empty()) daftarPerjalanan[i].tanggal = input;

                            cout << "Durasi baru    [" << daftarPerjalanan[i].durasi << "]: ";
                            getline(cin, input);
                            if (!input.empty()) daftarPerjalanan[i].durasi = input;

                            while (true) {
                                cout << "Budget baru    [" << daftarPerjalanan[i].detail.budget << "]: ";
                                getline(cin, input);
                                if (input.empty()) break;
                                bool vld = true;
                                if (input.size() > 15) vld = false;
                                for (int k = 0; k < (int)input.size(); k++) if (input[k] < '0' || input[k] > '9') { vld = false; break; }
                                if (!vld) { cout << "Pilihan tidak valid!" << endl; continue; }
                                daftarPerjalanan[i].detail.budget = stoll(input); break;
                            }

                            cout << "Cerita baru    [" << daftarPerjalanan[i].cerita << "]: ";
                            getline(cin, input);
                            if (!input.empty()) daftarPerjalanan[i].cerita = input;

                            int tipe = 0;
                            while (tipe != 1 && tipe != 2 && tipe != -1) {
                                cout << "Tipe sekarang  [" << daftarPerjalanan[i].detail.tipe << "]" << endl;
                                cout << "  1. Domestik" << endl;
                                cout << "  2. Internasional" << endl;

                                cout << "Pilih (1/2)    : "; getline(cin, input);
                                if (input.empty()) { tipe = -1; break; }
                                if (input == "1") tipe = 1;
                                else if (input == "2") tipe = 2;
                                else cout << "Pilihan tidak valid!" << endl;
                            }
                            if (tipe == 1) daftarPerjalanan[i].detail.tipe = "Domestik";
                            else if (tipe == 2) daftarPerjalanan[i].detail.tipe = "Internasional";

                            cout << "Perjalanan berhasil diedit!" << endl;
                        }
                    }
                }

                else if (pilihMenu == 4) {
                    cout << "\n=== HAPUS PERJALANAN ===" << endl;

                    int indeks[MAX_PERJALANAN];
                    int count = 0;
                    for (int i = 0; i < jumlahPerjalanan; i++) {
                        if (daftarPerjalanan[i].nama == userLogin) {
                            indeks[count++] = i;
                            cout << count << ". " << daftarPerjalanan[i].perjalanan
                                 << " - " << daftarPerjalanan[i].destinasi
                                 << " (" << daftarPerjalanan[i].detail.tipe << ")"
                                 << " - " << daftarPerjalanan[i].tanggal << endl;
                        }
                    }

                    if (count == 0) {
                        cout << "Kamu belum punya perjalanan." << endl;
                    } else {
                        int no = 0;
                        bool batal = false;
                        while (no < 1 || no > count) {
                            cout << "\nPilih nomor yang dihapus : "; getline(cin, input);
                            if (input.empty()) { cout << "Kembali ke menu." << endl; batal = true; break; }
                            bool vld = true;
                            for (int k = 0; k < (int)input.size(); k++) if (input[k] < '0' || input[k] > '9') { vld = false; break; }
                            if (!vld) { cout << "Pilihan tidak valid!" << endl; continue; }
                            no = stoi(input);
                            if (no < 1 || no > count) { cout << "Pilihan tidak valid!" << endl; no = 0; }
                        }

                        if (!batal) {
                            int i = indeks[no - 1];
                            string konfirm;
                            cout << "Yakin hapus '" << daftarPerjalanan[i].perjalanan << "'? (ya/tidak): ";
                            getline(cin, konfirm);
                            if (konfirm.empty()) {
                                cout << "Kembali ke menu." << endl;
                            } else {
                                for (int k = 0; k < (int)konfirm.size(); k++) konfirm[k] = tolower(konfirm[k]);
                                if (konfirm == "ya") {
                                    for (int j = i; j < jumlahPerjalanan - 1; j++)
                                        daftarPerjalanan[j] = daftarPerjalanan[j + 1];
                                    jumlahPerjalanan--;
                                    cout << "Perjalanan berhasil dihapus!" << endl;
                                } else {
                                    cout << "Penghapusan dibatalkan." << endl;
                                }
                            }
                        }
                    }
                }

                else if (pilihMenu == 5) {
                    cout << "Logout berhasil!" << endl;
                    userLogin = "";
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }

            } while (pilihMenu != 5);
        }

    } while (pilihAwal != 3);

    return 0;
}