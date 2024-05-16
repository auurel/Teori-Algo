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