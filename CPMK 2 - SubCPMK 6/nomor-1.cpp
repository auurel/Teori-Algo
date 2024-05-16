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