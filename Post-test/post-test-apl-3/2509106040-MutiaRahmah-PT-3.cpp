#include <iostream>
using namespace std;

#define MAX_USER 50
#define MAX_PERJALANAN 100

struct user {
    string username, password;
};

struct perjalanan {
    string nama, perjalanan, destinasi, tanggal, durasi, cerita, tipe;
    long long budget;
};

user daftarUser[MAX_USER];
int jumlahUser = 0;

perjalanan daftarPerjalanan[MAX_PERJALANAN];
int jumlahPerjalanan = 0;

string userLogin = "";

void Usersaya(user userArr[], int &jumlah, perjalanan perjalananArr[], int &jumlahP) {
    userArr[0].username = "Mutia";
    userArr[0].password = "040";
    jumlah = 1;

    perjalananArr[0].nama       = "Mutia";
    perjalananArr[0].perjalanan = "Liburan ke Bali";
    perjalananArr[0].destinasi  = "Bali";
    perjalananArr[0].tanggal    = "1 Januari 2025";
    perjalananArr[0].durasi     = "5 hari";
    perjalananArr[0].budget     = 5000000;
    perjalananArr[0].cerita     = "Seru banget";
    perjalananArr[0].tipe       = "Domestik";
    jumlahP = 1;
}

int isAngka(string s) {
    if (s.empty() || s.size() > 15) return 0;
    for (int k = 0; k < (int)s.size(); k++) {
        if (s[k] < '0' || s[k] > '9') return 0;
    }
    return 1;
}

void doLogin(int &loginBerhasil) {
    cout << "\n=== LOGIN ===" << endl;
    loginBerhasil = 0;

    for (int percobaan = 0; percobaan < 3; percobaan++) {
        string username, password;
        cout << "\nPercobaan " << percobaan + 1 << "/3" << endl;
        cout << "username : "; getline(cin, username);
        cout << "password : "; getline(cin, password);

        for (int i = 0; i < jumlahUser; i++) {
            if (daftarUser[i].username == username && daftarUser[i].password == password) {
                userLogin = username;
                loginBerhasil = 1;
                cout << "Login berhasil! Selamat datang, " << userLogin << endl;
                return;
            }
        }

        cout << "Username atau password salah!" << endl;
    }

    cout << "Login gagal. Program berhenti." << endl;
}

void doRegister(user userArr[], int &jumlah) {
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

    for (int i = 0; i < jumlah; i++) {
        if (userArr[i].username == username) {
            cout << "Username sudah digunakan!" << endl;
            return;
        }
    }

    userArr[jumlah].username = username;
    userArr[jumlah].password = password;
    jumlah++;
    cout << "Register berhasil!" << endl;
}

void lihat(perjalanan perjalananArr[], int jumlah) {
    cout << "\n=== SEMUA PERJALANAN ===" << endl;
    if (jumlah == 0) {
        cout << "Belum ada perjalanan apapun." << endl;
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". [" << perjalananArr[i].nama << "] "
             << perjalananArr[i].perjalanan
             << " - " << perjalananArr[i].destinasi
             << " (" << perjalananArr[i].tipe << ")"
             << " - " << perjalananArr[i].tanggal
             << " - " << perjalananArr[i].durasi
             << " - Rp " << perjalananArr[i].budget << endl;
        cout << "   Cerita: " << perjalananArr[i].cerita << endl;
    }
}

void tambah(string namaUser) {
    cout << "\n=== CATAT PERJALANAN BARU ===" << endl;
    cout << "(Tekan Enter kosong = Kembali ke menu)" << endl;
    perjalanan p;
    p.nama = namaUser;
    string input;

    cout << "Nama Perjalanan      : "; getline(cin, input);
    if (input.empty()) { cout << "Kembali ke menu." << endl; return; }
    p.perjalanan = input;

    cout << "Destinasi            : "; getline(cin, input);
    if (input.empty()) { cout << "Kembali ke menu." << endl; return; }
    p.destinasi = input;

    cout << "Tanggal Pergi        : "; getline(cin, input);
    if (input.empty()) { cout << "Kembali ke menu." << endl; return; }
    p.tanggal = input;

    cout << "Berapa Lama          : "; getline(cin, input);
    if (input.empty()) { cout << "Kembali ke menu." << endl; return; }
    p.durasi = input;

    while (true) {
        cout << "Budget               : "; getline(cin, input);
        if (input.empty()) { cout << "Kembali ke menu." << endl; return; }
        if (!isAngka(input)) { cout << "Pilihan tidak valid!" << endl; continue; }
        p.budget = stoll(input); break;
    }

    cout << "Cerita / Experience  : "; getline(cin, p.cerita);

    string inputTipe;
    int tipe = 0;
    while (tipe != 1 && tipe != 2) {
        cout << "Tipe Perjalanan      :" << endl;
        cout << "  1. Domestik" << endl;
        cout << "  2. Internasional" << endl;
        cout << "Pilih (1/2)          : "; getline(cin, inputTipe);
        if (inputTipe.empty()) { cout << "Kembali ke menu." << endl; return; }
        if (inputTipe == "1") tipe = 1;
        else if (inputTipe == "2") tipe = 2;
        else cout << "Pilihan tidak valid!" << endl;
    }
    p.tipe = (tipe == 2) ? "Internasional" : "Domestik";

    daftarPerjalanan[jumlahPerjalanan++] = p;
    cout << "Perjalanan berhasil dicatat!" << endl;
}

void edit(string namaUser) {
    cout << "\n=== EDIT PERJALANAN ===" << endl;

    int indeks[MAX_PERJALANAN];
    int count = 0;
    for (int i = 0; i < jumlahPerjalanan; i++) {
        if (daftarPerjalanan[i].nama == namaUser) {
            indeks[count++] = i;
            cout << count << ". " << daftarPerjalanan[i].perjalanan
                 << " - " << daftarPerjalanan[i].destinasi
                 << " (" << daftarPerjalanan[i].tipe << ")"
                 << " - " << daftarPerjalanan[i].tanggal << endl;
        }
    }

    if (count == 0) {
        cout << "Kamu belum punya perjalanan." << endl;
        return;
    }

    string input;
    int no = 0;
    while (no < 1 || no > count) {
        cout << "\nPilih nomor yang diedit (Tekan Enter Kosong = Kembali ke Menu) : "; getline(cin, input);
        if (input.empty()) { cout << "Kembali ke menu." << endl; return; }
        if (!isAngka(input)) { cout << "Pilihan tidak valid!" << endl; continue; }
        no = stoi(input);
        if (no < 1 || no > count) { cout << "Pilihan tidak valid!" << endl; no = 0; }
    }

    int i = indeks[no - 1];

    cout << "(Tekan Enter Kosong = Tidak diubah)" << endl;

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
        cout << "Budget baru    [" << daftarPerjalanan[i].budget << "]: ";
        getline(cin, input);
        if (input.empty()) break;
        if (!isAngka(input)) { cout << "Pilihan tidak valid!" << endl; continue; }
        daftarPerjalanan[i].budget = stoll(input); break;
    }

    cout << "Cerita baru    [" << daftarPerjalanan[i].cerita << "]: ";
    getline(cin, input);
    if (!input.empty()) daftarPerjalanan[i].cerita = input;

    int tipe = 0;
    while (tipe != 1 && tipe != 2 && tipe != -1) {
        cout << "Tipe sekarang  [" << daftarPerjalanan[i].tipe << "]" << endl;
        cout << "  1. Domestik" << endl;
        cout << "  2. Internasional" << endl;
        cout << "  Enter = tidak diubah" << endl;
        cout << "Pilih (1/2)    : "; getline(cin, input);
        if (input.empty()) { tipe = -1; break; }
        if (input == "1") tipe = 1;
        else if (input == "2") tipe = 2;
        else cout << "Pilihan tidak valid!" << endl;
    }
    if (tipe == 1) daftarPerjalanan[i].tipe = "Domestik";
    else if (tipe == 2) daftarPerjalanan[i].tipe = "Internasional";

    cout << "Perjalanan berhasil diedit!" << endl;
}

void hapus(string namaUser) {
    cout << "\n=== HAPUS PERJALANAN ===" << endl;

    int indeks[MAX_PERJALANAN];
    int count = 0;
    for (int i = 0; i < jumlahPerjalanan; i++) {
        if (daftarPerjalanan[i].nama == namaUser) {
            indeks[count++] = i;
            cout << count << ". " << daftarPerjalanan[i].perjalanan
                 << " - " << daftarPerjalanan[i].destinasi
                 << " (" << daftarPerjalanan[i].tipe << ")"
                 << " - " << daftarPerjalanan[i].tanggal << endl;
        }
    }

    if (count == 0) {
        cout << "Kamu belum punya perjalanan." << endl;
        return;
    }

    string input;
    int no = 0;
    while (no < 1 || no > count) {
        cout << "\nPilih nomor yang dihapus (Tekan Enter Kosong = Kembali ke Menu) : "; getline(cin, input);
        if (input.empty()) { cout << "Kembali ke menu." << endl; return; }
        if (!isAngka(input)) { cout << "Pilihan tidak valid!" << endl; continue; }
        no = stoi(input);
        if (no < 1 || no > count) { cout << "Pilihan tidak valid!" << endl; no = 0; }
    }

    int i = indeks[no - 1];
    string konfirm;
    cout << "Yakin hapus '" << daftarPerjalanan[i].perjalanan << "'? (ya/tidak): ";
    getline(cin, konfirm);
    if (konfirm.empty()) { cout << "Kembali ke menu." << endl; return; }

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

void menuUtama(string &namaUser) {
    string input;
    int pilih = 0;
    do {
        cout << "\n=== MENU [" << namaUser << "] ===" << endl;
        cout << "1. Lihat perjalanan yang sudah ditempuh" << endl;
        cout << "2. Catat perjalanan baru" << endl;
        cout << "3. Edit perjalanan yang sudah ada" << endl;
        cout << "4. Hapus salah satu perjalanan" << endl;
        cout << "5. Logout" << endl;
        cout << "Pilihan : "; getline(cin, input);

        if (input.empty()) { cout << "Tidak boleh kosong!" << endl; continue; }
        if (!isAngka(input)) { cout << "Pilihan tidak valid!" << endl; continue; }
        pilih = stoi(input);
        if (pilih < 1 || pilih > 5) { cout << "Pilihan tidak valid!" << endl; pilih = 0; continue; }

        switch (pilih) {
            case 1: lihat(daftarPerjalanan, jumlahPerjalanan); break;
            case 2: tambah(namaUser); break;
            case 3: edit(namaUser);   break;
            case 4: hapus(namaUser);  break;
            case 5: cout << "Logout berhasil!" << endl; namaUser = ""; break;
        }
    } while (pilih != 5);
}

int main() {
    Usersaya(daftarUser, jumlahUser, daftarPerjalanan, jumlahPerjalanan);

    string input;
    int pilih = 0;
    do {
        cout << "\n=== JURNAL PERJALANAN ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan : "; getline(cin, input);

        if (input.empty()) { cout << "Tidak boleh kosong!" << endl; continue; }
        if (!isAngka(input)) { cout << "Pilihan tidak valid!" << endl; continue; }
        pilih = stoi(input);
        if (pilih < 1 || pilih > 3) { cout << "Pilihan tidak valid!" << endl; pilih = 0; continue; }

        switch (pilih) {
            case 1: {
                int status = 0;
                doLogin(status);
                if (status == 1) menuUtama(userLogin);
                else return 0;
                break;
            }
            case 2: doRegister(daftarUser, jumlahUser); break;
            case 3: cout << "Sampai jumpa!" << endl; break;
        }
    } while (pilih != 3);

    return 0;
}