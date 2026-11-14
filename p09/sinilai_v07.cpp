#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Prototipe sembilan fungsi SiNilai v0.7.
int bacaJumlah();
string bacaNama();
double bacaKomponen(string label);
void bacaData(string& nama, string& npm, double& kehadiran,
              double& mingguan, double& uts, double& uas);
double hitungNilaiAkhir(double kehadiran, double mingguan,
                        double uts, double uas);
string hurufMutu(double nilai_akhir);
void perbaruiPenghitung(char awal, int& jumlah_a, int& jumlah_b,
                        int& jumlah_c, int& jumlah_d, int& jumlah_e);
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus);
void cetakSebaran(int jumlah_a, int jumlah_b, int jumlah_c,
                  int jumlah_d, int jumlah_e);

int main() {
    cout << "=== SiNilai v0.7 ===\n";
    const int jumlah_mahasiswa = bacaJumlah();
    cout << fixed << setprecision(2);

    double total_nilai = 0.0;
    int jumlah_lulus = 0;
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;
    double nilai_tertinggi = -1.0;
    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; ++i) {
        string nama;
        string npm;
        double kehadiran = 0.0;
        double mingguan = 0.0;
        double uts = 0.0;
        double uas = 0.0;

        cout << "\n--- Mahasiswa ke-" << i << " dari "
             << jumlah_mahasiswa << " ---\n";
        bacaData(nama, npm, kehadiran, mingguan, uts, uas);

        const double nilai_akhir =
            hitungNilaiAkhir(kehadiran, mingguan, uts, uas);
        const string huruf = hurufMutu(nilai_akhir);
        const bool lulus = nilai_akhir >= 60.0;
        cetakBaris(nama, nilai_akhir, huruf, lulus);

        total_nilai += nilai_akhir;
        if (lulus) {
            ++jumlah_lulus;
        }
        perbaruiPenghitung(huruf[0], jumlah_a, jumlah_b,
                           jumlah_c, jumlah_d, jumlah_e);

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
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
    cetakSebaran(jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);

    return 0;
}

int bacaJumlah() {
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
    return jumlah_mahasiswa;
}

string bacaNama() {
    string nama;
    bool nama_sah = false;

    do {
        cout << "Nama      : ";
        getline(cin, nama);

        bool ada_huruf = false;
        bool ada_angka = false;
        const int panjang_nama = static_cast<int>(nama.length());

        for (int i = 0; i < panjang_nama; ++i) {
            const unsigned char karakter =
                static_cast<unsigned char>(nama[i]);
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
    for (int i = 0; i < panjang_nama; ++i) {
        const unsigned char karakter =
            static_cast<unsigned char>(nama[i]);
        if (isspace(karakter)) {
            awal_kata = true;
        } else if (awal_kata) {
            nama[i] = static_cast<char>(toupper(karakter));
            awal_kata = false;
        } else {
            nama[i] = static_cast<char>(tolower(karakter));
        }
    }

    return nama;
}

double bacaKomponen(string label) {
    double nilai = 0.0;

    cout << label;
    cin >> nilai;
    while (cin.fail() || nilai < 0.0 || nilai > 100.0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Harus angka 0 sampai 100. ";
        cout << label;
        cin >> nilai;
    }
    return nilai;
}

void bacaData(string& nama, string& npm, double& kehadiran,
              double& mingguan, double& uts, double& uas) {
    nama = bacaNama();

    cout << "NPM       : ";
    getline(cin, npm);

    kehadiran = bacaKomponen("Kehadiran : ");
    mingguan = bacaKomponen("Mingguan  : ");
    uts = bacaKomponen("UTS       : ");
    uas = bacaKomponen("UAS       : ");
    cin.ignore(1000, '\n');
}

double hitungNilaiAkhir(double kehadiran, double mingguan,
                        double uts, double uas) {
    const double bobot_kehadiran = 0.10;
    const double bobot_mingguan = 0.45;
    const double bobot_uts = 0.25;
    const double bobot_uas = 0.20;

    return kehadiran * bobot_kehadiran
         + mingguan * bobot_mingguan
         + uts * bobot_uts
         + uas * bobot_uas;
}

string hurufMutu(double nilai_akhir) {
    if (nilai_akhir >= 80.0) {
        return "A";
    } else if (nilai_akhir >= 75.0) {
        return "B+";
    } else if (nilai_akhir >= 70.0) {
        return "B";
    } else if (nilai_akhir >= 65.0) {
        return "C+";
    } else if (nilai_akhir >= 60.0) {
        return "C";
    } else if (nilai_akhir >= 40.0) {
        return "D";
    }
    return "E";
}

void perbaruiPenghitung(char awal, int& jumlah_a, int& jumlah_b,
                        int& jumlah_c, int& jumlah_d, int& jumlah_e) {
    switch (awal) {
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
}

void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus) {
    cout << left << setw(22) << nama
         << right << setw(10) << nilai_akhir
         << "  " << left << setw(8) << huruf
         << (lulus ? "Lulus" : "Belum lulus") << '\n';
}

void cetakSebaran(int jumlah_a, int jumlah_b, int jumlah_c,
                  int jumlah_d, int jumlah_e) {
    const int jumlah_per_huruf[] = {
        jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e
    };

    cout << "\nSebaran huruf mutu:\n";
    for (int i = 0; i < 5; ++i) {
        const char huruf = static_cast<char>('A' + i);
        const int banyak = jumlah_per_huruf[i];
        cout << huruf << " | ";
        for (int j = 1; j <= banyak; ++j) {
            cout << '#';
        }
        cout << ' ' << banyak << '\n';
    }
}
