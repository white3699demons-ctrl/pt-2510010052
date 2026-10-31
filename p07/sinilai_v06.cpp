#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    int jumlah_mahasiswa = 0;

    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah_mahasiswa;

    while (cin.fail() || jumlah_mahasiswa < 1) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Jumlah mahasiswa harus berupa angka. ";
        } else {
            cout << "Jumlah mahasiswa paling sedikit 1. ";
        }
        cout << "Coba lagi: ";
        cin >> jumlah_mahasiswa;
    }
    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    int jumlah_lulus = 0;
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;

    double total_nilai = 0.0;
    double nilai_tertinggi = -1.0;
    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; ++i) {
        string nama;
        string npm;
        double kehadiran = 0.0;
        double mingguan = 0.0;
        double uts = 0.0;
        double uas = 0.0;
        bool nama_sah = false;

        cout << "\n--- Mahasiswa ke-" << i << " dari "
             << jumlah_mahasiswa << " ---\n";

        do {
            cout << "Nama      : ";
            getline(cin, nama);

            bool ada_huruf = false;
            bool ada_angka = false;
            const int panjang_nama = static_cast<int>(nama.length());

            for (int k = 0; k < panjang_nama; ++k) {
                const unsigned char karakter =
                    static_cast<unsigned char>(nama[k]);

                if (!isspace(karakter)) {
                    ada_huruf = true;
                }
                if (isdigit(karakter)) {
                    ada_angka = true;
                }
            }

            if (!ada_huruf) {
                cout << "Nama tidak boleh kosong.\n";
            } else if (ada_angka) {
                cout << "Nama tidak boleh mengandung angka.\n";
            } else {
                nama_sah = true;
            }
        } while (!nama_sah);

        bool awal_kata = true;
        const int panjang_nama = static_cast<int>(nama.length());
        for (int k = 0; k < panjang_nama; ++k) {
            const unsigned char karakter =
                static_cast<unsigned char>(nama[k]);

            if (isspace(karakter)) {
                awal_kata = true;
            } else if (awal_kata) {
                nama[k] = static_cast<char>(toupper(karakter));
                awal_kata = false;
            } else {
                nama[k] = static_cast<char>(tolower(karakter));
            }
        }

        cout << "NPM       : ";
        getline(cin, npm);

        cout << "Kehadiran : ";
        cin >> kehadiran;
        while (cin.fail() || kehadiran < 0.0 || kehadiran > 100.0) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Harus angka 0 sampai 100. ";
            cout << "Kehadiran : ";
            cin >> kehadiran;
        }

        cout << "Mingguan  : ";
        cin >> mingguan;
        while (cin.fail() || mingguan < 0.0 || mingguan > 100.0) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Harus angka 0 sampai 100. ";
            cout << "Mingguan  : ";
            cin >> mingguan;
        }

        cout << "UTS       : ";
        cin >> uts;
        while (cin.fail() || uts < 0.0 || uts > 100.0) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Harus angka 0 sampai 100. ";
            cout << "UTS       : ";
            cin >> uts;
        }

        cout << "UAS       : ";
        cin >> uas;
        while (cin.fail() || uas < 0.0 || uas > 100.0) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Harus angka 0 sampai 100. ";
            cout << "UAS       : ";
            cin >> uas;
        }
        cin.ignore(1000, '\n');

        // Bobot SiNilai v0.5: kehadiran 10%, mingguan 45%,
        // UTS 25%, dan UAS 20%.
        const double nilai_akhir =
            kehadiran * 0.10 + mingguan * 0.45 + uts * 0.25 + uas * 0.20;

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
        if (lulus) {
            ++jumlah_lulus;
        }
        total_nilai += nilai_akhir;

        switch (huruf_mutu[0]) {
            case 'A':
                ++jumlah_a;
                break;
            case 'B':
                ++jumlah_b;
                break;
            case 'C':
                ++jumlah_c;
                break;
            case 'D':
                ++jumlah_d;
                break;
            case 'E':
                ++jumlah_e;
                break;
            default:
                break;
        }

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }

        cout << left << setw(22) << nama
             << right << setw(10) << nilai_akhir
             << "  " << left << setw(8) << huruf_mutu
             << (lulus ? "Lulus" : "Belum lulus") << '\n';
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << left << setw(22) << "Jumlah mahasiswa :" << jumlah_mahasiswa << '\n';
    cout << left << setw(22) << "Lulus            :" << jumlah_lulus << '\n';
    cout << left << setw(22) << "Belum lulus      :"
         << jumlah_mahasiswa - jumlah_lulus << '\n';
    cout << left << setw(22) << "Rata-rata kelas :" 
         << total_nilai / jumlah_mahasiswa << '\n';
    cout << left << setw(22) << "Tertinggi        :"
         << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; ++huruf) {
        int banyak = 0;
        if (huruf == 'A') {
            banyak = jumlah_a;
        } else if (huruf == 'B') {
            banyak = jumlah_b;
        } else if (huruf == 'C') {
            banyak = jumlah_c;
        } else if (huruf == 'D') {
            banyak = jumlah_d;
        } else if (huruf == 'E') {
            banyak = jumlah_e;
        }

        cout << huruf << " | ";
        for (int j = 1; j <= banyak; ++j) {
            cout << '#';
        }
        cout << ' ' << banyak << '\n';
    }

    return 0;
}
