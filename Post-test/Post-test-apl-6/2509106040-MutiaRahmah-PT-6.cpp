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
void binarySearchBudget(perjalanan *perjalananArr, int *jumlah, long long *target);
void linearSearchDestinasi(perjalanan *perjalananArr, int *jumlah, string *keyword);

perjalanan daftarPerjalanan[MAX_PERJALANAN];
int jumlahPerjalanan = 0;

string userLogin = "";

void Usersaya(user userArr[], int &jumlah, perjalanan perjalananArr[], int &jumlahP) {
    userArr[0].username = "Mutia";
    userArr[0].password = "040";

    userArr[1].username = "Uci";
    userArr[1].password = "123";

    userArr[2].username = "Mio";
    userArr[2].password = "456";

    userArr[3].username = "Naura";
    userArr[3].password = "789";

    jumlah = 4;

    perjalananArr[0].nama       = "Mutia";
    perjalananArr[0].perjalanan = "Liburan ke Bali";
    perjalananArr[0].destinasi  = "Bali";
    perjalananArr[0].tanggal    = "1 Januari 2025";
    perjalananArr[0].durasi     = "5 hari";
    perjalananArr[0].budget     = 5200000;
    perjalananArr[0].cerita     = "Seru banget";
    perjalananArr[0].tipe       = "Domestik";

    perjalananArr[1].nama       = "Mio";
    perjalananArr[1].perjalanan = "Liburan ke Korea";
    perjalananArr[1].destinasi  = "Seoul";
    perjalananArr[1].tanggal    = "20 Maret 2025";
    perjalananArr[1].durasi     = "6 hari";
    perjalananArr[1].budget     = 13750000;
    perjalananArr[1].cerita     = "Seru banget";
    perjalananArr[1].tipe       = "Internasional";

    perjalananArr[2].nama       = "Naura";
    perjalananArr[2].perjalanan = "Trip ke Bali";
    perjalananArr[2].destinasi  = "Bali";
    perjalananArr[2].tanggal    = "5 Mei 2025";
    perjalananArr[2].durasi     = "3 hari";
    perjalananArr[2].budget     = 3150000;
    perjalananArr[2].cerita     = "Healing tipis-tipis";
    perjalananArr[2].tipe       = "Domestik";

    perjalananArr[3].nama       = "Uci";
    perjalananArr[3].perjalanan = "Liburan ke Malang";
    perjalananArr[3].destinasi  = "Malang";
    perjalananArr[3].tanggal    = "25 Februari 2025";
    perjalananArr[3].durasi     = "4 hari";
    perjalananArr[3].budget     = 2680000;
    perjalananArr[3].cerita     = "Udara sejuk";
    perjalananArr[3].tipe       = "Domestik";

    perjalananArr[4].nama       = "Mio";
    perjalananArr[4].perjalanan = "Trip ke Jepang";
    perjalananArr[4].destinasi  = "Tokyo";
    perjalananArr[4].tanggal    = "5 Maret 2025";
    perjalananArr[4].durasi     = "2 tahun";
    perjalananArr[4].budget     = 16200000;
    perjalananArr[4].cerita     = "Pengalaman luar biasa";
    perjalananArr[4].tipe       = "Internasional";

    perjalananArr[5].nama       = "Mutia";
    perjalananArr[5].perjalanan = "Trip ke Bandung";
    perjalananArr[5].destinasi  = "Bandung";
    perjalananArr[5].tanggal    = "15 Januari 2025";
    perjalananArr[5].durasi     = "2 bulan";
    perjalananArr[5].budget     = 1420000;
    perjalananArr[5].cerita     = "Kulineran enak";
    perjalananArr[5].tipe       = "Domestik";

    perjalananArr[6].nama       = "Naura";
    perjalananArr[6].perjalanan = "Liburan ke Lombok";
    perjalananArr[6].destinasi  = "Lombok";
    perjalananArr[6].tanggal    = "20 April 2025";
    perjalananArr[6].durasi     = "1 bulan";
    perjalananArr[6].budget     = 3820000;
    perjalananArr[6].cerita     = "Pantai indah";
    perjalananArr[6].tipe       = "Domestik";

    perjalananArr[7].nama       = "Uci";
    perjalananArr[7].perjalanan = "Jalan ke Yogyakarta";
    perjalananArr[7].destinasi  = "Yogyakarta";
    perjalananArr[7].tanggal    = "10 Februari 2025";
    perjalananArr[7].durasi     = "3 bulan";
    perjalananArr[7].budget     = 2190000;
    perjalananArr[7].cerita     = "Banyak wisata menarik";
    perjalananArr[7].tipe       = "Domestik";

    jumlahP = 8;
}

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

    perjalanan temp[MAX_PERJALANAN];
    for (int i = 0; i < jumlah; i++) {
        temp[i] = perjalananArr[i];
    }

    string input;
    int no = 0;

    cout << "\nUrutkan berdasarkan:" << endl;
    cout << "1. Destinasi (Z -> A)" << endl;
    cout << "2. Budget    (Terkecil -> Terbesar)" << endl;
    cout << "3. Durasi    (Terpendek -> Terlama)" << endl;

    while (no < 1 || no > 3) {
        cout << "Pilihan (Enter = Tidak Terurut) : ";
        getline(cin, input);

        if (input.empty()) {
            cout << "\n(Tidak Diurutkan)" << endl;
            break;
        }

        if (!isAngka(input)) {
            cout << "Pilihan tidak valid!" << endl;
            return;
        }

        no = stoi(input);

        if (no < 1 || no > 3) {
            cout << "Pilihan tidak valid!" << endl;
            no = 0;
        }
    }

    if (no == 1) {
        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                if (temp[j].destinasi < temp[j + 1].destinasi) {
                    swap(temp[j], temp[j + 1]);
                }
            }
        }
        cout << "\n(Diurutkan: Destinasi Z -> A)" << endl;

    } else if (no == 2) {
        for (int i = 0; i < jumlah - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < jumlah; j++) {
                if (temp[j].budget < temp[minIdx].budget) {
                    minIdx = j;
                }
            }
            swap(temp[i], temp[minIdx]);
        }
        cout << "\n(Diurutkan: Budget Terkecil -> Terbesar)" << endl;

    } else if (no == 3) {
        for (int i = 1; i < jumlah; i++) {
            perjalanan key = temp[i];
            int j = i - 1;

            while (j >= 0 && konversiHari(temp[j].durasi) > konversiHari(key.durasi)) {
                temp[j + 1] = temp[j];
                j--;
            }
            temp[j + 1] = key;
        }
        cout << "\n(Diurutkan: Durasi Terpendek -> Terlama)" << endl;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". [" << temp[i].nama << "] "
             << temp[i].perjalanan
             << " - " << temp[i].destinasi
             << " (" << temp[i].tipe << ")"
             << " - " << temp[i].tanggal
             << " - " << temp[i].durasi
             << " - Rp " << temp[i].budget << endl;

        cout << "   Cerita: " << temp[i].cerita << endl;
    }

    cout << "\n=== FITUR PENCARIAN ===" << endl;
    cout << "1. Cari berdasarkan Budget (Sorting Budget)" << endl;
    cout << "2. Cari berdasarkan Destinasi" << endl;
    cout << "Pilihan ( Tekan Enter kosong = Kembali ke menu ) : ";
    getline(cin, input);

    while (input != "1" && input != "2" && !input.empty()) {
        cout << "Pilihan tidak valid!" << endl;
        cout << "Pilihan ( Tekan Enter kosong = Kembali ke menu ) : ";
        getline(cin, input);}
        
    if (input.empty()) {cout << "Kembali ke menu." << endl; return;}
    
    int pilihSearch = stoi(input);

    if (pilihSearch == 1) {

        if (no != 2) {
            cout << "Gunakan sorting budget dulu untuk search ini!" << endl;
            return;
        }
        cout << "Masukkan budget: ";
        getline(cin, input);
        if (input.empty()) {cout << "Kembali ke menu." << endl; return;}

        while (!isAngka(input)){cout << "Masukkan angka!" << endl; cout << "Masukkan budget: ";
        getline(cin, input); if (input.empty()) {cout << "Kembali ke menu." << endl; return;}}

        long long target = stoll(input);
        binarySearchBudget(temp, &jumlah, &target);

    } else if (pilihSearch == 2) {

        cout << "Masukkan destinasi: ";
        getline(cin, input);
        if (input.empty()) {cout << "Kembali ke menu." << endl; return;}
        while (isAngka(input)) {cout << "Masukkan huruf!" << endl; cout << "Masukkan destinasi: ";
        getline(cin, input); if (input.empty()) {cout << "Kembali ke menu." << endl; return;}}
        
        linearSearchDestinasi(temp, &jumlah, &input);

    }
}

void tambah(string *namaUser) {
    cout << "\n=== CATAT PERJALANAN BARU ===" << endl;
    cout << "(Tekan Enter kosong = Kembali ke menu)" << endl;
    perjalanan p;
    p.nama = *namaUser;
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
        p.budget = stoll(input);
        break;
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
void binarySearchBudget(perjalanan *perjalananArr, int *jumlah, long long *target) {

    perjalanan temp[MAX_PERJALANAN];
    for (int i = 0; i < *jumlah; i++) {
        temp[i] = perjalananArr[i];
    }
    for (int i = 0; i < *jumlah - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < *jumlah; j++) {
            if (temp[j].budget < temp[minIdx].budget) {
                minIdx = j;
            }
        }
        swap(temp[i], temp[minIdx]);
    }
    int low = 0;
    int high = *jumlah - 1;
    int hasilIndeks = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (temp[mid].budget == *target) {
            hasilIndeks = mid;
            break;
        } else if (temp[mid].budget < *target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (hasilIndeks == -1) {
        cout << "Perjalanan dengan budget Rp " << *target << " tidak ditemukan." << endl;
    } else {

        cout << "\nHasil pencarian budget Rp " << *target << " :" << endl;
        bool adaHasil = false;
        for (int i = 0; i < *jumlah; i++) {
            if (temp[i].budget == *target) {
                cout << "- [" << temp[i].nama << "] "
                     << temp[i].perjalanan
                     << " - " << temp[i].destinasi
                     << " (" << temp[i].tipe << ")"
                     << " - " << temp[i].tanggal
                     << " - " << temp[i].durasi
                     << " - Rp " << temp[i].budget << endl;
                cout << "  Cerita: " << temp[i].cerita << endl;
                adaHasil = true;
            }
        }
        if (!adaHasil) {
            cout << "Perjalanan dengan budget Rp " << *target << " tidak ditemukan." << endl;
        }
    }
}

void linearSearchDestinasi(perjalanan *perjalananArr, int *jumlah, string *keyword) {

    string keyLower = *keyword;
    for (int i = 0; i < (int)keyLower.size(); i++) {
        keyLower[i] = tolower(keyLower[i]);
    }

    bool ditemukan = false;
    int urutan = 1;

    cout << "\nHasil pencarian destinasi \"" << *keyword << "\" :" << endl;
    for (int i = 0; i < *jumlah; i++) {
        string destLower = perjalananArr[i].destinasi;
        for (int j = 0; j < (int)destLower.size(); j++) {
            destLower[j] = tolower(destLower[j]);
        }
        if (destLower.find(keyLower) != string::npos) {
            cout << urutan++ << ". [" << perjalananArr[i].nama << "] "
                 << perjalananArr[i].perjalanan
                 << " - " << perjalananArr[i].destinasi
                 << " (" << perjalananArr[i].tipe << ")"
                 << " - " << perjalananArr[i].tanggal
                 << " - " << perjalananArr[i].durasi
                 << " - Rp " << perjalananArr[i].budget << endl;
            cout << "   Cerita: " << perjalananArr[i].cerita << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Perjalanan ke destinasi \"" << *keyword << "\" tidak ditemukan." << endl;
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
            case 2: tambah(&namaUser); break;
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