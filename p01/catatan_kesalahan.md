# Catatan Kesalahan

## Tabel Praktikum 5

| Berkas | Jenis Kesalahan | Penjelasan | Dampak |
|---|---|---|---|
| `hello.cpp` | Syntax error | Kesalahan penulisan sintaks C++, misalnya tanda `;` atau `}` tidak sesuai. | Program tidak dapat dikompilasi. |
| `rerata.cpp` | Logic error | Rumus atau proses perhitungan rata-rata dapat ditulis tidak sesuai dengan tujuan program. | Program dapat berjalan tetapi menghasilkan nilai yang salah. |
| `catatan_kesalahan.md` | Dokumentasi error | Kesalahan dapat terjadi jika format Markdown atau isi catatan tidak sesuai instruksi. | Dokumentasi tugas menjadi tidak lengkap. |
| `README.md` | Documentation error | Informasi identitas, struktur repository, atau deklarasi AI dapat ditulis tidak sesuai. | Informasi repository menjadi kurang jelas atau tidak sesuai tugas. |

Menurut saya, kesalahan yang paling berbahaya adalah **kesalahan logika**, karena program dapat berjalan tanpa error tetapi menghasilkan output yang salah sehingga kesalahannya tidak selalu langsung terlihat.

## Catatan Kompilasi

Berkas `.cpp` dirancang agar dapat dikompilasi dengan:

```bash
g++ -Wall -Wextra -pedantic hello.cpp -o hello
g++ -Wall -Wextra -pedantic rerata.cpp -o rerata
```

Berkas hasil kompilasi `.exe` tidak disertakan dalam repository.
