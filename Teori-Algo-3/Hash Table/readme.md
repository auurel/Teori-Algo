# <h1 align="center">Hash Tabel</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

Hash Table, yang juga dikenal sebagai hash map, adalah struktur data yang dirancang untuk menyimpan pasangan kunci-nilai. Struktur ini memfasilitasi pengambilan data dengan cepat berdasarkan kunci yang diberikan. Dalam JavaScript, sebuah objek adalah implementasi khusus dari hash table di mana objek secara otomatis menambahkan kuncinya sendiri [1].

#### Kelebihan Hash Tabel
- Hash table memungkinkan akses data yang sangat cepat, dengan waktu pencarian, penyisipan, dan penghapusan rata-rata O(1). Hal ini disebabkan oleh penggunaan fungsi hash yang mengubah kunci menjadi indeks dalam array [2]
- Hash table bisa sangat efisien dalam penggunaan ruang jika fungsi hash yang digunakan baik dan jumlah elemen tidak terlalu besar dibandingkan ukuran tabel [3]
- Hash table dapat digunakan untuk menyimpan berbagai tipe data dan cocok untuk banyak aplikasi yang memerlukan akses cepat ke data berdasarkan kunci.

#### Kekurangan Hash Tabel
- Kolisi terjadi ketika dua kunci yang berbeda menghasilkan indeks hash yang sama. Untuk mengatasi kolisi, metode seperti chaining atau open addressing diperlukan, yang dapat mengurangi efisiensi.
- Jika tabel hash sangat jarang (sparse), dengan banyak slot yang tidak terisi, maka ini dapat menyebabkan penggunaan memori yang tidak efisien [4]

```c++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```
#### Penjelasan Output
Kode di atas adalah implementasi sebuah hash table (tabel hash) yang menggunakan struktur data linked list untuk mewakili setiap elemen dalam tabel. Hash table ini memiliki fungsi insert untuk menambahkan elemen, get untuk mencari nilai elemen berdasarkan kunci, dan remove untuk menghapus elemen berdasarkan kunci. Fungsi traverse digunakan untuk menampilkan semua elemen dalam tabel.

Output dari kode di atas adalah sebagai berikut:

```C++
Get key 1: 10
Get key 4: -1
1: 10
2: 20
3: 30
```

- Get key 1: 10 : Fungsi 'get' digunakan untuk mencari nilai elemen dengan kunci 1. Karena elemen dengan kunci 1 telah ditambahkan sebelumnya, fungsi ini mengembalikan nilai 10.
- Get key 4: -1 : Fungsi 'get' digunakan untuk mencari nilai elemen dengan kunci 4. Karena elemen dengan kunci 4 tidak ada dalam tabel, fungsi ini mengembalikan nilai -1.
- 1: 10, 2: 20, 3: 30 : Fungsi 'traverse' digunakan untuk menampilkan semua elemen dalam tabel. Hasilnya adalah daftar elemen dengan kunci dan nilai yang telah ditambahkan sebelumnya.

#### Referensi

 [1] I. Ashraf, “Hash Table,” Medium, Dec. 27, 2023. Available: https://medium.com/@realirfanashraf/hash-table-176d0b18b59b#:~:text=A%20Hash%20Table%2C%20also%20referred%20to%20as%20a%20hash%20map,autonomously%20adds%20its%20own%20keys.. [Diakses: 20 Juni, 2024]

 [2] "A hash table is a data structure that provides fast insertion, deletion, and lookup of key/value pairs." (GeeksforGeeks)

 [3] "When implemented correctly, a hash table can be both time and space efficient." https://en.wikipedia.org/wiki/Hash_table [Diakses: 20 Juni, 2024]

 [4] "Hash tables can waste a lot of memory if not managed properly, especially if the load factor is low." https://en.wikipedia.org/wiki/Hash_table [Diakses: 20 Juni, 2024]
