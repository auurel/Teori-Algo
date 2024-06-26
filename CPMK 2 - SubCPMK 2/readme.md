### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 

#### Bubble Sort

Algoritma Bubble Sort bekerja dengan cara membandingkan dua elemen yang berdekatan secara berulang. Jika elemen pertama lebih besar dari elemen kedua, maka elemen tersebut ditukar posisinya. Proses ini diulang sampai tidak ada lagi pertukaran yang terjadi, menandakan bahwa daftar telah terurut.

###### Alur:

- Iterasi melalui daftar elemen.
- Bandingkan elemen pertama dengan elemen kedua.
- Jika elemen pertama lebih besar, tukar posisinya dengan elemen kedua.
- Ulangi langkah 1 dan 2 hingga tidak ada lagi pertukaran yang terjadi.

###### Runtime:

Best Case: O(n) - Terjadi ketika daftar sudah terurut dan tidak ada pertukaran yang dilakukan.
Worst Case: O(n^2) - Terjadi ketika daftar terbalik dan semua elemen perlu ditukar posisinya.

#### Selection Sort

Algoritma Selection Sort bekerja dengan cara mencari elemen terkecil dalam daftar dan menukarnya dengan elemen pertama. Proses ini diulang hingga semua elemen telah terurut.

###### Alur:

- Temukan elemen terkecil dalam daftar.
- Tukar elemen terkecil dengan elemen pertama.
- Ulangi langkah 1 dan 2 untuk elemen berikutnya, dan seterusnya.

###### Runtime:

Best Case: O(n) - Terjadi ketika daftar sudah terurut dan elemen terkecil ditemukan pada iterasi pertama.
Worst Case: O(n^2) - Terjadi ketika elemen terkecil selalu berada di akhir daftar pada setiap iterasi.

#### Merge Sort

Algoritma Merge Sort menggunakan pendekatan "divide and conquer" (bagi dan kuasai). Daftar dibagi menjadi dua sub-daftar yang lebih kecil, kemudian sub-daftar tersebut diurutkan secara rekursif, dan akhirnya digabungkan kembali menjadi daftar yang terurut.

###### Alur:

- Bagi daftar menjadi dua sub-daftar yang sama besar.
- Urutkan sub-daftar secara rekursif menggunakan Merge Sort.
- Gabungkan dua sub-daftar yang terurut menjadi satu daftar yang terurut.

###### Runtime:

Best Case: O(n log n) - Terjadi ketika daftar dibagi dengan cara yang seimbang pada setiap iterasi.
Worst Case: O(n log n) - Terjadi ketika daftar dibagi dengan cara yang tidak seimbang pada setiap iterasi.

###### Kesimpulan:

Masing-masing algoritma memiliki kelebihan dan kekurangannya sendiri. Bubble Sort dan Selection Sort sederhana untuk diimplementasikan, tetapi memiliki runtime yang lebih lambat untuk daftar yang besar. Merge Sort lebih kompleks untuk diimplementasikan, tetapi memiliki runtime yang lebih efisien (O(n log n)) untuk semua kasus.

Pemilihan algoritma yang tepat tergantung pada kebutuhan dan spesifikasi kasus yang akan dihadapi.


### 2.	Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut

```C++
#include <iostream>

using namespace std;

void selectionSort(int data[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (data[j] < data[minIndex]) {
        minIndex = j;
      }
    }
    swap(data[i], data[minIndex]);
  }
}

void printArray(int data[], int n) {
  for (int i = 0; i < n; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

int main() {
  int data[] = {5, 2, 4, 1, 3};
  int n = sizeof(data) / sizeof(data[0]);

  cout << "Array awal: ";
  printArray(data, n);

  selectionSort(data, n);

  cout << "Array setelah diurutkan: ";
  printArray(data, n);

  return 0;
}
```

##### Fungsi selectionSort:
- Mendefinisikan fungsi selectionSort dengan parameter data (array of integers) dan n (ukuran array).
- Melakukan perulangan i dari 0 hingga n-1.
- Di dalam perulangan i, variabel minIndex diinisialisasi dengan nilai i.
- Melakukan perulangan j dari i+1 hingga n.
- Di dalam perulangan j, membandingkan nilai data[j] dengan data[minIndex].
- Jika data[j] < data[minIndex], maka nilai minIndex diperbarui menjadi j.
- Setelah perulangan j, menukar nilai data[i] dengan data[minIndex] menggunakan fungsi swap.

##### Fungsi printArray:
- Mendefinisikan fungsi printArray dengan parameter data dan n.
- Melakukan perulangan i dari 0 hingga n-1.
- Di dalam perulangan i, mencetak nilai data[i] ke konsol.

##### Fungsi main:
- Mendefinisikan array data berisi angka-angka yang ingin diurutkan.
- Menentukan nilai n sebagai ukuran array.
- Mencetak array awal.
- Memanggil fungsi selectionSort untuk mengurutkan array.
- Mencetak array setelah diurutkan.

##### Kompleksitas waktu:

Algoritma selection sort memiliki kompleksitas waktu O(n^2), yang berarti waktu yang dibutuhkan untuk mengurutkan array akan meningkat secara kuadrat seiring dengan bertambahnya ukuran array.

##### Kelebihan:

Algoritma ini mudah dipahami dan diimplementasikan.
Bekerja dengan baik pada array kecil.

##### Kekurangan:

Algoritma ini tidak efisien untuk array besar karena kompleksitas waktu yang tinggi.
Melakukan banyak pertukaran elemen array, yang dapat membuat program lambat.

##### Kesimpulan:

Algoritma selection sort adalah pilihan yang baik untuk mengurutkan array kecil atau untuk tujuan pembelajaran. Untuk array besar, algoritma sorting lain dengan kompleksitas waktu yang lebih rendah seperti merge sort atau quick sort lebih direkomendasikan.


### 3.	Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram”
contoh
##### #Input string1 = “bahu” string2 = “buah”
Output: “anagram”
##### #Input string1 = “makan” string2 = “minum”
Output: “tidak anagram”

```C++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string checkAnagram() {
    string str1, str2;

    // Input string1
    cout << "Masukkan string pertama: ";
    cin >> str1;

    // Input string2
    cout << "Masukkan string kedua: ";
    cin >> str2;

    if (str1.length() != str2.length()) {
        return "tidak anagram";
    }

    string str1Copy = str1;
    string str2Copy = str2;

    sort(str1Copy.begin(), str1Copy.end());
    sort(str2Copy.begin(), str2Copy.end());

    if (str1Copy == str2Copy) {
        return "anagram";
    } else {
        return "tidak anagram";
    }
}

int main() {
    cout << checkAnagram() << endl;

    return 0;
}
```

Dalam fungsi 'checkAnagram', kita meminta pengguna untuk memasukkan dua string. Kemudian, kita memeriksa apakah panjang kedua string sama atau tidak. Jika tidak sama, maka mereka tidak dapat menjadi anagram dan kita mengembalikan "tidak anagram". Jika panjangnya sama, kita membuat salinan dari kedua string dan mengurutkan huruf-huruf dalam setiap string. Kemudian, kita membandingkan apakah string yang diurutkan sama atau tidak. Jika sama, maka string asli adalah anagram dan kita mengembalikan "anagram". Jika tidak sama, maka mereka tidak adalah anagram dan kita mengembalikan "tidak anagram".


### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeAndSort(vector<int>& A, const vector<int>& B) {
    // Gabungkan array B ke dalam array A
    A.insert(A.end(), B.begin(), B.end());

    // Urutkan array A
    sort(A.begin(), A.end());
}

int main() {
    vector<int> A = {1, 3, 5, 7};
    vector<int> B = {2, 4, 6, 8};

    cout << "Array A sebelum penggabungan: ";
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Array B sebelum penggabungan: ";
    for (int i : B) {
        cout << i << " ";
    }
    cout << endl;

    mergeAndSort(A, B);

    cout << "Array A setelah penggabungan dan pengurutan: ";
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
```

Dalam fungsi 'mergeAndSort', kita menggabungkan array B ke dalam array A menggunakan fungsi 'insert'. Kemudian, kita mengurutkan array A menggunakan fungsi 'sort' dari library 'algorithm'.

