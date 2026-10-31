# SiNilai v0.6 — P07

## Deklarasi AI

**Label AI 1**

- **Alat:** ChatGPT.
- **Untuk apa:** Membantu menyusun dan merapikan kode C++ SiNilai v0.6, menerapkan validasi jumlah mahasiswa, validasi nama, perapian huruf nama, dan validasi nilai 0–100, serta menyiapkan berkas pengujian.
- **Cara memeriksa:** Kode dikompilasi dengan `g++ -std=c++20 -Wall -Wextra -Wpedantic`. Program diuji menggunakan `contoh_masukan.txt`; hasil laporan dibandingkan dengan laporan acuan SiNilai v0.5 pada modul praktikum. Masukan salah seperti nama kosong, nama mengandung angka, teks pada input angka, dan nilai di luar rentang juga diuji.

## Berkas

- `sinilai_v06.cpp` — program utama SiNilai v0.6.
- `contoh_masukan.txt` — data uji enam mahasiswa beserta masukan jebakan P07.

## Build dan jalankan

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v06.cpp -o sinilai_v06
./sinilai_v06 < contoh_masukan.txt
```
