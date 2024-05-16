### 1.	Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll

```c++
#include <iostream>
using namespace std;

const int maxQueueSize = 10; // Ukuran maksimum queue

class Queue {
private:
    int front;
    int rear;
    int count;
    int queueArray[maxQueueSize];

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == maxQueueSize);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Antrian penuh, tidak dapat menambah nomor antrian.\n";
        } else {
            rear = (rear + 1) % maxQueueSize;
            queueArray[rear] = data;
            count++;
            cout << "Nomor antrian " << data << " telah ditambahkan.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong, tidak ada nomor antrian yang dihapus.\n";
        } else {
            cout << "Nomor antrian " << queueArray[front] << " telah dihapus.\n";
            front = (front + 1) % maxQueueSize;
            count--;
        }
    }

    int getFront() {
        if (!isEmpty()) {
            return queueArray[front];
        } else {
            cout << "Antrian kosong.\n";
            return -1;
        }
    }

    int getCount() {
        return count;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
        } else {
            cout << "Nomor antrian saat ini: ";
            for (int i = 0; i < count; i++) {
                int index = (front + i) % maxQueueSize;
                cout << queueArray[index] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue antrian;

    antrian.enqueue(1);
    antrian.enqueue(2);
    antrian.enqueue(3);
    antrian.enqueue(4);
    antrian.enqueue(5);

    antrian.printQueue();

    cout << "Nomor antrian didepan: " << antrian.getFront() << endl;

    antrian.dequeue();
    antrian.printQueue();

    cout << "Jumlah nomor antrian saat ini: " << antrian.getCount() << endl;

    antrian.enqueue(6);
    antrian.enqueue(7);
    antrian.enqueue(8);
    antrian.enqueue(9);
    antrian.enqueue(0);
    antrian.enqueue(1); // Harus menunjukkan bahwa antrian penuh

    antrian.printQueue();

    return 0;
}
```

Kode di atas adalah struktur data yang memungkinkan pengguna menambahkan dan menghapus elemen secara berurutan. Dalam kode ini, queue digunakan untuk menampung nomor antrian. Kode di atas juga berfungsi untuk menampilkan fungsi-fungsi yang terkait dengan queue, seperti menambahkan elemen ke dalam queue (enqueue), menghapus elemen dari queue (dequeue), mencetak isi queue, dan menampilkan jumlah elemen dalam queue.
Output dari kode di atas adalah sebagai berikut:
```c++
Nomor antrian saat ini: 1 2 3 4 5
Nomor antrian didepan: 1
Nomor antrian saat ini: 2 3 4 5
Jumlah nomor antrian saat ini: 4
Nomor antrian saat ini: 2 3 4 5 6 7 8 9 0 1
```
Output tersebut menunjukkan bahwa queue telah berfungsi dengan baik. Queue dapat menampung elemen hingga mencapai ukuran maksimum yang telah ditentukan, yaitu 10 elemen. Setelah queue penuh, pengguna tidak dapat lagi menambahkan elemen ke dalam queue.


### 2.	Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat

```c++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Definisikan struktur untuk hewan yang diadopsi
struct Hewan {
    string jenis;
    int waktuMasuk;
};

class AdopsiHewan {
private:
    queue<Hewan> antrianKucing;
    queue<Hewan> antrianAnjing;

public:
    // Fungsi untuk menambahkan hewan ke antrian sesuai jenisnya
    void enqueue(string jenis, int waktuMasuk) {
        Hewan hewan = {jenis, waktuMasuk};
        if (jenis == "Kucing") {
            antrianKucing.push(hewan);
        } else if (jenis == "Anjing") {
            antrianAnjing.push(hewan);
        } else {
            cout << "Jenis hewan tidak valid!" << endl;
        }
    }

    // Fungsi untuk mengadopsi hewan tertua dari antrian
    Hewan dequeueAny() {
        Hewan hewan;
        if (antrianKucing.empty() && antrianAnjing.empty()) {
            cout << "Antrian kosong!" << endl;
        } else if (antrianKucing.empty()) {
            hewan = antrianAnjing.front();
            antrianAnjing.pop();
        } else if (antrianAnjing.empty()) {
            hewan = antrianKucing.front();
            antrianKucing.pop();
        } else {
            if (antrianKucing.front().waktuMasuk < antrianAnjing.front().waktuMasuk) {
                hewan = antrianKucing.front();
                antrianKucing.pop();
            } else {
                hewan = antrianAnjing.front();
                antrianAnjing.pop();
            }
        }
        return hewan;
    }

    // Fungsi untuk mengadopsi kucing tertua
    Hewan dequeueCat() {
        Hewan hewan;
        if (antrianKucing.empty()) {
            cout << "Antrian kucing kosong!" << endl;
        } else {
            hewan = antrianKucing.front();
            antrianKucing.pop();
        }
        return hewan;
    }

    // Fungsi untuk mengadopsi anjing tertua
    Hewan dequeueDog() {
        Hewan hewan;
        if (antrianAnjing.empty()) {
            cout << "Antrian anjing kosong!" << endl;
        } else {
            hewan = antrianAnjing.front();
            antrianAnjing.pop();
        }
        return hewan;
    }
};

int main() {
    AdopsiHewan adopsiHewan;

    // Menambahkan beberapa hewan ke dalam antrian
    adopsiHewan.enqueue("Kucing", 1);
    adopsiHewan.enqueue("Anjing", 2);
    adopsiHewan.enqueue("Kucing", 3);
    adopsiHewan.enqueue("Anjing", 4);

    // Menu untuk pengguna
    int pilihan;
    do {
        cout << "\nMenu Adopsi Hewan Terlantar:" << endl;
        cout << "1. Adopsi Hewan Tertua (Kucing atau Anjing)" << endl;
        cout << "2. Adopsi Kucing Tertua" << endl;
        cout << "3. Adopsi Anjing Tertua" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Hewan hewan = adopsiHewan.dequeueAny();
                if (hewan.jenis != "") {
                    cout << "Hewan yang diadopsi: " << hewan.jenis << " (masuk pada waktu: " << hewan.waktuMasuk << ")" << endl;
                }
                break;
            }
            case 2: {
                Hewan hewan = adopsiHewan.dequeueCat();
                if (hewan.jenis != "") {
                    cout << "Kucing yang diadopsi: " << " (masuk pada waktu: " << hewan.waktuMasuk << ")" << endl;
                }
                break;
            }
            case 3: {
                Hewan hewan = adopsiHewan.dequeueDog();
                if (hewan.jenis != "") {
                    cout << "Anjing yang diadopsi: " << " (masuk pada waktu: " << hewan.waktuMasuk << ")" << endl;
                }
                break;
            }
            case 4: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
```

Kode di atas adalah implementasi dari sebuah program yang memungkinkan pengguna untuk mengadopsi hewan terlantar, seperti kucing dan anjing. Program ini menggunakan struktur data queue untuk menampung hewan yang diadopsi.

Maksud dari kode di atas adalah untuk menampilkan fungsi-fungsi yang terkait dengan adopsi hewan terlantar, seperti menambahkan hewan ke dalam antrian, mengadopsi hewan tertua, dan mengadopsi kucing atau anjing tertua.

Program ini memiliki beberapa fitur, seperti:
- Menambahkan hewan ke dalam antrian: Pengguna dapat menambahkan hewan ke dalam antrian dengan menggunakan fungsi 'enqueue' yang memungkinkan pengguna untuk memasukkan jenis hewan dan waktu masuk hewan.
- Mengadopsi hewan tertua: Pengguna dapat mengadopsi hewan tertua dari antrian dengan menggunakan fungsi 'dequeueAny' yang memungkinkan pengguna untuk mengadopsi hewan yang masuk terakhir.
- Mengadopsi kucing atau anjing tertua: Pengguna dapat mengadopsi kucing atau anjing tertua dari antrian dengan menggunakan fungsi 'dequeueCat' dan 'dequeueDog' yang memungkinkan pengguna untuk mengadopsi hewan yang masuk terakhir berdasarkan jenis hewan.

Program ini juga memiliki menu untuk pengguna yang memungkinkan pengguna untuk memilih opsi yang tersedia, seperti mengadopsi hewan tertua, mengadopsi kucing atau anjing tertua, atau keluar dari program.