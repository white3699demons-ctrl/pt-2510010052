#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int jumlah_mahasiswa = 0;

    cout << "=== SiNilai v0.4 ===\n";
    do {
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        cin >> jumlah_mahasiswa;
    } while (jumlah_mahasiswa < 1);

    double total_nilai = 0.0;
    int jumlah_lulus = 0;

    cout << fixed << setprecision(3);

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        double tugas = 0.0;
        double kuis = 0.0;
        double uts = 0.0;
        double uas = 0.0;
        double nilai_akhir = 0.0;
        string huruf = "E";
        bool lulus = false;

        cout << "\nMahasiswa ke-" << i << "\n";
        cout << "Nama: ";
        getline(cin >> ws, nama);
        cout << "Nilai tugas: ";
        cin >> tugas;
        cout << "Nilai kuis: ";
        cin >> kuis;
        cout << "Nilai UTS: ";
        cin >> uts;
        cout << "Nilai UAS: ";
        cin >> uas;

        // Bobot SiNilai: tugas 10%, kuis 45%, UTS 25%, UAS 20%.
        nilai_akhir = tugas * 0.10 + kuis * 0.45 + uts * 0.25 + uas * 0.20;

        if (nilai_akhir >= 80.0) {
            huruf = "A";
        } else if (nilai_akhir >= 70.0) {
            huruf = "B";
        } else if (nilai_akhir >= 65.0) {
            huruf = "C+";
        } else {
            huruf = "D";
        }

        lulus = nilai_akhir >= 60.0;
        cout << "\n=== Kartu Nilai ===\n";
        cout << "Nama        : " << nama << "\n";
        cout << "Nilai akhir : " << setprecision(3) << nilai_akhir << "\n";
        cout << "Huruf       : " << huruf << "\n";
        cout << "Status      : " << (lulus ? "Lulus" : "Belum lulus") << "\n";

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }
    }

    cout << "\n=== Rekap Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << setprecision(3)
         << total_nilai / jumlah_mahasiswa << "\n";

    return 0;
}
