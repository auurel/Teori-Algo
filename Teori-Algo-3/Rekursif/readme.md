# <h1 align="center">Rekursif</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

Rekursif adalah fungsi yang memanggil dirinya sendiri secara langsung ataupun tidak. Tujuan rekursif adalah untuk melakukan pengulangan, atau looping seperti for dan while, namun dengan cara yang berbeda [1]. 

#### Konsep Dasar Rekursif
Pada dasarnya, sebuah fungsi rekursif terdiri dari dua komponen utama:

- Base Case (Kasus Dasar): Ini adalah kondisi di mana fungsi tidak akan memanggil dirinya sendiri lagi dan langsung memberikan hasil. Base case diperlukan untuk menghentikan rekursi dan mencegah terjadinya loop tak berujung.
- Recursive Case (Kasus Rekursif): Bagian ini adalah di mana fungsi memanggil dirinya sendiri dengan versi yang lebih sederhana atau lebih kecil dari masalah aslinya.

```c++
#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    // Kondisi base untuk menghentikan rekursif
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Fungsi rekursif untuk menghitung faktorial
        return n * faktorial(n - 1);
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    // Cek apakah inputan adalah bilangan bulat positif
    if (num > 0) {
        cout << "Faktorial dari " << num << " adalah: " << faktorial(num) << endl;
    } else {
        cout << "Inputan harus bilangan bulat positif." << endl;
    }

    return 0;
}
```

#### Penjelasan Output
![Rekursif Unguided-1](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/c121cb1e-0d31-4e79-983c-0f66b3490ca8)

Kode di atas merupakan contoh program yang menggunakan rekursif langsung untuk menghitung nilai faktorial dari sebuah inputan bilangan bulat positif.

Program ini terdiri dari dua bagian utama: fungsi 'faktorial' dan fungsi 'main'.

Fungsi 'faktorial' digunakan untuk menghitung nilai faktorial dari sebuah bilangan 'n'. Fungsi ini menggunakan rekursif langsung, di mana nilai faktorial dari sebuah bilangan 'n' dihitung dengan mengalikan 'n' dengan nilai faktorial dari bilangan '(n - 1)'. Kondisi base untuk menghentikan rekursif adalah ketika 'n' menjadi 0 atau 1, di mana nilai faktorial dari 0 atau 1 adalah 1.

Fungsi 'main' meminta inputan bilangan bulat positif dari user dan kemudian memanggil fungsi 'faktorial' untuk menghitung nilai faktorial dari inputan tersebut. Jika inputan bukan bilangan bulat positif, program akan menampilkan pesan kesalahan.

Proses rekursif langsung berjalan sebagai berikut:
- Fungsi 'faktorial' dipanggil dengan argumen 'n'.
- Fungsi 'faktorial' mencari kondisi base untuk menghentikan rekursif, yaitu ketika 'n' menjadi 0 atau 1.
- Jika 'n' tidak menjadi 0 atau 1, fungsi 'faktorial' memanggil dirinya sendiri dengan argumen 'n - 1'.
- Proses ini berulang hingga 'n' menjadi 0 atau 1.
- Ketika 'n' menjadi 0 atau 1, fungsi 'faktorial' mengembalikan nilai 1, yang kemudian digunakan untuk menghitung nilai faktorial dari bilangan sebelumnya.

#### Referensi

[1] W. Hartanto, “Implementasi Algoritma Rekursif dengan Bahasa Pemrograman Python,” BINUS UNIVERSITY BANDUNG - Kampus Teknologi Kreatif, Dec. 04, 2019. Available: https://binus.ac.id/bandung/2019/12/implementasi-algoritma-rekursif-dengan-bahasa-pemrograman-python/. [Accessed: June 20, 2024]
