### 1.	Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) 

```c++
#include <iostream>
#include <unordered_set>

using namespace std;

// definisi struktur untuk node pada singly linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
}

// menghilangkan duplikasi data pada unsorted linked list
void hapusDuplikat(Node* head) {
    if (!head) return;

    unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (seen.find(current->data) != seen.end()) {
            // Jika data sudah ada di set, hapus node saat ini
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            // Jika data belum ada di set, tambahkan ke set
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

// mencetak linked list
void cetakList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Fungsi utama untuk pengujian
int main() {
    Node* head = nullptr;

    append(head, 13);
    append(head, 17);
    append(head, 77);
    append(head, 15);
    append(head, 67);
    append(head, 15);
    append(head, 99);

    cout << "Linked List awal : " << endl;
    cetakList(head);

    hapusDuplikat(head);

    cout << "Linked List setelah dihapus duplikat : " << endl;
    cetakList(head);

    return 0;
}
```

kode di atas berfungsi untuk menghapus duplikasi data pada sebuah linked list.
Fungsi hapusDuplikat berfungsi dengan cara mencari node yang memiliki data duplikat dan menghapus node tersebut. Fungsi append digunakan untuk menambahkan node baru ke linked list, sedangkan fungsi cetakList digunakan untuk mencetak linked list. Fungsi utama digunakan untuk menguji fungsi hapusDuplikat dengan membuat linked list, mencetak linked list awal, menghapus duplikat, dan mencetak linked list setelah dihapus duplikat.


### 2.	Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

```c++
#include <iostream>
using namespace std;

// Definisi struktur untuk node pada single linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddle(Node*& head) {
    if (!head || !head->next) {
        // List is empty or has only one node
        return;
    }
    Node* prev = head;
    Node* current = head;
    // Move prev and current to the middle of the list
    while (current && current->next) {
        prev = prev->next;
        current = current->next->next;
    }
    // Delete the middle node
    Node* temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Fungsi utama untuk pengujian
int main() {
    Node* head = nullptr;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Linked List sebelum menghapus node tengah: " << endl;
    printList(head);

    deleteMiddle(head);

    cout << "Linked List setelah menghapus node tengah: " << endl;
    printList(head);

    return 0;
}
```

Kode di atas berfungsi untuk menghapus node di tengah sebuah linked list. Fungsi 'deleteMiddle' digunakan untuk menghapus node tengah dari linked list, sedangkan fungsi 'append' digunakan untuk menambahkan node baru di akhir linked list. Fungsi 'printList' digunakan untuk mencetak linked list. Kode ini menunjukkan bagaimana linked list dapat diolah untuk menghapus node di tengah menggunakan pointer dan iterasi.


### 3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```c++
#include <iostream>
using namespace std;

// mendefinisi struktur untuk node pada singly linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
}

// membalik linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// memeriksa apakah linked list adalah palindrom
bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }

    // Temukan titik tengah linked list
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // membalikkan separuh kedua linked list
    Node* secondHalf = reverse(slow);
    Node* firstHalf = head;

    // membandingkan dua setengah linked list
    Node* secondHalfCopy = secondHalf; // Simpan untuk membalik kembali nanti
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            reverse(secondHalfCopy); // Balikkan kembali sebelum return false
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // kembalikan separuh kedua ke bentuk asli
    reverse(secondHalfCopy);
    return true;
}

// mencetak linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// pengujian
int main() {
    Node* head = nullptr;

    append(head, 3);
    append(head, 7);
    append(head, 3);
    append(head, 5);
    append(head, 7);
    append(head, 5);

    cout << "Linked List: " << endl;
    printList(head);

    if (isPalindrome(head)) {
        cout << "Linked list adalah palindrom" << endl;
    } else {
        cout << "Linked list bukan palindrom" << endl;
    }

    return 0;
}
```

Kode di atasberfungsi untuk memeriksa apakah sebuah linked list adalah palindrom atau tidak. Fungsi 'isPalindrome' menggunakan algoritma untuk menemukan titik tengah linked list, membalikkan separuh kedua linked list, dan kemudian membandingkan dua setengah linked list untuk menentukan apakah linked list adalah palindrom atau tidak. Fungsi 'append' digunakan untuk menambahkan node baru di akhir linked list, sedangkan fungsi 'printList' digunakan untuk mencetak linked list. Kode ini menunjukkan bagaimana linked list dapat diolah untuk memeriksa apakah linked list adalah palindrom atau tidak