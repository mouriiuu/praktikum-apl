#include <iostream>
using namespace std;

#define MAX_USER 50
#define MAX_PERJALANAN 100

struct user {
    string username, password;
};

struct perjalanan {
    string nama, perjalanan, destinasi, tanggal, durasi, cerita, tipe;
    int budget;
};

user daftarUser[MAX_USER];
int jumlahUser = 0;

perjalanan daftarPerjalanan[MAX_PERJALANAN];
int jumlahPerjalanan = 0;

string userLogin = "";

void initData() {
    daftarUser[0].username = "Mutia";
    daftarUser[0].password = "040";
    jumlahUser = 1;

    daftarPerjalanan[0].nama       = "Mutia";
    daftarPerjalanan[0].perjalanan = "Liburan ke Bali";
    daftarPerjalanan[0].destinasi  = "Bali";
    daftarPerjalanan[0].tanggal    = "1 Januari 2025";
    daftarPerjalanan[0].durasi     = "5 hari";
    daftarPerjalanan[0].budget     = 5000000;
    daftarPerjalanan[0].cerita     = "Seru banget";
    daftarPerjalanan[0].tipe       = "Domestik";
    jumlahPerjalanan = 1;
}

void doRegister() {
    cout << "\n=== REGISTER ===" << endl;
    string username, password;

    cin.ignore();
    cout << "username : "; getline(cin, username);
    cout << "Password : "; getline(cin, password);

    for (int i = 0; i < jumlahUser; i++) {
        if (daftarUser[i].username == username) {
            cout << "username sudah digunakan!" << endl;
            return;
        }
    }

    daftarUser[jumlahUser].username = username;
    daftarUser[jumlahUser].password = password;
    jumlahUser++;
    cout << "Register berhasil!" << endl;
}


bool doLogin() {
    cout << "\n=== LOGIN ===" << endl;
    int percobaan = 0;
    cin.ignore();

    while (percobaan < 3) {
        string username, password;
        cout << "\nPercobaan " << percobaan + 1 << "/3" << endl;
        cout << "username : "; getline(cin, username);
        cout << "password : "; getline(cin, password);

        for (int i = 0; i < jumlahUser; i++) {
            if (daftarUser[i].username == username && daftarUser[i].password == password) {
                userLogin = username;
                cout << "Login berhasil! Selamat datang, " << userLogin << endl;
                return true;
            }
        }

        percobaan++;
        cout << "username atau password salah!" << endl;
    }

    cout << "Login gagal. Program berhenti." << endl;
    return false;
}

void lihat() {
    cout << "\n=== SEMUA PERJALANAN ===" << endl;
    if (jumlahPerjalanan == 0) {
        cout << "Belum ada perjalanan apapun." << endl;
        return;
    }
    for (int i = 0; i < jumlahPerjalanan; i++) {
        cout << i + 1 << ". [" << daftarPerjalanan[i].nama << "] "
             << daftarPerjalanan[i].perjalanan
             << " - " << daftarPerjalanan[i].destinasi
             << " (" << daftarPerjalanan[i].tipe << ")"
             << " - " << daftarPerjalanan[i].tanggal
             << " - " << daftarPerjalanan[i].durasi
             << " - Rp " << daftarPerjalanan[i].budget << endl;
        cout << "   Cerita: " << daftarPerjalanan[i].cerita << endl;
    }
}

void tambah() {
    cout << "\n=== CATAT PERJALANAN BARU ===" << endl;
    perjalanan p;
    p.nama = userLogin;

    cin.ignore();
    cout << "Nama Perjalanan      : "; getline(cin, p.perjalanan);
    cout << "Destinasi            : "; getline(cin, p.destinasi);
    cout << "Tanggal Pergi        : "; getline(cin, p.tanggal);
    cout << "Berapa Lama          : "; getline(cin, p.durasi);

    cout << "Budget               : ";
    while (!(cin >> p.budget)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid, masukkan angka: ";
    }
    cin.ignore();

    cout << "Cerita / Experience  : "; getline(cin, p.cerita);

    int tipe = 0;
    while (tipe != 1 && tipe != 2) {
        cout << "Tipe Perjalanan      :" << endl;
        cout << "  1. Domestik" << endl;
        cout << "  2. Internasional" << endl;
        cout << "Pilih (1/2)          : ";
        if (!(cin >> tipe)) {
            cin.clear();
            cin.ignore(1000, '\n');
            tipe = 0;
        }
        if (tipe != 1 && tipe != 2) cout << "Pilihan tidak valid, coba lagi!" << endl;
    }
    cin.ignore();
    p.tipe = (tipe == 2) ? "Internasional" : "Domestik";

    daftarPerjalanan[jumlahPerjalanan++] = p;
    cout << "Perjalanan berhasil dicatat!" << endl;
}

void edit() {
    cout << "\n=== EDIT PERJALANAN ===" << endl;

    int indeks[MAX_PERJALANAN];
    int count = 0;
    for (int i = 0; i < jumlahPerjalanan; i++) {
        if (daftarPerjalanan[i].nama == userLogin) {
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

    int no = 0;
    while (no < 1 || no > count) {
        cout << "\nPilih nomor yang diedit (Enter/Pilih > 2 = tidak Dirubah) : ";
        if (!(cin >> no)) {
            cin.clear();
            cin.ignore(1000, '\n');
            no = 0;
        }
        if (no < 1 || no > count) cout << "Nomor tidak valid!" << endl;
    }

    int i = indeks[no - 1];
    cin.ignore();
    string input;

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

    cout << "Budget baru    [" << daftarPerjalanan[i].budget << "]: ";
    getline(cin, input);
    if (!input.empty()) {
        bool valid = true;
        for (int k = 0; k < (int)input.size(); k++) {
            if (input[k] < '0' || input[k] > '9') { valid = false; break; }
        }
        if (valid) daftarPerjalanan[i].budget = stoi(input);
        else cout << "Input budget tidak valid, budget tidak diubah." << endl;
    }

    cout << "Cerita baru    [" << daftarPerjalanan[i].cerita << "]: ";
    getline(cin, input);
    if (!input.empty()) daftarPerjalanan[i].cerita = input;

    cout << "Tipe sekarang  [" << daftarPerjalanan[i].tipe << "]" << endl;
    cout << "  1. Domestik" << endl;
    cout << "  2. Internasional" << endl;
    cout << "Pilih (1/2)    : ";
    getline(cin, input);
    if (input == "1") daftarPerjalanan[i].tipe = "Domestik";
    else if (input == "2") daftarPerjalanan[i].tipe = "Internasional";

    cout << "Perjalanan berhasil diedit!" << endl;
}

void hapus() {
    cout << "\n=== HAPUS PERJALANAN ===" << endl;

    int indeks[MAX_PERJALANAN];
    int count = 0;
    for (int i = 0; i < jumlahPerjalanan; i++) {
        if (daftarPerjalanan[i].nama == userLogin) {
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

    int no = 0;
    while (no < 1 || no > count) {
        cout << "\nPilih nomor yang dihapus: ";
        if (!(cin >> no)) {
            cin.clear();
            cin.ignore(1000, '\n');
            no = 0;
        }
        if (no < 1 || no > count) cout << "Nomor tidak valid!" << endl;
    }

    int i = indeks[no - 1];
    cout << "Yakin hapus '" << daftarPerjalanan[i].perjalanan << "'? (ya/tidak): ";
    string konfirm;
    cin.ignore();
    getline(cin, konfirm);

    if (konfirm == "ya" || konfirm == "Ya" || konfirm == "YA") {
        for (int j = i; j < jumlahPerjalanan - 1; j++)
            daftarPerjalanan[j] = daftarPerjalanan[j + 1];
        jumlahPerjalanan--;
        cout << "Perjalanan berhasil dihapus!" << endl;
    } else {
        cout << "Penghapusan dibatalkan." << endl;
    }
}

void menuUtama() {
    int pilih;
    do {
        cout << "\n=== MENU [" << userLogin << "] ===" << endl;
        cout << "1. Lihat perjalanan yang sudah ditempuh" << endl;
        cout << "2. Catat perjalanan baru" << endl;
        cout << "3. Edit perjalanan yang sudah ada" << endl;
        cout << "4. Hapus salah satu perjalanan" << endl;
        cout << "5. Logout" << endl;
        cout << "Pilihan: "; cin >> pilih;

        switch (pilih) {
            case 1: lihat();  break;
            case 2: tambah(); break;
            case 3: edit();   break;
            case 4: hapus();  break;
            case 5: cout << "Logout berhasil!" << endl; userLogin = ""; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 5);
}

int main() {
    initData();

    int pilih;
    do {
        cout << "\n=== JURNAL PERJALANAN ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: "; cin >> pilih;

        switch (pilih) {
            case 1:
                if (doLogin()) menuUtama();
                else return 0;
                break;
            case 2: doRegister(); break;
            case 3: cout << "Sampai jumpa!" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 3);

    return 0;
}