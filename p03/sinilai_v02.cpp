// SiNilai v0.2: menghitung nilai akhir satu mahasiswa.
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Konstanta bobot sesuai formula mata kuliah.
    constexpr double BOBOT_KEHADIRAN = 0.10;
    constexpr double BOBOT_MINGGUAN = 0.45;
    constexpr double BOBOT_UTS = 0.25;
    constexpr double BOBOT_UAS = 0.20;

    string nama;
    string npm;
    double kehadiran = 0.0;
    double mingguan = 0.0;
    double uts = 0.0;
    double uas = 0.0;

    cout << "=== SiNilai v0.2 ===\n";
    cout << "Nama      : ";
    getline(cin, nama);
    cout << "NPM       : ";
    cin >> npm;
    cout << "Kehadiran : ";
    cin >> kehadiran;
    cout << "Mingguan  : ";
    cin >> mingguan;
    cout << "UTS       : ";
    cin >> uts;
    cout << "UAS       : ";
    cin >> uas;

    const double nilai_akhir =
        kehadiran * BOBOT_KEHADIRAN +
        mingguan * BOBOT_MINGGUAN +
        uts * BOBOT_UTS +
        uas * BOBOT_UAS;

    const double rerata_polos =
        (kehadiran + mingguan + uts + uas) / 4.0;

    cout << "\n--- Kartu Nilai Mahasiswa ---\n";
    cout << "Nama        : " << nama << "\n";
    cout << "NPM         : " << npm << "\n";
    cout << "Nilai akhir : " << nilai_akhir << "\n";
    cout << "Rerata polos: " << rerata_polos << "\n";

    return 0;
}
