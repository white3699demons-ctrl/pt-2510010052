# SiNilai v0.4 — P05 Perulangan

## Isi berkas
- `sinilai_v04.cpp`: program SiNilai v0.4.
- `contoh_masukan.txt`: contoh masukan tiga mahasiswa.

## Struktur yang digunakan
- `do-while` meminta jumlah mahasiswa sampai nilainya minimal 1.
- `for` memproses mahasiswa dari 1 sampai jumlah mahasiswa.
- Dua akumulator: `total_nilai` dan `jumlah_lulus`.
- Rekap kelas menampilkan jumlah mahasiswa, lulus, belum lulus, dan rata-rata kelas.

## Kompilasi dan pengujian
```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v04.cpp -o sinilai_v04
./sinilai_v04 < contoh_masukan.txt
```

## Deklarasi AI — Label AI 1
- **Alat:** ChatGPT.
- **Untuk apa:** Membantu menyusun kerangka program C++ dan dokumentasi README berdasarkan instruksi Modul Praktikum P05.
- **Cara memeriksa:** Kompilasi dengan `-Wall -Wextra -Wpedantic`, jalankan dengan `contoh_masukan.txt`, lalu bandingkan seluruh kartu nilai dan rekap dengan tabel pada modul. Periksa juga kasus jumlah mahasiswa 0 atau negatif agar prompt diulang.

**Catatan:** Pastikan hasil kompilasi dan keluaran benar-benar diperiksa sebelum dikumpulkan.
