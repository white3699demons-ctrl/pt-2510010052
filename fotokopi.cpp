// UTS Praktikum Paket B: Fotokopi Kampus
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int HARGA_KECIL = 300;
    const int HARGA_SEDANG = 250;
    const int HARGA_BESAR = 200;
    const int BATAS_KECIL = 50;
    const int BATAS_SEDANG = 200;
    const int MAKS_HALAMAN = 1000;

    int jumlah = 0;
    cout << "=== Fotokopi Kampus ===\n";
    cout << "Jumlah pesanan: ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1) {
        if (cin.eof()) return 0;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Jumlah pesanan: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    int total_halaman = 0;
    int total_pendapatan = 0;
    int banyak_kecil = 0;
    int banyak_sedang = 0;
    int banyak_besar = 0;
    int biaya_terbesar = -1;
    string nama_terbesar;

    for (int i = 1; i <= jumlah; i++) {
        string nama;
        int halaman = 0;
        char warna = ' ';

        cout << "\n--- Pesanan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1: baca nama sampai sah, lalu rapikan menjadi Huruf Besar Di Awal Kata.
        bool nama_sah = false;
        do {
            cout << "Nama pemesan : ";
            if (!getline(cin, nama)) return 0;

            bool kosong = true;
            bool ada_angka = false;
            for (char karakter : nama) {
                unsigned char c = static_cast<unsigned char>(karakter);
                if (!isspace(c)) kosong = false;
                if (isdigit(c)) ada_angka = true;
            }

            if (kosong) {
                cout << "Nama tidak boleh kosong.\n";
            } else if (ada_angka) {
                cout << "Nama tidak boleh mengandung angka.\n";
            } else {
                nama_sah = true;
            }
        } while (!nama_sah);

        string nama_rapi;
        bool awal_kata = true;
        bool spasi_pending = false;
        for (char karakter : nama) {
            unsigned char c = static_cast<unsigned char>(karakter);
            if (isspace(c)) {
                if (!nama_rapi.empty()) {
                    spasi_pending = true;
                    awal_kata = true;
                }
            } else {
                if (spasi_pending) {
                    nama_rapi += ' ';
                    spasi_pending = false;
                }
                if (awal_kata) {
                    nama_rapi += static_cast<char>(toupper(c));
                    awal_kata = false;
                } else {
                    nama_rapi += static_cast<char>(tolower(c));
                }
            }
        }
        nama = nama_rapi;

        // TODO 2: baca halaman dengan aman, pada rentang 1 sampai 1000.
        cout << "Halaman (1-" << MAKS_HALAMAN << "): ";
        while (!(cin >> halaman) || halaman < 1 || halaman > MAKS_HALAMAN) {
            if (cin.eof()) return 0;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus bilangan bulat 1 sampai 1000. Halaman: ";
        }
        cin.ignore(1000, '\n');

        // TODO 3: baca tepat satu huruf Y atau T; huruf kecil diterima.
        string masukan_warna;
        cout << "Berwarna (Y/T): ";
        while (true) {
            if (!getline(cin, masukan_warna)) return 0;
            size_t awal = masukan_warna.find_first_not_of(" \t\r");
            size_t akhir = masukan_warna.find_last_not_of(" \t\r");
            if (awal != string::npos && awal == akhir) {
                warna = static_cast<char>(toupper(static_cast<unsigned char>(masukan_warna[awal])));
                if (warna == 'Y' || warna == 'T') break;
            }
            cout << "Hanya Y atau T. Berwarna (Y/T): ";
        }

        // TODO 4: tentukan harga, kategori, dan biaya pesanan.
        int harga_per_halaman = 0;
        if (halaman <= BATAS_KECIL) {
            harga_per_halaman = HARGA_KECIL;
            banyak_kecil++;
        } else if (halaman <= BATAS_SEDANG) {
            harga_per_halaman = HARGA_SEDANG;
            banyak_sedang++;
        } else {
            harga_per_halaman = HARGA_BESAR;
            banyak_besar++;
        }

        int biaya = halaman * harga_per_halaman;
        if (warna == 'Y') biaya *= 2;

        cout << "  " << left << setw(16) << nama << right << setw(6) << halaman;
        if (warna == 'Y') cout << setw(7) << "Warna";
        else cout << setw(7) << "Hitam";
        cout << setw(9) << biaya << "\n";

        total_halaman += halaman;
        total_pendapatan += biaya;

        // TODO 5b: perbarui pesanan dengan biaya terbesar.
        if (biaya > biaya_terbesar) {
            biaya_terbesar = biaya;
            nama_terbesar = nama;
        }
    }

    cout << "\n=== Rekap Hari Ini ===\n";
    cout << "Jumlah pesanan    : " << jumlah << "\n";
    cout << "Total halaman     : " << total_halaman << "\n";
    cout << "Total pendapatan  : " << total_pendapatan << "\n";
    cout << "Rata-rata halaman : "
         << static_cast<double>(total_halaman) / jumlah << "\n";

    // TODO 5c: cetak pesanan dengan biaya terbesar.
    cout << "Terbesar          : " << nama_terbesar << " (" << biaya_terbesar << ")\n";

    // TODO 6: cetak sebaran dengan perulangan bersarang.
    cout << "\nSebaran ukuran pesanan:\n";
    const string label_kategori[] = {"Kecil", "Sedang", "Besar"};
    const int jumlah_kategori[] = {banyak_kecil, banyak_sedang, banyak_besar};
    for (int i = 0; i < 3; i++) {
        cout << left << setw(7) << label_kategori[i] << "| ";
        for (int j = 0; j < jumlah_kategori[i]; j++) cout << '#';
        cout << ' ' << jumlah_kategori[i] << "\n";
    }

    return 0;
}
