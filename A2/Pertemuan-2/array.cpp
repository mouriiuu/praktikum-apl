#include <iostream>
using namespace std;

// int main() {
//   string buah[5] = {"Jeruk", "Mangga", "Nanas", "Apel"};

//   buah[4] = "Rambutan";
//   for (string x : buah) {
//     cout << x << endl;
//   }

    // int panjang = 0; 
    // string mahasiswa[MAX_MAHASISWA];

    // int pilihan, index;
    //     do {
    //     cout << "\n = MENU PROGRAM DATA MAHASISWA =" << endl;
    //     cout << "1. Tampilkan Mahasiswa" << endl;
    //     cout << "2. Tambah Mahasiswa" << endl;
    //     cout << "3. Ubah Mahasiswa" << endl;
    //     cout << "4. Hapus Mahasiswa" << endl;
    //     cout << "5. Keluar" << endl;
    //     cout << "Pilihan: ";
    //     cin >> pilihan;
    //     switch (pilihan) {
    //         case 1: 
    //         break;
    //         case 2: 
    //         break;
    //         case 3: 
    //         break;
    //         case 4:
    //         break;
    //         case 5:
    //         cout << "Program selesai." << endl;
    //         break;
    //         default:
    //         cout << "Pilihan tidak valid." << endl;
    //         }
    //         } while (pilihan != 5);
    //     return 0;

    // int matriks[3][3] = {

    // {1, 2, 3}, 
    // {4, 5, 6}, 
    // {7, 8, 9} 

    // };
    
    // cout << matriks[0][1] << endl;
    // cout << matriks[2][0] << endl;
    
    // for (int i = 0; i << 3; i++) { 
    //     for (int j = 0; j << 3; j++) { 
    //         cout << matriks[i][j] << " ";
    // }
    // cout << endl;
    // }
    // for (auto &baris : matriks) { 
    // for (auto &elemen : baris) { 
    // cout << elemen << " ";
    // }
    // cout << endl;
    // }
    // return 0;

//     int nilai[2][2][2] = {
//     { {80, 85}, {75, 90} },
//     { {88, 92}, {70, 78} }
// };
//         cout << " = DATA NILAI MAHASISWA =\n\n";
//         for (int k = 0; k << 2; k++) {
//             cout << "Kelas " << char('A' + k) << endl;
//             for (int m = 0; m << 2; m++) {
//                 cout << " Mahasiswa " << m + 1 << endl;
//                 cout << " UTS : " << nilai[k][m][0] << endl;
//                 cout << " UAS : " << nilai[k][m][1] << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// struct Alamat {
//     string jalan;
//     string kota;
//     string provinsi;
// };

// struct Mahasiswa {
//     int nim;
//     string nama;
//     float nilai;
//     Alamat alamat;
// };




// int main() { 

    // Mahasiswa mhs;
    // mhs.alamat.jalan = "Jl. Merdeka No. 123";
    // mhs.alamat.kota = "Bandung";
    // mhs.nim = 2501234;
    // mhs.nama = "Bintang";
    // mhs.nilai = 88.5;

    // cout << "NIM   : " << mhs.nim << endl;
    // cout << "Nama  : " << mhs.nama << endl;
    // cout << "Nilai : " << mhs.nilai << endl;

    // cin >> mhs.nilai;
    // cout << "Nilai : " << mhs.nilai << endl;

    // return 0;

struct date {
    int month;
    int day;
    int year;
};
struct mahasiswa{
    string name;
    struct date birthday;
};

int main() {
    struct mahasiswa mhs[10];
        mhs[0].name = "Ihsan";
        mhs[0].birthday.day = 30;
        mhs[0].birthday.month = 1;
        mhs[0].birthday.year = 2007;

        mhs[1].name = "Bintang";
        mhs[1].birthday.day = 15;
        mhs[1].birthday.month = 5;
        mhs[1].birthday.year = 2006;

        mhs[2].name = "Dewi";
        mhs[2].birthday.day = 10;
        mhs[2].birthday.month = 8;
        mhs[2].birthday.year = 2005;

        cout << "Nama          : " << mhs[0].name << endl;
        cout << "Tanggal Lahir : " << mhs[0].birthday.day << "/" << mhs[0].birthday.month << "/" << mhs[0].birthday.year << endl;

        cout << "Nama          : " << mhs[1].name << endl;
        cout << "Tanggal Lahir : " << mhs[1].birthday.day << "/" << mhs[1].birthday.month << "/" << mhs[1].birthday.year << endl;

}
