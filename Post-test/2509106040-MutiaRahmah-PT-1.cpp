#include <iostream>
using namespace std;

string username = "Mutia", password = "040", input_username, input_password;
int pilihan;
float meter, kilometer, centimeter;

int main() {
    cout << "====================================\n";
    cout << "      SISTEM KONVERSI KM, CM, M      \n";
    cout << "====================================\n\n";

    for (int i = 0; i < 3; i++){
        cout << "Masukkan username : ";
        cin >> input_username;
        cout << "Masukkan password : ";
        cin >> input_password;
        cout << endl;

        if (input_username == username && input_password == password){
            cout << "\n====================================\n";
            cout << "           LOGIN BERHASIL           \n";
            cout << "====================================\n\n";

            cout << "============== MENU UTAMA ==============\n";
            cout << "1. Meter      -> Kilometer & Centimeter\n";
            cout << "2. Kilometer  -> Meter & Centimeter\n";
            cout << "3. Centimeter -> Meter & Kilometer\n";
            cout << "========================================\n";
            cout << "Masukkan Pilihan (1/2/3) : ";
            cin >> pilihan;
            cout << endl;

            while (pilihan < 1 || pilihan > 3)
            {
                cout << "Pilihan tidak valid. Masukkan kembali pilihan (1/2/3) : ";
                cin >> pilihan;
            }
            
            cout << endl;

            switch (pilihan) {

                case 1:
                    cout << "Masukkan Nilai Meter : ";
                    cin >> meter;
                    kilometer = meter / 1000;
                    centimeter = meter * 100;
                    cout << "\nHasil Konversi:\n";
                    cout << "Kilometer  = " << kilometer << " Km\n";
                    cout << "Centimeter = " << centimeter << " Cm\n";
                    break;

                case 2:
                    cout << "Masukkan Nilai Kilometer : ";
                    cin >> kilometer;
                    meter = kilometer * 1000;
                    centimeter = kilometer * 100000;
                    cout << "\nHasil Konversi:\n";
                    cout << "Meter      = " << meter << " M\n";
                    cout << "Centimeter = " << centimeter << " Cm\n";
                    break;

                case 3:
                    cout << "Masukkan Nilai Centimeter : ";
                    cin >> centimeter;
                    meter = centimeter / 100;
                    kilometer = centimeter / 100000;
                    cout << "\nHasil Konversi:\n";
                    cout << "Meter     = " << meter << " M\n";
                    cout << "Kilometer = " << kilometer << " Km\n";
                    break;

            }

            cout << "\n====================================\n";
            cout << "               SELESAI                \n";
            cout << "====================================\n";
            break;
    
        } else {
            cout << "\n====================================\n";
            cout << "          LOGIN GAGAL " << i+1 << "/3\n";
            cout << "====================================\n\n";
        }
    }
}