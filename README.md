# SiNilai v0.7 — P09

## Deklarasi AI

**Label AI 1**

- **Alat:** ChatGPT.
- **Untuk apa:** Membantu memecah program SiNilai v0.6 menjadi sembilan fungsi sesuai prototipe modul P09, merapikan kode, dan menyiapkan pengujian.
- **Cara memeriksa:** Kode dikompilasi dengan `g++ -std=c++20 -Wall -Wextra -Wpedantic -g`. Program dijalankan menggunakan `contoh_masukan.txt`. Keluaran dibandingkan dengan keluaran SiNilai v0.6; selain baris judul versi, isi keluaran harus sama. Kode juga diperiksa untuk memastikan `bacaData` dan `perbaruiPenghitung` memakai parameter referensi serta tidak ada variabel global.

## Berkas

- `sinilai_v07.cpp` — program SiNilai v0.7 yang dipecah menjadi sembilan fungsi.
- `contoh_masukan.txt` — data uji enam mahasiswa beserta masukan tidak valid untuk menguji validasi.

## Build dan jalankan

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v07.cpp -o sinilai_v07
./sinilai_v07 < contoh_masukan.txt
```

## Pemeriksaan keluaran

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v06.cpp -o sinilai_v06
./sinilai_v06 < contoh_masukan.txt > keluaran_v06.txt
./sinilai_v07 < contoh_masukan.txt > keluaran_v07.txt
diff -u keluaran_v06.txt keluaran_v07.txt
```

Pada berkas v0.6 yang menjadi acuan, tidak terdapat baris judul versi. Program v0.7 mengikuti starter modul yang mencetak `=== SiNilai v0.7 ===`; karena itu, saat membandingkan hasil, baris judul v0.7 merupakan satu-satunya baris tambahan yang perlu diperhitungkan.
