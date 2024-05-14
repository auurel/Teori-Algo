### 1.	Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 

#### # Pengertian Struct
Struct adalah sebuah konstruk yang digunakan dalam bahasa pemrograman C++ untuk mendefinisikan sebuah struktur data yang terdiri dari beberapa variabel yang terkait. Struct dapat digunakan untuk mendefinisikan sebuah objek yang terdiri dari beberapa atribut dan metode yang terkait.

#### # Kelebihan Struct

1. Mengorganisasi Data: Struct memungkinkan kita untuk mengorganisasi data dalam sebuah struktur yang terstruktur dan mudah dipahami.
2. Menghemat Memori: Struct dapat membantu menghemat memori karena kita dapat mendefinisikan sebuah struktur data yang terdiri dari beberapa variabel yang terkait dalam satu blok memori.
3. Menghemat Waktu Pemrograman: Struct dapat membantu menghemat waktu pemrograman karena kita dapat mendefinisikan sebuah struktur data yang terdiri dari beberapa variabel yang terkait dalam satu blok kode.

#### # Kekurangan Struct

1. Keterbatasan: Struct memiliki keterbatasan dalam hal jumlah dan tipe variabel yang dapat didefinisikan.
2. Keterbatasan Akses: Struct memiliki keterbatasan dalam hal akses ke variabel yang terkait. Variabel yang terkait hanya dapat diakses melalui nama struct.

#### Contoh Penggunaan Struct
Berikut adalah contoh penggunaan struct untuk mendefinisikan sebuah struktur data untuk representasi sebuah mahasiswa:

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
Kode di atas merupakan program yang mendefinisikan tiga struktur: 'hewan', 'hewanDarat', 'hewanLaut'. Masing-masing struktur mewakili hewan yang berbeda karakteristiknya.

Struktur 'hewan' mewakili hewan umum, dengan atribut-atribut berikut:
- 'namaHewan' : nama hewan
- 'jenisKelamin' : jenis kelamin hewan (jantan atau betina)
- 'caraBerkembangbiak' : cara hewan bereproduksi (misalnya bertelur, melahirkan)
- 'alatPernapasan' : sistem pernafasan hewan (misalnya, paru-paru, insang)
- 'tempatHidup' : habitat atau lingkungan hidup hewan
- 'Karnivora' : boolean yang menunjukan apakah hewan adalah karnivora (pemakan daging)

Struktur 'hewanDarat' mewakili hewan darat (hewan yang hidup di darat) dengan atribut-atribut berikut:
- 'jumlahKaki' : jumlah kaki hewan
- 'menyusui' : boolean yang menunjukkan apakah hewan menyusui anaknya
- 'suara' : suara atau vokalisasi hewan

Struktur 'hewanLaut' mewakili hewan laut (hewan yang hidup di air), dengan atribut-atribut berikut:
- 'bentukSirip' : bentuk sirip hewan
- 'bentukPertahananDiri' : mekanisme pertahanan diri hewan (misalnya, cangkang, duri)

Kemudian program tersebut mencetak atribut-atribut dari masing-masing hewan, menggunakan struktur untuk mengakses dan mencetak informasi yang relevan. Misalnya, untuk serigala, program mencetak nama, jenis kelamin, cara bereproduksi, sistem pernafasan, habitat, dan apakah hewan tersebut karnivora. Untuk kelinci, program mencetak jumlah kaki, apakah hewan menyusui anaknya, dan suara. Untuk ikan, program mencetak bentuk sirip dan mekanisme pertahanan diri.
