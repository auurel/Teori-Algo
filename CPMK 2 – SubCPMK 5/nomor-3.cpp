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