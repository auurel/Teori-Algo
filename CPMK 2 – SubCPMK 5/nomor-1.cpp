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