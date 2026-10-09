#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Bobot harus sama dengan konstanta pada sinilai_v02.cpp (P03).
constexpr double BOBOT_KEHADIRAN = 0.15;
constexpr double BOBOT_MINGGUAN = 0.25;
constexpr double BOBOT_UTS = 0.25;
constexpr double BOBOT_UAS = 0.35;

int main() {
    string nama;
    string npm;
    double kehadiran = 0.0;
    double mingguan = 0.0;
    double uts = 0.0;
    double uas = 0.0;

    cout << "Nama mahasiswa : ";
    getline(cin, nama);
    cout << "NPM            : ";
    getline(cin, npm);
    cout << "Nilai kehadiran: ";
    cin >> kehadiran;
    cout << "Nilai mingguan : ";
    cin >> mingguan;
    cout << "Nilai UTS      : ";
    cin >> uts;
    cout << "Nilai UAS      : ";
    cin >> uas;

    const double nilai_akhir =
        kehadiran * BOBOT_KEHADIRAN +
        mingguan * BOBOT_MINGGUAN +
        uts * BOBOT_UTS +
        uas * BOBOT_UAS;

    string huruf_mutu;
    if (nilai_akhir >= 80.0) {
        huruf_mutu = "A";
    } else if (nilai_akhir >= 75.0) {
        huruf_mutu = "B+";
    } else if (nilai_akhir >= 70.0) {
        huruf_mutu = "B";
    } else if (nilai_akhir >= 65.0) {
        huruf_mutu = "C+";
    } else if (nilai_akhir >= 60.0) {
        huruf_mutu = "C";
    } else if (nilai_akhir >= 40.0) {
        huruf_mutu = "D";
    } else {
        huruf_mutu = "E";
    }

    const bool lulus = nilai_akhir >= 60.0;

    string keterangan;
    switch (huruf_mutu[0]) {
        case 'A':
            keterangan = "Sangat baik";
            break;
        case 'B':
            keterangan = "Baik";
            break;
        case 'C':
            keterangan = "Cukup";
            break;
        case 'D':
            keterangan = "Kurang";
            break;
        case 'E':
            keterangan = "Sangat kurang";
            break;
        default:
            keterangan = "Tidak diketahui";
            break;
    }

    cout << fixed << setprecision(3);
    cout << "\n--- Kartu Nilai Mahasiswa ---\n";
    cout << left << setw(14) << "Nama" << ": " << nama << '\n';
    cout << left << setw(14) << "NPM" << ": " << npm << '\n';
    cout << left << setw(14) << "Nilai akhir" << ": " << nilai_akhir << '\n';
    cout << left << setw(14) << "Huruf mutu" << ": " << huruf_mutu << '\n';
    cout << left << setw(14) << "Keterangan" << ": " << keterangan << '\n';
    cout << left << setw(14) << "Status" << ": ";
    if (lulus) {
        cout << "Lulus\n";
    } else {
        cout << "Belum lulus\n";
    }

    return 0;
}
