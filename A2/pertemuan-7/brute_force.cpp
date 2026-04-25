// #include <iostream>
// #include <cmath>
// #include <limits>
// #include <vector>
// using namespace std;

// struct Point
// {
//     double x, y;
// };

// double hitungJarak(Point p1, Point p2)
// {
//     return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
// }

// void cariPasanganTerdekat(vector<Point> &points)
// {

//     int n = points.size();
//     if (n < 2)
//     {
//         cout << "Minimal harus ada 2 titik." << endl;
//         return;
//     }
//     double minJarak = numeric_limits<double>::max();
//     Point pA, pB;
//     for (int i = 0; i < n; +i)
//     {
//         for (int j = i + 1; j < n; +j)
//         {
//             double jarak = hitungJarak(points[i], points[j]);
//             if (jarak < minJarak)
//             {
//                 minJarak = jarak;
//                 pA = points[i];
//                 pB = points[j];
//             }
//         }
//     }
//     cout << "Pasangan titik terdekat ditemukan:" << endl;
//     cout << "Titik 1: (" << pA.x << ", " << pA.y << ")" << endl;
//     cout << "Titik 2: (" << pB.x << ", " << pB.y << ")" << endl;
//     cout << "Jarak : " << minJarak << endl;
// }

// int main()
// {

//     vector<Point> points = {
//         {2, 3},
//         {12, 30},
//         {40, 50},
//         {5, 1},
//         {12, 10},
//         {3, 4}};

//     cout << "Menghitung pasangan titik terdekat ." << endl
//          << endl;
//     cariPasanganTerdekat(points);
//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;
struct Barang
{
    int id;
    float berat;
    float nilai;
    float rasio;
};
bool bandingkanBarang(Barang a, Barang b)
{
    return a.rasio > b.rasio;
}

int main(){
    Barang items[] = {
        {1, 10, 60, 0}, 
        {2, 20, 100, 0}
    };
    int n = 2;
    float kapasitas = 15;
    float totalNilai = 0;
    for (int i = 0; i < n; i++){
        items[i].rasio = items[i].nilai / items[i].berat;
    }
    sort(items, items + n, bandingkanBarang);
    cout << " = FRACTIONAL KNAPSACK (GREEDY) =" << endl;
    cout << "Kapasitas Tas: " << kapasitas << "kg\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        if (kapasitas == 0)
            break;
        if (items[i].berat <= kapasitas)
        {
            cout << "Ambil Barang " << items[i].id << " utuh (" <<

                items[i].berat << " kg)" << endl;

            totalNilai += items[i].nilai;
            kapasitas -= items[i].berat;
        }
        else
        {
            float bagian = kapasitas / items[i].berat;
            cout << "Ambil Barang " << items[i].id << " sebagian ("
                 << kapasitas << " kg dari " << items[i].berat << " kg)" << endl;

            totalNilai += items[i].nilai * bagian;
            kapasitas = 0;
        }
    }
    cout << "\nTotal Nilai Maksimum: " << totalNilai << endl;
    cout << "Sisa Kapasitas Tas: " << kapasitas << " kg" << endl;
    return 0;
}