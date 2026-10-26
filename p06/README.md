# P06 — SiNilai v0.5

## Isi folder
- `sinilai_v05.cpp`: program laporan kelas SiNilai v0.5.
- `contoh_masukan.txt`: data uji enam mahasiswa sesuai tabel pada Modul Praktikum P06.

## Cara membangun dan menjalankan
Gunakan terminal pada folder `p06`:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v05.cpp -o sinilai_v05
./sinilai_v05 < contoh_masukan.txt
```

Di Windows, jalankan program hasil kompilasi dengan `./sinilai_v05.exe < contoh_masukan.txt` bila diperlukan.

## Fitur
- Keluaran berkolom menggunakan `setw`, `left`, `right`, `fixed`, dan `setprecision(2)`.
- Penghitung huruf mutu menggunakan `switch`; nilai B dan B+ masuk kelompok B, C dan C+ masuk kelompok C.
- Menentukan mahasiswa dengan nilai akhir tertinggi.
- Menampilkan sebaran huruf mutu A–E menggunakan perulangan bersarang.

## Deklarasi AI — Label AI 1
- **Alat:** ChatGPT.
- **Untuk apa:** Membantu menyusun kode C++ SiNilai v0.5, berkas masukan contoh, dan README berdasarkan instruksi Modul Praktikum P06.
- **Cara memeriksa:** Kode dikompilasi dengan `-std=c++20 -Wall -Wextra -Wpedantic`; jalankan program dengan `contoh_masukan.txt`, lalu bandingkan enam nilai, rekap, mahasiswa tertinggi, dan sebaran huruf dengan tabel/laporan di modul. Periksa juga kode secara mandiri sebelum dikumpulkan.
