#include <iostream>
#include <string>
using namespace std;

int main() {
    string rumahUcup = "ucup";

    cout << rumahUcup << endl;
    cout << &rumahUcup << endl;

    string nama = "Rangga Aryawinata";
    cout << &nama << " adalah alamatnya " << nama << endl;

    return 0;
}