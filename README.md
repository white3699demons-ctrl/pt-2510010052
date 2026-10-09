# P04 — SiNilai v0.3

## Deklarasi AI: Label AI 1

- **Alat yang dipakai:** ChatGPT.
- **Untuk apa:** Membantu menyusun struktur percabangan `if-else` bertingkat untuk huruf mutu, variabel `bool lulus`, `switch` untuk keterangan, dan merapikan dokumentasi.
- **Cara memeriksa:** Kode perlu dikompilasi dengan `g++ -std=c++20 -Wall -Wextra -Wpedantic`, lalu dijalankan untuk ketujuh kasus uji pada Modul Praktikum P04. Bandingkan nilai akhir, huruf mutu, keterangan, dan status dengan tabel modul. Pastikan bobot konstanta sama dengan yang digunakan pada P03.

## Kompilasi

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v03.cpp -o sinilai_v03
```

## Menjalankan

```bash
./sinilai_v03
```

Masukkan nama, NPM, lalu nilai kehadiran, mingguan, UTS, dan UAS sesuai urutan prompt.
