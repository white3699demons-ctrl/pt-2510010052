// SiNilai v0.5: laporan kelas, nilai tertinggi, dan sebaran huruf mutu.
// Dibuat dengan bantuan ChatGPT untuk menyusun dan memeriksa struktur program.
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int jumlah_mahasiswa = 0;
    cout << "Jumlah mahasiswa: ";
    if (!(cin >> jumlah_mahasiswa) || jumlah_mahasiswa < 1) {
        cerr << "Jumlah mahasiswa harus minimal 1.\n";
        return 1;
    }

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

    cout << "\n--- Daftar Nilai Mahasiswa ---\n";
    cout << "  " << left << setw(20) << "Nama"
         << right << setw(7) << "Nilai" << "  "
         << left << setw(3) << "Huruf" << " Status\n";

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0.0;
        double mingguan = 0.0;
        double uts = 0.0;
        double uas = 0.0;

        getline(cin >> ws, nama);
        cin >> npm >> kehadiran >> mingguan >> uts >> uas;

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

        cout << "  " << left << setw(20) << nama
             << right << setw(7) << nilai_akhir << "  "
             << left << setw(3) << huruf_mutu
             << (lulus ? "Lulus" : "Belum lulus") << '\n';

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }

        switch (huruf_mutu[0]) {
            case 'A': jumlah_a++; break;
            case 'B': jumlah_b++; break;
            case 'C': jumlah_c++; break;
            case 'D': jumlah_d++; break;
            case 'E': jumlah_e++; break;
            default: break;
        }

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << left << setw(19) << "Jumlah mahasiswa :" << jumlah_mahasiswa << '\n';
    cout << left << setw(19) << "Lulus            :" << jumlah_lulus << '\n';
    cout << left << setw(19) << "Belum lulus      :" << jumlah_mahasiswa - jumlah_lulus << '\n';
    cout << left << setw(19) << "Rata-rata kelas :" 
         << total_nilai / jumlah_mahasiswa << '\n';
    cout << left << setw(19) << "Tertinggi        :" 
         << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        if (huruf == 'A') {
            banyak = jumlah_a;
        } else if (huruf == 'B') {
            banyak = jumlah_b;
        } else if (huruf == 'C') {
            banyak = jumlah_c;
        } else if (huruf == 'D') {
            banyak = jumlah_d;
        } else {
            banyak = jumlah_e;
        }

        cout << huruf << " | ";
        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }
        cout << " " << banyak << '\n';
    }

    return 0;
}
