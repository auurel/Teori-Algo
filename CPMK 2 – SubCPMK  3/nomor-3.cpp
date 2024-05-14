#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findIndex(const vector<string>& arr, const string& target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Kata tidak ditemukan
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};

    string target = "bola";
    int index = findIndex(arr, target);

    if (index != -1) {
        cout << "Lokasi kata '" << target << "' adalah indeks " << index << endl;
    } else {
        cout << "Kata '" << target << "' tidak ditemukan" << endl;
    }

    return 0;
}