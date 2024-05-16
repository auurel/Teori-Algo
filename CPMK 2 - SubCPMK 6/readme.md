### 1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll

```c++
#include <iostream>
#include <string>

using namespace std;

// Struktur untuk stack
struct Stack {
    int top;
    float data[10]; // Maksimal 10 elemen
};

// mengecek apakah stack kosong
bool isEmpty(Stack stack) {
    return (stack.top == -1);
}

// mengecek apakah stack penuh
bool isFull(Stack stack) {
    return (stack.top == 9);
}

// menambahkan elemen ke stack
void push(Stack &stack, float data) {
    if (isFull(stack)) {
        cout << "Stack penuh, tidak dapat menambah elemen." << endl;
    } else {
        stack.top++;
        stack.data[stack.top] = data;
        cout << "Elemen " << data << " telah ditambahkan ke stack." << endl;
    }
}

// menghapus elemen dari stack
void pop(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong, tidak dapat menghapus elemen." << endl;
    } else {
        cout << "Elemen " << stack.data[stack.top] << " telah dihapus dari stack." << endl;
        stack.top--;
    }
}

// mencetak isi stack
void print(Stack stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Isi stack: ";
        for (int i = 0; i <= stack.top; i++) {
            cout << stack.data[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Stack stack;
    stack.top = -1;

    int pilihan;
    do {
        cout << "\nMenu Operasi Stack:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                float data;
                cout << "Masukkan elemen yang akan ditambahkan: ";
                cin >> data;
                push(stack, data);
                break;
            }
            case 2: {
                pop(stack);
                break;
            }
            case 3: {
                print(stack);
                break;
            }
            case 4: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
```

Kode di atas berfungsi untuk menampilkan fungsi-fungsi yang terkait dengan stack, seperti menambahkan elemen ke stack, menghapus elemen dari stack, dan mencetak isi stack. Program ini juga memiliki menu untuk pengguna yang memungkinkan pengguna untuk memilih operasi yang akan dilakukan.

Berikut adalah fungsi-fungsi yang terkait dengan stack:
- 'isEmpty' : Fungsi ini digunakan untuk mengecek apakah stack kosong.
- 'isFull' : Fungsi ini digunakan untuk mengecek apakah stack penuh.
- 'push' : Fungsi ini digunakan untuk menambahkan elemen ke stack.
- 'pop' : Fungsi ini digunakan untuk menghapus elemen dari stack.
- 'print' : Fungsi ini digunakan untuk mencetak isi stack.

Output dari program ini akan menampilkan informasi tentang stack, seperti apakah stack kosong atau penuh, dan apakah elemen yang ditambahkan atau dihapus.


### 2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty

```c++
#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk menambah elemen ke stack dalam urutan yang tepat
void sortedInsert(stack<float>& s, float x) {
    if (s.empty() || x < s.top()) {
        s.push(x);
    } else {
        float temp = s.top();
        s.pop();
        sortedInsert(s, x);
        s.push(temp);
    }
}

// Fungsi untuk mensortir stack
void sortStack(stack<float>& s) {
    if (!s.empty()) {
        float x = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, x);
    }
}

// Fungsi untuk mencetak stack
void printStack(stack<float>& s) {
    stack<float> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    stack<float> s;
    s.push(4.50);
    s.push(3.93);
    s.push(33.77);
    s.push(37.80);
    s.push(10.27);
    s.push(13.69);

    cout << "Stack sebelum diurutkan: ";
    printStack(s);

    sortStack(s);

    cout << "Stack setelah diurutkan: ";
    printStack(s);

    return 0;
}
```

Maksud dari kode di atas adalah untuk menampilkan fungsi-fungsi yang terkait dengan stack, seperti menambahkan elemen ke stack, menghapus elemen dari stack, dan mencetak isi stack. Program ini juga memiliki fungsi untuk mensortir stack secara ascending.

Berikut adalah fungsi-fungsi yang terkait dengan stack:
- 'sortedInsert' : Fungsi ini digunakan untuk menambahkan elemen ke stack dalam urutan yang tepat. Jika stack kosong atau elemen teratas lebih besar dari x, maka x akan ditambahkan ke stack. Jika elemen teratas lebih kecil dari x, maka elemen teratas akan dihapus dan proses ini akan diulangi hingga x dapat ditambahkan ke stack.
- 'sortStack' : Fungsi ini digunakan untuk mensortir stack secara ascending. Jika stack tidak kosong, maka elemen teratas akan dihapus dan proses ini akan diulangi hingga stack kosong. Kemudian, elemen yang dihapus akan ditambahkan kembali ke stack dengan urutan yang tepat menggunakan fungsi sortedInsert.
- 'printStack' : Fungsi ini digunakan untuk mencetak isi stack.

Dalam main fungsi, kita memiliki stack yang berisi beberapa elemen dan kita mencetak isi stack sebelum diurutkan. Kemudian, kita memanggil fungsi sortStack untuk mensortir stack dan mencetak isi stack setelah diurutkan. Output dari program di atas akan menampilkan informasi tentang stack, seperti apakah stack kosong atau penuh, dan apakah elemen yang ditambahkan atau dihapus.