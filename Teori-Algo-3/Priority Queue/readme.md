# <h1 align="center">Hash Tabel</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

Priority Queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan nilai prioritas tertentu [1]. Elemen-elemen dalam Priority Queue diurutkan berdasarkan prioritas mereka, sehingga elemen dengan prioritas yang lebih tinggi akan diberikan akses lebih awal daripada elemen dengan prioritas yang lebih rendah [2]. 


### Cara Kerja Priority Queue
Pada dasarnya, Priority Queue dapat diimplementasikan dengan menggunakan struktur data dasar seperti heap atau binary search tree yang memungkinkan kita untuk melakukan operasi penyisipan (insert) dan penghapusan (delete) dalam waktu logaritmik. Dengan struktur data ini, kita dapat dengan mudah mengakses elemen dengan nilai prioritas tertinggi tanpa harus memindahkan seluruh elemen lainnya [1]. 

## Program Priority Queue

```c++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Struct untuk menyimpan tugas dengan prioritas
struct Task {
    int priority;
    string task;
    
    // Overload operator > untuk membuat min-heap
    bool operator>(const Task& other) const {
        return priority > other.priority;
    }
};

int main() {
    // Deklarasi priority queue dengan min-heap
    priority_queue<Task, vector<Task>, greater<Task>> pq;

    // Menambahkan beberapa task ke priority queue
    pq.push({3, "Task C"});
    pq.push({1, "Task A"});
    pq.push({2, "Task B"});
    pq.push({4, "Task D"});

    // Mengambil elemen dari priority queue dan menampilkannya
    cout << "Priority Queue:" << endl;
    while (!pq.empty()) {
        Task t = pq.top();
        pq.pop();
        cout << "Priority: " << t.priority << ", Task: " << t.task << endl;
    }

    return 0;
}
```
#### Penjelasan Program
- '#include <iostream>', '#include <queue>', '#include <vector>' digunakan untuk memasukkan fungsi input-output, priority queue, dan vector
- Struct 'Task' : Struct ini digunakan untuk menyimpan pasangan prioritas dan tugas. Operator '>' di-overload untuk membuat min-heap (heap dengan prioritas terkecil di bagian atas).
- 'priority_queue<Task, vector<Task>, greater<Task>> pq;' mendeklarasikan priority queue yang menggunakan 'Task' sebagai tipe data, 'vector<Task>' sebagai container, dan 'greater<Task>' untuk membuat min-heap.
- 'pq.push({priority, "task description"})' digunakan untuk menambahkan tugas dengan prioritas yang diberikan.
- 'pq.top()' mengambil elemen dengan prioritas tertinggi (terendah dalam kasus min-heap), 'pq.pop()' menghapus elemen tersebut dari queue, dan elemen tersebut ditampilkan.

#### Output Program
![Screenshot (1559)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/ad86e476-c3d4-476d-8be7-a986bd25bb1e)

- Elemen-elemen diambil dari priority queue dalam urutan prioritas, dimulai dari prioritas terendah (1) hingga tertinggi (4).
- "Task A" memiliki prioritas 1, sehingga diambil pertama kali.
- "Task B" memiliki prioritas 2, sehingga diambil kedua kali.
- "Task C" memiliki prioritas 3, sehingga diambil ketiga kali.
- "Task D" memiliki prioritas 4, sehingga diambil terakhir kali.

Dengan menggunakan min-heap, elemen dengan prioritas terkecil diambil terlebih dahulu, sesuai dengan kebutuhan untuk mengakses elemen berdasarkan prioritas.

### Kesimpulan
Priority Queue adalah konsep penting dalam algoritma yang membantu kita mengelola dan mengatur data dengan nilai prioritas tertentu. Implementasinya dalam struktur data seperti heap atau binary search tree memungkinkan operasi penyisipan dan penghapusan elemen dalam waktu logaritmik, yang sangat berguna dalam berbagai algoritma. Dengan pemahaman tentang Priority Queue, kita dapat meningkatkan efisiensi dan efektivitas algoritma yang kita gunakan dalam menyelesaikan masalah


#### Referensi 

[1] R. Pratama, "Priority Queue: Konsep dan Penggunaan dalam Algoritma," Medium, 22 Juli 2023. [Online]. Tersedia : https://medium.com/@furatamarizuki/priority-queue-konsep-dan-penggunaan-dalam-algoritma-f4c1cd117ba [Diakses: 20 Juni 2024].
[2] R. Pratama, “Queue: Pengealan, Implementasi, Operasi Dasar, dan Aplikasi,” Medium, 25 Mei 2023. [Online]. Tersedia : https://medium.com/@furatamarizuki/queue-pengenalan-implementasi-operasi-dasar-dan-aplikasi-c5eed7e871a3 [Diakses: 20 Juni 2024].