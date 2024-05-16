### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

### Binary Search
Binary Search adalah sebuah teknik pencarian data yang menggunakan proses carian dwipilihan. Berikut adalah alur dari Binary Search:

- Pengurutan Array: Data yang akan dicari harus diurutkan terlebih dahulu. Jika tidak, Binary Search tidak dapat digunakan.
- Pengaturan Rentang: Rentang pencarian diawali dari awal array dan berakhir di akhir array.
- Penghitungan Tengah: Rentang pencarian dihitung menjadi setengah, yaitu (LOW + HIGH)/2.
- Perbandingan: Nilai tengah di bandingkan dengan nilai yang dicari.
- Pengurutan Kembali: Jika nilai tengah tidak sama dengan nilai yang dicari, maka rentang pencarian diurutkan kembali ke bagian yang lebih kecil atau lebih besar.
- Pencarian Berlanjut: Proses pencarian berlanjut hingga nilai yang dicari ditemukan atau rentang pencarian kosong.

#### Runtime
- Best Case: Runtime Binary Search adalah O(1) karena nilai yang dicari ditemukan di tengah array.
- Worst Case: Runtime Binary Search adalah O(log n) karena nilai yang dicari tidak ditemukan dan proses pencarian harus dilakukan hingga akhir array.

### Linear Search
Linear Search adalah sebuah teknik pencarian data yang mencari nilai yang dicari secara berurutan melalui array. Berikut adalah alur dari Linear Search:

- Pengurutan Array: Data yang akan dicari tidak memerlukan pengurutan terlebih dahulu.
- Penghitungan Awal: Pencarian dimulai dari awal array.
- Perbandingan: Nilai array di bandingkan dengan nilai yang dicari.
- Pencarian Berlanjut: Proses pencarian berlanjut hingga nilai yang dicari ditemukan atau array habis dibaca.

#### Runtime
- Best Case: Runtime Linear Search adalah O(1) karena nilai yang dicari ditemukan di awal array.
- Worst Case: Runtime Linear Search adalah O(n) karena nilai yang dicari tidak ditemukan dan proses pencarian harus dilakukan hingga akhir array.

Dalam sintaks, Binary Search lebih efisien dibandingkan dengan Linear Search, terutama pada array yang besar, karena Binary Search dapat membagi array menjadi setengah dan mengurangi jumlah elemen yang perlu diuji. Namun, Linear Search lebih mudah digunakan pada array yang tidak terurut dan tidak memerlukan pengurutan awal.


### 2.	Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut

```C++
#include <iostream>
#include <conio.h>
#include <iomanip> 
using namespace std;

int data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort()
{
    int temp, min, i, j;

    for (i=0; i<7;i++)
    {
        min = i;
        for(j = i+1; j<7; j++)
        {
            if(data[j]<data[min])
            {
                min=j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch ()
{
    //searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal<=akhir)
    {
        tengah = (awal + akhir) /2;
        if(data[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah -1;
    }
        if(b_flag == 1)
            cout <<"\n   Data ditemukan pada index ke-" << tengah << endl;
        else
            cout <<"\n Data tidak ditemukan\n";
}

int main()
{
    cout << "\t     BINARY SEARCH   " << endl;
    cout << "\n Data        : ";
    //tampilkan data awal
    for(int x = 0; x<7; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin anda cari  :   ";
    cin >> cari;
    cout << "\n Data diurutkan  :   ";
    // Urutkan data dengan selection sort
    selection_sort();
    // Tampilkan data setelah diurutkan
    for(int x = 0; x<7; x++)
        cout << setw(3) << data[x];

    cout << endl;

        binarysearch();

    _getche();
    return EXIT_SUCCESS;
}
```
Kode diatas merupakan contoh program yang menggunakan algoritma Binary Search untuk mencari sebuah angka dalam sebuah array. Program diatas mempunyai variabel data yang berisi beberapa angka, yang salah satunya adalah angka yang akan dicari, yang disimpan dalam variabel `cari`.
Program menggunakan fungsi `selection_sort` untuk mengurutkan angka dalam array data melalui algoritma Selection Sort. Setelah angka ditemukan, program akan menampilkan hasil pencarian. Jika angka `cari` `ditemukan`, program akan menampilkan pesan `"Data ditemukan pada index ke-[tengah]"`. Jika angka `cari` `tidak ditemukan`, program akan menampilkan pesan `"Data tidak ditemukan"`.
Program ini menggunakan algoritma Binary Search, yang merupakan algoritma pencarian yang efisien yang mencari sebuah elemen dalam sebuah koleksi. Jika angka yang dicari tidak ditemukan, maka algoritma akan mengembalikan indeks -1.


### 3.	Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari!
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}
Output: 6

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findIndex(const vector<string>& arr, const string& target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Kata tidak ditemukan
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};

    string target = "bola";
    int index = findIndex(arr, target);

    if (index != -1) {
        cout << "Lokasi kata '" << target << "' adalah indeks " << index << endl;
    } else {
        cout << "Kata '" << target << "' tidak ditemukan" << endl;
    }

    return 0;
}
```
Dalam fungsi 'findIndex', kita melakukan looping melalui array dan membandingkan setiap elemen dengan kata yang dicari. Jika kita menemukan kata yang dicari, kita mengembalikan indeksnya. Jika tidak, kita mengembalikan nilai -1 untuk menandakan kata tidak ditemukan.
Dalam contoh di atas, kita mencari kata "bola" dalam array yang diberikan. Fungsi 'findIndex' mengembalikan indeks 6, yang menunjukkan bahwa kata "bola" terletak di indeks ke-6 dalam array.
