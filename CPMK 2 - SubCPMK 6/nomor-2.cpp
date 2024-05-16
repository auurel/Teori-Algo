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