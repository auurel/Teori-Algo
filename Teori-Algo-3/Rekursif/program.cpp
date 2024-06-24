#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    // Kondisi base untuk menghentikan rekursif
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Fungsi rekursif untuk menghitung faktorial
        return n * faktorial(n - 1);
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    // Cek apakah inputan adalah bilangan bulat positif
    if (num > 0) {
        cout << "Faktorial dari " << num << " adalah: " << faktorial(num) << endl;
    } else {
        cout << "Inputan harus bilangan bulat positif." << endl;
    }

    return 0;
}